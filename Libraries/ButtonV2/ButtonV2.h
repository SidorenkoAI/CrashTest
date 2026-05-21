#pragma once
#include <Arduino.h>

class Button{
  int pin;
  int counter;
  int longcounter;
public:
  Button();
  Button(int p);
  int pressed();
  int getCounter();
  void ResetCounter();
  int getLongCounter();
  void ResetLongCounter();
};