#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
    lcd.begin(16, 2);
    Serial.begin(9600);
}
void loop(){
    int nums[10];
    int soma, media;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Digite o primeiro");
    lcd.setCursor(0, 1);
    lcd.print("numero: ");

    while(!Serial.available());
    nums[0] = Serial.parseInt();

    for(int i=0; i<10; i++) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Digite o (");
        lcd.print(i+1);
        lcd.print("/10)");
        lcd.setCursor(0, 1);
        lcd.print("numero: ");

        while(!Serial.available());
        nums[i] = Serial.parseInt();
    }

    for(int i=0; i<10; i++) {
        soma += nums[i];
    }

    media = soma/10;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Media: ");
    lcd.print(media);
    delay(5000);

    Serial.print("A media dos valores lidos foi: ");
    Serial.println(media);
}