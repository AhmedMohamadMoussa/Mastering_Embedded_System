/*
 * SSD_interface.h
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_


void HSSD_DisplayNumber(DIO_PORTS A_DIOPort , u8 A_u8Number);
void HSSD_voidDisplayAscending(DIO_PORTS A_DIOPort , u16 A_u16DelayMs);
void HSSD_voidDisplayDescending(DIO_PORTS A_DIOPort , u16 A_u16DelayMs);

#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
