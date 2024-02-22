
void RegisterCommands() {
  serialEvents.registerCommand("help", cmdHelp);
  serialEvents.registerCommand("who", cmdWho);
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
