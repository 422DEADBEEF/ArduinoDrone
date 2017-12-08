/******************************************************************************
*   File:           ArduinoDrone.ino
*
*   Description:    An Arduino sketch for a custom-built quadcopter Arduino
*                   drone as a final project for CSS 427 (Embedded Systems),
*                   University of Washington Bothell
*
*   Authors:        Team 0xDEADBEEF:
*                   Ryan Berge and Jeremy DeHaan
*
*   Date Created:   November 9th, 2017
*   Last Modified:  November 28th, 2017
*
******************************************************************************/
#include "Diagnostics.h"
#include "Navigator.h"
//#include "SongDefinitions.h"

namespace 
{
    BluetoothReceiver receiver;
    Navigator navigator;

    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool forward = false;
    bool back = false;
    bool lift = false;
}


void setup() 
{
    // Remote drone has no Serial connection
    Serial.begin(9600);
    

    Diagnostics::Initialize(RED_PIN, GREEN_PIN, BLUE_PIN, &receiver);
    
    Diagnostics::SetLED(255, 0, 0);
    receiver.Initialize();
    Diagnostics::SetLED(0, 0, 255);

    Diagnostics::SendBTMessage("Initializing...");

    bool init = navigator.Initialize(NE_MOTOR_PIN, NW_MOTOR_PIN, SE_MOTOR_PIN, SW_MOTOR_PIN);

    analogReference(INTERNAL);
    pinMode(12, OUTPUT);

    if (init)
    {
        Diagnostics::SetLED(0, 255, 0);
        Diagnostics::SendBTMessage("Systems Green.");
    }
    else
    {
        Diagnostics::SetLED(0, 0, 255);
        Diagnostics::SendBTMessage("Systems Not Green.");
    }

    Diagnostics::SendBTMessage("Entering main loop...");
    
}

void loop()
{
    CheckBattery();
    navigator.Update();

    if (receiver.Update())
    {
        if (receiver.IsDown(Buttons::UpButton))
        {
            if (!up)
            {
                Diagnostics::SendBTMessage("Ascend!");
                up = true;
                navigator.Ascend();
            }
        }
        else
        {
            up = false;
        }

        if (receiver.IsDown(Buttons::DownButton))
        {
            if (!down)
            {
                Diagnostics::SendBTMessage("Descend!");
                down = true;
                navigator.Descend();
            }
        }
        else
        {
            down = false;
        }

        if (receiver.IsDown(Buttons::RightButton))
        {
            if (!right)
            {
                Diagnostics::SendBTMessage("Right!");
                right = true;
                navigator.GoRight();
            }
        }
        else
        {
            if (right)
            {
                right = false;
                navigator.StopRight();
            }
        }

        if (receiver.IsDown(Buttons::LeftButton))
        {
            if (!left)
            {
                Diagnostics::SendBTMessage("Left!");
                left = true;
                navigator.GoLeft();
            }
        }
        else
        {
            if (left)
            {
                left = false;
                navigator.StopLeft();
            }
        }

        if (receiver.IsDown(Buttons::ForwardButton))
        {
            if (!forward)
            {
                Diagnostics::SendBTMessage("Forward!");
                forward = true;
                navigator.GoForward();
            }
        }
        else
        {
            if (forward)
            {
                forward = false;
                navigator.StopForward();
            }
        }

        if (receiver.IsDown(Buttons::BackwardButton))
        {
            if (!back)
            {
                Diagnostics::SendBTMessage("Back!");
                back = true;
                navigator.GoBack();
            }
        }
        else
        {
            if (back)
            {
                back = false;
                navigator.StopBack();
            }
        }

        if (receiver.IsDown(Buttons::OnOffButton))
        {
            navigator.EmergencyShutdown();
        }

        if (receiver.IsDown(Buttons::SecretButton))
        {
            if (!lift)
            {
                lift = true;

                if (navigator.state == kLanded)
                {
                    Diagnostics::SendBTMessage("Lift Off!");
                    navigator.LiftOff();
                }
                else
                {
                    Diagnostics::SendBTMessage("Land!");
                    navigator.Land();
                }
            }
        }
        else
        {
            lift = false;
        }
    }
}

void CheckBattery()
{
    int reading = analogRead(A3);
    //char buffer[10];
    //char* str = itoa(reading, buffer, 10);
    //Diagnostics::SendBTMessage(str);
    if (reading <= 590)
    {
        digitalWrite(12, HIGH);
    }
}