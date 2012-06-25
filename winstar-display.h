#ifndef WINSTARDISPLAY_H_
#define WINSTARDISPLAY_H_

#include "delay.h"

//data bus structure
	typedef struct {		
		uint8_t DB0;
		uint8_t DB1;
		uint8_t DB2;
		uint8_t DB3;
		uint8_t DB4;
		uint8_t DB5;
		uint8_t DB6;
		uint8_t DB7;
		volatile uint8_t *port;
	} dataBus;
	
//read-write properties structure
	typedef struct {	 
		uint8_t RS;
		uint8_t RW;
		uint8_t E;
		volatile uint8_t *port;
	} readWrite;
		
//Run command
	void run (readWrite *rw);
	void initialize (dataBus *db, readWrite *rw);
		
		


#endif /*WINSTARDISPLAY_H_*/
