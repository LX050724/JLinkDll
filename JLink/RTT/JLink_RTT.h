/**
 * @file JLink_RTT.h
 * @brief The table below lists the available SEGGER J-Link RTT API routines. All functions are listed
 *        in alphabetical order. Detailed descriptions of the routines can be found in the sections
 *        that follow.
 */

#ifndef JLINKDLL_JLINK_RTT_H
#define JLINKDLL_JLINK_RTT_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calls an internal command to control RTT.
 * @param Cmd The Cmd that should be executed
 *          @see JLINKARM_RTTERMINAL_CMD
 * @param p Pointer to structure containing parameters for the command. (See Add. information below).
 *          JLINK_RTTERMINAL_CMD_GETNUMBUF takes a uint32_t Direction instead of a structure.
 *          @see JLINK_RTTERMINAL_START
 *          @see JLINK_RTTERMINAL_STOP
 *          @see JLINK_RTTERMINAL_BUFDESC
 * @retval >= 0 success
 * @retval < 0 error
 * @retval 0 Cmd = JLINKARM_RTTERMINAL_CMD_STOP: RTT was running and has been stopped r
 * @retval 1 Cmd = JLINKARM_RTTERMINAL_CMD_STOP: RTT stopped but was not running before
 * @retval -2 If CMD = (JLINKARM_RTTERMINAL_CMD_GETDESC || JLINKARM_RTTERMINAL_CMD_GETNUMBUF):
 *                      RTT Control Block not found yet.
 */
int JLINK_RTTERMINAL_Control(uint32_t Cmd, void *p);

/**
 * Reads bytes from the RTT host-side buffer.
 * @param BufferIndex Index of the buffer to read.
 * @param sBuffer Pointer to buffer which is used to store the data being read.
 * @param BufferSize Size of buffer for read data.
 * @retval >= 0 Ok, number of bytes read.
 * @retval < 0 Error
 */
int JLINK_RTTERMINAL_Read(uint32_t BufferIndex, char *sBuffer, uint32_t BufferSize);

/**
 * Writes data into the RTT buffer.
 * @param BufferIndex IIndex of the buffer to write data to.
 * @param sBuffer PPointer to the data that should be stored.
 * @param BufferSize Number of bytes to write.
 * @retval >= 0 Ok, number of bytes written.
 * @retval < 0 Error
 */
int JLINK_RTTERMINAL_Write(uint32_t BufferIndex, const char *sBuffer, uint32_t BufferSize);

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_RTT_H
