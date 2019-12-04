#include <Arduino.h>

long startTimer = 0;

bool timerLED(long maxTimer)
{
    bool value = 0;
    startTimer++;
    
    if (startTimer < maxTimer)
    {
        value = 0;
    }
    else if (startTimer < (2 * maxTimer))
    {
        value = 1;
    }
    else
    {
        startTimer = 0;
    }
    return value;
}

void allumerLED()
{
    if (timerLED(300))
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
    }
    else
    {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
    }
}

void eteindreLED()
{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
}

void LED(boolean action)
{
    if (action)
        allumerLED();
    else
        eteindreLED();
}