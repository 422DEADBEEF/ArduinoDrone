#ifndef SONAR_H
#define SONAR_H

#include "Util.h"

class Sonar
{
public:
    Sonar();
    void Initialize();
    void Update();
    float GetDistance();

public:
    float distance;
    uint8_t state;
    bool waiting;
    long elapsed_time;
    long previous_time;

    float distances[10];
    int head;
};

void insertion_sort(float arr[], int length);

#endif