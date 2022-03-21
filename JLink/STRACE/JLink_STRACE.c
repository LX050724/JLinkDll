//
// Created by yaoji on 2022/3/20.
//

#include "JLink_STRACE.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINK_STRACE_Config)(const char *sConfig);
static int (*P_JLINK_STRACE_Control)(uint32_t Cmd, void *pData);
static int (*P_JLINK_STRACE_GetInstStats)(void *paItem, uint32_t Addr, uint32_t NumItems, uint32_t SizeOfStruct, uint32_t Type);
static int (*P_JLINK_STRACE_Read)(uint32_t *paItem, uint32_t NumItems);
static int (*P_JLINK_STRACE_Start)(void);
static int (*P_JLINK_STRACE_Stop)(void);

int JLINK_STRACE_Init() {
    P_JLINK_STRACE_Config = JLinkDLL_getSym("JLINK_STRACE_Config");
    if (P_JLINK_STRACE_Config == NULL) return 0;
    P_JLINK_STRACE_Control = JLinkDLL_getSym("JLINK_STRACE_Control");
    if (P_JLINK_STRACE_Control == NULL) return 0;
    P_JLINK_STRACE_GetInstStats = JLinkDLL_getSym("JLINK_STRACE_GetInstStats");
    if (P_JLINK_STRACE_GetInstStats == NULL) return 0;
    P_JLINK_STRACE_Read = JLinkDLL_getSym("JLINK_STRACE_Read");
    if (P_JLINK_STRACE_Read == NULL) return 0;
    P_JLINK_STRACE_Start = JLinkDLL_getSym("JLINK_STRACE_Start");
    if (P_JLINK_STRACE_Start == NULL) return 0;
    P_JLINK_STRACE_Stop = JLinkDLL_getSym("JLINK_STRACE_Stop");
    if (P_JLINK_STRACE_Stop == NULL) return 0;
    return 1;
}
//PYTHON CHECK POINT
int JLINK_STRACE_Config(const char *sConfig) {
    return JLinkDLL_CALLPTR(P_JLINK_STRACE_Config, sConfig);
}

int JLINK_STRACE_Control(uint32_t Cmd, void *pData) {
    return JLinkDLL_CALLPTR(P_JLINK_STRACE_Control, Cmd, pData);
}

int JLINK_STRACE_GetInstStats(void *paItem, uint32_t Addr, uint32_t NumItems, uint32_t SizeOfStruct, uint32_t Type) {
    return JLinkDLL_CALLPTR(P_JLINK_STRACE_GetInstStats, paItem, Addr, NumItems, SizeOfStruct, Type);
}

int JLINK_STRACE_Read(uint32_t *paItem, uint32_t NumItems) {
    return JLinkDLL_CALLPTR(P_JLINK_STRACE_Read, paItem, NumItems);
}

int JLINK_STRACE_Start(void) {
    return JLinkDLL_CALLPTR(P_JLINK_STRACE_Start);
}

int JLINK_STRACE_Stop(void) {
    return JLinkDLL_CALLPTR(P_JLINK_STRACE_Stop);
}
//PYTHON CHECK POINT