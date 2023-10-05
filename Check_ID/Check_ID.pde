#include "LCD16x2.h"

#define  ADDRESS  0x30
#define  SDA  19
#define  SCL  20

LCD16x2 lcd(ADDRESS, SDA, SCL);

void setup(){
  SerialUSB.begin();
}
void loop(){
  SerialUSB.print("BOARD ID: 0x");
  SerialUSB.println(lcd.getID(), HEX);
  
  SerialUSB.print("FIRMWARE: 0x");
  SerialUSB.println(lcd.getFirmwareVersion(), HEX);
  
  delay (1000);
}
