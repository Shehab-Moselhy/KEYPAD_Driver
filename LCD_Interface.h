/*
 * LCD_Interface.h
 *
 *  Created on: 27 Nov 2023
 *      Author: sheha
 */

#ifndef INCLUDE_HAL_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_INTERFACE_H_

typedef enum{
	ROW1 = 0,
	ROW2
}LCD_ROWS;

typedef enum{
	COL1 = 0,
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
	COL14,
	COL15,
	COL16
}LCD_COLS;

void HLCD_voidGoToPos(LCD_ROWS A_LcdRowNo,LCD_COLS A_LcdColNo);

void HLCD_voidSendData(u8 A_u8Data);

void HLCD_voidSendCommand(u8 A_u8Command);

void HLCD_voidInit();

void HLCD_SendString(u8 *A_Pu8String);

void HLCD_voidClearDisplay();

void HLCD_voidDisplayNumber(s32 A_s32Number);

#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
