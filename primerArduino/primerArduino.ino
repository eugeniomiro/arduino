#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);

//void setup()
//{
//    Serial.println("Init");
//}
//
//void loop()
//{
//    if (BT.available()) {
//        Serial.write(BT.read());
//    }
//
//    if (Serial.available()) {
//        BT.write(Serial.read());
//    }
//}

int led[]       = { 2, 3, 4, 5, 6, 7, 8, 9 };
int size        = sizeof(led) / sizeof(int);
int span        = 1000 / size / 4 / 2;
int reminder    = 1000 - span * size * 4 * 2;

void setup()
{
    BT.begin(9600);
    Serial.begin(9600);
    Serial.print("size es: ");
    Serial.println(size);
    Serial.print("span es: ");
    Serial.println(span);
    Serial.print("reminder es: ");
    Serial.println(reminder);
    for (int l = 0; l < size; l++) {
        pinMode(led[l], OUTPUT);
    }
}

void loop()
{
    for (int l = 0; l < size; l++) {
        digitalWrite(led[l], HIGH);
        delay(span);
        digitalWrite(led[l], LOW);
        delay(span);
    }
    for (int l = size; l > 0; l--) {
        digitalWrite(led[l - 1], HIGH);
        delay(span);
        digitalWrite(led[l - 1], LOW);
        delay(span);
    }
    // wait the rest of the second
    delay(reminder);

    while (BT.available()) {
        Serial.write(BT.read());
    }

    if (Serial.available()) {
        BT.write(Serial.read());
    }
}