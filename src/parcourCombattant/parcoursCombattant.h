#include <Arduino.h>
#include <Time.h>

void prenderBalleEtReculer(int noRobot, int color)
{
    int a = 1;
    int b = 1;

    while (a != 0)
    {
        a = suiveurLigneValue();
        suiveurLigne(noRobot);
    }
    delay(500);
    Avancer(-1.2, -0.25, noRobot); //Reculer
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

    // time_t t3 = time(NULL);
    // time_t t4;

    while (b != 0)
    {
        // t4 = time(NULL);
        b = suiveurLigneValue();
        suiveurLigne(noRobot);
    }
    Serial.print("Sortis de la boucle");
    delay(100);
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

    switch (color)
    {
    case 1:
        tourner(RIGHT, 90, 0.15, noRobot);
        delay(100);
        Avancer(30, 0.25, noRobot);
        delay(100);
        tourner(LEFT, 90, 0.15, noRobot);
        delay(100);
        Avancer(50, .25, noRobot);
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
        Avancer(55, .25, noRobot);
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