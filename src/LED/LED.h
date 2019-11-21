#include <Arduino.h>

void allumerLED()
{
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    delay(500);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    delay(500);
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