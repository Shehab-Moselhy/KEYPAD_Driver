/*
 * LCD_Private.h
 *
 *  Created on: 27 Nov 2023
 *      Author: sheha
 */

#ifndef INCLUDE_HAL_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_PRIVATE_H_


//------------------------------------------------------------------------
//Address of ROW1 and ROW2
#define LCD_ROW1_ADDRESS 127
#define LCD_ROW2_ADDRESS 191
//------------------------------------------------------------------------

//8-bit mode
#define FUNCATION_SET  			CONC_BIT(0,0,1,LCD_DATA_LENGTH,LCD_NUMBER_OF_LINE,LCD_CHAR_FONT,0,0)

#define DISPLAY_ON_OFF_CONTROL  CONC_BIT(0,0,0,0,1,ENTIRE_DISPLAY,CURSOR_DISPLAY,BLINK_CURSOR)

#define DISPLAY_CLEAR 			0b00000001

#define ENTRY_MODE_SET  		CONC_BIT(0,0,0,0,0,1,DIRECTION_MODE,0)



//-------------------------------------------------------------------------
// 4-bit mode
#define FUNCATION_SET_1  			0x20
#define FUNCATION_SET_2				CONC_BIT(LCD_NUMBER_OF_LINE,LCD_CHAR_FONT,0,0,0,0,0,0)

#define DISPLAY_ON_OFF_CONTROL_1    0x00
#define DISPLAY_ON_OFF_CONTROL_2    CONC_BIT(1,ENTIRE_DISPLAY,CURSOR_DISPLAY,BLINK_CURSOR,0,0,0,0)

#define DISPLAY_CLEAR_1 			0x00
#define DISPLAY_CLEAR_2				0x10

#define ENTRY_MODE_SET_1  			0x00
#define ENTRY_MODE_SET_2			CONC_BIT(0,1,DIRECTION_MODE,0,0,0,0,0)

#endif /* INCLUDE_HAL_LCD_PRIVATE_H_ */
