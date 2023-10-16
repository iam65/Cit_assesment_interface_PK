#include <LiquidCrystal_I2C.h>
int but1 = 5;
int but2 = 6;
int but3 = 7;
int a, b, c;
int ln, cl;

LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x3F for a 16

void setup() {
 lcd.init();
 lcd.clear();
 lcd.backlight(); // Make sure backlight is on
 pinMode(but1, INPUT);
 pinMode(but2, INPUT);
 pinMode(but3, INPUT);
 lcd.setCursor(5,0);
 lcd.print("hello");


}


void loop() {
   // Print a message on both lines of the LCD.
    a = digitalRead(but1);
    b = digitalRead(but2);
    c = digitalRead(but3);

    if (a == LOW){
      for (ln = 0; ln <= 38; ln++){
        lcd.scrollDisplayLeft();
        delay(150);
      }
    }

    if (b == LOW){
      for (ln = 0; ln <= 38; ln++){
        lcd.scrollDisplayRight();
        delay(150);
      }
    }
 }