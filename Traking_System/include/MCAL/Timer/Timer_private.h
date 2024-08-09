/*
 * Timer_private.h
 *
 *  Created on: Aug 22, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_

//Timer 0
#define TCCR0_Reg  (*(volatile u8*)0x53)
#define TCNT0_Reg  (*(volatile u8*)0x52)
#define OCR0_Reg   (*(volatile u8*)0x5C)

#define TIMSK_Reg  (*(volatile u8*)0x59)
#define TIFR_Reg   (*(volatile u8*)0x58)

//Timer 1
#define TCCR1A_Reg (*(volatile u8*)0x4F)
#define TCCR1B_Reg (*(volatile u8*)0x4E)

#define TCNT1H_Reg (*(volatile u8*)0x4D)
#define TCNT1L_Reg (*(volatile u8*)0x4C)
#define TCNT1LH_Reg (*(volatile u16*)0x4C)

#define OCR1AH_Reg (*(volatile u8*)0x4B)
#define OCR1AL_Reg (*(volatile u8*)0x4A)
#define OCR1ALH_Reg (*(volatile u16*)0x4A)

#define OCR1BH_Reg (*(volatile u8*)0x49)
#define OCR1BL_Reg (*(volatile u8*)0x48)
#define OCR1BLH_Reg (*(volatile u16*)0x48)

#define ICR1H_Reg  (*(volatile u8*)0x47)
#define ICR1L_Reg  (*(volatile u8*)0x46)
#define ICR1LH_Reg  (*(volatile u16*)0x46)


#endif /* INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_ */
