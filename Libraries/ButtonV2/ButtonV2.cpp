#include <ButtonV2.h>

Button::Button(){
  pin = 2;
  counter = 0;
  longcounter = 0;
  
}

Button::Button(int p){
  pin = p;
  counter = 0;
  longcounter = 0;
  
}

int Button::pressed(){
static bool pState = false;
static bool hold = false;   // флаг удержания
static uint32_t tmr;

bool state = !digitalRead(pin);
if (pState != state && millis() - tmr >= 50) {
  tmr = millis();
  pState = state;
  hold = false;
  if (state) counter+=1;
 }
if (pState && !hold && millis() - tmr >= 500) {
  hold = true;    
  longcounter +=1;
  counter -=1;
 } 
 return state;
}

int Button::getCounter(){
  return counter;
}

void Button::ResetCounter(){
  counter = 0;
}
int Button::getLongCounter(){
  return longcounter;
}
void Button::ResetLongCounter(){
  longcounter = 0;
}