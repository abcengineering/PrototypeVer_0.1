/*
 * game.c
 *
 * Created: 04-04-2016 17:12:33
 *  Author: Jacob Roesen
 */


#include <avr/io.h>
#include "game.h"
#include "game_io.h"
#include "shared.h"

enum GAMESM state = idle;

int pinIn = 0;


unsigned char timer_control(int mode)
{
	switch(mode)
	{
	case 0:
	TCCR1B = 0b00001101;
	return 1;
	break;
	
	case 1:
	TCCR1B = 0b00000000;
	return 2;
	break;
	
	default:
	return 0;
	}
}





void start_game_SM(void)
{
	
	
	
	switch(state)
	{
		case idle:
		
		while(START_MASK != read_start_button());
		
		timer_control(start);
		led_mode(LEDMODE5);	
		while(HWREGTIMERINT != 1);
			HWREGTIMERINT=0;
			state = state1;
		break;
		
		case state1:
		led_mode(LEDMODE1);
		while(HWREGTIMERINT != 1);
			HWREGTIMERINT=0;
			state = state2;
		break;
		
		case state2:
		led_mode(LEDMODE2);
		while(HWREGTIMERINT != 1);
			HWREGTIMERINT=0;
			state =state3;
		break;
		
		case state3:
		led_mode(LEDMODE3);
		while(HWREGTIMERINT != 1);
			HWREGTIMERINT=0;
			state = state4;
		break;
		
		case state4:
		led_mode(LEDMODE4);
		while(HWREGTIMERINT != 1);
			HWREGTIMERINT=0;
			state = state5;
		break;
		
		case state5:
		led_mode(LEDMODE0);
		timer_control(stop);
		HWREGEXTINT=0;
		players_button(on);
		
		while(HWREGEXTINT != 1 );
		pinIn = PINB;
			if(pinIn & P1MASK)
			{
				HWREGEXTINT = 0;
				players_button(off);
				led_mode(LEDMODE7);
			}
			if(pinIn & P2MASK)
				{
				HWREGEXTINT = 0;
				players_button(off);
				led_mode(LEDMODE6);
				}
		state = idle;
		break;
		
	}
	
	
	
}