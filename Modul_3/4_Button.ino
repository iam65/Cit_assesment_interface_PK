int lightPin = A0; 
int lightPin1 = A1; 
int ledPin = 9;
int MODE = 0;
int but = 5;
int but1 =6;
int but2 =7;
int but3 =8;
int buz = 10;
void setup() { 
  
 Serial.begin(9600); 
 pinMode( ledPin, OUTPUT );
 pinMode (but, INPUT);
 pinMode (but1, INPUT);
 pinMode (but2, INPUT);
 pinMode (but3, INPUT);
 pinMode (buz, OUTPUT);
} 
void loop() { 

int a = digitalRead(but);
int b = digitalRead(but1);
int c = digitalRead(but2);
int d = digitalRead(but3);

if (a == LOW){
  Serial.print("LDR : ");
  Serial.println(analogRead(lightPin));
  delay(500);
  analogWrite(ledPin, analogRead(lightPin));
}
else if (b == LOW){
  Serial.print("Photodiode : ");
  Serial.println(analogRead(lightPin1));
  delay(500);
  analogWrite(ledPin, analogRead(lightPin1)); 
}
else if (c == LOW) {
  Serial.print("Photodiode : ");
  Serial.println(analogRead(lightPin1));
   delay(500);
   if (analogRead(lightPin1) > 700){
      digitalWrite(buz, HIGH);
   }
   else if (analogRead(lightPin1) <= 700){
      digitalWrite(buz, LOW);
   }
}
else if (d == LOW) {
  Serial.print("LDR : ");
  Serial.println(analogRead(lightPin));
   delay(500);
   if (analogRead(lightPin) > 100){
      digitalWrite(buz, HIGH);
   }
   else if (analogRead(lightPin) <= 100){
      digitalWrite(buz, LOW);
   }
}
else if (a == HIGH && b == HIGH && c == HIGH && d == HIGH){
  analogWrite(ledPin, LOW);
  digitalWrite(buz, LOW);
}

}