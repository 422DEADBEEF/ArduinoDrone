// Buzzer Prototype

#include "SongDefinitions.h"

const int kBuzzerPin = 9;

buzzer::Song mySong(0, kBuzzerPin);

void setup() 
{
    Serial.begin(9600);
    buzzer::MaryHadALittleLamb(mySong);
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
