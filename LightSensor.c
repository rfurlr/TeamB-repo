#include <avr/io.h>
#include <util/delay.h>
#include <avr/cores.h>
#include <stdbool.h>
#include "processes.h"

//initializes the light sensor
void Light_seninit(){

	DDRB |= _BV(DDB);
	
}

//initializes the warning diode
void Light_warning_init(){
	
	DDRB |= _BV(DDB);
	
}

//initializes the all clear diode
void Light_allclear_init(){
	
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

void LightSen(){

	warning_init();
	allclear_init();
	Light_seninit();
	
	if (ADCsingleRead(_BV(DDB)) > 75){
		warning_on();
		allclear_off();
	}
	else if(ADCsingleRead(_BV(DDB)) < 90){
		warning_on();
		allclear_off();
	}
	else 
		warning_off();
		allclear_on();	

}
