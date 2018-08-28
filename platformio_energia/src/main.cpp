/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Energia.h>

int pushButton = 5;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600); // msp430g2231 must use 4800
}

void loop()
{

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect


  // turn the LED on (HIGH is the voltage level)
  digitalWrite(RED_LED, HIGH);
  analogWrite(GREEN_LED, brightness);
  // wait 
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(RED_LED, LOW);
  int state = analogRead(GREEN_LED);
  Serial.println(state);
   // wait
  delay(30);
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);

}