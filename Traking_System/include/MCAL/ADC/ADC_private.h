/*
 * ADC_private.h
 *
 *  Created on: Jul 29, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX_REG  (*(volatile u8*)0x27)
#define ADCSRA_REG (*(volatile u8*)0x26)
#define ADCH_REG   (*(volatile u8*)0x25)
#define ADCL_REG   (*(volatile u8*)0x24)
#define ADCLH_REG  (*(volatile u16*)0x24)

#define ADC_CHANNEL_MASK 0b11100000

#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
