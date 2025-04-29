#include <Arduino.h>
#define pinLed 21

// * prototipos da funcao
void ligaLed(uint8_t pin);
void desligaLed(uint8_t pin);
void piscaLed(uint8_t pin);

int calculaSegundoGrau(int, int, int);

void setup()
{
  Serial.begin(9600);
  int raizDaFuncao = calculaSegundoGrau(1, 6, 9);
  Serial.println(raizDaFuncao);
  pinMode(pinLed, OUTPUT);
}

void loop()
{
  piscaLed(pinLed);
  
}

int calculaSegundoGrau(int a, int b, int c)
{
  int resultado;
  resultado = (-b + sqrt((b*b) - (4 * a * c))) / (2 * a);
  return resultado;
}

void ligaLed(uint8_t pin)
{
  digitalWrite(pin, HIGH);
}

void desligaLed(uint8_t pin)
{
  digitalWrite(pin, LOW);
}

void piscaLed(uint8_t pin)
{
  digitalWrite(pin, HIGH);
  delay(300);
  digitalWrite(pin, LOW);
  delay(300);
}