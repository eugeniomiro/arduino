const int btnPin = 2;
const int ledPin = 5;

void setup() {
  DDRD  = B00100000;
  PORTD = B00000100;
}

void loop() {
  int btn = ((1 << btnPin) & PORTD) >> btnPin;

  if (btn == LOW) {
    PORTD = (1 << ledPin | PORTD);
  } else {
    PORTD = ~(1 << ledPin) & PORTD;
  }
}
