#ifndef WINSTARDISPLAY_H_
#define WINSTARDISPLAY_H_

#include "delay.h"
#include <stdint.h>
//comment for test of reverting in github

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

//Run command
	void run (dataBus *db);
	void initialize (dataBus *db);
		
		


#endif /*WINSTARDISPLAY_H_*/
