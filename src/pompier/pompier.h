#include <flameSensor/flameSensor.h>
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

void buzzer(boolean buzzerOn)
{
    if (buzzerOn)
    {
        if (timerPompier(300))
            AX_BuzzerON(220, 250);
        else
            AX_BuzzerOFF();
    }
}

void setMotorSpeedZero()
{
    MOTOR_SetSpeed(RIGHT, 0);
    MOTOR_SetSpeed(LEFT, 0);
}

void LEDBuzzer(boolean buzzerOn)
{
    LED(allumer);
    buzzer(buzzerOn);
}

void trouverFlame(boolean buzzerOn)
{
    int read = ROBUS_ReadIR(3);
    boolean droit = detectFlame(flameDroit);
    boolean gauche = detectFlame(flameGauche);
    boolean centre = detectFlame(flameCentre);

    if ((droit && !centre && !gauche))
    {
        if (!centre)
        {
            LEDBuzzer(buzzerOn);
            MOTOR_SetSpeed(RIGHT, 0);
            MOTOR_SetSpeed(LEFT, .1);
            centre = detectFlame(flameCentre);
        }
    }
    if (centre || (droit && centre && gauche))
    {
        LEDBuzzer(buzzerOn);
        // MOTOR_SetSpeed(LEFT, 0.1);
        // MOTOR_SetSpeed(RIGHT, 0.1);
        if (read > 250 && read < 300)
        {
            setMotorSpeedZero();
            Serial.print("bonne distance");
            motorOFF = true;
        }
    }
    if (gauche && !centre && !droit)
    {
        if (!centre)
        {
            LEDBuzzer(buzzerOn);
            MOTOR_SetSpeed(RIGHT, 0.1);
            MOTOR_SetSpeed(LEFT, 0);
            centre = detectFlame(flameCentre);
        }
    }
}

void pompierFlame(int pompePin, bool pompeOn, bool buzzerOn)
{
    boolean droit = detectFlame(flameDroit);
    boolean centre = detectFlame(flameCentre);
    boolean gauche = detectFlame(flameGauche);

    if (droit || centre || gauche)
    {
        flame = true;
        LED(allumer);

        buzzer(buzzerOn);

        trouverFlame(buzzerOn);

        if (centre && pompeOn && motorOFF)
        {
            pinMode(pompePin, OUTPUT);
            while (timerPompier(80))
            {
                digitalWrite(pompePin, HIGH); // on
            }
        }
        else
        {
            digitalWrite(pompePin, LOW); // off
        }
    }
    else
    {
        motorOFF = false;
        suiveurLigneV2(flame);
        digitalWrite(pompePin, LOW); // off
        LED(etteind);
        AX_BuzzerOFF();

        if (timerPompier(2000))
            flame = false;
    }
}