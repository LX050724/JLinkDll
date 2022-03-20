/**
 * @file JLink_HSS.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_HSS_H
#define JLINKDLL_JLINK_HSS_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

int JLINK_HSS_Start(JLINK_HSS_MEM_BLOCK_DESC *paDesc, int NumBlocks, int Period_us, int Flags);
int JLINK_HSS_Stop(void);
int JLINK_HSS_Read(void *pBuffer, uint32_t BufferSize);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_HSS_H
