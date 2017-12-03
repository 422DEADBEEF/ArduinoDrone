#include "Navigator.h"
#include "Diagnostics.h"
#include <string.h>


Navigator::Navigator() : pitch_offset(0), roll_offset(0), ne_speed(0), nw_speed(0), 
                         se_speed(0), sw_speed(0), base_speed(0), forward(false), 
                         backward(false), left(false), right(false)
{
}

bool Navigator::Initialize(PwmPin ne, PwmPin nw, PwmPin se, PwmPin sw)
{
    ne_pin = ne;
    nw_pin = nw;
    se_pin = se;
    sw_pin = sw;

    //Diagnostics::SetLED(255, 0, 0);
    if (imu.Initialize())
    {
        pinMode(ne_pin, OUTPUT);
        pinMode(nw_pin, OUTPUT);
        pinMode(se_pin, OUTPUT);
        pinMode(sw_pin, OUTPUT);
    }
    else
    {
        Diagnostics::SetLED(0, 0, 255);
        return false;
    }
    Diagnostics::SendBTMessage("Calibration complete.");
    Diagnostics::SendBTMessage("Calibrating Sonar...");

    sonar.Initialize();
    state = kLanded;
    kHoverSpeed = 200;
    base_speed = 0;

    Diagnostics::SendBTMessage("Calibration complete.");
    return true;
}

