/*
 * Servo.h
 *
 * Created: 6/11/2022 3:10:20 PM
 *  Author: nada
 */
#ifndef F_CPU
#define F_CPU 16000000UL // 8 MHz clock speed
#endif 
#include "Atmega32PortsRegister.h"
#include "STD_types.h"
#include <util/delay.h>


#ifndef SERVO_H_
#define SERVO_H_

void ServoInit(void);
void ServoGoToAngle(Sint8 Angle);



#endif /* SERVO_H_ */