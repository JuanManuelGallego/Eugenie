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
  
 // loop();


//Parcour planché
  Avancer(120, vitesse, robot3B);
  delay(500);
  tourner(LEFT,85,vitesse, robot3B); //1
  delay(500);
  Avancer(85, vitesse, robot3B);
  delay(500);
  tourner(RIGHT,95,vitesse,robot3B); // 2
  delay(500);
  Avancer(95, vitesse, robot3B);
  delay(500);
  tourner(RIGHT,31,vitesse, robot3B); // 3
  delay(500);
  Avancer(175, vitesse, robot3B);
  delay(500);
  tourner(LEFT,83,vitesse, robot3B); // 4
  delay(500);
  Avancer(50, vitesse, robot3B);
  delay(500);
  tourner(RIGHT,31,vitesse, robot3B); // 5
  delay(500);
  Avancer(110, vitesse, robot3B);

}

/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop()
{

}