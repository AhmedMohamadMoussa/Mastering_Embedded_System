/*
 * UART_interface.h
 *
 *  Created on: Oct 13, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

//asynchronous 0
//synchronous 1
#define Mode_Select asynchronous

typedef enum{
	UART_RX_INTERRUPTS=0,
	UART_UDRE_INTERRUPTS,
	UART_TX_INTERRUPTS
}UART_INTERRUPTS;
void MUART_voidInit(void);
void MUART_voidSendByteSyncBlocking(u8 A_u8DataByte);
void MUART_voidSendByteSyncNonBlocking(u8 A_u8DataByte);
void MUART_voidSendStringSyncNonBlocking(u8 *A_u8String);
void MUART_voidSendByteASync(u8 A_u8DataByte);
u8 MUART_u8ReadByteSyncBlocking(void);
u8 MUART_u8ReadByteASync(void);
u8 MUART_u8ReadByteSyncNonBlocking(void);
void MUART_voidSetCallBack(UART_INTERRUPTS A_InterruptSource , void(*A_PtoFunc)(void));

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
