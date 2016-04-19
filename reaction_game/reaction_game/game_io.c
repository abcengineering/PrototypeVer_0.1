/*
 * game_io.c
 *
 * Created: 04-04-2016 17:12:33
 *  Author: Jacob Roesen
 */

#include <avr/io.h>
#include "game_io.h"






unsigned char read_start_button(void)
{
	return (PINB & START_MASK);
}


void players_button(int mode)
{
	switch(mode)
	{
		case 0:
		PCMSK = 0b11000000;
		break;
		
		case 1:
		PCMSK = 0b00000000;
		break;
		
		default:
		PCMSK = 0b00000000;
		break;
	}
}




void led_mode(int mode)
{
	
		switch(mode)
		{
			case 0:
			PORTB = 0b00000000;
			PORTD = 0b00000000;
			break;
			
			case 1:
			PORTB = 0b00000001;
			PORTD = 0b00000001;
			break;
			
			case 2:
			PORTB = 0b00000010;
			PORTD = 0b00000010;
			break;
			
			case 3:
			PORTB = 0b00000100;
			PORTD = 0b00000100;
			break;
			
			case 4:
			PORTB = 0b00001000;
			PORTD = 0b00001000;
			break;
			
			case 5:
			PORTB = 0b00001111;
			PORTD = 0b00001111;
			break;
			
			case 6:
			PORTB = 0b00001111;
			break;
			
			case 7:
			PORTD = 0b00001111;
			break;
			
			default:
			PORTB = 0b00000000;
			PORTD = 0b00000000;
			break;
		
		}
		
		
	
		
}

