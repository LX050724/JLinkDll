/**
 * @file JLink_STRACE.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_STRACE_H
#define JLINKDLL_JLINK_STRACE_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * @param sConfig
 * @return
 */
int JLINK_STRACE_Config(const char* sConfig);

/**
 * @see JLINK_STRACE_CMD
 * @param Cmd
 * @param pData
 * @return
 */
int JLINK_STRACE_Control(uint32_t Cmd, void* pData);
int JLINK_STRACE_GetInstStats(void* paItem, uint32_t Addr, uint32_t NumItems, uint32_t SizeOfStruct, uint32_t Type);
int JLINK_STRACE_Read(uint32_t* paItem, uint32_t NumItems);
int JLINK_STRACE_Start(void);
int JLINK_STRACE_Stop(void);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_STRACE_H
