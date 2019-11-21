#include <flameSensor/flameSensor.h>
#include <infraRouge/lecteurInfraRouge.h>
#include <suiveurLigne/suiveurLignesV2.h>
#include <Arduino.h>
#include <LED/LED.h>

#define allumer 1
#define etteind 0
#define flameDroit 0
#define flameCentre 2
#define flameGauche 1

void pompier(int outputPin)
{
    int read = InfraRougeValue();
    boolean droit = detectFlame(flameDroit);
    boolean gauche = detectFlame(flameGauche);
    boolean centre = detectFlame(flameCentre);

    suiveurLigneV2();

    if (droit)
    {
        LED(allumer);
        AX_BuzzerON(220, 250);
        MOTOR_SetSpeed(RIGHT, 0);
        MOTOR_SetSpeed(LEFT, .30);
        if (flameCentre)
        {
            MOTOR_SetSpeed(RIGHT, 0.20);
            MOTOR_SetSpeed(LEFT, 0.20);
        }
        delay(100);
    }

    if ((read > 250 && read < 500) && droit)
    {
        Serial.println("Lancer de l'eau!");
        digitalWrite(outputPin, HIGH); // on
        LED(allumer);
        AX_BuzzerON(220, 250);
        delay(100);
    }
    else
    {
        Serial.println("pas d'eau!");
        digitalWrite(outputPin, LOW); // off
        LED(etteind);
        AX_BuzzerOFF();
        delay(100);
    }
}

void pompierFlame(int outputPin)
{
    boolean droit = detectFlame(flameDroit);
    boolean centre = detectFlame(flameCentre);
    boolean gauche = detectFlame(flameGauche);

    suiveurLigneV2();

    if (droit || centre || gauche)
    {
        LED(allumer);
        AX_BuzzerON(220, 250);
        if(centre){
            Serial.println("Lancer de l'eau!");
            digitalWrite(13, HIGH); // on
        }
        else{
            Serial.println("pas d'eau!");
            digitalWrite(outputPin, LOW); // off
        }
    }
    else
    {
        Serial.println("pas d'eau!");
        digitalWrite(outputPin, LOW); // off
        LED(etteind);
        AX_BuzzerOFF();
        delay(10);
    }

    // if (droit)
    // {
    //     Serial.println("Lancer de l'eau!");
    //     digitalWrite(outputPin, HIGH); // on
    //     LED(allumer);
    //     AX_BuzzerON(220, 250);
    //     delay(100);
    // }
}

void trouverFlame()
{
    int read = InfraRougeValue();
    boolean droit = detectFlame(flameDroit);
    boolean gauche = detectFlame(flameGauche);
    boolean centre = detectFlame(flameCentre);

    if (droit)
    {
        MOTOR_SetSpeed(RIGHT, 0);
        MOTOR_SetSpeed(LEFT, .20);
        delay(100);
    }
    if (centre)
    {
        MOTOR_SetSpeed(RIGHT, 0.20);
        MOTOR_SetSpeed(LEFT, 0.20);
        if (read > 250 && read < 500)
        {
            MOTOR_SetSpeed(RIGHT, 0);
            MOTOR_SetSpeed(LEFT, 0);
        }
    }
    if (gauche)
    {
        MOTOR_SetSpeed(RIGHT, 0.30);
        MOTOR_SetSpeed(LEFT, 0);
        delay(100);
    }
}