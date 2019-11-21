#include <Arduino.h>
#include <LibRobus.h>

bool last_Value;

void suiveurLigneV2()
{
    //////////////////////////////////////////////////////////
    // Pin A3 et A4 sont les centrales
    // Si A_X > 0 Il y a un ligne noire
    // 0 : Blanc
    // 1 : Noir
    // 8  7  6  5  4  3  2  1
    // A7 A6 A5 A4 A3 A2 A1 A0
    // true : tourne a droite
    // false : trourne a gauche
    /////////////////////////////////////////////////////////
    int A_X[8] = {0};
    delay(50);
    // A_X[0] = digitalRead(38) ;
    // A_X[1] = digitalRead(40) ;
    // A_X[2] = digitalRead(42) ;
    // A_X[3] = digitalRead(44) ;
    // A_X[4] = digitalRead(46) ;
    // A_X[5] = digitalRead(48) ;
    // A_X[6] = digitalRead(22) ;
    // A_X[7] = digitalRead(33) ;
    A_X[0] = digitalRead(33);
    A_X[1] = digitalRead(22);
    A_X[2] = digitalRead(48);
    A_X[3] = digitalRead(46);
    A_X[4] = digitalRead(44);
    A_X[5] = digitalRead(42);
    A_X[6] = digitalRead(40);
    A_X[7] = digitalRead(38);
    Serial.print(A_X[0]);
    Serial.print(A_X[1]);
    Serial.print(A_X[2]);
    Serial.print(A_X[3]);
    Serial.print(A_X[4]);
    Serial.print(A_X[5]);
    Serial.print(A_X[6]);
    Serial.println(A_X[7]);
    // // for (int i = 0; i <= 7; i++)
    // // {
    // //     if (A_X[i] > 0)
    // //         A_X[i] = 1;
    // // }

    if (A_X[0])
    {
        MOTOR_SetSpeed(LEFT, 0);
        MOTOR_SetSpeed(RIGHT, .25);
        Serial.println("TOURNNNEEEE À DROITE!!!!! 0_1");
        last_Value = true;
    }
    else if (A_X[1])
    {
        MOTOR_SetSpeed(LEFT, .15);
        MOTOR_SetSpeed(RIGHT, .25);
        Serial.println("Tu devrais penser a tourner a droite");
    }
    else if (A_X[2])
    {
        MOTOR_SetSpeed(LEFT, .15);
        Serial.println("Tu devies un peu à gauche");
    }
    else if (A_X[3])
    {
        MOTOR_SetSpeed(LEFT, .25);
        MOTOR_SetSpeed(RIGHT, .25);
        Serial.println("Tout droit");
    }
    else if (A_X[4])
    {
        MOTOR_SetSpeed(LEFT, .25);
        MOTOR_SetSpeed(RIGHT, .25);
        Serial.println("Tout droit");
    }
    else if (A_X[5])
    {
        MOTOR_SetSpeed(RIGHT, .15);
        Serial.println("Tu devies un peu à droite");
    }
    else if (A_X[6])
    {
        MOTOR_SetSpeed(RIGHT, .15);
        MOTOR_SetSpeed(LEFT, .25);
        Serial.println("Tu devrais penser a tourner a gauche");
    }
    else if (A_X[7])
    {
        MOTOR_SetSpeed(RIGHT, 0);
        MOTOR_SetSpeed(LEFT, .25);
        Serial.println("TOURNNNEEEE À GAUCHE!!!!!6_7");
        last_Value = false;
    }
    else if (last_Value) //Cherche un ligne
    {
        MOTOR_SetSpeed(LEFT, 0);
        MOTOR_SetSpeed(RIGHT, .25);
        Serial.println("No line");
        Serial.println("TOURNNNEEEE À DROITE!!!!!");
    }
    else
    {
        MOTOR_SetSpeed(RIGHT, 0);
        MOTOR_SetSpeed(LEFT, .25);
        Serial.println("No line");
        Serial.println("TOURNNNEEEE À GAUCHE!!!!!");
    }
}