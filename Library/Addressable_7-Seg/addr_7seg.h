// This library is public domain. enjoy!
// https://github.com/IdleHandsProject/addr_7seg

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif




//Segment Layout and digit reference number

//		 ---0---
//		|       |
// 		1		2		
//		|		|
//		 ---7---
//		|		|	
//		6		3
//		|		|
//		 ---5---	O(4)	

// Example to display 0 would be 0x11110110	or 0xF6
// Example to display 1 would be 0x00110000	or 0x30
// Example to display 2 would be 0x10100111	or 0xA7
// Example to display 3 would be 0x10110101	or 0xB5
// Example to display 4 would be 0x01110001	or 0x71
// Example to display 5 would be 0x11010101	or 0xD5
// Example to display 6 would be 0x11010111	or 0xD7
// Example to display 7 would be 0x10110000	or 0xB0
// Example to display 8 would be 0x11110111 or 0xF7
// Example to display 9 would be 0x11110001	or 0xF1



class Addr_7seg
{

  
public:
  Addr_7seg(int8_t pin, int16_t displayCount);
  ~Addr_7seg();
  void setDisplay(uint16_t num, uint8_t value);
  void setPoint(uint16_t num, bool on);
  bool getPoint(uint16_t num);
  void setBrightness(uint16_t num, uint8_t brightness);
  uint8_t getBrightness(uint16_t num);
   void setLed(uint16_t num, uint8_t brightness);
  uint8_t getLed(uint16_t num);

private:
//Below has "0-F" and some random characters. Feel free to add more.
  const uint8_t digits_decode[75]= {
    0xF6, 0x30, 0xA7, 0xB5, 0x71, 0xD5, 0xD7, 0xB0, 0xF7, 0xF1, 0xF3, 0x57, 
    0x07, 0x37, 0xC7, 0xC3, 0x42, 0x77, 0xE3, 0x4E, 0x73, 0x4F, 0x47, 0x5E, 
    0x37, 0x06, 0x3C, 0x00, 0x0E, 0x00, 0x00, 0x7E, 0x67, 0x00, 0x00, 0x5B, 
    0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1F, 0x0D, 0x3D, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x15, 0x1D, 0x00, 0x73, 0x05, 0x00, 0x0F, 0x1C, 0x00, 0x00, 
    0x00, 0x3B, 0x00
  };
  uint16_t _displayCount = 0;
  Adafruit_NeoPixel* pixels;
  uint8_t* brightnessArray;
  uint8_t* ledBrightnessArray;
  bool* pointArray;
};
