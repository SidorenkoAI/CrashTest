#include <Adafruit_NeoPixel.h>
#include "Stick.h"

#define MATRIX_PIN 2
#define ROWS 20
#define COLS 20
#define NUM_PIXELS (ROWS * COLS)

Adafruit_NeoPixel matrix(NUM_PIXELS, MATRIX_PIN, NEO_GRB + NEO_KHZ800);
Stick stick;
void setup() {
  matrix.begin();
  
  Serial.begin(9600);
}

void loop() {
  static int x = 1;
  static int y = 1;
  int dot = (y * ROWS + x); 
  
  Serial.print("x = ");
  Serial.print(x);
  Serial.print("  y = ");
  Serial.print(y);
  Serial.print("  dot = ");
  Serial.println(dot);
  
  for (int i = 0; i < NUM_PIXELS; i++) {
    if (i == dot)
      matrix.setPixelColor(i, matrix.Color(255, 127, 0)); 
    else
      matrix.setPixelColor(i, matrix.Color(0, 0, 150)); 
  }
  matrix.show();
  
  
  if (stick.getValue() == 1 and y != 0)
    y--;
  else if (stick.getValue() == 2 and x != 19)
    x++;
  else if (stick.getValue() == 3 and y != 19)
    y++;
  else if (stick.getValue() == 4 and x != 0)
    x--;
  
  dot = (y * ROWS + x);
  matrix.show();
  delay(10);
}
