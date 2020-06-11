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

void Main(){
	int y = 0;
	//run the process as an infinite loop that starts when the machine starts, and stops when the machine is off
	while (y < 2){
		void Light_warning_init();
		void Light_allclear_init();
		void Light_seninit();
		void Light_warning_on();
		void Light_warning_off();
		void Light_allclear_on();	
		void Light_allclear_off();
		void LightSen();

		
	}

	
	
}
