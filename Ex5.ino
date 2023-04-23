#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {
  lcd.begin(16, 2);  
  Serial.begin(9600); 
}

void loop() {
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("Digite um numero:");
  
  while(!Serial.available()); 
  int num = Serial.parseInt(); 
  
  bool primo = true;
  for(int i=2; i<num; i++) {
    if(num % i == 0) {
      primo = false;
      break;
    }
  }
  
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("O numero ");
  lcd.print(num);
  lcd.setCursor(0, 1); 
  if(primo) {
    lcd.print("e primo");
  } else {
    lcd.print("nao e primo");
  }

  Serial.print("O numero ");
  Serial.print(num);
  if(primo) {
    Serial.println(" e primo");
  } else {
    Serial.println(" nao e primo");
  }
}