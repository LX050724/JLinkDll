//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Configuration.h"
#include "JLink/JLink_Init.h"

static void (*P_JLINKARM_ConfigJTAG)(int IRPre, int DRPre);
static int (*P_JLINK_EMU_AddLicense)(const char *sLicense);
static int (*P_JLINK_EMU_EraseLicenses)(void);
static int (*P_JLINK_EMU_GetLicenses)(char *pBuffer, uint32_t NumBytes);
static int (*P_JLINKARM_EMU_SelectByUSBSN)(uint32_t SerialNo);
static int (*P_JLINKARM_EMU_SelectIP)(char *pIPAddr, int BufferSize, uint16_t *pPort);
static void (*P_JLINKARM_EMU_SelectIPBySN)(uint32_t SerialNo);
static uint32_t (*P_JLINKARM_GetId)(void);
static char (*P_JLINKARM_SelectIP)(const char *sHost, int Port);
static char (*P_JLINKARM_SelectUSB)(int Port);
static int (*P_JLINK_SetHookUnsecureDialog)(JLINK_UNSECURE_DIALOG_CB_FUNC *pfHook);
static int (*P_JLINKARM_EMU_GetList)(int HostIFs, JLINKARM_EMU_CONNECT_INFO *paConnectInfo, int MaxInfos);

int JLINK_GERENAL_CONFIGURATION_Init() {
    P_JLINKARM_ConfigJTAG = JLinkDLL_getSym("JLINKARM_ConfigJTAG");
    if (P_JLINKARM_ConfigJTAG == NULL) return 0;
    P_JLINK_EMU_AddLicense = JLinkDLL_getSym("JLINK_EMU_AddLicense");
    if (P_JLINK_EMU_AddLicense == NULL) return 0;
    P_JLINK_EMU_EraseLicenses = JLinkDLL_getSym("JLINK_EMU_EraseLicenses");
    if (P_JLINK_EMU_EraseLicenses == NULL) return 0;
    P_JLINK_EMU_GetLicenses = JLinkDLL_getSym("JLINK_EMU_GetLicenses");
    if (P_JLINK_EMU_GetLicenses == NULL) return 0;
    P_JLINKARM_EMU_SelectByUSBSN = JLinkDLL_getSym("JLINKARM_EMU_SelectByUSBSN");
    if (P_JLINKARM_EMU_SelectByUSBSN == NULL) return 0;
    P_JLINKARM_EMU_SelectIP = JLinkDLL_getSym("JLINKARM_EMU_SelectIP");
    if (P_JLINKARM_EMU_SelectIP == NULL) return 0;
    P_JLINKARM_EMU_SelectIPBySN = JLinkDLL_getSym("JLINKARM_EMU_SelectIPBySN");
    if (P_JLINKARM_EMU_SelectIPBySN == NULL) return 0;
    P_JLINKARM_GetId = JLinkDLL_getSym("JLINKARM_GetId");
    if (P_JLINKARM_GetId == NULL) return 0;
    P_JLINKARM_SelectIP = JLinkDLL_getSym("JLINKARM_SelectIP");
    if (P_JLINKARM_SelectIP == NULL) return 0;
    P_JLINKARM_SelectUSB = JLinkDLL_getSym("JLINKARM_SelectUSB");
    if (P_JLINKARM_SelectUSB == NULL) return 0;
    P_JLINK_SetHookUnsecureDialog = JLinkDLL_getSym("JLINK_SetHookUnsecureDialog");
    if (P_JLINK_SetHookUnsecureDialog == NULL) return 0;
    P_JLINKARM_EMU_GetList = JLinkDLL_getSym("JLINKARM_EMU_GetList");
    if (P_JLINKARM_EMU_GetList == NULL) return 0;
    return 1;
}

void JLINKARM_ConfigJTAG(int IRPre, int DRPre) {
    P_JLINKARM_ConfigJTAG(IRPre, DRPre);
}

int JLINK_EMU_AddLicense(const char *sLicense) {
    return P_JLINK_EMU_AddLicense(sLicense);
}

int JLINK_EMU_EraseLicenses(void) {
    return P_JLINK_EMU_EraseLicenses();
}

int JLINK_EMU_GetLicenses(char *pBuffer, uint32_t NumBytes) {
    return P_JLINK_EMU_GetLicenses(pBuffer, NumBytes);
}

int JLINKARM_EMU_SelectByUSBSN(uint32_t SerialNo) {
    return P_JLINKARM_EMU_SelectByUSBSN(SerialNo);
}

int JLINKARM_EMU_SelectIP(char *pIPAddr, int BufferSize, uint16_t *pPort) {
    return P_JLINKARM_EMU_SelectIP(pIPAddr, BufferSize, pPort);
}

void JLINKARM_EMU_SelectIPBySN(uint32_t SerialNo) {
    P_JLINKARM_EMU_SelectIPBySN(SerialNo);
}

uint32_t JLINKARM_GetId(void) {
    return P_JLINKARM_GetId();
}

char JLINKARM_SelectIP(const char *sHost, int Port) {
    return P_JLINKARM_SelectIP(sHost, Port);
}

char JLINKARM_SelectUSB(int Port) {
    return P_JLINKARM_SelectUSB(Port);
}

int JLINK_SetHookUnsecureDialog(JLINK_UNSECURE_DIALOG_CB_FUNC *pfHook) {
    return P_JLINK_SetHookUnsecureDialog(pfHook);
}

int JLINKARM_EMU_GetList(int HostIFs, JLINKARM_EMU_CONNECT_INFO *paConnectInfo, int MaxInfos) {
    return P_JLINKARM_EMU_GetList(HostIFs, paConnectInfo, MaxInfos);
}
