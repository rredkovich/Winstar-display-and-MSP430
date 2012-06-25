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
			P2OUT &= ~RS;
			P2OUT &= ~RW;
			P1OUT &= ~DB7;
			P1OUT &= ~DB6;
			P1OUT &= ~DB5;
			P1OUT &= ~DB4;
			P1OUT |= DB3;
			P2OUT |= DB2;
			P2OUT |= DB1;
			P1OUT |= DB0;
			
			void run (readWrite *rw);
			
	//DELAY_MS (10);
	
		//Display clear
			P2OUT &= ~RS;
			P2OUT &= ~RW;
			P1OUT &= ~DB7;
			P1OUT &= ~DB6;
			P1OUT &= ~DB5;
			P1OUT &= ~DB4;
			P1OUT &= ~DB3;
			P2OUT &= ~DB2;
			P2OUT &= ~DB1;
			P1OUT |= DB0;
			
			void run (readWrite *rw);
		
		DELAY_MS (8);
			
		//Entry mode set
			P2OUT &= ~RS;
			P2OUT &= ~RW;
			P1OUT &= ~DB7;
			P1OUT &= ~DB6;
			P1OUT &= ~DB5;
			P1OUT &= ~DB4;
			P1OUT &= ~DB3;
			P2OUT |= DB2;
			P2OUT |= DB1;
			P1OUT &= ~DB0;
			
			void run (readWrite *rw);
			
		//DELAY_MS (10);
}