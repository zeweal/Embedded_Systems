/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_PROGRAM.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */
 
 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
 
 #include"DIO_INTERFACE.h"
 #include"EXTI_CONFIG.h"
 #include"EXTI_PRIVATE.h"
 #include"EXTI_INTERFACE.h"
 
 void (*EXTI_CallBack[3]) (void) = { NULL } ; 
 
 void EXTI_INIT(void){
	 #ifdef EXTI_LINE
	    #if EXTI_LINE==EXTI_LINE0
		    #if EXTI_SENSE_MODE == EXTI_RAISING_EDGE
			    SET_BIT( MCUCR_REG , 0 );
				SET_BIT( MCUCR_REG , 1 );
			#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
			    CLR_BIT(0,MCUCR_REG); 
			    SET_BIT(1,MCUCR_REG);
			#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
			    CLR_BIT(1,MCUCR_REG);
			    SET_BIT(0,MCUCR_REG);
			#elif EXTI_SENSE_MODE == EXTI_LOW_LEVEL
			    CLR_BIT(1,MCUCR_REG);
				CLR_BIT(0,MCUCR_REG);
            #endif
		#elif EXTI_LINE == EXTI_LINE1
		    #if EXTI_SENSE_MODE == EXTI_RAISING_EDGE
			    SET_BIT( MCUCR_REG , 2 );
				SET_BIT( MCUCR_REG , 3 );
			#elif EXTI_SENSE_MODE == EXTI_FALLING_EDGE
			    CLR_BIT(2,MCUCR_REG); 
			    SET_BIT(3,MCUCR_REG);
			#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
			    CLR_BIT(3,MCUCR_REG); 
			    SET_BIT(2,MCUCR_REG);
			#elif EXTI_SENSE_MODE == EXTI_LOW_LEVEL
			    CLR_BIT(2,MCUCR_REG);
				CLR_BIT(3,MCUCR_REG);
           #endif
		#elif EXTI_LINE == EXTI_LINE2
		#if     EXTI_SENSE_MODE == EXTI_FALLING_EDGE
					CLR_BIT( MCUCSR_REG , 6 );
				#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE
					SET_BIT( MCUCSR_REG , 6 );
				#endif

		#else
				#error "Wrong INT0_SENSE configuration option"
		
		#endif

	#endif
 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 void EXTI_SET_SIGNAL_LATCH(u8 Copy_u8SenseMode,u8 Copy_u8Line){
	 Copy_u8Line = ( 6 - Copy_u8Line ) * 2 ;
	 if( Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <= EXTI_LINE1 ){
	    switch(Copy_u8SenseMode){
		    case EXTI_LOW_LEVEL :    CLR_BIT(Copy_u8Line,MCUCR_REG);         
                                     CLR_BIT(Copy_u8Line+1,MCUCR_REG);
                                     break;
            case EXTI_RAISING_EDGE : SET_BIT(Copy_u8Line,MCUCR_REG);          
                                     SET_BIT(Copy_u8Line+1,MCUCR_REG);
                                     break;
            case EXTI_FALLING_EDGE : CLR_BIT(Copy_u8Line,MCUCR_REG);          
                                     SET_BIT((Copy_u8Line+1),MCUCR_REG);
                                     break;
            case EXTI_ON_CHANGE:     SET_BIT(Copy_u8Line,MCUCR_REG);          
                                     CLR_BIT(Copy_u8Line+1,MCUCR_REG);
                                     break;
	 }
	 }
    else if(Copy_u8Line==EXTI_LINE2){
		switch( Copy_u8SenseMode ){
		case EXTI_FALLING_EDGE : CLR_BIT(6,MCUCSR_REG);  break;
		case EXTI_RAISING_EDGE  : SET_BIT(6,MCUCSR_REG);  break;
	} 
 }
 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 u8   EXTI_DISABLE_INTRUPT(u8 Copy_u8Line){
	 u8 LOC = DIO_OK;
	 if((Copy_u8Line>=EXTI_LINE2) && (Copy_u8Line<=EXTI_LINE1)){
		 CLR_BIT(Copy_u8Line,GICR_REG);
	 }
	 else{
		 LOC=DIO_NOK;
	 }
	 return LOC;
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 u8   EXTI_ENABLE_INTRUPT(u8 Copy_u8Line){
	 u8 LOC = DIO_OK;
	 if((Copy_u8Line>=EXTI_LINE2) && (Copy_u8Line<=EXTI_LINE1)){
		 SET_BIT(Copy_u8Line,GICR_REG);
	 }
	 else{
		 LOC=DIO_NOK;
	 }
	 return LOC;
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 void EXTI_CLEAR_FLAG(u8 Copy_u8Line){
	 if((Copy_u8Line>=EXTI_LINE2) && (Copy_u8Line<=EXTI_LINE1)){
		 SET_BIT(Copy_u8Line,GIFR_REG);
	 }
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 u8 EXTI_u8GetFlag( u8 Copy_u8Line ){
	return GET_BIT(Copy_u8Line,GIFR_REG);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void EXTI_SET_CALL_BACK( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine){
	 if(Copy_pvoidCallBack != NULL){
		 EXTI_CallBack[Copy_u8EXTILine]= Copy_pvoidCallBack;
	 }
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 // ISR_IMPLEMENTATION
 
 //INT0
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXTI_CallBack[0] != NULL){
		EXTI_CallBack[0]();
		EXTI_CLEAR_FLAG(EXTI_LINE0);
	}
}

 //INT1
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXTI_CallBack[1] != NULL){
		EXTI_CallBack[1]();
		EXTI_CLEAR_FLAG(EXTI_LINE1);
	}
}

 //INT2
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(EXTI_CallBack[2] != NULL){
		EXTI_CallBack[2]();
		EXTI_CLEAR_FLAG(EXTI_LINE2);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
