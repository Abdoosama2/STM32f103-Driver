/*
 * NVIC.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Abdelrahman Osama
 */

#include "BIT_MATHS.h"
#include"STD_TYPES.h"
#include"Err_Type.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

u8 NVIC_SetInterrupt_Enable(NVIC_InterruptNumber_t IRQ_Num) {

	u8 local_u8ErrorState = OK;

	if (IRQ_Num < NVIC_TOTAL_NUMBERS) {

		u8 REG_NUM = IRQ_Num / 32;
		u8 BIT_NUM = IRQ_Num % 32;

		//
		//SET_BIT(NVIC->ISER[REG_NUM], BIT_NUM);
		NVIC->ISER[REG_NUM]=(1<<BIT_NUM);

	} else {
		local_u8ErrorState = OUT_OF_RANGE;

	}

	return local_u8ErrorState;

}

u8 NVIC_SetInterrupt_Disable(NVIC_InterruptNumber_t IRQ_Num) {

	u8 local_u8ErrorState = OK;

		if (IRQ_Num < NVIC_TOTAL_NUMBERS) {

			u8 REG_NUM = IRQ_Num / 32;
			u8 BIT_NUM = IRQ_Num % 32;

			SET_BIT(NVIC->ICER[REG_NUM], BIT_NUM);

		} else {
			local_u8ErrorState = OUT_OF_RANGE;

		}

		return local_u8ErrorState;



}
u8 NVIC_SetPendingFlag(NVIC_InterruptNumber_t IRQ_Num){
	u8 local_u8ErrorState = OK;

			if (IRQ_Num < NVIC_TOTAL_NUMBERS) {

				u8 REG_NUM = IRQ_Num / 32;
				u8 BIT_NUM = IRQ_Num % 32;

				SET_BIT(NVIC->ISPR[REG_NUM], BIT_NUM);

			} else {
				local_u8ErrorState = OUT_OF_RANGE;

			}

			return local_u8ErrorState;




}
u8 NVIC_ClearPendingFlag(NVIC_InterruptNumber_t IRQ_Num){

	u8 local_u8ErrorState = OK;

				if (IRQ_Num < NVIC_TOTAL_NUMBERS) {

					u8 REG_NUM = IRQ_Num / 32;
					u8 BIT_NUM = IRQ_Num % 32;

					SET_BIT(NVIC->ICPR[REG_NUM], BIT_NUM);

				} else {
					local_u8ErrorState = OUT_OF_RANGE;

				}

				return local_u8ErrorState;


}
u8 NVIC_GetActiveFlag(NVIC_InterruptNumber_t IRQ_Num,u8*ReturnActiveFlag){

	u8 local_u8ErrorState = OK;
	u8 local_u8Activeflag;


					if (IRQ_Num < NVIC_TOTAL_NUMBERS) {

						u8 REG_NUM = IRQ_Num / 32;
						u8 BIT_NUM = IRQ_Num % 32;

					 local_u8Activeflag=READ_BIT(NVIC->IABR[REG_NUM], BIT_NUM);
					 *ReturnActiveFlag =local_u8Activeflag;

					} else {
						local_u8ErrorState = OUT_OF_RANGE;

					}
return local_u8ErrorState;


}
u8 NVIC_SetInterruptPriority(NVIC_InterruptNumber_t IRQ_Num,u8 PriorityNum){

	u8 local_u8ErrorState = OK;

	if(IRQ_Num < NVIC_TOTAL_NUMBERS && PriorityNum <= 255){

		    u8 REG_NUM = IRQ_Num / 4;
			u8 BIT_NUM = (IRQ_Num % 4)*8;

			//first we clear the bits

			NVIC->IPR[REG_NUM]&=~((0xffU)<<(BIT_NUM));

			//second we set the  Priority
			NVIC->IPR[REG_NUM]|=(PriorityNum<<(BIT_NUM));



	}
	else{
		local_u8ErrorState=OUT_OF_RANGE;
	}
return local_u8ErrorState;

}

