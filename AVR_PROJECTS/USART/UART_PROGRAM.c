#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"UART_PRIVATE.h"
#include"UART_CONFIG.h"
#include"UART_INTERFACE.h"
#include"CLCD_INTERFACE.h"

static void (* USART_NotificationFunc)(void)={NULL};
static u8 USART_STATE = IDLE;
static const u8 * USART_u8SendData = NULL ;
static  u8 * USART_u8RecieveData = NULL ;
static  u8 * USART_u8BufferSize ;
static  u8  USART_u8Index ;

void USART_INIT(){
   	u8 LOC_u8UCSRC = 0;
	u16 LOC_u16UBRR= (u16)(FREQUENCY_SYSTEM/((16* USART_BAUD_RATE))-1);
	UBBRH=(u8) (LOC_u16UBRR>>8);
	UBBRL=(u8) LOC_u16UBRR;
	
	
	#if ((USART_SYSTEM_SPEED == USART_X2) && (USART_MODE == ASYNCH))
		LOC_u16UBRR /= 2;
		SET_BIT(UCSRA_U2X,UCSRA);
	#elif ((USART_SYSTEM_SPEED == USART_X1) && (USART_MODE == ASYNCH))
		CLR_BIT(UCSRA_U2X,UCSRA);
	#elif USART_MODE == SYNCH
	    LOC_u16UBRR /=8;
	#else 
		#error
	#endif 
	
	#if USART_MPCM == ENABLE
	SET_BIT(UCSRA_MPCM,UCSRA);
	#elif USART_MPCM == DISABLE
	CLR_BIT(UCSRA_MPCM,UCSRA);
	#endif 
	
	#if USART_MODE == ASYNCH
	CLR_BIT(UCSRC_UMSEL,LOC_u8UCSRC);
	#elif USART_MODE == SYNCH
	SET_BIT(UCSRC_UMSEL,LOC_u8UCSRC);
	#endif
	
	#if USART_PARITY_MODE == DISABLE
	CLR_BIT(UCSRC_UPM0,LOC_u8UCSRC);
	CLR_BIT(UCSRC_UPM1,LOC_u8UCSRC);
	#elif USART_PARITY_MODE == ENABLE_EVEN
	CLR_BIT(UCSRC_UPM0,LOC_u8UCSRC);
	SET_BIT(UCSRC_UPM1,LOC_u8UCSRC);
	#elif USART_PARITY_MODE == ENABLE_ODD
	SET_BIT(UCSRC_UPM0,LOC_u8UCSRC);
	SET_BIT(UCSRC_UPM1,LOC_u8UCSRC);
	#else 
		#error
	#endif
	
	#if USART_STOP_BIT == ONE_BIT
	CLR_BIT(UCSRC_USBS,LOC_u8UCSRC);
	#elif USART_STOP_BIT == TWO_BIT
	SET_BIT(UCSRC_USBS,LOC_u8UCSRC);
	#endif
	
	#if USART_DATA_SIZE == DATA_SIZE_9_BIT
	SET_BIT(UCSRC_UCSZ0,LOC_u8UCSRC);
	SET_BIT(UCSRC_UCSZ1,LOC_u8UCSRC);
	SET_BIT(UCSRB_UCSZ2,UCSRB);
	#elif USART_DATA_SIZE == DATA_SIZE_8_BIT
    SET_BIT(UCSRC_UCSZ0,LOC_u8UCSRC);
	SET_BIT(UCSRC_UCSZ1,LOC_u8UCSRC);
	CLR_BIT(UCSRB_UCSZ2,UCSRB);	
	#elif USART_DATA_SIZE == DATA_SIZE_7_BIT
    CLR_BIT(UCSRC_UCSZ0,LOC_u8UCSRC);
	SET_BIT(UCSRC_UCSZ1,LOC_u8UCSRC);
	CLR_BIT(UCSRB_UCSZ2,UCSRB);	
	#elif USART_DATA_SIZE == DATA_SIZE_6_BIT
    SET_BIT(UCSRC_UCSZ0,LOC_u8UCSRC);
	CLR_BIT(UCSRC_UCSZ1,LOC_u8UCSRC);
	CLR_BIT(UCSRB_UCSZ2,UCSRB);	
	#elif USART_DATA_SIZE == DATA_SIZE_5_BIT
    CLR_BIT(UCSRC_UCSZ0,LOC_u8UCSRC);
	CLR_BIT(UCSRC_UCSZ1,LOC_u8UCSRC);
	CLR_BIT(UCSRB_UCSZ2,UCSRB);	
	#else 
		#error
	#endif
	
	#if USART_MODE == SYNCH
	    #if USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
		SET_BIT(UCSRC_UCPOL,LOC_u8UCSRC);
		#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
		CLR_BIT(UCSRC_UCPOL,LOC_u8UCSRC);
		#else 
			#error
		#endif
	#endif
	
	SET_BIT(UCSRC_URSEL,LOC_u8UCSRC);
	UCSRC=LOC_u8UCSRC;
	
	#if USART_RX_COMPLETE_INTERRUPT == ENABLE
	SET_BIT(UCSRB_RXCIE,UCSRB);
	#elif USART_RX_COMPLETE_INTERRUPT == DISABLE
	CLR_BIT(UCSRB_RXCIE,UCSRB);
	#endif
	
	#if USART_TX_COMPLETE_INTERRUPT == ENABLE
	SET_BIT(UCSRB_TXCIE,UCSRB);
	#elif USART_TX_COMPLETE_INTERRUPT == DISABLE
	CLR_BIT(UCSRB_TXCIE,UCSRB);
	#endif
	
	#if USART_EMPTY_INTERRUPT == ENABLE
	SET_BIT(UCSRB_UDRIE,UCSRB);
	#elif USART_EMPTY_INTERRUPT == DISABLE
	CLR_BIT(UCSRB_UDRIE,UCSRB);
	#endif
	
	#if USART_RECIEVER_ENABLE == ENABLE
	SET_BIT(UCSRB_RXEN,UCSRB);
	#elif USART_RECIEVER_ENABLE == DISABLE
	CLR_BIT(UCSRB_RXEN,UCSRB);
	#endif
	
	#if USART_TRANSMITTER_ENABLE == ENABLE
	SET_BIT(UCSRB_TXEN,UCSRB);
	#elif USART_TRANSMITTER_ENABLE == DISABLE
	CLR_BIT(UCSRB_TXEN,UCSRB);
	#endif 
	
}
/*****************************************************************************************************************************/

