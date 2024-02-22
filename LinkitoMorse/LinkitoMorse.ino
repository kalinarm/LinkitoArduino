#define DEVICE_ID "Morse"
#define SERIAL_SPEED 115200

#include <Servo.h>

#include "SerialEvents.h"
SerialEvents serialEvents;

int buttonPin = 12;
bool buttonVal;
bool val;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  serialEvents.begin(SERIAL_SPEED);
  Serial.println(DEVICE_ID);

  // Register command listeners
  RegisterCommands();
}

void loop() {
  serialEvents.listen();
  grabInput();

  delay(20);
}

void grabInput() {
  val = !digitalRead(buttonPin);
  if (val != buttonVal) {
    buttonVal = val;
    digitalWrite(LED_BUILTIN, val);
    serialEvents.sendBool("morse",val);
  }
}
