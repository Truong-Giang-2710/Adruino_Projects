#define rl 7
void setup() 
{
 pinMode(rl, OUTPUT);
 int t = Serial.println();
}

void loop() 
{  
  if (t > 30)
  {
    digitalWrite(rl, 1);
  }
  else 
  {
    digitalWrite(rl, 0);
    delay(3000);
  }

}
