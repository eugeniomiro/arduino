// Pins
const uint8_t btnPin = 2;
const uint8_t ledPin = 5;

void setup() {
  // Set button pin to be input with pullup
  DDRD &= ~(1 << btnPin);
  PORTD |= (1 << btnPin);

  // Set LED pin to be output
  DDRD |= (1 << ledPin);

  attachInterrupt(digitalPinToInterrupt(btnPin), toggle, FALLING);
}

void loop() {
  // Pretend we're doing other stuff
  delay(500);
}

void toggle() {
  PORTD ^= (1 << ledPin);
}
