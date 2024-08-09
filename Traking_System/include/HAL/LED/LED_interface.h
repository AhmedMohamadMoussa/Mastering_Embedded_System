/*
 * LED_interface.h
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

typedef enum
{
	OFF=0,
	ON
}LED_STATUS;

void HAL_voidSetLedStatus(DIO_PORTS A_DIOPort , DIO_PINS A_DIOPin , LED_STATUS A_LedStatus);
void HAL_voidToggleLedStatus(DIO_PORTS A_DIOPort , DIO_PINS A_DIOPin );

#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
