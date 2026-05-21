#pragma once
#include <Arduino.h>

class Encoder{
 int But,RotRight,RotLeft;
 int timer;
 bool prev; 
 int Rotatecounter; 
 public:
 Encoder(int EncoderButton, int RotateRight, int RotateLeft);
 int pollEnc();
 int EncButton();
};