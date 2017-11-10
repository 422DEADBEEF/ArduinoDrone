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
*   Last Modified:  November 9th, 2017
*
******************************************************************************/
#include "Diagnostics.h"
#include "Motor.h"
#include "BluetoothReceiver.h"

Motor left_motor;
Motor right_motor;

BluetoothReceiver receiver;

MotorSpeed speed;

void setup() 
{
    // Remote drone has no Serial connection
    //Serial.begin(9600);

    receiver.Initialize();

    // In1, In2, EnA, In3, In4, EnB
    left_motor = Motor(24, 25, 9, 28, 29, 8, 
        Motor::Directions::Clockwise, Motor::Directions::Clockwise);
    
    // In1, In2, EnA, In3, In4, EnB
    right_motor = Motor(31, 32, 7, 35, 36, 6,
        Motor::Directions::Counterclockwise, Motor::Directions::Counterclockwise);

    // TODO: Do something if POST fails
    bool passed = Diagnostics::post();
}

void loop()
{
    receiver.Update();

    if (receiver.IsDown(Buttons::ForwardButton))
    {
        if ((speed + 8) > 255)
        {
            speed = 255;
        }
        else
        {
            speed += 8;
        }
        
        delay(80);
        left_motor.SetMotorASpeed(speed);

        //Serial.println(speed);
    }

    if (receiver.IsDown(Buttons::BackwardButton))
    {
        if ((speed - 8) < 0)
        {
            speed = 0;
        }
        else
        {
            speed -= 8;
        }

        delay(80);
        left_motor.SetMotorASpeed(speed);
        //Serial.println(speed);
    }
}