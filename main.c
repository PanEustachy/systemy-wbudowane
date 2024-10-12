#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "keyboard.h"


int main()
{

	// while (1)
	// {
	// 	DDRB = 0xFF;
	// 	PORTB = 0x0F;
	// 	_delay_ms(500);
	// 	PORTB = 0xF0;
	// 	_delay_ms(500);

	led_init('B');
	kb_init('A');


	while(1){

		get_key('m');

	}

	return 0;
}