#include "Navigator.h"
#include "Diagnostics.h"


Navigator::Navigator() : pitch_offset(0), roll_offset(0), ne_speed(0), nw_speed(0), 
                         se_speed(0), sw_speed(0), base_speed(0), forward(false), 
                         backward(false), left(false), right(false)
{
}

void Navigator::Initialize(PwmPin ne, PwmPin nw, PwmPin se, PwmPin sw)
{
    ne_pin = ne;
    nw_pin = nw;
    se_pin = se;
    sw_pin = sw;

    Diagnostics::SetLED(255, 0, 0);
    if (imu.Initialize())
    {
        pinMode(ne_pin, OUTPUT);
        pinMode(nw_pin, OUTPUT);
        pinMode(se_pin, OUTPUT);
        pinMode(sw_pin, OUTPUT);
        Diagnostics::SetLED(0, 255, 0);
    }

    sonar.Initialize();
    state = kLanded;
    kHoverSpeed = 200;
}

void Navigator::Update()
{
    imu.Update();
    sonar.Update();

    float pitch = imu.GetPitch();
    float roll = imu.GetRoll();

    if (state != kLanded)
    {
        float roll_angle = roll - roll_offset;

        if (abs(roll_angle) > STABILIZER_THRESHOLD)
        {
            if (roll_angle > 0)
            {
                // we are tilting too far forward
                if (base_speed < kHoverSpeed)
                {
                    ne_speed += SENSITIVITY;
                    nw_speed += SENSITIVITY;
                }
                else
                {
                    se_speed -= SENSITIVITY;
                    sw_speed -= SENSITIVITY;
                }
            }
            else if (roll_angle < 0)
            {
                // we are tilting backward
                if (base_speed < kHoverSpeed)
                {
                    se_speed += SENSITIVITY;
                    sw_speed += SENSITIVITY;
                }
                else
                {
                    ne_speed -= SENSITIVITY;
                    nw_speed -= SENSITIVITY;
                }
            }
        }

        float pitch_angle = pitch - pitch_offset;
        
        if (abs(pitch_angle) > STABILIZER_THRESHOLD)
        {
            if (pitch_angle > 0)
            {
                // we are tilting too far right
                if (base_speed < kHoverSpeed)
                {
                    ne_speed += SENSITIVITY;
                    se_speed += SENSITIVITY;
                }
                else
                {
                    nw_speed -= SENSITIVITY;
                    sw_speed -= SENSITIVITY;
                }
            }
            else if (pitch_angle < 0)
            {
                // we are tilting too far left
                if (base_speed < kHoverSpeed)
                {
                    nw_speed += SENSITIVITY;
                    sw_speed += SENSITIVITY;
                }
                else
                {
                    ne_speed -= SENSITIVITY;
                    se_speed -= SENSITIVITY;
                }
            }
        }

        if (state == kTakingOff)
        {
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
                    return;
                }

                base_speed += ASCENSION_RATE;
            }
        }

        if (state == kStabilizing)
        {
            Diagnostics::SetLED(200, 40, 220);
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
                if (abs(sonar.RisingRate()) < STABLE_CONSTANT)
                {
                    state = kFlying;
                    kHoverSpeed = base_speed;
                    Diagnostics::SetLED(0, 255, 0);
                }
            }
        }

        if (state == kLanding)
        {
            if (sonar.IsFalling())
            {
                if (sonar.GetDistance() < LANDING_THRESHOLD)
                {
                    state = kLanded;
                    EmergencyShutdown();
                    delay(2000);
                    Diagnostics::SetLED(0, 255, 0);
                }
            }
            else
            {
                if (base_speed - ASCENSION_RATE >= 0)
                {
                    base_speed -= ASCENSION_RATE;
                }
            }
        }

        analogWrite(ne_pin, ((ne_speed + base_speed) <= 255) ? ne_speed + base_speed : 255);
        analogWrite(nw_pin, ((nw_speed + base_speed) <= 255) ? nw_speed + base_speed : 255);
        analogWrite(se_pin, ((se_speed + base_speed) <= 255) ? se_speed + base_speed : 255);
        analogWrite(sw_pin, ((sw_speed + base_speed) <= 255) ? sw_speed + base_speed : 255);
    }
}

