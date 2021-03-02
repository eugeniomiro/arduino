int LED = 3;
int BRILLO;

void setup() {
	pinMode(LED, OUTPUT);
}

void loop() {
	for(BRILLO=0; BRILLO < 256; BRILLO++) {
		analogWrite(LED, BRILLO);
		delay(10);
	}

	for(BRILLO=255; BRILLO >= 0; BRILLO--) {
		analogWrite(LED, BRILLO);
		delay(10);
	}
}
