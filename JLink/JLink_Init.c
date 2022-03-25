//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Init.h"

#ifdef Linux
#define DL_OPEN(PATH) dlopen()
#define DL_SYM(HANDEL, NAME) dlsym
#define DL_HANDEL void *
//#ifndef JLINK_LIB_PATH
//#if _WIN64
//#define JLINK_LIB_PATH "JLink_x64.dll"
//#else
//#define JLINK_LIB_PATH "JLinkARM.dll"
//#endif
//#endif
#else
#include <windows.h>
#include <stdio.h>
#define DL_OPEN(PATH) LoadLibrary(PATH)
#define DL_FREE(HANDEL) FreeLibrary(HANDEL)
#define DL_SYM(HANDEL, NAME) GetProcAddress(HANDEL, NAME)
#define DL_HANDEL HINSTANCE
#ifndef JLINK_LIB_PATH
#if _WIN64
#define JLINK_LIB_PATH "JLink_x64.dll"
#else
#define JLINK_LIB_PATH "JLinkARM.dll"
#endif
#endif
#endif


#define INIT_MODULE(MODULE) \
int JLINK_##MODULE##_Init(); \
if (!JLINK_##MODULE##_Init()) return 0;

static DL_HANDEL handel;
static uint32_t fun_num;
static int dbgOut_enable;

void *JLinkDLL_getSym(const char *sym) {
    void *p = DL_SYM(handel, sym);
    if (p) {
        fun_num++;
        if (dbgOut_enable) {
            printf("Loaded '%s' at %p, Relative address %llX\n",
                   sym, p, ((uint64_t) p - (uint64_t) handel));
        }
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
        if (dbgOut_enable) {
            printf("Loaded DLL '%s' at %p\n", dl_path, handel);
        }
        INIT_MODULE(RTT)
        INIT_MODULE(General)
        INIT_MODULE(JTAG)
        INIT_MODULE(SWO)
        INIT_MODULE(HSS)
        INIT_MODULE(SPI)
        INIT_MODULE(STRACE)
        INIT_MODULE(POWERTRACE)
        INIT_MODULE(SWD)
    }
    if (dbgOut_enable) {
        printf("%d functions are loaded\n", fun_num);
    }
    return 1;
}

int JLinkDLL_DeInit() {
    if (handel) {
        int ret = DL_FREE(handel);
        handel = NULL;
        return ret;
    }
    return 1;
}

int JLinkDLL_Error(const char *fun_name, const char *filename, int line) {
    fprintf(stderr, "Error: function %s, in %s:%d\n", fun_name, filename, line);
    JLinkDLL_DeInit();
    exit(EXIT_FAILURE);
    return 0;
}

void JLinkDLL_SetDebugOutput(int enable) {
    dbgOut_enable = enable;
}
