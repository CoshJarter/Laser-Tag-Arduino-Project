#include <LiquidCrystal.h> //Import the LCD library
//Include^
//Init
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); /*Initialize the LCD and
                                        tell it which pins is
                                        to be used for communicating*/

//Global Var
//#define contra 9 //Define the pin that controls the contrast of the screen
//#define bri 10 //Define the pin the controls the brightness of the screen
int lives = 25;
int ammo = 50;
//Both pins are PWM so you can analogWrite to them and have them output a variable value


void setup() {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // put your setup code here, to run once:
  lcd.begin(16, 2); //Tell the LCD that it is a 16x2 LCD
  //pinMode(contra, OUTPUT); //set pin 9 to OUTPUT
  //pinMode(bri, OUTPUT); //Set pin 10 to OUTPUT
  //pinMode-ing OUTPUT makes the specified pin output power
  //digitalWrite(contra, LOW); /*outputs no power to the contrast pin.
  //analogWrite(bri, 255); //Outputs full power to the screen brightness LED
  lcd.setCursor(0, 0);
  lcd.print("Lives: ");
  lcd.print(lives); 
  lcd.setCursor(0, 1); 
  lcd.print("Ammo: ");
  lcd.print(ammo);
  delay(3000); //Wait 3 seconds
}//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void loop() {//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // put your main code here, to run repeatedly:

  for (int ammo = 50; ammo > -1; ammo--) { //For loop. Repeating 50 times
    delay(1000); //Slight delay before prining new ammo amount
    lcd.setCursor(6, 1);
    if (ammo < 10)
    {lcd.print(0);
    lcd.print(ammo);
    }
    else 
    {lcd.print(ammo);
    }
  }
  delay(1000);
  for (int lives = 25; lives > -1; lives--) { //For loop. Repeating 25 times
    delay(1000); //Slight delay before prining new life amount
    lcd.setCursor(7, 0);
    if (lives < 10)
    {lcd.print(0);
    lcd.print(lives);
    }
    else 
    {lcd.print(lives);
    }
  }
}

