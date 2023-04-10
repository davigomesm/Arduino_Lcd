#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Digite um numero");
}

void loop() {
  
  int numero;

  lcd.setCursor(0, 1);
  lcd.print("Entre 12 e 20:");
  while (true) {
    if (Serial.available() > 0) {
      numero = Serial.parseInt();
      if (numero >= 12 && numero <= 20) {
        break;
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Entrada invalida ");
        delay(1000);
        lcd.setCursor(0, 1);
        lcd.print("Entre 12 e 20:  ");
      }
    }
  }

  lcd.setCursor(0, 1);
  lcd.print("Numero digitado: ");
  lcd.print(numero);
  delay(2000);
  lcd.clear();
}