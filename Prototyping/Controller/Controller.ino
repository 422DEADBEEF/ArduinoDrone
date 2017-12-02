#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX
// Connect the Bluetooth TX to the Arduino RX on pin 10.
// Connect the Bluetooth RX to the Arduino TX on pin 11.

enum ButtonPins{
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


typedef byte ButtonState;

ButtonState lastState = 0;

ButtonState getButtonState()
{
  ButtonState state = 0;
  
  for(int i = 0; i < ButtonCount; i++)
  {
    byte button = (1 << i);

    if(digitalRead(LeftButton+i) == HIGH)
      state |= button;
  }

  return state;
  
}

void setup() {

  //Bluetooth HC-05 runs at 38400
  BTserial.begin(38400); 
  Serial.begin(9600);
  
  // initialize the buttons
  for(int i = 0; i < ButtonCount; i++)
  {
    pinMode(LeftButton+i, INPUT);
  }
  
}

void loop() {
  // read the state of the pushbutton value:
  ButtonState state = getButtonState();

  if(state != lastState)
    BTserial.write(state);

  lastState = state;

  if(BTserial.available() > 0)
  {
    while(BTserial.available() > 0)
    {
      Serial.print((char)BTserial.read());
    }
  }
}
