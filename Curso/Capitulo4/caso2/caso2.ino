int LED = 3;
int BRILLO;
int POT = 0;

void setup() {
	pinMode(LED, OUTPUT);
}

void loop() {
	BRILLO = analogRead(POT);
	analogWrite(LED, BRILLO / 4);
}
