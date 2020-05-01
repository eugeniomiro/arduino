// Pins
const uint8_t btnPin = 2;
const uint8_t ledPin = 5;

// Globals
uint8_t led_state = LOW;
uint8_t btn_prv = HIGH;

void setup() {
  pinMode(btnPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Poll for button push
  uint8_t btn_state = digitalRead(btnPin);
  if ((btn_state == LOW) && (btn_prv == HIGH)) {
    led_state = !led_state;
    digitalWrite(ledPin, led_state);
  }
  btn_prv = btn_state;

  // Pretend we're doing other stuff
  delay(500);
}
