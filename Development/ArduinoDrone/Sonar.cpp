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
    median_head = 0;
    log_head = 0;

    for (int i = 0; i < 10; i++)
    {
        Update();
    }
}

void Sonar::Update()
{
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

    long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);

    // Use the median of the last five values
    distance_median_buffer[median_head] = duration*0.034/2;
    median_head++;
    median_head %= SONAR_SENSITIVIY_BUFFER_SIZE;

    // After the first five calls, only up to one value should be 
    // out of place, so insertion sort should run quickly
    insertion_sort(distance_median_buffer, SONAR_SENSITIVIY_BUFFER_SIZE);
    distance = distance_median_buffer[2];

    distance_log[log_head] = distance;
    log_head++;
    log_head %= SONAR_DISTANCE_LOG_SIZE;
}

float Sonar::GetDistance()
{
    if (distance < SONAR_MAX_DISTANCE)
    {
        return distance;
    }
    else
    {
        return 0;
    }
}

bool Sonar::IsRising()
{
    float prev_value = distance_log[log_head];
    for (int i = 1; i < SONAR_DISTANCE_LOG_SIZE; ++i)
    {
        int index = (i + log_head) % SONAR_DISTANCE_LOG_SIZE;

        if (distance_log[index] <= prev_value)
        {
            return false;
        }
        else
        {
            prev_value = distance_log[index];
        }
    }
    return true;
}

bool Sonar::IsFalling()
{
    float prev_value = distance_log[log_head];
    float mean = 0;
    for (int i = 1; i < SONAR_DISTANCE_LOG_SIZE; ++i)
    {
        int index = (i + log_head) % SONAR_DISTANCE_LOG_SIZE;

        mean += distance_log[index] - prev_value;
        prev_value = distance_log[index];
    }

    if (mean / SONAR_DISTANCE_LOG_SIZE < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float Sonar::RisingRate()
{
    float total = 0;
    for (int i = 1; i < SONAR_DISTANCE_LOG_SIZE; ++i)
    {
        int index = (i + log_head) % SONAR_DISTANCE_LOG_SIZE;

        total += (distance_log[index] - distance_log[index - 1]);
    }
    return total / SONAR_DISTANCE_LOG_SIZE;
}

// I took this code directly from http://cforbeginners.com
// because Arduino doesn't support the <algorithm> header
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