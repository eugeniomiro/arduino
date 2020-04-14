int wait = 25;
int yellow = 2;
int green = 3;
int red = 4;


void setup() { 
	pinMode(yellow, OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(red, OUTPUT);
}

void loop() {
	digitalWrite(yellow, 1); 
	digitalWrite(green, 1);
	digitalWrite(red, 0);
	delay(wait); 
	digitalWrite(yellow, 1); 
	digitalWrite(green, 0);
	digitalWrite(red, 0);
	delay(wait);
	digitalWrite(yellow, 1); 
	digitalWrite(green, 0);
	digitalWrite(red, 1);
	delay(wait);
	digitalWrite(yellow, 0); 
	digitalWrite(green, 0);
	digitalWrite(red, 1);
	delay(wait);
	digitalWrite(yellow, 0); 
	digitalWrite(green, 1);
	digitalWrite(red, 1);
	delay(wait);
	digitalWrite(yellow, 0); 
	digitalWrite(green, 1);
	digitalWrite(red, 0);
	delay(wait);
}

/*
Music: Joakim Karud - Dreams
//
*/
