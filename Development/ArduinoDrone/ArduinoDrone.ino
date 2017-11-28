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
*   Last Modified:  November 24th, 2017
*
******************************************************************************/
#include "Diagnostics.h"
#include "BluetoothReceiver.h"
//#include "SongDefinitions.h"
#include "Navigator.h"

namespace 
{
    BluetoothReceiver receiver;
    Navigator navigator;
    Sonar sonar;

    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool forward = false;
    bool back = false;
}


void setup() 
{
    // Remote drone has no Serial connection
    Serial.begin(9600);
    Diagnostics::Initialize(RED_PIN, GREEN_PIN, BLUE_PIN);
    
    receiver.Initialize();
    navigator.Initialize(NE_MOTOR_PIN, NW_MOTOR_PIN, SE_MOTOR_PIN, SW_MOTOR_PIN);
    //sonar.Initialize();

}

void loop()
{
    receiver.Update();
    navigator.Update();
    //sonar.Update();
    
    if (receiver.IsDown(Buttons::UpButton))
    {
        Serial.println("Ascend!");
        if (!up)
        {
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
        Serial.println("Descend!");
        if (!down)
        {
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
        Serial.println("Right!");
        if (!right)
        {
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
        Serial.println("Left!");
        if (!left)
        {
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
        Serial.println("Forward!");
        if (!forward)
        {
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
        Serial.println("Back!");
        if (!back)
        {
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
        if (navigator.state == kLanded)
        {
            navigator.LiftOff();
        }
        else
        {
            navigator.Land();
        }
    }
}