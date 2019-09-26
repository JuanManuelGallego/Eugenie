#include <LibRobus.h>

#define D 0
#define G 1
#define gauche true
#define droite false
#define speed 0.25
#define K1 2.275 //constante du robot 1 (3B)
#define K2 2.113   //constante du robot 2 (3A)

void tourner(bool sens, int angle, int nbRobot)
{
    double k;
    if(nbRobot == 1) k = K1;
    else k = K2;

    if(sens == gauche)//Tourner à gauche
    {
        MOTOR_SetSpeed(D, -speed);
        MOTOR_SetSpeed(G, speed);
        delay((k * angle)/speed);
        MOTOR_SetSpeed(D, 0);
        MOTOR_SetSpeed(G, 0);
    }
    else //Tourner a droite
    {
        MOTOR_SetSpeed(G, -speed);
        MOTOR_SetSpeed(D, speed);
        delay((k * angle)/speed);
        MOTOR_SetSpeed(D, 0);
        MOTOR_SetSpeed(G, 0);
    }
}

void avancer(int temps)
{
    MOTOR_SetSpeed(D, speed);
    MOTOR_SetSpeed(G, speed);
    delay(temps);
    MOTOR_SetSpeed(D, 0);
    MOTOR_SetSpeed(G, 0);
}


