#include<Arduino.h>

float analogReadValue()
{
    int x = analogRead(A1);
    float v = x / 1023.0;
    return v;
}

void detectFlame()
{
  int flame_detected = analogReadValue();
  Serial.println(flame_detected);

   if (!flame_detected)
  {
    Serial.println("Flame detected...! take action immediately.");
  }
  else
  {
    Serial.println("No flame detected. stay cool");
  }
  // delay(1000);
}