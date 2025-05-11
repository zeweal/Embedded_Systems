#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define FREQUENCY_SYSTEM  8000000UL
#define USART_BAUD_RATE   9600UL
#define TIME_OUT          10000UL

/* Set Multi-Processor Communication mode
 * ENABLE
 * DISABLE
 */
#define USART_MPCM           DISABLE

/*Set RX Complete Interrupt Enable
 * DISABLE
 * ENABLE
 */
#define USART_RX_COMPLETE_INTERRUPT		DISABLE

/*Set TX Complete Interrupt Enable
 * DISABLE
 * ENABLE
 */
#define USART_TX_COMPLETE_INTERRUPT		DISABLE

/* Set UDR empty intrupt enable 
 * ENABLE
 * DISABLE
*/
#define USART_EMPTY_INTERRUPT            DISABLE

/* RX ENABLE
 * ENABLE
 * DISABLE
*/
#define USART_RECIEVER_ENABLE             ENABLE

/* TX ENABLE
 * ENABLE
 * DISABLE
 */
#define USART_TRANSMITTER_ENABLE          ENABLE


/*Set System Speed
 * choose between
 * 1. USART_X1
 * 2. USART_X2  (Double Speed Mode)
 */
#define USART_SYSTEM_SPEED				USART_X1

/* bit size 
 * DATA_SIZE_5_BIT
 * DATA_SIZE_6_BIT
 * DATA_SIZE_7_BIT
 * DATA_SIZE_8_BIT
 * DATA_SIZE_9_BIT
*/
#define USART_DATA_SIZE                    DATA_SIZE_8_BIT

/* set clock polarity (SYNCH only)
 * XCK_RISING_TX_XCH_FALLING_RX			
 * XCK_RISING_RX_XCH_FALLING_TX			
*/
#define USART_CLOCK_POLARITY       XCK_RISING_TX_XCH_FALLING_RX

/* stop bits 
 * ONE_BIT 
 * TWO_BITS
*/
#define USART_STOP_BIT                     ONE_BIT

/* Set parity mode 
 * DISABLED   
 * ENABLE_EVEN
 * ENABLE_ODD 
*/
#define USART_PARITY_MODE                   DISABLED

/* USART_CLOCK_SELECT
 * SYNCH 
 * ASYNCH
*/
#define USART_MODE                    ASYNCH


#endif