void Navigator::Ascend()
{
    if ((ne_speed + ASCENSION_RATE + base_speed) < MAX_BASE_SPEED &&
        (nw_speed + ASCENSION_RATE + base_speed) < MAX_BASE_SPEED &&
        (se_speed + ASCENSION_RATE + base_speed) < MAX_BASE_SPEED &&
        (sw_speed + ASCENSION_RATE + base_speed) < MAX_BASE_SPEED)
    {
        base_speed += ASCENSION_RATE;

        analogWrite(ne_pin, ne_speed + base_speed);
        analogWrite(nw_pin, nw_speed + base_speed);
        analogWrite(se_pin, se_speed + base_speed);
        analogWrite(sw_pin, sw_speed + base_speed);
    }
    else
    {
        // Cannot safely rise
        // LED? Bluetooth info?
    }
}

void Navigator::Descend()
{
    if (base_speed > 0)
    {
        if (base_speed > ASCENSION_RATE)
        {
            base_speed -= ASCENSION_RATE;
        }
        else
        {
            base_speed = 0;
        }

        if (base_speed == 0)
        {
            ne_speed = 0;
            nw_speed = 0;
            se_speed = 0;
            sw_speed = 0;
        }

        analogWrite(ne_pin, (ne_speed + base_speed > 0) ? ne_speed + base_speed : 0);
        analogWrite(nw_pin, (nw_speed + base_speed > 0) ? nw_speed + base_speed : 0);
        analogWrite(se_pin, (se_speed + base_speed > 0) ? se_speed + base_speed : 0);
        analogWrite(sw_pin, (sw_speed + base_speed > 0) ? sw_speed + base_speed : 0);
    }
}

void Navigator::LiftOff()
{
    state = kTakingOff;
    Diagnostics::SetLED(255, 140, 0);
}

void Navigator::Land()
{
    state = kLanding;
    Diagnostics::SetLED(255, 140, 0);    
}

void Navigator::EmergencyShutdown()
{
    ne_speed = 0;
    nw_speed = 0;
    se_speed = 0;
    sw_speed = 0;
    base_speed = 0;

    analogWrite(ne_pin, ne_speed + base_speed);
    analogWrite(nw_pin, nw_speed + base_speed);
    analogWrite(se_pin, se_speed + base_speed);
    analogWrite(sw_pin, sw_speed + base_speed);
}

void Navigator::GoForward()
{
    if (state == kFlying)
    {
        forward = true;
        roll_offset += MOVEMENT_ANGLE;
    }
}

void Navigator::GoBack()
{
    if (state == kFlying)
    {
        backward = true;
        roll_offset -= MOVEMENT_ANGLE;
    }
}

void Navigator::GoLeft()
{
    if (state == kFlying)
    {
        left = true;
        pitch_offset -= MOVEMENT_ANGLE;
    }
}

void Navigator::GoRight()
{
    if (state == kFlying)
    {
        forward = true;
        pitch_offset += MOVEMENT_ANGLE;
    }
}

void Navigator::StopForward()
{
    if (state == kFlying)
    {
        forward = false;
        roll_offset -= MOVEMENT_ANGLE;
    }
}

void Navigator::StopBack()
{
    if (state == kFlying)
    {
        backward = true;
        roll_offset += MOVEMENT_ANGLE;
    }
}

void Navigator::StopLeft()
{
    if (state == kFlying)
    {
        left = false;
        pitch_offset += MOVEMENT_ANGLE;
    }
}

void Navigator::StopRight()
{
    if (state == kFlying)
    {
        forward = false;
        pitch_offset -= MOVEMENT_ANGLE;
    }
}