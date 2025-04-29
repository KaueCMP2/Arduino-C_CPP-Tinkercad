#include <Arduino.h>

struct rgb
{
  int r;
  int g;
  int b;
};

rgb azul;
rgb verde;
rgb vermelho;

void setup() 
{
  Serial.print(9600);

  azul.r = 61;
  azul.g = 85;
  azul.b = 200;

  verde.r = 0;
  verde.g = 180;
  verde.b = 10;

  vermelho.r = 255;
  vermelho.g = 5;
  vermelho.b = 10;
}

void loop() 
{
  
}
