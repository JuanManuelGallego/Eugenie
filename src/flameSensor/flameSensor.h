#include <Arduino.h>

int analogReadValue(int IRID)
{
  int x = ROBUS_ReadIR(IRID);
  return x / 560;
}

boolean detectFlame(int IRID)
{
  int flame_detected = analogReadValue(IRID);

  if (!flame_detected)
  {
    return true;
  }
  else
  {
    return false;
  }
}