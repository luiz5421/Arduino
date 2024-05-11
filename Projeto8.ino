#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

int ledRed = 13; 
int ledYelow = 10; 
int ledGreen = 9;

int buzzerPin = 8;

int bot1 = 7;
int buttonState1;

int bot2 = 6;
int buttonState2;

int LM35 = A1; 
float temperatura; 

int pwmPin = A2; 
unsigned int valorLido; 
unsigned int pwm;

int ldrPin = 0;  
int ldrValor = 0;

void setup()
{
  	pinMode(ledRed, OUTPUT);
  	pinMode(ledYelow, OUTPUT);
	pinMode(ledGreen, OUTPUT);
  
  	pinMode(bot1,INPUT);
  	pinMode(bot2,INPUT);
  
  	pinMode(buzzerPin, OUTPUT);
  
  	Serial.begin(9600);
  
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.print("TP:23.23 PT:0");
  lcd_1.setCursor(0, 1);
  lcd_1.print("LD1021 L1:D L2:D");
}

void EscritaLcdTemp(float temp)
{
  lcd_1.setCursor(3, 0);
  lcd_1.print(temp);
}

float Temp(int LM35)
{
  float temp=0;
  
  temp = (float(((((analogRead(LM35)*5.0)/1023)*1000)-500)/10));
  
  return temp;
}

void Buzzer(int temp)
{
  if(temp>90)
  {
    tone(buzzerPin, 2000);
  }
  else
  {
     noTone(buzzerPin);
  }
}

void Bot1()
{
    buttonState1 = digitalRead(bot1);
}

void LedRed(int state1)
{
  if(state1==0)
  {
    digitalWrite(ledRed,HIGH);
  }
  else
  {
     digitalWrite(ledRed,LOW);
  }
}

void EscritaLedBot1(int state1)
{
  if(state1==0)
  {
    lcd_1.setCursor(6, 1);
  	lcd_1.print(" L1:L");
  }
  else
  {
     lcd_1.setCursor(6, 1);
  	 lcd_1.print(" L1:D");
  }
  
}

int Luminosidade(int ldrPin)
{
  int ldrValor=0;
    
  ldrValor = analogRead(ldrPin); 
  
  return ldrValor; 
}

void EscritaLdrLumi(int VldvalorLdr)
{
  if(VldvalorLdr>1000)
  {
   lcd_1.setCursor(2, 1);
   lcd_1.print(VldvalorLdr);
  }
  else
  {
    lcd_1.setCursor(5, 1);
    lcd_1.print(" ");
    lcd_1.setCursor(2, 1);
   	lcd_1.print(VldvalorLdr);
  }
  
}

void Bot2()
{
    buttonState2 = digitalRead(bot2);
}

void LedYelow(int state2)
{
  if(state2==0)
  {
    digitalWrite(ledYelow,HIGH);
    EscritaLedBot2(state2);
  }
  else
  {
     digitalWrite(ledYelow,LOW);
    EscritaLedBot2(state2);
  }
}

void EscritaLedBot2(int state2)
{
  if(state2==0)
  {
    lcd_1.setCursor(11, 1);
  	lcd_1.print(" L2:L");
  }
  else
  {
     lcd_1.setCursor(11, 1);
  	 lcd_1.print(" L2:D");
  }
  
}

int ValorPoten(int pwmPin)
{
   unsigned int valorRetorno;

    valorLido = analogRead(pwmPin);
	valorRetorno = MudarEscala(valorLido);
  
  return valorRetorno;
}

int MudarEscala(int valorLido)
{
  unsigned int valor;

  valor = map(valorLido, 0, 1023, 0, 255);

  return valor;
}

void EscritaPoten(int valorLdr)
{
  if(valorLdr>1000)
  {
   lcd_1.setCursor(12, 0);
   lcd_1.print(valorLdr);
  }
  else if(valorLdr>999)
  {
    lcd_1.setCursor(15, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(12, 0);
   	lcd_1.print(valorLdr);
  }
  else if(valorLdr>99)
  {
    lcd_1.setCursor(15, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(14, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(12, 0);
    lcd_1.print(valorLdr);
  }
  else if(valorLdr>9)
  {
    lcd_1.setCursor(15, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(14, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(13, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(12, 0);
   	lcd_1.print(valorLdr);
  }
  else if(valorLdr==0)
  {
    lcd_1.setCursor(15, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(14, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(13, 0);
    lcd_1.print(" ");
    lcd_1.setCursor(12, 0);
   	lcd_1.print(valorLdr);
}
}
void ControleGreen(int pwm) 
{ 	
     	analogWrite(ledGreen,pwm);
}
void loop()
{
  	temperatura =Temp(LM35);
    Buzzer(temperatura);
    EscritaLcdTemp(temperatura);
  
  	Bot1();
  	LedRed(buttonState1);
    EscritaLedBot1(buttonState1);
  
    ldrValor =  Luminosidade(ldrPin); 
  	EscritaLdrLumi(ldrValor);
  
  	Bot2();
  	LedYelow(buttonState2);
  
  	pwm = ValorPoten(pwmPin); 
  	Serial.println(valorLido);
    EscritaPoten(valorLido);
  	ControleGreen(pwm);
}