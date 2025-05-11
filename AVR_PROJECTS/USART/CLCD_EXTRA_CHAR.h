/*
///////////////////////////////////////////////////////////////////////CLCD_PRIVATE.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: CLCD
*/

#ifndef CLCD_EXTRA_CHAR_H_
#define CLCD_EXTRA_CHAR_H_

/*

 We draw each char on website ===>> https://maxpromer.github.io/LCD-Character-Creator/
 
 Hint : *this website already neglect the first 3 bits in each byte = 0 (on the left side)
        *take the hex value or ad 000 on the left
*/

u8 CLCD_EXTRA_CHAR[]={
	{0x01,0x01,0x01,0x01,0x11,0x11,0x1F,0x00},    //char 4 //ل
	{0x00,0x00,0x01,0x01,0x1F,0x00,0x0A,0x00},   //char 3 // ي
	{0x00,0x00,0x07,0x05,0x07,0x01,0x1E,0x00},  //char 2 // و
	{0x00,0x00,0x01,0x00,0x01,0x01,0x1E,0x00}, //char 1 // ز
};

#endif