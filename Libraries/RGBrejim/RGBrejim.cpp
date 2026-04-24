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
int RGBrejim::RGBsvet(){
  but.pressed();
  switch(but.getCounter()){
    case 0:{
      
      digitalWrite(pinR,LOW);
      digitalWrite(pinG,LOW);
      digitalWrite(pinB,LOW);
    }
    break;
    case 1:{
      
      digitalWrite(pinR,LOW);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinB,LOW);
    }
    break;
    case 2:{
     
      digitalWrite(pinR,HIGH);
      digitalWrite(pinG,LOW);
      digitalWrite(pinB,LOW);
    }
    break;
    case 3:{
     
      digitalWrite(pinR,LOW);
      digitalWrite(pinG,LOW);
      digitalWrite(pinB,HIGH);
    }
    break;
    case 4:{
     
      digitalWrite(pinR,HIGH);
      digitalWrite(pinG,HIGH);
      digitalWrite(pinB,HIGH);
    }
    break;
    case 5:{
    but.Reset();
    }break;
  }
}
int RGBrejim::RGBoff(){
  digitalWrite(pinR,LOW);
  digitalWrite(pinG,LOW);
  digitalWrite(pinB,LOW);
}
