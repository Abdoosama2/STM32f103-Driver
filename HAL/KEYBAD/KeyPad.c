/*
 * KeyPad.c
 *
 *  Created on: Dec 16, 2023
 *      Author: Nitro 5
 */

#define KEYPAD_C
#include "BIT_MATHS.h"
#include "STD_TYPES.h"
//#include "RCC_Interface.h"
//#include "STM32F103xx.h"
#include "GPIO.interface.h"
//#include "SysTick_interface.h"

#include "KeyPad_cfg.h"
#include "KeyPad.h"



const u8 COLUMN_PINS[]={COULMN_1,COULMN_2,COULMN_3,COULMN_4};
void KEYPAD_Init(void)
{
	 Gpio_u8_SetPinvalue(PORTA,FIRST_OUTPUT,PIN_HIGH);
	Gpio_u8_SetPinvalue(PORTA,FIRST_OUTPUT+1,PIN_HIGH);
	Gpio_u8_SetPinvalue(PORTA,FIRST_OUTPUT+2,PIN_HIGH);
	Gpio_u8_SetPinvalue(PORTA,FIRST_OUTPUT+3,PIN_HIGH);
}

u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;

	for (r=0;r<ROWS;r++)
	{
		Gpio_u8_SetPinvalue(PORTA,FIRST_OUTPUT+r,PIN_LOW);
	for (c=0;c<COLS;c++)
		{
			if (Gpio_u8_ReturnPinvalue(PORTB,COLUMN_PINS[c])==PIN_LOW)
			{

				while(Gpio_u8_ReturnPinvalue(PORTB,COLUMN_PINS[c])==PIN_LOW);
				key=KeysArray[r][c];
				return key;
			}


		}
		Gpio_u8_SetPinvalue(PORTA,FIRST_OUTPUT+r,PIN_HIGH);
	}
return key;
	}
