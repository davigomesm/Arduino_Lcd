#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600); 
}

void loop() {
  int nums[3];  
  int menor, maior;
  
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Digite o primeiro");
  lcd.setCursor(0, 1); 
  lcd.print("numero:");
  
  while(!Serial.available());  
  nums[0] = Serial.parseInt(); 
  menor = nums[0];
  maior = nums[0];

  for(int i=1; i<3; i++) {
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("Digite o proximo");
    lcd.setCursor(0, 1);
    lcd.print("numero (");
    lcd.print(i+1);
    lcd.print("/3):");
    
    while(!Serial.available()); 
    nums[i] = Serial.parseInt();
  }

  for(int i=0; i<3; i++) {
    if(nums[i] < menor) menor = nums[i]; 
    if(nums[i] > maior) maior = nums[i];  
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Menor:");
  lcd.print(menor);
  delay(2500);
  lcd.setCursor(0, 1);
  lcd.print("Maior:");
  lcd.print(maior);
  delay(2500);
  
  Serial.print("O menor valor lido foi: ");
  Serial.println(menor);
  Serial.print("O maior valor lido foi: ");
  Serial.println(maior);
}