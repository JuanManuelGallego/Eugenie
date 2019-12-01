#include <Arduino.h>

int analogReadValue(int IRID)
{
  int x = ROBUS_ReadIR(IRID);
  return x / 560;
}

boolean detectFlame(int IRID)
{
  int flame_detected = analogReadValue(IRID);
  // Serial.println(flame_detected);

  if (!flame_detected)
  {
    // Serial.println("Flame detected...! take action immediately.");
    return true;
  }
  else
  {
    // Serial.println("No flame detected. stay cool");
    return false;
  }
}