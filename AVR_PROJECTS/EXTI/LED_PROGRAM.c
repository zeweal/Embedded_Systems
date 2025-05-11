/*
//////////////////////////////////////////////////////////////////////////LED_PROGRAM.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
Auothor: Abdallah Zeweal
Layer: HAL
SWC: LED
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LED_PRIVATE.h"
#include "LED_CONFIG.h"


/*
* Berief:
      =>this function is used to initialize the led as output
* Parameters :
  	   => struct has the led porn , pin , status
*/
void LED_INIT(LED_TYPE LED_CONFIG){
     DIO_SET_PIN_DIRECTION( LED_CONFIG.PORT, LED_CONFIG.PIN , DIO_PIN_OUTPUT );	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to make the led on 
* Parameters :
  	   => struct has the led porn , pin , status
*/
void LED_ON(LED_TYPE LED_CONFIG){
	 if(LED_CONFIG.ACTIVATE_STATE==ACTIVE_HIGH){
		 DIO_SET_PIN_VALUE( LED_CONFIG.PORT, LED_CONFIG.PIN , DIO_PIN_HIGH);
	 }
	 else if (LED_CONFIG.ACTIVATE_STATE==ACTIVE_LOW){
		 DIO_SET_PIN_VALUE( LED_CONFIG.PORT, LED_CONFIG.PIN , DIO_PIN_LOW);
	 }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to make the led off
* Parameters :
  	   => struct has the led porn , pin , status
*/
void LED_OFF(LED_TYPE LED_CONFIG){
	 if(LED_CONFIG.ACTIVATE_STATE==ACTIVE_HIGH){
		 DIO_SET_PIN_VALUE( LED_CONFIG.PORT, LED_CONFIG.PIN , DIO_PIN_LOW);
	 }
	 else if (LED_CONFIG.ACTIVATE_STATE==ACTIVE_LOW){
		 DIO_SET_PIN_VALUE( LED_CONFIG.PORT, LED_CONFIG.PIN , DIO_PIN_HIGH);
	 }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to toggle the led
* Parameters :
  	   => struct has the led porn , pin , status
*/
void LED_TOGGLE(LED_TYPE LED_CONFIG){
	DIO_TOGGLE_PIN_VALUE( LED_CONFIG.PORT , LED_CONFIG.PIN);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////