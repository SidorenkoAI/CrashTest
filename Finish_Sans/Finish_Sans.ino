#define BUTTON_PIN 2
#define PIR_PIN 3
#define SVET_PIN 4
#define BUZZER_PIN 5
#define PHOTO_APIN A0

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(SVET_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(PIR_PIN)){
    digitalWrite(SVET_PIN, HIGH);
  }
  else
    digitalWrite(SVET_PIN, LOW);
  
  

}
