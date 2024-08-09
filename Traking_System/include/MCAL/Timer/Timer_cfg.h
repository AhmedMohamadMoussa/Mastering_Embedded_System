/*
 * Timer_cfg.h
 *
 *  Created on: Aug 22, 2023
 *      Author: User
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_

/*
 * NORMAL_MODE
 * PHASE_CORRECT_MODE
 * CTC_MODE
 * FAST_PWM_MODE
 */
#define TIMER0_MODE PHASE_CORRECT_MODE

/*
 * CS02 CS01 CS00 	 Description
 *	0	 0	   0	 No clock source (Timer/Counter stopped).
 *	0	 0	   1	 clkI/O/(No prescaling)
 *	0	 1	   0	 clkI/O/8 (From prescaler)
 *	0	 1	   1	 clkI/O/64 (From prescaler)
 *	1	 0	   0	 clkI/O/256 (From prescaler)
 *	1	 0	   1	 clkI/O/1024 (From prescaler)
 * 	1	 1	   0	 External clock source on T0 pin. Clock on falling edge.
 *	1 	 1	   1	 External clock source on T0 pin. Clock on rising edge
 */
#define TIMER_CLK_CONFIGRATION 0b010

#define OCR0_VALUE 0

/*
 * NORMAL_DIO_PIN 	0
 * TOGGLE_CTC 		1
 * CLEAR_CTC		2
 * SET_CTC			3
 */
#define TIMER0_CTC_OC0_PIN_MODE NORMAL_DIO_PIN

/*
 * NORMAL_DIO_PIN 				0
 * Reserved_PWM    				1
 * CLEAR_PWM_non_invereting 	2
 * SET_PWM_invereting			3
 */
#define TIMER0_PWM_OC0_PIN_MODE CLEAR_PWM_non_invereting

/*
 * 	 NORMAL_DIO_PIN 						0
 *	 Reserved_Phase_Correct    				1
 *	 CLEAR_Phase_Correct_non_invereting 	2
 *	 SET_Phase_Correct_invereting			3
 */
#define TIMER0_Phase_Correct_OC0_PIN_MODE CLEAR_Phase_Correct_non_invereting

/*
 * NORMAL_MODE 							  0
 * PWM_Phase_Correct_8bit 				  1
 * PWM_Phase_Correct_9bit 				  2
 * PWM_Phase_Correct_10bit	 			  3
 * CTC_OCR1A 							  4
 * Fast_PWM_8bit 						  5
 * Fast_PWM_9bit						  6
 * Fast_PWM_10bit						  7
 * PWM_Phase_and_Frequency_Correct_ICR1	  8
 * PWM_Phase_and_Frequency_Correct_OCR1A  9
 * PWM_Phase_Correct_ICR1				  10
 * PWM_Phase_Correct_OCR1A				  11
 * CTC_ICR1							  	  12
 * Reserved 							  13
 * Fast_PWM_ICR1						  14
 * Fast_PWM_OCR1A						  15
 */
#define TIMER1_MODE Fast_PWM_ICR1

#define ICR1_VALUE 19999
#define OCR1A_VALUE 1500

#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
