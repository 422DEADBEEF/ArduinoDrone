#ifndef FQUEUE_H
#define FQUEUE_H

#include "Arduino.h"

#define QUEUE_MAX_SIZE 255

typedef void (*function_pointer)();

class fQueue
{
public:
    fQueue();
    
    void push(function_pointer);
    function_pointer pop();

    int get_size();

private:
    function_pointer queue[QUEUE_MAX_SIZE];
    int head;
    uint8_t size;
};

fQueue::fQueue()
{
    head = 0;
    size = 0;
}

int fQueue::get_size()
{
    return size;
}

void fQueue::push(function_pointer f)
{
    // queue is full
    if (size >= QUEUE_MAX_SIZE)
    {
        // probably should be some sort of error message here
        return;
    }

    // safety
    noInterrupts();

    size++;
    queue[head] = f;
    head++;
    head %= QUEUE_MAX_SIZE;

    interrupts();
}

function_pointer fQueue::pop()
{
    // queue is empty
    if (size == 0)
    {
        return NULL;
    }

    noInterrupts();
    size--;
    if (head == 0) 
    {
        head = 255;
    }
    else
    {
        head--;
    }

    function_pointer temp = queue[head];
    
    interrupts();

    return temp;
}


#endif