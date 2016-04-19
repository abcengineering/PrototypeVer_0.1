/*
 * game.h
 *
 * Created: 24-03-2016 15:42:09
 *  Author: Jacob Roesen
 */ 


enum GAMETIMER
{
	start,
	stop
	
	};
	
enum GAMESM
{
	idle,
	state1,
	state2,
	state3,
	state4,
	state5
	
	};


//variabler



#ifndef GAME_H_
#define GAME_H_


// Defines whats mode LED' are in. x=OFF o=ON
									//	PORTB | PORTD
								//BIT	0123  | 3210
#define LEDMODE0 0	// Mode 0,LEDS:		xxxx  | xxxx
#define LEDMODE1 1	// Mode 1,LED:		oxxx  | xxxo
#define LEDMODE2 2	// Mode 2,LED:		xoxx  | xxox
#define LEDMODE3 3	// Mode 3,LED:		xxox  | xoxx
#define LEDMODE4 4	// Mode 4,LED:		xxxo  | oxxx
#define LEDMODE5 5	// Mode 5,LED:		oooo  | oooo
#define LEDMODE6 6	// Mode 6,LED:		xxxx  | oooo
#define LEDMODE7 7	// Mode 7,LED:		oooo  | xxxx

#define P1MASK 0b01000000
#define P2MASK 0b10000000






unsigned char timer_control(int);

void start_game_SM(void);





#endif /* GAME_H_ */