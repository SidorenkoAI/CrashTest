#include <RGBrejim.h>
int movement=3;
int fotores=5;
RGBrejim RGB(4,10,7,8);
unsigned long Timer = 0;
bool On=false;
bool Speedmovement=false;
bool Actimer=false;
void setup() {
 Serial.begin(9600);
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
 RGB.RGBsvet();
  } else {
    RGB.RGBoff();
  }
  if(Actimer){
  if(millis()-Timer>=30000){
     Serial.println("30 секунд истекло!");
     On=false;
     Actimer=false;
     } else {
      On=true; 
     }
  } 
}
