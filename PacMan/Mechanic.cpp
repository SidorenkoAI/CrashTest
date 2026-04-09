#include "Mechanic.h"
#include "Sprites.h"

Basic::Basic(LiquidCrystal_I2C &lcd) {
  *_lcd = lcd;
}

void Basic::setup(){
  _lcd->init();
  _lcd->backlight();
  
}

void Basic::animation(){
  int oldX = x;
  int oldY = y;

  x++;
  if (x >= 20) {
    x = 0;
    y++;
  }

  if (y >= 4) {
    y = 0;
  }

  _lcd->setCursor(oldX, oldY);
  _lcd->print(" ");

  _lcd->setCursor(x, y);
  _lcd->write(mouth ? 0 : 1);

  mouth = !mouth;
}