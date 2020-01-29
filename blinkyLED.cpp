/*
 * BlinkyLED.cpp
 *
 * Created: 29.01.2020 15:54:22
 * Author : David Monschein
 */ 

#include "sam.h"

void delay (void){
	for (volatile uint16_t x=0; x<65535;x++){
		asm ("nop");
	}
}


int main(void){
    /* Initialize the SAM system */
    SystemInit();
	REG_PIOC_PER |= PIO_PER_P15;	//Enable PIO-Controller
	REG_PIOC_OER |= PIO_PER_P15; //Enable As Output [OER = Enable, ODR = Disable]
    /* Replace with your application code */
    while (1){
		REG_PIOC_SODR |= PIO_PER_P15;	//set high
		delay();
		REG_PIOC_CODR |= PIO_PER_P15;	//set low
		delay();
    }
}
