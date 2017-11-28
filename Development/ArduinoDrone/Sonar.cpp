#include "Sonar.h"

Sonar::Sonar()
{
}

void Sonar::Initialize()
{
    
    pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
    pinMode(ULTRASONIC_ECHO_PIN, INPUT);

    previous_time = micros();
    waiting = false;
    state = 0;
    head = 0;
}

void Sonar::Update()
{
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

    long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);

    distances[head] = duration*0.034/2;
    head++;
    head %= 10;
    insertion_sort(distances, 10);
    distance = (distances[4] + distances[5]) / 2;
}

float Sonar::GetDistance()
{
    return distance;
}

// I took this code directly from http://cforbeginners.com
// because Arduino doesn't support <algorithm>
void insertion_sort(float arr[], int length)
{
    int j, temp;

    for (int i = 0; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j] < arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}