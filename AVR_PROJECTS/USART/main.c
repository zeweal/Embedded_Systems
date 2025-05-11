#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_INTERFACE.h"
#include"CLCD_INTERFACE.h"
#include"UART_INTERFACE.h"

#include<util/delay.h>

u8 DATA =0;
void main(){
	CLCD_INIT();
	USART_INIT();
	USART_SEND_STRING_SYNCH((u8 *) "ZEWEAL");
	CLCD_SEND_STRING((u8 *)"LCD -> ready ");
	_delay_ms(1000);
	CLCD_CLEAR_SCREEN();
	while(1){
		USART_RECIEVE_DATA(& DATA);
		if(DATA !=0){
			CLCD_SEND_STRING(& DATA);
			DATA=0;
		}
	}
}
