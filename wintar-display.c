void run (rw *rwImplementation);
	
void initialize (dataBus *db, readWrite *rw){
	

//initalization
		//function set
			*(rw->port) &= ~rw->RS; 	// эта хрень делает на ноге RS нуль
			*(rw->port) &= ~rw->RW;
			*( &= ~DB7;
			P1OUT &= ~DB6;
			P1OUT |= DB5;	//а эта хрень делает на ноге DB5 единицу
			P1OUT |= DB4;
			P1OUT |= DB3;
			P2OUT |= DB2;
			P2OUT |= DB1; 	//russian font
			P1OUT &= ~DB0;	//russian font
			
			//read command
			P2OUT  |= E;
			DELAY_MS(250);
			P2OUT &= ~E;
	
	//DELAY_MS (10);			//задержка в мс
	
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
			
			//read command
			P2OUT  |= E;
			DELAY_MS (250);
			P2OUT &= ~E;
			
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
			
			//read command
			P2OUT  |= E;
			DELAY_MS (250);
			P2OUT &= ~E;
		
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
			
			//read command
			P2OUT  |= E;
			DELAY_MS (250);
			P2OUT &= ~E;
			
		//DELAY_MS (10);
}