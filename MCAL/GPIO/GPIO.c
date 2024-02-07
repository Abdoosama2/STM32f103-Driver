/*
 * GPIO.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Abdelrahman Osama
 */

/*****INCLUDESS****/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "STM32F103xx.h"
#include "GPIO.interface.h"
#include "GPIO_private.h"
#include "Err_Type.h"

static Gpio_Reg_t *GPIO_PORT[TOTAL_PORT_NUM] = { GPIOA, GPIOB, GPIOC, GPIOD,
		GPIOE };

/* @fn Gpio_u8PinInit
 * @breif this function set the init status to the pin (output,configrations..)
 * @param[in] PinConfig :pointer to the stack pinconfig_T
 *
 *
 *
 */

u8 Gpio_u8PinInit(const PinConfig_t *PinConfig) {

	u8 local_u8ErrorState = OK;

	if (PinConfig->port < TOTAL_PORT_NUM
			&& PinConfig->pin_num < TOTAL_PIN_NUM) {

		u8 local_u8RegNum = (PinConfig->pin_num / 8);
		u8 local_u8BitNum = (PinConfig->pin_num % 8);

		/****** CLEAR THE ALL BITS FOR MOD AND CFN*****/
		GPIO_PORT[PinConfig->port]->CR[local_u8RegNum] &= ~((CRL_LH_MASK)
				<< ((local_u8BitNum) * CRL_LH_PIN_ACSESS));
		/*****SET THE MODE FOR THE PIN****/
		GPIO_PORT[PinConfig->port]->CR[local_u8RegNum] |= ((PinConfig->mode)
				<< ((local_u8BitNum) * CRL_LH_PIN_ACSESS));
		/*****SET THE configration FOR THE PIN****/
		if (PinConfig->mode != INPUT) {

			GPIO_PORT[PinConfig->port]->CR[local_u8RegNum] |=
					((PinConfig->outputType)
							<< (((local_u8BitNum) * CRL_LH_PIN_ACSESS) + 2));
		} else {
			GPIO_PORT[PinConfig->port]->CR[local_u8RegNum] |=
					((PinConfig->inputtype)
							<< (((local_u8BitNum) * CRL_LH_PIN_ACSESS) + 2));
		}

	} else {

		local_u8ErrorState = NOK;
	}

	return local_u8ErrorState;

}

/* @fn Gpio_u8_SetPinvalue
 * @breif this function set the output value to a certian pin
 * @param[in] port :the port number in the port_t enum
 * @param[in] pinnum: the pin number in the pin_T enum
 * @param[in] pinval: the output value to the sepecfic pin
 *
 *
 */
u8 Gpio_u8_SetPinvalue(Port_t port, Pin_t PinNum, PinVal_t PinVal) {

	u8 local_u8ErrorState = OK;
	if (port < TOTAL_PORT_NUM && PinNum < TOTAL_PIN_NUM) {

		if (PinVal == PIN_HIGH) {
			WRITE_BIT(GPIO_PORT[port]->ODR, PinNum, PIN_HIGH);
		}

		else if (PinVal == PIN_LOW) {
			WRITE_BIT(GPIO_PORT[port]->ODR, PinNum, PIN_LOW);
		} else {
			local_u8ErrorState = NOK;
		}

	} else {

		local_u8ErrorState = NOK;
	}

	return local_u8ErrorState;

}
/* @fn Gpio_u8_TogglePinvalue
 * @breif this function toggle the output value to a certian pin
 * @param[in] port :the port number in the port_t enum
 * @param[in] pinnum: the pin number in the pin_T enum
 * @
 *
 *
 */

u8 Gpio_u8_TogglePinvalue(Port_t port, Pin_t PinNum) {
	u8 local_u8ErrorState = OK;
	if (port < TOTAL_PORT_NUM && PinNum < TOTAL_PIN_NUM) {

		TOG_BIT(GPIO_PORT[port]->ODR, PinNum);

	} else {
		local_u8ErrorState = NOK;

	}
	return local_u8ErrorState;

}

/* @fn Gpio_u8_GetPinvalue
 * @breif this function to get the input value in a certian pin
 * @param[in] port :the port number in the port_t enum
 * @param[in] pinnum: the pin number in the pin_T enum
 * @param[in] pinval: a pointer to return the input value
 *
 *
 */
u8 Gpio_u8_GetPinvalue(Port_t port, Pin_t PinNum, PinVal_t *PinVal) {

	u8 local_u8ErrorState = OK;
	if (port < TOTAL_PORT_NUM && PinNum < TOTAL_PIN_NUM) {

		*PinVal = READ_BIT(GPIO_PORT[port]->IDR, PinNum);

	} else {
		local_u8ErrorState = NOK;

	}

	return local_u8ErrorState;
}



PinVal_t Gpio_u8_ReturnPinvalue(Port_t port,Pin_t PinNum){

	PinVal_t localpinval;
	if (port < TOTAL_PORT_NUM && PinNum < TOTAL_PIN_NUM) {

		localpinval=READ_BIT(GPIO_PORT[port]->IDR,PinNum);
		return localpinval;
	}





}




