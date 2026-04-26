#include <RGBrejim.h>
int movement=8;
int fotores=6;
RGBrejim RGB(7,9,10,11);
int pot=A0;
unsigned long Timer = 0;
bool On=false;
bool Speedmovement=false;
bool Actimer=false;
int Rpot;
int Gpot;
int Bpot;
void setup() {
 Serial.begin(9600);
}
void LightPot(){
  int pokazpot=analogRead(pot);
int  LightSvet=map(pokazpot,0,1023,0,255);
  switch(RGB.getLong()){
 //   case 0:{
 //   Rpot=10;
  //  Gpot=10;
  //  Bpot=10;
   // break;
   // }
    case 1:{
      Rpot=LightSvet;
      break;
    }
    case 2:{
      Gpot=LightSvet;
      break;
    }
    case 3:{
      Bpot=LightSvet;
      break;
    }
    case 4:{
      RGB.ResetLong();
      break;
    }
  }
}
void loop() {
bool  fotoresPokas=digitalRead(fotores);
  //Serial.print(fotoresPokas);
  if(!Actimer){
  if (fotoresPokas==true){
    On=true;
  } else {
    On=false;
  }}
Speedmovement=digitalRead(movement);
  if (Speedmovement==true){
    Actimer=true;
    Timer=millis();
  }
  if(On==true){
 LightPot();
 RGB.RGBsvet(Rpot,Gpot,Bpot);
  } else {
    RGB.RGBoff();
  }
  if(Actimer){
  if(millis()-Timer>=30000){
     On=false;
     Actimer=false;
     } else {
      On=true; 
     }
  } 
  Serial.print(analogRead(pot));
}
