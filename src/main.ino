/*
Projet: EuGenie
Equipe: P-03
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include <avancer/avancer.h>
#include <tourner/tourner.h>

/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales

#define robot3A 0
#define robot3B 1
#define vitesseAvancer 0.25
#define vitesseTourner 0.25
#define delais 500

void robot(int noRobot){
  // Parcour planché
  Avancer(120.5, vitesseAvancer, noRobot);
  delay(delais);

  tourner(LEFT, 90, vitesseTourner, noRobot); //1
  delay(delais);

  Avancer(80, vitesseAvancer, noRobot);
  delay(delais);

  tourner(RIGHT, 90, vitesseTourner, noRobot); // 2
  delay(delais);

  Avancer(103.5, vitesseAvancer, noRobot);
  delay(delais);

  tourner(RIGHT, 30, vitesseTourner, noRobot); // 3
  delay(delais);

  Avancer(170, vitesseAvancer, noRobot);
  delay(delais);

  tourner(LEFT, 90, vitesseTourner, noRobot); // 4
  delay(delais);

  Avancer(45, vitesseAvancer, noRobot);
  delay(delais);

  tourner(RIGHT, 30, vitesseTourner, noRobot); // 5
  delay(delais);

  Avancer(125, vitesseAvancer, noRobot);
}

void setup()
{
  BoardInit();
  robot(robot3A);
}

/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop()
{
  delay(10);
}