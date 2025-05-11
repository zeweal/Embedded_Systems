/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    KPD_PROGRAM.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : HAL
 *  SWC    : KPD
 *
 */
 
 #include"STD_TYPES.h"
 #include"BIT_MATH.h"
 
 #include"DIO_INTERFACE.h"
 
 #include"KPD_INTERFACE.h"
 #include"KPD_CONFIG.h"
 #include"KPD_PRIVATE.h"
#include"util/delay.h"
 
 void KPD_INIT(void){
	 //for the input
	 DIO_CONNECT_PULL_UP(KPD_PORT,KPD_R0,DIO_PIN_HIGH);
	 DIO_CONNECT_PULL_UP(KPD_PORT,KPD_R1,DIO_PIN_HIGH);
	 DIO_CONNECT_PULL_UP(KPD_PORT,KPD_R2,DIO_PIN_HIGH);
	 DIO_CONNECT_PULL_UP(KPD_PORT,KPD_R3,DIO_PIN_HIGH);
	 //for the output
	 DIO_SET_PIN_DIRECTION(KPD_PORT,KPD_C0,DIO_PIN_OUTPUT);
	 DIO_SET_PIN_DIRECTION(KPD_PORT,KPD_C1,DIO_PIN_OUTPUT);
	 DIO_SET_PIN_DIRECTION(KPD_PORT,KPD_C2,DIO_PIN_OUTPUT);
	 DIO_SET_PIN_DIRECTION(KPD_PORT,KPD_C3,DIO_PIN_OUTPUT);
	 //for the value
	 DIO_SET_PIN_VALUE(KPD_PORT,KPD_C0,DIO_PIN_HIGH);
	 DIO_SET_PIN_VALUE(KPD_PORT,KPD_C1,DIO_PIN_HIGH);
	 DIO_SET_PIN_VALUE(KPD_PORT,KPD_C2,DIO_PIN_HIGH);
	 DIO_SET_PIN_VALUE(KPD_PORT,KPD_C3,DIO_PIN_HIGH);
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 u8   KPD_GET_PRESSED(void){
	 u8 LOC=NOT_PRESSED;
	 u8 data;
	 //iterators
	 u8 row;
	 u8 col;
	 for(col = 0 + KPD_COL_INIT;col <= KPD_COL_END ; col++){
		 DIO_SET_PIN_VALUE(KPD_PORT,col,DIO_PIN_LOW);
		 for(row=0+KPD_ROW_INIT;row <= KPD_ROW_END ; row++){
			 DIO_GET_PIN_VALUE(KPD_PORT,row,&data);
			 if(data==0){
				 _delay_ms(50);
				 DIO_GET_PIN_VALUE(KPD_PORT,row,&data);
				 if(data==0){
					 LOC= KPD_Buttons[row-KPD_ROW_INIT][col-KPD_COL_INIT];
				 }
				 DIO_GET_PIN_VALUE(KPD_PORT,row,&data);
				 while(DIO_PIN_LOW==data){
					 DIO_GET_PIN_VALUE(KPD_PORT,row,&data);
				 }
				 break;
			 }
		 }
		 DIO_SET_PIN_VALUE(KPD_PORT,col,DIO_PIN_HIGH);
	 }
	 return LOC;
 }
