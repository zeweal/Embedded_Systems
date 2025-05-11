/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    GIE_PROGRAM.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : GIE
 *
 */
 
 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
 
 #include"DIO_INTERFACE.h"
 #include"GIE_PRIVATE.h"
 #include"GIE_INTERFACE.h"
 
  void GIE_ENABLE(void){
	  SET_BIT(SREG_I,SREG);
  }
  
  void GIE_DISABLE(void){
	  CLR_BIT(SREG_I,SREG);
  }
  