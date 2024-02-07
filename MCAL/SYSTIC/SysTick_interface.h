/*
 * SysTick_interface.h
 *
 *  Created on: Dec 14, 2023
 *      Author: Nitro 5
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


typedef enum{

	AHB_DEVIDEBY8=0,
	AHB,

}Clock_type;


#define AHB_8MHZ  8000000ul
#define AHB_1MHZ  1000000ul

#define MS_CONVERTER  (1/1000)
#define us_converter  (1/1000000)


 void SystickInit(void);
 void SysTick_delay_us(u32 Systicks);
 void SysTick_delay_ms(u32 Systicks);




#endif /* SYSTICK_INTERFACE_H_ */
