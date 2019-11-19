#include <flameSensor/flameSensor.h>
#include <infraRouge/lecteurInfraRouge.h>
#include <Arduino.h>
#include <LED/LED.h>

#define allumer 1
#define etteind 0

void pompier(int outputPin)
{
    int read = InfraRougeValue();
    boolean b = detectFlame();

    if ((read > 250 && read < 500) && b)
    {
        Serial.println("Lancer de l'eau!");
        digitalWrite(13, HIGH); // sets the digital pin 13 on
        delay(100);
    }
    else
    {
        Serial.println("pas d'eau!");
        digitalWrite(13, LOW); // sets the digital pin 13 off
        delay(100);
    }
}

void pompierFlame(int outputPin)
{
    boolean b = detectFlame();

    if (b)
    {
        Serial.println("Lancer de l'eau!");
        digitalWrite(13, HIGH); // sets the digital pin 13 on
        LED(allumer);
        AX_BuzzerON(220, 250);
        delay(100);
    }
    else
    {
        Serial.println("pas d'eau!");
        digitalWrite(13, LOW); // sets the digital pin 13 off
        LED(etteind);
        AX_BuzzerOFF();
        delay(100);
    }
}