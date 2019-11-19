#include <Arduino.h>
#include <LibRobus.h>

bool last_Value;

void suiveurLigneV2()
{
    int A_X[8] = {0};

    A_X[0] = analogRead(A0) / 100;
    A_X[1] = analogRead(A1) / 100;
    A_X[2] = analogRead(A2) / 100;
    A_X[3] = analogRead(A3) / 100;
    A_X[4] = analogRead(A4) / 100;
    A_X[5] = analogRead(A5) / 100;
    A_X[6] = analogRead(A6) / 100;
    A_X[7] = analogRead(A7) / 100;
    //////////////////////////////////////////////////////////
    // Pin A3 et A4 sont les centrales
    // Si A_X > 0 Il y a un ligne noire
    // 0 : Blanc
    // 1 : Noir
    // 8  7  6  5  4  3  2  1
    // A7 A6 A5 A4 A3 A2 A1 A0
    // true : tourne a droite
    // false : trourne a gauche

    for (int i = 0; i <= 7; i++)
    {
        if (A_X[i] > 0)
            A_X[i] = 1;
    }

    if (A_X[0] && A_X[1])
    {
        MOTOR_SetSpeed(LEFT, 0);
        MOTOR_SetSpeed(RIGHT, .30);
        Serial.println("TOURNNNEEEE À DROITE!!!!!");
        last_Value = true;
    }

    else if (A_X[1] && A_X[2])
    {
        MOTOR_SetSpeed(LEFT, .20);
        MOTOR_SetSpeed(RIGHT, .30);
        Serial.println("Tu devrais penser a tourner a droite");
    }
    else if (A_X[2] && A_X[3])
    {
        MOTOR_SetSpeed(LEFT, .20);
        Serial.println("Tu devies un peu à gauche");
    }

    else if (A_X[3] && A_X[4])
    {
        MOTOR_SetSpeed(LEFT, .25);
        MOTOR_SetSpeed(RIGHT, .25);
        Serial.println("Tout droit");
    }
    else if (A_X[4] && A_X[5])
    {
        MOTOR_SetSpeed(RIGHT, .20);
        Serial.println("Tu devies un peu à droite");
    }
    else if (A_X[5] && A_X[6])
    {
        MOTOR_SetSpeed(RIGHT, .20);
        MOTOR_SetSpeed(LEFT, .30);
        Serial.println("Tu devrais penser a tourner a gauche");
    }
    else if (A_X[6] && A_X[7])
    {
        MOTOR_SetSpeed(RIGHT, 0);
        MOTOR_SetSpeed(LEFT, .30);
        Serial.println("TOURNNNEEEE À GAUCHE!!!!!");
        last_Value = false;
    }
    else if (last_Value)//Cherche un ligne
    {
        MOTOR_SetSpeed(LEFT, 0);
        MOTOR_SetSpeed(RIGHT, .30);
        Serial.println("TOURNNNEEEE À DROITE!!!!!");
    }
    else
    {
        MOTOR_SetSpeed(RIGHT, 0);
        MOTOR_SetSpeed(LEFT, .30);
        Serial.println("TOURNNNEEEE À GAUCHE!!!!!");
    }
}