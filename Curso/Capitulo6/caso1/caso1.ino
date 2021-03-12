
#include <Servo.h>

Servo servo1;
int PINSERVO = 2;
int PULSOMIN = 500;
int PULSOMAX = 2500;

void setup() {
    servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
}

void loop() {
    servo1.write(0);
    delay(5000);
    servo1.write(180);
    delay(5000);
}

