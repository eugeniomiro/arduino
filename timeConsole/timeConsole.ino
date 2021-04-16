#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <RTClib.h>

#define ANCHO 128
#define ALTO 64
#define OLED_RESET 4

Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);
Adafruit_BMP280  bmp;
RTC_DS3231       rtc;

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
    if (!rtc.begin()){
        oled.clearDisplay();
        oled.setCursor(0, 0);
	oled.setTextSize(2);
        oled.print("rtc falló al inicializar!");
        while(1);
    }
    //rtc.adjust(DateTime(__DATE__, __TIME__));
}

void loop() {
    oled.clearDisplay();
    oled.setTextColor(WHITE);

    TEMPERATURA = bmp.readTemperature();
    PRESION = bmp.readPressure() / 100;

    oled.setCursor(0, 0);
    oled.setTextSize(1);

    oled.setTextSize(1);
    oled.setCursor(0, 2);
    printTime(rtc.now());

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

void printTime(DateTime now) {
    char time[15];

    int d, M, y, h, m, s;
    d = now.day();
    M = now.month();
    y = now.year();
    h = now.hour();
    m = now.minute();
    s = now.second();

    sprintf(time, "%d/%d/%d %02d:%02d:%02d  ", d, M, y, h, m, s);
    oled.print(time);
}
