/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_INTERFACE.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
 #ifndef ADC_INTERFACE_H_
 #define ADC_INTERFACE_H_
 
 #define ADC_Enable  1
 #define ADC_Disable 0
  
 #define INT_ENABLE  1
 #define INT_DISABLE 0
  
 #define AREF             0
 #define AVCC             1  
 #define INTERNAL_2_56    3
 
 #define RIGHT_ADJUSTMENT 0
 #define LEFT_ADJUSTMENT  1
 
 #define ADC_CHANNEL0 0
 #define ADC_CHANNEL1 1
 #define ADC_CHANNEL2 2
 #define ADC_CHANNEL3 3
 #define ADC_CHANNEL4 4
 #define ADC_CHANNEL5 5
 #define ADC_CHANNEL6 6
 #define ADC_CHANNEL7 7
 
 #define ADC_SINGLE_CONVERSION  0
 #define ADC_FREE_RUNNING       1
 #define ADC_ANALOG_COMPARATOR  2
 #define ADC_EXTI0              3
 #define ADC_TIM0_CTC           4
 #define ADC_TIM0_OVF           5
 #define ADC_TIM1_CTC_CHANNEL_B 6
 #define ADC_TIM1_OVF           7
 #define ADC_TIM1_ICU           8
 
 #define ADC_PRE_2              0
 #define ADC_PRE_4              2
 #define ADC_PRE_8              3
 #define ADC_PRE_16             4
 #define ADC_PRE_32             5
 #define ADC_PRE_64             6
 #define ADC_PRE_128            7
 

 
 typedef struct{
	 u8 channel;
	 u16 *result;
	 u8  size;
	 void(*NOTIFICATION_FUNCTION)(void);
 }CHAIN_TOOL;
 
 
 void ADC_INIT(void);
 u8 GET_RESULT_SUNC(u8 Copy_u8Channel,u16 *Copy_u16Result);
 u8 ADC_START_CONVERSION_ASYNC(u8 Copy_u8Channel, u16 Copy_u16Result, void(*Copy_FUNCTION)(void));
 u8 ADC_SINGLE_CHAIN_ASYNC(CHAIN_TOOL *Copy_CHAIN);
 
 void ADC_ENABLEE(void);
 void ADC_DISABLEE(void);
 void INT_ENABLEE(void);
 void INT_DISABLEE(void);
 
 u8 ADC_SET_PRESCALLER(u8 Copy_u8Prescaller);
 
 #endif
 
 
 
 
 
 
 
 
 
 
 
 
 
 
