/*
 * NVIC_private.h
 *
 *  Created on: Dec 27, 2023
 *      Author: Nitro 5
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define NCIV_BASE_ADRESS   0xE000E100U



typedef struct{

	volatile u32 ISER[32];
	volatile u32 ICER[32];
	volatile u32 ISPR[32];
	volatile u32 ICPR[32];
	volatile u32 IABR[64];
	volatile u32  IPR[59];



}NVIC_REG_T;


#define NVIC ((NVIC_REG_T*)NCIV_BASE_ADRESS)







#endif /* NVIC_PRIVATE_H_ */
