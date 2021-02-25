/*
 * led_driver.c
 *
 * Created: 2/21/2021 4:00:28 PM
 * Author : kiril
 */ 

#include <avr/io.h>
#include "led/led_driver.h"
#include "switch/switch_driver.h"

int main(void)
{
	led_create();
	init_keys();
    /* Replace with your application code */
    while (1) 
    {
		uint8_t inputOne = get_key(0);
		uint8_t inputTwo = get_key(1);
		
		set_logical_operators(inputOne, inputTwo);
    }
}

