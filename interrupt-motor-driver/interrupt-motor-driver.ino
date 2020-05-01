const int btnPin = 2;
const int ledPin = 5;

void setup() {
  DDRD  = B00100000;
  PORTD = B00000100;
}

void loop() {
  int btn = digitalRead(btnPin);

  if (btn == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
