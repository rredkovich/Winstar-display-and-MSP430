#include "winstar-display.h"


void run (readWrite *rw){
	*(rw->port) |= rw->E;
	DELAY_MS (250);
	*(rw->port) &= ~rw->E;
}
	
void initialize (dataBus *db, readWrite *rw){
	

//initalization
		//function set
			*(rw->port) &= ~rw->RS; 	// эта хрень делает на ноге RS нуль
			*(rw->port) &= ~rw->RW;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) |= db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) |= db->DB4.pin;
			*(db->DB3.port) |= db->DB3.pin;
			*(db->DB2.port) |= db->DB2.pin;
			*(db->DB1.port) |= db->DB1.pin; 	//russian font
			*(db->DB0.port) &= ~db->DB0.pin;	//russian font
			
			//read command
			//run (&rw); I don't find why this don't work
			*(rw->port) |= rw->E;
			DELAY_MS (250);
			*(rw->port) &= ~rw->E;
			
			DELAY_MS(10);
			
		//Display on/off
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) &= ~db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) &= ~db->DB4.pin;
			*(db->DB3.port) |= db->DB3.pin;
			*(db->DB2.port) |= db->DB2.pin;
			*(db->DB1.port) |= db->DB1.pin; 	//russian font
			*(db->DB0.port) |= db->DB0.pin;
			
			//run (&rw);
			*(rw->port) |= rw->E;
			DELAY_MS (250);
			*(rw->port) &= ~rw->E;
			
	DELAY_MS (10);
	
		//Display clear
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) &= ~db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) &= ~db->DB4.pin;
			*(db->DB3.port) &= ~db->DB3.pin;
			*(db->DB2.port) &= ~db->DB2.pin;
			*(db->DB1.port) &= ~db->DB1.pin; 	//russian font
			*(db->DB0.port) |= db->DB0.pin;
			
			//run (&rw);
			*(rw->port) |= rw->E;
			DELAY_MS (250);
			*(rw->port) &= ~rw->E;
			
			
		DELAY_MS (10);
			
		//Entry mode set
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->DB7.port) &= ~db->DB7.pin;
			*(db->DB6.port) &= ~db->DB6.pin;
			*(db->DB5.port) &= ~db->DB5.pin;	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4.port) &= ~db->DB4.pin;
			*(db->DB3.port) &= ~db->DB3.pin;
			*(db->DB2.port) |= db->DB2.pin;
			*(db->DB1.port) |= db->DB1.pin; 	//russian font
			*(db->DB0.port) &= ~db->DB0.pin;
			
			//run (&rw);
			*(rw->port) |= rw->E;
			DELAY_MS (250);
			*(rw->port) &= ~rw->E;
			
		DELAY_MS (10);
}