/*
 * UART_private.h
 *
 *  Created on: Oct 13, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

#define UDR_Reg (*(volatile u8*)0x2C)
#define UCSRA_Reg (*(volatile u8*)0x2B)
#define UCSRB_Reg (*(volatile u8*)0x2A)
#define UCSRC_Reg (*(volatile u8*)0x40)
#define UBRRL_Reg (*(volatile u8*)0x29)
#define UBRRH_Reg (*(volatile u8*)0x40)


#define BAUD_RATE_EQUATION (F_CPU/16/BaudRate_Value-1)

#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
