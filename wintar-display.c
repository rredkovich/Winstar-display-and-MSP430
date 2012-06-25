void run (readWrite *rw){
	*(rw->port)  |= rw->E;
	DELAY_MS (250);
	*(rw->port) &= ~rw->E;
};
	
void initialize (dataBus *db, readWrite *rw){
	

//initalization
		//function set
			*(rw->port) &= ~rw->RS; 	// эта хрень делает на ноге RS нуль
			*(rw->port) &= ~rw->RW;
			*(db->port) &= ~db->DB7;
			*(db->port) &= ~db->DB6;
			*(db->port) |= db->DB5;	//а эта хрень делает на ноге DB5 единицу
			*(db->port) |= db->DB4;
			*(db->port) |= db->DB3;
			*(db->port) |= db->DB2;
			*(db->port) |= db->DB1; 	//russian font
			*(db->port) &= ~DB0;	//russian font
			
			//read command
			void run (readWrite *rw);
	
		//Display on/off
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->port) &= ~db->DB7;
			*(db->port) &= ~db->DB6;
			*(db->port) &= ~db->DB5;
			*(db->port) &= ~db->DB4;
			*(db->port) |= db->DB3;
			*(db->port) |= db->DB2;
			*(db->port) |= db->DB1;
			*(db->port) |= db->DB0;
			
			void run (readWrite *rw);
			
	//DELAY_MS (10);
	
		//Display clear
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->port) &= ~db->DB7;
			*(db->port) &= ~db->DB6;
			*(db->port) &= ~db->DB5;
			*(db->port) &= ~db->DB4;
			*(db->port) &= ~db->DB3;
			*(db->port) &= ~db->DB2;
			*(db->port) &= ~db->DB1;
			*(db->port) |= db->DB0;
			
			void run (readWrite *rw);
		
		DELAY_MS (8);
			
		//Entry mode set
			*(rw->port) &= ~rw->RS;
			*(rw->port) &= ~rw->RW;
			*(db->port) &= ~db->DB7;
			*(db->port) &= ~db->DB6;
			*(db->port) &= ~db->DB5;
			*(db->port) &= ~db->DB4;
			*(db->port) &= ~db->DB3;
			*(db->port) |= db->DB2;
			*(db->port) |= db->DB1;
			*(db->port) &= ~db->DB0;
			
			void run (readWrite *rw);
			
		//DELAY_MS (10);
}