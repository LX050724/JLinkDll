//
// Created by yaoji on 2022/3/18.
//

#include "JLink_RTT.h"
#include "JLink/JLink_Init.h"

static int (*P_JLINK_RTTERMINAL_Control)(uint32_t Cmd, void *p);
static int (*P_JLINK_RTTERMINAL_Read)(uint32_t BufferIndex, char *sBuffer, uint32_t BufferSize);
static int (*P_JLINK_RTTERMINAL_Write)(uint32_t BufferIndex, const char *sBuffer, uint32_t BufferSize);

int JLINK_RTT_Init() {
    P_JLINK_RTTERMINAL_Control = JLinkDLL_getSym("JLINK_RTTERMINAL_Control");
    if (P_JLINK_RTTERMINAL_Control == NULL) return 0;
    P_JLINK_RTTERMINAL_Read = JLinkDLL_getSym("JLINK_RTTERMINAL_Read");
    if (P_JLINK_RTTERMINAL_Read == NULL) return 0;
    P_JLINK_RTTERMINAL_Write = JLinkDLL_getSym("JLINK_RTTERMINAL_Write");
    if (P_JLINK_RTTERMINAL_Write == NULL) return 0;
    return 1;
}
//PYTHON CHECK POINT
int JLINK_RTTERMINAL_Control(uint32_t Cmd, void *p) {
    return JLinkDLL_CALLPTR(P_JLINK_RTTERMINAL_Control, Cmd, p);
}

int JLINK_RTTERMINAL_Read(uint32_t BufferIndex, char *sBuffer, uint32_t BufferSize) {
    return JLinkDLL_CALLPTR(P_JLINK_RTTERMINAL_Read, BufferIndex, sBuffer, BufferSize);
}

int JLINK_RTTERMINAL_Write(uint32_t BufferIndex, const char *sBuffer, uint32_t BufferSize) {
    return JLinkDLL_CALLPTR(P_JLINK_RTTERMINAL_Write, BufferIndex, sBuffer, BufferSize);
}
//PYTHON CHECK POINT