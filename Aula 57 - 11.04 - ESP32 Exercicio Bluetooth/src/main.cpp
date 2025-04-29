#include <Arduino.h>
#define pinLed 21

void setup()
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(18, INPUT_PULLUP);
}

void loop()
{

  bool estadoBotao = digitalRead(18);

   if (estadoBotao == 1)
  {
    digitalWrite(pinLed, LOW);
  }

  else if (estadoBotao == 0)
  {
    digitalWrite(pinLed, HIGH);
  }
}