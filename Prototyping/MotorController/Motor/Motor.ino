//Code by Reichenstein7 (thejamerson.com)

//Keyboard Controls:
//
// 1 -Motor 1 Left
// 2 -Motor 1 Stop
// 3 -Motor 1 Right
//
// 4 -Motor 2 Left
// 5 -Motor 2 Stop
// 6 -Motor 2 Right

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

// Motor 1
int dir1PinA = 48;
int dir2PinA = 46;
int speedPinA = 9; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 44;
int dir2PinB = 42;
int speedPinB = 10; // Needs to be a PWM pin to be able to control motor speed

void setup() 
{  // Setup runs once per reset
        // initialize serial communication @ 9600 baud:
        Serial.begin(115200);

        //Define L298N Dual H-Bridge Motor Controller Pins

        pinMode(dir1PinA,OUTPUT);
        pinMode(dir2PinA,OUTPUT);
        pinMode(speedPinA,OUTPUT);
        //pinMode(dir1PinB,OUTPUT);
        //pinMode(dir2PinB,OUTPUT);
        //pinMode(speedPinB,OUTPUT);
}

int ReadSerialInt()
{
    char buffer[255];
    int index = 0;
    while (Serial.available())
    {
        buffer[index++] = Serial.read();
        delay(10);
    }
    buffer[index++] = 0;

    return atoi(buffer);
}

void loop() 
{

    // Initialize the Serial interface:

    if (Serial.available() > 0) 
    {
        int speed = ReadSerialInt();
        //int speed = 255;
       
        analogWrite(speedPinA, speed);
        digitalWrite(dir1PinA, LOW);
        digitalWrite(dir2PinA, HIGH);
        Serial.print("Motor1 set to: ");
        Serial.println(speed);
/*
        switch (inByte) 
        {

            //______________Motor 1______________

            
            case '1': // Motor 1 Forward
            analogWrite(speedPinA, 64);//Sets speed variable via PWM 
            digitalWrite(dir1PinA, LOW);
            digitalWrite(dir2PinA, HIGH);
            Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
            Serial.println("   "); // Creates a blank line printed on the serial monitor
            break;

            case '2': // Motor 1 Stop (Freespin)
            analogWrite(speedPinA, 0);
            digitalWrite(dir1PinA, LOW);
            digitalWrite(dir2PinA, HIGH);
            Serial.println("Motor 1 Stop");
            Serial.println("   ");
            break;

            case '3': // Motor 1 Reverse
            analogWrite(speedPinA, 255);
            digitalWrite(dir1PinA, HIGH);
            digitalWrite(dir2PinA, LOW);
            Serial.println("Motor 1 Reverse");
            Serial.println("   ");
            break;

            //______________Motor 2______________

            case '4': // Motor 2 Forward
            analogWrite(speedPinB, 255);
            digitalWrite(dir1PinB, LOW);
            digitalWrite(dir2PinB, HIGH);
            Serial.println("Motor 2 Forward");
            Serial.println("   ");
            break;

            case '5': // Motor 1 Stop (Freespin)
            analogWrite(speedPinB, 0);
            digitalWrite(dir1PinB, LOW);
            digitalWrite(dir2PinB, HIGH);
            Serial.println("Motor 2 Stop");
            Serial.println("   ");
            break;

            case '6': // Motor 2 Reverse
            analogWrite(speedPinB, 255);
            digitalWrite(dir1PinB, HIGH);
            digitalWrite(dir2PinB, LOW);
            Serial.println("Motor 2 Reverse");
            Serial.println("   ");
            break;

            default:
            // turn all the connections off if an unmapped key is pressed:
            for (int thisPin = 2; thisPin < 11; thisPin++) 
            {
                digitalWrite(thisPin, LOW);
            }
            
        }
        */
    }
}
