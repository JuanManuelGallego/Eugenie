/*
Projet: EuGenie
Equipe: P-03
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: Derniere date de modification
*/

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include <parcours/parcours.h>
#include <colorSensor/colorSensor.h>
#include <suiveurLigne/suiveurLignes.h>
// #include <Adafruit_TCS34725.h>
#include <parcourCombattant/parcoursCombattant.h>
#include <pompier/pompier.h>
#include <suiveurLigne/suiveurLignesV2.h>

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

#define green 1
#define red 2
#define blue 3
#define yellow

//LED
#define led1 2
#define led2 3

// Pick analog outputs, for the UNO these three work well
// use ~560  ohm resistor between Red & Blue, ~1K for green (its brighter)
#define redpin 3
#define greenpin 5
#define bluepin 6
// for a common anode LED, connect the common pin to +5V
// for common cathode, connect the common to ground

// our RGB -> eye-recognized gamma color
byte gammatable[256];

// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void parcourTest(int noRobot)
{
  // Parcour planché
  Avancer(120.5, vitesseAvancer, noRobot);
  delay(delais);

  tourner(LEFT, 90, vitesseTourner, noRobot); //1
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

void setPinMode()
{
  pinMode(13, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void setup()
{
  BoardInit();
  // colorSensorSetup(redpin, greenpin, bluepin);
  SERVO_Enable(0);
  SERVO_SetAngle(0, 55);
  Serial.begin(9600);
  ENCODER_Reset(RIGHT);
  ENCODER_Reset(LEFT);
  setPinMode();
  // digitalWrite(13, LOW); // sets the digital pin 13 off
}

/* ****************************************************************************
Fonctions de boucle infini (loop())
**************************************************************************** */
// -> Se fait appeler perpetuellement suite au "setup"

void loop()
{
  // if (ROBUS_IsBumper(3)) // arriere
  // {
  //   parcoursCombattant(robot3A, yellow);
  //   // parcoursCombattant(robot3B, red);
  // }
  // pompier(13);
  // suiveurLigneV2();
  // digitalWrite(13, HIGH); // sets the digital pin 13 on
  // detectFlame();

  while (true)
  {
    pompierFlame(13);
  }
}