#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Pino de conexão do sensor DHT11
const int pinoDHT11 = 2;

// Inicialização do sensor DHT11
DHT dht(pinoDHT11, DHT11);

// Inicialização do display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inicialização do sensor DHT11
  dht.begin();

  // Inicialização do display LCD
  lcd.begin(16, 2);
  lcd.print("Temp:");
  lcd.setCursor(0, 1);
  lcd.print("Umidade:");
}

void loop() {
  // Leitura da temperatura e umidade do sensor DHT11
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Atualização dos valores no display LCD
  lcd.setCursor(6, 0);
  lcd.print("     "); // Limpa o valor anterior
  lcd.setCursor(6, 0);
  lcd.print(temperatura);
  lcd.setCursor(10, 1);
  lcd.print("     "); // Limpa o valor anterior
  lcd.setCursor(10, 1);
  lcd.print(umidade);

  // Aguarda alguns segundos antes de realizar a próxima leitura
  delay(2000);
}
