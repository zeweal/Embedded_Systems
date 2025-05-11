/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_PRIVATE.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Zeweal
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */
 
 #ifndef ADC_PRIVATE_H_
 #define ADC_PRIVATE_H_
 
 
 #define ADMUX *((volatile u8*)0x27)
 // its bits
 #define ADMUX_ADLAR 5  // ADC left adjustment result 
 #define ADMUX_REFS0 6 // refrence selection bit0
 #define ADMUX_REFS1 7 // reference selection bit1
  //////////////////////////////////////
 #define ADCSRA *((volatile u8*)0x26) 
 // its bits
 #define ADCSRA_ADEN  7  // ADC enable
 #define ADCSRA_ADSC  6  // ADC start conversation
 #define ADCSRA_ADATE 5  // ADC auto trigger enable 
 #define ADCSRA_ADIF  4  // flag intrupt 
 #define ADCSRA_ADIE  3  // intrupt enable 
 #define ADCSRA_ADPS2 2  // prescaller bit 2
 #define ADCSRA_ADPS1 1  //prescaller bit 1
 #define ADCSRA_ADPS0 0  // prescaller bit 0
 ///////////////////////////////////////
 #define SFIOR *((volatile u8*)0x50)
 // its bits
 #define SFIOR_ADTS0  5      //Trigger Source bit0
 #define SFIOR_ADTS1  6      //Trigger Source bit1
 #define SFIOR_ADTS2  7      //Trigger Source bit2 

 
 #define ADCH *((volatile u8*)0x25)
 #define ADCL *((volatile u8*)0x24)
 #define ADC_DATA_RE *((volatile u16*)0x24)		//ADC Low + High	

 #define ADC_CH_MASK 0b11100000
 #define ADC_PRE_MASK  0b11111000
 
 #define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1

 
 #endif