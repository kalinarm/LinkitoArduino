#define DEVICE_ID "LinkitoLCD"
#define SERIAL_SPEED 115200

#include "SerialEvents.h"
SerialEvents serialEvents;

#define LED2 12

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  serialEvents.begin(SERIAL_SPEED);
  Serial.println(DEVICE_ID);


  // Register command listeners
  RegisterCommands();

  setupLCD();
  displayLCD("Hello, Linkiter");
}

void loop() {
  serialEvents.listen();
  delay(20);
}
