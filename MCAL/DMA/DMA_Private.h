/*
 * DMA_Private.h
 *
 * This file contains private definitions and structures related to DMA (Direct Memory Access).
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrahman Osama
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

// Base addresses for DMA controllers
#define DMA1_BASE_ADDRESS 0x40020000U
#define DMA2_BASE_ADDRESS 0x40020400U

// Structure representing the registers associated with each DMA channel
typedef struct {
    volatile u32 CCR;   // DMA channel configuration register
    volatile u32 CNDTR; // DMA channel number of data register
    volatile u32 CPAR;  // DMA channel peripheral address register
    volatile u32 CMAR;  // DMA channel memory address register
    volatile u32 RESERVED;
} DMA_CHANNELS_REG;

// Structure representing DMA registers
typedef struct {
    volatile u32 ISR;            // DMA interrupt status register
    volatile u32 IFCR;           // DMA interrupt flag clear register
    DMA_CHANNELS_REG CHANNEL[7]; // Array of DMA channel registers
} DMA_REGISTERS_t;

// DMA controller instances mapped to their base addresses
#define DMA1 ((DMA_REGISTERS_t*)DMA1_BASE_ADDRESS)
#define DMA2 ((DMA_REGISTERS_t*)DMA2_BASE_ADDRESS)

/* DMA_CCRx BITS */
#define MEM2MEM 14 // Memory to memory mode
#define PL 12      // Channel priority level
#define MSIZE 10   // Memory size
#define PSIZE 8    // Peripheral size
#define MINC 7     // Memory increment mode
#define PINC 6     // Peripheral increment mode
#define CIRC 5     // Circular mode
#define DIR 4      // Data transfer direction
#define TEIE 3     // Transfer error interrupt enable
#define HTIE 2     // Half transfer interrupt enable
#define TCIE 1     // Transfer complete interrupt enable
#define EN 0       // Channel enable

#endif /* DMA_PRIVATE_H_ */
