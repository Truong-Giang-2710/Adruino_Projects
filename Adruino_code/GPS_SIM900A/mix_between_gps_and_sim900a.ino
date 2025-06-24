#include <TinyGPS++.h>
char msg;
TinyGPSPlus gps;

void setup()
{
 Serial.begin(9600);
 Serial1.begin(9600); 
 Serial2.begin(9600);
 delay(100);
}

void loop()
{  
 while (Serial2.available() > 0)
  if (gps.encode(Serial2.read()))
   SendMessage();
}

void SendMessage(){
  Serial1.println("AT+CMGF=1");
  delay(1000);
  Serial1.println("AT+CMGS=\"+84589162448\"\r");
  delay(1000);
  Serial1.print(gps.location.lat(),6);
  Serial1.print(gps.location.lng(),6);
  delay(100);
  Serial1.println((char)26);
  delay(3000);
}
