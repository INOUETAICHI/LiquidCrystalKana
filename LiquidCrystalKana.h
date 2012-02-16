/*
  LiquidCrystalKana.h - ArduinoIDEに直接書き込んだ半角カナ(UTF8)をLCDのコード(SJIS)に変換するLiquidCrystalのオーバーライド
  Created by inouetaichi + Fujimoto Naoaki, 2012/2/16
  http://inouetaichi.jp/
  
  Arduino1.0で動作確認しました
  It was tested with arduino1.0
*/

#ifndef LiquidCrystalKana_h
#define LiquidCrystalKana_h

#include "LiquidCrystal.h"

class LiquidCrystalKana : public LiquidCrystal {
public:
  LiquidCrystalKana(uint8_t rs, uint8_t enable,
                    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                    uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  LiquidCrystalKana(uint8_t rs, uint8_t rw, uint8_t enable,
                    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                    uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  LiquidCrystalKana(uint8_t rs, uint8_t rw, uint8_t enable,
	            uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
  LiquidCrystalKana(uint8_t rs, uint8_t enable,
		    uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

  virtual size_t write(uint8_t);
  using Print::write;
private:
  void initializer();
  uint8_t _last;
};

#endif
