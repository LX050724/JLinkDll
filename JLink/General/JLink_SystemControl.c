//
// Created by yaoji on 2022/3/18.
//

#include "JLink_SystemControl.h"
#include "JLink/JLink_Init.h"

static uint32_t (*P_JLINKARM_GetDLLVersion)();
static void (*P_JLINKARM_ClrRESET)(void);
static int (*P_JLINKARM_ClrTCK)(void);
static void (*P_JLINKARM_ClrTDI)(void);
static void (*P_JLINKARM_ClrTMS)(void);
static void (*P_JLINKARM_ClrTRST)(void);
static void (*P_JLINKARM_ClrError)(void);

static void (*P_JLINKARM_BeginDownload)(uint32_t Flags);
static uint8_t (*P_JLINKARM_Clock)(void);
static int (*P_JLINKARM_CORESIGHT_Configure)(const char *sConfig);
static int (*P_JLINKARM_CORESIGHT_ReadAPDPReg)(uint8_t RegIndex, uint8_t APnDP, uint32_t *pData);
static int (*P_JLINKARM_CORESIGHT_WriteAPDPReg)(uint8_t RegIndex, uint8_t APnDP, uint32_t Data);
static void (*P_JLINKARM_Core2CoreName)(uint32_t Core, char *pBuffer, unsigned BufferSize);
static int (*P_JLINKARM_CP15_ReadEx)(uint8_t CRn, uint8_t CRm, uint8_t op1, uint8_t op2, uint32_t *pData);
static int (*P_JLINKARM_CP15_WriteEx)(uint8_t CRn, uint8_t CRm, uint8_t op1, uint8_t op2, uint32_t Data);
static int (*P_JLINKARM_DEVICE_GetIndex)(const char *sDeviceName);
static int (*P_JLINKARM_DEVICE_SelectDialog)(void *hParent, uint32_t Flags, JLINKARM_DEVICE_SELECT_INFO *pInfo);
static int (*P_JLINK_DownloadFile)(const char *sFileName, uint32_t Addr);
static int (*P_JLINKARM_EMU_COM_Read)(unsigned Channel, unsigned NumBytes, void *pData);
static int (*P_JLINKARM_EMU_COM_Write)(unsigned Channel, unsigned NumBytes, const void *pData);
static int (*P_JLINKARM_EMU_COM_IsSupported)(void);
static void (*P_JLINKARM_EMU_GetProductName)(char *pBuffer, uint32_t BufferSize);
static int (*P_JLINKARM_EMU_HasCapEx)(int CapEx);
static int (*P_JLINKARM_EMU_HasCPUCap)(uint32_t CPUCap);
static char (*P_JLINKARM_EMU_IsConnected)(void);
static void (*P_JLINKARM_EnableLog)(JLINKARM_LOG *pfLog);
static void (*P_JLINKARM_EnableLogCom)(JLINKARM_LOG *pfLog);
static int (*P_JLINKARM_EndDownload)(void);
static int (*P_JLINK_EraseChip)(void);
static const char *(*P_JLINKARM_GetCompileDateTime)(void);
static void (*P_JLINKARM_GetConfigData)(int *pIRPre, int *pDRPre);
static int (*P_JLINKARM_GetDebugInfo)(uint32_t Index, uint32_t *pInfo);
static int (*P_JLINKARM_GetDeviceFamily)(void);
static uint32_t (*P_JLINKARM_GetEmuCaps)(void);
static void (*P_JLINKARM_GetEmuCapsEx)(uint8_t *pCaps, int BufferSize);
static void (*P_JLINKARM_GetFeatureString)(char *pOut);
static void (*P_JLINKARM_GetFirmwareString)(char *s, int BufferSize);
static int (*P_JLINKARM_GetHWInfo)(uint32_t BitMask, uint32_t *pHWInfo);
static int (*P_JLINKARM_GetHWStatus)(JLINKARM_HW_STATUS *pStat);
static int (*P_JLINKARM_GetHardwareVersion)(void);
static void (*P_JLINKARM_GetIdData)(JTAG_ID_DATA *pIdData);
static int (*P_JLINKARM_GetMOEs)(JLINKARM_MOE_INFO *pInfo, int MaxNumMOEs);
static char (*P_JLINKARM_GetOEMString)(char *pOut);
static int (*P_JLINKARM_GetScanLen)(void);
static uint16_t (*P_JLINKARM_GetSelDevice)(void);
static int (*P_JLINKARM_GetSN)(void);
static uint16_t (*P_JLINKARM_GetSpeed)(void);
static void (*P_JLINKARM_GetSpeedInfo)(JLINKARM_SPEED_INFO *pSpeedInfo);
static char (*P_JLINKARM_HasError)(void);
static int (*P_JLINKARM_MeasureCPUSpeed)(uint32_t RAMAddr, int PreserveMem);
static int (*P_JLINKARM_MeasureCPUSpeedEx)(uint32_t RAMAddr, int PreserveMem, int AllowFail);
static int (*P_JLINKARM_MeasureSCLen)(int ScanChain);
static void (*P_JLINKARM_SelDevice)(uint16_t DeviceIndex);
static void (*P_JLINKARM_SelectTraceSource)(int Source);
static int (*P_JLINKARM_SetEndian)(int v);
static void (*P_JLINKARM_SetErrorOutHandler)(JLINKARM_LOG *pfErrorOut);
static void (*P_JLINKARM_SetLogFile)(const char *sFilename);
static void (*P_JLINKARM_SetMaxSpeed)(void);
static void (*P_JLINKARM_SetRESET)(void);
static void (*P_JLINKARM_SetSpeed)(uint32_t Speed);
static int (*P_JLINKARM_SetTCK)(void);
static void (*P_JLINKARM_SetTDI)(void);
static void (*P_JLINKARM_SetTMS)(void);
static void (*P_JLINKARM_SetTRST)(void);
static void (*P_JLINKARM_StoreBits)(uint32_t TMS, uint32_t TDI, int NumBits);
static void (*P_JLINKARM_TIF_GetAvailable)(uint32_t *pMask);
static int (*P_JLINKARM_TIF_Select)(int Interface);
static uint32_t (*P_JLINKARM_UpdateFirmwareIfNewer)(void);
static void (*P_JLINKARM_SetWarnOutHandler)(JLINKARM_LOG *pfWarnOut);
static void (*P_JLINKARM_WriteBits)(void);
static uint32_t (*P_JLINKARM_EMU_GetNumDevices)(void);

