//
// Created by yaoji on 2022/3/20.
//

#include "JLink_SWO.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINKARM_SWO_Control)(uint32_t Cmd, void *pData);
static int (*P_JLINKARM_SWO_DisableTarget)(uint32_t PortMask);
static int (*P_JLINKARM_SWO_EnableTarget)(uint32_t CPUSpeed, uint32_t SWOSpeed, int Mode, uint32_t PortMask);
static int (*P_JLINKARM_SWO_GetCompatibleSpeeds)(uint32_t CPUSpeed, uint32_t MaxSWOSpeed, uint32_t *paSWOSpeed,
                                                 uint32_t NumEntries);
static void (*P_JLINKARM_SWO_Read)(uint8_t *pData, uint32_t Offset, uint32_t *pNumBytes);
static void (*P_JLINKARM_SWO_ReadStimulus)(int Port, uint8_t *pData, uint32_t NumBytes);

int JLINK_SWO_Init() {
    P_JLINKARM_SWO_Control = JLinkDLL_getSym("JLINKARM_SWO_Control");
    if (P_JLINKARM_SWO_Control == NULL) return 0;
    P_JLINKARM_SWO_DisableTarget = JLinkDLL_getSym("JLINKARM_SWO_DisableTarget");
    if (P_JLINKARM_SWO_DisableTarget == NULL) return 0;
    P_JLINKARM_SWO_EnableTarget = JLinkDLL_getSym("JLINKARM_SWO_EnableTarget");
    if (P_JLINKARM_SWO_EnableTarget == NULL) return 0;
    P_JLINKARM_SWO_GetCompatibleSpeeds = JLinkDLL_getSym("JLINKARM_SWO_GetCompatibleSpeeds");
    if (P_JLINKARM_SWO_GetCompatibleSpeeds == NULL) return 0;
    P_JLINKARM_SWO_Read = JLinkDLL_getSym("JLINKARM_SWO_Read");
    if (P_JLINKARM_SWO_Read == NULL) return 0;
    P_JLINKARM_SWO_ReadStimulus = JLinkDLL_getSym("JLINKARM_SWO_ReadStimulus");
    if (P_JLINKARM_SWO_ReadStimulus == NULL) return 0;
    return 1;
}
//PYTHON CHECK POINT
int JLINKARM_SWO_Control(uint32_t Cmd, void *pData) {
    return JLinkDLL_CALLPTR(P_JLINKARM_SWO_Control, Cmd, pData);
}

int JLINKARM_SWO_DisableTarget(uint32_t PortMask) {
    return JLinkDLL_CALLPTR(P_JLINKARM_SWO_DisableTarget, PortMask);
}

int JLINKARM_SWO_EnableTarget(uint32_t CPUSpeed, uint32_t SWOSpeed, int Mode, uint32_t PortMask) {
    return JLinkDLL_CALLPTR(P_JLINKARM_SWO_EnableTarget, CPUSpeed, SWOSpeed, Mode, PortMask);
}

int JLINKARM_SWO_GetCompatibleSpeeds(uint32_t CPUSpeed, uint32_t MaxSWOSpeed,
                                     uint32_t *paSWOSpeed, uint32_t NumEntries) {
    return JLinkDLL_CALLPTR(P_JLINKARM_SWO_GetCompatibleSpeeds, CPUSpeed, MaxSWOSpeed, paSWOSpeed, NumEntries);
}

void JLINKARM_SWO_Read(uint8_t *pData, uint32_t Offset, uint32_t *pNumBytes) {
    JLinkDLL_CALLPTR(P_JLINKARM_SWO_Read, pData, Offset, pNumBytes);
}

void JLINKARM_SWO_ReadStimulus(int Port, uint8_t *pData, uint32_t NumBytes) {
    JLinkDLL_CALLPTR(P_JLINKARM_SWO_ReadStimulus, Port, pData, NumBytes);
}
//PYTHON CHECK POINT