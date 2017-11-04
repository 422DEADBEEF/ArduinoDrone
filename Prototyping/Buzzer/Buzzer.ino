// Buzzer Prototype

const int kBuzzerPin = 9;

void setup() 
{
        Serial.begin(9600);
        pinMode(kBuzzerPin, OUTPUT);
}

void loop() 
{
    if (Serial.available()) 
    {
        char command = Serial.read();
        if (command == '1')
        {
            // buzz
            tone(kBuzzerPin, 1000);
        }
        else
        {
            // stop buzzing
            noTone(kBuzzerPin);
        }
    }
}
