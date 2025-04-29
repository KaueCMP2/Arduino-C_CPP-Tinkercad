#include <Arduino.h>
#include "BluetoothSerial.h"

#define pinLed 2

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW); // Garante que o LED começa desligado

  // Inicialização do Bluetooth no modo master
  SerialBT.begin("ESPadrao", true); // true = master
  Serial.println("Espada Pronto para receber comandos...");
}

void loop() {
  // Verifica se chegou algum dado pelo Serial Monitor
  if (Serial.available()) {
    // Lê a string enviada pelo Serial Monitor até a quebra de linha ('\n')
    String comando = Serial.readStringUntil('\n');

    // Remove espaços em branco ou quebras extras no início e fim
    comando.trim();

    // Envia o comando lido via Bluetooth para o slave (ESPada)
    SerialBT.println(comando);

    // Mostra no Serial Monitor o comando que foi enviado
    Serial.println("Comando enviado via Bluetooth: " + comando);

    // Define um tempo limite de 3 segundos para aguardar a resposta do slave
    unsigned long timeout = millis() + 3000;

    // Aguarda até chegar uma resposta ou até estourar o tempo limite
    while (millis() < timeout) {
      // Se chegar algum dado via Bluetooth
      if (SerialBT.available()) {
        // Lê a resposta recebida até a quebra de linha
        String resposta = SerialBT.readStringUntil('\n');

        // Remove espaços em branco ou quebras extras
        resposta.trim();

        // Exibe a resposta recebida no Serial Monitor
        Serial.println("Resposta recebida: " + resposta);

        // Sai do loop assim que receber a resposta
        break;
      }
    }
  }
}
