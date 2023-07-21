
void RegisterCommands() {
  serialEvents.registerCommand("help", cmdHelp);
  serialEvents.registerCommand("who", cmdWho);
  serialEvents.registerCommand("led", cmdBuiltinLed);
  serialEvents.registerCommand("led2", cmdLed2);
  serialEvents.registerCommand("lcd", cmdLCD);
  serialEvents.registerCommand("lcd1", cmdLCD1);
  serialEvents.registerCommand("lcd2", cmdLCD2);
  serialEvents.registerCommand("lcdclear", cmdLCDClear);
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

void cmdLed2(const String& arguments) {
  bool on = SerialEvents::stringToBool(arguments);
  digitalWrite(LED2, on);
}

void cmdLCD(const String& arguments) {
  displayLCD(string2char(arguments));
}
void cmdLCD1(const String& arguments) {
  displayLCD(string2char(arguments), 0);
}
void cmdLCD2(const String& arguments) {
  displayLCD(string2char(arguments), 1);
}

void cmdLCDClear(const String& arguments) {
  clearLCD();
}
