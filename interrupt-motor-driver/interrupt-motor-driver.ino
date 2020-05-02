// Pins
const uint8_t btnPin = 2;
const uint8_t ledPin = 5;

void setup() {
  // Set button pin to be input with pullup
  DDRD &= ~(1 << btnPin);
  PORTD |= (1 << btnPin);

  // Set LED pin to be output
  DDRD |= (1 << ledPin);

  // Falling edge of INT0 generates interrupt
  EICRA |= (1 << ISC01);
  EICRA &= ~(1 << ISC00);

  // Enable Interrupts for INT0
  EIMSK |= (1 << INT0);

  // Enable global interrupts
  sei();
}

void loop() {
  // Pretend we're doing other stuff
  delay(500);
}

ISR(INT0_vect) {
  PORTD ^= (1 << ledPin);
}
