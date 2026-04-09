#include "Pacman.h"
#include "Sprites.h"

Pacman::Pacman() : lcd(0x27, 20, 4) {}

void Pacman::setup(){
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, (uint8_t*)PacManOpenRight);
  lcd.createChar(1, (uint8_t*)PacManCloseRight);
  lcd.createChar(2, (uint8_t*)PacManOpenLeft);
  lcd.createChar(3, (uint8_t*)PacManCloseLeft);
  lcd.createChar(4, (uint8_t*)point);
  lcd.createChar(5, (uint8_t*)tail_sprite_Horz);
  lcd.createChar(6, (uint8_t*)tail_sprite_Vert);
  
}

void Pacman::right(){
  int oldX = x;
  int oldY = y;

  x++;
  if (x >= 20) {
    x = 0;
  }

  lcd.setCursor(oldX, oldY);
  lcd.print(" ");

  lcd.setCursor(x, y);
  lcd.write(mouth ? 0 : 1);

  mouth = !mouth;

  delay(100);
}

void Pacman::left(){
  int oldX = x;
  int oldY = y;

  x--;
  if (x < 0) {
    x = 19;
  }

  lcd.setCursor(oldX, oldY);
  lcd.print(" ");

  lcd.setCursor(x, y);
  lcd.write(mouth ? 2 : 3);

  mouth = !mouth;

  delay(100);
}

void Pacman::up(){
  int oldX = x;
  int oldY = y;

  y--;
  if (y < 0) {
    y = 3;
  }

  lcd.setCursor(oldX, oldY);
  lcd.print(" ");

  lcd.setCursor(x, y);
  lcd.write(mouth ? 0 : 1);

  mouth = !mouth;

  delay(100);
}

void Pacman::down(){
  int oldX = x;
  int oldY = y;

  y++;
  if (y > 3) {
    y = 0;
  }

  lcd.setCursor(oldX, oldY);
  lcd.print(" ");

  lcd.setCursor(x, y);
  lcd.write(mouth ? 0 : 1);

  mouth = !mouth;

  delay(100);
}

void Pacman::ran(){
  if ((x == Xr) && (y == Yr)){
    Xr = random(20);
    Yr = random(4);

    lcd.setCursor(Xr, Yr);
    lcd.write(4);
    value++;
  }
}

void Pacman::tail_Horz(){
  if (value % 2 == 0){
    
  }
}