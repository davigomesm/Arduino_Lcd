#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
	lcd.begin(16, 2);
  	Serial.begin(9600);
}
void loop(){
  	int tam = 10;
  	int j = 0;
	int vetor1[tam];
	int vetor2[tam];
  	int vetor3[tam * 2];
  	
  	
  	lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Digite no vetor1");
  	lcd.setCursor(0, 1);
  	lcd.print("os seus valores: ");
  	delay(2000);
  	lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Digite o");
  	lcd.setCursor(0, 1);
  	lcd.print("primeiro valor");
  	
  	
	while(!Serial.available());
	vetor1[0] = Serial.parseInt();
	for(int i=1; i<tam; i++){
      	lcd.clear();
    	lcd.setCursor(0, 0);
    	lcd.print("Digite o proximo");
    	lcd.setCursor(0, 1);
    	lcd.print("numero (");
    	lcd.print(i+1);
    	lcd.print("/10):");
    	while(!Serial.available());
    	vetor1[i] = Serial.parseInt();
    }
  
  	lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Digite no vetor2");
  	lcd.setCursor(0, 1);
  	lcd.print("os seus valores: ");
  	delay(2000);
  	lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("Digite o");
  	lcd.setCursor(0, 1);
  	lcd.print("primeiro valor");
  
	while(!Serial.available());
	vetor2[0] = Serial.parseInt();
	for(int i=1; i<tam; i++){
      	lcd.clear();
    	lcd.setCursor(0, 0);
    	lcd.print("Digite o proximo");
    	lcd.setCursor(0, 1);
    	lcd.print("numero (");
    	lcd.print(i+1);
    	lcd.print("/10):");
    	while(!Serial.available());
    	vetor2[i] = Serial.parseInt();
    }
  	for(int i=0; i<tam; i++){
    	vetor3[j++] = vetor1[i];
      	vetor3[j++] = vetor2[i];
  	}
  	for(int i=0; i<tam*2; i++){
      	Serial.print(vetor3[i]);
    }
}