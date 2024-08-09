/*
 * ADC_interface.h
 *
 *  Created on: Jul 29, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_


typedef enum
{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7,
	ADC_0_0_10,
	ADC_1_0_10,
	ADC_0_0_200,
	ADC_1_0_200,
	ADC_2_2_10,
	ADC_3_2_10,
	ADC_2_2_200,
	ADC_2_3_200,
	ADC_0_1_1,
	ADC_1_1_1,
	ADC_2_1_1,
	ADC_3_1_1,
	ADC_4_1_1,
	ADC_5_1_1,
	ADC_6_1_1,
	ADC_7_1_1,
	ADC_0_2_1,
	ADC_1_2_1,
	ADC_2_2_1,
	ADC_3_2_1,
	ADC_4_2_1,
	ADC_5_2_1
}ADC_CHANNEL;

void MADC_voidInit(void);
u16 MADC_u16GetDigitalValue(ADC_CHANNEL A_AdcChannel);


#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
