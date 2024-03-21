iquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 libraryL works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 


#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float value;
int tmp = A1;
const int hot = 75;
const int cold = 20;

void setup() {
  pinMode(tmp, INPUT);
  pinMode(8, OUTPUT); //blue LED
  pinMode(7, OUTPUT); //yellow LED
  pinMode(6, OUTPUT); //red LED
  Serial.begin(9600);
}

void loop() { 
  value = analogRead(tmp)*0.004882814;
  value = (value - 0.5) * 100.0;
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(value);
  delay(1000);
  lcd.clear();
  
  
  Serial.print("Temp: ");
  Serial.print(value);
  
  if (value < cold) { //cold
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    Serial.println(" It's Cold.");
  }
  else if (value >= hot) { //hot
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    Serial.println(" It's Hot.");
  }
  else { //Normal
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    Serial.println(" It's Normal.");
  }
  delay(10);
}
 
