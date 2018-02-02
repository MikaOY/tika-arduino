
#include <BlynkSimpleCurieBLE.h> 
#include <CurieBLE.h> 
// You should get Auth Token in the Blynk App. 
// Go to the Project Settings (nut icon). 
char auth[] = "69489358a6b74bdfbd7cacdf466c1176"; 
BLEPeripheral  blePeripheral; 

void setup() { 
  blePeripheral.setLocalName("Tika Blynk"); 
  blePeripheral.setDeviceName("Tika Blynk"); 
  blePeripheral.setAppearance(384); 
  Blynk.begin(blePeripheral, auth); 
  blePeripheral.begin(); 
  // Setup the LED pin
  pinMode(13, OUTPUT);
} 

BLYNK_WRITE(0) {
  int switchValue = param.asInt();
  // Turn off if 0
  if (switchValue == 0) {
    digitalWrite(13, LOW);
  }
  // Turn on if 1
  if (switchValue == 1) {
   digitalWrite(13, HIGH);
  }
} 

void loop() { 
  Blynk.run(); 
  blePeripheral.poll(); 
} 