//static void (*P_JLINKARM_EMU_GetDeviceInfo)(uint32_t iEmu, JLINKARM_EMU_INFO *pInfo);

int JLINK_GERENAL_SystemControl_Init() {
    P_JLINKARM_GetDLLVersion = JLinkDLL_getSym("JLINKARM_GetDLLVersion");
    if (P_JLINKARM_GetDLLVersion == NULL) return 0;
    P_JLINKARM_ClrRESET = JLinkDLL_getSym("JLINKARM_ClrRESET");
    if (P_JLINKARM_ClrRESET == NULL) return 0;
    P_JLINKARM_ClrTCK = JLinkDLL_getSym("JLINKARM_ClrTCK");
    if (P_JLINKARM_ClrTCK == NULL) return 0;
    P_JLINKARM_ClrTDI = JLinkDLL_getSym("JLINKARM_ClrTDI");
    if (P_JLINKARM_ClrTDI == NULL) return 0;
    P_JLINKARM_ClrTMS = JLinkDLL_getSym("JLINKARM_ClrTMS");
    if (P_JLINKARM_ClrTMS == NULL) return 0;
    P_JLINKARM_ClrTRST = JLinkDLL_getSym("JLINKARM_ClrTRST");
    if (P_JLINKARM_ClrTRST == NULL) return 0;
    P_JLINKARM_ClrError = JLinkDLL_getSym("JLINKARM_ClrError");
    if (P_JLINKARM_ClrError == NULL) return 0;
    P_JLINKARM_BeginDownload = JLinkDLL_getSym("JLINKARM_BeginDownload");
    if (P_JLINKARM_BeginDownload == NULL) return 0;
    P_JLINKARM_Clock = JLinkDLL_getSym("JLINKARM_Clock");
    if (P_JLINKARM_Clock == NULL) return 0;
    P_JLINKARM_CORESIGHT_Configure = JLinkDLL_getSym("JLINKARM_CORESIGHT_Configure");
    if (P_JLINKARM_CORESIGHT_Configure == NULL) return 0;
    P_JLINKARM_CORESIGHT_ReadAPDPReg = JLinkDLL_getSym("JLINKARM_CORESIGHT_ReadAPDPReg");
    if (P_JLINKARM_CORESIGHT_ReadAPDPReg == NULL) return 0;
    P_JLINKARM_CORESIGHT_WriteAPDPReg = JLinkDLL_getSym("JLINKARM_CORESIGHT_WriteAPDPReg");
    if (P_JLINKARM_CORESIGHT_WriteAPDPReg == NULL) return 0;
    P_JLINKARM_Core2CoreName = JLinkDLL_getSym("JLINKARM_Core2CoreName");
    if (P_JLINKARM_Core2CoreName == NULL) return 0;
    P_JLINKARM_CP15_ReadEx = JLinkDLL_getSym("JLINKARM_CP15_ReadEx");
    if (P_JLINKARM_CP15_ReadEx == NULL) return 0;
    P_JLINKARM_CP15_WriteEx = JLinkDLL_getSym("JLINKARM_CP15_WriteEx");
    if (P_JLINKARM_CP15_WriteEx == NULL) return 0;
    P_JLINKARM_DEVICE_GetIndex = JLinkDLL_getSym("JLINKARM_DEVICE_GetIndex");
    if (P_JLINKARM_DEVICE_GetIndex == NULL) return 0;
    P_JLINKARM_DEVICE_SelectDialog = JLinkDLL_getSym("JLINKARM_DEVICE_SelectDialog");
    if (P_JLINKARM_DEVICE_SelectDialog == NULL) return 0;
    P_JLINK_DownloadFile = JLinkDLL_getSym("JLINK_DownloadFile");
    if (P_JLINK_DownloadFile == NULL) return 0;
    P_JLINKARM_EMU_COM_Read = JLinkDLL_getSym("JLINKARM_EMU_COM_Read");
    if (P_JLINKARM_EMU_COM_Read == NULL) return 0;
    P_JLINKARM_EMU_COM_Write = JLinkDLL_getSym("JLINKARM_EMU_COM_Write");
    if (P_JLINKARM_EMU_COM_Write == NULL) return 0;
    P_JLINKARM_EMU_COM_IsSupported = JLinkDLL_getSym("JLINKARM_EMU_COM_IsSupported");
    if (P_JLINKARM_EMU_COM_IsSupported == NULL) return 0;
    P_JLINKARM_EMU_GetProductName = JLinkDLL_getSym("JLINKARM_EMU_GetProductName");
    if (P_JLINKARM_EMU_GetProductName == NULL) return 0;
    P_JLINKARM_EMU_HasCapEx = JLinkDLL_getSym("JLINKARM_EMU_HasCapEx");
    if (P_JLINKARM_EMU_HasCapEx == NULL) return 0;
    P_JLINKARM_EMU_HasCPUCap = JLinkDLL_getSym("JLINKARM_EMU_HasCPUCap");
    if (P_JLINKARM_EMU_HasCPUCap == NULL) return 0;
    P_JLINKARM_EMU_IsConnected = JLinkDLL_getSym("JLINKARM_EMU_IsConnected");
    if (P_JLINKARM_EMU_IsConnected == NULL) return 0;
    P_JLINKARM_EnableLog = JLinkDLL_getSym("JLINKARM_EnableLog");
    if (P_JLINKARM_EnableLog == NULL) return 0;
    P_JLINKARM_EnableLogCom = JLinkDLL_getSym("JLINKARM_EnableLogCom");
    if (P_JLINKARM_EnableLogCom == NULL) return 0;
    P_JLINKARM_EndDownload = JLinkDLL_getSym("JLINKARM_EndDownload");
    if (P_JLINKARM_EndDownload == NULL) return 0;
    P_JLINK_EraseChip = JLinkDLL_getSym("JLINK_EraseChip");
    if (P_JLINK_EraseChip == NULL) return 0;
    P_JLINKARM_GetCompileDateTime = JLinkDLL_getSym("JLINKARM_GetCompileDateTime");
    if (P_JLINKARM_GetCompileDateTime == NULL) return 0;
    P_JLINKARM_GetConfigData = JLinkDLL_getSym("JLINKARM_GetConfigData");
    if (P_JLINKARM_GetConfigData == NULL) return 0;
    P_JLINKARM_GetDebugInfo = JLinkDLL_getSym("JLINKARM_GetDebugInfo");
    if (P_JLINKARM_GetDebugInfo == NULL) return 0;
    P_JLINKARM_GetDeviceFamily = JLinkDLL_getSym("JLINKARM_GetDeviceFamily");
    if (P_JLINKARM_GetDeviceFamily == NULL) return 0;
    P_JLINKARM_GetEmuCaps = JLinkDLL_getSym("JLINKARM_GetEmuCaps");
    if (P_JLINKARM_GetEmuCaps == NULL) return 0;
    P_JLINKARM_GetEmuCapsEx = JLinkDLL_getSym("JLINKARM_GetEmuCapsEx");
    if (P_JLINKARM_GetEmuCapsEx == NULL) return 0;
    P_JLINKARM_GetFeatureString = JLinkDLL_getSym("JLINKARM_GetFeatureString");
    if (P_JLINKARM_GetFeatureString == NULL) return 0;
    P_JLINKARM_GetFirmwareString = JLinkDLL_getSym("JLINKARM_GetFirmwareString");
    if (P_JLINKARM_GetFirmwareString == NULL) return 0;
    P_JLINKARM_GetHWInfo = JLinkDLL_getSym("JLINKARM_GetHWInfo");
    if (P_JLINKARM_GetHWInfo == NULL) return 0;
    P_JLINKARM_GetHWStatus = JLinkDLL_getSym("JLINKARM_GetHWStatus");
    if (P_JLINKARM_GetHWStatus == NULL) return 0;
    P_JLINKARM_GetHardwareVersion = JLinkDLL_getSym("JLINKARM_GetHardwareVersion");
    if (P_JLINKARM_GetHardwareVersion == NULL) return 0;
    P_JLINKARM_GetIdData = JLinkDLL_getSym("JLINKARM_GetIdData");
    if (P_JLINKARM_GetIdData == NULL) return 0;
    P_JLINKARM_GetMOEs = JLinkDLL_getSym("JLINKARM_GetMOEs");
    if (P_JLINKARM_GetMOEs == NULL) return 0;
    P_JLINKARM_GetOEMString = JLinkDLL_getSym("JLINKARM_GetOEMString");
    if (P_JLINKARM_GetOEMString == NULL) return 0;
    P_JLINKARM_GetScanLen = JLinkDLL_getSym("JLINKARM_GetScanLen");
    if (P_JLINKARM_GetScanLen == NULL) return 0;
    P_JLINKARM_GetSelDevice = JLinkDLL_getSym("JLINKARM_GetSelDevice");
    if (P_JLINKARM_GetSelDevice == NULL) return 0;
    P_JLINKARM_GetSN = JLinkDLL_getSym("JLINKARM_GetSN");
    if (P_JLINKARM_GetSN == NULL) return 0;
    P_JLINKARM_GetSpeed = JLinkDLL_getSym("JLINKARM_GetSpeed");
    if (P_JLINKARM_GetSpeed == NULL) return 0;
    P_JLINKARM_GetSpeedInfo = JLinkDLL_getSym("JLINKARM_GetSpeedInfo");
    if (P_JLINKARM_GetSpeedInfo == NULL) return 0;
    P_JLINKARM_HasError = JLinkDLL_getSym("JLINKARM_HasError");
    if (P_JLINKARM_HasError == NULL) return 0;
    P_JLINKARM_MeasureCPUSpeed = JLinkDLL_getSym("JLINKARM_MeasureCPUSpeed");
    if (P_JLINKARM_MeasureCPUSpeed == NULL) return 0;
    P_JLINKARM_MeasureCPUSpeedEx = JLinkDLL_getSym("JLINKARM_MeasureCPUSpeedEx");
    if (P_JLINKARM_MeasureCPUSpeedEx == NULL) return 0;
    P_JLINKARM_MeasureSCLen = JLinkDLL_getSym("JLINKARM_MeasureSCLen");
    if (P_JLINKARM_MeasureSCLen == NULL) return 0;
    P_JLINKARM_SelDevice = JLinkDLL_getSym("JLINKARM_SelDevice");
    if (P_JLINKARM_SelDevice == NULL) return 0;
    P_JLINKARM_SelectTraceSource = JLinkDLL_getSym("JLINKARM_SelectTraceSource");
    if (P_JLINKARM_SelectTraceSource == NULL) return 0;
    P_JLINKARM_SetEndian = JLinkDLL_getSym("JLINKARM_SetEndian");
    if (P_JLINKARM_SetEndian == NULL) return 0;
    P_JLINKARM_SetErrorOutHandler = JLinkDLL_getSym("JLINKARM_SetErrorOutHandler");
    if (P_JLINKARM_SetErrorOutHandler == NULL) return 0;
    P_JLINKARM_SetLogFile = JLinkDLL_getSym("JLINKARM_SetLogFile");
    if (P_JLINKARM_SetLogFile == NULL) return 0;
    P_JLINKARM_SetMaxSpeed = JLinkDLL_getSym("JLINKARM_SetMaxSpeed");
    if (P_JLINKARM_SetMaxSpeed == NULL) return 0;
    P_JLINKARM_SetRESET = JLinkDLL_getSym("JLINKARM_SetRESET");
    if (P_JLINKARM_SetRESET == NULL) return 0;
    P_JLINKARM_SetSpeed = JLinkDLL_getSym("JLINKARM_SetSpeed");
    if (P_JLINKARM_SetSpeed == NULL) return 0;
    P_JLINKARM_SetTCK = JLinkDLL_getSym("JLINKARM_SetTCK");
    if (P_JLINKARM_SetTCK == NULL) return 0;
    P_JLINKARM_SetTDI = JLinkDLL_getSym("JLINKARM_SetTDI");
    if (P_JLINKARM_SetTDI == NULL) return 0;
    P_JLINKARM_SetTMS = JLinkDLL_getSym("JLINKARM_SetTMS");
    if (P_JLINKARM_SetTMS == NULL) return 0;
    P_JLINKARM_SetTRST = JLinkDLL_getSym("JLINKARM_SetTRST");
    if (P_JLINKARM_SetTRST == NULL) return 0;
    P_JLINKARM_StoreBits = JLinkDLL_getSym("JLINKARM_StoreBits");
    if (P_JLINKARM_StoreBits == NULL) return 0;
    P_JLINKARM_TIF_GetAvailable = JLinkDLL_getSym("JLINKARM_TIF_GetAvailable");
    if (P_JLINKARM_TIF_GetAvailable == NULL) return 0;
    P_JLINKARM_TIF_Select = JLinkDLL_getSym("JLINKARM_TIF_Select");
    if (P_JLINKARM_TIF_Select == NULL) return 0;
    P_JLINKARM_UpdateFirmwareIfNewer = JLinkDLL_getSym("JLINKARM_UpdateFirmwareIfNewer");
    if (P_JLINKARM_UpdateFirmwareIfNewer == NULL) return 0;
    P_JLINKARM_SetWarnOutHandler = JLinkDLL_getSym("JLINKARM_SetWarnOutHandler");
    if (P_JLINKARM_SetWarnOutHandler == NULL) return 0;
    P_JLINKARM_WriteBits = JLinkDLL_getSym("JLINKARM_WriteBits");
    if (P_JLINKARM_WriteBits == NULL) return 0;
    P_JLINKARM_EMU_GetNumDevices = JLinkDLL_getSym("JLINKARM_EMU_GetNumDevices");
    if (P_JLINKARM_EMU_GetNumDevices == NULL) return 0;
//    P_JLINKARM_EMU_GetDeviceInfo = JLinkDLL_getSym("JLINKARM_EMU_GetDeviceInfo");
//    if (P_JLINKARM_EMU_GetDeviceInfo == NULL) return 0;
    return 1;
}

