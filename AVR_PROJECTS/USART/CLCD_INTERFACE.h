/*
///////////////////////////////////////////////////////////////////////CLCD_INTERFACE.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: CLCD
*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#if CLCD_MODE==4
#define FOUR_BITS 0x28
#elif CLCD_MODE==8
#define EIGHT_BITS 0x38
#endif


#define LCD_DISPLAY_ON_CURSOR_OFF 0x0c  // display on, cursor off, don't blink character
#define LCD_DISPLAY_ON_CURSOR_ON 0x00e  // display on, cursor on, don't blink character
#define LCD_DISPLAY_OFF_CURSOR_OFF 0x08 // display off, cursor off, don't blink character
#define LCD_CLEAR 0x01                  // clear all data
#define LCD_ENTRY_MODE 0x06             // shift cursor to right and left
#define LCD_HOME 0x02                   // return the cursor to first place in the first line
#define LCD_CGRAM 0x40                  // go to the first address in CGRAM
#define LCD_SET_CURSOR 0x80             // set cursor position
#define LCD_FUNCTION_RESET 0x30         // reset the LCD


#define CLCD_ROW_1   1
#define CLCD_ROW_2   2

#define CLCD_COL_1   1
#define CLCD_COL_2   2
#define CLCD_COL_3   3
#define CLCD_COL_4   4
#define CLCD_COL_5   5
#define CLCD_COL_6   6
#define CLCD_COL_7   7
#define CLCD_COL_8   8
#define CLCD_COL_9   9
#define CLCD_COL_10  10
#define CLCD_COL_11  11
#define CLCD_COL_12  12
#define CLCD_COL_13  13
#define CLCD_COL_14  14
#define CLCD_COL_15  15
#define CLCD_COL_16  16


void CLCD_INIT(void);                                     // make steps of initialization of the CLCD 
void CLCD_SEND_DATA(u8 Copy_u8DATA);                      // send the data you want to display to DIO_PORTA
void CLCD_SEND_COMMAND(u8 Copy_u8COMMAND);                // send the command you want to do to DIO_PORTA 
void CLCD_SEND_NUMBER(u64 Copy_u8NUMBER);                 // send the number you want to display to DIO_PORTA
void CLCD_SEND_STRING(const u8 * Copy_u8ptr);             // send the string you want to display to DIO_PORTA
void CLCD_SET_POSITION(u8 Copy_u8ROW,u8 Copy_u8COL);      // to set the curser in the first place in the first row
void CLCD_SEND_EXTRA_CHAR(u8 Copy_u8ROW,u8 Copy_u8COL);   // to send character in diffrent language
void CLCD_CLEAR_SCREEN(void);                             // to clear the screen


#endif