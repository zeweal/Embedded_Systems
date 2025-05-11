/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_PROGRAM.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
 
 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
 
 #include"ADC_INTERFACE.h"
 #include"ADC_CONFIG.h"
 #include"ADC_PRIVATE.h"
 
 
 
 
 /*Global pointer to carry the conversion result in the Asynchronous execution*/
 static u16 * ADC_ASYNC_CONVERSION_Result = NULL;
 
/*Global pointer to function to carry the notification function called by ISR*/
static void (* ADC_NOTIFICATION_FUNCTION)(void)= NULL;

/*Global flag for the ADC ISR State*/
static u8 ADC_ISR_STATE ;

/*Global pointer to carry the chain Channel*/
static u8 * ADC_CHAIN_CHANNEL ;

/*Global variable to carry the chain size*/
static u8 ADC_CHAIN_SIZE ;

/*Global variable to indicate for the current ADC Chain*/
static u8 ADC_INDEX ;

/*Global flag for the ADC Busy State*/
static u8 ADC_STATE = IDLE ;


void ADC_INIT(void){
	// select voltage
	#if ADC_VREF ==AREF
	CLR_BIT(ADMUX_REFS1,ADMUX);
	CLR_BIT(ADMUX_REFS0,ADMUX);
	#elif ADC_VREF == AVCC
	CLR_BIT(ADMUX_REFS1,ADMUX);
	SET_BIT(ADMUX_REFS0,ADMUX);
	#elif ADC_VREF == INTERNAL_2_56
	SET_BIT(ADMUX_REFS0,ADMUX);
	SET_BIT(ADMUX_REFS1,ADMUX);
	#else
		#error 
	#endif
	
	// select adjustment
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX_ADLAR,ADMUX);
	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX_ADLAR,ADMUX);
	#else 
		#error
	#endif
	
	// set prescaller
	ADCSRA &= ADC_PRE_MASK;
	ADCSRA |= ADC_PRESCALLER;
	
	// INT enable
	#if INT_STATUS == INT_ENABLE
	SET_BIT(ADCSRA_ADIE,ADCSRA);
	#elif INT_STATUS == INT_DISABLE
	CLR_BIT(ADCSRA_ADIE,ADCSRA);
	#else
		#error
	#endif
	
	// ADC enable
	#if ADC_STATUS == ADC_ENABLE
	SET_BIT(ADCSRA_ADEN,ADCSRA);
	#elif ADC_STATUS == ADC_DISABLE
	CLR_BIT(ADCSRA_ADEN,ADCSRA);
	#else 
		#error
	#endif
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void ADC_ENABLEE(void){
	 SET_BIT(ADCSRA_ADEN,ADCSRA);
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void ADC_DISABLEE(void){
	 CLR_BIT(ADCSRA_ADEN,ADCSRA);
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void INT_ENABLEE(void){
	 SET_BIT(ADCSRA_ADIE,ADCSRA);
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void INT_DISABLEE(void){
	 CLR_BIT(ADCSRA_ADIE,ADCSRA);
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 ADC_SET_PRESCALLER(u8 Copy_u8Prescaller){
	u8 LOC= OK;
	if(Copy_u8Prescaller <8){
			ADCSRA &= ADC_PRE_MASK;
			ADCSRA |= Copy_u8Prescaller;
	}
	return LOC;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 GET_RESULT_SUNC(u8 Copy_u8Channel,u16 *Copy_u16Result){
	u8 LOC= OK;
	u32 counter =0;
	if(Copy_u16Result != NULL){
		if(ADC_STATE == IDLE){
			ADC_STATE = BUSY ;
			ADMUX &= ADC_CH_MASK;
			ADMUX |= ADC_CHANNEL;
			//start conversion
			SET_BIT(ADCSRA_ADSC,ADCSRA) ;
            while((GET_BIT(ADCSRA_ADIF,ADCSRA)==0)&&(counter<ADC_TIMEOUT)){
				counter++;
			}
			if(counter>=ADC_TIMEOUT){
				LOC = TIMEOUT_STATE;
			}
			else{
				/*Clear the interrupt flag*/
				SET_BIT(ADCSRA_ADIF,ADCSRA) ;
				/*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					*Copy_u16Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*Copy_u16Result = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif
			}
			ADC_STATE= IDLE;
		}
		else{
			LOC= BUSY_STATE;
		}
	}
	else{
		LOC = NULL_POINTER;
	}
	return LOC;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
u8 ADC_START_CONVERSION_ASYNC(u8 Copy_u8Channel, u16 Copy_u16Result, void(*Copy_FUNCTION)(void)){
	u8 LOC= OK ;
	if(Copy_u8Channel != NULL && Copy_FUNCTION != NULL){
		if(ADC_STATE == IDLE){
			ADC_STATE = BUSY;
			/*Set ISR State*/
			ADC_ISR_STATE = SINGLE_CHANNEL_ASYNCH ;
			/*Initialize the global result pointer*/
			ADC_ASYNC_CONVERSION_Result = Copy_u16Result;
			ADC_NOTIFICATION_FUNCTION=Copy_FUNCTION;
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= Copy_u8Channel ;
			/*start conversion */
			SET_BIT(ADCSRA_ADSC,ADCSRA) ;
			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA_ADIE,ADCSRA) ;
		}
		else{
			LOC=BUSY_STATE;
		}
	}
	else{
		LOC= NULL_POINTER;
	}
	return LOC;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 u8 ADC_SINGLE_CHAIN_ASYNC(CHAIN_TOOL *Copy_Chain){
	 u8 LOC = OK;
	 if ((Copy_Chain != NULL) && (Copy_Chain->channel != NULL) && (Copy_Chain->NOTIFICATION_FUNCTION != NULL) && (Copy_Chain->result)){
		 if(ADC_STATE==IDLE){
			 ADC_STATE=BUSY;
			 /*Set ISR State*/
			ADC_ISR_STATE = CHAIN_CHANNEL_ASYNCH ;
			/*Assign the ADC data globally*/
			ADC_ASYNC_CONVERSION_Result = Copy_Chain->result ;
			ADC_CHAIN_CHANNEL = Copy_Chain->channel ;
			ADC_CHAIN_SIZE = Copy_Chain->size ;
			ADC_NOTIFICATION_FUNCTION = Copy_Chain->NOTIFICATION_FUNCTION ;
            ADC_INDEX=0;
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= ADC_CHAIN_CHANNEL[ADC_INDEX] ;
			/*Start Conversion*/
			SET_BIT(ADCSRA_ADSC,ADCSRA) ;
			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADCSRA_ADIE,ADCSRA) ;
		 }
		 else{
			 LOC= BUSY;
		 }
	 }
	 else{
		 LOC=NULL;
	 }
	 return LOC;
 }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void){
	if (ADC_ISR_STATE == SINGLE_CHANNEL_ASYNCH)
	{
		/*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					* ADC_ASYNC_CONVERSION_Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*ADC_ASYNC_CONVERSION_Result = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif

		/*ADC is IDLE*/
		ADC_STATE = IDLE ;

		/*Call Notification Function*/
		ADC_NOTIFICATION_FUNCTION() ;

		/*Disable the Conversion Complete Interrupt*/
		CLR_BIT(ADCSRA_ADIE,ADCSRA) ;
	}
	else{
	   /*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					* ADC_ASYNC_CONVERSION_Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					*ADC_ASYNC_CONVERSION_Result = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif
        ADC_INDEX++ ;
        if (ADC_INDEX == ADC_CHAIN_SIZE)
		{
			/*ADC is IDLE*/
			ADC_STATE = IDLE ;

			/*Call Notification Function*/
			ADC_NOTIFICATION_FUNCTION() ;

			/*Disable the Conversion Complete Interrupt*/
			CLR_BIT(ADCSRA_ADIE,ADCSRA) ;
		}	
        else
		{
			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= ADC_CHAIN_CHANNEL[ADC_INDEX] ;

			/*Start Conversion*/
			SET_BIT(ADCSRA_ADSC,ADCSRA) ;
		}		
	}
}





























