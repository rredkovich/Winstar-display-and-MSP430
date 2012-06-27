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
}