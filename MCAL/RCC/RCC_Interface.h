/*
 * RCC_Interface.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Nitro 5
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_






typedef enum{
	OFF,
	ON

}STATUS_TYPE;

typedef enum{
	HSE_BYB,
	HSE_OSCI,
	HSI,
	PLL

}CLK_TYPE;

typedef enum{
	HSE_1,
	HSE_2,
	HSI1

}PLL_INPUT_CLK;

typedef enum{
	    PLL_Mul_2 = 0,
	    PLL_Mul_3,
	    PLL_Mul_4,
	    PLL_Mul_5,
	    PLL_Mul_6,
	    PLL_Mul_7,
	    PLL_Mul_8,
	    PLL_Mul_9,
	    PLL_Mul_10,
	    PLL_Mul_11,
	    PLL_Mul_12,
	    PLL_Mul_13,
	    PLL_Mul_14,
	    PLL_Mul_15,
	    PLL_Mul_16

}PLL_MUL_FACTOR;

// AHB peripherals **//
#define RCC_u8_DMA1_GPIOA	0
#define RCC_u8_DMA2_GPIOB	1
#define RCC_u8_SRAM_GPIOC	2
#define RCC_u8_FLITF_GPIOD	4
#define RCC_u8_CRCE_GPIOE	6
#define RCC_u8_FSMC_GPIOH	8
#define RCC_u8_SDIO_CRC		10

typedef enum{
	AFIO=0,
	GPIOA1=2,
	GPIOB1,
	GPIOC1,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	ADC1,
	ADC2,
	TIM1,
	SPI1,
	TIM8,
	USART,
	ADC3,
	TIM9=19,
	TIM10,
	TIM11

}APB2_Peripherals;


typedef enum{
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDGEN=11,
	SPI2=14,
	SPI3,
	USART2=17,
	USART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	USB,
	CAN=25,
	BKP=27,
	PWR,
	DAC

}APB1_Peripherals;
//errors type//

#define OK 1
#define NOK 0

//*******************///


u8 RCC_SetClk_Status(CLK_TYPE clk,STATUS_TYPE status);
void RCC_SetSys_CLK(CLK_TYPE clk);
void RCC_PLL_CONFIG(PLL_INPUT_CLK CLK,PLL_MUL_FACTOR MUL);
void RCC_AHB_ENABLE_CLK(u8 perph);
void RCC_AHB_DISABLE_CLK(u8 perph);
void RCC_APB2_ENABLE_clk(APB2_Peripherals preph);
void RCC_APB2_DISABLE_clk(APB2_Peripherals preph);
void RCC_APB1_ENABLE_clk(APB1_Peripherals preph);
void RCC_APB1_DISABLE_clk(APB1_Peripherals preph);


#endif /* RCC_INTERFACE_H_ */

