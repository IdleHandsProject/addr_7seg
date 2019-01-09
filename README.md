# Addressable 7-Segment Displays
An API that lets you display numbers and letters on Addr7Segment LED displays that are available 
from [PCBway](https://www.pcbway.com/project/shareproject/Addressable_7_Segment_Display.html)
This board uses 3 x WS2811 IC to control the segments of the segmented display. 
This means they can be daisy chained and controlled with just a single data line. 

You can find the Open Source hardware PCB design and Gerber files [here](https://github.com/IdleHandsProject/addr_7seg)

## Installing and Use
The downloaded code should be added to your arduino IDE libraries folder, and the library requires the [Adafruit NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel) for it to function.

To include the Addr7Segment library in your project:

    #include <Addr7Segment.h>

You can then initialise the display with the following line that includes the number of Neo7Segment digits and the GPIO to control them:

	#define DIGITS       5   // Number of digits
	#define PIN          4   // Pin number

	// Initalise the display with 5 Addr7Segment boards connected to GPIO 4
	Addr7Segment disp( DIGITS, PIN );

You then start the display with the begin method, passing the brightness [0%-100%]:

    disp.Begin(20);

The you simply pass the display the String you would like displayed and a brigtness [0%-100%]:

    disp.DisplayText( "1234", 20 );
	

## Check out the video! - Click the Image

[![Addressable 7-Segment Display Video](https://img.youtube.com/vi/nfvzyg8gkIE/0.jpg)](https://youtu.be/nfvzyg8gkIE)

Order the PCB from PCBWay Here: http://bit.ly/addr7segpcb