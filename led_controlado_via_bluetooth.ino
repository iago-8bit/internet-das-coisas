;int led = 8;//amarelo 
int azul = 9;//
int red = 10; 
  void setup(){
    Serial.begin(9600);
    pinMode(led, OUTPUT);//led amarelo
    pinMode(azul, OUTPUT);//led azul
    pinMode(red, OUTPUT);//led vermelho 
  }

  void loop(){
     String comando = Serial.readString();
     Serial.println(comando);
       if( comando == "led on"){//liga led amarelo 
        digitalWrite(led, HIGH);
      }else if(comando == "led off"){// desliga led amarelo 
        digitalWrite(led, LOW);
      }else if(comando == "azul on"){//liga led azul
        digitalWrite(azul, HIGH);
      }else if(comando == "azul off"){//desliga led azul 
        digitalWrite(azul, LOW);
      }else if(comando == "red on"){//liga led vermelho 
        digitalWrite(red, HIGH);
      }else if(comando == "red off"){//desliga led vermelho 
        digitalWrite(red, LOW);
      }
}//o porque do nome e opcional 
