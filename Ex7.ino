#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  
  int numero;
  lcd.setCursor(0, 0);
  lcd.print("Digite um numero");		
  lcd.setCursor(0, 1);
  lcd.print("entre 12 e 20:");
  while (true) {
    if (Serial.available() > 0) {
      numero = Serial.parseInt();
      if (numero >= 12 && numero <= 20) {
        break;
      } else {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Entrada invalida ");
        delay(3000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Digite um numero");
        lcd.setCursor(0, 1);
        lcd.print("entre 12 e 20:");
      }
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Numero digitado: ");
  lcd.setCursor(0, 1);
  lcd.print(numero);
  delay(3000);
  lcd.clear();
}