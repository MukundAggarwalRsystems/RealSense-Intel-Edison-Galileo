#include<string.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR = 0;
int colorG = 0;
int colorB = 0;
const int ledPin = 13;     // the number of the pushbutton pin
const int aled = 3;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  if (Serial.available()>0) 
  /* read the most recent byte */
  {
    int tmp = Serial.parseInt();
    colorR = 0;
    colorG = 255;
    colorB = 0;
    lcd.setRGB(colorR, colorG, colorB);
    lcd.setCursor(0, 1);
    lcd.clear();
    lcd.print(tmp);
    tmp = map(tmp, 0, 100, 0, 255);
    analogWrite(3, tmp);
    digitalWrite(4, LOW);
    analogWrite(9, tmp);
    digitalWrite(8, LOW);
    
    
    if(tmp == 0)
    {
      // turn LED off:
      digitalWrite(ledPin, LOW);
    }
    else if (tmp >= 1)
    {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
    }
  }
}
