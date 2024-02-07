/*
 * Rcc_Private.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Nitro 5
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#include "STD_TYPES.h"
typedef struct{

u32 RCC_CR;
u32 RCC_CFGR;
u32 RCC_CIR;
u32 RCC_APB2RSTR;
u32 RCC_APB1RSTR;
u32 RCC_AHBENR;
u32 RCC_APB2ENR;
u32 RCC_APB1ENR;
u32 RCC_BDCR;
u32 RCC_CSR;

}RCC_REGt;

RCC_REGt *RCC=(RCC_REGt*)(0x40021000);






#endif /* RCC_PRIVATE_H_ */
