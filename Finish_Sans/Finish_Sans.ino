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

<<<<<<< HEAD
uint32_t t;
uint32_t handT;
static uint32_t time = millis();
static uint32_t Move = 0;
static uint32_t MoveT = 0;
=======
uint32_t t, handT;
>>>>>>> 9080bae0b270883c73ba2442f00b56919463dbc0

void loop() {
  int analogValue = analogRead(PHOTO_APIN);
<<<<<<< HEAD
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  int PIR = digitalRead(PIR_PIN);
  int BUTTON = digitalRead(BUTTON_PIN);
  bool dark = lux < 30;
  static bool flag = false;
  static bool lastPIR = false;
  static bool hand = false;  

// Первая задача
  if (BUTTON) {
    hand = true;
    handT = millis();
  }

  if (hand && millis() - handT >= 30000) {
    hand = false;
  }

  if (!dark) {
    Move = 0;
    MoveT = millis();
=======
  
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
        
    
>>>>>>> 9080bae0b270883c73ba2442f00b56919463dbc0
  }

  
  if (PIR){
    flag = true;
    t = millis();
  }

  if(dark && PIR && !lastPIR){
    Move++;
    Serial.println(Move);

    if (Move == 1){
      MoveT = millis();
    }
  }

  if (flag && !PIR && (millis() - t >= 5000)){
    flag = false;
  }

  if (hand || flag || lux < 30)
    digitalWrite(SVET_PIN, HIGH);
  else
    digitalWrite(SVET_PIN, LOW);


  // Вторая задача
  if (dark && Move > 0 && millis() - MoveT >= 60000){
    if (Move > 5){
      tone(BUZZER_PIN, 261.63, 1000);
      tone(BUZZER_PIN, 293.66, 1000);
      tone(BUZZER_PIN, 329.63, 1000);
      tone(BUZZER_PIN, 261.63, 1000);
      tone(BUZZER_PIN, 293.66, 2000);
      tone(BUZZER_PIN, 261.63, 2000);
    }
    Move = 0;
    time = millis();
  }
  lastPIR = PIR;
}