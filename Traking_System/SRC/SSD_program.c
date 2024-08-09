/*
 * SSD_program.c
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */
#include <util/delay.h>
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#define F_cpu 8000000ul


#include "../include/MCAL/DIO/DIO_interface.h"

#include  "../include/HAL/SSD/SSD_interface.h"
#include  "../include/HAL/SSD/SSD_private.h"
#include  "../include/HAL/SSD/SSD_cfg.h"


void HSSD_DisplayNumber(DIO_PORTS A_DIOPort , u8 A_u8Number)
{
	switch (A_u8Number)
	{
		case 0: MDIO_voidSetPortValue(A_DIOPort,ZERO);  break;
		case 1: MDIO_voidSetPortValue(A_DIOPort,ONE);   break;
		case 2: MDIO_voidSetPortValue(A_DIOPort,TWO);   break;
		case 3: MDIO_voidSetPortValue(A_DIOPort,THREE); break;
		case 4: MDIO_voidSetPortValue(A_DIOPort,FOUR);  break;
		case 5: MDIO_voidSetPortValue(A_DIOPort,FIVE);  break;
		case 6: MDIO_voidSetPortValue(A_DIOPort,SIX);   break;
		case 7: MDIO_voidSetPortValue(A_DIOPort,SEVEN); break;
		case 8: MDIO_voidSetPortValue(A_DIOPort,EIGHT); break;
		case 9: MDIO_voidSetPortValue(A_DIOPort,NINE);  break;
		default:break;
	}
}
void HSSD_voidDisplayAscending(DIO_PORTS A_DIOPort,u16 A_u16DelayMs)
{
	for (u8 i=0 ; i<10 ; i++)
	{
		HSSD_DisplayNumber(A_DIOPort , i);
		_delay_ms(A_u16DelayMs);
	}
}
void HSSD_voidDisplayDescending(DIO_PORTS A_DIOPort,u16 A_u16DelayMs)
{
	for (s8 i=9 ; i>=0 ; i--)//sign char to be continue count is it unsign it stop after finish one loop
		{
			HSSD_DisplayNumber(A_DIOPort , i);
			_delay_ms(A_u16DelayMs);
		}
}







