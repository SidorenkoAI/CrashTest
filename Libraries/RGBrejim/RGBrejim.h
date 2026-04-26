#include <Arduino.h>
#include <ButtonV2.h>
class RGBrejim{
  int pinR,pinG,pinB;
  Button but;
  public:
  RGBrejim(int Buttonpin,int Redpin,int GreenPin,int Bluepin);
int RGBsvet(int Rlight, int Glight, int Blight); 
int RGBoff();
int getLong();
void ResetLong();
};