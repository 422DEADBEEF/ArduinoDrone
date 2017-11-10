#include "BluetoothReceiver.h"

BluetoothReceiver::BluetoothReceiver()
{
}

void BluetoothReceiver::Initialize()
{
    BTserial.begin(38400);
}

void BluetoothReceiver::Update()
{
    state = 0;
    if (BTserial.available())
    {
        state = BTserial.read();
    }
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