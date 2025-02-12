#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
DHT11 dht(10);
int temperatura;
float umidade;

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop(){

  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  umidade = umidade /10;
  lcd.setCursor(0,0);
  lcd.print(temperatura);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print(umidade);
/*
  Serial.print("temepratura: ");
  Serial.print(temperatura);
  Serial.println("C°");

  Serial.print("umidade do ar: ");
  Serial.print(umidade); 
  Serial.println("%");
*/
}