/*
 * LCD_program.c
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */
#include <util/delay.h>
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#define F_cpu 8000000ul


#include "../include/MCAL/DIO/DIO_interface.h"

#include  "../include/HAL/LCD/LCD_interface.h"
#include  "../include/HAL/LCD/LCD_private.h"
#include  "../include/HAL/LCD/LCD_cfg.h"

void HLCD_voidSendCommend(u8 A_u8Command)
{
	//RS--> 0, RW --> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_RS_PIN , DIO_RESET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_RW_PIN , DIO_RESET);

	//set data port with command
	MDIO_voidSetPortValue(LCD_DATA_PORT , A_u8Command);

	//set pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_E_PIN , DIO_RESET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_E_PIN , DIO_SET);
}
void HLCD_voidSendData(u8 A_u8Data)
{
	//RS--> 1, RW --> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_RS_PIN , DIO_SET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_RW_PIN , DIO_RESET);

	//set data port with command
	MDIO_voidSetPortValue(LCD_DATA_PORT , A_u8Data);

	//set pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_E_PIN , DIO_RESET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT , LCD_E_PIN , DIO_SET);
}
void HLCD_voidIntl(void)
{
	//wait more than 30 second
	_delay_ms(32);
	//function set command
	HLCD_voidSendCommend(FUNCTION_SET);
	//wait for more than 39 us
	_delay_ms(1);
	//display on/off control
	HLCD_voidSendCommend(DISPLAY_ON_OFF_CONTROL);
	//wait for more than 39 us
	_delay_ms(1);
	//DISPLAY_CLEAR
	HLCD_voidSendCommend(DISPLAY_CLEAR);
	//wait for more than 1.35 us
	_delay_ms(2);
	//ENTRY MODE SET
	HLCD_voidSendCommend(ENTRY_MODE_SET);


}

void HLCD_voidSendString(u8 *A_Pu8String)
{
	while(*A_Pu8String>0)
	{
		HLCD_voidSendData(*A_Pu8String++);
	}
}

void HLCD_voidClearDiplay(void)
{
	//DISPLAY_CLEAR
	HLCD_voidSendCommend(DISPLAY_CLEAR);
	//wait for more than 1.35 us
	_delay_ms(2);
}


void HLCD_voidGoToPos(LCD_ROW ALcdRowNo,LCD_COL A_LcdColNo)
{
	switch(ALcdRowNo)
	{
		case ROW1 : HLCD_voidSendCommend(LCD_ROW1_ADDDRESS + A_LcdColNo);break;
		case ROW2 : HLCD_voidSendCommend(LCD_ROW2_ADDDRESS + A_LcdColNo);break;
		default : break;
	}
	_delay_ms(1);
}

void HLCD_voidDisplayNumberPositive(u32 A_u32Number)
{
	u32 local_u32Number=1;
	if (A_u32Number==0)
	{
		HLCD_voidSendData('0');
	}
	while(A_u32Number!=0)
	{
		local_u32Number=((local_u32Number*10)+(A_u32Number%10));
		A_u32Number/=10;
	}
	while(local_u32Number!=1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number /=10;
	}
}

void HLCD_voidDisplayNumberNegative(s32 A_s32Number)
{
	u32 local_u32Number=1;
	if (A_s32Number<0)
	{
		HLCD_voidSendData('-');
		A_s32Number*=-1;
	}
	if (A_s32Number==0)
	{
		HLCD_voidSendData('0');
	}
	while(A_s32Number!=0)
	{
		local_u32Number=((local_u32Number*10)+(A_s32Number%10));
		A_s32Number/=10;
	}
	while(local_u32Number!=1)
	{
		HLCD_voidSendData((local_u32Number%10)+48);
		local_u32Number /=10;
	}
}


void HLCD_voidSendSpecialCharecter(u8 *A_u8PatternArr , u8 Au8PatternNumber , LCD_ROW A_LcdRowNo , LCD_COL A_LcdColNo)
{
	u8 local_u8RamAddress;
	//calculate CGRAM Address = Pattern No. * 8
	local_u8RamAddress= Au8PatternNumber * 8;
	SET_BIT(local_u8RamAddress,6);
	//send CGRAM Write command
	HLCD_voidSendCommend(local_u8RamAddress);
	for (u8 i = 0; i < 8; i++)
	{
		HLCD_voidSendData(A_u8PatternArr[i]);
	}
	// send go to position command to the DDRAM
	HLCD_voidGoToPos(A_LcdRowNo , A_LcdColNo);
	//display pattern
	HLCD_voidSendData(Au8PatternNumber);
}


