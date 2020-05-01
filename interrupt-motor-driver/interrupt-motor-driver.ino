const int btnPin = 2;
const int ledPin = 5;

void setup() {
  DDRD  = B00100000;
  PORTD = B00000100;
}

void loop() {
  int btn = (_BV(btnPin) & PORTD) >> btnPin;

  if (btn == LOW) {
    PORTD = _BV(ledPin) | PORTD;
  } else {
    PORTD = ~_BV(ledPin) & PORTD;
  }
}
