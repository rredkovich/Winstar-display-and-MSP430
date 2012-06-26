#include <msp430.h>
#include "winstar-display.h"

//Похоже задание DB в виде массива было ошибкой, так как оба члена должны
//быть типа массива, а по факту первый - ссылка на PxOUT, второй целое число.
//нужно переделать DB в структуры.
//

int main () {
	
	WDTCTL = WDTPW + WDTHOLD; 	//Stop watchdog timer
	BCSCTL1 = CALBC1_8MHZ;		//Frequency have been set
	DCOCTL = CALDCO_8MHZ;		//Frequency have been set
	
	P1SEL = 0x0; //P1 to digital I/O function
	P2SEL = 0x0; //P2 to digital I/O function
	
	P1DIR = 0xFF; //P1 to out
	P2DIR = 0xFF; //P2 to out
	
	
	dataBus db;
	readWrite rw;
	
	
	//dataBus pins
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

	//readWrite port and pins
	rw.RS = BIT5;
	rw.RW = BIT4;
	rw.E = BIT3;
	rw.port = &P2OUT;
	
	initialize (&db, &rw);
	
	//try display ? sign
	*(rw.port) |= rw.RS;
	*(rw.port) &= ~rw.RW;
	*(db.DB7.port) &= ~db.DB7.pin;
	*(db.DB6.port) &= ~db.DB6.pin;
	*(db.DB5.port) |= db.DB5.pin;
	*(db.DB4.port) |= db.DB4.pin;
	*(db.DB3.port) |= db.DB3.pin;
	*(db.DB2.port) |= db.DB2.pin;
	*(db.DB1.port) |= db.DB1.pin;
	*(db.DB0.port) |= db.DB0.pin;				
	
	run (&rw);
			
	//Display Я/Ю
	*(rw.port) |= rw.RS;
	*(rw.port) &= ~rw.RW;
	*(db.DB7.port) |= db.DB7.pin;
	*(db.DB6.port) &= ~db.DB6.pin;
	*(db.DB5.port) |= db.DB5.pin;
	*(db.DB4.port) |= db.DB4.pin;
	*(db.DB3.port) &= ~db.DB3.pin;
	*(db.DB2.port) &= ~db.DB2.pin;
	*(db.DB1.port) &= ~db.DB1.pin;
	*(db.DB0.port) &= ~db.DB0.pin;	
	
	run (&rw);
	
	while(1);
		
};
