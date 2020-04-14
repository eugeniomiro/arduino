
int wait   = 25;
int yellow = 2;
int green  = 3;
int red    = 4;
bool started = true;

void setup() { 
    Serial.begin(9600);
    pinMode(yellow, OUTPUT);
    pinMode(green,  OUTPUT);
    pinMode(red,    OUTPUT);
}

void loop() {
    if (Serial.available()) {
        int c = Serial.read();

        Serial.println(c);
        switch(c) {
            case 'j':
                wait += 1;
                Serial.println(wait);
                break;
            case 'k':
                wait -= 1;
                Serial.println(wait);
                break;
            case 's':
                started = !started;
                break;
        }
    }
    if (!started) {
        delay(1);
        return;
    }
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
    original code from: https://www.youtube.com/watch?v=zXt7na8Bb40
    Music: Joakim Karud - Dreams
*/
