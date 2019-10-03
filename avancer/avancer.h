#include <LibRobus.h>
#include <encoder/encodeur.h>
#define constPond 0.00001

void Avancer(float distanceCM, float vitesse, int noRobot)
{
    encodeur(noRobot, "avancer", vitesse, constPond, distanceCM);

    // float Distance_parcourue = 0;
    // float Encodeur_Gauche = 0;
    // float Encodeur_Droit = 0;
    // float V_MotL = V_Mot;
    // // float V_MotR = 0.94* V_Mot; //pour robot 3A
    // float V_MotR = V_Mot;
    // ENCODER_Reset(LEFT);
    // ENCODER_Reset(RIGHT);

    // while (Distance_parcourue < Distance_cm)
    // {
    //     Encodeur_Gauche = ENCODER_Read(LEFT);
    //     Encodeur_Droit = ENCODER_Read(RIGHT);

    //     MOTOR_SetSpeed(LEFT, V_MotL);
    //     MOTOR_SetSpeed(RIGHT, V_MotR);

    //     V_MotR += ((Encodeur_Gauche - Encodeur_Droit) / 2) * Const_Pond;
    //     V_MotL += ((Encodeur_Droit - Encodeur_Gauche) / 2) * Const_Pond;

    //     Distance_parcourue = ((Encodeur_Droit + Encodeur_Gauche) / 6400) * 24;
    //     delay(200);
    // }
    // MOTOR_SetSpeed(LEFT, 0);
    // MOTOR_SetSpeed(RIGHT, 0);
}