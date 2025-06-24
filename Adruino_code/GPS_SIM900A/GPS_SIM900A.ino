#include <TinyGPS++.h>
TinyGPSPlus gps;
float latitude,longitude;

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); 
  Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();
}

void loop()
{
 Serial2.listen();
 while (Serial2.available() > 0)
 {
  if (gps.encode(Serial2.read()))
  latitude = (gps.location.lat());
  longitude = (gps.location.lng()); 
 }
 Serial.println(latitude);
 Serial.println(longitude);
}
