/*
 * LCD_cfg.h
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_

#define LCD_DATA_PORT    PORTD
#define LCD_CONTROL_PORT PORTC

#define LCD_RS_PIN PIN0
#define LCD_RW_PIN PIN1
#define LCD_E_PIN  PIN2

//0 --> 4 bit mode
//1 --> 8 bit mode
#define LCD_DL 1 //data length

//0 --> 1 Line
//1 --> 2 Line
#define LCD_NO_OF_LINES 1

//0 --> 5*7 size
//1 --> 5*10 size
#define LCD_CHAR_FONT 0

//0-->off
//1--> on
#define DISPLAY_SCREEN 1

//0-->off
//1--> on
#define DISPLAY_CURSOR 1

//0-->off
//1--> on
#define CURSOR_BLINK 1

//0--> RIGHT TO LEFT
//1--> LEFT TO RIGHT
#define DATA_DIRECTION 1
#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
