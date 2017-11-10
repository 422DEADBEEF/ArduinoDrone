#include "Controller.h"

Controller::Controller() : BTserial(SoftwareSerial(10, 11))
{
}

Controller::Controller(PwmPin rxPin, PwmPin txPin) : BTserial(SoftwareSerial(rxPin, txPin))
{
    //Bluetooth HC-05 runs at 38400
    BTserial.begin(38400); 

    // initialize the buttons
    for(int i = 0; i < (uint8_t)ButtonPins::ButtonCount; i++)
    {
        pinMode((uint8_t)ButtonPins::LeftButton + i, INPUT);
    }
}



ButtonState Controller::GetButtonState()
{
    ButtonState state = 0;

    for (int i = 0; i < (uint8_t)ButtonPins::ButtonCount; i++)
    {
        byte button = (1 << i);

        if (digitalRead((uint8_t)ButtonPins::LeftButton + i) == HIGH)
        {
            state |= button;
        }
    }

    return state;
}