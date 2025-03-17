#include <Servo.h>

const int butonn = 7;  // Pino do botão
int pos = 0;            // Posição do servo
int lastButtonState = LOW;  // Estado anterior do botão (usado para detectar mudança)


Servo servo_9;

void setup()
{
  pinMode(butonn, INPUT);  // Configura o pino do botão como entrada
  servo_9.attach(9, 500, 2500);  // Controla o servo no pino 9
  servo_9.write(0);  // Inicializa o servo na posição 0
}

void loop()
{
  int buttonState = digitalRead(butonn);  // Lê o estado do botão

  // Verifica se o botão foi pressionado (muda de LOW para HIGH)
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(50);  // Debounce simples para evitar múltiplos cliques
    if (pos == 0) {
      pos = 180; 
      servo_9.write(pos);  // Atualiza a posição do servo
    } else {
      pos = 0;  
      servo_9.write(pos); 
    }
  }

  lastButtonState = buttonState;  // Atualiza o estado anterior do botão
}
