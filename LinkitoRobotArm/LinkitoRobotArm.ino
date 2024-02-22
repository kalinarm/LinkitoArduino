#define DEVICE_ID "RobotArm"
#define SERIAL_SPEED 115200

#include <Servo.h>

#include "SerialEvents.h"
SerialEvents serialEvents;

Servo servoR;
Servo servoX;
Servo servoY;
Servo servoC;

void setup() {
  serialEvents.begin(SERIAL_SPEED);
  Serial.println(DEVICE_ID);

  pinMode(LED_BUILTIN, OUTPUT);

  servoR.attach(8);
  servoX.attach(9);
  servoY.attach(10);
  servoC.attach(12);

  initServos();

  // Register command listeners
  RegisterCommands();
}


void initServos() {
  int val = 90;
    servoR.write(90);
  servoX.write(val);
  servoY.write(val);
  servoC.write(val);
}

void loop() {
  serialEvents.listen();

  //delay(20);
}
