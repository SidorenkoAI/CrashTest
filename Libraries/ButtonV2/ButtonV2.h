#include <Arduino.h>

class Button{
  int pin;
  int counter;
  int longcounter;
public:
  Button();
  Button(int p);
  void pressed();
  int getCounter();
  void ResetCounter();
  int getLongCounter();
  void ResetLongCounter();
};