//PYTHON CHECK POINT

uint32_t JLINKARM_GetDLLVersion(void) {
    return P_JLINKARM_GetDLLVersion();
}


void JLINKARM_ClrRESET(void) {
    P_JLINKARM_ClrRESET();
}

int JLINKARM_ClrTCK(void) {
    return P_JLINKARM_ClrTCK();
}

void JLINKARM_ClrTDI(void) {
    P_JLINKARM_ClrTDI();
}

void JLINKARM_ClrTMS(void) {
    P_JLINKARM_ClrTMS();
}

void JLINKARM_ClrTRST(void) {
    P_JLINKARM_ClrTRST();
}

void JLINKARM_ClrError(void) {
    P_JLINKARM_ClrError();
}


void JLINKARM_BeginDownload(uint32_t Flags) {
    P_JLINKARM_BeginDownload(Flags);
}

uint8_t JLINKARM_Clock(void) {
    return P_JLINKARM_Clock();
}

int JLINKARM_CORESIGHT_Configure(const char *sConfig) {
    return P_JLINKARM_CORESIGHT_Configure(sConfig);
}

int JLINKARM_CORESIGHT_ReadAPDPReg(uint8_t RegIndex, uint8_t APnDP, uint32_t *pData) {
    return P_JLINKARM_CORESIGHT_ReadAPDPReg(RegIndex, APnDP, pData);
}

