// https://www.prometec.net/lcd-keypad-shield/
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int lcd_key = 0;
int adc_key_in = 0;

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int read_LCD_buttons() //  para leer los botones
{
    adc_key_in = analogRead(0);
    if (adc_key_in > 1000) return btnNONE;
    if (adc_key_in < 50) return btnRIGHT;
    if (adc_key_in < 195) return btnUP;
    if (adc_key_in < 380) return btnDOWN;
    if (adc_key_in < 555) return btnLEFT;
    if (adc_key_in < 790) return btnSELECT;
    return btnNONE;
}

void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Push the buttons");
}

void lcdPrintHora()
{
    lcd.setCursor(8, 1);
    char time[9];

    unsigned long sec = millis() / 1000;
    int h, m, s;
    h = (sec / 3600) % 24;
    m = (sec / 60) % 60;
    s = sec % 60;

    sprintf(time, "%02d:%02d:%02d", h, m, s);
    lcd.print(time);
}

void loop() {
    lcdPrintHora();
    lcd.setCursor(0, 1);
    switch(read_LCD_buttons()){
        case btnSELECT:
            lcd.print("sel");
            break;
        case btnLEFT:
            lcd.print("izq");
            break;
        case btnUP:
            lcd.print("arr");
            break;
        case btnDOWN:
            lcd.print("aba");
            break;
        case btnRIGHT:
            lcd.print("der");
            break;
        default:
            lcd.print("   ");
            lcd.setCursor(0, 1);
            break;
    }
    lcd.cursor();
    delay(250);
    lcd.noCursor();
    delay(250);
}
