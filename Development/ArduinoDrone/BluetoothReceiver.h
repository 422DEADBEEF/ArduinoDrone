/******************************************************************************
*   Class:          BluetoothReceiver
*
*   Description:    A receiver class for Bluetooth communication
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

#ifndef BLUETOOTH_RECEIVER_H
#define BLUETOOTH_RECEIVER_H

#include "Util.h"
#include <SoftwareSerial.h>

namespace {
    SoftwareSerial BTserial(10, 11);
}

class BluetoothReceiver
{
public:
    BluetoothReceiver();

    // Starts the UART SoftwareSerial connection
    void Initialize();

    // Send a message over the BT connection
    void SendMessage(const char* message);

    // Updates the button state by reading from the connection
    bool Update();

    // Checks to see if a particular button is pressed
    bool IsDown(Buttons button);

    ButtonState GetButtonState() const;

private:
    ButtonState state;
};

#endif