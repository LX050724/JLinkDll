//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Memory.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINK_GetMemZones)(JLINK_MEM_ZONE_INFO *paZoneInfo, int MaxNumZones);
static int (*P_JLINKARM_ReadMem)(uint32_t Addr, uint32_t NumBytes, void *pData);
static int (*P_JLINKARM_ReadMemEx)(uint32_t Addr, uint32_t NumBytes, void *pData, uint32_t AccessWidth);
static int (*P_JLINKARM_ReadMemIndirect)(uint32_t Addr, uint32_t NumBytes, void *pData);
static int (*P_JLINKARM_ReadMemHW)(uint32_t Addr, uint32_t NumBytes, void *pData);
static int (*P_JLINKARM_ReadMemU8)(uint32_t Addr, uint32_t NumItems, uint8_t *pData, uint8_t *pStatus);
static int (*P_JLINKARM_ReadMemU16)(uint32_t Addr, uint32_t NumItems, uint16_t *pData, uint8_t *pStatus);
static int (*P_JLINKARM_ReadMemU32)(uint32_t Addr, uint32_t NumItems, uint32_t *pData, uint8_t *pStatus);
static int (*P_JLINKARM_ReadMemU64)(uint32_t Addr, uint32_t NumItems, uint64_t *pData, uint8_t *pStatus);
static int (*P_JLINK_ReadMemZonedEx)(uint32_t Addr, uint32_t NumBytes, void *pData, uint32_t AccessWidth,
                                     const char *sZone);
static int (*P_JLINKARM_WriteMem)(uint32_t Addr, uint32_t Count, const void *pData);
static int (*P_JLINKARM_WriteMemDelayed)(uint32_t Addr, uint32_t Count, const void *pData);
static int (*P_JLINKARM_WriteMemEx)(uint32_t Addr, uint32_t NumBytes, const void *p, uint32_t AccessWidth);
static int (*P_JLINK_WriteMemZonedEx)(uint32_t Addr, uint32_t NumBytes, const void *p, uint32_t AccessWidth,
                                      const char *sZone);
static int (*P_JLINKARM_WriteU8)(uint32_t Addr, uint8_t Data);
static int (*P_JLINKARM_WriteU16)(uint32_t Addr, uint16_t Data);
static int (*P_JLINKARM_WriteU32)(uint32_t Addr, uint32_t Data);
static int (*P_JLINKARM_WriteU64)(uint32_t Addr, uint64_t Data);

int JLINK_GERENAL_MEM_Init() {
    P_JLINK_GetMemZones = JLinkDLL_getSym("JLINK_GetMemZones");
    if (P_JLINK_GetMemZones == NULL) return 0;
    P_JLINKARM_ReadMem = JLinkDLL_getSym("JLINKARM_ReadMem");
    if (P_JLINKARM_ReadMem == NULL) return 0;
    P_JLINKARM_ReadMemEx = JLinkDLL_getSym("JLINKARM_ReadMemEx");
    if (P_JLINKARM_ReadMemEx == NULL) return 0;
    P_JLINKARM_ReadMemIndirect = JLinkDLL_getSym("JLINKARM_ReadMemIndirect");
    if (P_JLINKARM_ReadMemIndirect == NULL) return 0;
    P_JLINKARM_ReadMemHW = JLinkDLL_getSym("JLINKARM_ReadMemHW");
    if (P_JLINKARM_ReadMemHW == NULL) return 0;
    P_JLINKARM_ReadMemU8 = JLinkDLL_getSym("JLINKARM_ReadMemU8");
    if (P_JLINKARM_ReadMemU8 == NULL) return 0;
    P_JLINKARM_ReadMemU16 = JLinkDLL_getSym("JLINKARM_ReadMemU16");
    if (P_JLINKARM_ReadMemU16 == NULL) return 0;
    P_JLINKARM_ReadMemU32 = JLinkDLL_getSym("JLINKARM_ReadMemU32");
    if (P_JLINKARM_ReadMemU32 == NULL) return 0;
    P_JLINKARM_ReadMemU64 = JLinkDLL_getSym("JLINKARM_ReadMemU64");
    if (P_JLINKARM_ReadMemU64 == NULL) return 0;
    P_JLINK_ReadMemZonedEx = JLinkDLL_getSym("JLINK_ReadMemZonedEx");
    if (P_JLINK_ReadMemZonedEx == NULL) return 0;
    P_JLINKARM_WriteMem = JLinkDLL_getSym("JLINKARM_WriteMem");
    if (P_JLINKARM_WriteMem == NULL) return 0;
    P_JLINKARM_WriteMemDelayed = JLinkDLL_getSym("JLINKARM_WriteMemDelayed");
    if (P_JLINKARM_WriteMemDelayed == NULL) return 0;
    P_JLINKARM_WriteMemEx = JLinkDLL_getSym("JLINKARM_WriteMemEx");
    if (P_JLINKARM_WriteMemEx == NULL) return 0;
    P_JLINK_WriteMemZonedEx = JLinkDLL_getSym("JLINK_WriteMemZonedEx");
    if (P_JLINK_WriteMemZonedEx == NULL) return 0;
    P_JLINKARM_WriteU8 = JLinkDLL_getSym("JLINKARM_WriteU8");
    if (P_JLINKARM_WriteU8 == NULL) return 0;
    P_JLINKARM_WriteU16 = JLinkDLL_getSym("JLINKARM_WriteU16");
    if (P_JLINKARM_WriteU16 == NULL) return 0;
    P_JLINKARM_WriteU32 = JLinkDLL_getSym("JLINKARM_WriteU32");
    if (P_JLINKARM_WriteU32 == NULL) return 0;
    P_JLINKARM_WriteU64 = JLinkDLL_getSym("JLINKARM_WriteU64");
    if (P_JLINKARM_WriteU64 == NULL) return 0;
    return 1;
}

