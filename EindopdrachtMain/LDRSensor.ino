//constants
const int LDRPIN = A2;
const int NACHTNUMMER = 4;

//methodes
void setupLDRSensor() {
  pinMode(LDRPIN, INPUT);
}

boolean nachtmode() {
  int ldrValue = map(analogRead(LDRPIN), 0, 1023, 0, 10);
  return (ldrValue <= NACHTNUMMER);
}
