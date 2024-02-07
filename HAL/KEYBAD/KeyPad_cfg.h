/*
 * KeyPad_cfg.h
 *
 *  Created on: Dec 16, 2023
 *      Author: Nitro 5
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define  COLS    4
#define  ROWS    4



#ifdef KEYPAD_C

const   u8 KeysArray[ROWS][COLS]={  {'7','8','9','+'},
							        {'4','5','6','-'},
							        {'1','2','3','/'},
							        {'c','0','=','*'} };



#endif

#define  NO_KEY   'T'

#define  FIRST_OUTPUT  PIN4
#define  COULMN_1 PIN11
#define  COULMN_2 PIN10
#define  COULMN_3 PIN1
#define  COULMN_4 PIN0






#endif /* KEYPAD_CFG_H_ */
