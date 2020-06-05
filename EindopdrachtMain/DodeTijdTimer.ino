//constants
const int INTERVAL_DODETIJD = 1000;
unsigned long previousMillis_DodeTijd;

//methodes
void setupDodeTijdTimer() {
  previousMillis_DodeTijd = millis();
}

boolean DodeTijd() {
  return (millis() - previousMillis_DodeTijd >= INTERVAL_DODETIJD);
}
