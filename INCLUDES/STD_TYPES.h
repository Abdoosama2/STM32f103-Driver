/*
 * STD_TYPES.h
 *
 *  Created on: Feb 13, 2023
 *      Author: a-m-m
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u32;
typedef signed int s32;

typedef unsigned short int u16;
typedef signed short int s16;

typedef float f32;
typedef long f64;
typedef long double f96;

typedef enum{
	BIT_RESET =0,
	BIT_SET=1
}BitStatus;

/*
typedef enum{
	OK,
	NOK,
	NULL,
	OUT_OF_RANGE
	}Error_type;
*/
#define NULL ((void*)0)

#define STD_TYPES_OK 	0;
#define STD_TYPES_NOK 	1;

#endif /* _STD_TYPES_H_ */
