#include "fQueue.h"

fQueue queue;

void b1_isr()
{
    queue.push(b1_function);
}

void b2_isr()
{
    queue.push(b2_function);
}

void b3_isr()
{
    queue.push(b3_function);
}

void b1_function()
{
    Serial.println("Button one processed.");
}

void b2_function()
{
    Serial.println("Button two processed.");
}

void b3_function()
{
    Serial.println("Button three processed.");
}

void setup()
{
    attachInterrupt(0, b1_isr, RISING);
    attachInterrupt(1, b2_isr, RISING);
    attachInterrupt(2, b3_isr, RISING);
}

void loop()
{
    while (queue.get_size() > 0)
    {
        function_pointer f = queue.pop();
        f();
    }
}