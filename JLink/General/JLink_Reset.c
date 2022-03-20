//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Reset.h"
#include "JLink/JLink_Init.h"

static int (*P_JLINKARM_Reset)(void);
static void (*P_JLINKARM_ResetNoHalt)(void);
static void (*P_JLINKARM_ResetPullsRESET)(uint8_t OnOff);
static void (*P_JLINKARM_ResetPullsTRST)(uint8_t OnOff);
static void (*P_JLINKARM_ResetTRST)(void);
static int (*P_JLINKARM_SetInitRegsOnReset)(int OnOff);
static void (*P_JLINKARM_SetResetDelay)(int ms);
static void (*P_JLINKARM_SetResetType)(JLINKARM_RESET_TYPE ResetType);
static int (*P_JLINKARM_GetResetTypeDesc)(int ResetType, const char **psResetName, const char **psResetDesc);

int JLINK_GERENAL_RESET_Init() {
    P_JLINKARM_Reset = JLinkDLL_getSym("JLINKARM_Reset");
    if (P_JLINKARM_Reset == NULL) return 0;
    P_JLINKARM_ResetNoHalt = JLinkDLL_getSym("JLINKARM_ResetNoHalt");
    if (P_JLINKARM_ResetNoHalt == NULL) return 0;
    P_JLINKARM_ResetPullsRESET = JLinkDLL_getSym("JLINKARM_ResetPullsRESET");
    if (P_JLINKARM_ResetPullsRESET == NULL) return 0;
    P_JLINKARM_ResetPullsTRST = JLinkDLL_getSym("JLINKARM_ResetPullsTRST");
    if (P_JLINKARM_ResetPullsTRST == NULL) return 0;
    P_JLINKARM_ResetTRST = JLinkDLL_getSym("JLINKARM_ResetTRST");
    if (P_JLINKARM_ResetTRST == NULL) return 0;
    P_JLINKARM_SetInitRegsOnReset = JLinkDLL_getSym("JLINKARM_SetInitRegsOnReset");
    if (P_JLINKARM_SetInitRegsOnReset == NULL) return 0;
    P_JLINKARM_SetResetDelay = JLinkDLL_getSym("JLINKARM_SetResetDelay");
    if (P_JLINKARM_SetResetDelay == NULL) return 0;
    P_JLINKARM_SetResetType = JLinkDLL_getSym("JLINKARM_SetResetType");
    if (P_JLINKARM_SetResetType == NULL) return 0;
    P_JLINKARM_GetResetTypeDesc = JLinkDLL_getSym("JLINKARM_GetResetTypeDesc");
    if (P_JLINKARM_GetResetTypeDesc == NULL) return 0;
    return 1;
}

int JLINKARM_Reset(void) {
    return P_JLINKARM_Reset();
}

void JLINKARM_ResetNoHalt(void) {
    P_JLINKARM_ResetNoHalt();
}

void JLINKARM_ResetPullsRESET(uint8_t OnOff) {
    P_JLINKARM_ResetPullsRESET(OnOff);
}

void JLINKARM_ResetPullsTRST(uint8_t OnOff) {
    P_JLINKARM_ResetPullsTRST(OnOff);
}

void JLINKARM_ResetTRST(void) {
    P_JLINKARM_ResetTRST();
}

int JLINKARM_SetInitRegsOnReset(int OnOff) {
    return P_JLINKARM_SetInitRegsOnReset(OnOff);
}

void JLINKARM_SetResetDelay(int ms) {
    P_JLINKARM_SetResetDelay(ms);
}

void JLINKARM_SetResetType(JLINKARM_RESET_TYPE ResetType) {
    P_JLINKARM_SetResetType(ResetType);
}

int JLINKARM_GetResetTypeDesc(int ResetType, const char **psResetName, const char **psResetDesc) {
    return P_JLINKARM_GetResetTypeDesc(ResetType, psResetName, psResetDesc);
}
