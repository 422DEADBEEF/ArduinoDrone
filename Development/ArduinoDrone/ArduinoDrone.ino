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

#define NE_MOTOR_PIN 9
#define NW_MOTOR_PIN 6
#define SE_MOTOR_PIN 5
#define SW_MOTOR_PIN 13

namespace {
BluetoothReceiver receiver;
Navigator navigator;

bool left;
bool right;
bool up;
bool down;
}


void setup() 
{
    // Remote drone has no Serial connection
    // Serial.begin(9600);

    receiver.Initialize();
    navigator.Initialize(NE_MOTOR_PIN, NW_MOTOR_PIN, SE_MOTOR_PIN, SW_MOTOR_PIN);
}

void loop()
{
    receiver.Update();
    navigator.Update();

    if (receiver.IsDown(Buttons::UpButton))
    {
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

    if (receiver.IsDown(Buttons::BackButton))
    {
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

}