#include "DHT.h"
#define rl 7
#define rl1 8
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int quangtro = A0;
int dht_pin = 9;
int DHTTYPE = DHT11;
DHT dht(dht_pin, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{
  Serial.begin(9600);
  pinMode(rl, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  pinMode(rl1, OUTPUT);
    lcd.begin();
  lcd.backlight();
}
void loop() 
 {
  int giatriQuangtro = analogRead(quangtro);
  Serial.println(giatriQuangtro);
  if (giatriQuangtro > 1000)
  {
    digitalWrite(rl, 1);
  }
  else
  {
    digitalWrite(rl, 0);
  }
  float t = dht.readTemperature();
  Serial.println(t);
  if (t > 30)
  {
    digitalWrite(rl1, 1);
  }
  else
  {
    digitalWrite(rl1, 0);
  }
  lcd.setCursor(0, 0);
  lcd.print("do sang:");
  lcd.setCursor(9, 0);
  lcd.print(giatriQuangtro);
  lcd.setCursor(0, 1);
  lcd.print("nhiet do:");
  lcd.setCursor(9, 1);
  lcd.print(t);
  lcd.setCursor(14, 1);
  lcd.print("C");
  
  
  
 }
