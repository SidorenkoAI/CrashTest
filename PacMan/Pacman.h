#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  7

#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>  

class Pacman{
  LiquidCrystal_I2C lcd;
  bool mouth = false;
  int x = 0;
  int y = 0;
  int Xr = 0;
  int Yr = 0;
  int value = 0;
public:
  Pacman();
  void setup();
  void right();
  void left();
  void up();
  void down();
  void ran();
  void tail_Horz();

};