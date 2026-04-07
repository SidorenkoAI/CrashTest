#include "Stick.h"

Stick::Stick() {
  pinMode(SEL_PIN, INPUT);

}

int Stick::getValue(){
  if (analogRead(VERT_PIN) > 600)
    return 1;
  else if (analogRead(VERT_PIN) < 400)
    return 3;
  else if (analogRead(HORZ_PIN) < 400)
    return 2;
  else if (analogRead(HORZ_PIN) > 600)
    return 4;
  else
    return 0;
}