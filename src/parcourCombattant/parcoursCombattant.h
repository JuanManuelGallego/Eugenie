#include <Arduino.h>
#define constPond 0.00001

#define robot3A 0
#define robot3B 1

void prenderBalleEtReculer(int noRobot, int color)
{
    int a = 1;
    int b = 1;
    // bool c = false;

    while (a != 0)
    {
        a = suiveurLigneValue();
        suiveurLigne(noRobot);
    }
    delay(500);
    Avancer(-1.3, -0.20, noRobot); //Reculer
    delay(500);
    SERVO_SetAngle(0, 180);
    delay(1000);
    tourner(LEFT, 45, 0.15, noRobot);
    delay(100);
    tourner(LEFT, 45, 0.17, noRobot);
    delay(100);
    tourner(LEFT, 45, 0.15, noRobot);
    delay(100);
    tourner(LEFT, 45, 0.17, noRobot);
    delay(100);

    //si rouge
    if (color == 2)
    {
        Avancer(85, 0.20, noRobot);
    }
    else
    {
        while (b != 0)
        {
            b = suiveurLigneValue();
            suiveurLigne(noRobot);
            // c = calculDistance(noRobot, "avancer", 0.15, constPond, 10);
        }
    }

    Serial.print("Sortis de la boucle");
    delay(3000);
    SERVO_SetAngle(0, 90); //Remet le bras vers le haut
    delay(500);

    //Aller se cacher

    Avancer(-10, -0.25, noRobot); //Reculer
    delay(100);

    if (color == 2) //Si la couleur est rouge
    {
        tourner(RIGHT, 45, 0.15, noRobot);
        delay(100);
        tourner(RIGHT, 45, 0.15, noRobot);
        delay(100);
        tourner(RIGHT, 45, 0.15, noRobot);
        delay(100);
    }
    else
    {
        tourner(LEFT, 45, 0.15, noRobot);
        delay(100);
        tourner(LEFT, 45, 0.15, noRobot);
        delay(100);
        tourner(LEFT, 45, 0.15, noRobot);
        delay(100);
    }
    Avancer(80, .25, noRobot);
}

void parcoursCombattant(int noRobot, int color)
{
    if (noRobot == robot3A)
    {
        switch (color)
        {
        case 1:
            tourner(RIGHT, 90, 0.15, noRobot);
            delay(100);
            Avancer(32, 0.25, noRobot);
            delay(100);
            tourner(LEFT, 90, 0.15, noRobot);
            delay(100);
            Avancer(48, .25, noRobot);
            delay(100);
            tourner(RIGHT, 45, 0.15, noRobot);
            delay(100);
            prenderBalleEtReculer(noRobot, color);
            break;

        case 2:
            tourner(LEFT, 90, 0.15, noRobot);
            delay(100);
            Avancer(30, .25, noRobot);
            delay(100);
            tourner(RIGHT, 90, 0.15, noRobot);
            delay(100);
            Avancer(58, .25, noRobot);
            delay(100);
            tourner(LEFT, 45, 0.15, noRobot);
            delay(100);
            prenderBalleEtReculer(noRobot, color);
            break;

        case 3:
            tourner(RIGHT, 90, 0.15, noRobot);
            delay(100);
            Avancer(25, .25, noRobot);
            delay(100);
            tourner(RIGHT, 75, 0.15, noRobot);
            delay(100);
            prenderBalleEtReculer(noRobot, color);
            break;

        case 4:
            tourner(LEFT, 90, 0.15, noRobot);
            delay(100);
            Avancer(25, .25, noRobot);
            delay(100);
            tourner(LEFT, 75, 0.2, noRobot);
            delay(100);
            prenderBalleEtReculer(noRobot, color);
            break;

        default:
            break;
        }
    }
    else if (noRobot == robot3B)
    {
        switch (color)
        {
        case 1:
            tourner(LEFT, 90, 0.25, noRobot);
            delay(500);
            Avancer(55, 0.3, noRobot);
            delay(500);
            tourner(LEFT, 15, 0.15, noRobot);
            delay(500);
            Avancer(38, 0.3, noRobot);
            delay(500);
            break;

        case 2:
            tourner(RIGHT, 90, 0.25, noRobot);
            delay(500);
            Avancer(30, 0.3, noRobot);
            delay(500);
            tourner(RIGHT, 30, 0.18, noRobot);
            delay(500);
            Avancer(50, 0.3, noRobot);
            delay(500);
            break;

        case 3:
            tourner(LEFT, 90, 0.25, noRobot);
            delay(500);
            Avancer(45, 0.3, noRobot);
            delay(500);
            tourner(RIGHT, 90, 0.25, noRobot);
            delay(500);
            Avancer(105, 0.3, noRobot);
            delay(500);
            tourner(LEFT, 30, 0.15, noRobot);
            delay(500);
            Avancer(24, 0.3, noRobot);
            break;

        case 4:
            tourner(RIGHT, 90, 0.23, noRobot);
            delay(500);
            Avancer(45, 0.3, noRobot);
            delay(500);
            tourner(LEFT, 90, 0.16, noRobot);
            delay(500);
            Avancer(110, 0.3, noRobot);
            delay(500);
            tourner(RIGHT, 30, 0.14, noRobot);
            delay(500);
            Avancer(20, 0.1, noRobot);
            delay(500);
            break;

        default:
            break;
        }
    }
}