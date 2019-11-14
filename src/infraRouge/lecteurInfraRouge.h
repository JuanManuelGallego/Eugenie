#include<LibRobus.h>
#include<Arduino.h>

void InfraRougeValue()
{
    int read = ROBUS_ReadIR(0);
    Serial.println(read);

    if (read > 250 && read < 500)
    {
        Serial.println("Lancer de l'eau!");
    }
    delay(1000);
}