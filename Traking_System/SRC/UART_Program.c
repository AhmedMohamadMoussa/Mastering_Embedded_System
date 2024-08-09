/*
 * UART_Interface.c
 *
 *  Created on: Oct 13, 2023
 *      Author: User
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/UART/UART_interface.h"
#include "../include/MCAL/UART/UART_private.h"
#include "../include/MCAL/UART/UART_cfg.h"

#define F_cpu 8000000ul
#define NULL 0
static void (*FuncPtr[3]) (void) ={NULL,NULL,NULL};

void MUART_voidInit(void)
{
	u16 local_u16BaudRateValue  =BAUD_RATE_EQUATION;
	//set boudrate
	UBRRL_Reg =(u8)local_u16BaudRateValue;
	UBRRH_Reg =(u8)(local_u16BaudRateValue >> 8);
	//character size 8 bit
	CLR_BIT(UCSRB_Reg,2);
	//mode asynchronous operation
	//parity disabled
	//1 stop bit
	UCSRC_Reg=CONC_BIT(1,0,0,0,0,1,1,0);
	//enable receiver
	SET_BIT(UCSRB_Reg,4);
	//enable transmitter
	SET_BIT(UCSRB_Reg,3);
}
void MUART_voidSendByteSyncBlocking(u8 A_u8DataByte)
{
	//wait until UDRE_REG is empty
	while(GET_BIT(UCSRA_Reg,5)==0);
	//set Data into Tx register and start Transmission
	UDR_Reg= A_u8DataByte;
	//wait until UDRE_REG is empty
	while(GET_BIT(UCSRA_Reg,5)==0);
	//CLEAR transmit interrupt flag
	SET_BIT(UCSRA_Reg,6);
}
void MUART_voidSendByteSyncNonBlocking(u8 A_u8DataByte)
{
	u32 local_u32TimeOut =0;
	//wait until UDRE_REG is empty or time out
	while(GET_BIT(UCSRA_Reg,5)==0)
	{
		local_u32TimeOut++;
		if (local_u32TimeOut==NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}
	if (local_u32TimeOut!=NON_BLOCKING_TIME_OUT)
	{
		local_u32TimeOut=0;
		//set Data into Tx register and start Transmission
		UDR_Reg= A_u8DataByte;
		//wait until UDRE_REG is empty or time out
		while(GET_BIT(UCSRA_Reg,5)==0)
		{
			local_u32TimeOut++;
			if (local_u32TimeOut==NON_BLOCKING_TIME_OUT)
			{
				break;
			}
		}
		//CLEAR transmit interrupt flag
		SET_BIT(UCSRA_Reg,6);
	}
}

void MUART_voidSendStringSyncNonBlocking(u8 *A_u8String)
{
	while(*A_u8String>0)
	{
		MUART_voidSendByteSyncNonBlocking(*A_u8String++);
	}
}

void MUART_voidSendByteASync(u8 A_u8DataByte)
{
	if (GET_BIT(UCSRA_Reg,5)==1)
	{
		UDR_Reg=A_u8DataByte;
	}
}

u8 MUART_u8ReadByteSyncBlocking(void)
{
	//wait for Rx Flag
	while(GET_BIT(UCSRA_Reg,7)==0);
	return UDR_Reg;
}

u8 MUART_u8ReadByteASync(void)
{
	return UDR_Reg;
}

u8 MUART_u8ReadByteSyncNonBlocking(void)
{
	u8 local_u8value = NO_VALUE_RETURNED;
	//wait for Rx Flag
	u32 local_u32TimeOut =0;
	//wait until Rx flag is up
	while(GET_BIT(UCSRA_Reg,7)==0)
	{
		local_u32TimeOut++;
		if (local_u32TimeOut==NON_BLOCKING_TIME_OUT)
		{
			break;
		}
	}
	if(local_u32TimeOut!= NON_BLOCKING_TIME_OUT)
	{local_u8value=UDR_Reg;}
	return UDR_Reg;
}

void MUART_voidSetCallBack(UART_INTERRUPTS A_InterruptSource , void(*A_PtoFunc)(void))
{
	if( (A_InterruptSource <=UART_TX_INTERRUPTS) && (A_PtoFunc != NULL) )
	{
		FuncPtr[A_InterruptSource] = A_PtoFunc;
	}
}

void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(FuncPtr[UART_RX_INTERRUPTS] != NULL)
	{
		FuncPtr[UART_RX_INTERRUPTS]();
	}
}

void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{
	if(FuncPtr[UART_UDRE_INTERRUPTS] != NULL)
	{
		FuncPtr[UART_UDRE_INTERRUPTS]();
	}
}

void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{
	if(FuncPtr[UART_TX_INTERRUPTS] != NULL)
	{
		FuncPtr[UART_TX_INTERRUPTS]();
	}
}




