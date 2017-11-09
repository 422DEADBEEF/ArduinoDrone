/******************************************************************************
*   File:           Motor.h
*   Class:          Motor
*
*   Description:    A controller class for an Arduino Qunqi L298N DC Stepper 
*                   Motor Controller
*
*   Project:        CSS 427 Embedded Systems, University of Washington Bothell
*
*   Authors:        Team 0xDEADBEEF:
*                   Ryan Berge and Jeremy DeHaan
*
*   Date Created:   November 9th, 2017
*   Last Modified:  November 9th, 2017
*
******************************************************************************/

#ifndef MOTOR_H
#define MOTOR_H

#include "Util.h"

class Motor
{
public:
    enum class Directions
    {
        None, Clockwise, Counterclockwise
    };

    Motor();
    Motor(DigitalPin dir1A, DigitalPin dir2A, PwmPin speedA,
          DigitalPin dir1B, DigitalPin dir2B, PwmPin speedB,
          Motor::Directions directionA, Motor::Directions directionB);
    
    void SetMotorADirection(Motor::Directions direction);
    void SetMotorASpeed(Motor::Directions direction);

    void SetMotorBDirection(MotorSpeed speed);
    void SetMotorBSpeed(MotorSpeed speed);

private:
    bool initialized;

    // Motor A
    DigitalPin dir1PinA;
    DigitalPin dir2PinA;
    PwmPin speedPinA;

    Motor::Directions directionA;

    MotorSpeed speedA;

    // Motor B
    DigitalPin dir1PinB;
    DigitalPin dir2PinB;
    PwmPin speedPinB;

    Motor::Directions directionB;
    
    MotorSpeed speedB;
};

#endif