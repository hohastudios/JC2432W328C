#include <ArduinoJson.h>
#include "configreader.h"
#include <SD.h>
#include <SPI.h>

// ---------------------------------------------------------------------------
//  Modified: read_sd_directory
//  Returns a String in LVGL-compatible format.
// ---------------------------------------------------------------------------
String read_sd_directory()
{
  if (!SD.begin()) { 
      Serial.println("Card Mount Failed");
      return String("");
  }
  Serial.println("Card Mounted"); 
  // 1. Open the directory that holds the configuration files
  File dirs = SD.open("/macrokeys/config");
  if (!dirs || !dirs.isDirectory()) {
    Serial.println("Failed to open /config directory");
    return String("");
  }

  String options = "";

  // 2. Iterate through all entries in the directory
  File file = dirs.openNextFile();
  while (file) {
    // Skip sub‑directories – we only want regular files
    if (!file.isDirectory()) {
      // Prepend a newline *only* if there is already something in the string
      if (!options.isEmpty()) {
        options += "\n";
      }
      options += String(file.name());   // e.g., "option1"
    }

    file.close();          // Close the current entry before opening the next
    file = dirs.openNextFile(); // Move to the next file/directory
  }

  dirs.close();  // Close the directory handle

  // 3. Return the constructed string
  return options;
}

void read_config_file(String path) {
  Serial.println(String("Reading file: ") + path);
  if (!SD.begin()) { 
      Serial.println("Card Mount Failed");
      return;
  }
  File file = SD.open("/macrokeys/config/" + path);
  if (!file || file.isDirectory()) {
    Serial.println("Failed to open file for reading");
    return;
  }

  String input;
  while (file.available()) {
    input += char(file.read());
  }
  file.close();

  Serial.println("File Content:");
  Serial.println(input);
  parse_json(input.c_str());

}

void parse_json(const char* input) {
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, input);

    if (error) {
      Serial.print("parse_json() failed: ");
      Serial.println(error.c_str());
      return;
    }

    const char* btn11_label = doc["btn11"]["label"]; // "1"
    const char* btn11_bind = doc["btn11"]["bind"]; // "1"
    Serial.println(btn11_label); 
}

