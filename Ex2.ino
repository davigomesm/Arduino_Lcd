#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600); 
}

void loop() {
  int nums[10]; 
  int soma = 0;
  
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Digite o primeiro");
  lcd.setCursor(0, 1); 
  lcd.print("numero:");
  
  while(!Serial.available());  
  nums[0] = Serial.parseInt(); 

  for(int i=1; i<10; i++) {
    lcd.clear();  
    lcd.setCursor(0, 0); 
    lcd.print("Digite o proximo");
    lcd.setCursor(0, 1);  
    lcd.print("numero (");
    lcd.print(i+1);
    lcd.print("/10):");
    
    while(!Serial.available());  
    nums[i] = Serial.parseInt();  
  }

  for(int i=0; i<10; i++) {
    soma += nums[i];
  }

  lcd.clear();  
  lcd.setCursor(0, 0);  
  lcd.print("Soma:");
  lcd.print(soma);
  delay(5000);
 
  Serial.print("A soma dos valores lidos foi: ");
  Serial.println(soma);
}