#include <Arduino.h>

class Button{
  int pin;
  int counter;
public:
  Button();
  Button(int p);
  bool pressed();
  int getCounter();
  void Reset();
};