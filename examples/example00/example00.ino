/*
	SevenSegment Library - Simple HEX display

	Demonstrates the use of one common cathode SevenSegment Display.

	The sketch demonstrates the use of the setSSDType()
	and displayNibble() functions to choose between common anode
	and common cathode and displaying a 4-bit value, respectively.

	Circuit:
	* Pins A to F of Seven Segment display go to digital pins 3 to 9
	* The common pin goes to ground through a resistor (assuming common cathode)
	
*/

#include <SevenSegment.h>

SSD s1(3, 4, 5, 6, 7, 8, 9);
/* A to G */

int polarity = SSD::COM_CATHODE;  // Common Anode or Cathode
byte number = 0;

void setup() {
  s1.setSSDType(polarity);
}

void loop() {
  s1.displayNibble(number);
  delay(3000);
  number++;
}
