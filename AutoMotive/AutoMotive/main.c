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
#include "LCD4bit_8bit.h"
#include "UltraSonic.h"
#include "Servo.h"
#include "IR.h"
#include "Motor.h"
#include <avr/interrupt.h>
#include <util/delay.h>
LCD Lcd1;


void SystemInit(void)
{
	
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
	LCDInit(&Lcd1);
	UltraSonic_init();
	ServoInit();
	IRInit();
	Motor_init();
	sei();
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
			Motor_Speet(100);
			Motor_foroword();
		} 
		else if(UltraSonic_Distance()>5 && UltraSonic_Distance()<=20)
		{
			LcdSetCursor(&Lcd1,0,0);
			writeString(&Lcd1,"Distance < 20 cm");
			LcdSetCursor(&Lcd1,1,0);
			writeString(&Lcd1,"scanning for output");
			Motor_Stop();
			ServoGoToAngle(-90);
			if (UltraSonic_Distance()>20)
			{
				Motor_Left();
				_delay_ms(500);
				speed = 100;
				ServoGoToAngle(0);
			} 
			else
			{
				ServoGoToAngle(90);
				if (UltraSonic_Distance()>20)
				{
					Motor_Right();
					_delay_ms(500);
					speed = 100;
					ServoGoToAngle(0);
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
			Motor_Speet(speed);
			Motor_foroword();
			_delay_ms(100);
		}else{
			LcdSetCursor(&Lcd1,0,0);
			writeString(&Lcd1,"Distance < 5 cm");
			LcdSetCursor(&Lcd1,1,0);
			writeString(&Lcd1,"there is no output");
			_delay_ms(100);
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
					ServoGoToAngle(0);
					_delay_ms(100);
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
						ServoGoToAngle(0);
					}
					else
					{
						ServoGoToAngle(0);
						_delay_ms(100);
					}
				}
			}
			Motor_foroword();
		}
    }
}

