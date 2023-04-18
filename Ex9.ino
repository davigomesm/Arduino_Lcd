#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop(){
  int idade;
  int soma_idades = 0;
  int num_pessoas = 0;
  int menor_idade = 1000;
  int maior_idade = 0;
  
  while (true){
    lcd.setCursor(0, 0);
    lcd.print("Digit a idade da");
    lcd.setCursor(0, 1);
    lcd.print("pessoa:(0)p/sair");
    Serial.println("Digite a idade da pessoa: ");
    while(!Serial.available());
    idade = Serial.parseInt();
    if (idade == 0) {
      break;
    }
    soma_idades += idade;
    num_pessoas++;
    if (idade < menor_idade) {
      menor_idade = idade;
    }
    if (idade > maior_idade) {
      maior_idade = idade;
    }
  }
  float idade_media = (float) soma_idades / (float) num_pessoas;
  lcd.clear();
  lcd.print("Num de Pessoas: ");
  lcd.print(num_pessoas);
  lcd.setCursor(0, 1);
  lcd.print("Idade Media: ");
  lcd.print(idade_media);
  Serial.println("Numero de Pessoas: ");
  Serial.println(num_pessoas);
  Serial.println("idade media: ");
  Serial.println(idade_media);
  
  delay(4000);
  
  lcd.clear();
  lcd.print("Menor Idade: ");
  lcd.print(menor_idade);
  lcd.setCursor(0, 1);
  lcd.print("Maior Idade: ");
  lcd.print(maior_idade);
  Serial.println("idade da pessoa mais velha: ");
  Serial.println(maior_idade);
  Serial.println("idade da pessoa mais nova: ");
  Serial.println(menor_idade);
  
  delay(4500);
}