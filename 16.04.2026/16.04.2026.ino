#include <Adafruit_NeoPixel.h>
#include "Stick.h"

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  7

#define MATRIX_PIN 9
#define ROWS 20
#define COLS 20
#define NUM_PIXELS (ROWS * COLS)

Stick stick;

Adafruit_NeoPixel matrix(NUM_PIXELS, MATRIX_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  Serial.begin(9600);
}

void loop() {
  static int a = 0;

  switch (stick.getValue()){
    case 1: //Up
      a -= 20;
      break;
    case 2: //Right
      a++;
      break;
    case 3: //Down
      a += 20;
      break;
    case 4: //Left
      a--;
      break;
    default:
      break;
  }

  if (a >= 400)
    a = a % 100;
  else if (a <= -1)
    a = a + 400;
  else{
    a = a;
  }

  Serial.println(a);
  for (int i = 0; i < NUM_PIXELS; i++){
      matrix.setPixelColor(i, matrix.Color(0, 0, 150));
  }
  matrix.setPixelColor(a, matrix.Color(255, 127, 0));
  matrix.show();

  delay(10);
}