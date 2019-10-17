#include<LibRobus.h>

void infrarouge1()
{
    int read = ROBUS_ReadIR(0);
    printf("valeur: %d", read);
    Serial.print(read);

    if (read < 200)
    {
        Avancer(10, 0.25, 1);
    }
}