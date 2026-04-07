#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  7

#pragma once
#include <Arduino.h> 

class Stick{

public:
  Stick();
  int getValue();
};