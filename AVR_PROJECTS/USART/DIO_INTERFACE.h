/*
*******************************************************************************DIO_INTERFACE.h**************************************************************************************
Name : Abdallah Zeweal
Layer : MCAL
SWC : DIO/GPIO
*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


//define DIO_ERROR_STATUS


typedef enum{
	DIO_NOK,
	DIO_OK
}DIO_ERROR_STATUS;

	
//define pin directions


#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1


//define pin value options


#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0


//define PINS


#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


//define PORTS

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


//define port options


#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0

//define port directions


#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT 0

//define internal pull up

#define PUD 2


//INPUT FUNCTIONS


DIO_ERROR_STATUS DIO_SET_PIN_DIRECTION(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8DIRECTION);
DIO_ERROR_STATUS DIO_SET_PIN_VALUE(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8VALUE);
DIO_ERROR_STATUS DIO_GET_PIN_VALUE(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 * Copy_PTR_DATA);
DIO_ERROR_STATUS DIO_TOGGLE_PIN_VALUE(u8 Copy_u8PORT,u8 Copy_u8PIN);

// pull up

DIO_ERROR_STATUS DIO_CONNECT_PULL_UP(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8CONNECT_PULL_up);

//INPUT PORTS


DIO_ERROR_STATUS DIO_SET_PORT_DIRECTION(u8 Copy_u8PORT,u8 Copy_u8DIRECTION);
DIO_ERROR_STATUS DIO_SET_PORT_VALUE(u8 Copy_u8PORT,u8 Copy_u8VALUE);
DIO_ERROR_STATUS DIO_GET_PORT_VALUE(u8 Copy_u8PORT,u8 * Copy_PTR_DATA);
DIO_ERROR_STATUS DIO_TOGGLE_PORT_VALUE(u8 Copy_u8PORT);


// IO Nibbles
DIO_ERROR_STATUS DIO_WRITE_HIGH_NIBBLES (u8 Copy_u8PORT,u8 Copy_u8VALUE);
DIO_ERROR_STATUS DIO_WRITE_LOW_NIBBLES (u8 Copy_u8PORT,u8 Copy_u8VALUE);


#endif