const int DATAPIN = 4;
const int LATCHPIN = 3;
const int CLOCKPIN = 2;
const int MAX_BITS = 10;

const int BYTES[MAX_BITS] =
{
  B11111100,
  B01100000,
  B11011010,
  B11110010,
  B01100110,
  B10110110,
  B10111110,
  B11100000,
  B11111110,
  B11110110
};

void setupDisplay() {
  pinMode(DATAPIN, OUTPUT);
  pinMode(LATCHPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
}

void updateDisplay(byte eightBits) {
  digitalWrite(LATCHPIN, LOW);
  shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, eightBits);
  digitalWrite(LATCHPIN, HIGH);
}

void shiftRegisterO() {
  byte bits = B11111100;
  updateDisplay(bits);
}

void shiftRegisterS() {
  byte bits = B1010110;
  updateDisplay(bits);
}

void shiftRegisterLoop(int currentDigitVoetgangers) {
  byte bits = BYTES[currentDigitVoetgangers] ;
  updateDisplay(bits);
}
