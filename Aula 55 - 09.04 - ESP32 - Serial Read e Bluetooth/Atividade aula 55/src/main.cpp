#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinLed0 2
#define pinLed1 4
#define pinLed2 7
#define pinLed3 8

void pinLedSaida(void);
void ligaLCD(void);

String comandos = "";

void setup()
{
  Serial.begin(9600);

  pinLedSaida;
  ligaLCD;
}

void loop()
{
 while(Serial.available())
 {
  char caractere = Serial.read();

   if(caractere == '\n' || caractere == '\r')
   {
    Serial.println(comandos);
    if(comandos.equals("liga"))
    {
      digitalWrite(pinLed0, HIGH);
    }
   }
 }`
}

void pinLedSaida()
{
  pinMode(pinLed0, OUTPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
}
void ligaLCD()
{
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 1);
  lcd.print("Algum comando chefe?");
}