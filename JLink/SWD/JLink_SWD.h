/**
 * @file JLink_SWD.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_SWD_H
#define JLINKDLL_JLINK_SWD_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t JLINKARM_SWD_GetU8(int BitPos);
uint32_t JLINKARM_SWD_GetU16(int BitPos);
uint32_t JLINKARM_SWD_GetU32(int BitPos);
void JLINKARM_SWD_GetData(uint8_t * pDest, int BitPos, int NumBits);
void JLINKARM_SWD_StoreRaw(const uint8_t* pDir, const uint8_t* pin, uint32_t NumBits);
void JLINKARM_SWD_StoreGetRaw(const uint8_t* pDir, uint8_t* pIn, const uint8_t* pOut, uint32_t NumBits);
void JLINKARM_SWD_SyncBits(void);
void JLINKARM_SWD_SyncBytes(void);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_SWD_H
