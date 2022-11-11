#define ledVerde1 6
#define ledVermelho1 7
#define ledVerde2 8
#define ledVermelho2 9
#define trigger1 10
#define echo1 11
#define trigger2 12 
#define echo2 13

int livres = 0, ocupadas = 0;

float tVaga1 = 0, dVaga1 = 0, tVaga2 = 0, dVaga2 = 0;

#include <LiquidCrystal.h>

LiquidCrystal lcd(0,1,2,3,4,5);

void setup()
{
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  
  pinMode(trigger1, OUTPUT);
  pinMode(trigger2, OUTPUT);
  
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  
  lcd.begin(16, 2);
}
void loop() 
{
  
  
  digitalWrite(trigger2, LOW);
  delayMicroseconds(5);
  
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(5);
  
  digitalWrite(trigger2, LOW);
  
  float tVaga1 = pulseIn(echo2, HIGH);
  dVaga1=(tVaga1*340/20000)/100;
  delayMicroseconds(5);
  
  
  digitalWrite(trigger1, LOW);
  delayMicroseconds(5);
  
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(5);
  
  digitalWrite(trigger1, LOW);
  
  float tVaga2 = pulseIn(echo1, HIGH);
  dVaga2 = (tVaga2*340/20000)/100;
  delay(90);
  
  
  
  if(dVaga1 < 2.00 && dVaga2 < 2.00){
  	livres = 0;
    ocupadas = 2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Vagas livres   " + String(livres));
    lcd.setCursor(0,1);
    lcd.print("Vagas ocupadas " + String(ocupadas));
  }
  
  if(dVaga1 > 2.00 && dVaga2 > 2.00){
    livres = 2;
    ocupadas = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(livres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas "+ String(ocupadas));
  }
  
  if(dVaga1 < 2.00 && dVaga2 > 2.00) {
    livres = 1;
    ocupadas = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(livres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas "+ String(ocupadas));
  }
  
  if (dVaga1 > 2.00 && dVaga2 < 2.00) {
  	livres = 1;
    ocupadas = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vagas livres   " + String(livres));
    lcd.setCursor(0, 1);
    lcd.print("Vagas ocupadas "+ String(ocupadas));
  }
  
  if(dVaga1 > 2.00){
  	digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVermelho1, LOW);
  }else {
  	digitalWrite(ledVerde1, LOW);
    digitalWrite(ledVermelho1, HIGH);
  }
  
  if(dVaga2 > 2.00){
  	digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledVermelho2, LOW);
  }else {
  	digitalWrite(ledVerde2, LOW);
    digitalWrite(ledVermelho2, HIGH);
  }
    
}
