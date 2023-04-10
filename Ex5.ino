#include <LiquidCrystal.h>  // Inclui a biblioteca do LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Define os pinos do LCD

void setup() {
  lcd.begin(16, 2);  // Inicializa o LCD
  Serial.begin(9600);  // Inicializa a comunicação serial
}

void loop() {
  lcd.clear();  // Limpa o LCD
  lcd.setCursor(0, 0);  // Define o cursor para a primeira linha
  lcd.print("Digite um numero:");
  
  while(!Serial.available());  // Espera o usuário digitar algo
  int num = Serial.parseInt();  // Lê o número digitado
  
  // Verifica se o número é primo
  bool primo = true;
  for(int i=2; i<num; i++) {
    if(num % i == 0) {
      primo = false;
      break;
    }
  }
  
  // Escreve o resultado no LCD
  lcd.clear();  // Limpa o LCD
  lcd.setCursor(0, 0);  // Define o cursor para a primeira linha
  lcd.print("O numero ");
  lcd.print(num);
  lcd.setCursor(0, 1);  // Define o cursor para a segunda linha
  if(primo) {
    lcd.print("e primo");
  } else {
    lcd.print("nao e primo");
  }
  
  // Escreve o resultado na porta serial
  Serial.print("O numero ");
  Serial.print(num);
  if(primo) {
    Serial.println(" e primo");
  } else {
    Serial.println(" nao e primo");
  }
}