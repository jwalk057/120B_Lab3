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
	DDRC = 0xFF; PORTC=0x00; //Output C

    /* Insert your solution below */
    while (1) {
	unsigned char fuel_Lvl = 0x00;
        unsigned char tmpC = 0x00;
	unsigned char keyIgn = 0x00;
	unsigned char driverSeat = 0x00;
	unsigned char driver_S_Belt = 0x00;

	keyIgn = (PINA & 0x10);
	driverSeat = (PINA & 0x20);
	driver_S_Belt = (PINA & 0x40);
	fuel_Lvl = (PINA & 0x0F);

	if(keyIgn && driverSeat && !driver_S_Belt){tmpC = 0x80;}
	if(fuel_Lvl <= 0x04||fuel_Lvl == 0x00){tmpC = tmpC | 0x40;}
	else if(fuel_Lvl <= 0x02){tmpC = tmpC | 0x20;}
	else if(fuel_Lvl <= 0x04){tmpC = tmpC | 0x30;}
	else if(fuel_Lvl <= 0x06){tmpC = tmpC | 0x38;}
	else if(fuel_Lvl <= 0x09){tmpC = tmpC | 0x3C;}
	else if(fuel_Lvl <= 0x0C){tmpC = tmpC | 0x3E;}
	else{tmpC = tmpC | 0x3F;}
	PORTC = tmpC;
    }
    return 1;
}
