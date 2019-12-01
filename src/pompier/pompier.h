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

boolean motorOFF = false;
boolean flame = false;
long startTimerSV = 0;

bool timerPompier(long maxTimer)
{
    bool value = 0;

    startTimerSV++;
    if (startTimerSV < maxTimer)
    {
        value = 0;
    }
    else if (startTimerSV < (2 * maxTimer))
    {
        value = 1;
    }
    else
        startTimerSV = 0;

    return value;
}

void pompier(int outputPin)
{
    int read = InfraRougeValue();
    boolean droit = detectFlame(flameDroit);
    boolean gauche = detectFlame(flameGauche);
    boolean centre = detectFlame(flameCentre);

    // suiveurLigneV2(ON);

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

void setMotorSpeedZero()
{
    MOTOR_SetSpeed(RIGHT, 0);
    MOTOR_SetSpeed(LEFT, 0);
}

void trouverFlame()
{
    int read = InfraRougeValue();
    boolean droit = detectFlame(flameDroit);
    boolean gauche = detectFlame(flameGauche);
    boolean centre = detectFlame(flameCentre);

    if ((droit && !centre && !gauche))
    {
        while (!centre)
        {
            MOTOR_SetSpeed(RIGHT, 0);
            MOTOR_SetSpeed(LEFT, .15);
            centre = detectFlame(flameCentre);
        }
    }
    if (centre || (droit && centre && gauche))
    {
        // setMotorSpeedZero();
        // MOTOR_SetSpeed(LEFT, 0.20);
        if (read > 250 && read < 400)
        {
            setMotorSpeedZero();
            Serial.print("bonne distance");
            motorOFF = true;
        }
    }
    if (gauche && !centre && !droit)
    {
        MOTOR_SetSpeed(RIGHT, 0.15);
        MOTOR_SetSpeed(LEFT, 0);
        if (centre)
        {
            gauche = 0;
        }
    }
}

void pompierFlame(int outputPin, bool pompeOn, bool buzzerOn)
{
    boolean droit = detectFlame(flameDroit);
    boolean centre = detectFlame(flameCentre);
    boolean gauche = detectFlame(flameGauche);

    if (droit || centre || gauche)
    {
        flame = true;
        LED(allumer);

        if(buzzerOn)
            AX_BuzzerON(220, 250);

        trouverFlame();

        if (centre && pompeOn && motorOFF)
        {
            pinMode(outputPin, OUTPUT);
            while (timerPompier(80))
            {
                Serial.println("Lancer de l'eau!");
                digitalWrite(outputPin, HIGH); // on
            }
        }
        else
        {
            // Serial.println("pas d'eau!");
            digitalWrite(outputPin, LOW); // off
        }
    }
    else
    {
        motorOFF = false;
        suiveurLigneV2(flame);
        // Serial.println("pas d'eau!");
        digitalWrite(outputPin, LOW); // off
        LED(etteind);
        AX_BuzzerOFF();

        int a = timerPompier(2000);
        // Serial.println(a);

        if(a)
            flame = false;
    }
}