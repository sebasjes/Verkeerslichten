//constants
const int BUZZERPIN = 1;
const int INTERVALBUZZER = 100;

unsigned long previousMillisBuzzer;

// methodes
void setupBuzzer() {
  pinMode(BUZZERPIN, OUTPUT);
  previousMillisBuzzer = millis();
}

void buzzerAan() {
  if (millis() - previousMillisBuzzer >= INTERVALBUZZER) {
    if (digitalRead(BUZZERPIN)) {
      digitalWrite(BUZZERPIN, HIGH);
    } else {
      digitalWrite(BUZZERPIN, LOW);
    }
  }
}

void buzzerUit() {
  digitalWrite(BUZZERPIN, LOW);
}
