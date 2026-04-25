#include <Button.h>

  Button::Button(){
    pin = 2;
    counter = 0;
  }

  Button::Button(int p){
    pin = p;
    counter = 0;
  }

  bool Button::pressed(){
      static bool flag = true;
      bool press = false;
      bool but = !digitalRead(pin);
      if(but && flag){
        delay(10);
        if(digitalRead(pin)){
          press = true;
          counter += 1;
          flag = false;
        }
      }
      if(!but && !flag){
        flag = true;
      }
      return press;
  }
  
  int Button::getCounter(){
    return counter;
  }

  void Button::Reset(){
    counter = 0;
  }
  int Longpressed(){
    
  }