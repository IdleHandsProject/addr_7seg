// ---------------------------------------------------------------------------
// Created by Jean Gauthier P.Eng. - SupremeSports - https://github.com/SupremeSports
// Copyright 2016 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// See "Addr7Segment.h" for purpose, syntax, version history, links, and more.
// ---------------------------------------------------------------------------

#include "Addr7Segment.h"
// This library is 100% entwined with the Adafruit NeoPixel library - please check their licensing terms in their library.
#include <Adafruit_NeoPixel.h>

//#define DEBUG

// Available characters a 7 Segment display can show
const byte ARRAY_SIZE = 34;

byte available_codes[ ARRAY_SIZE ][ 2 ] {
							  //   pgfedcba
						  { '0', 0b00111111 },
						  { '1', 0b00000110 },
						  { '2', 0b01011011 },
						  { '3', 0b01001111 },
						  { '4', 0b01100110 },
						  { '5', 0b01101101 },
						  { '6', 0b01111101 },
						  { '7', 0b00000111 },
						  { '8', 0b01111111 },
						  { '9', 0b01101111 },
						  { 'a', 0b01110111 },
						  { 'b', 0b01111100 },
						  { 'c', 0b01011000 },
						  { 'd', 0b01011110 },
						  { 'e', 0b01111001 },
						  { 'f', 0b01110001 },
						  { 'g', 0b01100111 },
						  { 'h', 0b01110110 },
						  { 'i', 0b00010000 },
						  { 'j', 0b00011110 },
						  { 'l', 0b00110000 },
						  { 'n', 0b01010100 },
						  { 'o', 0b01011100 },
						  { 'p', 0b01110011 },
						  { 'q', 0b01100111 },
						  { 'r', 0b01010000 },
						  { 's', 0b01101101 },
						  { 't', 0b01111000 },
						  { 'u', 0b00011100 },
						  { 'x', 0b01110110 },
						  { 'y', 0b01101110 },
						  { 'z', 0b01011011 },
						  { '-', 0b01000000 },
						  { ' ', 0b00000000 }
						};

byte available_codes_upper[ ARRAY_SIZE ][ 2 ] {
							  //   pgfedcba
						  { '0', 0b00111111 },
						  { '1', 0b00000110 },
						  { '2', 0b01011011 },
						  { '3', 0b01001111 },
						  { '4', 0b01100110 },
						  { '5', 0b01101101 },
						  { '6', 0b01111101 },
						  { '7', 0b00000111 },
						  { '8', 0b01111111 },
						  { '9', 0b01101111 },
						  { 'a', 0b01110111 },
						  { 'b', 0b01111111 },
						  { 'c', 0b00111001 },
						  { 'd', 0b00111111 },
						  { 'e', 0b01111001 },
						  { 'f', 0b01110001 },
						  { 'g', 0b01100111 },
						  { 'h', 0b01110110 },
						  { 'i', 0b00110000 },
						  { 'j', 0b00011110 },
						  { 'l', 0b00111000 },
						  { 'n', 0b00110111 },
						  { 'o', 0b00111111 },
						  { 'p', 0b01110011 },
						  { 'q', 0b01100111 },
						  { 'r', 0b00110001 },
						  { 's', 0b01101101 },
						  { 't', 0b01111000 },
						  { 'u', 0b00111110 },
						  { 'x', 0b01110110 },
						  { 'y', 0b01101110 },
						  { 'z', 0b01011011 },
						  { '-', 0b01000000 },
						  { ' ', 0b00000000 }
						};

byte spinAnimAll[6] 	{
							0b00000001,
							0b00000010,
							0b00000100,
							0b00001000,
							0b00010000,
							0b00100000
						};
					
byte spinAnimTop[4] 	{
							0b00000001,
							0b00000010,
							0b01000000,
							0b00100000
						};

byte spinAnimBottom[4] 	{
							0b01000000,
							0b00000100,
							0b00001000,
							0b00010000
						};

byte AnimEdgeLeft[4] 	{
							0b00001000,
							0b00010000,
							0b00100000,
							0b00000001
						};
byte AnimEdgeRight[4] 	{
							0b00000001,
							0b00000010,
							0b00000100,
							0b00001000
						};

Addr7Segment::Addr7Segment( uint8_t displayCount, uint8_t dPin )
{
	dispCount = displayCount;
	dispPin = dPin;
	NUM_PIXELS_PER_BOARD = 3;
	NUM_PIXELS_PER_CHIP = 3;
	pixels = Adafruit_NeoPixel ();
	pixels.updateType( NEO_GRB + NEO_KHZ800 );
  	pixels.updateLength( dispCount * NUM_PIXELS_PER_BOARD ); //Count number of pixels per digit board (Uses 3 WS281x per board/digit)
  	pixels.setPin(dispPin);
	isReady = false;
}

