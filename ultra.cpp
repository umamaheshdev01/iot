
#include <LiquidCrystal_I2C.h>
#define echo 2
#define trigger 3

LiquidCrystal_I2C lcd(0x26, 16, 2);  

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
  
  
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  
  int duration = pulseIn(echo,HIGH);
  int x = duration*0.034 / 2;
  
  digitalWrite(10,LOW);
  noTone(9);
  
  
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print(" cm");
  Serial.println(x);
  Serial.println(" cm");
  
  
  if(x<50)
  {
    digitalWrite(10,HIGH);
    tone(9,1000);
  }

  
  
  
  

  delay(1000);
}
