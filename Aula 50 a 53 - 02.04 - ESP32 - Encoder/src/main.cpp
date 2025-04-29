#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define canalA 13
#define canalB 27
#define pinBotao 14

bool estadoInicialA = 0;
bool estadoInicialB = 0;

int resultado = 0;
int contagem = 0;

void horario();
void antihorario();

void setup()
{
  Serial.begin(9600);

  pinMode(canalA, INPUT);
  pinMode(canalB, INPUT);
  pinMode(pinBotao, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("Gire o Botao");
}

void loop()
{

  int estadoAtualA = digitalRead(canalA);
  int estadoAtualB = digitalRead(canalB);

  if (estadoAtualA != estadoInicialA || estadoAtualB != estadoInicialB)
  {
    resultado = estadoAtualA << 1 | estadoAtualB;

    Serial.println(resultado);
    delay(100);
    Serial.println("____");

    estadoInicialA = estadoAtualA;
    estadoInicialB = estadoAtualB;
  }

  if (estadoAtualA != estadoInicialA)
  {
    contagem++;
    horario();
    delay(200);
  }

  if (estadoAtualB != estadoInicialB)
  {
    contagem--;
    horario();
    delay(200);
  }
}

void horario()
{
  lcd.setCursor(0, 3);
  lcd.print("numero e");
  lcd.print(contagem);
  lcd.print("  ");
}

void antihorario()
{
  lcd.setCursor(0, 3);
  lcd.print("numero e");
  lcd.print(contagem);
  lcd.print("  ");
}