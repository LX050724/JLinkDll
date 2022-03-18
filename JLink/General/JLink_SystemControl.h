/**
 * @file JLink_SystemControl.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_SYSTEMCONTROL_H
#define JLINKDLL_JLINK_SYSTEMCONTROL_H

#include <stdint.h>

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


#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_SYSTEMCONTROL_H
