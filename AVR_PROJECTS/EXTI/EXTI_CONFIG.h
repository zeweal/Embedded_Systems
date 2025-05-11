/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    EXTI_CONFIG.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : EXTI
 *
 */
 
 #ifndef EXTI_config_H_
 #define EXTI_config_H_
 
 /*
 Options :-

 	 1-EXTI_LINE0
 	 2-EXTI_LINE1
 	 3-EXTI_LINE2

 */
 
 #define EXTI_LINE EXTI_LINE0
 
 /*
 Options :-

 	 1-EXTI_RAISING_EDGE
 	 2-EXTI_FALLING_EDGE
 	 3-EXTI_ON_CHANGE
	 4-EXTI_LOW_LEVEL

 */
 
 #define EXTI_SENSE_MODE EXTI_FALLING_EDGE
 
 #endif
