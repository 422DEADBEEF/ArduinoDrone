#ifndef UTIL_H
#define UTIL_H

#include "Arduino.h"

#define IMU_SDA_PIN 2
#define IMU_SCL_PIN 3

#define NE_MOTOR_PIN 9
#define NW_MOTOR_PIN 6
#define SE_MOTOR_PIN 5
#define SW_MOTOR_PIN 13

#define ULTRASONIC_TRIG_PIN 12
#define ULTRASONIC_ECHO_PIN 7

#define RED_PIN A0
#define GREEN_PIN A1
#define BLUE_PIN A2

#define BLUETOOTH_TX 10
#define BLUETOOTH_RX 11

enum class ButtonPins
{
    LeftButton = 30,
    RightButton,
    ForwardButton,
    BackwardButton,
    DownButton,
    UpButton,
    SecretButton,
    OnOffButton,
    ButtonCount = 8
};

enum class Buttons
{
    LeftButton = 1,
    RightButton = 2,
    ForwardButton = 4,
    BackwardButton = 8,
    DownButton = 16,
    UpButton = 32,
    SecretButton = 64,
    OnOffButton = 128,
};

typedef uint8_t ButtonState;

typedef uint8_t DigitalPin;
typedef uint8_t AnalogPin;
typedef uint8_t PwmPin;

typedef uint8_t MotorSpeed;

#endif