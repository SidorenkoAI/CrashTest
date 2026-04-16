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
  
  static int dot = 150;
  int x = (dot % ROWS);
  int y = (dot / ROWS);
  for (int i = 0; i < NUM_PIXELS; i++) {
    if (i == dot)
      matrix.setPixelColor(i, matrix.Color(255, 127, 0)); 
    else
      matrix.setPixelColor(i, matrix.Color(0, 0, 150)); 
  }
  matrix.show();
  
  
  if (stick.getValue() == 1) and (dot != 20)
    dot = (dot + 20);
  else if (stick.getValue() == 2) and (dot != 20)
    dot++;
  else if (stick.getValue() == 3) and (dot != 0)
    dot = (dot - 20);
  else if (stick.getValue() == 4) and (dot != 0)
    dot--;
  
  
  matrix.show();
  delay(10);
}
