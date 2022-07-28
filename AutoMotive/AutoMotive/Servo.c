/*
 * Servo.c
 *
 * Created: 6/11/2022 3:11:20 PM
 *  Author: nada
 */ 
#include "Servo.h"

void ServoInit(void)
{
  DIO_SetPinDir(SERVO_PORT,SERVO_PIN,DIO_PIN_DIR_OUTPUT);         
  DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_LOW);
  ServoGoToAngle(0);    
}
void ServoGoToAngle(Sint8 Angle)
{
	if (Angle == 90)
	{
		DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_HIGH);         //Rotation to 0 degree
		_delay_us(1000);      //Rotation to 0 degree
		DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_LOW);         //Rotation to 0 degree
		_delay_ms(500);
	} 
	else if (Angle == 0)
	{
		DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_HIGH);         //Rotation to 0 degree
		_delay_us(1500);      //Rotation to 0 degree
		DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_LOW);         //Rotation to 0 degree
		_delay_ms(500);
	}
	else if (Angle == -90)
	{
		DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_HIGH);         //Rotation to 0 degree
		_delay_us(2000);      //Rotation to 0 degree
		DIO_SetPinVal(SERVO_PORT,SERVO_PIN,DIO_PIN_LOW);         //Rotation to 0 degree
		_delay_ms(500);
	}  
}
