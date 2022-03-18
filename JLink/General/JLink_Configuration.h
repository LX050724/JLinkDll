/**
 * @file JLink_Configuration.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_CONFIGURATION_H
#define JLINKDLL_JLINK_CONFIGURATION_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    /**
     * This is the serial number reported in the
     * discovery process. For J-Links which are
     * connected via USB this is the USB serial
     * number which is
     *
     * 1. the “true serial number” for newer JLinks
     *
     * 2. 123456 for older J-Links.
     *
     * For J-Links which are connected via TCP/IP
     * this is always the “true serial number”.
     */
    uint32_t SerialNumber;

    /**
     * Connection type of the J-Link. Can be
     * {@link JLINKARM_HOSTIF_USB} or {@link JLINKARM_HOSTIF_IP}.
     */
    uint32_t Connection;

    /**
     * USB Addr. Default is 0, values of 0..3 are
     * permitted. Only filled if for J-Links connected via USB. For J-Links which are connected via TCP/IP this field is zeroed.
     */
    uint32_t USBAddr;

    /**
     * IP Addr. of the connected emulator in case
     * the emulator is connected via IP. For IP4
     * (current version), only the first 4 bytes are
     * used. The remaining bytes are zeroed.
     */
    uint8_t aIPAddr[16];

    /**
     * J-Link via IP only: Time period [ms] after
     * which the UDP discover answer from emulator was received
     * (-1 if emulator is connected over USB)
     */
    int Time;

    /**
     * J-Link via IP only: Time period [us] after
     * which the UDP discover answer from emulator was received
     * (-1 if emulator is connected over USB)
     */
    uint64_t Time_us;

    uint32_t HWVersion;              //!<@brief J-Link via IP only: Hardware version of JLink
    uint8_t abMACAddr;               //!<@brief J-Link via IP only: MAC Addr
    char acProduct[32];              //!<@brief J-Link via IP only: Product name
    char acNickName[32];             //!<@brief J-Link via IP only: Nickname of J-Link
    char acFWString[112];            //!<@brief J-Link via IP only: Firmware string of JLink
    char IsDHCPAssignedIP;           //!<@brief J-Link via IP only: Is J-Link configured for IP address reception via DHCP?
    char IsDHCPAssignedIPIsValid;    //!<@brief J-Link via IP only
    char NumIPConnections;           //!<@brief J-Link via IP only: Number of IP connections which are currently established to this J-Link
    char NumIPConnectionsIsValid;    //!<@brief J-Link via IP only
    char aPadding[34];               //!<@brief Dummy bytes to pad the structure size to 264 bytes. Reserved for future use.
} JLINKARM_EMU_CONNECT_INFO;

/**
* TODO
* @deprecated 弃用结构体
* @bug 结构未知
*/
typedef struct {
    char a[sizeof(JLINKARM_EMU_CONNECT_INFO)];
} JLINKARM_EMU_INFO;

/**
 * @param sTitle Title of the unsecure dialog. Can be shown by handler function.
 * @param sMsg Text of the unsecure dialog (what will happen etc.). Can be shown by
 *             the handler function
 */
typedef int (*JLINK_UNSECURE_DIALOG_CB_FUNC)(const char *sTitle, const char *sMsg, uint32_t Flags);

/**
 * This function configures the JTAG scan chain and needs to be called if the J-Link ARM is
 * connected to a JTAG scan chain with multiple devices. In this case this function enables you
 * to configure the exact position of the ARM device you want to address.
 * @param IRPre Total length of instruction registers of all devices closer to TDI than
 *              the addressed ARM device. The instruction register length is defined
 *              by the manufacturer of the device. For ARM7 and ARM9 chips, the
 *              length of the instruction register is four.
 * @param DRPre Total number of data bits closer to TDI than the addressed ARM device.
 */
void JLINKARM_ConfigJTAG(int IRPre, int DRPre);

