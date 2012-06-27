#include "winstar-display.h"


void run (dataBus *db){
	*(db->E.port) |= db->E.pin;
	DELAY_MS (250);
	*(db->E.port) &= ~db->E.pin;
}
	
void initialize (dataBus *db){
//initalization
		//function set
			*(db->RS.port) &= ~db->RS.pin; 	// эта хрень делает на ноге RS нуль
			*(db->RW.port) &= ~db->RW.pin;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) |= db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) |= db->DB4.pin;
			*(db->DB3.port) |= db->DB3.pin;
			*(db->DB2.port) |= db->DB2.pin;
			*(db->DB1.port) |= db->DB1.pin; 	//russian font
			*(db->DB0.port) &= ~db->DB0.pin;	//russian font
			
			//read command
			//run (&db); I don't find why this don't work
			*(db->E.port) |= db->E.pin;
			DELAY_MS (250);
			*(db->E.port) &= ~db->E.pin;
			
			DELAY_MS(10);
			
		//Display on/off
			*(db->RS.port) &= ~db->RS.pin;
			*(db->RW.port) &= ~db->RW.pin;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) &= ~db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) &= ~db->DB4.pin;
			*(db->DB3.port) |= db->DB3.pin;
			*(db->DB2.port) |= db->DB2.pin;
			*(db->DB1.port) |= db->DB1.pin; 	//russian font
			*(db->DB0.port) |= db->DB0.pin;
			
			//run (&db);
			*(db->E.port) |= db->E.pin;
			DELAY_MS (250);
			*(db->E.port) &= ~db->E.pin;
			
	DELAY_MS (10);
	
		//Display clear
			*(db->RS.port) &= ~db->RS.pin;
			*(db->RW.port) &= ~db->RW.pin;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) &= ~db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) &= ~db->DB4.pin;
			*(db->DB3.port) &= ~db->DB3.pin;
			*(db->DB2.port) &= ~db->DB2.pin;
			*(db->DB1.port) &= ~db->DB1.pin; 	//russian font
			*(db->DB0.port) |= db->DB0.pin;
			
			//run (&db);
			*(db->E.port) |= db->E.pin;
			DELAY_MS (250);
			*(db->E.port) &= ~db->E.pin;
			
			
		DELAY_MS (10);
			
		//Entry mode set
			*(db->RS.port) &= ~db->RS.pin;
			*(db->RW.port) &= ~db->RW.pin;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) &= ~db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) &= ~db->DB4.pin;
			*(db->DB3.port) &= ~db->DB3.pin;
			*(db->DB2.port) |= db->DB2.pin;
			*(db->DB1.port) |= db->DB1.pin; 	//russian font
			*(db->DB0.port) &= ~db->DB0.pin;
			
			//run (&db);
			*(db->E.port) |= db->E.pin;
			DELAY_MS (250);
			*(db->E.port) &= ~db->E.pin;
			
		DELAY_MS (10);
};

void displaySymbol (dataBus *db, int byte) {

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