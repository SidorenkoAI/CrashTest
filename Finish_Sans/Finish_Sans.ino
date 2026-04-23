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

void loop() {
  int analogValue = analogRead(PHOTO_APIN);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  Serial.println(lux);

}
