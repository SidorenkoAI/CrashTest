#include <Arduino.h>
#include <Encoder.h> 
#include <RGBrejim.h>   
#include <EEPROM.h>   
#include <ButtonV2.h>
Encoder Enc(4,2,3);
const int RedRom = 0;   
const int GreenRom = 1;   
const int BlueRom = 2;   
#define VolumeSensor 5
#define movement 8     
#define fotores 6 
Button EncBut(4); 
int LightSvet = 0;  
RGBrejim RGB(7, 9, 10, 11);  
unsigned long Timer = 0; 
int brightness=0; 
int SummMovement=0; 
bool LedOn = false;         
bool Speedmovement = false; 
bool Actimer = false;      
bool VolumeZnach = false;
bool fotoresPokas;
int Rpot;
int Gpot;
int Bpot;

void setup() {
  Serial.begin(9600);  
  Rpot = EEPROM.read(RedRom);
  Gpot = EEPROM.read(GreenRom);
  Bpot = EEPROM.read(BlueRom);
}

void GammaLed() {
  switch (RGB.getLong()) {
    case 1: {         
          Rpot=brightness;      
      break;
    }
    case 2: {  
          Gpot=brightness;    
      break;
    }
    case 3: {           
          Bpot=brightness;   
      break;
    }
    case 4: {   
       EEPROM.write(RedRom, (byte)Rpot); 
       EEPROM.write(GreenRom, (byte)Gpot);
       EEPROM.write(BlueRom, (byte)Bpot);   
       RGB.ResetLong();
      break;
    }
  }
}

void loop() {
Speedmovement = digitalRead(movement);
VolumeZnach=digitalRead(VolumeSensor);
fotoresPokas = digitalRead(fotores);
brightness=Enc.pollEnc();
  if (!Actimer) {
    if (fotoresPokas == true) {
      LedOn = true;    
    } else {
      LedOn = false;   
    }
  }
  if (Speedmovement) {         
   int TimerDrebezg = millis();
   if(millis() - TimerDrebezg > 3000){ //В реальности датчик движения отправляет значение не один раз, а несколько.3000 - задержка между концом движения и прекращением отправки значения 
       SummMovement++;
       TimerDrebezg=0;
      }  
  }  
  if (Speedmovement || VolumeZnach) {
    Actimer = true;         
    Timer = millis();        
  }
  if (LedOn == true) {
    GammaLed();           
    RGB.RGBsvet(Rpot, Gpot, Bpot);     
  } else {
    RGB.RGBoff();                      
  } 
  if (Actimer) {
    if (millis() - Timer > 30000) {   
      LedOn = false;                      
      Actimer = false;                 
    } else {
      LedOn = true;                       
    }
  }
  if(SummMovement>=4){
    LedOn=false;
  Rpot = 0;
  Gpot = 255;
  Bpot = 255;
  int time=millis();
  if(millis()-time==500){
    Rpot = 0;
  Gpot = 255;
  Bpot = 255;
  }
  }
  if (Enc.EncButton()){
  EEPROM.write(RedRom,255);
  EEPROM.write(GreenRom,255);
  EEPROM.write(BlueRom,255);
  Rpot = 255;
  Gpot = 255;
  Bpot = 255;
  }
}
