#include<LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Sets the input for Digitial pins
int sec=00; //Initial values for the mission clock
int min=00;
int hr=00;

void setup() {
lcd.begin(16,2);
lcd.setCursor(2,1);
lcd.print("MISSION TIMER");
delay(1000);
lcd.setCursor(0,0);
lcd.print("IGNITION IN 5");
delay(1000);
lcd.clear();
lcd.print("IGNITION IN 4");
delay(1000);
lcd.clear();
lcd.print("IGNITION IN 3");
delay(1000);
lcd.clear();
lcd.print("IGNITION IN 2");
delay(1000);
lcd.clear();
lcd.print("IGNITION IN 1");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
}

void loop() {
//Prints out the 
lcd.setCursor(2,2);
lcd.print("TIME ELAPSE T+:");
lcd.setCursor(4,0);
lcd.print(hr);
lcd.setCursor(6,0);
lcd.print(":");
lcd.print(min);
lcd.setCursor(9,0);
lcd.print(":");
lcd.print(sec);
sec=sec+1;
delay(1000); //This delay equats to 1 second. This updates the '
  //Value of second with the delay
  
//If statements for updating minutes and hours
if(sec == 60){
  sec=00;
  min=min+1; 
}else;
if(min == 60){
  min=0;
  hr=hr+1;
}else;

lcd.clear();
}
