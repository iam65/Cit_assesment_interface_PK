#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);
//Mendefinisikan nomor pin
const int trigPin = 9;
const int echoPin = 10;
int pus = 7;
int mod = 0;
int buz = 11;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int begin = 0;
void setup() {
  pinMode(pus, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(trigPin, OUTPUT); //Mengatur trigPin sebagai output
 pinMode(echoPin, INPUT); //Mengatur echoPin sebagai input
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
  if(mod == 0 && begin == 0){
  	lcd.setCursor(0,0);
  	lcd.print("Stand By!");
    Serial.println("Stand By!");
    begin = 1;
  }
  
  if(mod == 1 || mod == 2 || mod == 3 || mod == 4){
      if (begin == 1 && mod == 1){
        lcd.setCursor(0,0);
    	lcd.print("Sensor Active!");
        Serial.println("Sensor Active!");
        begin = 2; 
      }
   
  
//Deklarasi variabel
long duration, inches, cm;
// Pin trigPin clear
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Atur trigPin pada kondisi HIGH selama 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//Membaca echoPin, mengembalikan gelombang suara dalam satuan microseconds
duration = pulseIn(echoPin, HIGH);
//Memanggil fungsi untuk menghitung jarak dalam satuan inch
inches = microsecondsToInches(duration);
// Memanggil fungsi untuk menghitung jarak dalam satuan cm
cm = microsecondsToCentimeters(duration);
//Tampilkan hasil perhitungan pada serial monitor
    if(mod == 2){
      lcd.setCursor(0,0);
      lcd.print("Jarak ");
      lcd.print(cm);
      lcd.print(" cm    ");
      if(cm >= 100){
        digitalWrite(buz, HIGH);
        lcd.setCursor(0,1);
        lcd.print("BUZZER ACTIVE");
      }
      else {
        lcd.setCursor(0,1);
        lcd.print("             ");
        digitalWrite(buz, LOW);
      }
    }
    if(mod == 3){
      digitalWrite(buz, LOW);
      lcd.setCursor(0,0);
      lcd.print("Jarak ");
      lcd.print(cm);
      lcd.print(" cm  ");
      digitalWrite(led1, cm);
      digitalWrite(led2, cm);
      digitalWrite(led3, cm);
      lcd.setCursor(0,1);
      lcd.print("LED ACTIVE");
    }
    if (mod == 4){
      lcd.clear();
      mod = 0;
      begin = 0;
    }
                            

delay(100);
}
}
//fungsi untuk menghitung jarak dalam satuan inch
long microsecondsToInches(long microseconds)
{
 return microseconds / 74 / 2;
}
// fungsi untuk menghitung jarak dalam satuan cm
long microsecondsToCentimeters(long microseconds)
{
 return microseconds / 29 / 2;
}