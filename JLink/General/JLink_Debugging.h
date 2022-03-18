/**
 * @file JLink_Debugging.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_DEBUGGING_H
#define JLINKDLL_JLINK_DEBUGGING_H

#include <stdint.h>
#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* This function clears a data event set via JLINKARM_SetDataEvent().
* @param Handle Handle of watchpoint to be removed. It is also possible to use the
*               JLINKARM_EVENT_HANDLE_ALL handle in order to remove all breakpoints,
*               which were set via JLINKARM_SetDataEvent().
* @see JLINKARM_SetDataEvent
* @retval 0 Ok
* @retval 1 Error
*/
int JLINKARM_ClrDataEvent(uint32_t Handle);


/**
 * This function removes a watchpoint set by JLINKARM_SetWP().
 * @note This function is deprecated! Use {@link JLINKARM_ClrDataEvent} instead.
 * @see JLINKARM_SetWP
 * @param WPHandle Handle of watchpoint to be removed. It is also possible to use the
 *                 JLINKARM_WP_HANDLE_ALL handle in order to remove all breakpoints,
 *                 which were set via JLINKARM_SetWP().
 * @retval 0 if watchpoint has been cleared
 * @retval -1 Error
 */
int JLINKARM_ClrWP(int WPHandle);

/**
 * This function removes a breakpoint set by JLINKARM_SetBP().
 * @details
 * This function writes directly to the ICE-breaker registers. This function can not be used
 * together with JLINKARM_ClrBPEx(). JLINKARM_ClrBPEx() may overwrite the ICE-breaker
 * registers.
 * @code
 * JLINKARM_SetBP(1, Addr);
 * JLINKARM_ClrBP(1);
 * @endcode
 *
 * @see JLINKARM_SetBP
 * @see JLINKARM_ClrBPEx
 * @param BPIndex Number of breakpoint. Either 0 or 1.
 */
void JLINKARM_ClrBP(uint32_t BPIndex);

/**
 * This function removes a breakpoint set by JLINKARM_SetBPEx()
 * @details This function does not write directly to the ICE-breaker registers. The
 *          ICE-breaker registers will be written when starting the core. This function
 *          can not be used together with JLINKARM_ClrBP(). JLINKARM_ClrBP() may overwrite
 *          the ICE-breaker registers.
 * @code
 * int BPHandle;
 * BPHandle = JLINKARM_SetBPEx(Addr, JLINKARM_BP_TYPE_THUMB);
 * JLINKARM_ClrBPEx(BPHandle);
 * @endcode
 * @param BPHandle Handle of breakpoint to be removed. It is also possible to use the
 *                 JLINKARM_BP_HANDLE_ALL handle in order to remove all breakpoints,
 *                 which were set via JLINKARM_SetBPEx().
 *
 * @see JLINKARM_ClrBP
 * @see JLINKARM_SetBPEx
 *
 * @retval 0 if breakpoint has been cleared
 * @retval -1 Error
 */
int JLINKARM_ClrBPEx(int BPHandle);

/**
 *
 * @param pEvent
 * @param pHandle
 * @return
 */
int JLINKARM_SetDataEvent(JLINKARM_DATA_EVENT *pEvent, uint32_t *pHandle);

/**
 *
 * @return
 */
uint32_t JLINKARM_CORE_GetFound(void);

/**
 *
 * @param Enable
 */
void JLINKARM_EnableSoftBPs(char Enable);

/**
 *
 * @param Addr
 * @return
 */
int JLINKARM_FindBP(uint32_t Addr);

/**
 *
 * @param BPHandle
 * @return
 */
uint32_t JLINKARM_GetBPInfo(int BPHandle);

/**
 *
 * @return
 */
uint32_t JLINKARM_GetNumBPs(void);

/**
 *
 * @param iBP
 * @param pInfo
 * @return
 */
int JLINKARM_GetBPInfoEx(int iBP, JLINKARM_BP_INFO *pInfo);

/**
 *
 * @return
 */
uint32_t JLINKARM_GetNumWPs(void);

