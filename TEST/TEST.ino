//Includes the Olimex LCD Shields Library
#include <LCD16x2.h>

//Include the required "Wire" Library
#include <Wire.h>

//Defines the "lcd" term as the LCD 16x2 Shield
LCD16x2 lcd;

//Assigns buttons to a value (Unknown)
//unsigned char buttons = 0xFF;
int buttons;
void setup() {

//Delay changes the LCD startup time
  delay(1000);

//Initializes the Wire Library
  Wire.begin();

//Sets the bitrate that the Arduino communicates with the PC at.
  Serial.begin(9600);
  
//Turns on the backlight to full brightness
//Brightness is the values 0 to 255, 0 being off and 255 being fully bright
  lcd.lcdSetBlacklight(255);
  
// Clears the LCD
  lcd.lcdClear();

//Welcome Message

    //At LCD location (1,1) Write "Welcome to ASU's"
      lcd.lcdGoToXY(1,1);
      lcd.lcdWrite("Welcome to ASU's");
      
    //At LCD location (2,1) Write "STEM Bingo Game!"
      lcd.lcdGoToXY(1,2);
      lcd.lcdWrite("STEM Bingo Game!");
    //Hold (Delay) message for set interval
      delay(5000);

// Clears the LCD
  lcd.lcdClear();


  //Main Menu
    //At LCD location (7,1) Write "Menu"
      lcd.lcdGoToXY(7,1);
      lcd.lcdWrite("Menu");

    //At LCD location (1,2) Write "S"
      lcd.lcdGoToXY(1,2);
      lcd.lcdWrite("S");

    //At LCD location (6,2) Write "T"
      lcd.lcdGoToXY(6,2);
      lcd.lcdWrite("T");

    //At LCD location (11,2) Write "E"
      lcd.lcdGoToXY(11,2);
      lcd.lcdWrite("E");

    //At LCD location (16,2) Write "M"
      lcd.lcdGoToXY(16,2);
      lcd.lcdWrite("M");
}

void loop() {
  // put your main code here, to run repeatedly:
        buttons = lcd.readButtons();
//Go to LCD location (1,1)      
  lcd.lcdGoToXY(1,1);
  //If readButtons shows that the button "1" is NOT pressed write "0" at above location
  if(buttons & 0x01)  
    lcd.lcdWrite("0");
  //If readButtons shows that the button "1" IS pressed
  else
  {
    lcd.lcdClear();
    delay(100);
    lcd.lcdGoToXY(6,1);
    lcd.lcdWrite("Science?");
    lcd.lcdGoToXY(1,2);
    lcd.lcdWrite("Yes");
    lcd.lcdGoToXY(15,2);
    lcd.lcdWrite("No");
    delay(1000);
    buttons = lcd.readButtons();
    lcd.lcdGoToXY(2,1);
    if(buttons & 0x01)
      lcd.lcdWrite("0");
    else
    {
      lcd.lcdClear();
      lcd.lcdWrite("YAY!");
      delay(3000);
    }
  }
}
