/*
 * EXTI_Interface.h
 *
 *  Created on: Feb 11, 2024
 *      Author: Abdelrahman Osama
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_




typedef enum{
	    EXTI_Line0 = 0,
	    EXTI_Line1,
	    EXTI_Line2,
	    EXTI_Line3,
	    EXTI_Line4,
	    EXTI_Line5,
	    EXTI_Line6,
	    EXTI_Line7,
	    EXTI_Line8,
	    EXTI_Line9,
	    EXTI_Line10,
	    EXTI_Line11,
	    EXTI_Line12,
	    EXTI_Line13,
	    EXTI_Line14,
	    EXTI_Line15,
	    EXTI_Line16, // Reserved for PVD (Power Voltage Detector)
	    EXTI_Line17, // Reserved for RTC Alarm
	    EXTI_Line18, // Reserved for USB Wakeup
	    EXTI_Line19 ,
		TOTAL_LINES// Reserved for Ethernet Wakeup
	    // EXTI_Line20 to EXTI_Line23 are used for software interrupts
	    // EXTI_Line24 to EXTI_Line31 are not used in STM32F103 series


}EXTI_Line_t;

typedef enum{
	falling_edge=0,
	rising_edge

}EDGE_t;

typedef enum{
	Disable=0,
	Enable

}STATE_t;

/**
 * @brief Enables the EXTI (External Interrupt) line specified by the given line number.
 *
 * This function enables the EXTI line for interrupt detection.
 *
 * @param line The EXTI line number to be enabled.
 *
 * @return uint8_t The error state of the function.
 * - OK: Indicates successful enablement of the EXTI line.
 * - ERROR: Indicates an error occurred during enablement.
 */
u8 EXTI_u8Enable(EXTI_Line_t line);


/**
 * @brief Disables the EXTI (External Interrupt) line specified by the given line number.
 *
 * This function disables the EXTI line, preventing interrupt detection.
 *
 * @param line The EXTI line number to be disabled.
 *
 * @return uint8_t The error state of the function.
 * - OK: Indicates successful disablement of the EXTI line.
 * - ERROR: Indicates an error occurred during disablement.
 */
u8 EXTI_u8Disable(EXTI_Line_t line);


/**
 * @brief Sets the trigger edge for the EXTI (External Interrupt) line specified by the given line number.
 *
 * This function configures the trigger edge (rising, falling, or both) for interrupt detection on the specified EXTI line.
 *
 * @param line The EXTI line number for which the trigger edge will be configured.
 * @param edge The trigger edge type (rising, falling, or both).
 *
 * @return uint8_t The error state of the function.
 * - OK: Indicates successful configuration of the trigger edge.
 * - ERROR: Indicates an error occurred during configuration.
 */
u8 EXTI_u8Set_Trigger(EXTI_Line_t line, EDGE_t edge);


/**
 * @brief Clears the pending flag for the EXTI (External Interrupt) line specified by the given line number.
 *
 * This function clears the pending flag for the specified EXTI line, indicating that the interrupt request has been serviced.
 *
 * @param line The EXTI line number for which the pending flag will be cleared.
 *
 * @return uint8_t The error state of the function.
 * - OK: Indicates successful clearing of the pending flag.
 * - ERROR: Indicates an error occurred during clearing.
 */
u8 EXTI_u8Clear_pendingflag(EXTI_Line_t line);


/**
 * @brief Reads the pending flag status for the EXTI (External Interrupt) line specified by the given line number.
 *
 * This function reads the status of the pending flag for the specified EXTI line.
 *
 * @param line The EXTI line number for which the pending flag status will be read.
 *
 * @return uint8_t The pending flag status.
 * - 0: Pending flag is not set.
 * - 1: Pending flag is set.
 */
u8 EXTI_u8Read_pendingflag(EXTI_Line_t line);


/**
 * @brief Sets the callback function for the EXTI (External Interrupt) line specified by the given line number.
 *
 * This function sets the callback function to be executed when an interrupt occurs on the specified EXTI line.
 *
 * @param line The EXTI line number for which the callback function will be set.
 * @param LocalPtr Pointer to the callback function.
 *
 * @return uint8_t The error state of the function.
 * - OK: Indicates successful setting of the callback function.
 * - ERROR: Indicates an error occurred during setting.
 */
u8 EXTI_u8Set_callback(EXTI_Line_t line, void (*LocalPtr)(void));







#endif /* EXTI_INTERFACE_H_ */
