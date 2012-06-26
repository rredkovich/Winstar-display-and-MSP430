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
	
	dataBus db;
	readWrite rw;
	
	
	//задаем dataBus
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

	//задаем readWrite
	rw.RS = BIT5;
	rw.RW = BIT4;
	rw.E = BIT3;
	rw.port = &P2OUT;
	
	initialize (&db, &rw);
	
	while(1);
		
};
