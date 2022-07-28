/*
 * UltraSonic.h
 *
 * Created: 6/11/2022 3:09:52 PM
 *  Author: nada
 */ 
#include "STD_types.h"

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#ifndef F_CPU
#define F_CPU 16000000UL // 8 MHz clock speed
#endif

#include "Atmega32PortsRegister.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Timer.h"


#define   TRIGER_PORT   DIO_PORTA
#define   ECHO_PULLUP   DIO_PORTD
#define   TRIGER        DIO_PIN_0
#define   ECHO          DIO_PIN_6

void UltraSonic_init(void);

void UltraSonic_triger(void);

void UltraSonic_SetCaptureEdge(Uint8);

Uint8 UltraSonic_Distance(void);

#endif /* ULTRASONIC_H_ */
