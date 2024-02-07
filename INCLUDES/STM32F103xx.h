/*
 * STM32F103xx.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Nitro 5
 */

#ifndef STM32F103XX_H_
#define STM32F103XX_H_






/*  NVIC Registers  */
#define NVIC_ISER   ((volatile u32*) 0xE000E100)
#define NVIC_ICER   ((volatile u32*) 0xE000E180)
#define NVIC_ISPR   ((volatile u32*) 0xE000E200)
#define NVIC_ICPR   ((volatile u32*) 0xE000E280)
#define NVIC_IABR   ((volatile u32*) 0xE000E300)
#define NVIC_IPR    ((volatile u8 *) 0xE000E400)

/**********************************************/







/************************GPIOS Base Adresss***************/
#define GPIOA_BASE_ADRESS     0X40010800U
#define GPIOB_BASE_ADRESS     0X40010C00U
#define GPIOC_BASE_ADRESS     0X40011000U
#define GPIOD_BASE_ADRESS     0X40011400U
#define GPIOE_BASE_ADRESS     0X40011800U


/**********GPIOS REGITER DEFINTIONS**********/

typedef struct{

	u32 CR[2];
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;

}Gpio_Reg_t;


/************************GPIO peripheral  DEFEINTIONS ***************/


  #define GPIOA           ((Gpio_Reg_t*)GPIOA_BASE_ADRESS)
  #define GPIOB           ((Gpio_Reg_t*)GPIOB_BASE_ADRESS)
  #define GPIOC           ((Gpio_Reg_t*)GPIOC_BASE_ADRESS)
  #define GPIOD           ((Gpio_Reg_t*)GPIOD_BASE_ADRESS)
  #define GPIOE           ((Gpio_Reg_t*)GPIOE_BASE_ADRESS)





#endif /* STM32F103XX_H_ */
