
#include <Encoder.h> 

  Encoder::Encoder(int EncoderButton, int RotateRight, int RotateLeft){
  Rotatecounter = 0; 
  But=EncoderButton;
  RotRight=RotateRight;
  RotLeft=RotateLeft;
  pinMode(But, INPUT_PULLUP);
  pinMode(RotRight, INPUT_PULLUP);
  pinMode(RotLeft, INPUT_PULLUP);
  prev = digitalRead(RotRight);
  }
 int Encoder::pollEnc() {
  bool Right=digitalRead(RotRight);
  bool Left=digitalRead(RotLeft);
    if (prev != Right) {                    
        bool dir = Right ^ Left; //  побитно сравнивает и выводит 1 если есть отличия           
        if (dir) {
            Rotatecounter -= 10;             
        } else {
            Rotatecounter += 10;             
        }
        Rotatecounter = constrain(Rotatecounter, 0, 255); // не позволяет быть значениям Rotatecounter < 0 и Rotatecounter > 255
        prev = Right;  
        return Rotatecounter;                   
    }
    
  }
 int Encoder::EncButton(){
  static bool pState = false;
  bool state = !digitalRead(But);
  
  if (pState != state && millis() - timer >= 50) {
    pState = state;
    timer = millis();
    
    if (state == LOW) {  // Кнопка нажата (INPUT_PULLUP - LOW при нажатии)
      return true;
    }
  }
  return false;
}
