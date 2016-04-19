/*
 * game_io.h
 *
 * Created: 05-04-2016 16:40:46
 *  Author: Jacob Roesen
 */



#define START_MASK 0b00100000

enum PBUTTON
{
	on,
	off
	};


#ifndef GAME_IO_H_
#define GAME_IO_H_


// Prototypes

void players_button(int mode);


unsigned char read_start_button(void);


void led_mode(int);




#endif /* GAME_IO_H_ */

