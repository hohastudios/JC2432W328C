#include <ArduinoJson.h>
#include "configreader.h"

void read_config_file(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
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

}

void parse_json(char* input) {
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, input);

    if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
    }

    const char* btn11_label = doc["btn11"]["label"]; // "1"
    const char* btn11_binding = doc["btn11"]["binding"]; // "1"
}

