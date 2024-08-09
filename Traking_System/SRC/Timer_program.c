/*
 * Timer_program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: User
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/Timer/Timer_intereface.h"
#include "../include/MCAL/Timer/Timer_private.h"
#include "../include/MCAL/Timer/Timer_cfg.h"

#define NULL 0
void (*TIMER0_OVF_CALLBACK)(void)= NULL;//here i make pointer
void (*TIMER0_CTC_CALLBACK)(void)= NULL;//here i make pointer

void MTIMER0_voidInit(void)
{

	#if TIMER0_MODE == NORMAL_MODE
		//set wave generation mode to normal mode
		CLR_BIT(TCCR0_Reg,3);
		CLR_BIT(TCCR0_Reg,6);
		// turn on overflow interrupt
		SET_BIT(TIMSK_Reg,0);
		CLR_BIT(TIMSK_Reg,1);//this is not necessary
		//start timer by setting its'clock
		TCCR0_Reg &=0b11111000;
		TCCR0_Reg |=TIMER_CLK_CONFIGRATION;

	#elif TIMER0_MODE == PHASE_CORRECT_MODE
		//set wave generation mode
		CLR_BIT(TCCR0_Reg,3);
		SET_BIT(TCCR0_Reg,6);
		//disable all interrupts
		CLR_BIT(TIMSK_Reg,1);
		CLR_BIT(TIMSK_Reg,0);
		//set OCR0 value
		OCR0_Reg=OCR0_VALUE;
		//start timer by setting its clock configure OCR0 pin action
		TCCR0_Reg &=0b11001000;
		TCCR0_Reg |=(TIMER_CLK_CONFIGRATION | (TIMER0_Phase_Correct_OC0_PIN_MODE<<4));

	#elif TIMER0_MODE == CTC_MODE
		//set wave generation mode to CTC MODE
		SET_BIT(TCCR0_Reg,3);
		CLR_BIT(TCCR0_Reg,6);
		// turn on CTC interrupt
		SET_BIT(TIMSK_Reg,1);
		CLR_BIT(TIMSK_Reg,0);
		//set compare match unite value
		OCR0_Reg=OCR0_VALUE;
		//start timer by setting its'clock and configure OC0 pin action
		TCCR0_Reg &=0b11001000;
		TCCR0_Reg |=(TIMER_CLK_CONFIGRATION | (TIMER0_CTC_OC0_PIN_MODE<<4));

	#elif TIMER0_MODE == FAST_PWM_MODE
		//set wave generation mode
		SET_BIT(TCCR0_Reg,3);
		SET_BIT(TCCR0_Reg,6);
		//disable all interrupts
		CLR_BIT(TIMSK_Reg,1);
		CLR_BIT(TIMSK_Reg,0);
		//set OCR0 value
		OCR0_Reg=OCR0_VALUE;
		//start timer by setting its clock configure OCR0 pin action
		TCCR0_Reg &=0b11001000;
		TCCR0_Reg |=(TIMER_CLK_CONFIGRATION | (TIMER0_PWM_OC0_PIN_MODE<<4));
	#endif



}
void MTIMER1_voidInit(void)
{

	#if TIMER1_MODE == NORMAL_MODE

	#elif TIMER1_MODE == Fast_PWM_ICR1
	//set wave generation mode
	CLR_BIT(TCCR1A_Reg,0);//WGM10
	SET_BIT(TCCR1A_Reg,1);//WGM11
	SET_BIT(TCCR1B_Reg,3);//WGM12
	SET_BIT(TCCR1B_Reg,4);//WGM13
	//select mode form fast PWM
	//non inverting mode for OC1A
	CLR_BIT(TCCR1A_Reg,4);//COM1B0//he doesn't write this
	CLR_BIT(TCCR1A_Reg,6);//COM1A0
	SET_BIT(TCCR1A_Reg,5);//COM1B1//he doesn't write this
	SET_BIT(TCCR1A_Reg,7);//COM1A1
	//set ICR1 value
	ICR1LH_Reg = ICR1_VALUE;
	//set OCR1A value
	OCR1ALH_Reg = OCR1A_VALUE;
	//start timer by setting its clock
	TCCR1B_Reg &=0b11111000;
	TCCR1B_Reg |=TIMER_CLK_CONFIGRATION;

	#endif

}

void MTIMER1_voidSetOCR1AValue (u16 A_u16Value)
{
	OCR1ALH_Reg = A_u16Value;
}
void MTIMER0_voidSetPreLoadvalue (u8 A_u8NoOfTicks)
{
	TCNT0_Reg=A_u8NoOfTicks;
}

void MTIMER0_void_SetOCR0Value(u8 A_u8OCR0Value)
{
	OCR0_Reg = A_u8OCR0Value ;
}
void MTIMER0_voidStopTimer (void)
{
	TCCR0_Reg &=0b11111000;
}

void MTIMER0_voidOVFSetCallBack(void (*A_PtrToFunc)(void))
{
	if(A_PtrToFunc!=NULL)
	{
		TIMER0_OVF_CALLBACK = A_PtrToFunc;
	}
}
void MTIMER0_voidCTCSetCallBack(void (*A_PtrToFunc)(void))
{
	if(A_PtrToFunc!=NULL)
	{
		TIMER0_CTC_CALLBACK = A_PtrToFunc;
	}
}

void _vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(TIMER0_OVF_CALLBACK!=NULL)
	{
		TIMER0_OVF_CALLBACK();
	}
}

void _vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_CTC_CALLBACK!=NULL)
	{
		TIMER0_CTC_CALLBACK();
	}
}





















