#include <Arduino.h>
#define pinLed 2
bool estadoBotao = 0;

bool botao = 0;

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(botao, INPUT);
}

void loop()
{
 estadoBotao = digitalRead(botao);
 
  if (estadoBotao = 0)
  {
    digitalWrite(pinLed, HIGH);
  }
  if (estadoBotao = 1)
  {
    digitalWrite(pinLed, LOW);
  }
}
