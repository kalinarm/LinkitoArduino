
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
  int angle = SerialEvents::stringToInt(arguments);
  servoX.write(angle);
}

void cmdServoY(const String& arguments) {
  int angle = SerialEvents::stringToInt(arguments);
  servoY.write(angle);
}

void cmdServoC(const String& arguments) {
  int angle = SerialEvents::stringToInt(arguments);
  servoC.write(angle);
}

void cmdServoR(const String& arguments) {
  int angle = SerialEvents::stringToInt(arguments);
  servoR.write(angle);
}
