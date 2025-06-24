#include "DHT.h"
#define rl 7
#define rl1 8
int quangtro = A0;
int dht_pin = 9;
int DHTTYPE = DHT11;
DHT dht(dht_pin, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  pinMode(rl, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  pinMode(rl1, OUTPUT);
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
 }
