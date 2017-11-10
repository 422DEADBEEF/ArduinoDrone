#ifndef UTIL_H
#define UTIL_H

#include "Arduino.h"

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