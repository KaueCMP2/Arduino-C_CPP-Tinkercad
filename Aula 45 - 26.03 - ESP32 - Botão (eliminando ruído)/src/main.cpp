#include <Arduino.h>

#define pinLed 21
#define botao 18

void setup()
{

  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  bool estadoAtualBotao = digitalRead(botao);
  static bool estadoAnteriorBotao = 1;
  static bool estadoBotao = 0;
  static bool ultimaAcao = 1;
  static unsigned long tempoAnteriorDebounce = 0;
  unsigned long tempoAtual = millis();
  const unsigned long tempoDeFiltro = 50; // < que o estado de pressiona-lo e > que o tempo do debounce

  static int contagem = 0;

  // inicio do tratamento de botao
  // Marca quando uma mudanca de estado ocorre
  if (estadoAtualBotao != estadoAnteriorBotao)
  {
    tempoAnteriorDebounce = millis();
  }
  // * Marca quando uma mudanca de estado ocorre
  if ((tempoAtual - tempoAnteriorDebounce) > tempoDeFiltro)
  {
    if (estadoAtualBotao != ultimaAcao) // Houve uma alteracao proposital no botao
    {
      acao = estadoAtualBotao; // agora verifique se ele esta apertado ou solto
      if (!estadoAtualBotao)
      {
        contagem++;
        Serial.println(contagem); // botao foi pressionado
      }
      else
      {
        // o botao foi solto
      }
    }
  }
  estadoAnteriorBotao = estadoAtualBotao; // TODO
}