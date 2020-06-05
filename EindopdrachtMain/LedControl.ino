//Zet pinouts
void ledControlSetup(int pinArray[]) {
  for (int ledNummer = 0; ledNummer < 3; ledNummer++) {
    pinMode(pinArray[ledNummer], OUTPUT);
  }
}

//zet een ledlampje aan
//led nummer moet meegegeven worden
void ledControlSetLedOn(int ledNummer) {
  digitalWrite(ledNummer, HIGH);
}

//zet een ledlampje uit
//led nummer moet meegegeven worden
void ledControlSetLedOff(int ledNummer) {
  digitalWrite(ledNummer, LOW);
}
