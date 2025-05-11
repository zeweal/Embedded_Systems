/*
***************************************************************DIO_PRIVATE.h*********************************************************************************
Author : Abdallah Zeweal
Layer : MCAL
SWC : GPIO
*/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

//define A
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

//define B
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

//define C
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

//define D
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)

//define SFIOR
#define  SFIOR   *((volatile u8*)0x50)

#endif