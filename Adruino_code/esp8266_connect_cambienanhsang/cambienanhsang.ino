int quangtro = A0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int giatriQuangtro = analogRead(quangtro);
  Serial.println(giatriQuangtro); 
  delay(500);
} 
