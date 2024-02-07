/*
 * Rcc.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Nitro 5
 */
#include"Rcc_Private.h"
#include"RCC_Interface.h"
#include "RCC_Config.h"
#include"BIT_MATHS.h"
#include"STD_TYPES.h"
#include "Register_map.h"


u8 RCC_SetClk_Status(CLK_TYPE clk,STATUS_TYPE status){


	u8 c=0,flag=0;
	u8 return_status=OK;
switch(clk){

case HSI:

if(status==ON){
	SET_BIT(RCC->RCC_CR,HSION);
 while(!READ_BIT(RCC->RCC_CR,HSIRDY)&&c<CLK_TIMEOUT){

flag=1;

 }
 if(flag==1){
	 return_status= NOK;
 }

}
else{
	CLR_BIT(RCC->RCC_CR,HSION);
}
break;

case HSE_OSCI:

	CLR_BIT(RCC->RCC_CR,HSEBYP);
	if(status==ON){
		SET_BIT(RCC->RCC_CR,HSEON);
	 while(!READ_BIT(RCC->RCC_CR,HSERDY)&&c<CLK_TIMEOUT){
		 flag=1;

	 }
	 if(flag==1){

		 return_status= NOK;
	 }

	}
	else{
		CLR_BIT(RCC->RCC_CR,HSEON);
	}


break;
case HSE_BYB:

	SET_BIT(RCC->RCC_CR,HSEBYP);
	if(status==ON){
		SET_BIT(RCC->RCC_CR,16);
	 while(!READ_BIT(RCC->RCC_CR,17)&&c<CLK_TIMEOUT){
		 flag=1;

	 }
	 if(flag==1){

		 return_status= NOK;
	 }

	}
	else{
		CLR_BIT(RCC->RCC_CR,16);
	}

case PLL:
	if(status==ON){
		SET_BIT(RCC->RCC_CR,PLLON);
	 while(!READ_BIT(RCC->RCC_CR,PLLRDY)&&c<CLK_TIMEOUT){

		 flag=1;
	 }
	 if(flag==1){
		 return_status= NOK;

	 }

	}
	else{
		CLR_BIT(RCC->RCC_CR,PLLON);
	}

}

return return_status;


}
void RCC_SetSys_CLK(CLK_TYPE clk){

	switch(clk){

	case HSI:
		RCC->RCC_CFGR&=~0x3;
	break;
	case HSE_BYB:
	RCC->RCC_CFGR&=~0x3;
	SET_BIT(RCC->RCC_CFGR,0);
	case HSE_OSCI:
		RCC->RCC_CFGR&=~0x3;
		SET_BIT(RCC->RCC_CFGR,0);
	break;
	case PLL:
		RCC->RCC_CFGR&=~0x3;
		SET_BIT(RCC->RCC_CFGR,1);
	}


}

void RCC_PLL_CONFIG(PLL_INPUT_CLK CLK,PLL_MUL_FACTOR MUL){

	switch(CLK){
	case HSE_1:
		CLR_BIT(RCC->RCC_CFGR,PLLXTPRE);
		SET_BIT(RCC->RCC_CFGR,PLLSRC);


break;
	case HSE_2:
		        SET_BIT(RCC->RCC_CFGR,PLLXTPRE);
		        SET_BIT(RCC->RCC_CFGR,PLLSRC);

  break;
	case HSI1:
		CLR_BIT(RCC->RCC_CFGR,PLLSRC);
	}

	RCC->RCC_CFGR &=0xFFC3FFFF;
	RCC->RCC_CFGR|=((u32)MUL<<18);

}

void RCC_AHB_ENABLE_CLK(u8 perph){

		SET_BIT(RCC->RCC_AHBENR,perph);


}
void RCC_AHB_DISABLE_CLK(u8 perph){

	CLR_BIT(RCC->RCC_AHBENR,perph);
}

void RCC_APB2_ENABLE_clk(APB2_Peripherals preph){

			SET_BIT(RCC->RCC_APB2ENR,preph);


}

void RCC_APB2_DISABLE_clk(APB2_Peripherals preph){


	CLR_BIT(RCC->RCC_APB2ENR,preph);

}

void RCC_APB1_ENABLE_clk(APB1_Peripherals preph){

				SET_BIT(RCC->RCC_APB1ENR,preph);



}

void RCC_APB1_DISABLE_clk(APB1_Peripherals preph){
	CLR_BIT(RCC->RCC_APB1ENR,preph
			);

}


