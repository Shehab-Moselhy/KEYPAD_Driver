/*
 * LCD_Program.c
 *
 *  Created on: 27 Nov 2023
 *      Author: shehab
 */

#include <util/delay.h>
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#define F_CPU  8000000UL

#include "../include/MCAL/DIO/DIO_Interface.h"

#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LCD/LCD_Private.h"
#include "../include/HAL/LCD/LCD_Cfg.h"



void HLCD_voidSendCommand(u8 A_u8Command)
{


		#if LCD_DATA_LENGTH == 0
		//To Write Command RS -> 0 , RW -> 0
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_RESET);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);

		//Set Data Port with First Nibble of Command
		//Value Of Pin 0 of data port equal to the first bit of the command that send
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN4,GET_BIT(A_u8Command,PIN4));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN5,GET_BIT(A_u8Command,PIN5));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN6,GET_BIT(A_u8Command,PIN6));
		MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN7,GET_BIT(A_u8Command,PIN7));

		//Set Pulse on E pin with 2ms delay
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
		_delay_ms(2);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);



		#elif LCD_DATA_LENGTH == 1
		//To Write Command RS -> 0 , RW -> 0
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_RESET);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);
		//Set Data Port with Command
		MDIO_voidSetPortStatus(LCD_DATA_PORT,A_u8Command);
		//Set Pulse on E pin with 2ms delay
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
		_delay_ms(2);
		MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);
		#endif

	_delay_ms(2);

}

//************************************************************************************************/
void HLCD_voidSendData(u8 A_u8Data)
{
	#if LCD_DATA_LENGTH == 0
	//To Write Command RS -> 1 , RW -> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_SET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);

	//Set Data Port with First Nibble of Command
	//Value Of Pin 0 of data port equal to the first bit of the command that send
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN4,GET_BIT(A_u8Data,PIN4));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN5,GET_BIT(A_u8Data,PIN5));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN6,GET_BIT(A_u8Data,PIN6));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN7,GET_BIT(A_u8Data,PIN7));

	//Set Pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

	//Set Data Port with First Nibble of Command
	//Value Of Pin 0 of data port equal to the first bit of the command that send
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN4,GET_BIT(A_u8Data,PIN0));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN5,GET_BIT(A_u8Data,PIN1));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN6,GET_BIT(A_u8Data,PIN2));
	MDIO_voidSetPinStatus(LCD_DATA_PORT,LCD_4BIT_MODE_DATA_PORT_PIN7,GET_BIT(A_u8Data,PIN3));

	//Set Pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);

	#elif LCD_DATA_LENGTH == 1
	//To Write Command RS -> 1 , RW -> 0
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_SET);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_RESET);

	//Set Data Port with Command
	MDIO_voidSetPortStatus(LCD_DATA_PORT,A_u8Data);

	//Set Pulse on E pin with 2ms delay
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinStatus(LCD_CONTROL_PORT,LCD_E_PIN,DIO_RESET);
	#endif


}
//************************************************************************************************/
void HLCD_voidInit(void)
{
	#if LCD_DATA_LENGTH == 0
	//wait for more than 30 ms
	_delay_ms(32);
	//Function Set Command
	HLCD_voidSendCommand(FUNCATION_SET_1);
	HLCD_voidSendCommand(FUNCATION_SET_1);
	HLCD_voidSendCommand(FUNCATION_SET_2);
	//wait for more than 39 us
	_delay_ms(1);
	//Display On/Off control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL_1);
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL_2);
	//wait for more than 39 us
	_delay_ms(1);
	//Display clear
	HLCD_voidSendCommand(DISPLAY_CLEAR_1);
	HLCD_voidSendCommand(DISPLAY_CLEAR_2);
	//wait for more than 1.53 ms
	_delay_ms(2);
	HLCD_voidSendCommand(ENTRY_MODE_SET_1);
	HLCD_voidSendCommand(ENTRY_MODE_SET_2);

	#elif LCD_DATA_LENGTH == 1
	//wait for more than 30 ms
	_delay_ms(32);
	//Function Set Command
	HLCD_voidSendCommand(FUNCATION_SET);
	//wait for more than 39 us
	_delay_ms(1);
	//Display On/Off control
	HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
	//wait for more than 39 us
	_delay_ms(1);
	//Display clear
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	//wait for more than 1.53 ms
	_delay_ms(2);
	HLCD_voidSendCommand(ENTRY_MODE_SET);
	#endif
}
void HLCD_SendString(u8 *A_Pu8String)
{
	while(*A_Pu8String > 0)
	{
		HLCD_voidSendData(*A_Pu8String++);
	}
}

//********************************************************************************************************

void HLCD_voidClearDisplay()
{
	#if LCD_DATA_LENGTH == 0
	HLCD_voidSendCommand(DISPLAY_CLEAR_1);
	HLCD_voidSendCommand(DISPLAY_CLEAR_2);
	_delay_ms(2);

	#elif LCD_DATA_LENGTH == 1
	HLCD_voidSendCommand(DISPLAY_CLEAR);
	_delay_ms(2);
	#endif
}
//***********************************************************************************************
void HLCD_voidGoToPos(LCD_ROWS A_LcdRowNo,LCD_COLS A_LcdColNo)
{
	switch (A_LcdRowNo)
	{
	case ROW1: HLCD_voidSendCommand(LCD_ROW1_ADDRESS + A_LcdColNo); break;
	case ROW2: HLCD_voidSendCommand(LCD_ROW2_ADDRESS + A_LcdColNo); break;
	default: break;
	}
	_delay_ms(1);
}
//**************************************************************************************************

void HLCD_voidDisplayNumber(s32 A_s32Number)
{
	u32 local_u32Number = 1 ;
	if(A_s32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	if(A_s32Number <0 )
	{
		HLCD_voidSendData('-');
		A_s32Number *= -1;
	}
	while(A_s32Number != 0)
	{
		local_u32Number = (local_u32Number * 10) + (A_s32Number % 10 );
		A_s32Number /= 10;
	}
	while(local_u32Number != 1)
	{
		HLCD_voidSendData((local_u32Number % 10)+48);
		local_u32Number /=10;
	}
}
//***************************************************************************************************







