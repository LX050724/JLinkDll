/**
 * @file JLinkDLL_Init.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_INIT_H
#define JLINKDLL_JLINK_INIT_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

int JLinkDLL_Init(const char *dl_path);
void *JLinkDLL_getSym(const char *sym);
int JLinkDLL_DeInit();

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_INIT_H
