/*
 * Timer_intereface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_INTEREFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER_INTEREFACE_H_

//Timer 0 MODE
#define NORMAL_MODE 		0
#define PHASE_CORRECT_MODE	1
#define CTC_MODE 			2
#define FAST_PWM_MODE		3

//TIMER0_CTC_OC0_PIN_MODE
#define NORMAL_DIO_PIN 	0
#define TOGGLE_CTC 		1
#define CLEAR_CTC		2
#define SET_CTC			3

//TIMER0_PWM_OC0_PIN_MODE
#define NORMAL_DIO_PIN 				0
#define Reserved_PWM    			1
#define CLEAR_PWM_non_invereting 	2
#define SET_PWM_invereting			3

//TIMER0_Phase_Correct_OC0_PIN_MODE
#define NORMAL_DIO_PIN 						0
#define Reserved_Phase_Correct    			1
#define CLEAR_Phase_Correct_non_invereting 	2
#define SET_Phase_Correct_invereting		3

//Timer 1 MODE
#define NORMAL_MODE 						  0
#define PWM_Phase_Correct_8bit 				  1
#define PWM_Phase_Correct_9bit 				  2
#define PWM_Phase_Correct_10bit 			  3
#define CTC_OCR1A 							  4
#define Fast_PWM_8bit 						  5
#define Fast_PWM_9bit						  6
#define Fast_PWM_10bit						  7
#define PWM_Phase_and_Frequency_Correct_ICR1  8
#define PWM_Phase_and_Frequency_Correct_OCR1A 9
#define PWM_Phase_Correct_ICR1				  10
#define PWM_Phase_Correct_OCR1A				  11
#define CTC_ICR1							  12
#define Reserved 							  13
#define Fast_PWM_ICR1						  14
#define Fast_PWM_OCR1A						  15

void MTIMER0_voidInit(void);
void MTIMER0_voidSetPreLoadvalue (u8 A_u8NoOfTicks);
void MTIMER0_voidOVFSetCallBack(void (*A_PtrToFunc)(void));
void MTIMER0_voidCTCSetCallBack(void (*A_PtrToFunc)(void));
void MTIMER0_void_SetOCR0Value(u8 A_u8OCR0Value);
void MTIMER0_voidStopTimer (void);

void MTIMER1_voidInit(void);
void MTIMER1_voidSetOCR1AValue (u16 A_u16Value);


#endif /* INCLUDE_MCAL_TIMER_TIMER_INTEREFACE_H_ */
