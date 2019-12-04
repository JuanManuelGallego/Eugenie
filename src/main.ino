/*
Projet: EuGenie
Equipe: P-03
Auteurs: Les membres auteurs du script
Description: Breve description du script
Date: 2019-15-04
*/

#include <LibRobus.h> // Essentielle pour utiliser RobUS
#include <parcours/parcours.h>
#include <colorSensor/colorSensor.h>
#include <suiveurLigne/suiveurLignes.h>
#include <parcourCombattant/parcoursCombattant.h>
#include <pompier/pompier.h>

// Parcours
#define robot3A 0
#define robot3B 1
#define vitesseAvancer 0.25
#define vitesseTourner 0.25
#define delais 200

// Couleurs parcours combattant
#define green 1
#define red 2
#define blue 3
#define yellow

// LED
#define led1 2
#define led2 3

// Pompe
#define pompePin 13

// btnONOFF
#define btnONOFF 50

static int ONOFF = 0;

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
  //Gyrophare
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  //Btn ON/OFF
  pinMode(btnONOFF, INPUT);

  // Suiveur de lignes
  pinMode(38, INPUT);
  pinMode(40, INPUT);
  pinMode(42, INPUT);
  pinMode(44, INPUT);
  pinMode(46, INPUT);
  pinMode(48, INPUT);
  pinMode(22, INPUT);
  pinMode(33, INPUT);
}

void setup()
{
  BoardInit();
  setPinMode();
  Serial.begin(9600);
  ENCODER_Reset(RIGHT);
  ENCODER_Reset(LEFT);
}

void initialSetup()
{
  setMotorSpeedZero();
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(pompePin, LOW);
  ENCODER_Reset(RIGHT);
  ENCODER_Reset(LEFT);
}

int actionnerRobot()
{
  int powerONOFF = digitalRead(btnONOFF);
  ONOFF = powerONOFF;
  return powerONOFF;
}

void loop()
{
  // if (ROBUS_IsBumper(3)) // arriere
  // {
  //   parcoursCombattant(robot3A, yellow);
  //   // parcoursCombattant(robot3B, red);
  // }

  if (ONOFF)
  {
    pompierFlame(pompePin, false, false);
    ONOFF = actionnerRobot();
  }
  else
  {
    initialSetup();
    ONOFF = actionnerRobot();
  }
}