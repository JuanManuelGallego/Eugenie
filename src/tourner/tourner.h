#include <LibRobus.h>
#define constPond 0.00001

void tourner(bool direction, float angle, float vitesse, int noRobot)
{
    float tourComplet = 26.7;

    //robotB
    if(noRobot == 1){
        tourComplet = 28.5;
    }
    if(noRobot == 0){
        tourComplet = 28.5;
    }

    float distance = (tourComplet / 360) * angle;

    encodeur(noRobot, "tourner", vitesse, constPond, distance, direction);
}