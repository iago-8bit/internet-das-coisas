#define luz A0//porta do sensor 
int lumin;//variavel
void setup() {
  Serial.begin(9600);//indica que vai usar o Monitor Serial
  
}

void loop() {
  
  lumin = analogRead(luz);//variavel recebe valor da porta analogica (A0)
  Serial.println(lumin);//exibe valor
  delay(100);//delay para não mostrar valores na velocidade da luz slk 
  
}
