/*
 * Motor.h
 *
 * Created: 6/17/2022 11:06:56 PM
 *  Author: eng_s
 */ 

#include "DIO.h"
#include "Giop.h"
#include "Atmega32PortsRegister.h"
#include "Timer.h"

#define MOTOR_PORT		DIO_PORTC
#define MOTOREN_PORT	DIO_PORTD
#define MOTOR1_PIN0		DIO_PIN_3
#define MOTOR1_PIN1		DIO_PIN_4
#define MOTOR2_PIN0		DIO_PIN_5
#define MOTOR2_PIN1		DIO_PIN_6
#define MOTOR1_ENPIN	DIO_PIN_7
#define MOTOR2_ENPIN	DIO_PIN_7

#ifndef MOTOR_H_
#define MOTOR_H_

void Motor_init(void);
void Motor_Speet(int);
void Motor_foroword(void);
void Motor_backword(void);
void Motor_Left(void);
void Motor_Right(void);
void Motor_Stop(void);

#endif /* MOTOR_H_ */