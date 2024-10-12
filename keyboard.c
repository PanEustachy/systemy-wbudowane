#include "keyboard.h"
// #include <stdio.h>

#include <stdio.h>

void led_init(char led_port){
        // PORTB = 0b00001111;

        set_IO_registers(led_port);

        // printf("led_init: 1\n");
        DDRLED = DDR;
        PORTLED = PORT;
        *DDRLED = 0xFF;
        *PORTLED = 0x0F;
        // printf("led_init: 2\n");

        _delay_ms(5000);
        // printf("led_init: 3\n");

        *PORTLED = 0x00;
        // printf("led_init: 4\n");
        _delay_ms(5000);

}

void led_set(char output){
    *PORTLED = output;
}

void set_IO_registers(char port){
    switch(port){
        case 'a':
        case 'A':
            DDR = &DDRA;
            PORT = &PORTA;
            PIN = &PINA;
            break;
        case 'b':
        case 'B':
            DDR = &DDRB;
            PORT = &PORTB;
            PIN = &PINB;
            PORTB = 0x02;
            break;
        case 'c':
        case 'C':
            DDR = &DDRC;
            PORT = &PORTC;
            PIN = &PINC;
            break;
        case 'd':
        case 'D':
            DDR = &DDRD;
            PORT = &PORTD;
            PIN = &PIND;
            break;
        default:
            break;
    }
}


void kb_init(char kb_port){
    set_IO_registers( kb_port );
    *DDR = 0xF0;
    *PORT = 0x0F;   
}

unsigned char get_key(char kb_size){
    // set_IO_registers(kb_port);
    *DDR = 0xF0;
    *PORT = 0x0F;
    char kb1 = *PIN;
    if (kb1 != 0x0F){
        *DDR = 0x0F;
        *PORT = 0xF0;
        char kb2 = *PIN;
    
        char out = 0x00;

        out |= kb1;
        out |= kb2;

        switch(out){
            case 0b11101110:
                out = '1';
                break;
            
            case 0b11011110:
                out = '2';
                break;
            
            case 0b10111110:
                out = '3';
                break;
            
            case 0b01111110:
                out = '+';
                break;
            case 0b11101101:
                out = '4';
                break;
            
            case 0b11011101:
                out = '5';
                break;
            
            case 0b10111101:
                out = '6';
                break;
            
            case 0b01111101:
                out = '-';
                break;
                
            case 0b11101011:
                out = '7';
                break;
            
            case 0b11011011:
                out = '8';
                break;
            
            case 0b10111011:
                out = '9';
                break;
            
            case 0b01111011:
                out = '*';
                break;
                
            case 0b11100111:
                out = '/';
                break;
            
            case 0b11010111:
                out = '0';
                break;
            
            case 0b10110111:
                out = '=';
                break;
            
            case 0b01110111:
                out = '.';
                break;
        }
    led_set(out);
    }


    // led_set(kb);

        // for(int i = 0; i<4;i++;)

    // }
    
}