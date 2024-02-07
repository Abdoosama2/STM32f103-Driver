/*
 * GPIO.interface.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Nitro 5
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


typedef enum{
	 PORTA=0,
	 PORTB,
	 PORTC,
	 PORTD,
	 PORTE,
	 TOTAL_PORT_NUM
}Port_t;


typedef enum{
PIN0=0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7,
PIN8,
PIN9,
PIN10,
PIN11,
PIN12,
PIN13,
PIN14,
PIN15,
TOTAL_PIN_NUM
}Pin_t;

typedef enum{
	INPUT=0,
	OUTPUT_10MHZ,
	OUTPUT_2MHZ,
	OUTPUT_50MHZ
}Mode_t;

typedef enum{
	OP_PUSH_PULL,
	OP_OPEN_DRAIN,
	AF_PUSH_PULL,
	AF_OPEN_DRAIN

}Output_cfg_t;

typedef enum{
ANALOG,
FLOATING,
PULL_UP_DOWM

}Input_cfg_t;

typedef enum{
	PIN_LOW=0,
	PIN_HIGH,

}PinVal_t;



typedef struct{
		Port_t port;
		Pin_t pin_num;
		Mode_t mode;
		Output_cfg_t outputType;
		Input_cfg_t inputtype;
	}PinConfig_t;

	    u8 Gpio_u8PinInit(const PinConfig_t* PinConfig);
		u8 Gpio_u8_SetPinvalue(Port_t port,Pin_t PinNum,PinVal_t PinVal);
		u8 Gpio_u8_TogglePinvalue(Port_t port,Pin_t PinNum);
	    u8 Gpio_u8_GetPinvalue(Port_t port,Pin_t PinNum,PinVal_t* PinVal);
	    PinVal_t Gpio_u8_ReturnPinvalue(Port_t port,Pin_t PinNum);



#endif /* GPIO_INTERFACE_H_ */
