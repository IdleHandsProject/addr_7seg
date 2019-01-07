/*
   Check out the video for the Addressable Seven Segment Display at http://Youtube.com/seanhodgins

   This is an example program to run the addressable 7 segment display chain.
   Connect to pin 9 and define how many Digits you have in the daisy chain
   I refer to each 7 segment display as a DIGIT, and easy led in a digit as a SEGMENT
   There are 7 segments and 1 decimal place.

   If you want to help develop a real library for these feel free to contact me @ sean.hodginsa@gmail.com
   I will gladly supply you with a few displays to get the ball rolling.

   This program uses the Adafruit Neopixel library to control the Segments.
   https://github.com/adafruit/Adafruit_NeoPixel
   Open source of course.
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


//#define TESTDISPLAY


#define PIN             9             //The Pin that connects to the data line of the FIRST (Rightmost) digit.
#define NUMDIGITS       4             //Number of DIGITs Daisy Chained.
#define NUMWS2811       3*NUMDIGITS   // How many WS2811s are attached.

uint8_t numGRB[10] = {0b01101111, 0b00001100, 0b11100101, 0b10101101, 0b10001110, 0b10101011, 0b11101011, 0b00001101, 0b11101111, 0b10001111};
uint8_t setDEC[NUMDIGITS] = {};

Adafruit_NeoPixel segments = Adafruit_NeoPixel(NUMWS2811, PIN, NEO_GRB + NEO_KHZ400); //Required to initiallize the digits

int delayval = 1000; // delay for half a second

void setup() {
  //Sets the Decimals all off.
  for (int x = 0; x < NUMDIGITS; x++) {
    setDEC[x] = 0;
  }
  segments.begin(); // Starts NeoPixel library.
  Serial.begin(115200);

#ifdef TESTDISPLAY
  while (1) {
    for (int y = 0; y < NUMDIGITS; y++) {
      testDisplay(y, 100);
    }
  }
#endif
}

uint8_t number = 0;

void loop() {
  // A Display Demo
  for (int i = 0; i < NUMDIGITS; i++) {
    slideDown(i);
    slideUp(i);
    rotateCW(i);
    rotateCCW(i);
  }
  for (int x = 1; x < 1000; x++) {
    writeDigit(2, (x / 100) % 10, 100);
    writeDigit(1, (x / 10) % 10, 100);
    writeDigit(0, x % 10, 100);
    segments.show();
    delay(10);
  }
  number = 0;
  while (number < 10) {
    writeDigit(0, number, 100);
    writeDigit(1, number, 100);
    writeDigit(2, number, 100);
    number++;
    segments.show();
    delay(100);
  }
  number = 0;
  while (number < 10) {
    pulseNum(0, number, 100);
    pulseNum(1, number, 100);
    pulseNum(2, number, 100);
    number++;
    segments.show();
    delay(100);
    changeDEC(0);
  }
}

//This Writes a number to a Digit
void writeDigit(int digit, uint8_t num, int brightness) {
  int ws2811[3] = {0, 1, 2};

  ws2811[0] = digit * 3;
  ws2811[1] = (digit * 3) + 1;
  ws2811[2] = (digit * 3) + 2;

  uint8_t BIT[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t SET[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  Serial.print(num);
  Serial.print(" ");
  Serial.println(numGRB[num], BIN);
  for (int x = 0; x < 8; x++) {

    BIT[x] = bitRead(numGRB[num], x);
    if (BIT[x]) {
      SET[x] = brightness;
    }
    Serial.print(SET[x]);
    Serial.print(", ");

  }
  if (setDEC[digit] == 1) {
    SET[4] = brightness;
  }
  else {
    SET[4] = 0;
  }
  Serial.println();
  segments.setPixelColor(ws2811[0], segments.Color(SET[0], SET[1], SET[2]));
  segments.setPixelColor(ws2811[1], segments.Color(SET[3], SET[4], SET[5]));
  segments.setPixelColor(ws2811[2], segments.Color(SET[6], SET[7], SET[8]));


}

void testDisplay(int digit, uint8_t brightness) {
  int ws2811[3] = {0, 1, 2};
  if (digit > 0) {
    ws2811[0] = digit * 3;
    ws2811[1] = (digit * 3) + 1;
    ws2811[1] = (digit * 3) + 2;
  }
  segments.setPixelColor(digit * 3, segments.Color(brightness, 0, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit * 3, segments.Color(0, brightness, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit * 3, segments.Color(0, 0, brightness));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit * 3, segments.Color(0, 0, 0));
  segments.show();
  segments.setPixelColor(digit * 3 + 1, segments.Color(brightness, 0, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit + 1, segments.Color(0, brightness, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit + 1, segments.Color(0, 0, brightness));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit + 1, segments.Color(0, 0, 0));
  segments.setPixelColor(digit + 2, segments.Color(brightness, 0, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit + 2, segments.Color(0, brightness, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit + 2, segments.Color(0, 0, brightness));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit + 2, segments.Color(0, 0, 0));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit * 3, segments.Color(brightness, brightness, brightness));
  segments.setPixelColor(digit + 1, segments.Color(brightness, brightness, brightness));
  segments.setPixelColor(digit + 2, segments.Color(brightness, brightness, brightness));
  segments.show();
  delay(1000);
  segments.setPixelColor(digit * 3, segments.Color(0, 0, 0));
  segments.setPixelColor(digit + 1, segments.Color(0, 0, 0));
  segments.setPixelColor(digit + 2, segments.Color(0, 0, 0));
  segments.show();
}

void slideDown(int digit) {
  clearDigit(digit * 3);
  setSeg(digit * 3, 0, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 7, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 5, 100);
  segments.show();
  delay(100);
}

void slideUp(int digit) {
  clearDigit(digit * 3);
  setSeg(digit * 3, 5, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 7, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 0, 100);
  segments.show();
  delay(100);
}

void rotateCW(int digit) {
  clearDigit(digit * 3);
  setSeg(digit * 3, 0, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 2, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 3, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 5, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 6, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 1, 100);
  segments.show();
  delay(100);
}

void rotateCCW(int digit) {
  clearDigit(digit * 3);
  setSeg(digit * 3, 0, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 1, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 6, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 5, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 3, 100);
  segments.show();
  delay(100);
  clearDigit(digit * 3);
  setSeg(digit * 3, 2, 100);
  segments.show();
  delay(100);
}

void setSeg (int digit, int seg, uint8_t brightness) {
  switch (seg) {
    case 0:
      segments.setPixelColor(digit * 3, segments.Color(brightness, 0, 0));
      break;
    case 1:
      segments.setPixelColor(digit * 3, segments.Color(0, brightness, 0));
      break;
    case 2:
      segments.setPixelColor(digit * 3, segments.Color(0, 0, brightness));
      break;
    case 3:
      segments.setPixelColor(digit * 3 + 1, segments.Color(brightness, 0, 0));
      break;
    case 4:
      segments.setPixelColor(digit * 3 + 1, segments.Color(0, brightness, 0));
      break;
    case 5:
      segments.setPixelColor(digit * 3 + 1, segments.Color(0, 0, brightness));
      break;
    case 6:
      segments.setPixelColor(digit * 3 + 2, segments.Color(brightness, 0, 0));
      break;
    case 7:
      segments.setPixelColor(digit * 3 + 2, segments.Color(0, brightness, 0));
      break;
    case 8:
      segments.setPixelColor(digit * 3 + 2, segments.Color(0, 0, brightness));
      break;
    default:
      break;
  }
}

void clearDigit(int digit) {
  int ws2811[3] = {0, 1, 2};
  if (digit > 0) {
    ws2811[0] = digit * 3;
    ws2811[1] = (digit * 3) + 1;
    ws2811[1] = (digit * 3) + 2;
  }
  segments.setPixelColor(digit * 3, segments.Color(0, 0, 0));
  segments.setPixelColor(digit * 3 + 1, segments.Color(0, 0, 0));
  segments.setPixelColor(digit * 3 + 2, segments.Color(0, 0, 0));
}

void pulseNum(int digit, int num, uint8_t maxb) {
  int    brightness = 10;
  int     rate = 5;
  while (brightness > 0) {
    if (brightness > maxb) {
      rate = rate * -1;
    }
    writeDigit(digit, num, brightness);
    delay(10);
    brightness += rate;
    segments.show();
  }
  writeDigit(digit, num, 0);
  segments.show();
}


void changeDEC(int digit) {
  if (setDEC[digit] == 0) {
    setDEC[digit] = 1;
  }
  else {
    setDEC[digit] = 0;
  }
}
