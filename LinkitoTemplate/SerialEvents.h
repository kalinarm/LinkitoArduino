#include <Arduino.h>

class SerialEvents {
  public:
    typedef void (*CommandCallback)(const String&);

    void begin(long baudRate) {
      Serial.begin(baudRate);
    }

    void listen() {
      if (Serial.available()) {
        String message = Serial.readStringUntil('\n');
        message.trim();

        // Parse command and arguments
        int spaceIndex = message.indexOf(' ');
        String command = message.substring(0, spaceIndex);
        String arguments = message.substring(spaceIndex + 1);

        // Find and call the registered callback
        for (int i = 0; i < numListeners; i++) {
          if (commandListeners[i].command == command) {
            CommandCallback callback = commandListeners[i].callback;
            callback(arguments);
            break;
          }
        }
      }
    }

    void registerCommand(const String& command, CommandCallback callback) {
      if (numListeners < maxListeners) {
        commandListeners[numListeners].command = command;
        commandListeners[numListeners].callback = callback;
        numListeners++;
      }
    }

    static int stringToInt(const String& str) {
      return str.toInt();
    }

    static float stringToFloat(const String& str) {
      return str.toFloat();
    }

    static bool stringToBool(const String& str) {
      String lowercaseStr = str;
      lowercaseStr.toLowerCase();
      if (lowercaseStr == "1" || lowercaseStr == "true" || lowercaseStr == "on") {
        return true;
      }
      return false;
    }

    void sendMessage(const String& command, const String& arguments) {
      String message = command + " " + arguments;
      Serial.println(message);
    }

    void sendInt(const String& command, int value) {
      String arguments = String(value);
      sendMessage(command, arguments);
    }

    void sendFloat(const String& command, float value) {
      String arguments = String(value);
      sendMessage(command, arguments);
    }

    void sendBool(const String& command, bool value) {
      String arguments = value ? "true" : "false";
      sendMessage(command, arguments);
    }

    void cmdHelp(const String& arguments) {
      Serial.println("availables commands :");
      for (int i = 0; i < numListeners; i++) {
        Serial.println(commandListeners[i].command);
        delay(10);  // Small delay to avoid overwhelming the serial port
      }
    }

  private:
    struct CommandListener {
      String command;
      CommandCallback callback;
    };

    static const int maxListeners = 10;
    CommandListener commandListeners[maxListeners];
    int numListeners = 0;
};
