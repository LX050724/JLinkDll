/**
 * @file JLink_SystemControl.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_SYSTEMCONTROL_H
#define JLINKDLL_JLINK_SYSTEMCONTROL_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function returns the version of the DLL.
 * @return 32 bit DLL version number. The version number consists of major, minor and revision
 *         number. In decimal representation, the version can be interpreted as follows:
 *         Mmmrr, where
 *         M is Major number
 *         mm is minor number,
 *         rr is revision number.
 */
uint32_t JLINKARM_GetDLLVersion(void);

/**
 * This function sets the RESET pin of the J-Link target interface to LOW (asserts reset).
 */
void JLINKARM_ClrRESET(void);

/**
 * Sets the TCK pin to LOW value.
 * @retval 0 Ok
 * @retval -1 Firmware of connected emulator does not support this feature
 */
int JLINKARM_ClrTCK(void);

/**
 * This function clears the test data input, therefore the TDI is set to logical 0 (GND - common ground).
 */
void JLINKARM_ClrTDI(void);

/**
 * This function clears the test mode select, therefore the TMS is set to logical 0 (GND - common ground).
 */
void JLINKARM_ClrTMS(void);

/**
 * This function sets the TRST pin of the J-Link target interface to LOW (asserts TRST).
 */
void JLINKARM_ClrTRST(void);

/**
 * This function clears the DLL internal error state.
 */
void JLINKARM_ClrError(void);

/**
 * @deprecated Use {@link JLINKARM_EMU_GetList} instead.
 * Get USB enumeration specific information about a specific J-Link such as serial number
 * used by J-Link to enumerate on USB.
 */
//void JLINKARM_EMU_GetDeviceInfo(uint32_t iEmu, JLINKARM_EMU_INFO *pInfo);

void JLINKARM_BeginDownload(uint32_t Flags);
uint8_t JLINKARM_Clock(void);
int JLINKARM_CORESIGHT_Configure(const char *sConfig);
int JLINKARM_CORESIGHT_ReadAPDPReg(uint8_t RegIndex, uint8_t APnDP, uint32_t *pData);
int JLINKARM_CORESIGHT_WriteAPDPReg(uint8_t RegIndex, uint8_t APnDP, uint32_t Data);
void JLINKARM_Core2CoreName(uint32_t Core, char *pBuffer, unsigned BufferSize);
int JLINKARM_CP15_ReadEx(uint8_t CRn, uint8_t CRm, uint8_t op1, uint8_t op2, uint32_t *pData);
int JLINKARM_CP15_WriteEx(uint8_t CRn, uint8_t CRm, uint8_t op1, uint8_t op2, uint32_t Data);
int JLINKARM_DEVICE_GetIndex(const char *sDeviceName);
int JLINKARM_DEVICE_SelectDialog(void *hParent, uint32_t Flags, JLINKARM_DEVICE_SELECT_INFO *pInfo);
int JLINK_DownloadFile(const char *sFileName, uint32_t Addr);
int JLINKARM_EMU_COM_Read(unsigned Channel, unsigned NumBytes, void *pData);
int JLINKARM_EMU_COM_Write(unsigned Channel, unsigned NumBytes, const void *pData);
int JLINKARM_EMU_COM_IsSupported(void);
void JLINKARM_EMU_GetProductName(char *pBuffer, uint32_t BufferSize);
int JLINKARM_EMU_HasCapEx(int CapEx);
int JLINKARM_EMU_HasCPUCap(uint32_t CPUCap);
char JLINKARM_EMU_IsConnected(void);
void JLINKARM_EnableLog(JLINKARM_LOG *pfLog);
void JLINKARM_EnableLogCom(JLINKARM_LOG *pfLog);
int JLINKARM_EndDownload(void);
int JLINK_EraseChip(void);
const char *JLINKARM_GetCompileDateTime(void);
void JLINKARM_GetConfigData(int *pIRPre, int *pDRPre);
int JLINKARM_GetDebugInfo(uint32_t Index, uint32_t *pInfo);
int JLINKARM_GetDeviceFamily(void);
uint32_t JLINKARM_GetEmuCaps(void);
void JLINKARM_GetEmuCapsEx(uint8_t *pCaps, int BufferSize);
void JLINKARM_GetFeatureString(char *pOut);
void JLINKARM_GetFirmwareString(char *s, int BufferSize);
int JLINKARM_GetHWInfo(uint32_t BitMask, uint32_t *pHWInfo);
int JLINKARM_GetHWStatus(JLINKARM_HW_STATUS *pStat);
int JLINKARM_GetHardwareVersion(void);
void JLINKARM_GetIdData(JTAG_ID_DATA *pIdData);
int JLINKARM_GetMOEs(JLINKARM_MOE_INFO *pInfo, int MaxNumMOEs);
char JLINKARM_GetOEMString(char *pOut);
int JLINKARM_GetScanLen(void);
uint16_t JLINKARM_GetSelDevice(void);
int JLINKARM_GetSN(void);
uint16_t JLINKARM_GetSpeed(void);
void JLINKARM_GetSpeedInfo(JLINKARM_SPEED_INFO * pSpeedInfo);
char JLINKARM_HasError(void);
int JLINKARM_MeasureCPUSpeed(uint32_t RAMAddr, int PreserveMem);
int JLINKARM_MeasureCPUSpeedEx(uint32_t RAMAddr, int PreserveMem, int AllowFail);
int JLINKARM_MeasureSCLen(int ScanChain);
void JLINKARM_SelDevice(uint16_t DeviceIndex);
void JLINKARM_SelectTraceSource (int Source);
int JLINKARM_SetEndian(int v);
void JLINKARM_SetErrorOutHandler(JLINKARM_LOG* pfErrorOut);
void JLINKARM_SetLogFile (const char* sFilename);
void JLINKARM_SetMaxSpeed(void);
void JLINKARM_SetRESET(void);
void JLINKARM_SetSpeed(uint32_t Speed);
int JLINKARM_SetTCK(void);
void JLINKARM_SetTDI(void);
void JLINKARM_SetTMS(void);
void JLINKARM_SetTRST(void);
void JLINKARM_StoreBits(uint32_t TMS, uint32_t TDI, int NumBits);
void JLINKARM_TIF_GetAvailable(uint32_t* pMask);
int JLINKARM_TIF_Select(int Interface);
uint32_t JLINKARM_UpdateFirmwareIfNewer(void);
void JLINKARM_SetWarnOutHandler(JLINKARM_LOG* pfWarnOut);
void JLINKARM_WriteBits(void);
uint32_t JLINKARM_EMU_GetNumDevices(void);

// 缺少JLINK_FUNC_INDEX定义，无法使用
//void *JLINK_GetpFunc(JLINK_FUNC_INDEX FuncIndex);

// 缺少JLINKARM_RTCK_REACT_INFO定义，无法使用
//int JLINKARM_MeasureRTCKReactTime(JLINKARM_RTCK_REACT_INFO* pReactInfo);

// 弃用函数
//void JLINKARM_EMU_GetDeviceInfo(uint32_t iEmu, JLINKARM_EMU_INFO *pInfo);


#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_SYSTEMCONTROL_H
