//Simbols library
#ifndef WINSTARDISPLAYSIMBOLS_H_
#define WINSTARDISPLAYSIMBLOS_H_

#include "winstar-display.h"

void displaySymbol (uint8_t byte);
{
	*(db.RS.port) |= db.RS.pin;
	*(db.RW.port) &= ~db.RW.pin;

	if (byte & 0x80){
		*(db.DB7.port) |= db.DB7.pin;
	} else {
		*(db.DB7.port) &= ~db.DB7.pin;
	}

	if (byte & 0x40) {
		*(db.DB6.port) |= db.DB6.pin;
	} else {
		*(db.DB6.port) &= ~db.DB6.pin;
	}

	if (byte & 0x20) {
		*(db.DB5.port) |= db.DB5.pin;
	} else {
		*(db.DB5.port) &= ~db.DB5.pin;
	}

	if (byte & 0x10) {
		*(db.DB4.port) |= db.DB4.pin;
	} else{
		*(db.DB4.port) &= ~db.DB4.pin;
	}

	if (byte & 0x8) {
		*(db.DB3.port) |= db.DB3.pin;
	} else {
		*(db.DB3.port) &= ~db.DB3.pin;
	}

	if (byte & 0x4){
		*(db.DB2.port) |= db.DB2.pin;
	} else {
		*(db.DB2.port) &= ~db.DB2.pin;
	}

	if (byte & 0x2) {
		*(db.DB1.port) |= db.DB1.pin;
	} else {
		*(db.DB1.port) &= ~db.DB1.pin;
	}

	if (byte & 0x1) {
		*(db.DB0.port) |= db.DB0.pin;	
	} else {
		*(db.DB0.port) &= ~db.DB0.pin;	
	}

	run (&db);
}


	*(db.DB7.port) &= ~db.DB7.pin;
	*(db.DB6.port) &= ~db.DB6.pin;
	*(db.DB5.port) |= db.DB5.pin;
	*(db.DB4.port) |= db.DB4.pin;
	*(db.DB3.port) |= db.DB3.pin;
	*(db.DB2.port) |= db.DB2.pin;
	*(db.DB1.port) |= db.DB1.pin;
	*(db.DB0.port) |= db.DB0.pin;	
	int i;
  for(i = 0; i < 8; i++)
  {
    onewire_write_bit(ow, byte & 1);
    byte >>= 1;
}






void onewire_write_byte(onewire_t *ow, uint8_t byte)
{
  int i;
  for(i = 0; i < 8; i++)
  {
    onewire_write_bit(ow, byte & 1);
    byte >>= 1;
  }
}

#endif /*WINSTARDISPLAYSIMBOLS_H_*/