#include "DHT.h"
int dht_pin = 9;
int DHTTYPE = DHT11;
int quangtro = A0;
DHT dht(dht_pin, DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  dht.begin();
}
void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float tf = dht.readTemperature(true);
  int giatriQuangtro = analogRead(quangtro);
  Serial.println(giatriQuangtro); 
  delay(500);
  Serial.println(t);  
}
