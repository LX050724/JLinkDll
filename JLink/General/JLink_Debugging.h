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
 * Extended version of {@link JLINKARM_SetWP}. Allows specifying data events which halt the CPU,
 * trigger SWO output, trigger trace output.
 * @param pEvent
 * @param pHandle
 * @return
 */
int JLINKARM_SetDataEvent(JLINKARM_DATA_EVENT *pEvent, uint32_t *pHandle);

/**
 * This function returns the CPU core identified by J-Link after {@link JLINKARM_Connect} has been
 * called. This function may only be used after {@link JLINKARM_Connect} has succeeded.
 * @retval 0 J-Link is not connected to a target
 * @retval >0 Target connected
 */
uint32_t JLINKARM_CORE_GetFound(void);

/**
 * This function allows the use of software breakpoints.
 * @param Enable Enables (=1) or disables (=0) the software breakpoint feature
 */
void JLINKARM_EnableSoftBPs(char Enable);

/**
 * This function tries to find a breakpoint at the given address
 * @param Addr Address to be searched for
 * @return Handle of breakpoint at given address or zero if no matching breakpoint exist
 */
int JLINKARM_FindBP(uint32_t Addr);

/**
 * Returns the breakpoint type.
 * @param BPHandle Handle of breakpoint.
 * @retval -1 Error
 * @return Bit 0 - 30 Reserved;
 *         Bit 31 0 = Hardware breakpoint;
 *         1 = Software breakpoint
 */
uint32_t JLINKARM_GetBPInfo(int BPHandle);

/**
 * This function retrieves the number of currently active breakpoints. These are breakpoints
 * which have been set using {@link JLINKARM_SetBPEx} and have not been cleared (using {@link JLINKARM_ClrBPEx}).
 * @return Number of breakpoints.
 */
uint32_t JLINKARM_GetNumBPs(void);

/**
 * Gets information about a breakpoint, such as breakpoint handle, address and implementation type.
 * @param iBP Index of breakpoint of which information is requested. If the index
 *            is unknown, use -1 and fill in the handle member of the JLINKARM_BP_INFO structure instead.
 * @param pInfo Pointer to structure of type JLINKARM_BP_INFO.
 * @return Number of breakpoints which are currently in the DLL internal breakpoint list.
 */
int JLINKARM_GetBPInfoEx(int iBP, JLINKARM_BP_INFO *pInfo);

/**
 * This function retrieves the number of watchpoints.
 * @return unsigned JLINKARM_GetNumWPs(void);
 */
uint32_t JLINKARM_GetNumWPs(void);

/**
 * This function retrieves the total number of available breakpoints on specified breakpoint units.
 * @see JLINKARM_BP_TYPE
 * @param Type Specifies the breakpoint units to be queried. (Described below)
 * @return Total number of available hardware breakpoints.
 */
int JLINKARM_GetNumBPUnits(JLINKARM_BP_TYPE Type);

/**
 * This function retrieves the number of available watchpoints.
 * @return Total number of available watchpoints
 */
int JLINKARM_GetNumWPUnits(void);

/**
 * Stores a list of indices for all registers that are supported by the connected CPU into a given
 * buffer. These indices can then be used to read the register content via {@link JLINKARM_ReadRegs}.
 * @note This function may only be called after a successful call to {@link JLINKARM_Connect}.
 * @code
 * U32 aRegIndex[JLINKARM_MAX_NUM_CPU_REGS];
 * U32 aRegData[JLINKARM_MAX_NUM_CPU_REGS];
 * int NumRegs;
 * int i;
 * NumRegs = JLINKARM_GetRegisterList(aRegIndex, JLINKARM_MAX_NUM_CPU_REGS);
 * JLINKARM_ReadRegs(aRegIndex, aRegData, NULL, NumRegs);
 * for (i = 0; i < NumRegs; i++) {
 *     printf("%s = %.8X\n", JLINKARM_GetRegisterName(aRegIndex[i]), aRegData[i]);
 * }
 * @endcode
 * @param paList Pointer to buffer of U32 items which is used to store the register indices.
 * @param MaxNumItems Maximum number of indices that can be stored in paList .
 * @retval >=0 Number of indices that have been stored in paList .
 */
int JLINKARM_GetRegisterList(uint32_t *paList, int MaxNumItems);

/**
 * The function retrieves and returns the name of the ARM CPU register for the given index.
 * @param RegIndex
 * @return Name of the register
 */
const char *JLINKARM_GetRegisterName(uint32_t RegIndex);


/**
 * Gets information about a watchpoint and returns the number of watchpoints which are
 * currently in the DLL internal watchpoint list.
 * @param iWP Index of the watchpoint.
 * @param pInfo Pointer to structre of type {@link JLINKARM_WP_INFO}.
 * @return Number of watchpoints which are currently in the DLL internal watchpoint list.
 */
int JLINKARM_GetWPInfoEx(int iWP, JLINKARM_WP_INFO *pInfo);

