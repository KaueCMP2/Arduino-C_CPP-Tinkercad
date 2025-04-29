#include <Arduino.h>

struct Pessoa
{
  char nome[20];
  int idade;
  float altura;
  bool calvice;
};

Pessoa aluno;
Pessoa jober;

void setup()
{
  Serial.begin(9600);

  strcpy(aluno.nome, "Kaue");
  aluno.idade = 18;
  aluno.altura = 1.82;
  aluno.calvice = false;

//TODO ta dando pau nesta merda...
/*
  strcpy(jober.nome, "Anna Gir");
  jober.idade = 64;
  jober.altura = 1.98;
  jober.calvice = true;
*/
  Serial.printf("Meu nome e: %s \n\r", aluno.nome);
  Serial.printf("Tenho %d anos \n\r", aluno.idade);
  Serial.printf("Minha altura e: %.2f \n\r", aluno.altura);
  Serial.printf("Eu %s mesmo ", aluno.calvice ? Serial.println("sou CALVO ") : Serial.println("nao, nao sou CALVO"));

//TODO ta dando pau nesta continuacao da merda...
 /*
  Serial.printf("Meu nome e: %s \n\r", jober.nome);
  Serial.printf("Tenho %d anos \n\r", jober.idade);
  Serial.printf("Minha altura e: %.2f \n\r", jober.altura);
  Serial.printf("Eu %s mesmo \n\r", jober.calvice ? Serial.println("sou CALVO :'( ") : Serial.println("nao, nao sou CALVO"));
*/
}

void loop() 
{
  
}