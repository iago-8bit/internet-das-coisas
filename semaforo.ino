#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>
Ultrasonic ultrasom(5,4);
LiquidCrystal_I2C lcd(0x27,16,2);

int red = 2;
int yellow = 3;
int azul = 4;
int dist;


void setup() {
  lcd.init();
  lcd.backlight();
  digitalWrite(red, OUTPUT);
  digitalWrite(yellow, OUTPUT);
  digitalWrite(azul, OUTPUT);
}

void timer(){
  digitalWrite(azul, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);

  for(int seg = 10; seg > 0; seg--){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(seg);
  delay(1000);
}
  digitalWrite(azul, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("transito");
  dist = ultrasom.Ranging(CM);
  
   while(dist < 1){
    timer();
  }

    digitalWrite(azul, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    delay (5000);//sinal azul pode passar

    digitalWrite(azul, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    delay (3000);//sinal amarelo atenção

    digitalWrite(azul, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay (5000);//sinal vermelho pare
  /*if(dist <10){
    timer();
  }*/

}
