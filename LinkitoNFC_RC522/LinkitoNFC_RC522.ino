// Example sketch to add functionnalities to the game Linkito
// available here : https://store.steampowered.com/app/2312770/Linkito/
// use a NFC module itead studio
// connected on I2C
//    VCC  -->  5V (ou une broche 5V)
//    GND  -->  GND
//    SDA  -->  Pin A4 (SDA)
//    SCL  -->  Pin A5 (SCL)
//    IRQ  -->  Not connected
//    RST  -->  can be connected to pin 9


#define DEVICE_ID "NFC"
#define SERIAL_SPEED 115200
#define LED_PIN 7

#include "NFC.h"
#include "SerialEvents.h"
SerialEvents serialEvents;

void setup() {
  pinMode(LED_PIN, OUTPUT);
    
  serialEvents.begin(SERIAL_SPEED);
  Serial.println(DEVICE_ID);

  // Register command listeners
  RegisterCommands();

  initNFC();
}

void loop() {
  serialEvents.listen();
  loopNFC();

  delay(20);
}
