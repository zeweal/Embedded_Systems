/*
***************************************************************DIO_PROGRAM.C*************************************************************************
Author : Abdallah Zeweal
Layer : MCAL
SWC : GPIO
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h"
#include "DIO_CONFIG.h"

///////////////////////////////////////////////////////////////////////INPUT FUNCTIONS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*
* Berief:
      =>this function is used to set the direction of the pin (0->input,1->output)
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_SET_PIN_DIRECTION(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8DIRECTION){
	DIO_ERROR_STATUS LOC_STATE= DIO_OK;
	if((Copy_u8PORT<=DIO_PORTD)&&(Copy_u8PIN<=DIO_PIN7)){
		    if(Copy_u8DIRECTION==DIO_PIN_OUTPUT){
		         switch(Copy_u8PORT){
		         	case DIO_PORTA: SET_BIT(Copy_u8PIN,DDRA_Register); break;
		         	case DIO_PORTB: SET_BIT(Copy_u8PIN,DDRB_Register); break;
		         	case DIO_PORTC: SET_BIT(Copy_u8PIN,DDRC_Register); break;
		         	case DIO_PORTD: SET_BIT(Copy_u8PIN,DDRD_Register); break;
		         }	
		    }
	
		    else if(Copy_u8DIRECTION==DIO_PIN_INPUT){
			     switch(Copy_u8PORT){
			         case DIO_PORTA: CLR_BIT(Copy_u8PIN,DDRA_Register); break;
			         case DIO_PORTB: CLR_BIT(Copy_u8PIN,DDRB_Register); break;
			         case DIO_PORTC: CLR_BIT(Copy_u8PIN,DDRC_Register); break;
			         case DIO_PORTD: CLR_BIT(Copy_u8PIN,DDRD_Register); break;
		         }	
			}
		    else {
			    LOC_STATE=DIO_NOK;
		    }
	}
	else {
			LOC_STATE=DIO_NOK;
	}
		return LOC_STATE;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to set the value of the pin 
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8VALUE --> Pin Direction [ DIO_PIN_HIGH , DIO_PIN_LOW ]
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_SET_PIN_VALUE(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8VALUE){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if((Copy_u8PIN<=DIO_PIN7)&&(Copy_u8PORT<=DIO_PORTD)){
		if(Copy_u8VALUE==DIO_PIN_HIGH){
		         switch(Copy_u8PORT){
		         	 case DIO_PORTA: SET_BIT(Copy_u8PIN,PORTA_Register); break;
		         	 case DIO_PORTB: SET_BIT(Copy_u8PIN,PORTB_Register); break;
		         	 case DIO_PORTC: SET_BIT(Copy_u8PIN,PORTC_Register); break;
		         	 case DIO_PORTD: SET_BIT(Copy_u8PIN,PORTD_Register); break;
		         }
	    }
	    else if (Copy_u8VALUE==DIO_PIN_LOW){
		         switch(Copy_u8PORT){
		         	 case DIO_PORTA: CLR_BIT(Copy_u8PIN,PORTA_Register); break;
		         	 case DIO_PORTB: CLR_BIT(Copy_u8PIN,PORTB_Register); break;
		         	 case DIO_PORTC: CLR_BIT(Copy_u8PIN,PORTC_Register); break;
		         	 case DIO_PORTD: CLR_BIT(Copy_u8PIN,PORTD_Register); break;
		         }
	    }
	
	    else{
	    	     LOC_STATE=DIO_NOK;
        }
	}
	else {
			LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to get the value of the pin
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>*Copy_PTR_DATA --> pointer recieve pin value
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_GET_PIN_VALUE(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 * Copy_PTR_DATA){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if((Copy_u8PORT<=DIO_PORTD)&&(Copy_u8PIN<=DIO_PIN7)){
		         switch(Copy_u8PORT){
			         case DIO_PORTA: * Copy_PTR_DATA= GET_BIT(Copy_u8PIN,PINA_Register); break;
		         	 case DIO_PORTB: * Copy_PTR_DATA= GET_BIT(Copy_u8PIN,PINB_Register); break;
		         	 case DIO_PORTC: * Copy_PTR_DATA= GET_BIT(Copy_u8PIN,PINC_Register); break;
		         	 case DIO_PORTD: * Copy_PTR_DATA= GET_BIT(Copy_u8PIN,PIND_Register); break;
		         }
		
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to toggle pin value
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
* Return : 
      =>its state
*/


