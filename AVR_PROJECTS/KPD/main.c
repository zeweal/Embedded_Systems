#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_INTERFACE.h"
#include"LED_INTERFACE.h"
#include"CLCD_INTERFACE.h"
#include"KPD_INTERFACE.h"
#include"util/delay.h"

LED_TYPE LEDS[8]={{DIO_PIN0,DIO_PORTC,ACTIVE_HIGH},{DIO_PIN1,DIO_PORTC,ACTIVE_HIGH},
			         {DIO_PIN2,DIO_PORTC,ACTIVE_HIGH},{DIO_PIN3,DIO_PORTC,ACTIVE_HIGH},
			         {DIO_PIN4,DIO_PORTC,ACTIVE_HIGH},{DIO_PIN5,DIO_PORTC,ACTIVE_HIGH},
		           	 {DIO_PIN6,DIO_PORTC,ACTIVE_HIGH},{DIO_PIN7,DIO_PORTC,ACTIVE_HIGH}} ;
static void LEDS_OFF(){
	for(u8 y=0;y<8;y++){
		LED_OFF(LEDS[y]);
	}
}

void main(){

  for(u8 i=0;i<8;i++){
	  LED_INIT(LEDS[i]);
  }
  CLCD_INIT();
  KPD_INIT();

  while(1){
	  u8 x=KPD_GET_PRESSED();

	  if(x!=0xff){

	  CLCD_SEND_DATA(x);
		switch(x){
		case('1'): LEDS_OFF();     LED_ON(LEDS[0]);  break;
		case('2'): LEDS_OFF();     LED_ON(LEDS[1]);  break;
		case('3'): LEDS_OFF();     LED_ON(LEDS[2]);  break;
		case('4'): LEDS_OFF();     LED_ON(LEDS[3]);  break;
		case('5'): LEDS_OFF();     LED_ON(LEDS[4]);  break;
		case('6'): LEDS_OFF();     LED_ON(LEDS[5]);  break;
		case('7'): LEDS_OFF();     LED_ON(LEDS[6]);  break;
		case('8'): LEDS_OFF();     LED_ON(LEDS[7]);  break;
		default:   LEDS_OFF();     CLCD_CLEAR_SCREEN();  break;
		}
	  }
}
	  }


