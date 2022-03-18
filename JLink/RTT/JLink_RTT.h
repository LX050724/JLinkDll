/**
 * @file JLink_RTT.h
 * @brief The table below lists the available SEGGER J-Link RTT API routines. All functions are listed
 *        in alphabetical order. Detailed descriptions of the routines can be found in the sections
 *        that follow.
 */

#ifndef JLINKDLL_JLINK_RTT_H
#define JLINKDLL_JLINK_RTT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t ConfigBlockAddress; //!<@brief Address of RTT block
    uint32_t Dummy0;
    uint32_t Dummy1;
    uint32_t Dummy2;
} JLINK_RTTERMINAL_START;

typedef struct {
    uint8_t InvalidateTargetCB; //!<@brief If set, RTTCB will be invalidated on target.
    uint8_t acDummy[3];
    uint32_t Dummy0;
    uint32_t Dummy1;
    uint32_t Dummy2;
} JLINK_RTTERMINAL_STOP;

typedef struct {
    int BufferIndex;             //!<@brief In: Index of the buffer to get info about.
    uint32_t Direction;          //!<@brief In: Direction of the buffer. (0 = Up; 1 = Down)
    char acName[32];             //!<@brief Out: Array for the 0-terminated name of the buffer.
    uint32_t SizeOfBuffer;       //!<@brief Out: Size of the buffer on the target.
    uint32_t Flags;              //!<@brief Out: Flags of the buffer.
} JLINK_RTTERMINAL_BUFDESC;

enum JLINKARM_RTTERMINAL_CMD {
    JLINKARM_RTTERMINAL_CMD_START = 0,       //!<@brief Starts RTT processing. This includes background read of RTT data from target. p may be NULL.  TODO @bug 值不确定
    JLINKARM_RTTERMINAL_CMD_STOP = 1,        //!<@brief Stops RTT on the J-Link and host side. p may be NULL.  TODO @bug 值不确定
    JLINKARM_RTTERMINAL_CMD_GETDESC = 2,     //!<@brief Get the size, name, and flag of a buffer.  TODO @bug 值不确定
    JLINKARM_RTTERMINAL_CMD_GETNUMBUF = 3,   //!<@brief After starting RTT, get the current number of up or down buffers.  TODO @bug 值不确定
//    JLINKARM_RTTERMINAL_CMD_GETSTAT = 4,
};

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
