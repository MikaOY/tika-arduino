/*********************************************************************
 This is CurieBot RC -- the Arduino 101 based robot using Bluetooth LE
 Modified to drive a 3-wheeled BLE Robot Rover! by http://james.devi.to

 Pick one up today in the Adafruit shop!

 Adafruit invests time and resources providing this open source code,
 please support Adafruit and open-source hardware by purchasing
 products from Adafruit!

 MIT license, check LICENSE for more information
 All text above, and the splash screen below must be included in
 any redistribution
*********************************************************************/

#include <string.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

#include <CurieBLE.h>
#include <BLEPeripheral.h>
#include "BLESerial.h"

BLESerial ble = BLESerial();


// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

// Create servo
Servo leftServo;
Servo rightServo;
int leftPos = 0;
int rightPos = 0;

#define BLUETOOTH_NAME                 "CurieBot" //Name your RC here
#define BLE_READPACKET_TIMEOUT         500   // Timeout in ms waiting to read a response

// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

// function prototypes over in packetparser.cpp
uint8_t readPacket(Stream *ble, uint16_t timeout);
float parsefloat(uint8_t *buffer);
void printHex(const uint8_t * data, const uint32_t numBytes);

// the packet buffer
extern uint8_t packetbuffer[];

char buf[60];

/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/
void setup(void)
{
 
  AFMS.begin();  // create with the default frequency 1.6KHz

  myMotor->setSpeed(20);  // 10 rpm   
    
  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit Robot Controller Example"));
  Serial.println(F("-----------------------------------------"));
  
  leftServo.attach(9);
  rightServo.attach(10);
  
  /* Initialize the module */
  BLEsetup();
}

int velocity = 0;

float x, y;

int L_restrict = 0;
int R_restrict = 0;

unsigned long lastAccelPacket = 0;

bool modeToggle = false;

void loop(void)
{
  // read new packet data
  uint8_t len = readPacket(&ble, BLE_READPACKET_TIMEOUT);
  if (len == 0) {

    return;
  }

  // always use buttonMode
  buttonMode();
}


bool isMoving = false;
unsigned long lastPress = 0;

bool buttonMode(){

   // Buttons
  if (packetbuffer[1] == 'B') {
    uint8_t buttnum = packetbuffer[2] - '0';
    boolean pressed = packetbuffer[3] - '0';

    Serial.print("Button #"); Serial.print(buttnum);
    if (pressed) 
      {
      Serial.println(" pressed");
      }
    else {
      Serial.println(" released");
    }
    
    if (pressed) {
      isMoving = true;
      if(buttnum == 5){

          Serial.print("moving" + leftPos);
          // move forward
          leftPos += 10;
          rightPos += 10;
          leftServo.write(leftPos);
          rightServo.write(rightPos);
          delay(15);

      }
      if(buttnum == 6){

      }
      if(buttnum == 7){

  
      }
      if(buttnum == 8){
   
      }

      lastPress = millis();
      
    } else {
      isMoving = false;
      
    }
     return true; 
  }

  return false;

}

void BLEsetup() {
  // using Curie
  ble.setLocalName("CurieBot");
  ble.begin();
}


