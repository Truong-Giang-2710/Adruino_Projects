#include <Wire.h>
#include <LiquidCrystal_I2C_AvrI2C.h>
#include "DHT.h"
LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);
#define DHTPIN 9    // Digital pin connected to the DHT sensor
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#define DHTTYPE DHT11   // DHT 11
#define rl 7
#define rll 8
DHT dht(DHTPIN, DHTTYPE);
char auth[] = "oU6yGTsTaPp306-f5lMT5BcYhdSSyLXn";
char ssid[] = "P108 - TT Home";
char pass[] = "brvt020803";
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(11, 10); // RX, TX
#define ESP8266_BAUD 9600
ESP8266 wifi(&EspSerial);
int quangtro = A0;
boolean a=0, b=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(rl, OUTPUT);
  Serial.begin(9600);
  pinMode(rll,OUTPUT);
  Serial.println(F("DHTxx test!"));
  delay(10);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  
}
BLYNK_WRITE(V4)
{
 a = param.asInt();
}
BLYNK_WRITE(V5)
{
 b = param.asInt();
}


void loop() 
{
  int giatriQuangtro = analogRead(quangtro);
  //Serial.println(giatriQuangtro);
  /*
  if (giatriQuangtro > 1000)
  {
    digitalWrite(rl, 1);
  }
  else
  {
    digitalWrite(rl, 0);
  }
  */
  Blynk.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.setCursor(2,0);
  lcd.print(t,1);
  lcd.setCursor(6,0);
  lcd.print("oC");
  lcd.setCursor(9,0);
  lcd.print("H:");
  lcd.setCursor(11,0);
  lcd.print(h,1);
  lcd.setCursor(15,0);
  lcd.print("%");
  lcd.setCursor(4,1);
  if(giatriQuangtro > 1000)
  {
  lcd.print("TROI TOI");
  }
  else
  {
  lcd.print("TROI SANG");
  }
  //lcd.print("LX:");
  //lcd.setCursor(11, 0);
  //lcd.print(giatriQuangtro);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V3,giatriQuangtro);
  if ((a==1)||(giatriQuangtro > 1020))
  {
    digitalWrite(rl, 1);
  }
  if ((a==0)&(giatriQuangtro <1020))
  {
    digitalWrite(rl, 0);
  }
  if (( b==1)||(t>30))
  {
   digitalWrite(rll, 1);
  }
  if((b==0)&(t<30))
  {
   digitalWrite(rll,0);
  }
}
