/* Vibration switch module (KY-002) [S039] : http://rdiot.tistory.com/89 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
int pin = 2;
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(pin,INPUT);
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S039:VibrationSwitch");
 
  int vibration = digitalRead(pin);
 
  lcd.setCursor(0,1);
  lcd.print("digital=" + (String)vibration + "  ");
 
  if(vibration == LOW)
  {
    lcd.setCursor(0,2);
    lcd.print("vibration=detected");
    delay(100);
  }
  else{
    lcd.setCursor(0,2);
    lcd.print("vibration=NONE    ");
  }
 
}
