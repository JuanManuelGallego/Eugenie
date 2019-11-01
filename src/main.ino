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

  Serial.begin(9600);
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
  int x = analogRead(A0);
  float v = x * (5.0 / 1023.0);
  Serial.println(v);  

  if(v > 4.9) 
  {
    Serial.println("TOUT BLANC"); 
    //Avancer(5,0.15,robot3A);
  } // ChercherLigne();
  else if (v > 4.0) 
  {
     Serial.println("DROITE"); 
    //tourner(RIGHT,0.1,0.25,robot3A);
  }// TournerDroite
  else if (v > 3.0) 
  {
    Serial.println("TOUT DROIT"); 
    //Avancer(5,0.15,robot3A);
  }// Tout droit
  else if (v > 1)
  {
    Serial.println("GAUCHE"); 

    //tourner(LEFT,0.1,0.25,robot3A);
  } // Tourner Gauche
  else 
  {
    Serial.println("TOUT NOIR"); 
  }
  delay(500);
}