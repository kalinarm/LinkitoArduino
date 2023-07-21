
void RegisterCommands() {
  serialEvents.registerCommand("help", cmdHelp);
  serialEvents.registerCommand("who", cmdWho);
  serialEvents.registerCommand("led", cmdBuiltinLed);
  serialEvents.registerCommand("motor", cmdServo);
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

void cmdServo(const String& arguments) {
  int angle = SerialEvents::stringToInt(arguments);
  myservo.write(angle);
}
