/*	Author: lab
 *  Partner(s) Name: Jeremy Walker
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

// PART 1

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA=0x00; //Input A
	DDRB = 0x00; PORTB=0x00; //Input B
	DDRC = 0xFF; PORTC=0x00; //Output C

	

    /* Insert your solution below */
    while (1) {
	unsigned char num_One_A = 0x00;
        unsigned char num_One_B = 0x00;
        unsigned char tmpC = 0x00;

	if(PINA & 0x01){num_One_A= num_One_A + 1;}
       	if(PINA & 0x02){num_One_A= num_One_A + 1;}
        if(PINA & 0x04){num_One_A= num_One_A + 1;}
       	if(PINA & 0x08){num_One_A= num_One_A + 1;}
	if(PINA & 0x10){num_One_A= num_One_A + 1;}
        if(PINA & 0x20){num_One_A= num_One_A + 1;}
        if(PINA & 0x40){num_One_A= num_One_A + 1;}
        if(PINA & 0x80){num_One_A= num_One_A + 1;}
	if(PINB & 0x01){num_One_B= num_One_B + 1;}
        if(PINB & 0x02){num_One_B= num_One_B + 1;}
        if(PINB & 0x04){num_One_B= num_One_B + 1;}
        if(PINB & 0x08){num_One_B= num_One_B + 1;}
        if(PINB & 0x10){num_One_B= num_One_B + 1;}
        if(PINB & 0x20){num_One_B= num_One_B + 1;}
        if(PINB & 0x40){num_One_B= num_One_B + 1;}
        if(PINB & 0x80){num_One_B= num_One_B + 1;}

	tmpC = num_One_A + num_One_B;
	PORTC = tmpC;
    }
    return 1;
}
