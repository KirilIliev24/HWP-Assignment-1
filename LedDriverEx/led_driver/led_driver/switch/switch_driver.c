/*
 * switch_driver.c
 *
 * Created: 2/24/2021 4:56:08 PM
 *  Author: Kiril
 */ 

#include <avr/io.h>
#include "switch_driver.h"

void init_keys()
{
	//configure pins 0 to 5 as input
	DDRC = 0xc0;
	
	//activates pull up resistors of PORTC
	PORTC = 0xff;
}

uint8_t get_key(uint8_t key_no)
{
	uint8_t status = PINC & _BV(key_no);
	//status 0 means button is pressed
	if (status == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}