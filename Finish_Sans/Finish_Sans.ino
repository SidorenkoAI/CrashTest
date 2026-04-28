#include <GTimer.h>

#define BUTTON_PIN 2
#define PIR_PIN 3
#define SVET_PIN 4
#define BUZZER_PIN 5
#define PHOTO_APIN A0
const float GAMMA = 0.7;
const float RL10 = 50;


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(SVET_PIN, OUTPUT);
}

uint32_t t, handT;

void loop() {
  static uint32_t tmr;

  int analogValue = analogRead(PHOTO_APIN);
  
  int PIR = digitalRead(PIR_PIN);
  int BUTTON = digitalRead(BUTTON_PIN);
 

// Первая задача

  static bool hand = false;
  if (BUTTON){
    digitalWrite(SVET_PIN, HIGH);
    hand = true;
    handT = millis();
  }
if (hand)
  if (millis() - handT > 30000){
    digitalWrite(SVET_PIN, LOW);
    hand = false;
  }

 
 
  if (PIR == 1){
    digitalWrite(SVET_PIN, HIGH);
    t = millis();
  }
  if (!hand and !PIR){
    if (millis() - t > 5000){
      digitalWrite(SVET_PIN, LOW);
    
    }
        
    
  }

  
}