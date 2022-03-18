/**
 * @file JLink_FileIO.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_FILEIO_H
#define JLINKDLL_JLINK_FILEIO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * On emulators which support file I/O this function deletes a specific file.
 * Check if a specific emulator supports file I/O by calling {@link JLINKARM_GetEmuCaps}.
 * Currently, only Flasher models support file I/O.
 * @retval >=0 Ok
 * @retval <0 Error
 */
int JLINKARM_EMU_FILE_Delete(const char *sFile);

/**
 * On emulators which support file I/O this function gets the size of a specific file.
 * Check if a specific emulator supports file I/O by calling {@link JLINKARM_GetEmuCaps}.
 * Currently, only Flasher models support file I/O.
 * @retval >=0 Size of specified file
 * @retval <0 Error
 */
int JLINKARM_EMU_FILE_GetSize(const char *sFile);

/**
 * On emulators which support file I/O this function reads a specific file.
 * Check if a specific emulator supports file I/O by calling {@link JLINKARM_GetEmuCaps}.
 * Currently, only Flasher models support file I/O.
 * @retval >=0 Number of bytes read succesfully.
 * @retval <0 Error
 */
int JLINKARM_EMU_FILE_Read(const char *sFile, uint8_t *pData, uint32_t Offset, uint32_t NumBytes);

/**
 * On emulators which support file I/O this function writes a specific file.
 * Check if a specific emulator supports file I/O by calling {@link JLINKARM_GetEmuCaps}.
 * Currently, only Flasher models support file I/O.
 * @retval Number of bytes written succesfully.
 * @retval <0 Error
 */
int JLINKARM_EMU_FILE_Write(const char *sFile, const uint8_t *pData, uint32_t Offset, uint32_t NumBytes);

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_FILEIO_H
