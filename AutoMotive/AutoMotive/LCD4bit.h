/*
 * LCD4bit.h
 *
 * Created: 11/3/2021 10:55:31 AM
 *  Author: eng_s
 */ 


#ifndef LCD4BIT_H_
#define LCD4BIT_H_
#include <stdbool.h>
#define A			0x39
#define B			0x36
#define C			0x33
#define D			0x30
#define H			0xff
#ifndef LCDPort
#define LCDPort		B
#define LCDDATA		A
#define D4			4
#define D5			5
#define D6			6
#define D7			7
#define RS			1
#define RW			2
#define EN			3
#endif
#define set_bin(reg,bit)   ( (*(volatile char*) reg) |= (1<<bit))
#define reset_bin(reg,bit)  ( (*(volatile char*) reg) &=~ (1<<bit))
#define XOR(reg,bit)  ( (*(volatile char*) reg) ^= (1<<bit))
void pinChange(char,bool);
void PortWrite(char);
void cmd (char);
void LCDEN ();
void LCDInit ();
void writeData(char);
void LCD_character (char[],char);




#endif /* LCD4BIT_H_ */