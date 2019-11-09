// #include <Wire.h>
// #include <Adafruit_TCS34725.h>

// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// void colorSensorSetup(int redpin, int greenpin, int bluepin)
// {
//   if (tcs.begin())
//   {
//     //Serial.println("Found sensor");
//   }
//   else
//   {
//     Serial.println("No TCS34725 found ... check your connections");
//     while (1)
//       ; // halt!
//   }

//   // use these three pins to drive an LED
//   pinMode(redpin, OUTPUT);
//   pinMode(greenpin, OUTPUT);
//   pinMode(bluepin, OUTPUT);

//   // thanks PhilB for this gamma table!
//   // it helps convert RGB colors to what humans see
//   // for (int i = 0; i < 256; i++)
//   // {
//   //     float x = i;
//   //     x /= 255;
//   //     x = pow(x, 2.5);
//   //     x *= 255;

//   //     gammatable[i] = x;
//   // }
// }

// void colorSensor(int redpin, int greenpin, int bluepin)
// {
//   float red, green, blue;

//   tcs.setInterrupt(false); // turn on LED

//   delay(1000); // takes 50ms to read

//   tcs.getRGB(&red, &green, &blue);

//   tcs.setInterrupt(true); // turn off LED

//   Serial.print("R:\t");
//   Serial.print(int(red));
//   Serial.print("\tG:\t");
//   Serial.print(int(green));
//   Serial.print("\tB:\t");
//   Serial.print(int(blue));

//   Serial.print("\n");

//   // Serial.print("R:\t");
//   // Serial.print(gammatable[(int)red]);
//   // Serial.print("\tG:\t");
//   // Serial.print(gammatable[(int)green]);
//   // Serial.print("\tB:\t");
//   // Serial.print(gammatable[(int)blue]);
//   // Serial.print("\n");

//   // analogWrite(redpin, gammatable[(int)red]);
//   // analogWrite(greenpin, gammatable[(int)green]);
//   // analogWrite(bluepin, gammatable[(int)blue]);

//   if (red > blue && green > blue && red > green)
//   {
//     Serial.print("yellow");
//   }
//   else if (red > blue && red > green)
//   {
//     Serial.print("red");
//   }
//   else if (blue > red && blue > green && blue > 100)
//   {
//     Serial.print("blue");
//   }
//   else if (green > blue && green > red)
//   {
//     Serial.print("green");
//   }
//   else if (red < 5 && green < 5 && blue < 5)
//   {
//     Serial.print("black");
//   }
//   Serial.print("\n");
// }