void Navigator::Update()
{
    delay(NAVIGATION_CLOCK_DELAY);

    imu.Update();

    if (state == kTakingOff || state == kLanding)
    {
        sonar.Update();
    }

    float pitch = imu.GetPitch();
    float roll = imu.GetRoll();

    
    if (state != kLanded && state != kTesting)
    {
        float roll_angle = roll - roll_offset;
        roll_angle = (roll_angle >= 0) ? roll_angle : -roll_angle;

        if (roll_angle > STABILIZER_THRESHOLD)
        {
            if (roll_angle > 0)
            {
                // we are tilting too far forward
                //if (base_speed < kHoverSpeed)
                {
                    ne_speed += SENSITIVITY;
                    nw_speed += SENSITIVITY;
                }
                //else
                //{
                //    se_speed -= SENSITIVITY;
                //    sw_speed -= SENSITIVITY;
                //}
            }
            else if (roll_angle < 0)
            {
                // we are tilting backward
                //if (base_speed < kHoverSpeed)
                //{
                //    se_speed += SENSITIVITY;
                //    sw_speed += SENSITIVITY;
                //}
                //else
                {
                    ne_speed -= SENSITIVITY;
                    nw_speed -= SENSITIVITY;
                }
            }
        }

        float pitch_angle = pitch - pitch_offset;
        pitch_angle = (pitch_angle >= 0) ? pitch_angle : -pitch_angle;
        
        if (pitch_angle > STABILIZER_THRESHOLD)
        {
            if (pitch_angle > 0)
            {
                // we are tilting too far right
                if (base_speed < kHoverSpeed)
                {
                    ne_speed += SENSITIVITY;
                    se_speed += SENSITIVITY;
                }
                //else
                //{
                //    nw_speed -= SENSITIVITY;
                //    sw_speed -= SENSITIVITY;
                //}
            }
            else if (pitch_angle < 0)
            {
                // we are tilting too far left
                //if (base_speed < kHoverSpeed)
                //{
                //    nw_speed += SENSITIVITY;
                //    sw_speed += SENSITIVITY;
                //}
                //else
                {
                    ne_speed -= SENSITIVITY;
                    se_speed -= SENSITIVITY;
                }
            }
        }
    }

    if (state == kFlying)
    {
        char pitchBuffer[6];
        char rollBuffer[6];
        dtostrf(imu.GetPitch(), 3, 2, pitchBuffer);
        dtostrf(imu.GetRoll(), 3, 2, rollBuffer);

        char messageBuffer[28] = "Pitch:       \tRoll:       \0";
        memcpy(messageBuffer + 7, pitchBuffer, 6);
        memcpy(messageBuffer + 21, pitchBuffer, 6);
        for (int i = 0; i < 27; i++)
        {
            if (messageBuffer[i] == '\0')
            {
                messageBuffer[i] = ' ';
            }
        }
        Diagnostics::SendBTMessage(messageBuffer);
    }    

    if (state == kTakingOff)
    {
        delay(TAKEOFF_CLOCK_DELAY);

        if (sonar.IsRising())
        {
            if (sonar.RisingRate() < DESIRED_RISING_RATE)
            {
                base_speed += ASCENSION_RATE;
                if (base_speed > MAX_BASE_SPEED)
                {
                    base_speed = MAX_BASE_SPEED;
                }
            }

            if (sonar.GetDistance() >= HOVER_HEIGHT)
            {
                Diagnostics::SendBTMessage("Stabilizing...");
                state = kStabilizing;
            }
        }
        else
        {
            if (base_speed + ASCENSION_RATE >= MAX_BASE_SPEED)
            {
                EmergencyShutdown();
                state = kLanded;
                Diagnostics::SetLED(0, 0, 255);
                Diagnostics::SendBTMessage("Max speed reached; unable to get airborne.");
                return;
            }

            Diagnostics::SendBTMessage("Increasing motor speed...");
            base_speed += ASCENSION_RATE;
        }
    }

    if (state == kStabilizing)
    {
        Diagnostics::SetLED(255, 0, 255);
        if (sonar.IsRising())
        {
            base_speed -= ASCENSION_RATE;
        }
        else if (sonar.IsFalling())
        {
            base_speed += ASCENSION_RATE;
        }
        else
        {
            if (Diagnostics::DroneAbs(sonar.RisingRate()) < STABLE_CONSTANT)
            {
                state = kFlying;
                kHoverSpeed = base_speed;
                Diagnostics::SetLED(0, 255, 0);
                Diagnostics::SendBTMessage("Stabilization complete. Controls are enabled.");
            }
        }
    }

    if (state == kLanding)
    {

        if (sonar.GetDistance() < LANDING_THRESHOLD)
        {
            Diagnostics::SendBTMessage("Landing complete.");
            state = kLanded;
            EmergencyShutdown();
            delay(2000);
            Diagnostics::SetLED(0, 255, 0);
        }
        else
        {
            if (base_speed - ASCENSION_RATE >= 0)
            {
                base_speed -= ASCENSION_RATE;
            }
        }
        char sonarBuffer[8];
        dtostrf(sonar.GetDistance(), 5, 2, sonarBuffer);
        char messageBuffer[18] = "Distance:        ";
        memcpy(messageBuffer + 10, sonarBuffer, 6);
        for (int i = 0; i < 17; i++)
        {
            if (messageBuffer[i] == '\0')
            {
                messageBuffer[i] = ' ';
            }
        }
        Diagnostics::SendBTMessage(messageBuffer);
    }

    if (state != kLanded)
    {
        analogWrite(ne_pin, ((ne_speed + base_speed) <= 255) ? ne_speed + base_speed : 255);
        analogWrite(nw_pin, ((nw_speed + base_speed) <= 255) ? nw_speed + base_speed : 255);
        analogWrite(se_pin, ((se_speed + base_speed) <= 255) ? se_speed + base_speed : 255);
        analogWrite(sw_pin, ((sw_speed + base_speed) <= 255) ? sw_speed + base_speed : 255);
    }
}

void Navigator::Ascend()
{
    // if (state == kFlying)
    // {
    //     if ((ne_speed + UP_DOWN_RATE + base_speed) < MAX_BASE_SPEED &&
    //         (nw_speed + UP_DOWN_RATE + base_speed) < MAX_BASE_SPEED &&
    //         (se_speed + UP_DOWN_RATE + base_speed) < MAX_BASE_SPEED &&
    //         (sw_speed + UP_DOWN_RATE + base_speed) < MAX_BASE_SPEED)
    //     {
    //         base_speed += UP_DOWN_RATE;
    //     }
    //     else
    //     {
    //         // Cannot safely rise
    //         // LED? Bluetooth info?
    //     }
    // }
    state = kTesting;
    Diagnostics::SetLED(255, 0, 255);
}

