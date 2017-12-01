// Buzzer Prototype

#include "SongDefinitions.h"

const int kBuzzerPin = A5;

buzzer::Song mySong(0, kBuzzerPin);

void setup() 
{
    Serial.begin(9600);
    buzzer::Valkyries(mySong);
}

bool ran = false;

void loop() 
{
    mySong.Update();

    if (!ran)
    {       
        mySong.Start();
        ran = true;
    }
}
