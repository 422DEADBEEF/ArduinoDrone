#include "BluetoothReceiver.h"

BluetoothReceiver::BluetoothReceiver()
{
}

void BluetoothReceiver::Initialize()
{
    BTserial.begin(38400);
    state = 1;

    //while (!Update());
}

bool BluetoothReceiver::Update()
{
    if (BTserial.available())
    {
        ButtonState newState = BTserial.read();
        return true;
    }
    return false;
}

void BluetoothReceiver::SendMessage(const char* message)
{
    BTserial.println(message);
}

ButtonState BluetoothReceiver::GetButtonState() const
{
    return state;
}

bool BluetoothReceiver::IsDown(Buttons button)
{
    if ((state & (uint8_t)button) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}