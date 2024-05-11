// C++ code
//
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

int verdec1 = 13; 
int amareloc1 = 12; 
int vermelhoc1 = 11;

int verdec2 = 7; 
int amareloc2 = 6; 
int vermelhoc2 = 5;

int verdep1 = 10; 
int vermelhop1 = 9;

int verdep2 = 4; 
int vermelhop2 = 3;

int bot = 2;
int buttonState=0;
void setup()
{
    pinMode(verdec1, OUTPUT);
	pinMode(amareloc1, OUTPUT);
	pinMode(vermelhoc1, OUTPUT);
  
	pinMode(verdec2, OUTPUT);
    pinMode(amareloc2, OUTPUT);
	pinMode(vermelhoc2, OUTPUT);
  
  	pinMode(verdep1, OUTPUT);
	pinMode(vermelhop1, OUTPUT);
  
	pinMode(verdep2, OUTPUT);
	pinMode(vermelhop2, OUTPUT);
  
  	pinMode(bot,INPUT);
  	Serial.begin(9600);
  
  lcd_1.begin(16, 2);
  
}

int AcendLedRedp()
{
  	 digitalWrite(vermelhop1,HIGH);
     digitalWrite(vermelhop2,HIGH);
  
}
int AcendLedYelowc2()
{
  	 digitalWrite(amareloc2,HIGH);
  lcd_1.setCursor(0,0);
  lcd_1.print("1V   A  Rx V  Rx");
  lcd_1.setCursor(0,1);
  lcd_1.print("2V   Ax R  V  Rx");
}
int ApagLedYelowc2()
{
  	 digitalWrite(amareloc2,LOW);
}
int AcendLedYelowc1()
{
  	 digitalWrite(amareloc1,HIGH);
   lcd_1.setCursor(0,0);
  lcd_1.print("1V   Ax R  V  Rx");
  lcd_1.setCursor(0,1);
  lcd_1.print("2V   A  Rx V  Rx");
}
int ApagLedYelowc1()
{
  	 digitalWrite(amareloc1,LOW);
}
int AcendLedRedc2()
{
     digitalWrite(vermelhoc2,HIGH);
  lcd_1.setCursor(0,0);
  lcd_1.print("1Vx  A  R  V  Rx");
  lcd_1.setCursor(0,1);
  lcd_1.print("2V   A  Rx V  Rx");
}
int ApagLedRedp()
{
     digitalWrite(vermelhop1,LOW);
     digitalWrite(vermelhop2,LOW);
}
int AcendLedVerdp()
{
     digitalWrite(verdep1,HIGH);
     digitalWrite(verdep2,HIGH);
  lcd_1.setCursor(0,0);
  lcd_1.print("1V   A  Rx Vx R ");
  lcd_1.setCursor(0,1);
  lcd_1.print("2V   A  Rx Vx R ");
}
int AcendLedVerdc1()
{
     digitalWrite(verdec1,HIGH);
  lcd_1.setCursor(0,0);
  lcd_1.print("1Vx  A  R  V  Rx");
  lcd_1.setCursor(0,1);
  lcd_1.print("2V   A  Rx V  Rx");
}
int AcendLedVerdc2()
{
     digitalWrite(verdec2,HIGH);
  lcd_1.setCursor(0,0);
  lcd_1.print("1V   A  Rx V  Rx");
  lcd_1.setCursor(0,1);
  lcd_1.print("2Vx  A  R  V  Rx");
}
int ApagLedVerdc2()
{
     digitalWrite(verdec2,LOW);
}
int ApagLedVerdp()
{
     digitalWrite(verdep1,LOW);
     digitalWrite(verdep2,LOW);
}
int ApagLedVerdc1()
{
     digitalWrite(verdec1,LOW);
}
int ApagLedRedc1()
{
     digitalWrite(vermelhoc1,LOW);
}
int AcendLedRedc1()
{
     digitalWrite(vermelhoc1,HIGH);
   lcd_1.setCursor(0,0);
  lcd_1.print("1V   A  Rx V  Rx");
  lcd_1.setCursor(0,1);
  lcd_1.print("2Vx  A  R  V  Rx");
}
int ApagLedRedc2()
{
     digitalWrite(vermelhoc2,LOW);
  
  
}
void loop()
{
  AcendLedRedp();
  ApagLedYelowc2();
  AcendLedRedc2();
  
  	buttonState = digitalRead(bot);
	Serial.println(buttonState);
  if (buttonState == LOW) 
    {
		ApagLedRedp();
        AcendLedVerdp();
    
    	delay(3000);
    
    	AcendLedRedp();
    	ApagLedVerdp();
	}
   
  
    ApagLedRedc1();
    AcendLedVerdc1();
    
    delay(3000);
    
    ApagLedVerdc1();
    AcendLedYelowc1();
    
    delay(3000);
  	
  	ApagLedYelowc1();
    AcendLedRedc1();
  
  
  	ApagLedRedc2();
    AcendLedVerdc2();
  
  	delay(3000);
  	ApagLedVerdc2();
  	AcendLedYelowc2();
  	delay(3000);
 
}