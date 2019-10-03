#include <LibRobus.h>
#include <string.h>

void encodeur(int noRobot, String action, float vitesseMoteur, float constPond, float distanceCM, int direction = -1)
{
    float distanceParcourue = 0;
    float encodeurGauche = 0;
    float encodeurDroit = 0;
    float vitesseMoteurL = vitesseMoteur;
    float vitesseMoteurR = vitesseMoteur;

    ENCODER_Reset(LEFT);
    ENCODER_Reset(RIGHT);

    if (noRobot == 0)
    {
        vitesseMoteurR = 0.94 * vitesseMoteur; //pour robot 3A
    }

    while (distanceParcourue < distanceCM)
    {
        if (action == "tourner" && direction >= 0)
        {
            //vers la gauche
            if (direction == LEFT)
            {
                encodeurGauche = ENCODER_Read(LEFT) * -1;
                encodeurDroit = ENCODER_Read(RIGHT);
                MOTOR_SetSpeed(LEFT, vitesseMoteurL * -1);
                MOTOR_SetSpeed(RIGHT, vitesseMoteurR);
            }
            if (direction == RIGHT)
            {
                encodeurGauche = ENCODER_Read(LEFT);
                encodeurDroit = ENCODER_Read(RIGHT) * -1;
                MOTOR_SetSpeed(LEFT, vitesseMoteurL);
                MOTOR_SetSpeed(RIGHT, vitesseMoteurR * -1);
            }
        }
        else
        {
            encodeurGauche = ENCODER_Read(LEFT);
            encodeurDroit = ENCODER_Read(RIGHT);

            MOTOR_SetSpeed(LEFT, vitesseMoteurL);
            MOTOR_SetSpeed(RIGHT, vitesseMoteurR);
        }

        vitesseMoteurR += ((encodeurGauche - encodeurDroit) / 2) * constPond;
        vitesseMoteurL += ((encodeurDroit - encodeurGauche) / 2) * constPond;

        distanceParcourue = ((encodeurDroit + encodeurGauche) / 6400) * 24;
        delay(200);
    }
    MOTOR_SetSpeed(LEFT, 0);
    MOTOR_SetSpeed(RIGHT, 0);
}