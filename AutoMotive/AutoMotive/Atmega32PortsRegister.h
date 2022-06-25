/*
 * Atmega32PortsRegister.h
 *
 * Created: 25/02/2022 11:02:14 PM
 *  Author: eng_s
 */ 


#ifndef ATMEGA32PORTSREGISTER_H_
#define ATMEGA32PORTSREGISTER_H_

#define PINA					*(volatile unsigned char*)(0x39)
#define DDRA					*(volatile unsigned char*)(0x3A)
#define PORTA					*(volatile unsigned char*)(0x3B)

#define PINB					*(volatile unsigned char*)(0x36)
#define DDRB					*(volatile unsigned char*)(0x37)
#define PORTB					*(volatile unsigned char*)(0x38)

#define PINC					*(volatile unsigned char*)(0x33)
#define DDRC					*(volatile unsigned char*)(0x34)
#define PORTC					*(volatile unsigned char*)(0x35)

#define PIND					*(volatile unsigned char*)(0x30)
#define DDRD					*(volatile unsigned char*)(0x31)
#define PORTD					*(volatile unsigned char*)(0x32)

#define SREG					(*(volatile unsigned char*)(0x5F))

#define GICR					(*(volatile unsigned char*)(0x5B))

#define GIFR					(*(volatile unsigned char*)(0x5A))

#define MCUCR					(*(volatile unsigned char*)(0x55))

#define MCUCSR					(*(volatile unsigned char*)(0x54))

/***********************		ADC		****************************/
#define ADCMUX					(*(volatile unsigned char*)(0x27))
#define ADCSRA					(*(volatile unsigned char*)(0x26))
#define ADCH					(*(volatile unsigned char*)(0x25))
#define ADCL					(*(volatile unsigned char*)(0x24))
#define ADC_ADJUCT				(*(volatile Uint16*)(0x24))

/****************************** Timer 0 ********************************************/

#define TCNT0  (*(volatile Uint8*)(0x52))
#define TCCR0  (*(volatile Uint8*)(0x53))
#define OCR0   (*(volatile Uint8*)(0x5C))
#define TIMSK  (*(volatile Uint8*)(0x59))
#define TIFR   (*(volatile Uint8*)(0x58))
/****************************** Timer 1 ********************************************/
#define TCCR1A (*(volatile Uint8*)(0x4F))
#define TCCR1B (*(volatile Uint8*)(0x4E))
#define OCR1A  (*(volatile Uint16*)(0x4A))
#define OCR1B  (*(volatile Uint16*)(0x48))
#define ICR1   (*(volatile Uint16*)(0x46))
/****************************** Timer 2 ********************************************/
#define TCCR2 (*(volatile Uint8*)(0x45))
#define OCR2  (*(volatile Uint16*)(0x43))

/********************************** I2C ********************************************/
#define TWDR   (*(volatile Uint8*)(0x03))
#define TWAR   (*(volatile Uint8*)(0x02))
#define TWSR   (*(volatile Uint8*)(0x01))
#define TWBR   (*(volatile Uint8*)(0x00))

#endif /* ATMEGA32PORTSREGISTER_H_ */