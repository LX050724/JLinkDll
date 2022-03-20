//
// Created by yaoji on 2022/3/20.
//

#include "JLink_SWD.h"
#include <JLink/JLink_Init.h>

static uint32_t (*P_JLINKARM_SWD_GetU8)(int BitPos);
static uint32_t (*P_JLINKARM_SWD_GetU16)(int BitPos);
static uint32_t (*P_JLINKARM_SWD_GetU32)(int BitPos);
static void (*P_JLINKARM_SWD_GetData)(uint8_t *pDest, int BitPos, int NumBits);
static void (*P_JLINKARM_SWD_StoreRaw)(const uint8_t *pDir, const uint8_t *pin, uint32_t NumBits);
static void (*P_JLINKARM_SWD_StoreGetRaw)(const uint8_t *pDir, uint8_t *pIn, const uint8_t *pOut, uint32_t NumBits);
static void (*P_JLINKARM_SWD_SyncBits)(void);
static void (*P_JLINKARM_SWD_SyncBytes)(void);

int JLINK_SWD_Init() {
    // 文档中函数名前缀是JLINKARM，但DLL中是JLINK
    P_JLINKARM_SWD_GetU8 = JLinkDLL_getSym("JLINK_SWD_GetU8");
    if (P_JLINKARM_SWD_GetU8 == NULL) return 0;
    P_JLINKARM_SWD_GetU16 = JLinkDLL_getSym("JLINK_SWD_GetU16");
    if (P_JLINKARM_SWD_GetU16 == NULL) return 0;
    P_JLINKARM_SWD_GetU32 = JLinkDLL_getSym("JLINK_SWD_GetU32");
    if (P_JLINKARM_SWD_GetU32 == NULL) return 0;
    P_JLINKARM_SWD_GetData = JLinkDLL_getSym("JLINK_SWD_GetData");
    if (P_JLINKARM_SWD_GetData == NULL) return 0;
    P_JLINKARM_SWD_StoreRaw = JLinkDLL_getSym("JLINK_SWD_StoreRaw");
    if (P_JLINKARM_SWD_StoreRaw == NULL) return 0;
    P_JLINKARM_SWD_StoreGetRaw = JLinkDLL_getSym("JLINK_SWD_StoreGetRaw");
    if (P_JLINKARM_SWD_StoreGetRaw == NULL) return 0;
    P_JLINKARM_SWD_SyncBits = JLinkDLL_getSym("JLINK_SWD_SyncBits");
    if (P_JLINKARM_SWD_SyncBits == NULL) return 0;
    P_JLINKARM_SWD_SyncBytes = JLinkDLL_getSym("JLINK_SWD_SyncBytes");
    if (P_JLINKARM_SWD_SyncBytes == NULL) return 0;
    return 1;
}

uint32_t JLINKARM_SWD_GetU8(int BitPos) {
    return P_JLINKARM_SWD_GetU8(BitPos);
}

uint32_t JLINKARM_SWD_GetU16(int BitPos) {
    return P_JLINKARM_SWD_GetU16(BitPos);
}

uint32_t JLINKARM_SWD_GetU32(int BitPos) {
    return P_JLINKARM_SWD_GetU32(BitPos);
}

void JLINKARM_SWD_GetData(uint8_t *pDest, int BitPos, int NumBits) {
    P_JLINKARM_SWD_GetData(pDest, BitPos, NumBits);
}

void JLINKARM_SWD_StoreRaw(const uint8_t *pDir, const uint8_t *pin, uint32_t NumBits) {
    P_JLINKARM_SWD_StoreRaw(pDir, pin, NumBits);
}

void JLINKARM_SWD_StoreGetRaw(const uint8_t *pDir, uint8_t *pIn, const uint8_t *pOut, uint32_t NumBits) {
    P_JLINKARM_SWD_StoreGetRaw(pDir, pIn, pOut, NumBits);
}

void JLINKARM_SWD_SyncBits(void) {
    P_JLINKARM_SWD_SyncBits();
}

void JLINKARM_SWD_SyncBytes(void) {
    P_JLINKARM_SWD_SyncBytes();
}
