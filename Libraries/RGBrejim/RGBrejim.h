#include <Arduino.h>
#include <Button.h>
class RGBrejim{
  int pinR,pinG,pinB;
  Button but;
  public:
  RGBrejim(int Buttonpin,int Redpin,int GreenPin,int Bluepin);
int RGBsvet(); 
int RGBoff();
};