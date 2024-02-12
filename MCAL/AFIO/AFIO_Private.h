/*
 * AFIO_Private.h
 *
 *  Created on: Feb 12, 2024
 *      Author: Abdelrahman Osama
 */

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

/********AFIO REGISTERS BASE ADRESS*//////////


#define AFIO_BASE_ADRESS   0x40010000U
//#define AFIO_EXTICR_BASE_ADRESS 0x40010008U//


/*********** AFIO REGISTER MAPPING***************/////////////

typedef struct{
	    volatile u32 EVCR;
	    volatile u32 MAPR;
	    volatile u32 EXTICR[4];
	    volatile u32 MAPR2;

}AFIO_t;


#define AFIO ((AFIO_t*)AFIO_BASE_ADRESS)








#endif /* AFIO_PRIVATE_H_ */
