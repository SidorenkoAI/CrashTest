#include <Adafruit_NeoPixel.h>
#include "Stick.h"

#define MATRIX_PIN 2
#define ROWS 20
#define COLS 20
#define NUM_PIXELS (ROWS * COLS)

Adafruit_NeoPixel matrix(NUM_PIXELS, MATRIX_PIN, NEO_GRB + NEO_KHZ800);
Stick st;
void setup() {
  matrix.begin();
  
  Serial.begin(9600);
}

void loop() {
  Serial.println(st.getValue());
  int dot = 150;
  for (int i = 0; i < NUM_PIXELS; i++) {
    if (i == dot)
      matrix.setPixelColor(i, matrix.Color(255, 127, 0)); 
    else
      matrix.setPixelColor(i, matrix.Color(0, 0, 150)); 
  }
  matrix.show();
  delay(10);
}