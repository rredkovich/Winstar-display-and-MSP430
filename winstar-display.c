#include "winstar-display.h"
//Похоже задание DB в виде массива было ошибкой, так как оба члена должны
//быть типа массива, а по факту первый - ссылка на PxOUT, второй целое число.
//нужно переделать DB в структуры.
//
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
			void run (readWrite *rw);
	
		//Display on/off
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->DB7[0]) &= ~db->DB7[1];
			*(db->DB6[0]) &= ~db->DB6[1];
			*(db->DB5[0]) &= ~db->DB5[1];	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4[0]) &= ~db->DB4[1];
			*(db->DB3[0]) |= db->DB3[1];
			*(db->DB2[0]) |= db->DB2[1];
			*(db->DB1[0]) |= db->DB1[1]; 	//russian font
			*(db->DB0[0]) |= db->DB0[1];
			
			void run (readWrite *rw);
			
	//DELAY_MS (10);
	
		//Display clear
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->DB7[0]) &= ~db->DB7[1];
			*(db->DB6[0]) &= ~db->DB6[1];
			*(db->DB5[0]) &= ~db->DB5[1];	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4[0]) &= ~db->DB4[1];
			*(db->DB3[0]) &= ~db->DB3[1];
			*(db->DB2[0]) &= ~db->DB2[1];
			*(db->DB1[0]) &= ~db->DB1[1]; 	//russian font
			*(db->DB0[0]) |= db->DB0[1];
			
			void run (readWrite *rw);
		
		DELAY_MS (8);
			
		//Entry mode set
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->DB7[0]) &= ~db->DB7[1];
			*(db->DB6[0]) &= ~db->DB6[1];
			*(db->DB5[0]) &= ~db->DB5[1];	//а эта хрень делает на ноге DB5 единицу
			*(db->DB4[0]) &= ~db->DB4[1];
			*(db->DB3[0]) &= ~db->DB3[1];
			*(db->DB2[0]) |= db->DB2[1];
			*(db->DB1[0]) |= db->DB1[1]; 	//russian font
			*(db->DB0[0]) &= ~db->DB0[1];
			
			void run (readWrite *rw);
			
		//DELAY_MS (10);
}