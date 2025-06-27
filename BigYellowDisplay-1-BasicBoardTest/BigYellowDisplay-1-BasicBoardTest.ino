int ledPins[] = {4, 16, 17};

void setup() {
  Serial.begin(115200);
  delay(1000);
  for (int p : ledPins) pinMode(p, OUTPUT);
}

void loop() {
  for (int p : ledPins) {
    Serial.printf("Blinking GPIO %d\n", p);
    digitalWrite(p, HIGH);
    delay(300);
    digitalWrite(p, LOW);
    delay(300);
  }
}