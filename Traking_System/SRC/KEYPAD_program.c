/*
 * KEYPAD_program.c
 *
 *  Created on: Jul 9, 2023
 *      Author: User
 */
#include <util/delay.h>
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#define F_cpu 8000000ul


#include "../include/MCAL/DIO/DIO_interface.h"

#include  "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include  "../include/HAL/KEYPAD/KEYPAD_privat.h"
#include  "../include/HAL/KEYPAD/KEYPAD_cfg.h"



u8 static Global_u8ArrOFRows [ROW_NO] = KEYPAD_ROWS;
u8 static Global_u8ArrOFCols [ROW_NO] = KEYPAD_COLS;



u8 HKEYPAD_u8GetPressdKey(void)
{
	u8 local_u8KeyValue = KEY_NOT_PRESSED;

	u8 local_u8RowCounter = 0 , local_u8ColCounter = 0 , local_u8PinValue , local_u8flag = 0;
	for (local_u8RowCounter = 0; local_u8RowCounter < ROW_NO; local_u8RowCounter++)
	{
		//active one row
		MDIO_voidSetPinStatus(KEYPAD_PORT , Global_u8ArrOFRows[local_u8RowCounter] , DIO_RESET);
		for (local_u8ColCounter = 0; local_u8ColCounter < COL_NO ; local_u8ColCounter++)
		{
			//READ COL
			local_u8PinValue = MDIO_PinStatusGetPin( KEYPAD_PORT , Global_u8ArrOFCols[local_u8ColCounter] );
			if (local_u8PinValue == KEYPAD_PRESSED)
			{
				//delay for bouncing effect
				_delay_ms(KEYPAD_DEPOUSING_DELAY);
				local_u8PinValue = MDIO_PinStatusGetPin( KEYPAD_PORT , Global_u8ArrOFCols[local_u8ColCounter] );
				if (local_u8PinValue == KEYPAD_PRESSED)
				{
					while(local_u8PinValue == KEYPAD_PRESSED)
					{
						local_u8PinValue = MDIO_PinStatusGetPin( KEYPAD_PORT , Global_u8ArrOFCols[local_u8ColCounter] );
					}

					local_u8KeyValue = Global_u8ArrOFKeyValues[local_u8RowCounter][local_u8ColCounter];
					local_u8flag = FLAG_UP;
					break;
				}
			}
		}

		//deactive row
		MDIO_voidSetPinStatus(KEYPAD_PORT , Global_u8ArrOFRows[local_u8RowCounter] , DIO_SET);
		if (local_u8flag == FLAG_UP)
		{
			break;
		}
	}



	return local_u8KeyValue;
}