int JLINKARM_CORESIGHT_WriteAPDPReg(uint8_t RegIndex, uint8_t APnDP, uint32_t Data) {
    return P_JLINKARM_CORESIGHT_WriteAPDPReg(RegIndex, APnDP, Data);
}

void JLINKARM_Core2CoreName(uint32_t Core, char *pBuffer, unsigned BufferSize) {
    P_JLINKARM_Core2CoreName(Core, pBuffer, BufferSize);
}

int JLINKARM_CP15_ReadEx(uint8_t CRn, uint8_t CRm, uint8_t op1, uint8_t op2, uint32_t *pData) {
    return P_JLINKARM_CP15_ReadEx( CRn,  CRm,  op1,  op2, pData);
}

int JLINKARM_CP15_WriteEx(uint8_t CRn, uint8_t CRm, uint8_t op1, uint8_t op2, uint32_t Data) {
    return P_JLINKARM_CP15_WriteEx( CRn,  CRm,  op1,  op2,  Data);
}

int JLINKARM_DEVICE_GetIndex(const char *sDeviceName) {
    return P_JLINKARM_DEVICE_GetIndex(sDeviceName);
}

int JLINKARM_DEVICE_SelectDialog(void *hParent, uint32_t Flags, JLINKARM_DEVICE_SELECT_INFO *pInfo) {
    return P_JLINKARM_DEVICE_SelectDialog(hParent, Flags, pInfo);
}

