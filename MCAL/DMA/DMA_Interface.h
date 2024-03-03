/*
 * DMA_Interface.h
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdelrahman Osama
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

// Define guard to prevent multiple inclusion of the header file

// Enumeration defining different DMA channels
typedef enum {
    CHANNEL1 = 0,
    CHANNEL2,
    CHANNEL3,
    CHANNEL4,
    CHANNEL5,
    CHANNEL6,
    CHANNEL7,
    TOTAL_CHANNEL_NUM
} CHANNEL_NUM;

// Enumeration defining priority levels for DMA channels
typedef enum {
    Low,
    MEDIUM,
    HIGH,
    Very_HIGH
} CHANNEL_PRIORITY;

// Enumeration defining memory transfer size options
typedef enum {
    MEM_BITS_8,
    MEM_BITS_16,
    MEM_BITS_32,
    MEM_RESERVED,
} MEMORY_SIZE;

// Enumeration defining peripheral transfer size options
typedef enum {
    PER_BITS_8,
    PER_BITS_16,
    PER_BITS_32,
    PER_RESERVED,
} PERIPHERAL_SIZE;

// Enumeration defining DMA controller types
typedef enum {
    DMA_1,
    DMA_2
} DMA_TYPE;

// Enumeration defining transfer directions
typedef enum {
    MEMORY_TO_MEMORY,
    MEMORY_TO_PERIPH,
    PERIPH_TO_MEMORY
} DIRECTION_t;

// Enumeration defining memory increment options
typedef enum {
    MEM_INC_DISABLE,
    MEM_INC_ENABLE
} MEMORY_INC;

// Enumeration defining peripheral increment options
typedef enum {
    PERIPH_INC_DISABLE,
    PERIPH_INC_ENABLE
} PERIPH_INC;

// Enumeration defining DMA operation modes
typedef enum {
    NORMAL,
    CIRCULAR
} MODE_t;

// Enumeration defining DMA flags
typedef enum {
    GLOBAL_FLAG = 0,
    TRANS_COMPELETE = 1,
    TRANS_HALF = 2,
    TRANS_ERR = 3
} FLAG_t;

// Structure to hold DMA channel configuration
typedef struct {
    DMA_TYPE dma;
    CHANNEL_NUM channel;
    CHANNEL_PRIORITY priority;
    MEMORY_SIZE mem_size;
    PERIPHERAL_SIZE periph_size;
    DIRECTION_t Direction;
    MODE_t mode;
    PERIPH_INC PeriphInc;
    MEMORY_INC MemInc;
} DMA_ChannelCfg_t;

// Function prototypes for DMA operations

// Initialize DMA channel with provided configuration
u8 DMA_U8Channel_Init(const DMA_ChannelCfg_t *Channelcfg);

// Set peripheral and memory addresses and block length for DMA transfer
void DMA_VoidSetAddresses(const DMA_ChannelCfg_t *Channelcfg, u32 PeripheralAddress, u32 MemoryAddress, u32 Copy_u32BlockLength);

// Enable DMA channel
void DMA_Voidchannel_Enable(const DMA_ChannelCfg_t *Channelcfg);

// Disable DMA channel
void DMA_Voidchannel_Disable(const DMA_ChannelCfg_t *Channelcfg);

// Enable specific DMA flag
void DMA_VoidFlag_Enable(const DMA_ChannelCfg_t *Channelcfg, FLAG_t flag);

// Disable specific DMA flag
void DMA_VoidFlag_Disable(const DMA_ChannelCfg_t *Channelcfg, FLAG_t flag);

// Clear specific DMA flag
void DMA_VoidClear_flag(const DMA_ChannelCfg_t *Channelcfg, FLAG_t flag);

// Read status of specific DMA flag
u8 DMA_VoidRead_flag(const DMA_ChannelCfg_t *Channelcfg, FLAG_t flag);

// Set callback function for DMA channel
void DMA_voidSetCallBack(const DMA_ChannelCfg_t *Channelcfg, void (*funcptr)(void));

// Read DMA2 channel flag (specific to DMA2)
u8 static DMA_READ_DMA2ChannelFlag(CHANNEL_NUM channel, FLAG_t flag);

#endif /* DMA_INTERFACE_H_ */
