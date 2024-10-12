#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "keyboard.h"


int main()
{
	led_init('B');
	kb_init('A');

	while(1){

		get_key('m');

	}

	return 0;
}