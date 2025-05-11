/*
//////////////////////////////////////////////////////////////////////SW_INTERFACE.h\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 *  Author : Abdallah Zeweal
 *  Layer  : HAL
 *  SWC    : Switch
 *
 */
 #ifndef SW_INTERFACE_H_
 #define SW_INTERFACE_H_
 
 
 #define SW_PRESSED 1
 #define SW_NOT_PRESSED 0
  
 /* 
 $ Optins of State :-
	 1- SW_INT_PULL_UP
	 2- SW_EXT_PULL_UP
	 3- SW_EXT_PULL_DOWN
	 4- SW_FLOATING

 */
 #define SW_INT_PULL_UP   0
 #define SW_EXT_PULL_UP   1
 #define SW_EXT_PULL_DOWN 2
 #define SW_FLOATING      3  
 
 
 typedef struct{
	 u8 PORT;
	 u8 PIN;
	 u8 PULL_STATE;
 }SW_TYPE;
  
 
 // SW_FUNCTIONS
 void SW_INIT(SW_TYPE SW_CONFIG);
 u8   SW_GET_PRESSED(SW_TYPE SW_CONFIG);
 
 #endif