/*
//////////////////////////////////////////////////////////////////////SW_PROGRAM.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 *  Author : Abdallah Zeweal
 *  Layer  : HAL
 *  SWC    : Switch
 *
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_INTERFACE.h"
#include"SW_INTERFACE.h"
#include"SW_CONFIG.h"
#include"SW_PRIVATE.h"


void SW_INIT(SW_TYPE SW_CONFIG){
	DIO_SET_PIN_DIRECTION(SW_CONFIG.PORT,SW_CONFIG.PIN,DIO_PIN_INPUT);
	
	//         to disable the PUD in SFIOR           //
	if(SW_CONFIG.PULL_STATE==SW_INT_PULL_UP){
		DIO_SET_PIN_VALUE(SW_CONFIG.PORT,SW_CONFIG.PIN,DIO_PIN_HIGH);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8   SW_GET_PRESSED(SW_TYPE SW_CONFIG){
	
	u8 VALUE =SW_NOT_PRESSED;
	u8 RESULT=SW_NOT_PRESSED;
	
	if((SW_CONFIG.PULL_STATE==SW_INT_PULL_UP)||(SW_CONFIG.PULL_STATE==SW_EXT_PULL_UP)){
		DIO_GET_PIN_VALUE(SW_CONFIG.PORT,SW_CONFIG.PIN,&VALUE);
		if(VALUE==0){
			RESULT=SW_PRESSED;
		}
		else if(VALUE==1){
			RESULT=SW_NOT_PRESSED;
		}
	}
	else if(SW_CONFIG.PULL_STATE==SW_EXT_PULL_DOWN){
		DIO_GET_PIN_VALUE(SW_CONFIG.PORT,SW_CONFIG.PIN,&VALUE);
		if(VALUE==1){
			RESULT=SW_PRESSED;
		}
		else if(VALUE==0){
			RESULT=SW_NOT_PRESSED;
		}
	}
	return RESULT;
	
}