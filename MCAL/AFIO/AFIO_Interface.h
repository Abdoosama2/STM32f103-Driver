/*
 * AFIO_Interface.h
 *
 *  Created on: Feb 12, 2024
 *      Author: Nitro 5
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_


//enum for ports
typedef enum{
	 pORTA=0,
	 pORTB,
	 pORTC,
	 pORTD,
	 pORTE,
	 tOTAL_PORT_NUM
}Port_type;



//enum for pin numbers
typedef enum{
pIN0=0,
pIN1,
pIN2,
pIN3,
pIN4,
pIN5,
pIN6,
pIN7,
pIN8,
pIN9,
pIN10,
pIN11,
pIN12,
pIN13,
pIN14,
pIN15,
tOTAL_PIN_NUM
}Pin_type;

/**
 * @brief Sets the EXTI (External Interrupt) line for a specific pin on a microcontroller.
 *
 * This function configures the EXTI line for a given pin and port on a microcontroller.
 * It clears the existing configuration bits related to the pin and sets new configuration
 * bits corresponding to the selected port.
 *
 * @param port The port for which the EXTI line will be configured.
 * @param pin The pin number for which the EXTI line will be configured.
 *
 * @return uint8_t The error state of the function.
 * - OK: Indicates successful configuration of the EXTI line.
 * - OUT_OF_RANGE: Indicates that either the port or pin number is out of range.
 *
 * @note This function assumes direct hardware register manipulation and is intended for
 * use in embedded systems programming, particularly for microcontroller environments.
 */
u8 AFIO_Set_EXTI_line(Port_type port,Pin_type pin);




#endif /* AFIO_INTERFACE_H_ */
