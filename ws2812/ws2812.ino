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
  
  int dot = 150;
  int x = (dot % ROWS);
  int y = (dot / ROWS);
  for (int i = 0; i < NUM_PIXELS; i++) {
    if (i == dot)
      matrix.setPixelColor(i, matrix.Color(255, 127, 0)); 
    else
      matrix.setPixelColor(i, matrix.Color(0, 0, 150)); 
  }
  matrix.show();
  
  
  if (stick.getValue() == 1)
    dot = (dot + 20);
  else if (stick.getValue() == 2)
    dot++;
  else if (stick.getValue() == 3)
    dot = (dot - 20);
  else if (stick.getValue() == 4)
    dot--;
  
  if (x > 20)
   dot--; 
  if (y > 20)
   dot = (dot - 20);
  
  matrix.show();
  delay(10);
}
