#ifndef WINSTARDISPLAY_H_
#define WINSTARDISPLAY_H_

#include "delay.h"
#include <stdint.h>
//comment for test of reverting in github

//DBx pin structure
	typedef struct {
		volatile uint8_t *port;
		int pin;
	} DBx;
	
//data bus structure
	typedef struct {		
		DBx DB0;
		DBx DB1;
		DBx DB2;
		DBx DB3;
		DBx DB4;
		DBx DB5;
		DBx DB6;
		DBx DB7;			
	} dataBus;
	
//read-write properties structure
	typedef struct {	 
		int RS;
		int RW;
		int E;
		volatile uint8_t *port;
	} readWrite;
		
//Run command
	void run (readWrite *rw);
	void initialize (dataBus *db, readWrite *rw);
		
		


#endif /*WINSTARDISPLAY_H_*/
