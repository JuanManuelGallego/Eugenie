/*
Projet: EuGenie
Equipe: P-03
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include<avancer/avancer.h>
#include<tourner/tourner.h>

/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales

#define robot3A 0
#define robot3B 1
#define vitesse 0.25
#define delais 500

void setup()
{
  BoardInit();

  Avancer(10.5, vitesse, robot3B);
  delay(delais);
  tourner(LEFT,90, vitesse, robot3B);

//Parcour planché
  // Avancer(120.5, 0.25, robot3B);
  // delay(500);
  // tourner(0,90,0.25); //1
  // delay(500);
  // Avancer(85, 0.25, robot3B);
  // delay(500);
  // tourner(1,90,0.25); // 2
  // delay(500);
  // Avancer(103.5, 0.25, robot3B);
  // delay(500);
  // tourner(1,35,0.25); // 3
  // delay(500);
  // Avancer(170, 0.25, robot3B);
  // delay(500);
  // tourner(0,90,0.25); // 4
  // delay(500);
  // Avancer(50, 0.25, robot3B);
  // delay(500);
  // tourner(1,30,0.25); // 5
  // delay(500);
  // Avancer(110, 0.25, robot3B);
}

/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop()
{
  delay(10);
}