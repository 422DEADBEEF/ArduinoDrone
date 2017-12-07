#ifndef SONAR_H
#define SONAR_H

#include "Util.h"

#define SONAR_SENSITIVIY_BUFFER_SIZE 5
#define SONAR_DISTANCE_LOG_SIZE 10
#define SONAR_MAX_DISTANCE 2000

class Sonar
{
public:
    Sonar();
    void Initialize();
    void Update();
    float GetDistance();

    bool IsRising();
    bool IsFalling();
    float RisingRate();

public:
    float distance;
    uint8_t state;
    bool waiting;
    long elapsed_time;
    long previous_time;

    // Ultrasonic sometimes gives oddly large values; reduce error
    // by only using the median of the last X data points to remove
    // outliers
    float distance_median_buffer[SONAR_SENSITIVIY_BUFFER_SIZE];

    // Keep a log of distances to see if the drone is rising or falling
    // and at what rate
    float distance_log[SONAR_DISTANCE_LOG_SIZE];

    int median_head;
    int log_head;
};

void insertion_sort(float arr[], int length);

#endif