#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void USART_INIT();
u8 USART_SEND_DATA(u8 Copy_u8Data);
u8 USART_SEND_STRING_ASYNCH(const u8 * Copy_pchString , void (* NotificationFunc)(void));
u8 USART_SEND_STRING_SYNCH(const u8 * Copy_pchString);
u8 USART_RECIEVE_DATA(u8 *RecievedData);
u8 USART_RECIEVE_BUFFER_ASYNCH(u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void));
u8 USART_RECIEVE_BUFFER_SYNCH(u8 * Copy_pchString , u32 Copy_uint32BufferSize);

#endif
