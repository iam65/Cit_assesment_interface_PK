#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
//Mendefinisikan nomor pin
int pus = 4;
int mod = 0;
int led3 = 6;
int ProxSensor = 8;
int Buzzer = 9;
int begin = 0;
int inputVal = 0;
void setup() {
  pinMode(pus, INPUT);
  pinMode(led3, OUTPUT);
  pinMode(Buzzer, OUTPUT);
 Serial.begin(9600); //Mengaktifkan komunikasi serial
  lcd.begin(16,2);
  lcd.init();	
  lcd.backlight();
}


void loop()
{
  int te = digitalRead(pus);
  if (te == LOW){
    mod++;
  }
  if (mod == 0 && begin == 0){
  	  lcd.setCursor(0,0);
 	  lcd.print("Stand By!");
	  Serial.println("Stand By!");
    begin = 1;
  }
  
if(mod == 1 || mod == 2 || mod == 3 || mod == 4){
        lcd.setCursor(0,0);
    	lcd.print("Sensor Active!");
        Serial.println("Sensor Active!");
   
  
 if (digitalRead(ProxSensor) == LOW) {
   if(mod == 1){
	lcd.setCursor(0,1);
	lcd.print("Terdeteksi!");   
   }

	Serial.println("Terdeteksi Halangan!");
 	inputVal = analogRead(ProxSensor);
 	Serial.println(inputVal);
    if (mod == 2){
      	lcd.setCursor(0,1);
      	lcd.print("Terdeteksi!buzON");
   		digitalWrite(Buzzer, HIGH);
      	Serial.println("Buzz ON");
    }
   	if (mod == 3){
      	lcd.setCursor(0,1);
      	lcd.print("Terdeteksi!LEDON");
     	digitalWrite(Buzzer, LOW);
     	delay(500);
   		analogWrite(led3, inputVal);
     	Serial.println("LED ON");
   	}
 }

 if (digitalRead(ProxSensor) == HIGH) {
   if(mod == 1){
   	lcd.setCursor(0,1);
	lcd.print("Clear!             ");
   }
   else if (mod == 2){
    lcd.setCursor(0,1);
	lcd.print("Clear! BUZ OFF     ");
   }
   else if (mod == 3){
    lcd.setCursor(0,1);
	lcd.print("Clear! LED OFF     ");
   }
    Serial.println("Clear!");
 	inputVal = analogRead(ProxSensor);
    Serial.println(inputVal);
    digitalWrite(Buzzer, LOW);
    digitalWrite(led3, LOW);
   	
 }
}
   if (mod >= 4){
  	lcd.clear();
    digitalWrite(led3, LOW);
    mod = 0;
    begin = 0;
  } 
}