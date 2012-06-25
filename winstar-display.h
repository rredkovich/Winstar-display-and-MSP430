#ifndef WINSTARDISPLAY_H_
#define WINSTARDISPLAY_H_

#include "delay.h"
#include <stdint.h>
//comment for test of reverting in github

//data bus structure
	typedef struct {		
		volatile uint8_t *DB0[2]; //where DB0[1]=&PxOUT DB0[2]=BITx
		volatile uint8_t *DB1[2];
		volatile uint8_t *DB2[2];
		volatile uint8_t *DB3[2];
		volatile uint8_t *DB4[2];
		volatile uint8_t *DB5[2];
		volatile uint8_t *DB6[2];
		volatile uint8_t *DB7[2];
		//volatile uint8_t *port;
	} dataBus;
	
//read-write properties structure
	typedef struct {	 
		volatile uint8_t RS;
		volatile uint8_t RW;
		int E;
		volatile uint8_t *port;
	} readWrite;
		
//Run command
	void run (readWrite *rw);
	void initialize (dataBus *db, readWrite *rw);
		
		


#endif /*WINSTARDISPLAY_H_*/
