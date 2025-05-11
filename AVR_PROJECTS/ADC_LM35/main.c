/*#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_INTERFACE.h"
#include"ADC_INTERFACE.h"
#include"LM35_INTERFACE.h"
#include"CLCD_INTERFACE.h"

LM35_CONFIG LMM={ADC_CHANNEL0,AVCC,ADC_RESOLUTION_10_BIT};

void main(){
	u8 temp=0;
	ADC_INIT();
	CLCD_INIT();
	while(1){
		u8 z= GET_TEMP(&LMM , &temp);
		CLCD_SEND_STRING("temp is ");
		CLCD_SEND_NUMBER(z);
	}
}*/


/*

 * main.c
 *
 *  Created on: Mar 20, 2023
 *      Author: Mahmoud Karem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

#include "LED_INTERFACE.h"
#include "CLCD_INTERFACE.h"
#include "LM35_INTERFACE.h"

u8 LM35_V = 0;
/***********************************************/

LED_TYPE LED1={LED_PIN5,LED_PORTA,ACTIVE_HIGH};

LM35_CONFIG LM35_S = {ADC_CHANNEL0,AVCC,0};

/***********************************************/

static void APP_Init()
{
	ADC_INIT();
	CLCD_INIT();
	LED_INIT(LED1);
	LED_OFF(LED1);
}

/***********************************************/
int main ()
{
	APP_Init();
	CLCD_SEND_STRING((u8 *)"ZOZZ :)");
	while(1)
	{
		CLCD_SET_POSITION(CLCD_ROW_2,CLCD_COL_2);
		CLCD_SEND_STRING((u8 *)"Temp = ");
		GET_TEMP(&LM35_S,&LM35_V);
		CLCD_SEND_NUMBER(LM35_V);
		CLCD_SET_POSITION(CLCD_ROW_2,CLCD_COL_12);
		CLCD_SEND_STRING((u8 *)" C");

		if (LM35_V >= 20)
		{
			LED_ON(LED1);
		}
		else
		{
			LED_OFF(LED1);
		}
	}
	return 0;
}
