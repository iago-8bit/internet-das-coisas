#include <Servo.h>

Servo servo;

const int botao1 = 2;
const int botao2 = 3;
const int botao3 = 4;

int velocidade;

void setup()
{
  servo.attach(9);
  Serial.begin(9600);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  digital.write(botao1, LOW);
  digital.write(botao2, LOW);
  digital.write(botao3, LOW);
  servo.write(0);
}

void loop() {


  if (digitalRead(botao1) == HIGH) {
    Serial.println("Botão 1");
    velocidade = 15;  // Ajuste a velocidade conforme necessário
    
    
    for (int pos = 0; pos <= 179; pos++) {
      servo.write(pos);
      delay(velocidade);  // Atraso igual para o movimento para frente e para trás
    }

    // Movimento para trás (179 a 0)
    for (int pos = 179; pos >= 0; pos--) {
      servo.write(pos);
      delay(velocidade);  // Atraso igual para o movimento para frente e para trás
    }
  }

  if (digitalRead(botao2) == HIGH) {
    Serial.println("Botão 2");
    velocidade = 15;  // Ajuste a velocidade conforme necessário
    
    // Movimento para frente (0 a 179)
    for (int pos = 0; pos <= 179; pos++) {
      servo.write(pos);
      delay(velocidade);  // Atraso igual para o movimento para frente e para trás
    }

    // Movimento para trás (179 a 0)
    for (int pos = 179; pos >= 0; pos--) {
      servo.write(pos);
      delay(velocidade);  // Atraso igual para o movimento para frente e para trás
    }
  }

  if (digitalRead(botao3) == HIGH) {
    Serial.println("Botão 3");
    velocidade = 15;  // Ajuste a velocidade conforme necessário
    

    // Movimento para frente (0 a 179)
    for (int pos = 0; pos <= 179; pos++) {
      servo.write(pos);
      delay(velocidade);  // Atraso igual para o movimento para frente e para trás
    }

    // Movimento para trás (179 a 0)
    for (int pos = 179; pos >= 0; pos--) {
      servo.write(pos);
      delay(100);  // Atraso igual para o movimento para frente e para trás
    }
  }
}
