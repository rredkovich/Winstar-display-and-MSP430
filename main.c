#include <msp430.h>
#include "winstar-display.h"


int main () {
	
	WDTCTL = WDTPW + WDTHOLD; 	//Stop watchdog timer
	BCSCTL1 = CALBC1_8MHZ;		//Frequency have been set
	DCOCTL = CALDCO_8MHZ;		//Frequency have been set
	
	struct dataBus db;
	struct readWrite rw;
	
	
	//задаем dataBus
	db.DB0[0] = &P1OUT;
	db.DB0[1] = BIT0;
	
	db.DB1[0] = &P2OUT;
	db.DB1[1] = BIT1;
	
	db.DB2[0] = &P2OUT;
	db.DB2[1] = BIT2;
	
	db.DB3[0] = &P1OUT;
	db.DB3[1] = BIT3;
	
	db.DB4[0] = &P1OUT;
	db.DB4[1] = BIT4;
	
	db.DB5[0] = &P1OUT;
	db.DB5[1] = BIT5;
	
	db.DB6[0] = &P1OUT;
	db.DB6[1] = BIT6;
	
	db.DB7[0] = &P1OUT;
	db.DB7[1] = BIT7;

	//задаем readWrite
	rw.RS = BIT5;
	rw.RW = BIT4;
	rw.E = BIT3;
	rw.port = &P2OUT;
	
	
};
