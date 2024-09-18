#ifndef BIT_MATH_H
#define BIT_MATH_H

//......................................//
#define SET_BIT(bit,reg)                reg|=(1<<bit)
#define CLR_BIT(bit,reg)                reg&=(~(1<<bit))
#define TOG_BIT(bit,reg)                reg^=(1<<bit)
#define GET_BIT(bit,reg)                ((reg&(1<<bit))>>bit)
#define ROT_L(reg,num,NUM_OF_BITs)      ((reg>>num)|(reg<<(NUM_OF_BITs - num)))           
 #define ROT_R(reg,num,NUM_OF_BITs)      ((reg<<num)|(reg>>(NUM_OF_BITs - num)))  
 
#endif