int JLINK_DownloadFile(const char *sFileName, uint32_t Addr) {
    return P_JLINK_DownloadFile(sFileName, Addr);
}

int JLINKARM_EMU_COM_Read(unsigned Channel, unsigned NumBytes, void *pData) {
    return P_JLINKARM_EMU_COM_Read(Channel, NumBytes, pData);
}

int JLINKARM_EMU_COM_Write(unsigned Channel, unsigned NumBytes, const void *pData) {
    return P_JLINKARM_EMU_COM_Write(Channel, NumBytes, pData);
}

int JLINKARM_EMU_COM_IsSupported(void) {
    return P_JLINKARM_EMU_COM_IsSupported();
}

uint32_t JLINKARM_EMU_GetNumDevices(void) {
    return P_JLINKARM_EMU_GetNumDevices();
}

void JLINKARM_EMU_GetProductName(char *pBuffer, uint32_t BufferSize) {
    P_JLINKARM_EMU_GetProductName(pBuffer, BufferSize);
}

int JLINKARM_EMU_HasCapEx(int CapEx) {
    return P_JLINKARM_EMU_HasCapEx(CapEx);
}

int JLINKARM_EMU_HasCPUCap(uint32_t CPUCap) {
    return P_JLINKARM_EMU_HasCPUCap(CPUCap);
}

