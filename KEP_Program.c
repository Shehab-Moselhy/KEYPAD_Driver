///*
// * KEP_Program.c
// *
// *  Created on: Dec 1, 2023
// *      Author: shehab
// */
//
//
#include "util/delay.h"
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#define F_CPU 80000000

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/HAL/LCD/LCD_Interface.h"

#include "../include/HAL/KEP/KEP_Interface.h"
#include "../include/HAL/KEP/KEP_Private.h"
#include "../include/HAL/KEP/KEP_Cfg.h"

u8 static Global_u8ArrOfRows [ROW_NO] = KEYPAD_ROWS;
u8 static Global_u8ArrOfCols [COL_NO] = KEYPAD_COLS;



u8 HKEP_voidGetPressedKey()
{
	u8 local_u8KeyValue = KEY_NOT_PRESSED;

	u8 local_u8RowCounter =0 , local_u8ColCounter =0 , local_u8PinValue , local_u8Flag = 0;


	for (local_u8RowCounter =0 ; local_u8RowCounter < ROW_NO ; local_u8RowCounter++ )
	{
		//Activate One Row
		MDIO_voidSetPinStatus(KEYPAD_PORT , Global_u8ArrOfRows[local_u8RowCounter] ,DIO_RESET);

		for (local_u8ColCounter =0 ; local_u8ColCounter < COL_NO ; local_u8ColCounter++ )
		{
			//Read Column
			local_u8PinValue = MDIO_PinStatusGetPinStatus(KEYPAD_PORT ,Global_u8ArrOfCols[local_u8ColCounter]);
			if (local_u8PinValue == KEYPAD_PRESSED)
			{
				//Delay Of Bouncing Effect
				_delay_ms(KEYPAD_DEBOUNCIND_DELAY);

				//Read the value again to avoid repeated the same number in keypad
				local_u8PinValue = MDIO_PinStatusGetPinStatus(KEYPAD_PORT ,Global_u8ArrOfCols[local_u8ColCounter]);
				if (local_u8PinValue == KEYPAD_PRESSED)
				{
					while (local_u8PinValue == KEYPAD_PRESSED)
					{
						local_u8PinValue = MDIO_PinStatusGetPinStatus(KEYPAD_PORT ,Global_u8ArrOfCols[local_u8ColCounter]);
					}

					local_u8KeyValue = GLobal_u8ArrKeyOfValues [local_u8RowCounter][local_u8ColCounter];
					local_u8Flag = 1 ;
					break;
				}

			}
		}
		//Deactivate One Row
		MDIO_voidSetPinStatus(KEYPAD_PORT , Global_u8ArrOfRows[local_u8RowCounter] ,DIO_SET);

		// To End the Columns Loop(to control the loop to break)
		if (local_u8Flag == 1)
		{
			break;
		}

	}
	return local_u8KeyValue ;

}

