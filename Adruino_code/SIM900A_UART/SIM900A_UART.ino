#include <SoftwareSerial.h>
#include <TinyGPS++.h>
char msg;
TinyGPSPlus gps;

void setup()
{
 Serial1.begin(9600); 
 Serial.begin(9600);
 Serial2.begin(9600);
 delay(100);
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop()
{  
 SendMessage();
  while (Serial2.available() > 0)
    if (gps.encode(Serial2.read()))
      displayInfo();
  {
    Serial.println("No GPS detected");
    while(true);
  }
}
void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 10);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 10);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}
void SendMessage()
{
  Serial1.println("AT+CMGF=1");
  delay(1000);
  Serial1.println("AT+CMGS=\"+84589162448\"\r");
  delay(1000);
  Serial1.println("Co chay xay ra tai :");
  Serial1.print("15, 17");
  delay(100);
  Serial1.println((char)26);
  delay(1000);
}
