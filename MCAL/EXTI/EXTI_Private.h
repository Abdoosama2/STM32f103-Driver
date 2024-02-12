/*
 * EXTI_Private.h
 *
 *  Created on: Feb 11, 2024
 *      Author: Abdelrahman Osama
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



#define EXTI_BASE_ADRESS   0x40010400U

typedef struct {
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;

}EXTI_Reg_t;

#define EXTI ((EXTI_Reg_t*)EXTI_BASE_ADRESS)


#endif /* EXTI_PRIVATE_H_ */
