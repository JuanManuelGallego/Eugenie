#include <Arduino.h>

float analogReadValue()
{
  int x = analogRead(A8);
  float v = x / 1023.0;
  return v;
}

boolean detectFlame()
{
  int flame_detected = analogReadValue();
  Serial.println(flame_detected);

  if (!flame_detected)
  {
    Serial.println("Flame detected...! take action immediately.");
    return true;
  }
  else
  {
    Serial.println("No flame detected. stay cool");
    return false;
  }
}