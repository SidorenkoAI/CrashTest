#include "RGBrejim.h"   // Библиотека для управления RGB-светодиодом (скорее всего, самодельная)
#include <EEPROM.h>     // Библиотека для работы с энергонезависимой памятью
#include "ButtonV2.h"

// Адреса в EEPROM для хранения значений яркости каждого канала
const int EEPROM_ADDR_R = 0;   // адрес для красного
const int EEPROM_ADDR_G = 1;   // адрес для зелёного
const int EEPROM_ADDR_B = 2;   // адрес для синего

// Пины
int movement = 8;      // вход от датчика движения 
int fotores = 6;       // вход от модуля датчика освещённости 
RGBrejim RGB(7, 9, 10, 11);  // объект RGB:Button,Redpin,Greenpin,Bluepin, (общий анод)
int pot = A0;          // потенциометр для управления яркостью выбранного канала

// Переменные таймера
unsigned long Timer = 0;   // метка времени для таймера 30 секунд
bool On = false;           // флаг – включена ли подсветка в данный момент
bool Speedmovement = false; // флаг – сработал ли датчик движения 
bool Actimer = false;      // флаг – активен ли таймер после срабатывания движения

// Текущие значения яркости (0..255)
int Rpot;
int Gpot;
int Bpot;

void setup() {
  Serial.begin(9600);   // для отладки 

  // При запуске считываем последние сохранённые значения яркости из EEPROM
  Rpot = EEPROM.read(EEPROM_ADDR_R);
  Gpot = EEPROM.read(EEPROM_ADDR_G);
  Bpot = EEPROM.read(EEPROM_ADDR_B);
}

// Функция, которая вызывается, когда нужно настроить яркость текущего канала
void LightPot() {
  int pokazpot = analogRead(pot);                     // читаем потенциометр (0..1023)
  int LightSvet = map(pokazpot, 0, 1023, 0, 255);     // преобразуем в диапазон 0..255

  // RGB.getLong() – возвращает сколько раз кнопка удержена
  switch (RGB.getLong()) {
    case 1: {   // настройка красного канала
      if (Rpot != LightSvet) {          // если значение изменилось
        Rpot = LightSvet;               // обновляем переменную
        EEPROM.write(EEPROM_ADDR_R, (byte)Rpot);  // и сохраняем в EEPROM
      }
      break;
    }
    case 2: {   // настройка зелёного канала
      if (Gpot != LightSvet) {
        Gpot = LightSvet;
        EEPROM.write(EEPROM_ADDR_G, (byte)Gpot);
      }
      break;
    }
    case 3: {   // настройка синего канала
      if (Bpot != LightSvet) {
        Bpot = LightSvet;
        EEPROM.write(EEPROM_ADDR_B, (byte)Bpot);
      }
      break;
    }
    case 4: {   // сброс выбора канала (не трогает сохранённые яркости)
      RGB.ResetLong();
      break;
    }
  }
}

Button b(2);
void testButton(){
  
  
  b.pressed();
  Serial.print(b.getLongCounter());
  Serial.print(" ");
  Serial.println(b.getCounter());

}

void loop() {
  testButton();
  
  /*
  
  bool fotoresPokas = digitalRead(fotores);   // читаем фоторезистор 

  // Если таймер после движения не активен, управляем On только по фоторезистору
  if (!Actimer) {
    if (fotoresPokas == true) {
      On = true;     // темно – включаем подсветку
    } else {
      On = false;    // светло – выключаем
    }
  }
  
  // Обработка датчика движения
  Speedmovement = digitalRead(movement);
  if (Speedmovement == true) {
    Actimer = true;          // запускаем таймер (подсветка будет гореть принудительно 30 секунд)
    Timer = millis();        // запоминаем момент срабатывания
  }
  
  // Управление RGB-светодиодом
  if (On == true) {
    LightPot();                        // позволяем потенциометру менять яркость текущего канала
    RGB.RGBsvet(Rpot, Gpot, Bpot);     // устанавливаем цвет с сохранёнными/изменёнными значениями
  } else {
    RGB.RGBoff();                      // выключаем светодиод
  }
  
  // Работа таймера после движения: 30 секунд подсветка горит всегда (On = true)
  if (Actimer) {
    if (millis() - Timer >= 30000) {   // прошло 30 секунд?
      On = false;                      // выключаем подсветку
      Actimer = false;                 // выходим из режима таймера
    } else {
      On = true;                       // пока таймер не истёк – подсветка включена
    }
  }
  */
}
