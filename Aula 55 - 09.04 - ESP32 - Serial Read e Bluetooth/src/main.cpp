#include <Arduino.h>
#include "BluetoothSerial.h"

#define pinLed 2

//* Instancias de Objetos
String palavra = "";

void setup()
{
  Serial.begin(9600);
  Serial.println("Digite algo no monitor Serial:");
  
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  while (Serial.available())
  {

    char caractere = Serial.read();

    if (caractere == '\n')
    {
      Serial.println(palavra);
      if (palavra.equals("liga"))
      {
        digitalWrite(pinLed, HIGH);
      }

      else if (palavra.equals("desliga"))
      {
        digitalWrite(pinLed, LOW);
      }

      else
      {
        Serial.println("Comando nao reconhecido");
      }
      palavra = "";
    }
    else if (caractere != '\r')
    {
      palavra += caractere;
    }
  }
}