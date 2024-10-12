#include "keyboard.h"
// #include <stdio.h>

#include <stdio.h>

//przypisanie zmiennym uniwersalnym odpowiedniego portu
void led_init(char led_port)
{   set_IO_registers(led_port);
    DDRLED = DDR;
    PORTLED = PORT;
    *DDRLED = 0xFF; //ustawienie ledów na wyjście
}

void led_set(char output)
{
    *PORTLED = output;
}

//przypisanie zmiennym uniwersalnym odpowiedniego portu
void set_IO_registers(char port)
{
    switch (port)
    {
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

void kb_init(char kb_port)
{
    set_IO_registers(kb_port);
    *DDR = 0xF0;
    *PORT = 0x0F;
}

unsigned char get_key(char kb_size)
{
    //sprawdzenie wierszy
    *DDR = 0xF0;
    *PORT = 0x0F;
    char kb1 = *PIN;
    //jeżeli wiersz jest wciśnięty
    if (kb1 != 0x0F)
    {
        // sprawdzenie kolumn
        *DDR = 0x0F;
        *PORT = 0xF0;
        char kb2 = *PIN;

        //wyzerowanie zmiennej przechowującej stan klawiszy
        char out = 0x00;
        //ustawienie stanu wierszy i kolumn w zmiennej wyjściowej
        out |= kb1;
        out |= kb2;
        if (kb_size == 'M' || kb_size == 'm')   //jeżeli klawiatura mała
        {
            //przypisanie odpowiednich wartości danemu klawiszowi
            switch (out)
            {
            case 0b11101110:
                out = '1';
                break;

            case 0b11101101:
                out = '4';
                break;

            case 0b11101011:
                out = '7';
                break;

            case 0b11100111:
                out = '/';
                break;
            default:
                out = 0x00;
            }
        }
        else if(kb_size == 'W' || kb_size == 'w')//jeżeli klawiatura duża
        {
            //przypisanie odpowiednich wartości danemu klawiszowi
            switch (out)
            {
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
            default:
                out = 0x00;
            }
        }
        // wyświetlenie stanu kalwiatury na tablicy ledów
        led_set(out);
    }
}