/**
 * @see  JLINKARM_Go
 * Allows the DLL so simulate up to NumInsts instructions. Can be useful for source level
 * debugging when perfoming a Step-over over small functions.
 * @note If any breakpoint is hit during simulation, the DLL stops simulating instructions.
 */
void JLINKARM_GoAllowSim(uint32_t NumInsts);

/**
 * Read code memory.
 *
 * Not used by most applications; it has the advantage that it uses a cache and reads ahead.
 * Primary purpose is to accelerate applications such as IAR and a GDB-server which read
 * small chunks of data for a disassembly window.
 * @param Addr Address to start reading
 * @param NumBytes Number of bytes that should be read.
 * @param pData Pointer to a buffer where the data should be stored. Make sure that it
 *              points to valid memory and that there is sufficient space for the entire
 *              number of data items.
 * @retval >=0 Number of items read succesfully
 * @retval <0 Error
 */
int JLINKARM_ReadCodeMem(uint32_t Addr, uint32_t NumBytes, void *pData);

/**
 * The function reads an ARM ICE register.
 * @code
 * int v0;
 * JLINKARM_WriteICEReg(0x08, 0x12345678, 1);
 * v0 = JLINKARM_ReadICEReg(0x08);
 * if (v0 != 0x12345678) {
 *     sprintf(ac, "ICE communication failed: Expected 0x12345678 in ICE registers 0x8. Found %8X", v0);
 * } else {
 *     printf("ICE communication o.k.\n");
 * }
 * @endcode
 * @param RegIndex Register to read. Either 0 or 1.
 * @return Content of the queried ICE register.
 */
uint32_t JLINKARM_ReadICEReg(int RegIndex);

/**
 * The function reads and returns the value of the specified ARM CPU register.
 * @param RegIndex Register to read.
 * @return Content of the queried register.
 */
uint32_t JLINKARM_ReadReg(ARM_REG RegIndex);

/**
 * Reads multiple CPU registers. Especially useful if the debugger needs the values of a specific
 * set of registers in a defined order in an array.
 * The register list passed to this function does not need to have continuous register indexes.
 * @param paRegIndex Pointer to array of register indexes.
 * @param paData Pointer to array of memory areas to store the register values
 * @param paStatus Pointer to array of status bytes. May be NULL.
 *
 *                 - 0 if corresponding register has been successfully read.
 *
 *                 - -1 if register could not be read.
 * @param NumRegs Number of registers to read
 * @retval 0 O.K.
 * @retval <0 Error
 */
int JLINKARM_ReadRegs(const uint32_t *paRegIndex, uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs);

/**
 * Currently only used internally by the J-Link GlueDLL for Renesas HEW and IAR EWRX.
 * Read terminal data from J-Link.
 * @note Currently only implemented for Renesas RX series which implement virtual terminal
 *       via E2C / C2E functionality and use the Renesas library.
 * @retval >=0 Number of bytes read
 * @retval <0 Error
 */
int JLINKARM_ReadTerminal(uint8_t *pBuffer, uint32_t BufferSize);

/**
 * This function tries to simulate the specified instruction.
 * @param Inst Instruction to simulate.
 * @retval 0 if instruction has been simulated
 * @retval 1 if instruction could not be simulated
 */
char JLINKARM_SimulateInstruction(uint32_t Inst);

/**
 * This function inserts a hardware breakpoint with index BPIndex at address Addr .
 * @note This function writes directly to the ICE-breaker registers. This function can not be
 *       used together with {@link JLINKARM_SetBPEx}. {@link JLINKARM_SetBPEx} may overwrite the
 *       ICE-breaker registers.
 * @note The use of {@note JLINKARM_SetBPEx} is recommended instead
 * @code
 * U32 Addr;
 * Addr = 0x00200000;
 * JLINKARM_SetBP(1, Addr);
 * @endcode
 * @param BPIndex Number of breakpoint. Either 0 or 1.
 * @param Addr Address
 */
void JLINKARM_SetBP(uint32_t BPIndex, uint32_t Addr);

/**
 * This function sets a breakpoint of a specific type at a specified address. If the breakpoint
 * needs to be set in a specific depends on the CPU which is used. Which breakpoint modes
 * are available also depends on the CPU that is used. For more information about which
 * breakpoint modes are available for which CPU, please refer to the breakpoint mode table
 * below. This function can set all types of breakpoints:
 *
 * - Hardware
 *
 * - Software (in RAM)
 *
 * - Software (in Flash memory).
 *
 * Various implementation flags allow control of the type of breakpoint to set
 * @param Addr Address where the breakpoint shall be set. This address can be in RAM, flash or ROM.
 * @param TypeFlags Specifies the desired breakpoint type. (Described below)
 * @retval >0 O.K., handle of new breakpoint
 * @retval 0 On Error
 */
int JLINKARM_SetBPEx(uint32_t Addr, uint32_t TypeFlags);

/**
 * This function executes a single step on the target. The instruction is overstepped even if it is breakpointed.
 * @retval 0 O.K.
 * @retval 1 Error
 */
char JLINKARM_Step(void);

/**
 * This function executes a single step on the target in THUMB mode.
 * @retval 0 O.K.
 * @retval 1 Error
 */
