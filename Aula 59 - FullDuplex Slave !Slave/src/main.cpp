#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBt;
void setup()
{
  Serial.begin(9600);
  if (!SerialBt.begin("ESPulsenSlave", false))
  {
    Serial.print("Erro ao iniciar Bluetooth como Slave");
  }
}
void loop()
{
  if (Serial.available())
  {
    String comandoEnviar = Serial.readStringUntil('\n');
    comandoEnviar.trim();
    SerialBt.println(comandoEnviar);
  }
  
  if (SerialBt.available())
  {
    String comandoReceber = SerialBt.readStringUntil('\n');
    comandoReceber.trim();
    SerialBt.printf("comando recebido: %s\n\r", comandoReceber);
    if (comandoReceber.equals("Liga"))
    {
    }
    else if (comandoReceber.equals("desliga"))
    {
    }
    else if (comandoReceber.equals("pisca"))
    {
    }
    else
    {
      SerialBt.println("comando nao reconhecido");
    }
  }
}
