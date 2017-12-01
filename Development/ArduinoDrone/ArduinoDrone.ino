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
#include "SongDefinitions.h"

namespace 
{
    BluetoothReceiver receiver;
    Navigator navigator;
    buzzer::Song valkyries(0, A5);

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
    Serial.println("Initializing...");

    buzzer::Valkyries(valkyries);
    valkyries.Start();

    Diagnostics::Initialize(RED_PIN, GREEN_PIN, BLUE_PIN, &receiver);
    
    receiver.Initialize();
    if (navigator.Initialize(NE_MOTOR_PIN, NW_MOTOR_PIN, SE_MOTOR_PIN, SW_MOTOR_PIN))
    {
        Diagnostics::SetLED(0, 255, 0);
        Diagnostics::SendBTMessage("1");
    }
    else
    {
        Diagnostics::SetLED(0, 0, 255);
        Diagnostics::SendBTMessage("2");
    }

    valkyries.Start();
    while (valkyries.playing)
    {
        valkyries.Update();
    }

    Serial.println("Entering main loop...");
    
}

void loop()
{
    navigator.Update();

    if (receiver.Update())
    {
        if (receiver.IsDown(Buttons::UpButton))
        {
            if (!up)
            {
                Serial.println("Ascend!");
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
                Serial.println("Descend!");
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
                Serial.println("Right!");
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
                Serial.println("Left!");
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
                Serial.println("Forward!");
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
                Serial.println("Back!");
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
                    Serial.println("Lift Off!");
                    navigator.LiftOff();
                }
                else
                {
                    Serial.println("Land!");
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