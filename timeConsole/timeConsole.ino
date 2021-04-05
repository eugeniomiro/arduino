#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define ANCHO 128
#define ALTO 64
#define OLED_RESET 4

Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);
Adafruit_BMP280 bmp;

float TEMPERATURA;
float PRESION, P0;

void setup() {
    Wire.begin();
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    if (!bmp.begin(0x76)) {
        oled.clearDisplay();
        oled.setCursor(0, 0);
        oled.setTextSize(2);
        oled.print("BMP280 no encontrado!");
        while(1);
    }
}

void loop() {
    oled.clearDisplay();
    oled.setTextColor(WHITE);

    TEMPERATURA = bmp.readTemperature();
    PRESION = bmp.readPressure() / 100;

    oled.setCursor(0, 0);
    oled.setTextSize(1);

    oled.setTextSize(2);
    oled.setCursor(5, 2);
    oled.print(millis() / 1000);
    oled.setTextSize(1);
    oled.print(" s");

    oled.setCursor(5, 26);
    oled.print("T:");
    oled.setTextSize(2);
    oled.print(TEMPERATURA);
    oled.setTextSize(1);
    oled.print(" C");

    oled.setCursor(5, 48);
    oled.print("P:");
    oled.setTextSize(2);
    oled.print(PRESION);
    oled.setTextSize(1);
    oled.print(" hPa");
    
    oled.display();
    delay(200);
}
