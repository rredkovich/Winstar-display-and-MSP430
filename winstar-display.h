#ifndef WINSTARDISPLAY_H_
#define WINSTARDISPLAY_H_

#include "delay.h"
#include <stdint.h>

//data bus structure
	typedef struct {		
		uint8_t *DB0[2]; //where DB0[1]=&PxOUT DB0[2]=BITx
		uint8_t *DB1[2];
		uint8_t *DB2[2];
		uint8_t *DB3[2];
		uint8_t *DB4[2];
		uint8_t *DB5[2];
		uint8_t *DB6[2];
		uint8_t *DB7[2];
		//volatile uint8_t *port;
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
