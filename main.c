#include <msp430.h>
#include "winstar-display.h"
#include <stdbool.h>


int main () {
	
	WDTCTL = WDTPW + WDTHOLD; 	//Stop watchdog timer
	BCSCTL1 = CALBC1_8MHZ;		//Frequency have been set
	DCOCTL = CALDCO_8MHZ;		//Frequency have been set
	
	P1SEL = 0x0; //P1 to digital I/O function
	P2SEL = 0x0; //P2 to digital I/O function
	
	P1DIR = 0xFF; //P1 to out
	P2DIR = 0xFF; //P2 to out
	
	DELAY_MS(20);
	
	dataBus db;
	
	
	//dataBus pins
	db.RS.port = &P2OUT;
	db.RS.pin = BIT5;

	db.RW.port = &P2OUT;
	db.RW.pin = BIT4;

	db.E.port = &P2OUT;
	db.E.pin = BIT3;

	db.DB0.port = &P1OUT;
	db.DB0.pin = BIT0;
	
	db.DB1.port = &P2OUT;
	db.DB1.pin = BIT1;
	
	db.DB2.port = &P2OUT;
	db.DB2.pin = BIT2;
	
	db.DB3.port = &P1OUT;
	db.DB3.pin = BIT3;
	
	db.DB4.port = &P1OUT;
	db.DB4.pin = BIT4;
	
	db.DB5.port = &P1OUT;
	db.DB5.pin = BIT5;
	
	db.DB6.port = &P1OUT;
	db.DB6.pin = BIT6;
	
	db.DB7.port = &P1OUT;
	db.DB7.pin = BIT7;


	initialize (&db);
	
	displaySymbol (&db, 0x50); //displaying P
	displaySymbol (&db, 0x69); //displaying i
 	//displaySymbol (&db, 0x20); //displaying space
 	displaySymbol (&db, 0x3d); //displaying =
 	//displaySymbol (&db, 0x20); //displaying space
 	displaySymbol (&db, 0x33); //displaying 3
 	displaySymbol (&db, 0xd); //displaying .
 	displaySymbol (&db, 0x31); //displaying 1
 	displaySymbol (&db, 0x34); //displaying 4
 	
 	//_BIS_SR(LPM0_bits + GIE);
	while(1){};
		
};
