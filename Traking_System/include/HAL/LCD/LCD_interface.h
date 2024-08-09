/*
 * LCD_interface.h
 *
 *  Created on: Jul 4, 2023
 *      Author: User
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

typedef enum
{
	ROW1=1,
	ROW2
}LCD_ROW;
typedef enum
{
	COL1=1,
	COL2,
	COL3,
	COL4,
	COL5,
	COL6,
	COL7,
	COL8,
	COL9,
	COL10,
	COL11,
	COL12,
	COL13,
	COL14
}LCD_COL;
void HLCD_voidSendCommend(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidIntl(void);
void HLCD_voidSendString(u8 *A_Pu8String);
void HLCD_voidClearDiplay(void);
void HLCD_voidGoToPos(LCD_ROW ALcdRowNo,LCD_COL A_LcdColNo);
void HLCD_voidDisplayNumberPositive (u32 A_u32Number);
void HLCD_voidDisplayNumberNegative (s32 A_s32Number);
void HLCD_voidSendSpecialCharecter(u8 *A_u8PatternArr , u8 Au8PatternNumber , LCD_ROW A_LcdRowNo , LCD_COL A_LcdColNo);

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
