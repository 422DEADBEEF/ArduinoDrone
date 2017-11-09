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

Motor left_motor;
Motor right_motor;

void setup() 
{
    left_motor = Motor(24, 25, 9, 28, 29, 8, 
        Motor::Directions::Clockwise, Motor::Directions::Counterclockwise);
    
    right_motor = Motor(31, 32, 7, 35, 36, 6,
        Motor::Directions::Clockwise, Motor::Directions::Counterclockwise);

    // TODO: Do something if POST fails
    bool passed = Diagnostics.post();


}

void loop()
{

}