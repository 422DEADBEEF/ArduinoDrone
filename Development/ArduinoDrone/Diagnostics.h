/******************************************************************************
*   File:           Diagnostics.h
*
*   Description:    Originally, this system was intended to provide an array
*                   of features, including POST tests, LED controls, and 
*                   Bluetooth back-communication. It currently provides LED
*                   controls and nothing more.
*
*   Authors:        Team 0xDEADBEEF:
*                   Ryan Berge and Jeremy DeHaan
*
******************************************************************************/
#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include "Util.h"
#include "BluetoothReceiver.h"

namespace {
    DigitalPin red;
    DigitalPin blue;
    DigitalPin green;
    BluetoothReceiver* bt_receiver;
}

class Diagnostics
{
public:


    static void Initialize(DigitalPin Red, DigitalPin Green, DigitalPin Blue, BluetoothReceiver* bt)
    {
        red = Red;
        blue = Blue;
        green = Green;

        pinMode(RED_PIN, OUTPUT);
        pinMode(GREEN_PIN, OUTPUT);
        pinMode(BLUE_PIN, OUTPUT);

        bt_receiver = bt;
    }

    static void SetLED(uint8_t r, uint8_t g, uint8_t b)
    {
        digitalWrite(RED_PIN, r);
        digitalWrite(GREEN_PIN, g);
        digitalWrite(BLUE_PIN, b);
    }

    static void SendBTMessage(const char* message)
    {
        bt_receiver->SendMessage(message);
    }

    static float DroneAbs(float val)
    {
        return (val >= 0) ? val : -val;
    }
};

#endif