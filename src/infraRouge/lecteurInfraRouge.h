#include <LibRobus.h>
#include <Arduino.h>

int InfraRougeValue()
{
    int read = ROBUS_ReadIR(0);
    Serial.println(read);
    if ((read > 250 && read < 500))
    {
        Serial.println("Bonne distance");
    }
    return read;
}