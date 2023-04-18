#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  float lado1, lado2, lado3;
  while (true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Digite o tamanho");
    lcd.setCursor(0, 1);
    lcd.print("do lado 1: ");
    Serial.println("Digite o tamanho do lado 1 do triangulo: ");
    while (!Serial.available());
    lado1 = Serial.parseFloat();
    if (lado1 > 0) {
      break;
    }
  }
  
  while (true) {
    lcd.setCursor(0, 0);
    lcd.print("Digite o tamanho");
    lcd.setCursor(0, 1);
    lcd.print("do lado 2: ");
    Serial.println("Digite o tamanho do lado 2 do triangulo: ");
    while (!Serial.available());
    lado2 = Serial.parseFloat();
    if (lado2 > 0) {
      break;
    }
  }
  
  while (true) {
    lcd.setCursor(0, 0);
    lcd.print("Digite o tamanho");
    lcd.setCursor(0, 1);
    lcd.print("do lado 3: ");
    Serial.println("Digite o tamanho do lado 3 do triangulo: ");
    while (!Serial.available());
    lado3 = Serial.parseFloat();
    if (lado3 > 0) {
      break;
    }
  }
  
  if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
    
    if (lado1 == lado2 && lado1 == lado3) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("O triangulo e:");
      lcd.setCursor(0, 1);
      lcd.print("Equilatero");
      Serial.println("O triangulo e equilatero");
    }
    
    if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("O triangulo e:");
      lcd.setCursor(0, 1);
      lcd.print("Isoceles");
      Serial.println("O triangulo e isoceles");
    } 
    
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("O triangulo e:");
      lcd.setCursor(0, 1);
      lcd.print("Escaleno");
      Serial.println("O triangulo e escaleno");
    }
  } 
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nao forma");
    lcd.setCursor(0, 1);
    lcd.print("um triangulo");
    Serial.println("Os lados nao formam um triangulo");
  }
  
  delay(3000);
}