/**
 *
 * @param Type
 * @return
 */
int JLINKARM_GetNumBPUnits(JLINKARM_BP_TYPE Type);

/**
 *
 * @return
 */
int JLINKARM_GetNumWPUnits(void);

/**
 *
 * @param paList
 * @param MaxNumItems
 * @return
 */
int JLINKARM_GetRegisterList(uint32_t *paList, int MaxNumItems);

/**
 *
 * @param RegIndex
 * @return
 */
const char *JLINKARM_GetRegisterName(uint32_t RegIndex);



/**
 *
 * @param iWP
 * @param pInfo
 * @return
 */
int JLINKARM_GetWPInfoEx(int iWP, JLINKARM_WP_INFO *pInfo);

/**
 *
 * @param NumInsts
 */
void JLINKARM_GoAllowSim(uint32_t NumInsts);

/**
 *
 * @param Addr
 * @param NumBytes
 * @param pData
 * @return
 */
int JLINKARM_ReadCodeMem(uint32_t Addr, uint32_t NumBytes, void *pData);

/**
 *
 * @param RegIndex
 * @return
 */
uint32_t JLINKARM_ReadICEReg(int RegIndex);

/**
 *
 * @param RegIndex
 * @return
 */
uint32_t JLINKARM_ReadReg(ARM_REG RegIndex);

/**
 *
 * @param paRegIndex
 * @param paData
 * @param paStatus
 * @param NumRegs
 * @return
 */
int JLINKARM_ReadRegs(const uint32_t *paRegIndex, uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs);

/**
 *
 * @param pBuffer
 * @param BufferSize
 * @return
 */
int JLINKARM_ReadTerminal(uint8_t *pBuffer, uint32_t BufferSize);

/**
 *
 * @param Inst
 * @return
 */
char JLINKARM_SimulateInstruction(uint32_t Inst);

/**
 *
 * @param BPIndex
 * @param Addr
 */
void JLINKARM_SetBP(uint32_t BPIndex, uint32_t Addr);

/**
 *
 * @param Addr
 * @param TypeFlags
 * @return
 */
int JLINKARM_SetBPEx(uint32_t Addr, uint32_t TypeFlags);

/**
 *
 * @return
 */
char JLINKARM_Step(void);

/**
 *
 * @return
 */
char JLINKARM_StepComposite(void);

/**
 *
 * @param TimeOut
 * @return
 */
int JLINKARM_WaitForHalt(int TimeOut);

/**
 *
 * @param RegIndex
 * @param Value
 * @param AllowDelay
 */
void JLINKARM_WriteICEReg(int RegIndex, uint32_t Value, int AllowDelay);

/**
 *
 * @param RegIndex
 * @param Data
 * @return
 */
char JLINKARM_WriteReg(ARM_REG RegIndex, uint32_t Data);

/**
 *
 * @param paRegIndex
 * @param paData
 * @param paStatus
 * @param NumRegs
 * @return
 */
int JLINKARM_WriteRegs(const uint32_t *paRegIndex, const uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs);

/**
 *
 * @param Value
 * @return
 */
int JLINKARM_WriteVectorCatch(uint32_t Value);

/**
 *
 * @param pData
 * @param NumItems
 * @param TimeOut
 * @return
 */
int JLINKARM_ReadDCC(uint32_t *pData, uint32_t NumItems, int TimeOut);

/**
 *
 * @param pData
 * @param NumItems
 */
void JLINKARM_ReadDCCFast(uint32_t *pData, uint32_t NumItems);

/**
 *
 * @param TimeOut
 * @return
 */
int JLINKARM_WaitDCCRead(int TimeOut);

/**
 *
 * @param pData
 * @param NumItems
 * @param TimeOut
 * @return
 */
int JLINKARM_WriteDCC(const uint32_t *pData, uint32_t NumItems, int TimeOut);

/**
 *
 * @param pData
 * @param NumItems
 */
void JLINKARM_WriteDCCFast(const uint32_t *pData, uint32_t NumItems);


#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_DEBUGGING_H
