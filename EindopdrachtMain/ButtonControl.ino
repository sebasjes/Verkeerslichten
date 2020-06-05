const int KNOPVOETGANGERS = A1;
const int KNOPLINKS = A2;
const int KNOPRECHTS = A4;

int knopStatus = LOW;
int laatsteKnop;

void setupKnop() {
  pinMode(KNOPVOETGANGERS, INPUT);
  pinMode(KNOPLINKS, INPUT);
  pinMode(KNOPRECHTS, INPUT);
}

void knopCheck() {
  if (nachtModeFalse() && isGedrukt() && knopStatus == LOW) {
    setKnop();
    knopStatus = HIGH;
  } else {
    knopStatus = LOW;
  }
}

void setKnop() {
  if (autoKnopLinksIngedrukt()) {
    laatsteKnop = KNOPLINKS;
    switchHuidigeStaat(1);
  } else if (autoKnopRechtsIngedrukt()) {
    laatsteKnop = KNOPRECHTS;
    switchHuidigeStaat(2);
  } else if (voetgangersKnopIngedrukt) {
    laatsteKnop = KNOPVOETGANGERS;
    switchHuidigeStaat(3);
  }
}

boolean isGedrukt() {
  return (autoKnopRechtsIngedrukt() || autoKnopLinksIngedrukt() || voetgangersKnopIngedrukt());
}

boolean autoKnopRechtsIngedrukt()
{
  return (digitalRead(KNOPRECHTS) == HIGH);
}

boolean autoKnopLinksIngedrukt()
{
  return (digitalRead(KNOPLINKS) == HIGH);
}

boolean voetgangersKnopIngedrukt()
{
  return (digitalRead(KNOPVOETGANGERS) == HIGH);
}
