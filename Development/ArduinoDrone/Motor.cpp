#include "Motor.h"

Motor::Motor() : initialized(false)
{
    // Motor A
    dir1PinA = -1;
    dir2PinA = -1;
    speedPinA = -1;

    directionA = Motor::Directions::None;
    speedA = 0;
    
    // Motor B
    dir1PinB = -1;
    dir2PinB = -1;
    speedPinB = -1;

    directionB = Motor::Directions::None;
    speedB = 0;
}

Motor::Motor(DigitalPin dir1A, DigitalPin dir2A, PwmPin speedPinA,
             DigitalPin dir1B, DigitalPin dir2B, PwmPin speedPinB,
             Motor::Directions directionA, Motor::Directions directionB) :
             dir1PinA(dir1A), dir2PinA(dir2A), speedPinA(speedPinA),
             dir1PinB(dir1B), dir2PinB(dir2B), speedPinB(speedPinB),
             directionA(directionA), directionB(directionB),
             speedA(0), speedB(0)
{
    pinMode(dir1PinA, OUTPUT);
    pinMode(dir2PinA, OUTPUT);
    pinMode(speedPinA, OUTPUT);

    pinMode(dir1PinB, OUTPUT);
    pinMode(dir2PinB, OUTPUT);
    pinMode(speedPinB, OUTPUT);

    initialized = true;

    SetMotorADirection(directionA);
    SetMotorBDirection(directionB);
}

void Motor::SetMotorADirection(Motor::Directions direction)
{
    if (!initialized)
    {
        Diagnostics::ErrorMessage("Cannot set MotorA Direction: Motor not initialized.");
        return;
    }

    switch (direction)
    {
    case Motor::Directions::Clockwise:
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        break;

    case Motor::Directions::Counterclockwise:
        digitalWrite(dir1PinA, HIGH);
        digitalWrite(dir2PinA, LOW);
        break;
        
    case Motor::Directions::None:
    default:
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, LOW);
        break;
    }
}

void Motor::SetMotorASpeed(MotorSpeed speed)
{
    if (!initialized)
    {
        Diagnostics::ErrorMessage("Cannot set MotorA Speed: Motor not initialized.");
        return;
    }

    analogWrite(speedPinA, speed);
}

void Motor::SetMotorBDirection(Motor::Directions direction)
{
    if (!initialized)
    {
        Diagnostics::ErrorMessage("Cannot set MotorB Direction: Motor not initialized.");
        return;
    }

    switch (direction)
    {
    case Motor::Directions::Clockwise:
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, HIGH);
        break;

    case Motor::Directions::Counterclockwise:
        digitalWrite(dir1PinB, HIGH);
        digitalWrite(dir2PinB, LOW);
        break;
        
    case Motor::Directions::None:
    default:
        digitalWrite(dir1PinB, LOW);
        digitalWrite(dir2PinB, LOW);
        break;
    }
}

void Motor::SetMotorBSpeed(MotorSpeed speed)
{
    if (!initialized)
    {
        Diagnostics::ErrorMessage("Cannot set MotorB Speed: Motor not initialized.");
        return;
    }

    analogWrite(speedPinB, speed);
}
