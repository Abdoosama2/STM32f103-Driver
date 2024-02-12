/*
 * EXTI.c
 *
 *  Created on: Feb 11, 2024
 *      Author:Abdelrahman Osama
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include"EXTI_Interface.h"
#include "EXTI_Private.h"
#include "Err_Type.h"


static void (*pfunc[16])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

u8 EXTI_u8Enable(EXTI_Line_t line){

	u8 local_u8ErrorState=OK;

	if(line<TOTAL_LINES){


			SET_BIT(EXTI->EXTI_IMR,line);

	}
	else{

		local_u8ErrorState=OUT_OF_RANGE;
	}

	return local_u8ErrorState;

}
u8 EXTI_u8Disable(EXTI_Line_t line){
	u8 local_u8ErrorState=OK;

	if(line<TOTAL_LINES){
	CLR_BIT(EXTI->EXTI_IMR,line);
	}
	else{

			local_u8ErrorState=OUT_OF_RANGE;
		}
	return local_u8ErrorState;
}

u8 EXTI_u8Set_Trigger(EXTI_Line_t line,EDGE_t edge){
	u8 local_u8ErrorState=OK;

		if(line<TOTAL_LINES){

			if(edge==rising_edge){
				SET_BIT(EXTI->EXTI_RTSR,line);

			}
			else if(edge==falling_edge){
				SET_BIT(EXTI->EXTI_FTSR,line);
			}

		}
		else{
			local_u8ErrorState=OUT_OF_RANGE;
		}
		return local_u8ErrorState;

}
u8 EXTI_u8Clear_pendingflag(EXTI_Line_t line){
	u8 local_u8ErrorState=OK;
	if(line<TOTAL_LINES){

		SET_BIT(EXTI->EXTI_PR,line);

	}
	else{
		local_u8ErrorState=OUT_OF_RANGE;
	}
	return local_u8ErrorState;
}
u8 EXTI_u8Read_pendingflag(EXTI_Line_t line){

	return READ_BIT(EXTI->EXTI_PR,line);
}
u8 EXTI_u8Set_callback(EXTI_Line_t line,void (*LocalPtr)(void)){
	u8 local_u8ErrorState=OK;
	if(line<TOTAL_LINES){

		pfunc[line]=LocalPtr;

		}
		else{
			local_u8ErrorState=OUT_OF_RANGE;
		}


return local_u8ErrorState;
}


void EXTI0_IRQHandler(void){

	EXTI_u8Clear_pendingflag(0);
	if(pfunc[0]!=NULL){

		pfunc[0]();


	}

}


void EXTI1_IRQHandler(void){

	EXTI_u8Clear_pendingflag(1);
	if(pfunc[1]!=NULL){

		pfunc[1]();

	}

}

void EXTI2_IRQHandler(void){

	EXTI_u8Clear_pendingflag(2);
	if(pfunc[2]!=NULL){

		pfunc[2]();


	}

}

void EXTI3_IRQHandler(void){

	EXTI_u8Clear_pendingflag(3);
	if(pfunc[3]!=NULL){

		pfunc[3]();


	}

}



void EXTI4_IRQHandler(void){

	EXTI_u8Clear_pendingflag(4);
	if(pfunc[4]!=NULL){

		pfunc[4]();


	}

}
void EXTI9_5_IRQHandler(void){

	if(EXTI_u8Read_pendingflag(5)==1){
		EXTI_u8Clear_pendingflag(5);
		if(pfunc[5]!=NULL){

				pfunc[5]();


			}

	}
	 if(EXTI_u8Read_pendingflag(6)==1){
		 EXTI_u8Clear_pendingflag(6);
			if(pfunc[6]!=NULL){

					pfunc[6]();


				}

		}
	 if(EXTI_u8Read_pendingflag(7)==1){
		 EXTI_u8Clear_pendingflag(7);
			if(pfunc[7]!=NULL){

					pfunc[7]();


				}

		}
	 if(EXTI_u8Read_pendingflag(8)==1){
		 EXTI_u8Clear_pendingflag(8);
			if(pfunc[8]!=NULL){

					pfunc[8]();


				}

		}
 if(EXTI_u8Read_pendingflag(9)==1){
	 EXTI_u8Clear_pendingflag(9);
			if(pfunc[9]!=NULL){

					pfunc[9]();


				}

		}


}


void EXTI15_10_IRQHandler(void){

	if(EXTI_u8Read_pendingflag(10)==1){
		EXTI_u8Clear_pendingflag(10);
		if(pfunc[10]!=NULL){

				pfunc[10]();


			}

	}
	 if(EXTI_u8Read_pendingflag(11)==1){
		 EXTI_u8Clear_pendingflag(11);
			if(pfunc[11]!=NULL){

					pfunc[11]();


				}

		}
	 if(EXTI_u8Read_pendingflag(12)==1){
		 EXTI_u8Clear_pendingflag(12);
			if(pfunc[12]!=NULL){

					pfunc[12]();


				}

		}
	 if(EXTI_u8Read_pendingflag(13)==1){
		 EXTI_u8Clear_pendingflag(13);
			if(pfunc[13]!=NULL){

					pfunc[13]();


				}

		}
	 if(EXTI_u8Read_pendingflag(14)==1){
		 EXTI_u8Clear_pendingflag(14);
			if(pfunc[14]!=NULL){

					pfunc[14]();


				}

		}
	 if(EXTI_u8Read_pendingflag(15)==1){
		 EXTI_u8Clear_pendingflag(15);
				if(pfunc[15]!=NULL){

						pfunc[15]();


					}

			}


}



