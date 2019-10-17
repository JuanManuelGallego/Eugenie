#include <LibRobus.h>
#include <avancer/avancer.h>
#include <tourner/tourner.h>

void defiParcoursA(int noRobot, float vitesseAvancer, float vitesseTourner, float delais)
{
    Avancer(50, vitesseAvancer, noRobot);
    delay(delais);

    tourner(LEFT, 87.568989, vitesseTourner, noRobot); //1
    delay(delais);

    Avancer(50, vitesseAvancer, noRobot);
    delay(delais);

    tourner(RIGHT, 88, vitesseTourner, noRobot); //2
    delay(delais);

    Avancer(45, vitesseAvancer, noRobot);
    delay(delais);

    tourner(RIGHT, 88, vitesseTourner, noRobot); //3
    delay(delais);

    Avancer(55, vitesseAvancer, noRobot);
    delay(delais);

    tourner(LEFT, 88, vitesseTourner, noRobot); //4
    delay(delais);

    Avancer(100, vitesseAvancer, noRobot);
    delay(delais);

    tourner(RIGHT, 91, vitesseTourner, noRobot); //5
    delay(delais);

    Avancer(46, vitesseAvancer, noRobot);
    delay(delais);

    tourner(LEFT, 88.5, vitesseTourner, noRobot); //6
    delay(delais);

    Avancer(125, vitesseAvancer, noRobot);
    delay(delais);
}