char JLINKARM_EMU_IsConnected(void) {
    return P_JLINKARM_EMU_IsConnected();
}

void JLINKARM_EnableLog(JLINKARM_LOG *pfLog) {
    P_JLINKARM_EnableLog(pfLog);
}

void JLINKARM_EnableLogCom(JLINKARM_LOG *pfLog) {
    P_JLINKARM_EnableLogCom(pfLog);
}

int JLINKARM_EndDownload(void) {
    return P_JLINKARM_EndDownload();
}

int JLINK_EraseChip(void) {
    return P_JLINK_EraseChip();
}

const char *JLINKARM_GetCompileDateTime(void) {
    return P_JLINKARM_GetCompileDateTime();
}

void JLINKARM_GetConfigData(int *pIRPre, int *pDRPre) {
    P_JLINKARM_GetConfigData(pIRPre, pDRPre);
}

int JLINKARM_GetDebugInfo(uint32_t Index, uint32_t *pInfo) {
    return P_JLINKARM_GetDebugInfo(Index, pInfo);
}

int JLINKARM_GetDeviceFamily(void) {
    return P_JLINKARM_GetDeviceFamily();
}

uint32_t JLINKARM_GetEmuCaps(void) {
    return P_JLINKARM_GetEmuCaps();
}

void JLINKARM_GetEmuCapsEx(uint8_t *pCaps, int BufferSize) {
    P_JLINKARM_GetEmuCapsEx(pCaps, BufferSize);
}

