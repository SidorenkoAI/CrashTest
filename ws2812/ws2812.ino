#include <Adafruit_NeoPixel.h>

#define MATRIX_PIN 2
#define ROWS 20
#define COLS 20
#define NUM_PIXELS (ROWS * COLS)

Adafruit_NeoPixel matrix(NUM_PIXELS, MATRIX_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  for (int i = 0; i < NUM_PIXELS; i++) {
    matrix.setPixelColor(i, matrix.Color(0, 0, 150)); // Blue
  }
  matrix.show();
}

void loop() {
  delay(10);
}