Addr7Segment::~Addr7Segment()
{
	isReady = false;
}

bool Addr7Segment::IsReady()
{
	return isReady;
}

void Addr7Segment::Begin( uint8_t brightness )
{
	pixels.begin(); // This initializes the NeoPixel library.
	pixels.show();
	pixels.setBrightness( brightness );

	#ifdef DEBUG
		Serial.print("Brightness: ");
		Serial.println(brightness);
		Serial.println("Ready!");
	#endif

	cachedString = "";
	cachedBytes = (byte *) malloc(dispCount * sizeof(byte));
	
	for ( int i = 0; i < dispCount; i++ )
		cachedBytes[i] = 0;

	//Digits are initialised and ready
	isReady = true;
	isForcedUpper = false;
}

void Addr7Segment::SetBrightness( uint8_t brightness )
{
	if ( isReady )
		pixels.setBrightness( brightness );
}

void Addr7Segment::ForceUppercase( bool force )
{
	isForcedUpper = force;
}

byte Addr7Segment::GetArraySize()
{
	return ARRAY_SIZE;
}

String Addr7Segment::GetCharacterAtArrayIndex( int index )
{
	return ( (String)(char)available_codes[ index ][0] );
}

// Convert separate 3 segments into packed 32-bit 3 segments.
uint32_t Addr7Segment::Wrap3Segments( uint8_t seg1, uint8_t seg2, uint8_t seg3 )
{
  return ((uint32_t)seg1 << 16) | ((uint32_t)seg2 <<  8) | seg3;
}

void Addr7Segment::CheckToCacheBytes( String str )
{
	if ( str != cachedString )
	{
		cachedString = str;
		
		int index = 0;
		for ( int s = 0; s < str.length(); s++ )
		{
			#ifdef DEBUG
			Serial.print( (String)str.charAt(s) );
			Serial.print( " .. " );
			#endif

			if ( (String)str.charAt(s) != "." )
			{ 
				cachedBytes[index] = FindByteForCharater( (String)str.charAt(s) );
				#ifdef DEBUG
				Serial.println( "1" );
				#endif
				index++;
			}
			else if ( s > 0 && bitRead( cachedBytes[index-1], 7 ) != 1 )
			{
				cachedBytes[index-1] = cachedBytes[index-1] | 0b10000000;
				#ifdef DEBUG
				Serial.println( "2" );
				#endif
			}
			else
			{
				cachedBytes[index] = 0b10000000;
				#ifdef DEBUG
				Serial.println( "3" );
				#endif
				index++;
			}
		}
	}
}

void Addr7Segment::DisplayDigit( int32_t number, uint8_t intensity )
{
	if ( !isReady )
		return;
	
	String text = String(number);
	
	DisplayText( text, intensity ); //Does the exact same thing, so convert number to string and call function
	
}

void Addr7Segment::DisplayText( String text, uint8_t intensity )
{
	if ( !isReady )
		return;
		
	CheckToCacheBytes( text );
	
	// Clamp the length, so text longer than the display count is ignored
	int lengthOfLoop = min( dispCount, (uint8_t)text.length() );
	
	// Grab the byte (bits) for the segments for the character passed in
	for ( int s = 0; s < lengthOfLoop; s++ )
	{
		byte code = cachedBytes[s];
		
		if(code > -1)
		{
			bool on[9];
			
			for( int segment = 0; segment < 8; segment++ )
				on[segment] = ( bitRead( code, segment ) == 1 );
			
			on[8] = false; // Left dp not used

			// Scroll all three chips on board
			for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
			{
				uint8_t seg[3];
				// Scroll all three segments on chip
				for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
					seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? intensity : 0;
				
				// Wrap three segments of chip into one "color" to the chip
				uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );
				
				pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), color );
			}
		}
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

void Addr7Segment::DisplayTextDigit( String text, uint8_t intensity[] )
{
	if ( !isReady )
		return;

	CheckToCacheBytes( text );

	// Clamp the length, so text longer than the display count is ignored
	int lengthOfLoop = min( dispCount, (uint8_t)text.length() );
	
	// Grab the byte (bits) for the segments for the character passed in
	for ( int s = 0; s < lengthOfLoop; s++ )
	{
		byte code = cachedBytes[s];
		
		if(code > -1)
		{
			bool on[9];
			
			for( int segment = 0; segment < 8; segment++ )
				on[segment] = ( bitRead( code, segment ) == 1 );
			
			on[8] = false; // Left dp not used

			// Scroll all three chips on board
			for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
			{
				uint8_t seg[3];
				// Scroll all three segments on chip
				for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
					seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? intensity[s] : 0;
				
				// Wrap three segments of chip into one "color" to the chip
				uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );
				
				pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), color );
			}
		}
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

