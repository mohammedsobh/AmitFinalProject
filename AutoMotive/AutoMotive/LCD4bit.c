/*
 * LCD4bit.c
 *
 * Created: 11/3/2021 11:07:20 AM
 *  Author: eng_s
 */ 
#include "LCD4bit.h"
#include <stdbool.h>
#include <util/delay.h>

void pinChange (char bin ,bool setRest )
{
	if (setRest)
		set_bin ( (LCDPort+2) , bin);
	else
		reset_bin ( (LCDPort+2) , bin);
}
void pinDATAChange (char bin ,bool setRest )
{
	if (setRest)
	set_bin ( (LCDDATA+2) , bin);
	else
	reset_bin ( (LCDDATA+2) , bin);
}
void LCDEN (){
	pinChange(EN,1);
	_delay_ms(1);
	pinChange(EN,0);
}
void PortWrite(char Data){
		if(Data & 1)
		pinDATAChange(D4,1);
		else
		pinDATAChange(D4,0);
		
		if(Data & 2)
		pinDATAChange(D5,1);
		else
		pinDATAChange(D5,0);
		
		if(Data & 4)
		pinDATAChange(D6,1);
		else
		pinDATAChange(D6,0);
		
		if(Data & 8)
		pinDATAChange(D7,1);
		else
		pinDATAChange(D7,0);
}
void cmd (char command){
	pinChange(RS,0);
	PortWrite((command&0xF0)>>4);
	LCDEN ();
	PortWrite(command & 0x0F);
	LCDEN ();
}
void LCDInit()
{
	pinChange(RW,0);
	PortWrite(0x00);
	_delay_ms(20);
	///////////// Reset process from datasheet /////////
	cmd(0x03);
	_delay_ms(5);
	cmd(0x03);
	_delay_ms(11);
	cmd(0x03);
	/////////////////////////////////////////////////////
	cmd(0x02);
	cmd(0x02);
	cmd(0x08);
	cmd(0x00);
	cmd(0x0C);
	cmd(0x00);
	cmd(0x06);
}
void writeData(char Data){
	pinChange(RS,1);
	PortWrite((Data&0xF0)>>4);
	LCDEN ();
	PortWrite(Data & 0x0F);
	LCDEN ();
}