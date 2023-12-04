/*
 * LCD_Cfg.h
 *
 *  Created on: 27 Nov 2023
 *      Author: sheha
 */

#ifndef INCLUDE_HAL_LCD_CFG_H_
#define INCLUDE_HAL_LCD_CFG_H_

//********************************************************************************
//								 LCD_DATA_PORT
#define LCD_DATA_PORT     PORTD

//********************************************************************************
//								 LCD_CONTROL_PORT
#define LCD_CONTROL_PORT  PORTC
//********************************************************************************
//								 LCD Control Pins
#define LCD_RS_PIN		PIN0
#define LCD_RW_PIN		PIN1
#define LCD_E_PIN		PIN2

//********************************************************************************
// 							4 Bit Mode For Data Pins

#define LCD_4BIT_MODE_DATA_PORT_PIN4	PIN4
#define LCD_4BIT_MODE_DATA_PORT_PIN5	PIN5
#define LCD_4BIT_MODE_DATA_PORT_PIN6	PIN6
#define LCD_4BIT_MODE_DATA_PORT_PIN7	PIN7
//********************************************************************************




// 1--> 8-bit
// 0--> 4-bit
#define LCD_DATA_LENGTH		1

//0 --> 1 line
//1 --> 2 line
#define LCD_NUMBER_OF_LINE  1

//0--> 5 * 7
//1--> 5 * 10
#define LCD_CHAR_FONT 		0

//0 --> OFF
//1 --> ON
#define ENTIRE_DISPLAY      1

//0 --> OFF
//1 --> ON
#define CURSOR_DISPLAY      1

//0 --> OFF
//1 --> ON
#define BLINK_CURSOR        1

//Lift to Right	-->1
//Right to Lift -->0
#define DIRECTION_MODE		1



#endif /* INCLUDE_HAL_LCD_CFG_H_ */