DIO_ERROR_STATUS DIO_TOGGLE_PIN_VALUE(u8 Copy_u8PORT,u8 Copy_u8PIN){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if((Copy_u8PORT<=DIO_PORTD)&&(Copy_u8PIN<=DIO_PIN7)){
		         switch(Copy_u8PORT){
					 case DIO_PORTA: TOG_BIT(Copy_u8PIN,PINA_Register); break;
		         	 case DIO_PORTB: TOG_BIT(Copy_u8PIN,PINB_Register); break;
		         	 case DIO_PORTC: TOG_BIT(Copy_u8PIN,PINC_Register); break;
		         	 case DIO_PORTD: TOG_BIT(Copy_u8PIN,PIND_Register); break;
				 } 
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////PORT FUNCTIONS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*
* Berief:
      =>this function is used to set the direction of the port
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8Direction --> Pin Direction [ DIO_PORT_OUTPUT , DIO_PORT_INPUT ]
* Return : 
      =>its state
*/

DIO_ERROR_STATUS DIO_SET_PORT_DIRECTION(u8 Copy_u8PORT,u8 Copy_u8DIRECTION){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if(Copy_u8PORT<=DIO_PORTD){
	  	                  switch(Copy_u8PORT){
				            case DIO_PORTA: DDRA_Register=Copy_u8DIRECTION; break;
		                   	case DIO_PORTB: DDRB_Register=Copy_u8DIRECTION; break;
		                   	case DIO_PORTC: DDRC_Register=Copy_u8DIRECTION; break;
		                   	case DIO_PORTD: DDRD_Register=Copy_u8DIRECTION; break;
                            default: LOC_STATE=DIO_NOK;                      break;							
				          }
	}
	else{
	 LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to set prt value
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8VALUE  --> Port value [DIO_PORT_HIGH , DIO_PORT_LOW ]

* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_SET_PORT_VALUE(u8 Copy_u8PORT,u8 Copy_u8VALUE){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if((Copy_u8PORT<=DIO_PORTD)&&(Copy_u8VALUE<=255||Copy_u8VALUE==DIO_PORT_HIGH||Copy_u8VALUE==DIO_PORT_LOW)){
	  	                  switch(Copy_u8PORT){
				            case DIO_PORTA: PORTA_Register=Copy_u8VALUE; break;
		                   	case DIO_PORTB: PORTB_Register=Copy_u8VALUE; break;
		                   	case DIO_PORTC: PORTC_Register=Copy_u8VALUE; break;
		                   	case DIO_PORTD: PORTD_Register=Copy_u8VALUE; break;
                            default: LOC_STATE=DIO_NOK;            break;							
				          }
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to get port value
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>*Copy_PTR_DATA --> pointer recieve port value
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_GET_PORT_VALUE(u8 Copy_u8PORT,u8 * Copy_PTR_DATA){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if(Copy_u8PORT<=DIO_PORTD){
	  	                  switch(Copy_u8PORT){
				            case DIO_PORTA: * Copy_PTR_DATA=PINA_Register; break;
		                   	case DIO_PORTB: * Copy_PTR_DATA=PINB_Register; break;
		                   	case DIO_PORTC: * Copy_PTR_DATA=PINC_Register; break;
		                   	case DIO_PORTD: * Copy_PTR_DATA=PIND_Register; break;
                            default :LOC_STATE=DIO_NOK;                     break;							
				          }
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to toggle port value
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_TOGGLE_PORT_VALUE(u8 Copy_u8PORT){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if(Copy_u8PORT<=DIO_PORTD){
		                  switch(Copy_u8PORT){
		                  	 case DIO_PORTA: PORTA_Register=~(PORTA_Register); break;
		                   	 case DIO_PORTB: PORTB_Register=~(PORTB_Register); break;
		                   	 case DIO_PORTC: PORTC_Register=~(PORTC_Register); break;
		                   	 case DIO_PORTD: PORTD_Register=~(PORTD_Register); break;
                             default: LOC_STATE=DIO_NOK;                        break;	
		                  }
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DIO_ERROR_STATUS DIO_CONNECT_PULL_UP(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8CONNECT_PULL_up){
   DIO_ERROR_STATUS LOC_STATE=DIO_OK;
   if( (Copy_u8PORT<=DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7) ){
	   switch(Copy_u8PORT){
		   case(DIO_PORTA):
		        if(Copy_u8CONNECT_PULL_up==DIO_PIN_HIGH){
		           CLR_BIT(PUD,SFIOR);
		           CLR_BIT(Copy_u8PIN,DDRA_Register);
		           SET_BIT(Copy_u8PIN,PORTA_Register);
		        }
		        else{
		           CLR_BIT(Copy_u8PIN,PORTA_Register);
		        }
		        break;
		   case(DIO_PORTB):
		        if(Copy_u8CONNECT_PULL_up==DIO_PIN_HIGH){
			       CLR_BIT(PUD,SFIOR);
			       CLR_BIT(Copy_u8PIN,DDRB_Register);
			       SET_BIT(Copy_u8PIN,PORTB_Register);
		        }
		        else{
			       CLR_BIT(Copy_u8PIN,PORTB_Register);
		        }
		        break;
		   case(DIO_PORTC):
		        if(Copy_u8CONNECT_PULL_up==DIO_PIN_HIGH){
			       CLR_BIT(PUD,SFIOR);
			       CLR_BIT(Copy_u8PIN,DDRC_Register);
			       SET_BIT(Copy_u8PIN,PORTC_Register);
		        }
		        else{
			       CLR_BIT(Copy_u8PIN,PORTC_Register);
		        }
		        break;
			case(DIO_PORTD):
		        if(Copy_u8CONNECT_PULL_up==DIO_PIN_HIGH){
			       CLR_BIT(PUD,SFIOR);
			       CLR_BIT(Copy_u8PIN,DDRD_Register);
			       SET_BIT(Copy_u8PIN,PORTD_Register);
		        }
		        else{
			       CLR_BIT(Copy_u8PIN,PORTD_Register);
		        }
		        break;
	   }
   }
   else{
	   LOC_STATE=DIO_NOK;
   }
   return LOC_STATE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
* Berief:
      =>this function is used to write in the upper pins (pin4 -->pin7)
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
      =>Copy_u8VALUE --> to set its high bits on high nibble of register
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_WRITE_HIGH_NIBBLES (u8 Copy_u8PORT,u8 Copy_u8VALUE){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if(Copy_u8PORT<=DIO_PORTD){
		    Copy_u8VALUE=(Copy_u8VALUE<<4);
		                  switch(Copy_u8PORT){
		                  	 case DIO_PORTA: PORTA_Register &=0x0f;
							 PORTA_Register |= Copy_u8VALUE;
							 break;
		                   	 case DIO_PORTB: PORTB_Register &=0x0f;
							 PORTB_Register |= Copy_u8VALUE;
							 break;
		                   	 case DIO_PORTC: PORTC_Register &=0x0f;
							 PORTC_Register |= Copy_u8VALUE;
							 break;
		                   	 case DIO_PORTD: PORTD_Register &=0x0f;
							 PORTD_Register |= Copy_u8VALUE;
							 break;
                            
		                  }
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Berief:
      =>this function is used to write in the lower pins (pin0 -->pin3)
* Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
      =>Copy_u8VALUE --> to set its lower bits on lower nibble of register
* Return : 
      =>its state
*/
DIO_ERROR_STATUS DIO_WRITE_LOW_NIBBLES (u8 Copy_u8PORT,u8 Copy_u8VALUE){
	DIO_ERROR_STATUS LOC_STATE=DIO_OK;
	if(Copy_u8PORT<=DIO_PORTD){
		            Copy_u8VALUE &= 0x0f;
		                  switch(Copy_u8PORT){
		                  	 case DIO_PORTA: PORTA_Register &=0xf0;
							 PORTA_Register |= Copy_u8VALUE;     
							 break;                             
		                   	 case DIO_PORTB: PORTB_Register &=0xf0;
							 PORTB_Register |= Copy_u8VALUE ;    
							 break;                             
		                   	 case DIO_PORTC: PORTC_Register &=0xf0;
							 PORTC_Register |= Copy_u8VALUE   ;  
							 break;                             
		                   	 case DIO_PORTD: PORTD_Register &=0xf0;
							 PORTD_Register |= Copy_u8VALUE;
							 break;
                             	
		                  }
	}
	else{
		LOC_STATE=DIO_NOK;
	}
	return LOC_STATE;
}
