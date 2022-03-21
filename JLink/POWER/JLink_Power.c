//
// Created by yaoji on 2022/3/20.
//

#include "JLink_Power.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINK_POWERTRACE_Control)(int Cmd, void *pIn, void *pOut);
static int (*P_JLINK_POWERTRACE_Read)(JLINK_POWERTRACE_DATA_ITEM *paData, uint32_t NumItems);

int JLINK_POWERTRACE_Init() {
    P_JLINK_POWERTRACE_Control = JLinkDLL_getSym("JLINK_POWERTRACE_Control");
    if (P_JLINK_POWERTRACE_Control == NULL) return 0;
    P_JLINK_POWERTRACE_Read = JLinkDLL_getSym("JLINK_POWERTRACE_Read");
    if (P_JLINK_POWERTRACE_Read == NULL) return 0;
    return 1;
}
//PYTHON CHECK POINT
int JLINK_POWERTRACE_Control(int Cmd, void *pIn, void *pOut) {
    return JLinkDLL_CALLPTR(P_JLINK_POWERTRACE_Control, Cmd, pIn, pOut);
}
int JLINK_POWERTRACE_Read(JLINK_POWERTRACE_DATA_ITEM *paData, uint32_t NumItems) {
    return JLinkDLL_CALLPTR(P_JLINK_POWERTRACE_Read, paData, NumItems);
}
//PYTHON CHECK POINT