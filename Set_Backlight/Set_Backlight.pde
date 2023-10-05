#include <Wire.h>

#include "LCD16x2.h"


#define  ADDRESS  0x30
#define  SDA  19
#define  SCL  20

LCD16x2 lcd(ADDRESS, SDA, SCL);

const int analog_pin = 15;  // A0

void setup(){
  pinMode(analog_pin, INPUT);
}
void loop(){
  
  int value = analogRead(analog_pin);
  map(value, 0, 1023, 0, 255);
  lcd.lcdSetBacklight(value);
  delay(100);  
  
}