void Addr7Segment::DisplayTime( uint8_t hours, uint8_t mins, uint8_t secs, uint8_t intensity )
{
	if ( !isReady )
		return;
		
	String text = PadTimeData( hours ) + PadTimeData( mins );

	if ( text.length() < dispCount )
	{
		for ( int i = 0; i < (dispCount - text.length()); i++ )
			text = " " + text;
	}

	CheckToCacheBytes( text );
	
	// Clamp the length, so text longer than the display count is ignored
	int lengthOfLoop = min( dispCount, (uint8_t)text.length() );

	// Grab the byte (bits) for the segments for the character passed in
	for ( int s = 0; s < lengthOfLoop; s++ )
	{
		byte code = cachedBytes[s];
		
		if(code > -1)
		{
			bool on[9];
			
			uint8_t cachedColor = intensity;
			
			// Displaying mins, so work out new color
			if ( s >= text.length() - 2 )
				cachedColor = ( secs % 2 == 0 ) ? intensity*0.5 : intensity;
			
			for( int segment = 0; segment < 8; segment++ )
				on[segment] = ( bitRead( code, segment ) == 1 );
			
			on[8] = false; // Left dp not used

			// Scroll all three chips on board
			for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
			{
				uint8_t seg[3];
				// Scroll all three segments on chip
				for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
					seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? cachedColor : 0;
				
				// Wrap three segments of chip into one "color" to the chip
				uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );
				
				pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), color );
			}
		}
	}

	// Blank extra digits
	if ( text.length() < dispCount )
	{
		for ( int s = lengthOfLoop; s < dispCount; s++ )
		{
			// Scroll all three chips on board
			for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
				pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), Wrap3Segments(0, 0, 0) );
		}
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

void Addr7Segment::DisplayKnightRider( uint8_t index, uint8_t intensity )
{
	if ( !isReady )
		return;

	bool isForward = true;

	int pixelIndex = ( index % ( dispCount * 2 ) );
	if ( pixelIndex > ( dispCount - 1 ) )
	{
		pixelIndex = ( dispCount * 2 ) - ( pixelIndex + 1 );
		isForward = false;
	}
	
	bool on[9];
	uint8_t intensityFade = intensity * 0.5;

	// Grab the byte (bits) for the segments for the character passed in
	for ( int s = 0; s < dispCount; s++ )
	{
		
		for( int segment = 0; segment < 9; segment++ )
			on[segment] = false;
			
		on[6] = true;
		
		uint8_t colorChase = 0;
		

		if ( s == pixelIndex )
			colorChase = intensity;
		else if ( isForward && s == pixelIndex - 1 )
			colorChase = intensityFade;
		else if ( !isForward && s == pixelIndex + 1 )
			colorChase = intensityFade;
		else
			colorChase = 0;
		
		// Scroll all three chips on board
		for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
		{
			uint8_t seg[3];
			// Scroll all three segments on chip
			for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
				seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? colorChase : 0;

			// Wrap three segments of chip into one "color" to the chip
			uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );

			pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), color );
		}
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

void Addr7Segment::DisplayBorderAnimation( uint8_t index, uint8_t intensity )
{
	if ( !isReady )
		return;
		
	int numSegmentSteps = 6; // Default for 1 display only
	int leftOverDisplayCount = 0; // Default left over displays from the middle
	if ( dispCount > 1 )
	{
		if ( dispCount < 3 )
			numSegmentSteps = 8;
		else
		{
			leftOverDisplayCount = dispCount - 2;
			numSegmentSteps = 8 + ( 2 * leftOverDisplayCount );
		}
	}

	int step = (index % numSegmentSteps);
	int curentDisplay = 0;

	byte code = -1;
	if ( step < 4 )
	{
		code = AnimEdgeLeft[ step ];
		curentDisplay = 0;
	}
	else if ( step < ( numSegmentSteps / 2 ) )
	{
		curentDisplay = step - 3;
		code = 0b00000001;
	}
	else if ( step > ( numSegmentSteps - leftOverDisplayCount - 1 ) )
	{
		curentDisplay = abs( step - numSegmentSteps );
		code = 0b00001000;
	}
	else
	{
		code = AnimEdgeRight[ step - ( numSegmentSteps / 2 ) ];
		curentDisplay = dispCount - 1;
	}

	// Grab the byte (bits) for the segments for the character passed in
	for ( int s = 0; s < dispCount; s++ )
	{
		bool on[9];
		for( int segment = 0; segment < 8; segment++ )
			on[segment] = ( bitRead( code, segment ) == 1 );
		
		on[7] = false; // Right dp not used
		on[8] = false; // Left dp not used
		
		if ( s == curentDisplay )
		{
			// Scroll all three chips on board
			for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
			{
				uint8_t seg[3];
				// Scroll all three segments on chip
				for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
					seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? intensity : 0;
				
				// Wrap three segments of chip into one "color" to the chip
				uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );
			
				pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), color );
			}
		}
		else
		{
			// Scroll all three chips on board
			for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
				pixels.setPixelColor( chipOnBoard + ( s * NUM_PIXELS_PER_BOARD ), Wrap3Segments(0, 0, 0) );
		}
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

