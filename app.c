/*
 * app.c
 *
 *  Created on: Apr 4, 2023
 *      Author: Shehab Eldin Saber
 */


#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/KEP/KEP_Interface.h"


#define KPD_NO_PREASSED 255



int main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HLCD_SendString("shehab");
	u8 key;
	while(1)
	{
		do
		{
			key = HKEP_voidGetPressedKey();
		} while(key == KPD_NO_PREASSED);
		HLCD_voidSendData(key);

		if(key == 'C')
		{
			HLCD_voidClearDisplay();
		}
	}
}






















