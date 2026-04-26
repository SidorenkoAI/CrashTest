#include <RGBrejim.h>

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
  analogWrite(pinR,Rlight);
  analogWrite(pinG,Glight);
  analogWrite(pinB,Blight);
    }
    break;
    case 1:{
      
      analogWrite(pinR,255);
      analogWrite(pinG,0);
      analogWrite(pinB,128);
    }
    break;
    case 2:{
     
      analogWrite(pinR,255);
      analogWrite(pinG,35);
      analogWrite(pinB,255);
    }
    break;
    case 3:{
     
      analogWrite(pinR,0);
      analogWrite(pinG,255);
      analogWrite(pinB,255);
    }
    break;
    case 4:{
     
  digitalWrite(pinR,LOW);
  digitalWrite(pinG,LOW);
  digitalWrite(pinB,LOW);
    }
    break;
    case 5:{
    but.ResetCounter();
    }break;
  }
}
int RGBrejim::RGBoff(){
  digitalWrite(pinR,LOW);
  digitalWrite(pinG,LOW);
  digitalWrite(pinB,LOW);
}
int RGBrejim::getLong(){
  return but.getLongCounter();
}
void RGBrejim::ResetLong(){
  but.getLongCounter();
}
