#include <avr/io.h>
#include <util/delay.h>
#include <avr/cores.h>
#include <stdbool.h>
#include "processes.h"


//initializes the warning diode
void warning_init(){
	
	DDRB |= _BV(DDB);
	
}

//initializes the all clear diode
void allclear_init(){
	
	DDRB |= _BV(DDB);
	
}


//turns on the warning diode
void Light_warning_on(){
	
	PORTB |= _BV(PORTB);
	
}

//turns off warning diode
void Light_warning_off(){
	
	PORTB &= ~_BV(PORTB);
}

//turns on all clear diode
void Light_allclear_on(){
	
	PORTB |= _BV(PORTB);
	
}


//turns off all clear diode
void Light_allclear_off(){
			
	PORTB &= ~_BV(PORTB);
	
}
