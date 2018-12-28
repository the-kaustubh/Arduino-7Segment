#ifndef _SSD_H
#define _SSD_H

class SSD {

  unsigned char a, b, c, d, e, f, g, dp;
  unsigned char disp_pins[7];
  const int COM_ANODE = 1;
  const int COM_CATHODE = 0;
  int type;

  // This is the Product of Sum form of the
  // digita function
  const int POS[7][7] = {
    { 1, 4, 11, 12, 13},      // The segment 'a' remains off for these numbers
          // a
    { 5, 6, 11, 12, 14, 15 }, // segment 'b' for these
         // b
    { 2, 12, 14, 15 },        // C'mon you get the idea
         // c
    { 1, 4, 7, 10, 15 },
         // d
    { 1, 3, 4, 5, 7, 9 },
         // e
    { 1, 2, 3, 7, 12, 13 },
         // f
    { 0, 1, 7 }
         // g
  };

  // this array holds the size of the pos array for eacg segment
  const int function_size[7] = { 5, 6, 4, 5, 6, 6, 3 };


public:
  SSD(int _a, int _b, int _c, int _d, int _e, int _f, int _g);

  void reset(); // Resets the SSDisplay

  bool isMaxterm(int num, int function);

  void setSSDType(int _type) {
    type = _type;
  }

  void displayNibble(int num);

};

#endif
