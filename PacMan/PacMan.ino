#include <LiquidCrystal_I2C.h>
#include "Sprites.h"
// #include "Mechanic.h"
#include "Pacman.h"
#include "Stick.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);
Pacman pack;
Stick stick;

void setup() {
  pack.setup();
  Serial.begin(9600);

}

void loop() {
  if (stick.getValue() == 1)
    pack.up();
  else if (stick.getValue() == 2)
    pack.right();
  else if (stick.getValue() == 3)
    pack.down();
  else if (stick.getValue() == 4)
    pack.left();

}
