// Пин для считывания сигнала
const int signalPin = 8;

// Переменные для измерения времени
unsigned long startTime = 0;   // время начала импульса
bool isMeasuring = false;      // флаг: идёт ли измерение

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Настройка пина на вход
  pinMode(signalPin, INPUT);
}

void loop() {
  // Считываем текущее состояние пина
  int currentState = digitalRead(signalPin);

  // Если на пине HIGH и измерение ещё не начато – запускаем таймер
  if (currentState == HIGH && !isMeasuring) {
    isMeasuring = true;
    startTime = millis();        // запоминаем момент начала импульса
  }

  // Если на пине LOW и измерение идёт – заканчиваем, выводим результат
  if (currentState == LOW && isMeasuring) {
    unsigned long duration = millis() - startTime;   // вычисляем длительность
    Serial.print("Длительность импульса: ");
    Serial.print(duration);
    Serial.println(" мс");
    isMeasuring = false;         // сбрасываем флаг (таймер обнулён)
  }
}
