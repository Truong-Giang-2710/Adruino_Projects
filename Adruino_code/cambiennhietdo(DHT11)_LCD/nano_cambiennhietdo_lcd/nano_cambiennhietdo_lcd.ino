#include "DHT.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int dht_pin = 7;//Khai báo chân kết nối DHT với Arduino
int DHTTYPE = DHT11;//Khai báo loại cảm biến DHT
DHT dht(dht_pin, DHTTYPE);//Khai báo một đối tượng DHT
void setup() {
  lcd.begin(16, 2);
  dht.begin();//Khởi tạo đối tượng DHT
}

void loop() {
  float h = dht.readHumidity();//Lấy giá trị độ ẩm
  float t = dht.readTemperature();//Lấy giá trị nhiệt độ ở đơn vị độ C
  float tf = dht.readTemperature(true);//Lấy giá trị nhiệt độ ở đơn vị độ F
  lcd.setCursor(0, 0);
  lcd.print("HUMIDITY:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.print(char(223));
  lcd.print("C");
  lcd.print("-");
  lcd.print(tf);
  lcd.print(char(223));
  lcd.print("F");
}
