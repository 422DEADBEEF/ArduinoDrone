#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Util.h"
#include <SoftwareSerial.h>

class Controller
{
public:
    Controller();
    Controller(PwmPin rx_pin, PwmPin tx_pin);

    ButtonState GetButtonState();

private:

    SoftwareSerial BTserial;
    ButtonState lastState = 0;
};

#endif