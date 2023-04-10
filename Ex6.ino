#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
    lcd.begin(16, 2);
    Serial.begin(9600);
}
void loop(){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Digite o num.");
    lcd.setCursor(0, 1);
    lcd.print("inferior do itv.");

    while(!Serial.available());
    int numinf = Serial.parseInt();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Digite o num.");
    lcd.setCursor(0, 1);
    lcd.print("superior do itv.");

    while(!Serial.available());
    int numsup = Serial.parseInt();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Digite o num.");
    lcd.setCursor(0, 1);
    lcd.print("para verificar: ");

    while(!Serial.available());
    int numver = Serial.parseInt();
  	
  	lcd.clear();

    if(numver >= numinf && numver <= numsup){
        lcd.setCursor(0, 0);
        lcd.print("O numero esta");
        lcd.setCursor(0, 1);
        lcd.print("dentro do itv.");
    }
    else{
        lcd.setCursor(0, 0);
        lcd.print("O numero NAO sta");
        lcd.setCursor(0, 1);
        lcd.print("dentro do itv.");
    }

    if(numver >= numinf && numver <= numsup){
        Serial.print("O numero esta dentro do intervalo \n");
    }
    else{
        Serial.print("O numero NAO esta dentro do intervalo \n");
    }
}