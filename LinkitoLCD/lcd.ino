#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setupLCD() {
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, Linkiter!");
}

void clearLCD() {
  lcd.clear();
}

void displayLCD(char* str) {
  lcd.clear();
  char* t;
  for (t = str; *t != '\0'; t++) {
    if (t[0] == '/') {
      lcd.setCursor(0, 1);
      continue;
    }
    lcd.write(t[0]);
  }
}

void displayLCD(char* str, int line) {
  lcd.setCursor(0, line);
  char* t;
  for (t = str; *t != '\0'; t++) {
    lcd.write(t[0]);
  }
}


char* string2char(String command){
    if(command.length()!=0){
        char *p = const_cast<char*>(command.c_str());
        return p;
    }
}
