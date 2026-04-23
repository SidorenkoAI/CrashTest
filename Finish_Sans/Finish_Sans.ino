#include <GTimer.h>

#define BUTTON_PIN 2
#define PIR_PIN 3
#define SVET_PIN 4
#define BUZZER_PIN 5
#define PHOTO_APIN A0
const float GAMMA = 0.7;
const float RL10 = 50;


void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(SVET_PIN, OUTPUT);
}

void loop() {
  static uint32_t tmr;

  int analogValue = analogRead(PHOTO_APIN);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  int PIR = digitalRead(PIR_PIN);
  int BUTTON = digitalRead(BUTTON_PIN);

  // Первая задача
  if (PIR == 1){
    digitalWrite(SVET_PIN, HIGH);
    EVERY_S(10) {
      digitalWrite(SVET_PIN, LOW);
    }
  }

  if (BUTTON == 1){
    digitalWrite(SVET_PIN, HIGH);
    EVERY_MS(30000) {
      digitalWrite(SVET_PIN, LOW);
    }
  }
}
