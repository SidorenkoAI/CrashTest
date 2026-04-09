#include <LiquidCrystal_I2C.h>
#include "Sprites.h"
//#include "Mechanic.h"
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
  switch (stick.getValue()){
    case 1:
      pack.up();
      break;
    case 2:
      pack.right();
      break;
    case 3:
      pack.down();
      break;
    case 4:
      pack.left();
      break;
    default:
      break;
  }
  pack.ran();
}
