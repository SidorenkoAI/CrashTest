#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  7

#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>  
#include "Pacman.h"

class Basic{
  LiquidCrystal_I2C *_lcd;
  bool mouth = false;
  int x = 0;
  int y = 0;
public:
  Basic(LiquidCrystal_I2C &lcd);
  void setup();
  void animation();
};