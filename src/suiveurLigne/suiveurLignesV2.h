#include <Arduino.h>
#include <LibRobus.h>

bool last_Value = true;

// 0 : Blanc
// 1 : Noir
// true : tourne a droite
// false : trourne a gauche

void suiveurLigneV2(bool active)
{
    int A_X[8] = {0};
    A_X[0] = digitalRead(33);
    A_X[1] = digitalRead(22);
    A_X[2] = digitalRead(48);
    A_X[3] = digitalRead(46);
    A_X[4] = digitalRead(44);
    A_X[5] = digitalRead(42);
    A_X[6] = digitalRead(40);
    A_X[7] = digitalRead(38);

    if (!active)
    {
        if (A_X[0])
        {
            MOTOR_SetSpeed(LEFT, -.15);
            MOTOR_SetSpeed(RIGHT, .25);
            last_Value = true;
        }
        else if (A_X[1])
        {
            MOTOR_SetSpeed(LEFT, .15);
            MOTOR_SetSpeed(RIGHT, .25);
            last_Value = true;
        }
        else if (A_X[2])
        {
            MOTOR_SetSpeed(LEFT, .15);
            last_Value = true;
        }
        else if (A_X[3])
        {
            MOTOR_SetSpeed(LEFT, .25);
            MOTOR_SetSpeed(RIGHT, .25);
        }
        else if (A_X[4])
        {
            MOTOR_SetSpeed(LEFT, .25);
            MOTOR_SetSpeed(RIGHT, .25);
        }
        else if (A_X[5])
        {
            MOTOR_SetSpeed(RIGHT, .15);
            last_Value = false;
        }
        else if (A_X[6])
        {
            MOTOR_SetSpeed(RIGHT, .15);
            MOTOR_SetSpeed(LEFT, .25);
            last_Value = false;
        }
        else if (A_X[7])
        {
            MOTOR_SetSpeed(RIGHT, -.15);
            MOTOR_SetSpeed(LEFT, .25);
            last_Value = false;
        }
        else if (!last_Value)
        {
            MOTOR_SetSpeed(RIGHT, -.25);
            MOTOR_SetSpeed(LEFT, .25);
        }
        else if (last_Value) //Cherche une ligne
        {
            MOTOR_SetSpeed(LEFT, -.25);
            MOTOR_SetSpeed(RIGHT, .25);
        }
    }
}