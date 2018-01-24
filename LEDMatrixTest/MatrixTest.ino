

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  matrix.setBrightness(1);
}

void loop() {
  // put your main code here, to run repeatedly:

  matrix.clear();      // clear display
  matrix.drawLine(7, 0, 7, 7, LED_GREEN);
  matrix.writeDisplay();
  delay(500);
}
