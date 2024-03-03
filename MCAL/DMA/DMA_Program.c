/*
 * DMA_Program.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrahman Osama
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DMA_Private.h"
#include "DMA_Interface.h"
#include "DMA_Config.h"
#include  "Err_Type.h"


static void (*DMA1_pfunc[7])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL};
static void (*DMA2_pfunc[5])(void)={NULL,NULL,NULL,NULL,NULL};

u8 DMA_U8Channel_Init(const DMA_ChannelCfg_t *Channelcfg){

	u8 local_u8ErrorState = OK;

	if(Channelcfg->dma==DMA_1){

		if(Channelcfg->channel<TOTAL_CHANNEL_NUM){

			//first we disable the channel
			CLR_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,EN);

			//setting the directions
			if(Channelcfg->Direction==MEMORY_TO_MEMORY){

				SET_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,MEM2MEM);
				CLR_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,DIR);
			}
			else if(Channelcfg->Direction==MEMORY_TO_PERIPH){

				SET_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,DIR);
			}
			else if(Channelcfg->Direction==PERIPH_TO_MEMORY){

				CLR_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,DIR);
						}
			//setting the desired priority
			DMA1->CHANNEL[Channelcfg->channel].CCR &=~(3<<PL);
			DMA1->CHANNEL[Channelcfg->channel].CCR |=(Channelcfg->priority<<PL);

			//setting the memory Alligment size
			DMA1->CHANNEL[Channelcfg->channel].CCR &=~(3<<MSIZE);
			DMA1->CHANNEL[Channelcfg->channel].CCR |=(Channelcfg->mem_size<<MSIZE);

			//setting the memory Alligment size
			DMA1->CHANNEL[Channelcfg->channel].CCR &=~(3<<PSIZE);
			DMA1->CHANNEL[Channelcfg->channel].CCR |=(Channelcfg->periph_size << PSIZE);

			//choosing the Peripheral inc
			WRITE_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,PINC,Channelcfg->PeriphInc );
			//choosing the mem inc
			WRITE_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,MINC,Channelcfg->MemInc);
			//Choosing the mode
			WRITE_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,CIRC,Channelcfg->mode);


		}else{
			local_u8ErrorState=OUT_OF_RANGE;

		}



	}
	else if(Channelcfg->dma==DMA_2){

		if(Channelcfg->channel<=CHANNEL5){


			//first we disable the channel
						CLR_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,EN);

						//setting the directions
						if(Channelcfg->Direction==MEMORY_TO_MEMORY){

							SET_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,MEM2MEM);
						}
						else if(Channelcfg->Direction==MEMORY_TO_PERIPH){

							SET_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,DIR);
						}
						else if(Channelcfg->Direction==PERIPH_TO_MEMORY){

							CLR_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,DIR);
									}
						//setting the desired priority
						DMA2->CHANNEL[Channelcfg->channel].CCR &=~(3<<PL);
						DMA2->CHANNEL[Channelcfg->channel].CCR |=(Channelcfg->priority<<PL);

						//setting the memory Alligment size
						DMA2->CHANNEL[Channelcfg->channel].CCR &=~(3<<MSIZE);
						DMA2->CHANNEL[Channelcfg->channel].CCR |=(Channelcfg->mem_size<<MSIZE);

						//setting the memory Alligment size
						DMA2->CHANNEL[Channelcfg->channel].CCR &=~(3<<PSIZE);
						DMA2->CHANNEL[Channelcfg->channel].CCR |=(Channelcfg->periph_size << PSIZE);

						//choosing the Peripheral inc
						WRITE_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,PINC,Channelcfg->PeriphInc );
						//choosing the mem inc
						WRITE_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,MINC,Channelcfg->MemInc);
						//Choosing the mode
						WRITE_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,CIRC,Channelcfg->mode);


				}else{
					local_u8ErrorState=OUT_OF_RANGE;

				}


	}
	else{
		local_u8ErrorState=OUT_OF_RANGE;

	}
	return local_u8ErrorState;

}
void DMA_VoidSetAddresses(const DMA_ChannelCfg_t *Channelcfg ,u32 PeripheralAddress , u32  MemoryAddress , u32 Copy_u32BlockLength)
{

	if(Channelcfg->dma==DMA_1){
		  CLR_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,EN);

			//write Peripheral Address
			DMA1->CHANNEL[Channelcfg->channel].CPAR = (u32)PeripheralAddress;

			//write Memory Address
			DMA1->CHANNEL[Channelcfg->channel].CMAR = (u32)MemoryAddress;

			//write Block Length
			DMA1->CHANNEL[Channelcfg->channel].CNDTR = Copy_u32BlockLength;
			//enable channel
		//	SET_BIT(DMA->CHANNEL[channel].CCR , EN);
	}
	else if(Channelcfg->dma==DMA_2){


	//make sure channel is disable
	CLR_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,EN);

	//write Peripheral Address
	DMA2->CHANNEL[Channelcfg->channel].CPAR = (u32)PeripheralAddress;

	//write Memory Address
	DMA2->CHANNEL[Channelcfg->channel].CMAR = (u32)MemoryAddress;

	//write Block Length
	DMA2->CHANNEL[Channelcfg->channel].CNDTR = Copy_u32BlockLength;
	//enable channel
//	SET_BIT(DMA->CHANNEL[channel].CCR , EN);
	}
}

void DMA_Voidchannel_Enable(const DMA_ChannelCfg_t *Channelcfg){
	if(Channelcfg->dma==DMA_1){
	SET_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,EN);
	}
	else{
		SET_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,EN);
	}
}
void DMA_Voidchannel_Disable(const DMA_ChannelCfg_t *Channelcfg){
	if(Channelcfg->dma==DMA_1){
	CLR_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,EN);
	}
	else{
		CLR_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,EN);
	}

}

void DMA_VoidFlag_Enable(const DMA_ChannelCfg_t *Channelcfg,FLAG_t flag){

	if(Channelcfg->dma==DMA_1){
	WRITE_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,flag,1);
	//	SET_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,flag);
	}
	else{
	WRITE_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,flag,1);
	}
}

void DMA_VoidFlag_Disable(const DMA_ChannelCfg_t *Channelcfg,FLAG_t flag){
	if(Channelcfg->dma==DMA_1){
	WRITE_BIT(DMA1->CHANNEL[Channelcfg->channel].CCR,flag,0);
	}
	else{
	WRITE_BIT(DMA2->CHANNEL[Channelcfg->channel].CCR,flag,0);
	}
}

void DMA_VoidClear_flag(const DMA_ChannelCfg_t *Channelcfg,FLAG_t flag){

	if(Channelcfg->dma==DMA_1){

		//first we calculate the bit number
		u8 localu8bitnum=(Channelcfg->channel*4)+flag;
		//second we set the desired flags bit to clear
		SET_BIT(DMA1->IFCR,localu8bitnum);

	}
	else{
		//first we calculate the bit number
		u8 localu8bitnum=(Channelcfg->channel*4)+flag;
		//second we set the desired flags bit to clear
		SET_BIT(DMA2->IFCR,localu8bitnum);

	}


}
u8 DMA_VoidRead_flag(const DMA_ChannelCfg_t *Channelcfg,FLAG_t flag){

	if(Channelcfg->dma==DMA_1){

			//first we calculate the bit number
			u8 localu8bitnum=(Channelcfg->channel*4)+flag;
			//second we read the flags bit
			return READ_BIT(DMA1->ISR,localu8bitnum);


		}
		else{
			//first we calculate the bit number
			u8 localu8bitnum=(Channelcfg->channel*4)+flag;
			//second we read the flags bit
			return READ_BIT(DMA2->ISR,localu8bitnum);

		}

}

u8 static DMA_READ_DMA2ChannelFlag(CHANNEL_NUM channel,FLAG_t flag){

	u8 localu8Returnflag;
	u8 localu8bitnum;
	localu8bitnum=(channel*4)+flag;
	localu8Returnflag=READ_BIT(DMA2->ISR,localu8bitnum);

	return localu8Returnflag;


}

void DMA_voidSetCallBack(const DMA_ChannelCfg_t *Channelcfg,void(*funcptr)(void)){

	if(Channelcfg->dma==DMA_1){

		DMA1_pfunc[Channelcfg->channel]=funcptr;
	}
	else{

		DMA2_pfunc[Channelcfg->channel]=funcptr;
	}
}
void DMA1_Channel1_IRQHandler(void){

	if(DMA1_pfunc[0]!=NULL){

		DMA1_pfunc[0]();
		DMA1->IFCR&=~(DMA_FLAGS_MASk<<(0*4));
	}

}
void DMA1_Channel2_IRQHandler(void){

	if(DMA1_pfunc[1]!=NULL){

			DMA1_pfunc[1]();
			DMA1->IFCR&=~(DMA_FLAGS_MASk<<(1*4));
		}


}
void DMA1_Channel3_IRQHandler(void){

	if(DMA1_pfunc[2]!=NULL){

				DMA1_pfunc[2]();
				DMA1->IFCR&=~(DMA_FLAGS_MASk<<(2*4));
			}


}
void DMA1_Channel4_IRQHandler(void){
	if(DMA1_pfunc[3]!=NULL){

				DMA1_pfunc[3]();
				DMA1->IFCR&=~(DMA_FLAGS_MASk<<(3*4));
			}

}
void DMA1_Channel5_IRQHandler(void){


	if(DMA1_pfunc[4]!=NULL){

				DMA1_pfunc[4]();
				DMA1->IFCR&=~(DMA_FLAGS_MASk<<(4*4));
			}


}
void DMA1_Channel6_IRQHandler(void){

	if(DMA1_pfunc[5]!=NULL){

				DMA1_pfunc[5]();
				DMA1->IFCR&=~(DMA_FLAGS_MASk<<(5*4));
			}


}
void DMA1_Channel7_IRQHandler(void){



	if(DMA1_pfunc[6]!=NULL){

				DMA1_pfunc[6]();
				DMA1->IFCR&=~(DMA_FLAGS_MASk<<(6*4));
			}


}



void DMA2_Channel1_IRQHandler(void){

	if(DMA2_pfunc[0]!=NULL){

					DMA2_pfunc[0]();
					DMA2->IFCR&=~(DMA_FLAGS_MASk<<(0*4));
				}

}
void DMA2_Channel2_IRQHandler(void){



	if(DMA2_pfunc[1]!=NULL){

					DMA2_pfunc[1]();
					DMA2->IFCR&=~(DMA_FLAGS_MASk<<(1*4));
				}


}
void DMA2_Channel3_IRQHandler(void){

	if(DMA2_pfunc[2]!=NULL){

					DMA2_pfunc[2]();
					DMA2->IFCR&=~(DMA_FLAGS_MASk<<(2*4));
				}



}
void DMA2_Channel4_5_IRQHandler(void){


	if(DMA2_pfunc[3]!=NULL&&DMA_READ_DMA2ChannelFlag(CHANNEL4,GLOBAL_FLAG)==1){

					DMA2_pfunc[3]();
					DMA2->IFCR&=~(DMA_FLAGS_MASk<<(3*4));
				}
	else if(DMA2_pfunc[4]!=NULL&&DMA_READ_DMA2ChannelFlag(CHANNEL5,GLOBAL_FLAG)==1) {

		DMA2_pfunc[4]();
	     DMA2->IFCR&=~(DMA_FLAGS_MASk<<(4*4));

	}
}



