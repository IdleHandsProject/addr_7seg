// This library is public domain. enjoy!
// https://github.com/IdleHandsProject/addr_7seg

// #include <avr/pgmspace.h>
//#include <util/delay.h>
#include <stdint.h>
#include "addr_7seg.h"

Addr_7seg::Addr_7seg(int8_t pin, int16_t displayCount)
{
  _displayCount = displayCount;
  pixels = new Adafruit_NeoPixel(displayCount * 3, pin, NEO_GRB + NEO_KHZ800);

  #if defined(__AVR_ATtiny85__)
  if (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif

  pixels->begin();

  brightnessArray = new uint8_t[displayCount];
  ledBrightnessArray = new uint8_t[displayCount];
  pointArray = new bool[displayCount];
  
  for(uint16_t i =0; i < displayCount; i++)
  {
    brightnessArray[i] = 255;
    ledBrightnessArray[i] = 0;
    pointArray[i] = 0;
   // setDisplay(i,0);
  }
 
}
Addr_7seg::~Addr_7seg()
{
  delete pixels;
  pixels = NULL;
  delete brightnessArray;
  brightnessArray = NULL;
  delete ledBrightnessArray;
  ledBrightnessArray = NULL;
}

void Addr_7seg::setDisplay(uint16_t num, uint8_t value)
{
  if (num > _displayCount - 1)
    return;
  uint16_t pixel = num * 3;
  uint8_t segments = digits_decode[value];
  uint8_t seg[8];
  for (uint8_t i = 0; i < 8; i++)
  {
    seg[i] = (segments >> i & 1) * brightnessArray[num];
  }

  pixels->setPixelColor(pixel, pixels->Color(seg[5], seg[0], seg[1]));
  pixels->setPixelColor(pixel + 1, pixels->Color(pointArray[num]*brightnessArray[num], seg[2], seg[3]));
  pixels->setPixelColor(pixel + 2, pixels->Color(seg[5],seg[4], ledBrightnessArray[num]));
  pixels->show();
}
void Addr_7seg::setPoint(uint16_t num, bool on)
{
  if (num > _displayCount - 1)
    return;
  pointArray[num] = on;
}
bool Addr_7seg::getPoint(uint16_t num)
{
  if (num > _displayCount - 1)
    return false;
  return pointArray[num];
}
void Addr_7seg::setBrightness(uint16_t num, uint8_t brightness)
{
  if (num > _displayCount - 1)
    return;
  brightnessArray[num] = brightness;
}
uint8_t Addr_7seg::getBrightness(uint16_t num)
{
  if (num > _displayCount - 1)
    return 0;
  return brightnessArray[num];
}
