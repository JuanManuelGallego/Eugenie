#include<LibRobus.h>
#define constPond 0.00001

<<<<<<< Updated upstream
void tourner(bool direction, float angle, float vitesse, int noRobot){

    float tourComplet = 30;
    float distance = (tourComplet/360) * angle;

    encodeur(noRobot, "tourner", vitesse, constPond, distance, direction);
=======
void tourner(bool direction, float angle, float vitesse, int noRobot)
{
    float tourComplet = 26.7;

    //robotB
    if(noRobot == 1){
        tourComplet = 28.5;
    }
    if(noRobot == 0){
        tourComplet = 28.5;
    }
>>>>>>> Stashed changes

    // float Distance_parcourue = 0;
    // float Encodeur_Gauche = 0;
    // float Encodeur_Droit = 0;
    // float V_MotL = vitesse;
    // float V_MotR = vitesse;
    // ENCODER_Reset(LEFT);
    // ENCODER_Reset(RIGHT);

    // while (Distance_parcourue < distance)
    // {
    //     //vers la gauche
    //     if(direction == LEFT){
    //         Encodeur_Gauche = ENCODER_Read(LEFT) * -1; 
    //         Encodeur_Droit = ENCODER_Read(RIGHT);
    //         MOTOR_SetSpeed(LEFT, V_MotL * -1);
    //         MOTOR_SetSpeed(RIGHT, V_MotR);
    //     }
    //     if(direction == RIGHT){
    //         Encodeur_Gauche = ENCODER_Read(LEFT);
    //         Encodeur_Droit = ENCODER_Read(RIGHT) * -1;
    //         MOTOR_SetSpeed(LEFT, V_MotL);
    //         MOTOR_SetSpeed(RIGHT, V_MotR * -1);
    //     }

    //     V_MotR += ((Encodeur_Gauche - Encodeur_Droit) / 2) * Const_Pond;
    //     V_MotL += ((Encodeur_Droit - Encodeur_Gauche) / 2) * Const_Pond;

    //     Distance_parcourue = ((Encodeur_Droit + Encodeur_Gauche) / 6400) * 23.94;
    //     delay(200);
    // }
    // MOTOR_SetSpeed(LEFT, 0);
    // MOTOR_SetSpeed(RIGHT, 0);

}