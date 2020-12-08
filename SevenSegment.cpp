#include "Arduino.h"
#include "SevenSegment.h"

SSD::SSD(int _a, int _b, int _c, int _d, int _e, int _f, int _g) {
  // This is a hell lot of arguments
  // Refactor this!
  // Use Shift Regs or I2C
  int i;
  this->a = _a;
  this->b = _b;
  this->c = _c;
  this->d = _d;
  this->e = _e;
  this->f = _f;
  this->g = _g;
  this->disp_pins[0] = this->a;
  this->disp_pins[1] = this->b;
  this->disp_pins[2] = this->c;
  this->disp_pins[3] = this->d;
  this->disp_pins[4] = this->e;
  this->disp_pins[5] = this->f;
  this->disp_pins[6] = this->g;

  for(i = 0; i < 7; i++) pinMode(this->disp_pins[i], OUTPUT);
}


void SSD::reset() { // Resets the SSDisplay
  int i;
  for( i = 0; i < 7; i++) {
    digitalWrite(SSD::disp_pins[i], 0);
  }
}

bool SSD::isMaxterm(int num, int function) {
  // Should return true if the number is present in the POS function
  int i;
  for( i = 0; i < SSD::function_size[function]; i++) {
    if( num ==  POS[function][i])
      return true;
  }
  return false;
}

void SSD::displayNibble(int num) {
  int i;
  for( i = 0; i < 7; i++) {
    if(isMaxterm(num & 0xf, i)) {
      digitalWrite(
      SSD::disp_pins[i],
      (SSD::type) ? 0 : 1
        );
    } else {
     digitalWrite(
       SSD::disp_pins[i],
       (SSD::type) ? 1 : 0
        );
    }
  }
}
