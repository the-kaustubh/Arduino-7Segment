#include <SevenSegment.h>

SSD s1(3, 4, 5, 6, 7, 8, 9);
/* A to G */

int polarity = 13;  // Common Anode or Cathode
byte number = 0;

void setup() {
  pinMode(polarity, INPUT);
  s1.setSSDType(digitalRead(polarity));
}

void loop() {
  s1.displayNibble(number);
  delay(3000);
  number++;
}
