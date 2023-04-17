#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Digite sua scala");
  lcd.setCursor(0, 1);
  lcd.print("desejada: C,F,K");
  
  Serial.println("Digite a escala da sua temperatura, 1 pra celcius, 2 para fareraiti, 3 pra kevin \n");
  while(!Serial.available());
  float temperatura = Serial.parseFloat();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Digite valor da");
  lcd.setCursor(0, 1);
  lcd.print("sua temperatura");
  
  Serial.println("Digite os graus da sua temperatura: \n");
  while(!Serial.available());
  float valor = Serial.parseFloat();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Para qual deseja");
  lcd.setCursor(0, 1);
  lcd.print("converter: C,F,K");
  
  Serial.println("Para qual escala deseja converter: digite 1 pra celcius, 2 para fareraiti, 3 pra kevin \n");
  while(!Serial.available());
  float converter = Serial.parseFloat();
  float temperaturaconvertida;
  
  if(temperatura == 1 && converter == 2){
    temperaturaconvertida = valor * 1.8 + 32;
  }
  if(temperatura == 1 && converter == 3){
    temperaturaconvertida = valor + 273.15;
  }
  if(temperatura == 2 && converter == 1){
    temperaturaconvertida = (valor - 32) / 1.8;
  }
  if(temperatura == 2 && converter == 3){
    temperaturaconvertida = (valor - 32) * 5/9 + 273.15;
  }
  if(temperatura == 3 && converter == 1){
    temperaturaconvertida = (valor - 273.15);
  }
  if(temperatura == 3 && converter == 2){
    temperaturaconvertida = 1.8 * (valor - 273) + 32;
  }
  else{
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Convertido para");
  	lcd.setCursor(0, 1);
  	lcd.print("o mesmo valor");
    temperaturaconvertida = valor;
    delay(2500);
  }
  Serial.println("valor convertido: ");
  Serial.println(temperaturaconvertida);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Convertido para:");
  lcd.setCursor(0, 1);
  lcd.print(temperaturaconvertida);
  delay(5000);
}
  