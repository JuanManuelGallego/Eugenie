#include <LibRobus.h>
#include <encoder/encodeur.h>
#define constPond 0.00001

void Avancer(float distanceCM, float vitesse, int noRobot)
{
    encodeur(noRobot, "avancer", vitesse, constPond, distanceCM);
}