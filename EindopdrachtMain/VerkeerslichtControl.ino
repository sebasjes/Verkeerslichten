//constants
const int AANTAL_VERKEERSLICHTEN = 2;
const int AANTAL_KLEUREN = 3;
const int PIN_ARRAY[AANTAL_VERKEERSLICHTEN][AANTAL_KLEUREN] = {
  { 13, 12, 11 },
  { 10, 9,  8  }
};

//methodes
void SetupVerkeerslichtControl() {
  ledControlSetup(PIN_ARRAY[VERKEERSLICHT_LINKS]);
  ledControlSetup(PIN_ARRAY[VERKEERSLICHT_RECHTS]);
}

void lampVerkeerslicht(int verkeerslicht, int kleur) {
  for (int led = 0; led < 3; led++) {
    if (led == kleur) {
      ledControlSetLedOn(PIN_ARRAY[verkeerslicht][led]);
    } else {
      ledControlSetLedOff(PIN_ARRAY[verkeerslicht][led]);
    }
  }
}

void dodeTijd() {
  setupDodeTijdTimer();
  if (DodeTijd) {
    lampVerkeerslicht(VERKEERSLICHT_LINKS, ROOD);
    lampVerkeerslicht(VERKEERSLICHT_RECHTS, ROOD);
  }
}
