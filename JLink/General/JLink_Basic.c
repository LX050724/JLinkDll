//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Basic.h"
#include "JLink/JLink_Init.h"

static void (*P_JLINKARM_Close)(void);
static int (*P_JLINKARM_Connect)(void);
static void (*P_JLINKARM_Go)(void);
static void (*P_JLINKARM_GoIntDis)(void);
static char (*P_JLINKARM_Halt)(void);
static void (*P_JLINKARM_GoEx)(uint32_t MaxEmulInsts, uint32_t Flags);
static char (*P_JLINKARM_IsConnected)(void);
static char (*P_JLINKARM_IsHalted)(void);
static char (*P_JLINKARM_IsOpen)(void);
static void (*P_JLINKARM_Lock)(void);
static const char *(*P_JLINKARM_Open)(void);
static const char *(*P_JLINKARM_OpenEx)(JLINKARM_LOG *pfLog, JLINKARM_LOG *pfErrorOut);
static void (*P_JLINKARM_Unlock)(void);

int JLINK_GERENAL_BASE_Init() {
    P_JLINKARM_Close = JLinkDLL_getSym("JLINKARM_Close");
    if (P_JLINKARM_Close == NULL) return 0;
    P_JLINKARM_Connect = JLinkDLL_getSym("JLINKARM_Connect");
    if (P_JLINKARM_Connect == NULL) return 0;
    P_JLINKARM_Go = JLinkDLL_getSym("JLINKARM_Go");
    if (P_JLINKARM_Go == NULL) return 0;
    P_JLINKARM_GoIntDis = JLinkDLL_getSym("JLINKARM_GoIntDis");
    if (P_JLINKARM_GoIntDis == NULL) return 0;
    P_JLINKARM_Halt = JLinkDLL_getSym("JLINKARM_Halt");
    if (P_JLINKARM_Halt == NULL) return 0;
    P_JLINKARM_GoEx = JLinkDLL_getSym("JLINKARM_GoEx");
    if (P_JLINKARM_GoEx == NULL) return 0;
    P_JLINKARM_IsConnected = JLinkDLL_getSym("JLINKARM_IsConnected");
    if (P_JLINKARM_IsConnected == NULL) return 0;
    P_JLINKARM_IsHalted = JLinkDLL_getSym("JLINKARM_IsHalted");
    if (P_JLINKARM_IsHalted == NULL) return 0;
    P_JLINKARM_IsOpen = JLinkDLL_getSym("JLINKARM_IsOpen");
    if (P_JLINKARM_IsOpen == NULL) return 0;
    P_JLINKARM_Lock = JLinkDLL_getSym("JLINKARM_Lock");
    if (P_JLINKARM_Lock == NULL) return 0;
    P_JLINKARM_Open = JLinkDLL_getSym("JLINKARM_Open");
    if (P_JLINKARM_Open == NULL) return 0;
    P_JLINKARM_OpenEx = JLinkDLL_getSym("JLINKARM_OpenEx");
    if (P_JLINKARM_OpenEx == NULL) return 0;
    P_JLINKARM_Unlock = JLinkDLL_getSym("JLINKARM_Unlock");
    if (P_JLINKARM_Unlock == NULL) return 0;
    return 1;
}
//PYTHON CHECK POINT
void JLINKARM_Close(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_Close);
}

int JLINKARM_Connect(void) {
    return JLinkDLL_CALLPTR(P_JLINKARM_Connect);
}

void JLINKARM_Go(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_Go);
}

void JLINKARM_GoIntDis(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_GoIntDis);
}

char JLINKARM_Halt(void) {
    return JLinkDLL_CALLPTR(P_JLINKARM_Halt);
}


void JLINKARM_GoEx(uint32_t MaxEmulInsts, uint32_t Flags) {
    JLinkDLL_CALLPTR(P_JLINKARM_GoEx, MaxEmulInsts, Flags);
}


char JLINKARM_IsConnected(void) {
    return JLinkDLL_CALLPTR(P_JLINKARM_IsConnected);
}

char JLINKARM_IsHalted(void) {
    return JLinkDLL_CALLPTR(P_JLINKARM_IsHalted);
}

char JLINKARM_IsOpen(void) {
    return JLinkDLL_CALLPTR(P_JLINKARM_IsOpen);
}

void JLINKARM_Lock(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_Lock);
}

const char *JLINKARM_Open(void) {
    return JLinkDLL_CALLPTR(P_JLINKARM_Open);
}

const char *JLINKARM_OpenEx(JLINKARM_LOG *pfLog, JLINKARM_LOG *pfErrorOut) {
    return JLinkDLL_CALLPTR(P_JLINKARM_OpenEx, pfLog, pfErrorOut);
}

void JLINKARM_Unlock(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_Unlock);
}
//PYTHON CHECK POINT
