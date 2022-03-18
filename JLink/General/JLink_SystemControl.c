//
// Created by yaoji on 2022/3/18.
//

#include "JLink_SystemControl.h"
#include "JLink/JLink_Init.h"

static uint32_t (*P_JLINKARM_GetDLLVersion)();
static void (*P_JLINKARM_ClrRESET)(void);
static int (*P_JLINKARM_ClrTCK)(void);
static void (*P_JLINKARM_ClrTDI)(void);
static void (*P_JLINKARM_ClrTMS)(void);
static void (*P_JLINKARM_ClrTRST)(void);
static void (*P_JLINKARM_ClrError)(void);

int JLINK_GERENAL_SystemControl_Init() {
    P_JLINKARM_GetDLLVersion = JLinkDLL_getSym("JLINKARM_GetDLLVersion");
    if (P_JLINKARM_GetDLLVersion == NULL) return 0;
    P_JLINKARM_ClrRESET = JLinkDLL_getSym("JLINKARM_ClrRESET");
    if (P_JLINKARM_ClrRESET == NULL) return 0;
    P_JLINKARM_ClrTCK = JLinkDLL_getSym("JLINKARM_ClrTCK");
    if (P_JLINKARM_ClrTCK == NULL) return 0;
    P_JLINKARM_ClrTDI = JLinkDLL_getSym("JLINKARM_ClrTDI");
    if (P_JLINKARM_ClrTDI == NULL) return 0;
    P_JLINKARM_ClrTMS = JLinkDLL_getSym("JLINKARM_ClrTMS");
    if (P_JLINKARM_ClrTMS == NULL) return 0;
    P_JLINKARM_ClrTRST = JLinkDLL_getSym("JLINKARM_ClrTRST");
    if (P_JLINKARM_ClrTRST == NULL) return 0;
    P_JLINKARM_ClrError = JLinkDLL_getSym("JLINKARM_ClrError");
    if (P_JLINKARM_ClrError == NULL) return 0;
    return 1;
}

uint32_t JLINKARM_GetDLLVersion(void) {
    return P_JLINKARM_GetDLLVersion();
}


void JLINKARM_ClrRESET(void) {
    P_JLINKARM_ClrRESET();
}

int JLINKARM_ClrTCK(void) {
    return P_JLINKARM_ClrTCK();
}

void JLINKARM_ClrTDI(void) {
    P_JLINKARM_ClrTDI();
}

void JLINKARM_ClrTMS(void) {
    P_JLINKARM_ClrTMS();
}

void JLINKARM_ClrTRST(void) {
    P_JLINKARM_ClrTRST();
}

void JLINKARM_ClrError(void) {
    P_JLINKARM_ClrError();
}
