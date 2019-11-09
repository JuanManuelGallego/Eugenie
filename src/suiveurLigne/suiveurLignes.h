#include <Arduino.h>

float suiveurLigneValue()
{
    int x = analogRead(A0);
    float v = x * (5.0 / 1023.0);
    return v;
}

void suiveurLigne(int noRobot)
{
    float v = suiveurLigneValue();

    if (v > 4.9) // ChercherLigne();
    {
        Serial.println("TOUT BLANC");
        Avancer(5, 0.15, noRobot);
    }
    else if (v > 4.0) // TournerDroite
    {
        Serial.println("DROITE");
        MOTOR_SetSpeed(LEFT, 0.2);
    }
    else if (v > 3.0) // Tout droit
    {
        Serial.println("TOUT DROIT");
        Avancer(2.5, 0.15, noRobot);
    }
    else if (v > 1) // Tourner Gauche
    {
        Serial.println("GAUCHE");
        MOTOR_SetSpeed(RIGHT, 0.2);
    }
    else
    {
        Serial.println("TOUT NOIR");
    }
}