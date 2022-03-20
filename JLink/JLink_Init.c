//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Init.h"

#ifdef Linux
#define DL_OPEN(PATH) dlopen()
#define DL_SYM(HANDEL, NAME) dlsym
#define DL_HANDEL void *
#else
#include <windows.h>
#include <stdio.h>
#define DL_OPEN(PATH) LoadLibrary(PATH)
#define DL_FREE(HANDEL) FreeLibrary(HANDEL)
#define DL_SYM(HANDEL, NAME) GetProcAddress(HANDEL, NAME)
#define DL_HANDEL HINSTANCE
#endif

#ifndef JLINK_LIB_PATH
#if _WIN64
#define JLINK_LIB_PATH "JLink_x64.dll"
#else
#define JLINK_LIB_PATH "JLinkARM.dll"
#endif
#endif

#define INIT_MODULE(MODULE) \
int JLINK_##MODULE##_Init(); \
if (!JLINK_##MODULE##_Init()) return 0;

static DL_HANDEL handel;

void *JLinkDLL_getSym(const char *sym) {
    void *p = DL_SYM(handel, sym);
    if (p) {
        printf("Loaded '%s' at %p, Relative address %llX\n",
               sym, p, ((uint64_t) p - (uint64_t) handel));
    } else {
        printf("Error: load '%s' failed\n", sym);
    }
    return p;
}

int JLinkDLL_Init(const char *dl_path) {
    if (handel == NULL) {
        if (dl_path == NULL) {
            dl_path = JLINK_LIB_PATH;
        }
        handel = DL_OPEN(dl_path);
        if (handel == NULL) return 0;
//        printf("Loaded DLL '%s' at %p\n", dl_path, handel);
        INIT_MODULE(RTT)
        INIT_MODULE(General)
        INIT_MODULE(JTAG)
        INIT_MODULE(SWO)
    }
    return 1;
}

int JLinkDLL_DeInit() {
    return DL_FREE(handel);
}
