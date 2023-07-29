
void RegisterCommands() {
  serialEvents.registerCommand("help", cmdHelp);
  serialEvents.registerCommand("who", cmdWho);
  serialEvents.registerCommand("led", cmdBuiltinLed);
  serialEvents.registerCommand("x", cmdServoX);
  serialEvents.registerCommand("y", cmdServoY);
  serialEvents.registerCommand("c", cmdServoC);
  serialEvents.registerCommand("r", cmdServoR);
}

void cmdHelp(const String& arguments) {
  serialEvents.cmdHelp(arguments);
}

void cmdWho(const String& arguments) {
  Serial.println(DEVICE_ID);
}

void cmdPing(const String& arguments) {
  Serial.println("pong");
}

void cmdBuiltinLed(const String& arguments) {
  bool on = SerialEvents::stringToBool(arguments);
  digitalWrite(LED_BUILTIN, on);
}

void cmdServoX(const String& arguments) {
  int angle = constrain(SerialEvents::stringToInt(arguments), 10, 110);
  servoX.write(angle);
}

void cmdServoY(const String& arguments) {
  int angle = constrain(SerialEvents::stringToInt(arguments), 50, 170);
  servoY.write(angle);
}

void cmdServoC(const String& arguments) {
  int angle = constrain(SerialEvents::stringToInt(arguments), 20, 110);
  servoC.write(angle);
}

void cmdServoR(const String& arguments) {
  int angle = SerialEvents::stringToInt(arguments);
  servoR.write(angle);
}
