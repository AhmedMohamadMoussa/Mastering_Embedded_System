/*
 * ADC_program.c
 *
 *  Created on: Jul 29, 2023
 *      Author: User
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/ADC/ADC_interface.h"
#include "../include/MCAL/ADC/ADC_private.h"
#include "../include/MCAL/ADC/ADC_cfg.h"

void MADC_voidInit(void)
{
	//Select AVCC with external capacitor at AREF pin
	SET_BIT(ADMUX_REG,6);
	CLR_BIT(ADMUX_REG,7);
	//RIGHT Adjustment
	CLR_BIT(ADMUX_REG,5);
	//disable Auto Trigger
	CLR_BIT(ADCSRA_REG,5);
	//select CLK /64
	CLR_BIT(ADCSRA_REG,0);
	SET_BIT(ADCSRA_REG,1);
	SET_BIT(ADCSRA_REG,2);
	//Enable ADC
	SET_BIT(ADCSRA_REG,7);
}
u16 MADC_u16GetDigitalValue(ADC_CHANNEL A_AdcChannel)
{
	u16 local_u16DigitalValue=0;
	if(A_AdcChannel< 32)
	{
		//clear the channel 5 bits
		ADMUX_REG &= ADC_CHANNEL_MASK;
		//select channel
		ADMUX_REG |=A_AdcChannel;
		//start conversion
		SET_BIT(ADCSRA_REG,6);
		//polling on ADC complete flag
		while(GET_BIT(ADCSRA_REG,4)==0);
		//clear INT .Flag
		SET_BIT(ADCSRA_REG,4);
		//READ CONVERSION VALUE
		local_u16DigitalValue =ADCLH_REG;
	}
	//return result of conversion
	return local_u16DigitalValue;
}












