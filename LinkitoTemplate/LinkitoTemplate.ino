#define DEVICE_ID "Linkito"
#define SERIAL_SPEED 115200

#include <Servo.h>

#include "SerialEvents.h"
SerialEvents serialEvents;

int buttonPin = 12;
int sensorPin0 = A0;
int sensorPin1 = A1;

int buttonState;
int sensorValue0 = 0;
int sensorValue1 = 0;

int threshold = 5;

Servo myservo;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  serialEvents.begin(SERIAL_SPEED);
  Serial.println(DEVICE_ID);

  myservo.attach(9);
  // Register command listeners
  RegisterCommands();
}

void loop() {
  serialEvents.listen();
  grabInput();

  delay(20);
}

void grabInput() {
  int val;
  val = analogRead(sensorPin0);
  if (abs(val - sensorValue0) > threshold) {
    sensorValue0 = val;
    serialEvents.sendInt("x", sensorValue0);
  }

  val = analogRead(sensorPin1);
  if (abs(val - sensorValue1) > threshold) {
    sensorValue1 = val;
    serialEvents.sendInt("y", sensorValue1);
  }

  val = digitalRead(buttonPin);
  if (val != buttonState) {
    buttonState = val;
    digitalWrite(LED_BUILTIN, buttonState);
  }
}
