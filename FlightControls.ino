#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "graphics.h"

#include <Servo.h>

Servo aileron;
Servo elevator;

#define OLED_RESET 4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

const byte pot_pin = A0;

const int downtrimpin = 2; 
int downtrim = 0;   

const int uptrimpin = 8; 
int uptrim = 0;  

int pot;

float pitchtrim = 0.0;

void setup() {
  pinMode(downtrimpin, INPUT);
  pinMode(uptrimpin, INPUT);
  Wire.begin();
  aileron.attach(3);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //or 0x3D
  display.clearDisplay(); //for Clearing the display
  display.drawBitmap(0, 0, background, 128, 64, WHITE);
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.display();
}

void loop() {
  uptrim = digitalRead(uptrimpin);
  downtrim = digitalRead(downtrimpin);
  pot = analogRead(pot_pin);
  int aileronpot = map(pot, 0, 1023, 0, 180);
  int leftindy = map(pot, 0, 1023, 17, 48);
  int rightindy = map(pot, 0, 1023, 47, 16);
  aileron.write(aileronpot);
  delay(1);
  display.clearDisplay(); //for Clearing the display
  display.drawBitmap(0, 0, background, 128, 64, WHITE);
  display.drawBitmap(23, leftindy, leftind, 6, 5, WHITE);
  display.drawBitmap(99, rightindy, rightind, 6, 5, WHITE);
  display.setCursor(53, 38); 
  display.println(pitchtrim);
  display.display();
  
  if (uptrim == HIGH) {
    // go right
    pitchtrim = pitchtrim + 0.01;
    delay(30);
  }
  if (downtrim == HIGH) {
    // go right
    pitchtrim = pitchtrim - 0.01;
    delay(30);
  }
} 
