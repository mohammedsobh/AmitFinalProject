/*
 * UltraSonic.h
 *
 * Created: 6/11/2022 3:09:52 PM
 *  Author: eng_s
 */ 
#include "STD_types.h"
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include<string.h>
#include <stdlib.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "timer/timer.h"


#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGER        0
#define   ECHO          3




#endif /* ULTRASONIC_H_ */
