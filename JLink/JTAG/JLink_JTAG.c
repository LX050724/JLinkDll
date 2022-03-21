//
// Created by yaoji on 2022/3/20.
//

#include "JLink_JTAG.h"
#include <JLink/JLink_Init.h>

static void (*P_JLINK_JTAG_ConfigDevices)(uint32_t NumDevices, const JLINKARM_JTAG_DEVICE_CONF *paConf);
static uint32_t (*P_JLINKARM_JTAG_GetDeviceId)(unsigned DeviceIndex);
static int (*P_JLINKARM_JTAG_GetDeviceInfo)(unsigned DeviceIndex, JLINKARM_JTAG_DEVICE_INFO *pDeviceInfo);
static uint32_t (*P_JLINKARM_JTAG_GetU8)(int BitPos);
static uint32_t (*P_JLINKARM_JTAG_GetU16)(int BitPos);
static uint32_t (*P_JLINKARM_JTAG_GetU32)(int BitPos);
static void (*P_JLINKARM_JTAG_GetData)(uint8_t *pDest, int BitPos, int NumBits);
static int (*P_JLINKARM_JTAG_StoreData)(const uint8_t *pTDI, int NumBits);
static void (*P_JLINKARM_JTAG_StoreInst)(const uint8_t *pTDI, int IRLen);
static int (*P_JLINKARM_JTAG_StoreRaw)(const uint8_t *pTDI, const uint8_t *pTMS, uint32_t NumBits);
static void (*P_JLINKARM_JTAG_StoreGetData)(const uint8_t *pTDI, uint8_t *pTDO, int NumBits);
static void (*P_JLINKARM_JTAG_StoreGetRaw)(const uint8_t *pTDI, uint8_t *pTDO, const uint8_t *pTMS, uint32_t NumBits);
static void (*P_JLINKARM_JTAG_SyncBits)(void);
static void (*P_JLINKARM_JTAG_SyncBytes)(void);

int JLINK_JTAG_Init() {
    P_JLINK_JTAG_ConfigDevices = JLinkDLL_getSym("JLINK_JTAG_ConfigDevices");
    if (P_JLINK_JTAG_ConfigDevices == NULL) return 0;
    P_JLINKARM_JTAG_GetDeviceId = JLinkDLL_getSym("JLINKARM_JTAG_GetDeviceId");
    if (P_JLINKARM_JTAG_GetDeviceId == NULL) return 0;
    P_JLINKARM_JTAG_GetDeviceInfo = JLinkDLL_getSym("JLINKARM_JTAG_GetDeviceInfo");
    if (P_JLINKARM_JTAG_GetDeviceInfo == NULL) return 0;
    P_JLINKARM_JTAG_GetU8 = JLinkDLL_getSym("JLINKARM_JTAG_GetU8");
    if (P_JLINKARM_JTAG_GetU8 == NULL) return 0;
    P_JLINKARM_JTAG_GetU16 = JLinkDLL_getSym("JLINKARM_JTAG_GetU16");
    if (P_JLINKARM_JTAG_GetU16 == NULL) return 0;
    P_JLINKARM_JTAG_GetU32 = JLinkDLL_getSym("JLINKARM_JTAG_GetU32");
    if (P_JLINKARM_JTAG_GetU32 == NULL) return 0;
    P_JLINKARM_JTAG_GetData = JLinkDLL_getSym("JLINKARM_JTAG_GetData");
    if (P_JLINKARM_JTAG_GetData == NULL) return 0;
    P_JLINKARM_JTAG_StoreData = JLinkDLL_getSym("JLINKARM_JTAG_StoreData");
    if (P_JLINKARM_JTAG_StoreData == NULL) return 0;
    P_JLINKARM_JTAG_StoreInst = JLinkDLL_getSym("JLINKARM_JTAG_StoreInst");
    if (P_JLINKARM_JTAG_StoreInst == NULL) return 0;
    P_JLINKARM_JTAG_StoreRaw = JLinkDLL_getSym("JLINKARM_JTAG_StoreRaw");
    if (P_JLINKARM_JTAG_StoreRaw == NULL) return 0;
    P_JLINKARM_JTAG_StoreGetData = JLinkDLL_getSym("JLINKARM_JTAG_StoreGetData");
    if (P_JLINKARM_JTAG_StoreGetData == NULL) return 0;
    P_JLINKARM_JTAG_StoreGetRaw = JLinkDLL_getSym("JLINKARM_JTAG_StoreGetRaw");
    if (P_JLINKARM_JTAG_StoreGetRaw == NULL) return 0;
    P_JLINKARM_JTAG_SyncBits = JLinkDLL_getSym("JLINKARM_JTAG_SyncBits");
    if (P_JLINKARM_JTAG_SyncBits == NULL) return 0;
    P_JLINKARM_JTAG_SyncBytes = JLinkDLL_getSym("JLINKARM_JTAG_SyncBytes");
    if (P_JLINKARM_JTAG_SyncBytes == NULL) return 0;
    return 1;
}
//PYTHON CHECK POINT
void JLINK_JTAG_ConfigDevices(uint32_t NumDevices, const JLINKARM_JTAG_DEVICE_CONF *paConf) {
    JLinkDLL_CALLPTR(P_JLINK_JTAG_ConfigDevices, NumDevices, paConf);
}

