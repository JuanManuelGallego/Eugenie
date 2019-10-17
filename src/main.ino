/*
Projet: EuGenie
Equipe: P-03
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include <parcours/parcours.h>
#include <infraRouge/lecteurInfraRouge.h>

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
#define delais 200

void parcourTest(int noRobot)
{
  // Parcour planché
  Avancer(120.5, vitesseAvancer, noRobot);
  delay(delais);

  tourner(LEFT, 90, vitesseTourner, noRobot); //1
  delay(delais);

  Avancer(78, vitesseAvancer, noRobot);
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

void defiParcourt(int noRobot)
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

void choixRobot(int noRobot)
{
  if (noRobot == robot3A)
    defiParcoursA(robot3A, vitesseAvancer, vitesseTourner, delais); //RobotA
  // else
  //   defiParcoursB(robot3B, vitesseAvancer, vitesseTourner, delais); //RobotB
}

void setup()
{
  BoardInit();
  Serial.begin(200);

  //Activer les fonctions quand le bunper arrière est cliqué.
  // if(ROBUS_IsBumper(3))
  //   choixRobot(robot3B);
}

/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop()
{
  infrarouge1();
  delay(10);
}