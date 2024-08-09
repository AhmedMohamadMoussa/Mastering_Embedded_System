/*
 * LED_program.c
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include  "../include/HAL/LED/LED_interface.h"
#include  "../include/HAL/LED/LED_private.h"
#include  "../include/HAL/LED/LED_cfg.h"

void HAL_voidSetLedStatus(DIO_PORTS A_DIOPort , DIO_PINS A_DIOPin , LED_STATUS A_LedStatus)
{
	MDIO_voidSetPinStatus(A_DIOPort ,A_DIOPin ,A_LedStatus);
}
void HAL_voidToggleLedStatus(DIO_PORTS A_DIOPort , DIO_PINS A_DIOPin )
{
	MDIO_voidTogglePinValue( A_DIOPort , A_DIOPin );
}
