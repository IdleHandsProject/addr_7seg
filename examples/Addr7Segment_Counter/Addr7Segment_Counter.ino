//Displays all digits with the same number counting from 0 to 9. Odd numbers have decimal point ON, others OFF.
//Push button on pin 5 to control color changing
#include <Addr7Segment.h>

#define DIGITS       		      5   // Number of digits
#define PIN          		      4   // Pin number

// Initalise the display with 5 Addr7Segment boards, connected to GPIO 4
Addr7Segment disp(DIGITS, PIN);

int loopIndex               	= 0;
int featureIndex				      = 0;
unsigned long nextLoop   	  	= 0;
int displayFeature          	= 0;
long nextCount              	= millis();

//Button pin define
#define buttonPin           	5

bool changeFeature          	= false;
bool buttonActive           	= false;
int digitDisplay            	= 0;

String text                 	= "";

void setup()
{
  Serial.begin(9600);
  delay(1000);

  pinMode(buttonPin, INPUT);

  // Start the display with a brightness value of 20
  disp.Begin(20);

  // Set the initial display feature to show as 0
  displayFeature = 0;
}

void loop()
{
  // Wait until the display is initialised before we try to show anything
  if ( !disp.IsReady() )
    return;

  readButtonPush();

  if ( millis() > nextCount )
  {
    digitDisplay += 1;
    nextCount = millis() + 1000;
  }

  if (digitDisplay > 9)
    digitDisplay = 0;

  String dot = ( ( digitDisplay%2 ) == 0 ) ? "." : "";
  String digit = String( digitDisplay );

  text = "";
  for ( int i = 0; i < DIGITS; i++ )
    text = text + digit + dot;

  // Switch sequence when pressing on button
  if ( changeFeature )
    displayFeature = (displayFeature + 1) % 8;

  // Display stuff on the Neo7Segment displays
  if (nextLoop < millis() || changeFeature)
    colorChangingSequences();

  changeFeature = false;
}

void colorChangingSequences()
{
  switch(displayFeature)
  {
    case 0:
      featureIndex++;

      if (featureIndex % 5 == 0)
      {
        loopIndex++;
        if (loopIndex >= disp.GetSpinAllLength())
          loopIndex = 0;
      }

      disp.SetDigitSegments(0, disp.GetSpinAllAtIndex(loopIndex), 50);
      disp.SetDigitSegments(1, disp.GetSpinAllAtIndex(loopIndex), 100);
      disp.SetDigitSegments(2, disp.GetSpinAllAtIndex(loopIndex), 150);
      disp.SetDigitSegments(3, disp.GetSpinAllAtIndex(loopIndex), 200);
      disp.SetDigitSegments(4, disp.GetSpinAllAtIndex(loopIndex), 250);

      for (int i = 5; i<DIGITS; i++)
        disp.SetDigit(i, "", 0);

      nextLoop = millis() + 10;
      break;

    case 1:
      if (featureIndex > (2*DIGITS))
        featureIndex = 0;

      disp.DisplayKnightRider(featureIndex, 255);
      nextLoop = millis() + 10;
      featureIndex++;
      break;

    case 2://
      disp.DisplayBorderAnimation(featureIndex, 250);
      nextLoop = millis() + 100;
      featureIndex--;
      break;

    case 3:
      disp.DisplayTime((digitDisplay*10+digitDisplay), (digitDisplay*10+digitDisplay), digitDisplay, 255 );
      nextLoop = millis() + 500;
      break;

    case 4:
      disp.DisplayText(text, featureIndex);
      nextLoop = millis() + 10;
      featureIndex += 5;
      break;
	  
	  case 5:
	    uint32_t number;
	    for ( int i = 0; i < DIGITS; i++ )
		    number += digitDisplay*pow(10, i);
	
      disp.DisplayDigit(number, featureIndex);
      nextLoop = millis() + 10;
      featureIndex -= 5;
      break;
	  
    case 6: // Same as case #5, but allows to send complete string and change each digit's color
      uint8_t digitIntensity[DIGITS];
  	  digitIntensity[0] = 50;
  	  digitIntensity[1] = 100;
  	  digitIntensity[2] = 150;
  	  digitIntensity[3] = 200;
  	  digitIntensity[4] = 250;

      for (int i = 5; i<DIGITS; i++)
        digitIntensity[i] = 0;

      disp.DisplayTextDigit(text, digitIntensity);
      nextLoop = millis() + 50;
      featureIndex++;
      break;

    case 7: // Same as case #5, but allows to send string character (only first will be used) and change only one digit at a time
      disp.SetDigit(0, text, 250);
      disp.SetDigit(1, text, 200);
      disp.SetDigit(2, text, 150);
      disp.SetDigit(3, text, 100);
      disp.SetDigit(4, text, 50);

      nextLoop = millis() + 50;
      featureIndex++;
      break;

    default:
      displayFeature = 0;
      break;
  }
}

void readButtonPush()
{
  bool buttonPressed = !digitalRead(buttonPin);
  if (buttonPressed)
  {
    if (!buttonActive)
      buttonActive = true;
  }
  else
  {
    if (buttonActive)
      changeFeature = true;

    buttonActive = false;
  }
}