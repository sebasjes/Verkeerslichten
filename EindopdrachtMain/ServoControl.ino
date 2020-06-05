#include <Servo.h>

Servo servo;
const int SERVO_PIN = 0;
const int MIN_GRADEN = 0;
const int MAX_GRADEN = 90;

int servoValue = MAX_GRADEN;

void setupServo() {
  servo.attach(SERVO_PIN);
  servo.write(servoValue);
}

void servoOmlaag() {
  while (servoValue > MIN_GRADEN) {
    servoValue = MIN_GRADEN;
    servo.write(servoValue);
  }
}

void servoOmhoog() {
  while (servoValue > MAX_GRADEN) {
    servoValue = MAX_GRADEN;
    servo.write(servoValue);
  }
}