u8 USART_SEND_DATA(u8 Copy_u8Data){
	u8 ERROR =OK;
	u32 TIMER=0;
	if(USART_STATE == IDLE){
		USART_STATE = BUSY;
	    while ((GET_BIT(UCSRA_UDRE,UCSRA) == 0) && (TIMER != TIME_OUT)){
		     TIMER++;
	    }
		if(TIMER == TIME_OUT){
			ERROR = TIMEOUT_STATE;
		}
		else{
			UDR = Copy_u8Data;
		}
		USART_STATE = IDLE;
	}
	else{
		USART_STATE= BUSY;
	}
	return ERROR;
}

/*****************************************************************************************************************************/

u8 USART_RECIEVE_DATA(u8 *Copy_u8RecievedData){
	u8 ERROR ;
	u8 TIMER=0;
	if (Copy_u8RecievedData != NULL){
		if (USART_STATE == IDLE){
			USART_STATE = BUSY;
			while((GET_BIT(UCSRA_RXC,UCSRA)==0) && (TIMER != TIME_OUT)){
				TIMER++;
			}
			if(TIMER == TIME_OUT){
				ERROR = TIMEOUT_STATE;
			}
			else{
				*Copy_u8RecievedData = UDR;
			}
			USART_STATE = IDLE;
		}
		else {
			ERROR = BUSY_STATE;
		}
	}
	else{
		ERROR= NULL_POINTER;
	}
	return ERROR;
}
/*****************************************************************************************************************************/
u8 USART_SEND_STRING_SYNCH(const u8 * Copy_pchString){
	u8 ERROR =OK;
	u8 INDEX =0;
	if(Copy_pchString != NULL){
		while(Copy_pchString[INDEX]!='\0'){
		ERROR=USART_SEND_DATA(Copy_pchString[INDEX]);
		INDEX++;
		}
		if(ERROR != OK){
			return ERROR;
		}
	}
	else{
		ERROR = NULL_POINTER;
	}
	return ERROR;
}
/*****************************************************************************************************************************/
u8 USART_SEND_STRING_ASYNCH(const u8 * Copy_pchString , void (* NotificationFunc)(void)){
	u8 ERROR = OK;

	if(USART_STATE == IDLE){
		if ((Copy_pchString != NULL) && (NotificationFunc != NULL)){
			USART_STATE = BUSY;
			USART_u8SendData = Copy_pchString;
			USART_NotificationFunc = NotificationFunc;
			USART_u8Index=0;
			UDR=USART_u8SendData[USART_u8Index];
			SET_BIT(UCSRB_TXCIE,UCSRB);
		}
		else{
			ERROR = NULL_POINTER;
		}
	}
	else{
		ERROR = BUSY_STATE; 
	}
	return ERROR;
}
/*****************************************************************************************************************************/
u8 USART_RECIEVE_BUFFER_ASYNCH(u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)){
	u8 ERROR = OK;
	if(USART_STATE == IDLE){
		if((Copy_pchString != NULL)&&(NotificationFunc != NULL)){
			USART_u8RecieveData = Copy_pchString ;
			USART_u8BufferSize = Copy_uint32BufferSize ;
			USART_NotificationFunc = NotificationFunc;
			USART_u8Index = 0 ;
			SET_BIT(UCSRB_RXCIE,UCSRB);
		}
		else{
			ERROR = NULL_POINTER;
		}
	}
	else{
		ERROR = BUSY_STATE;
	}
	return ERROR;
}
/*****************************************************************************************************************************/
u8 USART_RECIEVE_BUFFER_SYNCH(u8 * Copy_pchString , u32 Copy_uint32BufferSize){
	u8 ERROR = OK;
	u8 INDEX = 0;
	if(Copy_pchString != NULL){
		USART_u8RecieveData = Copy_pchString ;
		while(INDEX<Copy_uint32BufferSize){
			ERROR= USART_SEND_DATA(Copy_pchString[INDEX]);
			INDEX++ ;
			if(ERROR != OK){
				return ERROR;
			}
		}
	}
	else{
		ERROR = NULL_POINTER;
	}
	return ERROR;
}
/*****************************************************************************************************************************/

void __vector_13 (void)           __attribute__ ((signal));
void __vector_13 (void){
	
	USART_u8RecieveData[USART_u8Index]=UDR;
	USART_u8Index++;
	if(USART_u8Index == USART_u8BufferSize){
		USART_u8Index=0;
		USART_STATE= IDLE;
		USART_NotificationFunc();
		CLR_BIT(UCSRB_RXCIE , UCSRB);
	}
}
/*****************************************************************************************************************************/

void __vector_15 (void)           __attribute__ ((signal));
void __vector_15 (void){
	USART_u8Index++;
	if(USART_u8SendData[USART_u8Index] == '\0'){
		USART_u8Index=0;
		USART_STATE= IDLE;
		USART_NotificationFunc();
		CLR_BIT(UCSRB_TXCIE,UCSRB);
	}
	else{
		UDR=USART_u8SendData[USART_u8Index];
	}
}