void JLINKARM_GetFeatureString(char *pOut) {
    P_JLINKARM_GetFeatureString(pOut);
}

void JLINKARM_GetFirmwareString(char *s, int BufferSize) {
    P_JLINKARM_GetFirmwareString(s, BufferSize);
}

int JLINKARM_GetHWInfo(uint32_t BitMask, uint32_t *pHWInfo) {
    return P_JLINKARM_GetHWInfo(BitMask, pHWInfo);
}

int JLINKARM_GetHWStatus(JLINKARM_HW_STATUS *pStat) {
    return P_JLINKARM_GetHWStatus(pStat);
}

int JLINKARM_GetHardwareVersion(void) {
    return P_JLINKARM_GetHardwareVersion();
}

void JLINKARM_GetIdData(JTAG_ID_DATA *pIdData) {
    P_JLINKARM_GetIdData(pIdData);
}

int JLINKARM_GetMOEs(JLINKARM_MOE_INFO *pInfo, int MaxNumMOEs) {
    return P_JLINKARM_GetMOEs(pInfo, MaxNumMOEs);
}

char JLINKARM_GetOEMString(char *pOut) {
    return P_JLINKARM_GetOEMString(pOut);
}

int JLINKARM_GetScanLen(void) {
    return P_JLINKARM_GetScanLen();
}

