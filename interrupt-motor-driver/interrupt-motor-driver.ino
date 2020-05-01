const int btnPin = 2;
const int ledPin = 5;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int btn = digitalRead(btnPin);

  if (btn == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
