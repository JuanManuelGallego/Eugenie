/*
Projet: Le nom du script
Equipe: Votre numero d'equipe
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

/* ****************************************************************************
Inclure les librairies de functions que vous voulez utiliser
**************************************************************************** */

#include <LibRobus.h> // Essentielle pour utiliser RobUS



/* ****************************************************************************
Variables globales et defines
**************************************************************************** */
// -> defines...
// L'ensemble des fonctions y ont acces
#define D 0
#define G 1
#define speed 0.5
#define K 100 //à trouver par essai erreur



/* ****************************************************************************
Vos propres fonctions sont creees ici
**************************************************************************** */
void tourner(bool sens, int angle)
{
    if(sens == true)//Tourner à droite
    {
        MOTOR_SetSpeed(D, -speed);
        MOTOR_SetSpeed(G, speed);
        delay((K * angle)/speed);
        MOTOR_SetSpeed(D, 0);
        MOTOR_SetSpeed(G, 0);
    }
    else //Tourner a gauche
    {
        MOTOR_SetSpeed(G, -speed);
        MOTOR_SetSpeed(D, speed);
        delay((K * angle)/speed);
        MOTOR_SetSpeed(D, 0);
        MOTOR_SetSpeed(G, 0);
    }
}


/* ****************************************************************************
Fonctions d'initialisation (setup)
**************************************************************************** */
// -> Se fait appeler au debut du programme
// -> Se fait appeler seulement un fois
// -> Generalement on y initilise les varibbles globales

void setup(){
  BoardInit();
}


/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop() {
  // SOFT_TIMER_Update(); // A decommenter pour utiliser des compteurs logiciels
  delay(10);// Delais pour décharger le CPU
  tourner(true, 45);
  delay(2000);
  tourner(false, 45);
}