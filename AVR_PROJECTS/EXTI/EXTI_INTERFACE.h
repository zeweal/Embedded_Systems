/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_INTERFACE.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */
 
 #ifndef EXTI_INTERFACE_H_
 #define EXTI_INTERFACE_H_
 
 //define the external intrupts
 #define EXTI_LINE0  6
 #define EXTI_LINE1  7
 #define EXTI_LINE2  5
 
 //define sense mode
 #define EXTI_RAISING_EDGE  0
 #define EXTI_FALLING_EDGE  1
 #define EXTI_ON_CHANGE     2
 #define EXTI_LOW_LEVEL     3
 
 #define NULL 0
 
 //functions
 void EXTI_INIT(void);
 void EXTI_SET_SIGNAL_LATCH(u8 Copy_u8SenseMode,u8 Copy_u8Line);
 u8   EXTI_DISABLE_INTRUPT(u8 Copy_u8Line);
 u8   EXTI_ENABLE_INTRUPT(u8 Copy_u8Line);
 void EXTI_CLEAR_FLAG(u8 Copy_u8Line);
 void EXTI_SET_CALL_BACK( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine);
 
 #endif
