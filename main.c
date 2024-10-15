#include <avr/io.h>
#include <util/delay.h>
#include "keyboard.h"
#define F_CPU 16000000UL
int main (void){
	
	led_init('b');
	kb_init('a');

	while(1){
		led_set(get_key('m'));
		_delay_ms(50);
	}
	

	return 0;
}