#include "winstar-display.h"


void run (dataBus *db){
	DELAY_MS(50);
	*(db->E.port) |= db->E.pin;
	DELAY_US (270);
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
	*(db->DB1.port) |= db->DB1.pin; 	//cursor on/off
	*(db->DB0.port) |= db->DB0.pin;	//cursor blinks / doesn't blinks
			
	run (db);
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
}

void printSymbol (dataBus *db, unsigned char symbol){
	if (symbol == '0') displaySymbolWithCode (db, 0x30);
	else if (symbol =='1') displaySymbolWithCode (db, 0x31);
	else if (symbol =='2') displaySymbolWithCode(db, 0x32);
	else if (symbol =='3') displaySymbolWithCode(db, 0x33);
	else if (symbol =='4') displaySymbolWithCode(db, 0x34);
	else if (symbol =='5') displaySymbolWithCode(db, 0x35);
	else if (symbol =='6') displaySymbolWithCode(db, 0x36);
	else if (symbol =='7') displaySymbolWithCode(db, 0x37);
	else if (symbol =='8') displaySymbolWithCode(db, 0x38);
	else if (symbol =='9') displaySymbolWithCode(db, 0x39);
	else if (symbol =='.') displaySymbolWithCode(db, 0x2E);
	else if (symbol ==',') displaySymbolWithCode(db, 0x2C);

	else if (symbol =='A') displaySymbolWithCode(db, 0x41);
	else if (symbol =='B') displaySymbolWithCode(db, 0x42);
	else if (symbol =='C') displaySymbolWithCode(db, 0x43);
	else if (symbol =='D') displaySymbolWithCode(db, 0x44);
	else if (symbol =='E') displaySymbolWithCode(db, 0x45);
	else if (symbol =='F') displaySymbolWithCode(db, 0x46);
	else if (symbol =='G') displaySymbolWithCode(db, 0x47);
	else if (symbol =='H') displaySymbolWithCode(db, 0x48);
	else if (symbol =='I') displaySymbolWithCode(db, 0x49);
	else if (symbol =='J') displaySymbolWithCode(db, 0x4A);
	else if (symbol =='K') displaySymbolWithCode(db, 0x4B);
	else if (symbol =='L') displaySymbolWithCode(db, 0x4C);
	else if (symbol =='M') displaySymbolWithCode(db, 0x4D);
	else if (symbol =='N') displaySymbolWithCode(db, 0x4E);
	else if (symbol =='O') displaySymbolWithCode(db, 0x4F);
	else if (symbol =='P') displaySymbolWithCode(db, 0x50);
	else if (symbol =='Q') displaySymbolWithCode(db, 0x51);
	else if (symbol =='R') displaySymbolWithCode(db, 0x52);
	else if (symbol =='S') displaySymbolWithCode(db, 0x53);
	else if (symbol =='T') displaySymbolWithCode(db, 0x54);
	else if (symbol =='U') displaySymbolWithCode(db, 0x55);
	else if (symbol =='V') displaySymbolWithCode(db, 0x56);
	else if (symbol =='W') displaySymbolWithCode(db, 0x57);
	else if (symbol =='X') displaySymbolWithCode(db, 0x58);
	else if (symbol =='Y') displaySymbolWithCode(db, 0x59);
	else if (symbol =='Z') displaySymbolWithCode(db, 0x5A);
	else if (symbol =='[') displaySymbolWithCode(db, 0x5B);
	else if (symbol ==']') displaySymbolWithCode(db, 0x5D);
	}
