/*
 * UltraSonic.c
 *
 * Created: 6/11/2022 3:09:22 PM
 *  Author: nada
 */ 
#include "UltraSonic.h"

Uint8 TimerOverflow = 0;

TimerControl UltraSonicTimer;

void UltraSonic_init(void){
	UltraSonicTimer.TimerSelect = TIMER1;
	UltraSonicTimer.TimerMode = TIMER_NORMAL_MODE;
	UltraSonicTimer.TimerInterruptSelect = TIMER1_Input_Capture_Interrupt_En;
	UltraSonicTimer.TimerPrescaler = TimerPrescaler_0;
	DIO_SetPinDir(TRIGER_PORT,TRIGER,DIO_PIN_DIR_OUTPUT);
}


void UltraSonic_triger(void){
	DIO_SetPinVal(TRIGER_PORT,TRIGER,DIO_PIN_HIGH);
	_delay_us(10);
	DIO_SetPinVal(TRIGER_PORT,TRIGER,DIO_PIN_LOW);
	TCNT1 = 0;	/* Clear Timer counter */
	UltraSonic_SetCaptureEdge(TIMER_RISING_CAPTURE);
	Timer_ClearFlage(&UltraSonicTimer,TIMER_ICP_FALG);
	Timer_ClearFlage(&UltraSonicTimer,TIMER_OVERFLOW_FALG);
}

void UltraSonic_SetCaptureEdge(Uint8 Rising_Falling){
	
	Timer_SetRisingFallingEdge(&UltraSonicTimer,Rising_Falling);
}

Float64 UltraSonic_Distance(void)
{
	Uint8 count = 0;
	Uint8 distance = 0;
	UltraSonic_triger();
	while ((TIFR & (1 << 5)) == 0);/* Wait for rising edge */
	TCNT1 = 0;	/* Clear Timer counter */
	UltraSonic_SetCaptureEdge(TIMER_FALLING_CAPTURE);
	Timer_ClearFlage(&UltraSonicTimer,TIMER_ICP_FALG);
	Timer_ClearFlage(&UltraSonicTimer,TIMER_OVERFLOW_FALG);
	TimerOverflow = 0;/* Clear Timer overflow count */

	while ((TIFR & (1 << 5)) == 0);/* Wait for falling edge */
	count = ICR1 + (65535 * TimerOverflow);	/* Take count */
	/* 16MHz Timer freq, sound speed =343 m/s */
	distance = (double)count / 466.47;
	return distance;
}
 

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}