uint32_t JLINKARM_JTAG_GetDeviceId(unsigned DeviceIndex) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_GetDeviceId, DeviceIndex);
}

int JLINKARM_JTAG_GetDeviceInfo(unsigned DeviceIndex, JLINKARM_JTAG_DEVICE_INFO *pDeviceInfo) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_GetDeviceInfo, DeviceIndex, pDeviceInfo);
}

uint32_t JLINKARM_JTAG_GetU8(int BitPos) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_GetU8, BitPos);
}

uint32_t JLINKARM_JTAG_GetU16(int BitPos) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_GetU16, BitPos);
}

uint32_t JLINKARM_JTAG_GetU32(int BitPos) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_GetU32, BitPos);
}

void JLINKARM_JTAG_GetData(uint8_t *pDest, int BitPos, int NumBits) {
    JLinkDLL_CALLPTR(P_JLINKARM_JTAG_GetData, pDest, BitPos, NumBits);
}

int JLINKARM_JTAG_StoreData(const uint8_t *pTDI, int NumBits) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_StoreData, pTDI, NumBits);
}

void JLINKARM_JTAG_StoreInst(const uint8_t *pTDI, int IRLen) {
    JLinkDLL_CALLPTR(P_JLINKARM_JTAG_StoreInst, pTDI, IRLen);
}

int JLINKARM_JTAG_StoreRaw(const uint8_t *pTDI, const uint8_t *pTMS, uint32_t NumBits) {
    return JLinkDLL_CALLPTR(P_JLINKARM_JTAG_StoreRaw, pTDI, pTMS, NumBits);
}

void JLINKARM_JTAG_StoreGetData(const uint8_t *pTDI, uint8_t *pTDO, int NumBits) {
    JLinkDLL_CALLPTR(P_JLINKARM_JTAG_StoreGetData, pTDI, pTDO, NumBits);
}

void JLINKARM_JTAG_StoreGetRaw(const uint8_t *pTDI, uint8_t *pTDO, const uint8_t *pTMS, uint32_t NumBits) {
    JLinkDLL_CALLPTR(P_JLINKARM_JTAG_StoreGetRaw, pTDI, pTDO, pTMS, NumBits);
}

void JLINKARM_JTAG_SyncBits(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_JTAG_SyncBits);
}

void JLINKARM_JTAG_SyncBytes(void) {
    JLinkDLL_CALLPTR(P_JLINKARM_JTAG_SyncBytes);
}
//PYTHON CHECK POINT
