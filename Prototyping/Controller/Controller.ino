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

char droneMessage[100];
int messagePos = 0;
short droneSequence = 0;

short commandSequence = 0;
const int RESEND_TIMEOUT = 6000;
int resendTimer = 0;
bool waitForACK = false;

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
  {
    Serial.print("Controller: Sending Command #");
    Serial.println(commandSequence);
    BTserial.write(state);
    waitForACK = true;
  }

  lastState = state;

  if(BTserial.available() > 0)
  {
    byte receivedByte = BTserial.read();
    if(receivedByte == 1)
    {
      Serial.print("Controller: ACK for Command # ");
      Serial.print(commandSequence);
      Serial.println(" received.");
      commandSequence++;
      waitForACK = false;
      resendTimer = 0;
    }
    else
    {
      char nextChar = (char)receivedByte;
      if(nextChar == '\n')
      {
        droneMessage[messagePos] = '\0';
        Serial.print("Drone Message #");
        Serial.print(droneSequence);
        Serial.print(": ");
        Serial.println(droneMessage);

        droneSequence++;
        messagePos = 0;
      }
      else
      {
        droneMessage[messagePos] = nextChar;
        messagePos++;
      }
    }
  }

  if(waitForACK)
  {
    resendTimer++;

    if(resendTimer == RESEND_TIMEOUT)
    {
      Serial.print("Controller: Re-Sending Command #");
      Serial.println(commandSequence);
      BTserial.write(lastState);
    }
  }
}
