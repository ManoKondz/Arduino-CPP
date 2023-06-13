#include <Arduino.h>

// Definição dos pinos dos botões e do buzzer
const int numBotoes = 8;
const int botoes[numBotoes] = {2, 3, 4, 5, 6, 7, 8, 9};
const int pinoBuzzer = 10;

// Frequências correspondentes às notas musicais
const int frequencias[numBotoes] = {262, 294, 330, 349, 392, 440, 494, 523};

// Inicialização do buzzer e dos botões
void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  for (int i = 0; i < numBotoes; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
  }
}

// Verifica se algum botão foi pressionado e toca a nota correspondente
void loop() {
  for (int i = 0; i < numBotoes; i++) {
    if (digitalRead(botoes[i]) == LOW) {
      tocarNota(frequencias[i]);
      delay(200); // Tempo de espera para evitar repetições rápidas
    }
  }
}

// Toca a nota no buzzer por um certo tempo
void tocarNota(int frequencia) {
  tone(pinoBuzzer, frequencia);
  delay(500); // Tempo de duração da nota
  noTone(pinoBuzzer);
}
