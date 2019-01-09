// ---------------------------------------------------------------------------
// Addr7Segment Library - v2.0.1 - 09/01/2019
//
// AUTHOR/LICENSE:
// Created by Jean Gauthier P.Eng. - SupremeSports - https://github.com/SupremeSports
// Copyright 2016 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
//
// LINKS:
// Project home: XXX <--
// Blog: XXX <--
//
// DISCLAIMER:
// This software is furnished "as is", without technical support, and with no 
// warranty, express or implied, as to its usefulness for any purpose.
//
// PURPOSE:
// Seven Segment Library for the Addr7Segment display boards
//
// SYNTAX:
//   Addr7Segment( digits, pin ) - Initialise the array of displays
//     Parameters:
//		* digits		- The number of digits you will be displaying on
//		* pin			- Pin speaker is wired to (other wire to ground, be sure to add an inline 100 ohm resistor).
//
// HISTORY:

//
// 09/01/2019 v1.0    - Initial release.
//
// ---------------------------------------------------------------------------

#ifndef Addr7Segment_h
	#define Addr7Segment_h

	#include <Adafruit_NeoPixel.h>

  	#if defined(ARDUINO) && ARDUINO >= 100
    	#include <Arduino.h>
  	#else
    	#include <WProgram.h>
		#include <pins_arduino.h>
	#endif

	#ifdef __AVR__
	  #include <avr/power.h>
	#endif

class Addr7Segment
{
	public:
		Addr7Segment( uint8_t displayCount, uint8_t dPin );
		~Addr7Segment();
		
		void Begin( uint8_t brightness );
		void SetBrightness( uint8_t brightness );
		
		void DisplayDigit( int32_t number, uint8_t intensity );
		void DisplayText( String text, uint8_t intensity );
		void DisplayTextDigit( String text, uint8_t intensity[] );
		void DisplayKnightRider( uint8_t index, uint8_t intensity );
		void DisplayBorderAnimation( uint8_t index, uint8_t intensity );
		void DisplayTime( uint8_t hours, uint8_t mins, uint8_t secs, uint8_t intensity );
		
		void SetDigit( uint8_t digit, String text, uint8_t intensity );
		void SetDigitSegments( uint8_t digit, byte bits, uint8_t intensity );
		
		static uint32_t Wrap3Segments(uint8_t seg1, uint8_t seg2, uint8_t seg3);

		void ForceUppercase( bool force );
		
		// SpinningAnims
		uint8_t GetSpinAllLength( void );
		uint8_t GetSpinTopLength( void );
		uint8_t GetSpinBottomLength( void );
		byte GetSpinAllAtIndex( uint8_t index );
		byte GetSpinTopAtIndex( uint8_t index );
		byte GetSpinBottomAtIndex( uint8_t index );

		bool IsReady( void );
		
		int FindIndexOfChar(String character);
		byte FindByteForCharater( String character );

	protected:

	private:
		Adafruit_NeoPixel pixels;
		uint8_t dispCount;
		uint8_t dispPin;
		uint8_t NUM_PIXELS_PER_BOARD;
		uint8_t NUM_PIXELS_PER_CHIP;
		byte GetArraySize();
		String GetCharacterAtArrayIndex( int index );
		void SetupCharacters();
		void CheckToCacheBytes( String s );
		String PadTimeData( int8_t data );
		byte *cachedBytes;
		String cachedString;
		
		bool isReady;
		
		bool isForcedUpper;
};
#endif