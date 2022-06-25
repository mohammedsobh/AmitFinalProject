/*
 * Timer.h
 *
 * Created: 3/30/2022 10:49:34 PM
 *  Author: mohammed sobh
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define null ((void*) 0X00)

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "Atmega32PortsRegister.h"
#include "DIO.h"
#include "TimerCnfg.h"
#include <avr/interrupt.h>

#define TIMER0			0
#define TIMER1			1
#define TIMER2			2

#define TIMER_NORMAL_MODE					0
#define TIMER_CTC_MODE						1
#define TIMER_PHASE_CORRECT_8BIT_PWM_MODE	2
#define TIMER_FAST_PWM_MODE					3

#define TIMER_COMPARETOR_NORMAL				0
#define TIMER_COMPARETOR_TOGGLE				1
#define TIMER_COMPARETOR_CLR				2
#define TIMER_COMPARETOR_SET				3

#define TIMER_ICP_FALG					1
#define TIMER_OVERFLOW_FALG				2

#define TIMER1_COMPARETOR_A				0
#define TIMER1_COMPARETOR_B				1
#define TIMER1_INPUT_CAPTURE			2

#define TIMER_RISING_CAPTURE			1
#define TIMER_FALLING_CAPTURE			0

#define TimerPrescaler_0				1
#define TimerPrescaler_8				8
#define TimerPrescaler_32				32
#define TimerPrescaler_64				64
#define TimerPrescaler_128				128
#define TimerPrescaler_256				256
#define TimerPrescaler_1024				1024

#define TIMER1_Input_Capture_Interrupt_En				1				
#define TIMER1_Output_CompareA_Match_Interrupt_En		2
#define TIMER1_Output_CompareB_Match_Interrupt_En		3
#define TIMER1_Overflow_Interrupt_Enable				4



void Timer_Init(TimerControl*);

void Timer_Start(TimerControl*);

void Timer_Stop(TimerControl*);

void Timer_SetDelay(TimerControl*,Uint32 Delay_Ms);

void Timer_SetINTERUPPT(TimerControl* TimerC,Uint32 InterruptSelect);

void Timer_SetRisingFallingEdge(TimerControl* TimerC,Uint8 Rising_Falling);

void Timer_ClearFlage(TimerControl* TimerC,Uint8 Flag);

void SetCallBack(TimerControl*,void (*P_Fn)(void));

#endif /* TIMER_H_ */