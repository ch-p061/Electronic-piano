#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int buzzer = 8;
int button[16] = {22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
int led[16] = {17,16,15,14,21,20,19,18,41,40,39,38,45,44,43,42};
int sound[16] = {262,294,330,349,392,440,494,523,587,659,698,784,880,988,1047,1175};
String text[16] = {"Do", "Re", "Mi", "Pa", "Sol", "Ra", "Si", "Do", "Re", "Mi", "Pa", "Sol", "Ra", "Si", "Do", "Re"};

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  for(int i=0; i<16; i++){
    pinMode(button[i],INPUT);
    pinMode(led[i],OUTPUT);
  }
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<16; i++)
  {
    if(!digitalRead(button[i]))
    {
      digitalWrite(led[i],HIGH);
      tone(buzzer,sound[i],500);
      lcd.print(text[i]);
      delay(500);
      lcd.clear();
    }
    else
    {
      digitalWrite(led[i],LOW);
    }
  }
}