uint16_t JLINKARM_GetSelDevice(void) {
    return P_JLINKARM_GetSelDevice();
}

int JLINKARM_GetSN(void) {
    return P_JLINKARM_GetSN();
}

uint16_t JLINKARM_GetSpeed(void) {
    return P_JLINKARM_GetSpeed();
}

void JLINKARM_GetSpeedInfo(JLINKARM_SPEED_INFO *pSpeedInfo) {
    P_JLINKARM_GetSpeedInfo(pSpeedInfo);
}

char JLINKARM_HasError(void) {
    return P_JLINKARM_HasError();
}

int JLINKARM_MeasureCPUSpeed(uint32_t RAMAddr, int PreserveMem) {
    return P_JLINKARM_MeasureCPUSpeed(RAMAddr, PreserveMem);
}

int JLINKARM_MeasureCPUSpeedEx(uint32_t RAMAddr, int PreserveMem, int AllowFail) {
    return P_JLINKARM_MeasureCPUSpeedEx(RAMAddr, PreserveMem, AllowFail);
}

int JLINKARM_MeasureSCLen(int ScanChain) {
    return P_JLINKARM_MeasureSCLen(ScanChain);
}

void JLINKARM_SelDevice(uint16_t DeviceIndex) {
    P_JLINKARM_SelDevice(DeviceIndex);
}

void JLINKARM_SelectTraceSource(int Source) {
    P_JLINKARM_SelectTraceSource(Source);
}

int JLINKARM_SetEndian(int v) {
    return P_JLINKARM_SetEndian(v);
}

void JLINKARM_SetErrorOutHandler(JLINKARM_LOG *pfErrorOut) {
    P_JLINKARM_SetErrorOutHandler(pfErrorOut);
}

void JLINKARM_SetLogFile(const char *sFilename) {
    P_JLINKARM_SetLogFile(sFilename);
}

void JLINKARM_SetMaxSpeed(void) {
    P_JLINKARM_SetMaxSpeed();
}

void JLINKARM_SetRESET(void) {
    P_JLINKARM_SetRESET();
}

void JLINKARM_SetSpeed(uint32_t Speed) {
    P_JLINKARM_SetSpeed(Speed);
}

int JLINKARM_SetTCK(void) {
    return P_JLINKARM_SetTCK();
}

void JLINKARM_SetTDI(void) {
    P_JLINKARM_SetTDI();
}

void JLINKARM_SetTMS(void) {
    P_JLINKARM_SetTMS();
}

void JLINKARM_SetTRST(void) {
    P_JLINKARM_SetTRST();
}

void JLINKARM_StoreBits(uint32_t TMS, uint32_t TDI, int NumBits) {
    P_JLINKARM_StoreBits(TMS, TDI, NumBits);
}

void JLINKARM_TIF_GetAvailable(uint32_t *pMask) {
    P_JLINKARM_TIF_GetAvailable(pMask);
}

int JLINKARM_TIF_Select(int Interface) {
    return P_JLINKARM_TIF_Select(Interface);
}

uint32_t JLINKARM_UpdateFirmwareIfNewer(void) {
    return P_JLINKARM_UpdateFirmwareIfNewer();
}

void JLINKARM_SetWarnOutHandler(JLINKARM_LOG *pfWarnOut) {
    P_JLINKARM_SetWarnOutHandler(pfWarnOut);
}

void JLINKARM_WriteBits(void) {
    P_JLINKARM_WriteBits();
}

//void JLINKARM_EMU_GetDeviceInfo(uint32_t iEmu, JLINKARM_EMU_INFO *pInfo) {
//    P_JLINKARM_EMU_GetDeviceInfo(iEmu, pInfo);
//}