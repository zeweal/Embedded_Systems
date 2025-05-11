/*
///////////////////////////////////////////////////////////////////////CLCD_CONFIG.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: CLCD
*/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_MODE 4

#define CLCD_DATA_PORT DIO_PORTC     //B0--->B7
#define CLCD_CONTROL_PORT DIO_PORTB  // EN,READ,WRITE,RS

#define CLCD_RS             DIO_PIN1
#define CLCD_RW             DIO_PIN2
#define CLCD_EN             DIO_PIN3

#endif
 
