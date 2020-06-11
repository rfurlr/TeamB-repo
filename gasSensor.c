#include <LiquidCrystal.h>

int const PINO_SGAS = A1;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd1(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd2(12, 10, 5, 4, 3, 2);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
  // Print a message to the LCD.
  lcd1.print("Cabin Control");
  lcd2.print("Team B");
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  lcd1.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd1.print(millis() / 1000);
  
  int value = analogRead(PINO_SGAS);
  value = map(value, 300, 750, 0, 100);
  lcd2.setCursor(0, 1);
  lcd2.print(value);
}
 
