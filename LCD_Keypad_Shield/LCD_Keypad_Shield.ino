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
    if (adc_key_in == 1023) return btnNONE;
    if (adc_key_in == 639) return btnSELECT;
    if (adc_key_in == 404) return btnLEFT;
    if (adc_key_in == 98 || adc_key_in == 97) return btnUP;
    if (adc_key_in == 252) return btnDOWN;
    if (adc_key_in == 0) return btnRIGHT;
    lcd.setCursor(0, 1);
    lcd.print("boton: ");
    lcd.print(adc_key_in);
    return btnNONE;
}

void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
}

void loop() {
    lcd.setCursor(0, 1);
    switch(read_LCD_buttons()){
        case btnSELECT:
            lcd.print("select");
            break;
        case btnLEFT:
            lcd.print("izquierda");
            break;
        case btnUP:
            lcd.print("arriba");
            break;
        case btnDOWN:
            lcd.print("abajo");
            break;
        case btnRIGHT:
            lcd.print("derecha");
            break;
        default:
            lcd.clear();
            break;
    }
    lcd.cursor();
    delay(250);
    lcd.noCursor();
    delay(250);
}
