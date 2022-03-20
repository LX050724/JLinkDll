/**
 * @file JLink_Power.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_POWER_H
#define JLINKDLL_JLINK_POWER_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

int JLINK_POWERTRACE_Control(int Cmd, void *pIn, void *pOut);
int JLINK_POWERTRACE_Read(JLINK_POWERTRACE_DATA_ITEM *paData, uint32_t NumItems);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_POWER_H
