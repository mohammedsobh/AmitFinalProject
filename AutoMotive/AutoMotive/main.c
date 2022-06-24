/*
 * AutoMotive.c
 *
 * Created: 6/11/2022 12:01:23 PM
 * Author : eng_s
 */
#ifndef F_CPU
#define F_CPU 16000000UL // 8 MHz clock speed
#endif
#include "DIO.h"
#include "Giop.h"
#include "Atmega32PortsRegister.h"
#include "Timer.h" 
#include "LCD4bit_8bit.h"
#include "UltraSonic.h"
#include "Servo.h"
#include "IR.h"
#include "Motor.h"
#include <avr/interrupt.h>
#include <util/delay.h>
LCD Lcd1;
TimerControl Motor1PWMTimer;
TimerControl Motor2PWMTimer;
void SystemInit(void)
{
	
	Motor1PWMTimer.TimerSelect = TIMER1;
	Motor1PWMTimer.TimerMode = TIMER_PHASE_CORRECT_8BIT_PWM_MODE;
	Motor1PWMTimer.TimerPrescaler = TimerPrescaler_8;
	Motor1PWMTimer.TimerCompSelect = TIMER1_COMPARETOR_A;
	Motor1PWMTimer.TimerCompMode = TIMER_COMPARETOR_CLR;
	
	Motor2PWMTimer.TimerSelect = TIMER1;
	Motor2PWMTimer.TimerMode = TIMER_PHASE_CORRECT_8BIT_PWM_MODE;
	Motor2PWMTimer.TimerPrescaler = TimerPrescaler_8;
	Motor2PWMTimer.TimerCompSelect = TIMER1_COMPARETOR_B;
	Motor2PWMTimer.TimerCompMode = TIMER_COMPARETOR_CLR;
	
	Lcd1.mode = LCD_4BIT_MODE;
	Lcd1.controlPort = DIO_PORTB;
	Lcd1.RSPin = DIO_PIN_1;
	Lcd1.RWPin = DIO_PIN_2;
	Lcd1.ENPin = DIO_PIN_3;
	Lcd1.dataPort = DIO_PORTA;
	Lcd1.D4Pin = DIO_PIN_4;
	Lcd1.D5Pin = DIO_PIN_5;
	Lcd1.D6Pin = DIO_PIN_6;
	Lcd1.D7Pin = DIO_PIN_7;
	Timer_Init(&Motor1PWMTimer);
	Timer_Init(&Motor2PWMTimer);
	Timer_Start(&Motor1PWMTimer);
	Timer_Start(&Motor2PWMTimer);
	LCDInit(&Lcd1);
	UltraSonic_init();
	ServoInit();
	IRInit();
	Motor_init();
	sei();
	Motor_Speet(100);
}

int main(void)
{
    /* Replace with your application code */
	SystemInit();
	int speed = 70 , count = 0;
    while (1) 
    {
		if(UltraSonic_Distance()>20)
		{
			LcdSetCursor(&Lcd1,0,0);
			writeString(&Lcd1,"Distance > 20 cm");
			LcdSetCursor(&Lcd1,1,0);
			writeString(&Lcd1,"move foreword");
			Motor_foroword();
		} 
		else if(UltraSonic_Distance()>5)
		{
			LcdSetCursor(&Lcd1,0,0);
			writeString(&Lcd1,"Distance < 20 cm");
			LcdSetCursor(&Lcd1,1,0);
			writeString(&Lcd1,"scanning for output");
			Motor_Stop();
			Motor_Speet(speed);
			ServoGoToAngle(-90);
			if (UltraSonic_Distance()>20)
			{
				Motor_Left();
				_delay_ms(500);
				speed = 100;
			} 
			else
			{
				ServoGoToAngle(90);
				if (UltraSonic_Distance()>20)
				{
					Motor_Right();
					_delay_ms(500);
					speed = 100;
				}
				else
				{
					ServoGoToAngle(0);
				}
			}
			if (speed > 30 && count == 50)
			{
				speed --;
				count = 0;
			}
			count ++;
			Motor_foroword();
		}else{
			LcdSetCursor(&Lcd1,0,0);
			writeString(&Lcd1,"Distance < 5 cm");
			LcdSetCursor(&Lcd1,1,0);
			writeString(&Lcd1,"there is no output");
			Clear(&Lcd1);
			writeString(&Lcd1,"move backward");
			Uint8 ThereIsOut = 0;
			speed = 50;
			while(!ThereIsOut)
			{
				Motor_Speet(speed);
				Motor_backword();
				ServoGoToAngle(-90);
				if (UltraSonic_Distance()>20)
				{
					Motor_Left();
					_delay_ms(500);
					speed = 100;
					ThereIsOut = 1;
				}
				else
				{
					ServoGoToAngle(90);
					if (UltraSonic_Distance()>20)
					{
						Motor_Right();
						_delay_ms(500);
						speed = 100;
						ThereIsOut = 1;
					}
					else
					{
						ServoGoToAngle(0);
					}
				}
			}
			Motor_foroword();
		}
    }
}

ISR(INT0_vect)
{
	Motor_Stop();
}
ISR(INT1_vect)
{
	Motor_Stop();
}