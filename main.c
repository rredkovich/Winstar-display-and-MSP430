#include <msp430.h>
#include "winstar-display.h"


int main () {
	
	WDTCTL = WDTPW + WDTHOLD; 	//Stop watchdog timer
	BCSCTL1 = CALBC1_8MHZ;		//Frequency have been set
	DCOCTL = CALDCO_8MHZ;		//Frequency have been set
	
	struct dataBus db;
	struct readWrite rw;
	
	
	
	ow.port_out = &P1OUT;
	ow.port_in = &P1IN;
	ow.port_ren = &P1REN;
	ow.port_dir = &P1DIR;
	ow.pin = BIT4;
	
	
};
