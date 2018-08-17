
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
    middle_finger_bmp[] =
  { B00011000,
    B00011000,
    B00011000,
    B01100100,
    B11000010,
    B01000110,
    B00111000,
    B00111000 },
    flower_bmp[] =
  { B00011000,
    B00011000,
    B00011000,
    B01000010,
    B10000001,
    B01010010,
    B00111100,
    B00000000 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },
  trevor_is_awesome[] =
  { B11111111,
    B11111111,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000 },
  trevor_is_awesomel[] =
  { B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
    B11111111,
    B11111111 };
//void loop() {
////  matrix.clear();
////  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
////  matrix.writeDisplay();
////  delay(500);
//
////  matrix.clear();
////  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
////  matrix.writeDisplay();
////  delay(500);
////
////  matrix.setBrightness(1);
////  matrix.clear();
////  matrix.drawBitmap(0, 0, trevor_is_awesome, 8, 8, LED_ON);
////  matrix.writeDisplay();
////  delay(200);
////  matrix.setBrightness(1);
////  matrix.clear();
////  matrix.drawBitmap(0, 0, trevor_is_awesomeq, 8, 8, LED_ON);
////  matrix.writeDisplay();
////  delay(200);
////
////  matrix.clear();
////  matrix.drawBitmap(0, 0, flower_bmp, 8, 8, LED_ON);
////  matrix.writeDisplay();
////  delay(500);
////
////  matrix.clear();      // clear display
////  matrix.drawPixel(0, 0, LED_ON);  
////  matrix.writeDisplay();  // write the changes we just made to the display
////  delay(500);
////
////  matrix.clear();
////  matrix.drawLine(0,0, 7,7, LED_ON);
////  matrix.writeDisplay();  // write the changes we just made to the display
////  delay(500);
////
////  matrix.clear();
////  matrix.drawRect(0,0, 8,8, LED_ON);
////  matrix.fillRect(2,2, 4,4, LED_ON);
////  matrix.writeDisplay();  // write the changes we just made to the display
////  delay(500);
////
////  matrix.clear();
////  matrix.drawCircle(3,3, 3, LED_ON);
////  matrix.writeDisplay();  // write the changes we just made to the display
////  delay(500);
////
//
//  
//  matrix.setTextSize(1);
//  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
//  matrix.setTextColor(LED_ON);
//  for (int8_t x=0; x>=-95; x--) {
//    matrix.clear();
//    matrix.setCursor(x,0);
//    matrix.print(" Ms. Lulu is crazy");
//    matrix.writeDisplay();
//    delay(100);
//  }
////  matrix.setRotation(3);
////  for (int8_t x=7; x>=-36; x--) {
////    matrix.clear();
////    matrix.setCursor(x,0);
////    matrix.print("World");
////    matrix.writeDisplay();
////    delay(100);
////  }
////  matrix.setRotation(0);
//}
const int buttonPin = 12;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70); 
  matrix.setBrightness(0.5);
  buttonState = digitalRead(12);
}
void loop() {
  if (buttonState == HIGH) {
  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  digitalWrite(8, HIGH);
  } else {
  matrix.clear();
  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  digitalWrite(8, LOW);
  }
}
