/*
 * AFIO.c
 *
 *  Created on: Feb 12, 2024
 *      Author: Abdelrahman Osama
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "Err_Type.h"
#include "AFIO_Interface.h"
#include "AFIO_Private.h"









u8 AFIO_Set_EXTI_line(Port_type port,Pin_type pin){


	u8 local_u8ErrorState=OK;

	if(port <tOTAL_PORT_NUM && pin <tOTAL_PIN_NUM){

		u8 LocalRegNum=pin/4;
		u8 LocalBitNum=(pin%4)*4;
		(AFIO->EXTICR[LocalRegNum])&=(~(0b1111<<LocalBitNum));
		(AFIO->EXTICR[LocalRegNum])|=(port<<LocalBitNum);

	}
	else{

		local_u8ErrorState=OUT_OF_RANGE;
	}


return local_u8ErrorState;



}


