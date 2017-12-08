#include "BluetoothReceiver.h"

BluetoothReceiver::BluetoothReceiver()
{
}

void BluetoothReceiver::Initialize()
{
    BTserial.begin(38400);
    state = 0;
}

bool BluetoothReceiver::Update()
{
    if (BTserial.available())
    {
        state = BTserial.read();
        BTserial.write(state);

        return true;
    }
    return false;
}

void BluetoothReceiver::SendMessage(const char* message)
{
    BTserial.println(message);
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