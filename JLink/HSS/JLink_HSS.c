//
// Created by yaoji on 2022/3/20.
//

#include "JLink_HSS.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINK_HSS_Start)(JLINK_HSS_MEM_BLOCK_DESC *paDesc, int NumBlocks, int Period_us, int Flags);
static int (*P_JLINK_HSS_Stop)(void);
static int (*P_JLINK_HSS_Read)(void *pBuffer, uint32_t BufferSize);

int JLINK_HSS_Init() {
    P_JLINK_HSS_Start = JLinkDLL_getSym("JLINK_HSS_Start");
    if (P_JLINK_HSS_Start == NULL) return 0;
    P_JLINK_HSS_Stop = JLinkDLL_getSym("JLINK_HSS_Stop");
    if (P_JLINK_HSS_Stop == NULL) return 0;
    P_JLINK_HSS_Read = JLinkDLL_getSym("JLINK_HSS_Read");
    if (P_JLINK_HSS_Read == NULL) return 0;
    return 1;
}

int JLINK_HSS_Start(JLINK_HSS_MEM_BLOCK_DESC *paDesc, int NumBlocks, int Period_us, int Flags) {
    return P_JLINK_HSS_Start(paDesc, NumBlocks, Period_us, Flags);
}

int JLINK_HSS_Stop(void) {
    return P_JLINK_HSS_Stop();
}

int JLINK_HSS_Read(void *pBuffer, uint32_t BufferSize) {
    return P_JLINK_HSS_Read(pBuffer, BufferSize);
}