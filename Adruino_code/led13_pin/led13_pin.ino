// code den 13 nhap nhay
int led = 13;
void setup()
{                
  pinMode(led, OUTPUT);    
}
void loop() 
{
  digitalWrite(led, HIGH);   
  delay(1000);               
  digitalWrite(led, LOW);    
  delay(1000);       
}
