#include "winstar-display.h"


void run (dataBus *db){
	DELAY_MS(50);
	*(db->E.port) |= db->E.pin;
	DELAY_US (10);
	*(db->E.port) &= ~(db->E.pin);
	//DELAY_MS(20);
	}

void functionSet (dataBus *db){
	*(db->RS.port) &= ~db->RS.pin; 	
	*(db->RW.port) &= ~db->RW.pin;
	*(db->DB7.port) &= ~db->DB7.pin;
	*(db->DB6.port) &= ~db->DB6.pin;
	*(db->DB5.port) |= db->DB5.pin;	
	*(db->DB4.port) |= db->DB4.pin;		//set interface datalenght
	*(db->DB3.port) |= db->DB3.pin;		//set number of lines
	*(db->DB2.port) |= db->DB2.pin;		//sets character font
	*(db->DB1.port) |= db->DB1.pin; 	//first bit of character table
	*(db->DB0.port) &= ~db->DB0.pin;	//second bit of character table
			
    run (db); 
			
	//DELAY_MS(10);
}

void displayOnOff (dataBus *db) {
	*(db->RS.port) &= ~db->RS.pin;
	*(db->RW.port) &= ~db->RW.pin;
	*(db->DB7.port) &= ~db->DB7.pin;
	*(db->DB6.port) &= ~db->DB6.pin;
	*(db->DB5.port) &= ~db->DB5.pin;	
	*(db->DB4.port) &= ~db->DB4.pin;
	*(db->DB3.port) |= db->DB3.pin;
	*(db->DB2.port) |= db->DB2.pin;		//display on/off
	*(db->DB1.port) &= ~db->DB1.pin; 	//cursor on/off
	*(db->DB0.port) &= ~db->DB0.pin;	//cursor blinks / doesn't blinks
			
	run (db);
			
	//DELAY_MS (10);
}

void displayClear (dataBus *db){
	*(db->RS.port) &= ~db->RS.pin;
	*(db->RW.port) &= ~db->RW.pin;
	*(db->DB7.port) &= ~db->DB7.pin;
	*(db->DB6.port) &= ~db->DB6.pin;
	*(db->DB5.port) &= ~db->DB5.pin;	
	*(db->DB4.port) &= ~db->DB4.pin;
	*(db->DB3.port) &= ~db->DB3.pin;
	*(db->DB2.port) &= ~db->DB2.pin;
	*(db->DB1.port) &= ~db->DB1.pin; 	//russian font
	*(db->DB0.port) |= db->DB0.pin;
			
	run (db);
			
	//DELAY_MS (10);
}

void entryModeSet (dataBus *db){
	*(db->RS.port) &= ~db->RS.pin;
	*(db->RW.port) &= ~db->RW.pin;
	*(db->DB7.port) &= ~db->DB7.pin;
	*(db->DB6.port) &= ~db->DB6.pin;
	*(db->DB5.port) &= ~db->DB5.pin;	
	*(db->DB4.port) &= ~db->DB4.pin;
	*(db->DB3.port) &= ~db->DB3.pin;
	*(db->DB2.port) |= db->DB2.pin;
	*(db->DB1.port) |= db->DB1.pin; 	//russian font
	*(db->DB0.port) &= ~db->DB0.pin;	
						
	run (db);
			
	//DELAY_MS (10);
}
	
void initialize (dataBus *db){ //look at datasheet for initialization algorithm

	functionSet (db);
	displayOnOff (db);
	displayClear (db);	
	entryModeSet (db);	
}	

void displaySymbolWithCode (dataBus *db, volatile uint8_t byte) { //codes are in datasheet

	*(db->RS.port) |= db->RS.pin;
	*(db->RW.port) &= ~db->RW.pin;

	if (byte & 0x80){
		*(db->DB7.port) |= db->DB7.pin;
	} else {
		*(db->DB7.port) &= ~db->DB7.pin;
	}

	if (byte & 0x40) {
		*(db->DB6.port) |= db->DB6.pin;
	} else {
		*(db->DB6.port) &= ~db->DB6.pin;
	}

	if (byte & 0x20) {
		*(db->DB5.port) |= db->DB5.pin;
	} else {
		*(db->DB5.port) &= ~db->DB5.pin;
	}

	if (byte & 0x10) {
		*(db->DB4.port) |= db->DB4.pin;
	} else{
		*(db->DB4.port) &= ~db->DB4.pin;
	}

	if (byte & 0x8) {
		*(db->DB3.port) |= db->DB3.pin;
	} else {
		*(db->DB3.port) &= ~db->DB3.pin;
	}

	if (byte & 0x4){
		*(db->DB2.port) |= db->DB2.pin;
	} else {
		*(db->DB2.port) &= ~db->DB2.pin;
	}

	if (byte & 0x2) {
		*(db->DB1.port) |= db->DB1.pin;
	} else {
		*(db->DB1.port) &= ~db->DB1.pin;
	}

	if (byte & 0x1) {
		*(db->DB0.port) |= db->DB0.pin;	
	} else {
		*(db->DB0.port) &= ~db->DB0.pin;	
	}

	run (db);
	//DELAY_MS(10);
}

void returnHome (dataBus *db){ //Set DDRAM address to 0, returns shifted display to original position
	
	*(db->RS.port) &= ~db->RS.pin; 	
	*(db->RW.port) &= ~db->RW.pin;
	*(db->DB7.port) &= ~db->DB7.pin;
	*(db->DB6.port) &= ~db->DB6.pin;
	*(db->DB5.port) &= ~db->DB5.pin;	
	*(db->DB4.port) &= ~db->DB4.pin;
	*(db->DB3.port) &= ~db->DB3.pin;
	*(db->DB2.port) &= ~db->DB2.pin;
	*(db->DB1.port) |= db->DB1.pin; 	
	*(db->DB0.port) &= ~db->DB0.pin;	
			
	run (db); 
			
	//DELAY_MS(10);
	
	}

void shiftDisplay (dataBus *db) {
	*(db->RS.port) &= ~db->RS.pin; 	
	*(db->RW.port) &= ~db->RW.pin;
	*(db->DB7.port) &= ~db->DB7.pin;
	*(db->DB6.port) &= ~db->DB6.pin;
	*(db->DB5.port) &= ~db->DB5.pin;	
	*(db->DB4.port) |= db->DB4.pin;		
	*(db->DB3.port) |= db->DB3.pin;		//S/C
	*(db->DB2.port) |= db->DB2.pin;		//R/L
	*(db->DB1.port) &= ~db->DB1.pin; 	
	*(db->DB0.port) &= ~db->DB0.pin;	
			
    run (db); 
			
	//DELAY_MS(10);
}