/**
 * Add a custom license to the connected J-Link. Custom licenses can be stored on a J-Link
 * to use it as an USB dongle for software licenses.
 * @details J-Link V9 and J-Link ULTRA/PRO V4 have 336 Bytes memory for licenses. Previous models
 *          support up to 80 Bytes.
 *          For an example on how to use the J-Link License Feature, refer to Store custom licenses
 *          on J-Link on page 178.
 * @param sLicense 0-Terminated license string to be added to J-Link.
 * @retval 0 O.K., license added.
 * @retval 1 O.K., license already exists.
 * @retval -1 Error. Unspecified
 * @retval -2 Error. Failed to read/write licensearea
 * @retval -3 Error. Not enough space on J-Link to store license
 */
int JLINK_EMU_AddLicense(const char *sLicense);

/**
 * Erase all custom licenses from the connected J-Link’s.
 * @retval 0 O.K.
 * @retval < 0 Error.
 */
int JLINK_EMU_EraseLicenses(void);

/**
 * Get all custom licenses from the connected J-Link.
 * @details J-Link V9 and J-Link ULTRA/PRO V4 have 336 Bytes memory for licenses. Previous models
 *          support up to 80 Bytes. For an example on how to use the J-Link License Feature, refer to
 *          “Store custom licenses on J-Link” on page 178.
 * @param pBuffer Pointer to buffer to store the licenses into.
 * @param NumBytes Number of bytes available in the buffer.
 * @retval >= 0 O.K., Number of bytes written into buffer.
 * @retval < 0 Error.
 */
int JLINK_EMU_GetLicenses(char *pBuffer, uint32_t NumBytes);


enum {
    JLINKARM_HOSTIF_USB, //!<@bug TODO 值不确定
    JLINKARM_HOSTIF_IP,  //!<@bug TODO 值不确定
};

/**
 * This function is used to get a list of all emulators which are connected to the host PC via
 * USB. In addition to that when calling this function, it can be specified if emulators which
 * are connected via TCP/IP should also be listed. This function does not commu- nicate with
 * the J-Link firmware in order to get the emulator information, so calling this function does
 * not interfere with a J-Link which is in a running debug session.
 * @code
 * int r;
 * int i;
 * char NeedDealloc;
 * char ac[128];
 * const char *s;
 * U32 Index;
 * JLINKARM_EMU_CONNECT_INFO * paConnectInfo;
 * JLINKARM_EMU_CONNECT_INFO aConnectInfo[50];
 * //
 * // Request emulator list
 * //
 * r = JLINKARM_EMU_GetList(JLINKARM_HOSTIF_USB, &aConnectInfo[0], COUNTOF(aConnectInfo));
 * //
 * // Allocate memory for emulator info buffer if local buffer is not big enough
 * //
 * NeedDealloc = 0;
 * if (r > COUNTOF(aConnectInfo)) {
 *     paConnectInfo = malloc(r * sizeof(JLINKARM_EMU_CONNECT_INFO));
 *     if (paConnectInfo == NULL) {
 *         printf("Failed to allocate memory for emulator info buffer.\n");
 *         return -1;
 *     }
 *     JLINKARM_EMU_GetList(JLINKARM_HOSTIF_USB, paConnectInfo, r);
 * }
 * @endcode
 * @param HostIFs Specifies on which host interfaces should be searched for connected J-Links.
 *                HostIFs can be JLINKARM_HOSTIF_USB or JLINKARM_HOSTIF_IP. Both host interface
 *                types can be or-combined.
 * @param paConnectInfo Pointer to an array of JLINKARM_EMU_CONNECT_INFO structures which is used
 *                      to hold the information for each emulator.
 * @param MaxInfos Specifies the maximum number of emulators for which information can be stored
 *                 in the array pointed to by paConnectInfo .
 * @retval >= 0 O.K., total number of emulators which have been found.
 * @retval < 0 Error.
 */
int JLINKARM_EMU_GetList(int HostIFs, JLINKARM_EMU_CONNECT_INFO *paConnectInfo, int MaxInfos);

/**
 * @deprecated Use {@link JLINKARM_EMU_GetList} instead.
 * Get USB enumeration specific information about a specific J-Link such as serial number
 * used by J-Link to enumerate on USB.
 */
void JLINKARM_EMU_GetDeviceInfo(uint32_t iEmu, JLINKARM_EMU_INFO *pInfo);

