/*
 * KEP_Cfg.h
 *
 *  Created on: Dec 3, 2023
 *      Author: shehab
 */

#ifndef INCLUDE_HAL_KEP_KEP_CFG_H_
#define INCLUDE_HAL_KEP_KEP_CFG_H_

/************************************************************************************************/
/*							 		Define KEYPAD PORT 											*/
/************************************************************************************************/
#define KEYPAD_PORT PORTA
/************************************************************************************************/
/*							 Define KEYPAD Rows And Columns Number								*/
/************************************************************************************************/
#define ROW_NO 	4
#define COL_NO  4

#define KEY_NOT_PRESSED 255
/************************************************************************************************/
/*							 Define KEYPAD Rows And Columns Values								*/
/************************************************************************************************/
u8 GLobal_u8ArrKeyOfValues [ROW_NO][COL_NO] ={
												{'7','8','9','/'},
												{'4','5','6','*'},
												{'1','2','3','-'},
												{'C','0','=','+'}
											 };
/************************************************************************************************/
/*								 Define KEYPAD Rows Pins										*/
/************************************************************************************************/
//Define ROWs OutPut
#define ROW_0	  PIN0
#define ROW_1     PIN1
#define ROW_2     PIN2
#define ROW_3     PIN3
#define KEYPAD_ROWS		{ROW_0,ROW_1,ROW_2,ROW_3}
/************************************************************************************************/
/*								 Define KEYPAD Columns Pins										*/
/************************************************************************************************/
//Define Columns Input / PullUp Mode
#define COLUMNS_0	PIN4
#define COLUMNS_1   PIN5
#define COLUMNS_2   PIN6
#define COLUMNS_3   PIN7
#define KEYPAD_COLS	{COLUMNS_0,COLUMNS_1,COLUMNS_2,COLUMNS_3}
/************************************************************************************************/
#define KEYPAD_DEBOUNCIND_DELAY 30
/************************************************************************************************/
#define KEYPAD_PRESSED 0

#endif /* INCLUDE_HAL_KEP_KEP_CFG_H_ */