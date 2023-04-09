#include <LiquidCrystal.h>  // Inclui a biblioteca do LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Define os pinos do LCD

void setup() {
  lcd.begin(16, 2);  // Inicializa o LCD
  Serial.begin(9600);  // Inicializa a comunicação serial
}

void loop() {
  int nums[10];  // Cria um vetor com 10 elementos
  int menor, maior;
  
  lcd.clear();  // Limpa o LCD
  lcd.setCursor(0, 0);  // Define o cursor para a primeira linha
  lcd.print("Digite o primeiro");
  lcd.setCursor(0, 1);  // Define o cursor para a segunda linha
  lcd.print("numero:");
  
  // Lê o primeiro número
  while(!Serial.available());  // Espera o usuário digitar algo
  nums[0] = Serial.parseInt();  // Lê o número digitado
  menor = nums[0];  // Inicializa menor e maior com o primeiro número lido
  maior = nums[0];

  // Lê os próximos 9 números e armazena no vetor
  for(int i=1; i<10; i++) {
    lcd.clear();  // Limpa o LCD
    lcd.setCursor(0, 0);  // Define o cursor para a primeira linha
    lcd.print("Digite o proximo");
    lcd.setCursor(0, 1);  // Define o cursor para a segunda linha
    lcd.print("numero (");
    lcd.print(i+1);
    lcd.print("/10):");
    
    while(!Serial.available());  // Espera o usuário digitar algo
    nums[i] = Serial.parseInt();  // Lê o número digitado
  }

  // Procura o menor e o maior valor no vetor
  for(int i=0; i<10; i++) {
    if(nums[i] < menor) menor = nums[i];  // Atualiza menor, se necessário
    if(nums[i] > maior) maior = nums[i];  // Atualiza maior, se necessário
  }

  // Escreve o menor e o maior valor lido no LCD
  lcd.clear();  // Limpa o LCD
  lcd.setCursor(0, 0);  // Define o cursor para a primeira linha
  lcd.print("Menor:");
  lcd.print(menor);
  lcd.setCursor(0, 1);  // Define o cursor para a segunda linha
  lcd.print("Maior:");
  lcd.print(maior);
  
  // Escreve o menor e o maior valor lido na porta serial
  Serial.print("O menor valor lido foi: ");
  Serial.println(menor);
  Serial.print("O maior valor lido foi: ");
  Serial.println(maior);
}