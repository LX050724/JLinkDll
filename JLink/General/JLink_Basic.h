/**
 * @file JLink_Basic.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_BASIC_H
#define JLINKDLL_JLINK_BASIC_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function closes the JTAG connection and the connection to the J-Link.
 */
void JLINKARM_Close(void);

/**
 * This function establishes a connection to the target system.
 * When calling this func- tion, JLink will start its auto-detection
 * and identification of the target CPU. It is nec- essary to call
 * this function before any other target communication than low-level
 * JTAG/SWD sequence generation is performed.
 
 * @retval >= 0 O.K. Connection to target system established successfully.
 * @retval < 0 Error
 * @retval -1 Unspecified error
 * @retval <= -256 Global DLL error code. For a list of global error codes
 *         which can be returned by this function, please refer to Global
 *         DLL error codes on page 51.
 */
int JLINKARM_Connect(void);

/**
 * Restarts the CPU core after it has been halted. If the current instruction is break- pointed,
 * this instruction is not automatically overstepped. Instead, the CPU will immediately stop
 * again. If the intention is to overstep a breakpointed instruction, there are 2 possible options:
 *
 * - Perform a single step (which oversteps any breakpointed instruction), then start the
 *   CPU using JLINKARM_Go()
 *
 * - Use JLINKARM_GoEx() with the JLINKARM_GO_OVERSTEP_BP option
 *
 */
void JLINKARM_Go(void);

/**
 * When this flag is set and the current instruction is breakpointed, JLINKARM_GoEx() oversteps the breakpoint automatically
 * TODO
 * @bug 值不确定
 */
#define JLINKARM_GO_OVERSTEP_BP 1

/**
 * This function restarts the CPU core, but in addition to JLINKARM_Go() it allows to define a
 * maximum number of instructions which can be simulated/emulated. This especially takes
 * advantage when the program is located in flash and flash breakpoints are used. Simulating
 * instructions avoids to reprogram the flash and speeds up (single) stepping, especially on
 * source code level
 * @param MaxEmulInsts Maximum number of instructions allowed to be simulated. Instruction
 *                     simulation stops whenever a breakpointed instruction is hit, an instruction
 *                     which can not be simulated/emulated is hit or when MaxEmulInsts is reached.
 * @param Flags Specifies the behaviour of JLINKARM_GoEx
 * @see JLINKARM_GO_OVERSTEP_BP
 */
void JLINKARM_GoEx(uint32_t MaxEmulInsts, uint32_t Flags);

/**
 * Disables the interrupts and restarts the CPU core. If the current instruction is breakpointed,
 * this instruction is not automatically overstepped. Instead, the CPU will immediately stop
 * again. If the intention is to overstep a breakpointed instruction, perform a single step (which
 * oversteps any breakpointed instruction), then start the CPU using {@link JLINKARM_GoIntDis}.
 */
void JLINKARM_GoIntDis(void);

/**
 * This function halts the ARM core. It is always the first function you have to call if you want
 * to communicate with the ARM core
 * @retval 0 if ARM core has been halted
 * @retval 1 on error
 */
char JLINKARM_Halt(void);

/**
 * This function checks whether the JTAG connection has been opened.
 * @retval if not connected
 * @retval if connected
 */
char JLINKARM_IsConnected(void);

/**
 * This function checks whether the ARM core is halted.
 * @retval 0 ARM core is not halted
 * @retval 1 ARM core is halted
 * @retval <0 Error
 */
char JLINKARM_IsHalted(void);

/**
 * Check if DLL has been opened ({@link JLINKARM_Open} or {@link JLINKARM_OpenEx} successfully returned)
 * and therefore a connection to a J-Link could be established.
 * @return
 */
char JLINKARM_IsOpen(void);

/**
 * Per default, the J-Link API locks against other threads and processes (accessing the same
 * J-Link) for the duration of the API call.
 *
 * If there are have multiple API calls that need to be done in order andmust not be interrupted
 * by an API call from another thread / process, JLINKARM_Lock can be called to lock beyond
 * a single API call.
 *
 * After the multi-API call operation is finished, {@link JLINKARM_Unlock} must be called.
 */
void JLINKARM_Lock(void);

/**
 * This function opens the connection to J-Link. It’s always the first function you have to call to
 * use the J-Link ARM DLL. After opening the connection, the function checks also if a newer
 * firmware version is available.
 * @code
 * sError = JLINKARM_Open();
 * if (sError) {
 *      MessageBox(NULL, sError, "J-Link", MB_OK);
 *      exit(1);
 * }
 * @endcode
 * @retval NULL Ok
 * @retval !=NULL Pointer to an error string
 */
const char *JLINKARM_Open(void);


typedef void (*JLINKARM_LOG)(const char *sError);

/**
 * Opens the JTAG connection (see description of {@link JLINKARM_Open}). This function allows to
 * set log and error out handlers before the JTAG connection is opened.
 * @code
 * static void _LogHandler(const char* sLog) {
 *     printf(sLog);
 * }
 * static void _ErrorOutHandler(const char* sError) {
 *     MessageBox(NULL, sError, "J-Link", MB_OK);
 * }
 * void main(void) {
 *     const char* sError;
 *     sError = JLINKARM_OpenEx(_LogHandler, _ErrorOutHandler);
 *     if (sError) {
 *         MessageBox(NULL, sError, "J-Link", MB_OK);
 *         exit(1);
 *     }
 * }
 * @endcode
 * @param pfLog Pointer to log handler function of type JLINKARM_LOG
 * @param pfErrorOut Pointer to error out handler function of type JLINKARM_LOG.
 * @retval NULL Ok
 * @retval !=NULL Pointer to an error string
 */
const char *JLINKARM_OpenEx(JLINKARM_LOG *pfLog, JLINKARM_LOG *pfErrorOut);

/**
 * Please refer to {link JLINKARM_Lock}
 * @see JLINKARM_Lock
 */
void JLINKARM_Unlock(void);

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_BASIC_H