/**
 * This function allows the user to select a specific J-Link he wants to connect to by passing
 * the units serial number to this function. In general there are 2 different ways how a J-Link
 * can be identified by the host system:
 *
 *  1. By the USB address the J-Link is connected to (deprecated)
 *
 *  2. By the serial number of the unit
 *
 * The old method to connect multiple J-Links to one PC via USB was, to configure them to
 * be identified by different USB addresses. This method limited the maximum number of JLinks which could be simultaneously connected to one PC to 4 (USB addr. 0 - 3). This way
 * of connecting multiple J-Links to the PC is deprecated and should not be used anymore.
 * Nevertheless, due to compatibility it is still supported by later versions of the DLL. The
 * identification via serial number allows a unlimited number of J-Links to be simultaneously
 * connected to the PC.
 * @code
 * //
 * // Select J-Link with serial number 58001326
 * // to connect to when calling JLINKARM_Open()
 * //
 * JLINKARM_EMU_SelectByUSBSN(58001326);
 * //
 * // Connect to selected J-Link
 * //
 * JLINKARM_Open();
 * @endcode
 * @param SerialNo Serial number of the J-Link which shall be selected.
 * @retval >= 0 Index of emulator with given serial number (0 if only one emulator is connected to the PC)
 * @retval < 0 Error, no emulator with given serial number found
 */
int JLINKARM_EMU_SelectByUSBSN(uint32_t SerialNo);

/**
 * This function opens the J-Link emulator selection dialog in order to
 * select between all emulators which are available over TCP/IP.
 * @param pIPAddr Buffer which holds the IP address of the selected emulator.
 * @param BufferSize Size of the buffer which pIPAddr is pointing to.
 * @param pPort Port number of the selected connection.
 * @retval < 0 No emulator selected
 * @retval >= 0 Ok
 */
int JLINKARM_EMU_SelectIP(char *pIPAddr, int BufferSize, uint16_t *pPort);

/**
 * Select an emulator which is connected to the host via Ethernet, by its serial number. This
 * function can be used to select an emulator even if you do not know its IP address (for
 * environments where the IP address is changed in some intervals). You simply need the
 * emulator’s serial number in order to connect to it.
 * @param SerialNo Serial number of the emulator which shall be selected.
 */
void JLINKARM_EMU_SelectIPBySN(uint32_t SerialNo);

/**
 * This function returns the Id of the ARM core.
 * @return 32-bit Id number.
 */
uint32_t JLINKARM_GetId(void);

/**
 * This function selects and configures a connection to the J-Link via TCP/IP.
 * @param sHost String that contains a host name or an IP address.
 * @param Port TCP/IP port to be used for the connection.
 * @retval 0 O.K.
 * @retval 1 Error
 */
char JLINKARM_SelectIP(const char *sHost, int Port);

/**
 * This function selects and configures a connection to J-Link via USB. Per default, the DLL
 * connects via USB to J-Link. In this version of the DLL up to 4 J-Links can be connected
 * to a single host.
 * @note This function should be called before trying to connect to the J-Link using {@link JLINKARM_Open} or {@link JLINKARM_OpenEx}.
 * @param Port USB port to be used for the connection. Valid values range from 0 to 3.
 * @retval 0 O.K.
 * @retval 1 Error
 */
char JLINKARM_SelectUSB(int Port);

/**
 * Sets a hook function that is called instead of showing the device-unsecure-dialog of the
 * J-Link DLL. Can be used to customize the unsecure dialog that potentially shows up for
 * certain devices, if they are locked/secured. This especially makes sense, if an IDE vendor
 * etc. wants to show additional / other information in the unsecure dialog etc.
 * @note This dialog is only available for certain devices. It is not available for all ones.
 * @note This function should be called after {@link JLINK_Open} but before {@link JLINK_Connect}.
 * @param pfHook Pointer to unsecure dialog handling type JLINK_UNSECURE_DIALOG_CB_FUNC.
 * @retval ≥ 0 O.K.
 * @retval < 0 Error
 */
int JLINK_SetHookUnsecureDialog(JLINK_UNSECURE_DIALOG_CB_FUNC *pfHook);

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_CONFIGURATION_H
