#include "RGBrejim.h"

  RGBrejim::RGBrejim(int Buttonpin,int Redpin,int GreenPin,int Bluepin){
  pinR=Redpin;
  pinG=GreenPin;
  pinB=Bluepin;
  but=Buttonpin;
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  }
int RGBrejim::RGBsvet(int Rlight, int Glight, int Blight){
  but.pressed();
  switch(but.getCounter()){
    case 0:{   
   RGBoff();
    }
    break;
    case 1:{
      analogWrite(pinR,Rlight);
      analogWrite(pinG,Glight);
      analogWrite(pinB,Blight);
    }
    break;
    case 2:{
      analogWrite(pinR,105);
      analogWrite(pinG,255);
      analogWrite(pinB,0);
    }
    break;
    case 3:{
    but.ResetCounter();
    }break;
  }
}
int RGBrejim::RGBoff(){
  digitalWrite(pinR,HIGH);
  digitalWrite(pinG,HIGH);
  digitalWrite(pinB,HIGH);
}
int RGBrejim::getLong(){
  return but.getLongCounter();
}
void RGBrejim::ResetLong(){
  but.ResetLongCounter();
}