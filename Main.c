     /**********************  Arduino Baremetal C Cabin Control Systems  ******************************/
     /*********************                  Authors                      *****************************/
     /********************                                                 ****************************/
     /*******************                                                   ***************************/
     /******************	                                             **************************/
     /*****************	                                                      *************************/
     /****************	                                                       ************************/ 
	
#include <stdbool.h>
#include <avr/io.h> 
#include <avr/pgmspace.h>
#include <avr/cores.h>
#include <util/delay.h>
#include "processes.h"
#include <stdint.h>       // needed for uint8_t
#include <avr/interrupt.h>

int seconds = 0; //counts seconds through timer and interrupt

void Main(){
	int y = 0;
	int temp = 0;
	
	OCR1A = 0x3D08;
	TCCR1B |= (1 << WGM12); // Mode 4, CTC on OCR1A
    	
	TIMSK1 |= (1 << OCIE1A);  //Set interrupt on compare match
   
	TCCR1B |= (1 << CS12) | (1 << CS10); // set prescaler to 1024 and start the timer
    
	sei(); // enable interrupts
    
	
	//run the process as an infinite loop that starts when the machine starts, and stops when the machine is off
	while (!y){
		void Light_warning_init();
		void Light_allclear_init();
		void Light_seninit();
		void Light_warning_on();
		void Light_warning_off();
		void Light_allclear_on();	
		void Light_allclear_off();
		void LightSen();

		//returns 1 or 2 if temp is not room temp, 0 if room temp.
      	temp = tempSensor();
	}

int tempSensor()
{
	//initialize values
	int sensorValue = 0;
	int state = 0;
  
  	//Read analog input 0
  	sensorValue = ADCsingleREAD(0);
  
  	//return current temperature state
  	if(sensorValue > 155)
  	{
  		state = 2;
  	}
  	else if(sensorValue < 135)
  	{
  		state = 1;
  	}
  	else
  	{
    	state = 0;
  	}
  
  	return state;
}

int ADCsingleREAD(uint8_t adctouse){
	
    	int ADCval;

    	ADMUX = adctouse;         // use inputted ADC
    	ADMUX |= (1 << REFS0);    // use AVcc as the reference
    	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution
    
    	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale for 8Mhz
    	ADCSRA |= (1 << ADEN);    // Enable the ADC

    	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

    	while(ADCSRA & (1 << ADSC));      // This line waits for the ADC to finish 

    	ADCval = ADCL;
    	ADCval = (ADCH << 8) + ADCval;    // ADCH is read so ADC can be updated again

    	return ADCval;
}
	
ISR (TIMER1_COMPA_vect)
{
  	seconds++; //every second this interrupt will go off and increment seconds.
}
