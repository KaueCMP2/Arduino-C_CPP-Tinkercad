#include <Arduino.h>
#define pinLed 2

void setup()
{
  pinMode(pinLed, OUTPUT);                           // Define o led como saida
  Serial.begin(9600);                                // Inicia a comunicacao com o monitor serial com velocidade de 9600
  Serial.println("comunicacao Serial foi iniciada"); // imprime no monitor serial a frase "comunicacao Serial foi iniciada"
}

void loop()
{
  //* Tratamento Led
  static bool estadoLed = false;
  static bool piscaLed = false;

  //* Tratamento tempo
  static unsigned long tempoInicial = 0;
  unsigned long tempo = 300;
  unsigned long tempoAtual = millis();

  if (Serial.available()) // Se ver
  {
    String msg = Serial.readStringUntil('\n');
    msg.trim();

    if (msg.equals("liga"))
    {
      Serial.println(" ");
      Serial.println("ligando o led...");
      estadoLed = true;
      Serial.println("Led ligado!!!");
    }
    else if (msg.equals("desliga"))
    {
      Serial.println(" ");
      Serial.println("Desligando o led...");
      estadoLed = false;
      Serial.println("Led desligado!!!");
    }
    if (msg.equals("pisca"))
    {
      piscaLed = true;
    
      Serial.println(" ");
      Serial.println("Seu led esta piscando");
    }
    if (msg.equals("parar"))
    {
      piscaLed = false;

      Serial.println(" ");
      Serial.println("Seu led parou de piscar");
    }

    if (msg.equals("rap"))
    {
      Serial.println(" ");
      Serial.println("Acelerando...");
      tempo -= 50; //* tempo = tempo - 50
      if (tempo < 50)
      {
        Serial.println("Ops, velocidade maxima atingida");
        tempo = 50;
      }
      Serial.println("Pronto, led esta mais rapido!!!");
    }

    if (msg.equals("dev"))
    {
      Serial.println(" ");
      Serial.println("Desacelerando...");
      tempo += 50;
      if (tempo > 1000)
      {
        tempo = 1000;
        Serial.println("Velocidade minima atingida");
      }
      Serial.println("Pronto, led esta mais devagar!!!");
    }
    if (msg.startsWith("Vel = "))
    {
      int tamanho = msg.length();
      String extracao = msg.substring(6, tamanho);
      int valorVelocidade = extracao.toInt();

      if (valorVelocidade >= 0 && valorVelocidade <= 100)
        tempo = map(valorVelocidade, 0, 100, 1000, 50);

      else
        Serial.println("Apenas valores entre 0 e 100");
    }
    if(piscaLed)
    {
      if(tempoAtual - tempoInicial > tempo)
      {
        estadoLed = !estadoLed;
        tempoInicial = tempoAtual;
      }
    }
    digitalWrite(pinLed, estadoLed);
  }
}