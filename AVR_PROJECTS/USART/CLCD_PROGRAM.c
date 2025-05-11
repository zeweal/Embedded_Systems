/*
///////////////////////////////////////////////////////////////////////CLCD_PROGRAM.c\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: CLCD
*/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <util/delay.h>

#include"DIO_INTERFACE.h"

#include"CLCD_INTERFACE.h"
#include"CLCD_CONFIG.h"
#include"CLCD_PRIVATE.h"
#include"CLCD_EXTRA_CHAR.h"

void CLCD_INIT(void){
	
/***************************************************************** 8BITS ***********************************************************************************/
	
	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	#if CLCD_MODE==8
	_delay_ms(50);
	
	// make all pins output
	DIO_SET_PORT_DIRECTION(CLCD_DATA_PORT,DIO_PORT_HIGH);
    DIO_SET_PIN_DIRECTION(CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_CONTROL_PORT,CLCD_RW,DIO_PIN_OUTPUT);
	
	//initialize cursor to first line
	CLCD_SEND_COMMAND(LCD_HOME);
	_delay_ms(1);
	
	CLCD_SEND_COMMAND(EIGHT_BITS); // 8 Bit Mode ==> 0x38
	_delay_ms(1); // wait more than 39 Ms
	
	//display on the LCD
	CLCD_SEND_COMMAND(LCD_DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	
	//clear the screen
	CLCD_CLEAR_SCREEN();
	_delay_ms(1);
	
	// set the entry mode
	CLCD_SEND_COMMAND(LCD_ENTRY_MODE);
	_delay_ms(1);
	/***************************************************************** 4BITS ***********************************************************************************/
    #elif CLCD_MODE==4
	_delay_ms(50);
	
	// make all pins output
	DIO_SET_PIN_DIRECTION(CLCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
    DIO_SET_PIN_DIRECTION(CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_OUTPUT);
	DIO_SET_PIN_DIRECTION(CLCD_CONTROL_PORT,CLCD_RW,DIO_PIN_OUTPUT);
	
	//initialize cursor to first line
	CLCD_SEND_COMMAND(LCD_HOME);
	_delay_ms(1);
	
	CLCD_SEND_COMMAND(0x28); // 4 Bit Mode ==> 0x28
	_delay_ms(1); // wait more than 39 Ms
	
	//display on the LCD
	CLCD_SEND_COMMAND(LCD_DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	
	//clear the screen
	CLCD_CLEAR_SCREEN();
	_delay_ms(1);
	
	// set the entry mode
	CLCD_SEND_COMMAND(LCD_ENTRY_MODE);
	_delay_ms(1);
	
	#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_SEND_DATA(u8 Copy_u8DATA){
/***************************************************************** 8BITS ***********************************************************************************/
	#if CLCD_MODE==8
	
    DIO_SET_PORT_VALUE(CLCD_DATA_PORT,Copy_u8DATA);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_HIGH);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RW,DIO_PIN_LOW);
	CLCD_SEND_FALLING_EDGE();
/***************************************************************** 4BITS ***********************************************************************************/
	#elif CLCD_MODE==4
	
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_HIGH);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RW,DIO_PIN_LOW);
	DIO_WRITE_HIGH_NIBBLES (CLCD_DATA_PORT,((Copy_u8DATA)>>4)); // write the MSBs of data in high nibbles
	CLCD_SEND_FALLING_EDGE();
	DIO_WRITE_HIGH_NIBBLES (CLCD_DATA_PORT,Copy_u8DATA); // write the LSBs of data in high nibbles
	CLCD_SEND_FALLING_EDGE();
	#endif
	_delay_ms(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_SEND_COMMAND(u8 Copy_u8COMMAND){
/***************************************************************** 8BITS ***********************************************************************************/
	#if CLCD_MODE==8
	
    DIO_SET_PORT_VALUE(CLCD_DATA_PORT,Copy_u8COMMAND);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_LOW);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RW,DIO_PIN_LOW);
	CLCD_SEND_FALLING_EDGE();
/***************************************************************** 4BITS ***********************************************************************************/
	#elif CLCD_MODE==4
	
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RS,DIO_PIN_LOW);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_RW,DIO_PIN_LOW);
	DIO_WRITE_HIGH_NIBBLES (CLCD_DATA_PORT,((Copy_u8COMMAND)>>4)); // write the MSBs of command in high nibbles
	CLCD_SEND_FALLING_EDGE();
	DIO_WRITE_HIGH_NIBBLES (CLCD_DATA_PORT,Copy_u8COMMAND); // write the LSBs of command in high nibbles
	CLCD_SEND_FALLING_EDGE();
	#endif
	_delay_ms(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_SEND_NUMBER(u64 Copy_u8NUMBER){
	u8 reversed =1;
	if(Copy_u8NUMBER==0){CLCD_SEND_DATA('0');}
	else{
		while(Copy_u8NUMBER != 0){
			reversed=(reversed*10)+(Copy_u8NUMBER % 10);
			Copy_u8NUMBER/=10;
		}
		while(reversed != 1){
			CLCD_SEND_DATA((reversed % 10)+48);
            reversed/=10;			
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_SEND_STRING(const u8 * Copy_u8ptr){
	u8 i=0;
	while(Copy_u8ptr[i] != '\0'){
		CLCD_SEND_DATA(Copy_u8ptr[i]);
		i++;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_SET_POSITION(u8 Copy_u8ROW,u8 Copy_u8COL){
	u8 i;
	if(Copy_u8COL<1||Copy_u8COL>16||Copy_u8ROW<1||Copy_u8ROW>2)      {i =LCD_SET_CURSOR ; }
	else if(Copy_u8ROW==CLCD_ROW_1){
		i=  ( (LCD_SET_CURSOR) + ( Copy_u8COL - 1 ) );
	}
	else if(Copy_u8ROW==CLCD_ROW_2){
		i= ((LCD_SET_CURSOR)+(64)+( Copy_u8COL - 1 ));
	}
	CLCD_SEND_COMMAND(i);
	_delay_ms(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_CLEAR_SCREEN(){
	CLCD_SEND_COMMAND(LCD_CLEAR);
	_delay_ms(10);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void CLCD_SEND_FALLING_EDGE(){
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SET_PIN_VALUE(CLCD_CONTROL_PORT,CLCD_EN,DIO_PIN_LOW);
	_delay_ms(1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CLCD_SEND_EXTRA_CHAR(u8 Copy_u8ROW,u8 Copy_u8COL){
	u8 iterator =0;
	// go to CGRAM
	CLCD_SEND_COMMAND(LCD_CGRAM);
	// draw characters 
	for(iterator=0;iterator<((sizeof(CLCD_EXTRA_CHAR))/(sizeof(CLCD_EXTRA_CHAR[0])));iterator++){
		CLCD_SEND_DATA(CLCD_EXTRA_CHAR[iterator]);
	}
	// back to DDRAM
	CLCD_SET_POSITION(Copy_u8ROW,Copy_u8COL);
	// send addresses of characters
	for(iterator=0;iterator<8;iterator++){
		CLCD_SEND_DATA(iterator);
	}
}
