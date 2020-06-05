//constants
const int VOETGANGERSTIMER = 9;
const int INTERVAL = 1000;

//timer variable
unsigned long previousMillis;
int currentDigitVoetgangers;

//methodes
void voetgangerTimerReset() {
  currentDigitVoetgangers = VOETGANGERSTIMER;
  previousMillis = millis();
}

void voetgangersTimer() {
  if (currentDigitVoetgangers >= 0) {
    buzzerAan();
    if (millis() - previousMillis >= INTERVAL) {
      shiftRegisterLoop(currentDigitVoetgangers);
      currentDigitVoetgangers--;
      previousMillis = millis();
    }
  } else {
    buzzerUit();
    switchHuidigeStaat(Staat_Verkeer_Stil_Entry);
  }
}