int JLINK_GetMemZones(JLINK_MEM_ZONE_INFO *paZoneInfo, int MaxNumZones) {
    return P_JLINK_GetMemZones(paZoneInfo, MaxNumZones);
}

int JLINKARM_ReadMem(uint32_t Addr, uint32_t NumBytes, void *pData) {
    return P_JLINKARM_ReadMem(Addr, NumBytes, pData);
}

int JLINKARM_ReadMemEx(uint32_t Addr, uint32_t NumBytes, void *pData, uint32_t AccessWidth) {
    return P_JLINKARM_ReadMemEx(Addr, NumBytes, pData, AccessWidth);
}

int JLINKARM_ReadMemIndirect(uint32_t Addr, uint32_t NumBytes, void *pData) {
    return P_JLINKARM_ReadMemIndirect(Addr, NumBytes, pData);
}

int JLINKARM_ReadMemHW(uint32_t Addr, uint32_t NumBytes, void *pData) {
    return P_JLINKARM_ReadMemHW(Addr, NumBytes, pData);
}

int JLINKARM_ReadMemU8(uint32_t Addr, uint32_t NumItems, uint8_t *pData, uint8_t *pStatus) {
    return P_JLINKARM_ReadMemU8(Addr, NumItems, pData, pStatus);
}

int JLINKARM_ReadMemU16(uint32_t Addr, uint32_t NumItems, uint16_t *pData, uint8_t *pStatus) {
    return P_JLINKARM_ReadMemU16(Addr, NumItems, pData, pStatus);
}

int JLINKARM_ReadMemU32(uint32_t Addr, uint32_t NumItems, uint32_t *pData, uint8_t *pStatus) {
    return P_JLINKARM_ReadMemU32(Addr, NumItems, pData, pStatus);
}

int JLINKARM_ReadMemU64(uint32_t Addr, uint32_t NumItems, uint64_t *pData, uint8_t *pStatus) {
    return P_JLINKARM_ReadMemU64(Addr, NumItems, pData, pStatus);
}

int JLINK_ReadMemZonedEx(uint32_t Addr, uint32_t NumBytes, void *pData, uint32_t AccessWidth, const char *sZone) {
    return P_JLINK_ReadMemZonedEx(Addr, NumBytes, pData, AccessWidth, sZone);
}

int JLINKARM_WriteMem(uint32_t Addr, uint32_t Count, const void *pData) {
    return P_JLINKARM_WriteMem(Addr, Count, pData);
}

int JLINKARM_WriteMemDelayed(uint32_t Addr, uint32_t Count, const void *pData) {
    return P_JLINKARM_WriteMemDelayed(Addr, Count, pData);
}

int JLINKARM_WriteMemEx(uint32_t Addr, uint32_t NumBytes, const void *p, uint32_t AccessWidth) {
    return P_JLINKARM_WriteMemEx(Addr, NumBytes, p, AccessWidth);
}

int JLINK_WriteMemZonedEx(uint32_t Addr, uint32_t NumBytes, const void *p, uint32_t AccessWidth, const char *sZone) {
    return P_JLINK_WriteMemZonedEx(Addr, NumBytes, p, AccessWidth, sZone);
}

int JLINKARM_WriteU8(uint32_t Addr, uint8_t Data) {
    return P_JLINKARM_WriteU8(Addr, Data);
}

int JLINKARM_WriteU16(uint32_t Addr, uint16_t Data) {
    return P_JLINKARM_WriteU16(Addr, Data);
}

int JLINKARM_WriteU32(uint32_t Addr, uint32_t Data) {
    return P_JLINKARM_WriteU32(Addr, Data);
}

int JLINKARM_WriteU64(uint32_t Addr, uint64_t Data) {
    return P_JLINKARM_WriteU64(Addr, Data);
}

