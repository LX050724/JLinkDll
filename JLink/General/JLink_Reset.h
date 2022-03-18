/**
 * @file JLink_Reset.h
 * @author yao
 */


#ifndef JLINKDLL_JLINK_RESET_H
#define JLINKDLL_JLINK_RESET_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function performs a reset. The RESET pin and the TRST pin are toggled by default,
 * when this function is called.
 * @retval >= 0 Number of bytes read
 * @retval < 0 Error
 */
int JLINKARM_Reset(void);

/**
 * This function performs a RESET but without halting the device.
 * For more detailed information please see the description of {@link JLINKARM_Reset}.
 */
void JLINKARM_ResetNoHalt(void);

/**
 * This function affects the behaviour of the function JLINKARM_Reset(). If ResetPullsRESET
 * is enabled, the function JLINKARM_Reset() will also toggle the RESET pin on the JTAG bus
 * @param OnOff Enables (=1) or disables (=0) ResetPullsRESET.
 */
void JLINKARM_ResetPullsRESET(uint8_t OnOff);

/**
 * This function affects the behaviour of the function JLINKARM_Reset(). If ResetPullsTRST is
 * enabled, the function JLINKARM_Reset() will also toggle the TRST pin on the JTAG bus.
 * @param OnOff Enables (=1) or disables (=0) ResetPullsTRST.
 */
void JLINKARM_ResetPullsTRST(uint8_t OnOff);

/**
 * This function resets the TAP controller via TRST
 */
void JLINKARM_ResetTRST(void);

/**
 *
 * @param OnOff
 * @return
 */
int JLINKARM_SetInitRegsOnReset(int OnOff);

/**
 * Defines a delay in milliseconds after reset. This function is useful for some evalboards which
 * already contain an application or a boot loader and therefore need some time before the
 * core is stopped, for example to initialize hardware, the memory management unit (MMU)
 * or the external bus interface. Default value is 0.
 *
 * @note Boards like the ATMEL EB55 start up in 32 kHz mode. Allowing the default flash to execute
 * before stopping makes it possible to work with the board without writing a debugger macro
 * to set up the clock. It makes initial work with a board easier. Another example is when the
 * onboard flash sets up boards with memory like DRAM. In a final design this is not an issue,
 * but it makes life easier for the first playing around.
 *
 * @param ms Delay after reset in milliseconds.
 */
void JLINKARM_SetResetDelay(int ms);

/**
 * Refer to the J-Link / J-Trace User Guide,
 * section Reset strategies in chapter Working with J-Link and J-Trace for detailed
 * information about the different reset
 * strategies. Default value is JLINKARM_RESET_TYPE_NORMAL.
 *
 * Refer to the J-Link / J-Trace User Guide,
 * section Reset strategies in chapter Working with J-Link and J-Trace for detailed
 * information about the different reset
 * strategies. Default value is JLINKARM_CM3_RESET_TYPE_NORMAL.
 *
 * @bug TODO 值不确定
 */
typedef enum {
    // ARM7/ ARM9
    JLINKARM_RESET_TYPE_NORMAL,
    JLINKARM_RESET_TYPE_BP0,
    JLINKARM_RESET_TYPE_ADI,
    JLINKARM_RESET_TYPE_NO_RESET,
    JLINKARM_RESET_TYPE_HALT_WP,
    JLINKARM_RESET_TYPE_HALT_DBGRQ,
    JLINKARM_RESET_TYPE_SOFT,
    JLINKARM_RESET_TYPE_SAM7,

    // Cortex-M specifics
    JLINKARM_CM3_RESET_TYPE_NORMAL,
    JLINKARM_CM3_RESET_TYPE_CORE,
    JLINKARM_CM3_RESET_TYPE_RESETPIN,
    JLINKARM_CM3_RESET_TYPE_CONNECT_UNDER_RESET,
    JLINKARM_CM3_RESET_TYPE_HALT_AFTER_BTL,
    JLINKARM_CM3_RESET_TYPE_HALT_BEFORE_BTL,
    JLINKARM_CM3_RESET_TYPE_KINETIS,
    JLINKARM_CM3_RESET_TYPE_ADI_HALT_AFTER_KERNEL,
    JLINKARM_CM3_RESET_TYPE_LPC1200,
    JLINKARM_CM3_RESET_TYPE_S3FN60D,
} JLINKARM_RESET_TYPE;

/**
 * Defines the reset strategy.
 * @param ResetType Defines the reset strategy.
 */
void JLINKARM_SetResetType(JLINKARM_RESET_TYPE ResetType);

/**
 * Get description of a specific reset type available for the currently connected CPU core.
 * @note Target already needs to be identified by {@link JLINKARM_Connect} when calling this function.
 * @return Number of available reset types for CPU core J-Link is currently connected to
 */
int JLINKARM_GetResetTypeDesc(int ResetType, const char **psResetName, const char **psResetDesc);


#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_RESET_H
