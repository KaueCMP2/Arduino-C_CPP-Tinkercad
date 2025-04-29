#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBt;

void setup()
{
  Serial.begin(9600); // inicializa a

  if (!SerialBt.begin("ESPulsenMaster", true)) //*inicializa a coneccao bt no modo master...
  {
    Serial.println("Erro ao inicializar Bruetooth no modo master!!!"); //! caso contrario...
  }

  if (SerialBt.connect("ESPulsenSlave"))
  {
    Serial.println("conectado com sucesso ao ESPulsenSlave...");
  }
  else
  {
    Serial.println("Falha ao tentar conectar...");
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
    String comandoReceber = Serial.readStringUntil('\n');
    comandoReceber.trim();
    Serial.printf("comando recebido: %s\n\r", comandoReceber);
    if (comandoReceber.equals("liga"))
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
      Serial.println("comando nao reconhecido");
    }
  }
}