void Navigator::StopAscend()
{
    if (state == kFlying)
    {
        if (base_speed >= UP_DOWN_RATE)
        {
            base_speed -= UP_DOWN_RATE;
        }
        else
        {
            base_speed = 0;
        }
    }
}

void Navigator::Descend()
{
    // if (state == kFlying)
    // {
    //     if (base_speed > 0)
    //     {
    //         if (base_speed > UP_DOWN_RATE)
    //         {
    //             base_speed -= UP_DOWN_RATE;
    //         }
    //         else
    //         {
    //             base_speed = 0;
    //         }

    //         if (base_speed == 0)
    //         {
    //             ne_speed = 0;
    //             nw_speed = 0;
    //             se_speed = 0;
    //             sw_speed = 0;
    //         }
    //     }
    // }
    state = kFlying;
    Diagnostics::SetLED(0, 255, 0);
    base_speed = 100;
}

void Navigator::StopDescend()
{
    if (state == kFlying)
    {
        base_speed += UP_DOWN_RATE;
    }
}

void Navigator::LiftOff()
{
    if (state == kLanded)
    {
        for (int i = 0; i < 10; i++)
        {
            sonar.Update();
        }

        state = kTakingOff;
        Diagnostics::SetLED(0, 0, 0);

        base_speed = TAKEOFF_SPEED;
        Diagnostics::SendBTMessage("Takeoff procedure initiated.");
    }
}

void Navigator::Land()
{
    if (state != kLanded)
    {
        for (int i = 0; i < 10; i++)
        {
            sonar.Update();
        }

        state = kLanding;
        Diagnostics::SetLED(0, 0, 0);
        Diagnostics::SendBTMessage("Landing...");
    }
}

void Navigator::EmergencyShutdown()
{
    Diagnostics::SetLED(255, 0, 0);
    ne_speed = 0;
    nw_speed = 0;
    se_speed = 0;
    sw_speed = 0;
    base_speed = 0;

    analogWrite(ne_pin, ne_speed + base_speed);
    analogWrite(nw_pin, nw_speed + base_speed);
    analogWrite(se_pin, se_speed + base_speed);
    analogWrite(sw_pin, sw_speed + base_speed);

    state = kLanded;
}

void Navigator::GoForward()
{
    if (state == kFlying)
    {
        forward = true;
        roll_offset += MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        sw_speed = 50;
        se_speed = 50;
    }
}

void Navigator::GoBack()
{
    if (state == kFlying)
    {
        backward = true;
        roll_offset -= MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        nw_speed = 50;
        ne_speed = 50;
    }
}

void Navigator::GoLeft()
{
    if (state == kFlying)
    {
        left = true;
        pitch_offset -= MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        ne_speed = 50;
        se_speed = 50;
    }
}

void Navigator::GoRight()
{
    if (state == kFlying)
    {
        forward = true;
        pitch_offset += MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        nw_speed = 50;
        sw_speed = 50;
    }
}

void Navigator::StopForward()
{
    if (state == kFlying)
    {
        forward = false;
        roll_offset -= MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        nw_speed = 0;
        ne_speed = 0;
        sw_speed = 0;
        se_speed = 0;
    }
}

void Navigator::StopBack()
{
    if (state == kFlying)
    {
        backward = true;
        roll_offset += MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        nw_speed = 0;
        ne_speed = 0;
        sw_speed = 0;
        se_speed = 0;
    }
}

void Navigator::StopLeft()
{
    if (state == kFlying)
    {
        left = false;
        pitch_offset += MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        nw_speed = 0;
        ne_speed = 0;
        sw_speed = 0;
        se_speed = 0;
    }
}

void Navigator::StopRight()
{
    if (state == kFlying)
    {
        forward = false;
        pitch_offset -= MOVEMENT_ANGLE;
    }
    else if (state == kTesting)
    {
        nw_speed = 0;
        ne_speed = 0;
        sw_speed = 0;
        se_speed = 0;
    }
}