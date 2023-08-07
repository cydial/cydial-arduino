#include <Encoder.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <stdlib.h>

int latitude;
LiquidCrystal_I2C lcd(0x27,16,2);
Encoder myEnc(3,2);
long oldPosition = -999;

Servo myservo;

void setup(){
  Serial.begin(9600);

  lcd.init();  // LCD초기 설정             
  lcd.backlight(); // LCD초기 설정  
  lcd.setCursor(0,0); //텍스트가 LCD에 나타날 위치
  lcd.print("Cydial 2.0"); 
  lcd.setCursor(0,1);
  lcd.print("Lat: "); 
  myservo.attach(5);

  Serial.println("Ready");
}

void loop(){
  long newPosition = myEnc.read()/4;
  if(newPosition != oldPosition){
    oldPosition = newPosition;
    Serial.println(newPosition);
    lcd.setCursor(5,1);
    lcd.print("      ");
    lcd.setCursor(5,1);
    lcd.print(newPosition);
    myservo.write(abs(newPosition));
  }
}
