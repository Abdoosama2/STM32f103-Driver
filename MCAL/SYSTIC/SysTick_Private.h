/*
 * SysTick_Private.h
 *
 *  Created on: Dec 14, 2023
 *      Author: Nitro 5
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_


#define SYSTICK_BASE_ADRESS 0xE000E010UL

#define ENABLE 0
#define TICKINT 1
#define CLKSOURCE 2
#define COUNTFLAG 16

typedef struct{

	    volatile u32 STK_CTRL;
		volatile u32 STK_LOAD;
		volatile u32 STK_VAL;
		volatile u32 STK_CALIB;


}Sytick_Reg_t;


#define SysTick  ((Sytick_Reg_t*)SYSTICK_BASE_ADRESS)






#endif /* SYSTICK_PRIVATE_H_ */
