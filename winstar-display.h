#ifndef WINSTARDISPLAY_H_
#define WINSTARDISPLAY_H_

#include "delay.h"
#include <stdint.h>

//busWire pin structure
typedef struct {
	volatile uint8_t *port;
	int pin;
} busWire;
	
//data bus structure
typedef struct {		
	busWire RS;
	busWire RW;
	busWire E;
	busWire DB0;
	busWire DB1;
	busWire DB2;
	busWire DB3;
	busWire DB4;
	busWire DB5;
	busWire DB6;
	busWire DB7;
	} dataBus;

void run (dataBus *db);
void functionSet (dataBus *db);
void displayOnOff (dataBus *db);
void displayClear (dataBus *db);
void entryModeSet (dataBus *db);
void initialize (dataBus *db);
void displaySymbolWithCode (dataBus *db, volatile uint8_t byte);
void returnHome (dataBus *db); 
void shiftDisplay (dataBus *db);
void printSymbol (dataBus *db, unsigned char symbol);

#endif /*WINSTARDISPLAY_H_*/
