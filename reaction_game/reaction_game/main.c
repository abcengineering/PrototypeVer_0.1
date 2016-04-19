/*
 * reaction_game.c
 *
 * Created: 21-03-2016 15:30:51
 * Author : jacob
 */ 

#include <avr/io.h>

#include <avr/interrupt.h>

#include "init.h"
#include "game.h"
#include "shared.h"








int main(void)
{
	cli();
	init_system();	
	sei();
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		start_game_SM();
    }
	
	
	
	return 0;
}


ISR(TIMER1_COMPA_vect)
{
	HWREGTIMERINT = 1;
	
}


ISR(PCINT_vect)
{
	HWREGEXTINT = 1;
	
	
	
}