uint8_t Addr7Segment::GetSpinAllLength( void )
{
	return ( sizeof(spinAnimAll) / sizeof(byte) );
}
uint8_t Addr7Segment::GetSpinTopLength( void )
{
	return ( sizeof(spinAnimTop) / sizeof(byte) );
}
uint8_t Addr7Segment::GetSpinBottomLength( void )
{
	return ( sizeof(spinAnimBottom) / sizeof(byte) );
}

byte Addr7Segment::GetSpinAllAtIndex( uint8_t index )
{
	if ( index < GetSpinAllLength() )
		return ( spinAnimAll[ index ] );
}

byte Addr7Segment::GetSpinTopAtIndex( uint8_t index )
{
	if ( index < GetSpinTopLength() )
		return ( spinAnimTop[ index ] );
}

byte Addr7Segment::GetSpinBottomAtIndex( uint8_t index )
{
	if ( index < GetSpinBottomLength() )
		return ( spinAnimBottom[ index ] );
}

void Addr7Segment::SetDigit( uint8_t digit, String text, uint8_t intensity )
{
	if ( !isReady )
		return;

	if ( digit < 0 || digit > dispCount )
		return;

	CheckToCacheBytes( text );

	byte code = cachedBytes[0]; //No matter the length of string received, only first character with it's point will be displayed on requested digit

	if(code > -1)
	{
		bool on[9];
		
		for( int segment = 0; segment < 8; segment++ )
			on[segment] = ( bitRead( code, segment ) == 1 );
		
		on[8] = false; // Left dp not used

		// Scroll all three chips on board
		for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
		{
			uint8_t seg[3];
			// Scroll all three segments on chip
			for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
				seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? intensity : 0;
			
			// Wrap three segments of chip into one "color" to the chip
			uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );
			
			pixels.setPixelColor( chipOnBoard + ( digit * NUM_PIXELS_PER_BOARD ), color );
		}
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

void Addr7Segment::SetDigitSegments( uint8_t digit, byte bits, uint8_t intensity )
{
	if ( !isReady )
		return;
	
	if ( digit < 0 || digit > dispCount )
		return;
	
	bool on[9];
	
	for( int segment = 0; segment < 8; segment++ )
		on[segment] = ( bitRead( bits, segment ) == 1 );
	
	on[8] = false; // Left dp not used

	// Scroll all three chips on board
	for ( int chipOnBoard = 0; chipOnBoard < NUM_PIXELS_PER_BOARD; chipOnBoard++ )
	{
		uint8_t seg[3];
		// Scroll all three segments on chip
		for ( int segOnChip = 0; segOnChip < NUM_PIXELS_PER_CHIP; segOnChip++ )
			seg[ chipOnBoard ] = on[ ( chipOnBoard*NUM_PIXELS_PER_CHIP ) + segOnChip ] ? intensity : 0;
		
		// Wrap three segments of chip into one "color" to the chip
		uint32_t color = Wrap3Segments( seg[0], seg[1], seg[2] );
		
		pixels.setPixelColor( chipOnBoard + ( digit * NUM_PIXELS_PER_BOARD ), color );
	}

	// We have finished setting all of the segment for this Addr7Segment, so lets turn on the pixels
	pixels.show();
}

int Addr7Segment::FindIndexOfChar(String character)
{
	String s = character;
	s.toLowerCase();
	for(int i=0; i< ARRAY_SIZE; i++)
	{
		if( s.equals( (String)( (char)available_codes[i][0] ) ) )
			return i;
	}
	return -1;
}

byte Addr7Segment::FindByteForCharater( String character )
{
	String s = character;
	s.toLowerCase();
	for(int i=0; i< ARRAY_SIZE; i++)
	{
		if ( isForcedUpper )
		{
			if( s.equals( (String)( (char)available_codes_upper[i][0] ) ) )
				return available_codes_upper[i][1];
		}
		else
		{
			if( s.equals( (String)( (char)available_codes[i][0] ) ) )
				return available_codes[i][1];
		}
	}
	return -1;
}

String Addr7Segment::PadTimeData( int8_t data )
{
  if( data < 10 )
	return String("0") + String(data);

  return String(data);
}
