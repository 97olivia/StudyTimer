#include <LiquidCrystal.h> //Till LCD skärmen för att den ska starta korekt

const int rs = 7;
const int en = 6;
const int d4 = 12;
const int d5 = 10;
const int d6 = 9;
const int d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//Initiering och skapandet av "tiden"
long hour = 0, minute = 30, second = 0;
long count_time = (hour*3600) + (minute * 60) + second;

void setup(){
  lcd.begin(16, 2);
  lcd.setCursor(1, 0); //Vart på LCD skärmen texten kommer att komma upp
  lcd.print("TIME TO STUDY!");
  lcd.setCursor(4, 0);
}

void loop(){

  long countdowntime = count_time - (millis() / 1000);
  
  if(countdowntime >= 0){
    //I dessa if-satser räknas tiden ner och blir til 00 på skärmen när klart
    long time_hour = countdowntime / 3600;
    long time_minute = ((countdowntime / 60)%60);
    long time_sec = countdowntime % 60;
    lcd.setCursor(4, 1);

    if(time_hour < 10){
      lcd.print("0");
    }
    lcd.print(time_hour);
    lcd.print(":");
    if(time_minute < 10){
      lcd.print("0");
    }
    lcd.print(time_minute);
    lcd.print(":");
    if(time_sec < 10){
      lcd.print("0");
    }
    lcd.print(time_sec);
  }
  else{ //Efter 30 min påminns den studerande om att ta en paus
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("TIME'S UP!");
    lcd.setCursor(2, 1);
    lcd.print("TAKE A BREAK");
  }
  
  delay(500);
}