//
// mouse_mover.ino
// Naookie Sato
//
// Created by Naookie Sato on 07/25/2019
// Copyright © 2018 Naookie Sato. All rights reserved.
//

#include "Keyboard.h"
#include "Mouse.h"

int button_pin = 8;

void dont_move() {
    delay(1000);
    while(true) {
        if (digitalRead(button_pin) == HIGH) {
          break;
        }
        delay(100);
    }
}

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  Serial.begin(9600);

  // Begining the Keyboard stream
  Keyboard.begin();

  // Begin the mouse
  Mouse.begin();

  // micro ducky mouse test
  // By Naookie Sato
  delay(1000);
  // pushbutton setup, check for new script
  pinMode(button_pin, INPUT);

  randomSeed(analogRead(0));
}

void loop() {
    if(digitalRead(button_pin) == HIGH) {
      dont_move();
      delay(1000);
    }
    int r1 = random(10);
    if (!r1) {
      int movex = random(100);
      int movey = random(100);
      int mult = random(4);
      switch (mult) {
        case 1:
          movex *= -1;
          break;
        case 2:
          movex *= -1;
        case 3:
          movey *= -1;
          break;
      }
      Mouse.move(movex, movey);
    }
    delay(50);
    //Mouse.move(0, 100);
    //delay(500);
    //Mouse.move(-100, 0);
    //delay(500);
    //Mouse.move(0, -100);
    //delay(500);
}
