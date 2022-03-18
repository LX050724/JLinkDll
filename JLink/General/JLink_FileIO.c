//
// Created by yaoji on 2022/3/18.
//

#include "JLink_FileIO.h"
#include "JLink/JLink_Init.h"

int (*P_JLINKARM_EMU_FILE_Delete)(const char *sFile);
int (*P_JLINKARM_EMU_FILE_GetSize)(const char *sFile);
int (*P_JLINKARM_EMU_FILE_Read)(const char *sFile, uint8_t *pData, uint32_t Offset, uint32_t NumBytes);
int (*P_JLINKARM_EMU_FILE_Write)(const char *sFile, const uint8_t *pData, uint32_t Offset, uint32_t NumBytes);

int JLINK_GERENAL_FILE_IO_Init() {
    P_JLINKARM_EMU_FILE_Delete = JLinkDLL_getSym("JLINKARM_EMU_FILE_Delete");
    if (P_JLINKARM_EMU_FILE_Delete == NULL) return 0;
    P_JLINKARM_EMU_FILE_GetSize = JLinkDLL_getSym("JLINKARM_EMU_FILE_GetSize");
    if (P_JLINKARM_EMU_FILE_GetSize == NULL) return 0;
    P_JLINKARM_EMU_FILE_Read = JLinkDLL_getSym("JLINKARM_EMU_FILE_Read");
    if (P_JLINKARM_EMU_FILE_Read == NULL) return 0;
    P_JLINKARM_EMU_FILE_Write = JLinkDLL_getSym("JLINKARM_EMU_FILE_Write");
    if (P_JLINKARM_EMU_FILE_Write == NULL) return 0;
    return 1;
}

int JLINKARM_EMU_FILE_Delete(const char *sFile) {
    return P_JLINKARM_EMU_FILE_Delete(sFile);
}

int JLINKARM_EMU_FILE_GetSize(const char *sFile) {
    return P_JLINKARM_EMU_FILE_GetSize(sFile);
}

int JLINKARM_EMU_FILE_Read(const char *sFile, uint8_t *pData, uint32_t Offset, uint32_t NumBytes) {
    return P_JLINKARM_EMU_FILE_Read(sFile, pData, Offset, NumBytes);
}

int JLINKARM_EMU_FILE_Write(const char *sFile, const uint8_t *pData, uint32_t Offset, uint32_t NumBytes) {
    return P_JLINKARM_EMU_FILE_Write(sFile, pData, Offset, NumBytes);
}
