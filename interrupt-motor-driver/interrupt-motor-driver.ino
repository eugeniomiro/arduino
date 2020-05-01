// Pins
const uint8_t btnPin = 2;
const uint8_t ledPin = 5;

// Globals
uint8_t led_state = LOW;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(btnPin), toggle, FALLING);
}

void loop() {
  // Pretend we're doing other stuff
  delay(500);
}

void toggle() {
  led_state = !led_state;
  digitalWrite(ledPin, led_state);
}
