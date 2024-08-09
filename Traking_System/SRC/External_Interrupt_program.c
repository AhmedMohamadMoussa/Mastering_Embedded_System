/*
 * External_Interrupt_program.c
 *
 *  Created on: Jul 22, 2023
 *      Author: User
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"

#include "../include/MCAL/EXTERNAL_INTERRUPT/External_INT_interface.h"
#include "../include/MCAL/EXTERNAL_INTERRUPT/External_INT_Privat.h"
#include "../include/MCAL/EXTERNAL_INTERRUPT/External_INT_cfg.h"

void MEXTI_voidConfig(EXTI_ID A_EXTI_ID , EXTI_SENSE_MODE A_EXTI_SENSE_MODE)
{
	if((A_EXTI_ID <= EXTI2)&&(A_EXTI_SENSE_MODE <= RISING_EDGE))
	{
		switch (A_EXTI_ID)
		{
			case EXTI0:
				MCUCR_REG &= ~(SENSE_MODE_MASK <<EXTI0_SENSE_MODE_BITS);//~(3<<0)//clear first two bit
				MCUCR_REG |= (A_EXTI_SENSE_MODE << EXTI0_SENSE_MODE_BITS);//(sense_mode<<0)
				break;
			case EXTI1:
				MCUCR_REG &= ~(SENSE_MODE_MASK <<EXTI1_SENSE_MODE_BITS);//~(3<<2)
				MCUCR_REG |= (A_EXTI_SENSE_MODE << EXTI1_SENSE_MODE_BITS);
				break;
			case EXTI2:
				switch (A_EXTI_SENSE_MODE)
				{
					case FALLING_EDGE: CLR_BIT(MCUCSR_REG,EXTI2_SENSE_MODE_BITS); break;
					case RISING_EDGE: SET_BIT(MCUCSR_REG,EXTI2_SENSE_MODE_BITS); break;
					default:break;
				}
				break;
			default:
				break;
		}
	}
}
void MEXTI_voidEnable(EXTI_ID A_EXTI_ID)
{
	if(A_EXTI_ID <= EXTI2)
	{
		switch (A_EXTI_ID)
		{
			case EXTI0:
				SET_BIT(GICR_REG,EXTI0_ENABLE_BIT);
				break;
			case EXTI1:
				SET_BIT(GICR_REG,EXTI1_ENABLE_BIT);
				break;
			case EXTI2:
				SET_BIT(GICR_REG,EXTI2_ENABLE_BIT);
				break;
			default:
				break;
		}
	}
}
void MEXTI_voidDisable(EXTI_ID A_EXTI_ID)
{
	if(A_EXTI_ID <= EXTI2)
	{
		switch (A_EXTI_ID)
		{
			case EXTI0:
				CLR_BIT(GICR_REG,EXTI0_ENABLE_BIT);
				break;
			case EXTI1:
				CLR_BIT(GICR_REG,EXTI1_ENABLE_BIT);
				break;
			case EXTI2:
				CLR_BIT(GICR_REG,EXTI2_ENABLE_BIT);
				break;
			default:
				break;
		}
	}
}
void MEXTI_voidClearFlag(EXTI_ID A_EXTI_ID)
{
	if(A_EXTI_ID <= EXTI2)
	{
		switch (A_EXTI_ID)
		{
			case EXTI0:
				SET_BIT(GIFR_REG,EXTI0_FLAG_BIT);
				break;
			case EXTI1:
				SET_BIT(GIFR_REG,EXTI1_FLAG_BIT);
				break;
			case EXTI2:
				SET_BIT(GIFR_REG,EXTI2_FLAG_BIT);
				break;
			default:
				break;
		}
	}
}
//example to understand
/*void Func(void)
{

}
MEXTI_voidSetCallBack(EXTI0 , &Func)
*/
#define NULL 0
void(*EXTI0_Callback)(void) = NULL;
void(*EXTI1_Callback)(void) = NULL;
void(*EXTI2_Callback)(void) = NULL;

void MEXTI_voidSetCallBack(EXTI_ID A_EXTI_ID,void(*ptrToFUNC)(void))
{
	if((A_EXTI_ID <= EXTI2)&&(ptrToFUNC!=NULL))
	{
		switch (A_EXTI_ID)
		{
			case EXTI0:
				EXTI0_Callback = ptrToFUNC;
				break;
			case EXTI1:
				EXTI1_Callback = ptrToFUNC;
				break;
			case EXTI2:
				EXTI2_Callback = ptrToFUNC;
				break;
			default:
				break;
		}
	}
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI0_Callback != NULL)
	{EXTI0_Callback();}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI1_Callback != NULL)
	{EXTI1_Callback();}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI2_Callback != NULL)
	{EXTI2_Callback();}
}