char JLINKARM_StepComposite(void);

/**
 * Waits for CPU to be halted
 * Returns on:
 *
 * - CPU halted
 *
 * - Error while retrieving CPU state
 *
 * - Timeout reached
 *
 * @param TimeOut Number of milliseconds to wait for halt before a timeout occurs.
 * @retval 1 CPU halted
 * @retval 0 CPU not halted (timeout reached)
 * @retval <0 Error
 */
int JLINKARM_WaitForHalt(int TimeOut);

/**
 * This function writes in the selected ICE Breaker register.
 * @code
 * int v0;
 * JLINKARM_WriteICEReg(0x08, 0x12345678, 1);
 * v0 = JLINKARM_ReadICEReg(0x08);
 * if (v0 != 0x12345678) {
 *     sprintf(ac, "ICE communication failed: Expected 0x12345678 in ICE registers 0x8. Found %8X", v0);
 * } else {
 *     printf("ICE communication o.k.\n");
 * }
 * @endcode
 * @param RegIndex Register to write.
 * @param Value Data that should be written to the register.
 * @param AllowDelay 0 for not allowing a delay. Data will be written directly to the target.
 */
void JLINKARM_WriteICEReg(int RegIndex, uint32_t Value, int AllowDelay);

/**
 * Writes into an ARM register. The data is not immediately written into the register. Instead
 * we first write into a cache and the data is transferred to the register on CPU start.
 * For a list of different register sets, please refer to {@link JLINKARM_ReadReg}.
 * @param RegIndex Register to write. (See description of {@link JLINKARM_ReadReg} for detailed information of the {@link ARM_REG} type)
 * @param Data Data to write.
 * @retval 0 if register has been written
 * @retval 1 on error
 */
char JLINKARM_WriteReg(ARM_REG RegIndex, uint32_t Data);

/**
 * Writes multiple CPU registers. Especially useful if the debugger gives the values of a specific
 * set of registers in a defined order in an array.
 * @param paRegIndex Pointer to array of registers (by index) to write.
 * @param paData Pointer to array of data to write.
 * @param paStatus Pointer to status array. May be NULL.
 *                 0 if corresponding register has been successfully written.
 *                 -1 if register could not be written.
 * @param NumRegs Number of registers to write
 * @retval 0
 */
int JLINKARM_WriteRegs(const uint32_t *paRegIndex, const uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs);

/**
 * This function allows to set the vector catch bits of the processor. If the CPU jumps to a
 * vector on which vector catch is active/set, the CPU normally enters debug state or takes
 * a debug exception. For example, the vector catch for reset vector is usually set by the
 * debugger before the CPU is reset, in order to halt it immediately after the reset. (If the
 * CPU supports vector catch for the reset vector)
 * @param Value Bitmask which determines which vector catch bits shall be written.
 *              (See bit description for different CPU cores below)
 * @retval >=0 O.K.
 * @retval <0 On error.
 */
int JLINKARM_WriteVectorCatch(uint32_t Value);

/**
 * Read code memory.
 * Reads data items (32-bits) from ARM core via DCC.
 * @param pData Pointer to a buffer where the data should be stored. Make sure that it
 *              points to valid memory and that there is sufficient space for the entire
 *              number of data items.
 * @param NumItems Number of 32-bit data items that should be read.
 * @param TimeOut Timeout in milliseconds for a single data item.
 * @return Number of 32-bit data items read.
 */
int JLINKARM_ReadDCC(uint32_t *pData, uint32_t NumItems, int TimeOut);

/**
 * Read code memory.
 * Reads data items (32-bits) from ARM core via DCC without checking if the requested data is available.
 * @param pData Pointer to a buffer where the data should be stored. Make sure that it
 *              points to valid memory and that there is sufficient space for the entire
 *              number of data items.
 * @param NumItems Number of 32-bit data items that should be read.
 */
void JLINKARM_ReadDCCFast(uint32_t *pData, uint32_t NumItems);

/**
 * This function checks if new DCC data is available. If no data item is available after the
 * specified amount of time, a timeout error occurs.
 * @param TimeOut Number of milliseconds to wait for data before a timeout occurs.
 * @retval 0 if a timeout occurred
 * @retval 1 if new DCC data is available
 */
int JLINKARM_WaitDCCRead(int TimeOut);

/**
 * Writes data items (32-bits) to ARM core via DCC.
 * @param pData Pointer to buffer containing data to be written.
 * @param NumItems Number of 32-bit data items that should be written.
 * @param TimeOut Timeout in milliseconds for a single data item.
 * @return Number of 32-bit data items written.
 */
int JLINKARM_WriteDCC(const uint32_t *pData, uint32_t NumItems, int TimeOut);

/**
 * Writes data items (32-bits) to ARM core via DCC without checking if the target is ready
 * to accept the data.
 * @param pData Pointer to buffer containing data to be written.
 * @param NumItems Number of 32-bit data items that should be written.
 */
void JLINKARM_WriteDCCFast(const uint32_t *pData, uint32_t NumItems);


#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_DEBUGGING_H
