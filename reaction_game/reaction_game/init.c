/*
 * init.c
 *
 * Created: 04-04-2016 17:12:33
 *  Author: Jacob Roesen
 */

#include <avr/io.h>
#include "init.h"





void init_timer(void)
{
		TCCR1A = 0b00000000;
		
		OCR1A = 976;
		TIMSK |= 0b01000000;
}

void ext_interrupt_init(void)
{
	GIMSK = 0b00100000;
	
}

void init_ports(void)
{
	DDRB = 0b00001111; // setting PORTB PB0-PB3: Output, PB4-PB7: Input
	DDRD = 0b00001111; // setting PORTD PD0-PD3: Output, PD4-PD6: Input
	PORTB = 0b00000000; // Setting power on value portB PB0-PB3:on(0)
	PORTD = 0b00000000; // Setting power on value portD PD0-PD3:on(0)
}

void init_system(void)
{
	init_timer();
	ext_interrupt_init();
	init_ports();
}