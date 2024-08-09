/*
 * WDT_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: User
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/WDT/WDT_interface.h"
#include "../include/MCAL/WDT/WDT_private.h"
#include "../include/MCAL/WDT/WDT_cfg.h"


void MWDT_voidEnable(void)
{
	WDTCR_Reg = 0b00001111;
}
void MWDT_voidDisable(void)
{
	CLR_BIT(WDTCR_Reg,3);
	SET_BIT(WDTCR_Reg,4);
	WDTCR_Reg = 0b00000000;
}
