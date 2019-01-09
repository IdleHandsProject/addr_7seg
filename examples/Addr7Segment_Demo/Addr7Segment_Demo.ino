//Displays different designs
//Changes feature every 5 seconds
#include <Addr7Segment.h>

#define DIGITS       		      5   // Number of digits
#define PIN          		      4   // Pin number

// Initalise the display with 5 Addr7Segment boards, connected to GPIO 4
Addr7Segment disp(DIGITS, PIN);

int loopIndex               	= 0;
int featureIndex				      = 0;
unsigned long nextLoop   	  	= 0;
int displayFeature          	= 0;
long nextSwitch              	= millis();

void setup()
{
  Serial.begin(9600);
  delay(1000);

  // Start the display with a brightness value of 20
  disp.Begin(20);

  // Set the initial display feature to show as 0
  displayFeature = 0;
}

void loop()
{
  // Wait until the display is initialised before we try to show anything
  if ( !disp.IsReady() )
  {
    nextSwitch = millis();
    return;
  }

  // Switch what we are showing every 5 seconds
  if ( millis() > nextSwitch )
  {
    nextSwitch = millis() + 5000;
    displayFeature = ( displayFeature + 1 ) % 13;
  }

  // Display stuff on the Neo7Segment displays
  if ( nextLoop < millis() )
    colorChangingSequences();
}

void colorChangingSequences()
{
  switch( displayFeature )
  {
    case 0:
      disp.DisplayText( "12345", featureIndex );
      nextLoop = millis() + 1;
      featureIndex++;
      break;

    case 1:
      disp.DisplayText("     ", 255 );
      delay(250);
      disp.DisplayText("C    ", 255 );
      delay(250);
      disp.DisplayText("CL   ", 255 );
      delay(250);
      disp.DisplayText("CLE  ", 255 );
      delay(250);
      disp.DisplayText("CLEA ", 255 );
      delay(250);
      disp.DisplayText("CLEAR", 255 );
      delay(1250);
      disp.DisplayText(" LEAR", 255 );
      delay(250);
      disp.DisplayText("  EAR", 255 );
      delay(250);
      disp.DisplayText("   AR", 255 );
      delay(250);
      disp.DisplayText("    R", 255 );
      delay(250);
      disp.DisplayText("     ", 255 );
      delay(500);
      nextSwitch = 0;
      break;  

    case 2:
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

    case 3:
      if (featureIndex > (2*DIGITS))
  			featureIndex = 0;
  
  		disp.DisplayKnightRider(featureIndex, 255);
  		nextLoop = millis() + 10;
  		featureIndex++;
  		break;

    case 4:
      disp.DisplayBorderAnimation(featureIndex, 255);
  		nextLoop = millis() + 100;
  		featureIndex--;
  		break;
    
    case 5:
      disp.DisplayTime( 22, 16, (featureIndex % 60), 255);
      nextLoop = millis() + 500;
	    featureIndex++;
      break;

    case 6:
      disp.DisplayText( "0....0", featureIndex );
      nextLoop = millis() + 10;
      featureIndex++;
      break;

    case 11: // Same as case #0, but allows to send complete string and change each digit's color
      uint8_t digitIntensity[DIGITS];
  		digitIntensity[0] = 50;
  		digitIntensity[1] = 100;
  		digitIntensity[2] = 150;
  		digitIntensity[3] = 200;
  		digitIntensity[4] = 250;
  
  		for (int i = 5; i<DIGITS; i++)
  		  digitIntensity[i] = 0;
  
  		disp.DisplayTextDigit("67890", digitIntensity);
  		nextLoop = millis() + 50;
  		featureIndex++;
  		break;

    case 12: // Same as case #0, but allows to send string character (only first will be used) and change only one digit at a time
      disp.SetDigit(0, "A", 250);
  		disp.SetDigit(1, "B", 200);
  		disp.SetDigit(2, "C", 150);
  		disp.SetDigit(3, "D", 100);
  		disp.SetDigit(4, "E", 50);
  
  		nextLoop = millis() + 50;
  		featureIndex++;
  		break;

    default:
      displayFeature = 0;
      break;
  }
}