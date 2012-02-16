#include "LiquidCrystalKana.h"

LiquidCrystalKana::LiquidCrystalKana(uint8_t rs, uint8_t rw,
uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
LiquidCrystal(rs, rw, d0, d1, d2, d3, d4, d5, d6, d7){
  initializer();
}
LiquidCrystalKana::LiquidCrystalKana(uint8_t rs, uint8_t rw, uint8_t enable,
uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7){
  initializer();
}
LiquidCrystalKana::LiquidCrystalKana(uint8_t rs, uint8_t rw, uint8_t enable,
uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
LiquidCrystal(rs, rw, enable, d0, d1, d2, d3){
  initializer();
}
LiquidCrystalKana::LiquidCrystalKana(uint8_t rs, uint8_t rw,
uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
LiquidCrystal(rs, rw, d0, d1, d2, d3){
  initializer();
}

void LiquidCrystalKana::initializer(){
  _last = 0;
}

// UTF8→SJISの変換部分
inline size_t LiquidCrystalKana::write(uint8_t value){
  // 半角カナの開始を検出
  if(value==0xEF)
    _last = value;
  // 半角カナ2バイト目をストア
  else if(_last==0xEF)
    _last = value;
  else{
    if(_last==0xBE) // タ以降は2バイトめが0xBEになり、3バイト目がsjisと0x40ズレるので修正
      value += 0x40;  
    LiquidCrystal::write(value);
    _last=0;
  }
  #if ARDUINO >= 100
  return 1;
  #endif
}