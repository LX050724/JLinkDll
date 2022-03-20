/**
 * @file JTAG.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_JTAG_H
#define JLINKDLL_JLINK_JTAG_H

#include "JLink/JLink_Define.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Allows to setup the actual JTAG scan chain.
 * @code
 * JLINKARM_JTAG_DEVICE_CONF aDeviceConf[2];
 * //
 * // Specify device 0
 * //
 * aDeviceConf[0].SizeOfStruct = sizeof(JLINKARM_JTAG_DEVICE_CONF);
 * aDeviceConf[0].IRLen = 4;
 * aDeviceConf[0].IRPrint = 1;
 * aDeviceConf[0].Id = 0x4BA00477;
 * aDeviceConf[0].sName = "Device0";
 * //
 * // Sepcify device 1
 * //
 * aDeviceConf[1].SizeOfStruct = sizeof(JLINKARM_JTAG_DEVICE_CONF);
 * aDeviceConf[1].IRLen = 4;
 * aDeviceConf[1].IRPrint = 0; // Unknown / invalid
 * aDeviceConf[1].Id = 0; // Unknown / invalid
 * aDeviceConf[1].sName = NULL; // Unknown / invalid
 * //
 * // Configure JTAG scan chain
 * //
 * JLINK_JTAG_ConfigDevices(COUNTOF(aDeviceConf), &aDeviceConf[0]);
 * @endcode
 * @param NumDevices NumDevices describes the number of elements the paConf pointer
 *                   Points to. This also specifies how many devices are in the JTAG chain.
 * @param paConf Pointer to a list of JTAG devices. The first JTAG device paConf points
 *               to, is later as position JLINK_ConfigJTAG(0, 0);
 */
void JLINK_JTAG_ConfigDevices(uint32_t NumDevices, const JLINKARM_JTAG_DEVICE_CONF *paConf);

/**
 * Returns the JTAG-Id of one of a connected device.
 * @param DeviceIndex Index of the device. E.g. if n devices are connected to the scan chain,
 *                    then is the index between 0 and n-1.
 * @return JTAG Id of the device with index n.
 */
uint32_t JLINKARM_JTAG_GetDeviceId(unsigned DeviceIndex);

/**
 * Get additional information about a device, such as device name, IRLen and IRPrint, based
 * on the device index.
 * @param DeviceIndex Index of the device. E.g. if n devices are connected to the scan chain,
 *                    then is the index between 0 and n-1.
 * @param pDeviceInfo Pointer to info variable which is used to hold the device information.
 * @retval 0 Additional device information available. All elements of JLINKARM_JTAG_DEVICE_INFO are available
 * @retval >0 Unknown device, IRLen information available
 * @retval -1 No additional device information
available */
int JLINKARM_JTAG_GetDeviceInfo(unsigned DeviceIndex, JLINKARM_JTAG_DEVICE_INFO *pDeviceInfo);

/**
 * This function gets a unit of 8 bit from output buffer.
 * @param BitPos Startposition of unit to read from input buffer.
 * @return 8 Bit data from input buffer.
 */
uint32_t JLINKARM_JTAG_GetU8(int BitPos);

/**
 * This function gets a unit of 16 bit from output buffer.
 * @param BitPos Startposition of unit to read from input buffer.
 * @return 16 Bit data from input buffer.
 */
uint32_t JLINKARM_JTAG_GetU16(int BitPos);

/**
 * This function gets a unit of 16 bit from output buffer.
 * @param BitPos Startposition of unit to read from input buffer.
 * @return 32 Bit data from input buffer.
 */
uint32_t JLINKARM_JTAG_GetU32(int BitPos);

/**
 * Retrieves TDO data from input buffer.
 * @param pDest Pointer to data destination buffer.
 * @param BitPos Startposition of unit to read from input buffer.
 * @param NumBits Number of bits to read and write.
 */
void JLINKARM_JTAG_GetData(uint8_t *pDest, int BitPos, int NumBits);

/**
 * This function adds the bits to set the TAP controller into Shift-DR state to the delivered data
 * bits and stores the sequence in the output buffers.
 * @param pTDI Pointer to output buffer.
 * @param NumBits Number of bits to store.
 * @return The bit position of data in input buffer after transmission.
 */
int JLINKARM_JTAG_StoreData(const uint8_t *pTDI, int NumBits);

/**
 * This function adds the bits to set the TAP controller into Shift-IR state to the delivered
 * command bits and stores the sequence in the output buffers.
 * @param pTDI Pointer to output buffer.
 * @param IRLen Instruction length in bits.
 */
void JLINKARM_JTAG_StoreInst(const uint8_t *pTDI, int IRLen);

/**
 * This function stores a raw data sequence in the output buffer.
 * @param pTDI Pointer to output buffer.
 * @param pTMS Pointer to mode select buffer.
 * @param NumBits Number of bits to read and write.
 * @return The bit position of data in input buffer after transmission.
 */
int JLINKARM_JTAG_StoreRaw(const uint8_t *pTDI, const uint8_t *pTMS, uint32_t NumBits);

/**
 * This function transmits the input buffer to the connected JTAG device and stores the received data in the output buffer.
 * @param pTDI Pointer to output buffer.
 * @param pTDO Pointer to input buffer.
 * @param NumBits Number of bits to read and write.
 * @retval If pTDO is set to NULL the transmission is not essential. If the data amount is not beyond
 *         buffer size the data will only transferred only when necessary.
 */
void JLINKARM_JTAG_StoreGetData(const uint8_t *pTDI, uint8_t *pTDO, int NumBits);

/**
 * This function stores the specified number of bits in the output buffers, transfers the whole
 * content of the output buffers to the JTAG device(s) and stores the received data in the input
 * buffer. This function writes only the assigned raw data without additions to the JTAG device.
 * @param pTDI Pointer to output buffer.
 * @param pTDO Pointer to input buffer.
 * @param pTMS Pointer to mode select buffer.
 * @param NumBits Number of bits to read and write.
 */
void JLINKARM_JTAG_StoreGetRaw(const uint8_t *pTDI, uint8_t *pTDO, const uint8_t *pTMS, uint32_t NumBits);

/**
 * Writes out the data remaining in the output buffers to JTAG device.
 */
void JLINKARM_JTAG_SyncBits(void);

/**
 * This function transmits the content of data in the output buffers to the JTAG device and
 * adds if necessary one ore more 0-bits to fill the buffer to bytesize. E.g. if the output buffers
 * are filled with 23 bits, {@link JLINKARM_JTAG_SyncBytes} adds one 0-bit to each output buffer
 * and transmits 24 bits.
 */
void JLINKARM_JTAG_SyncBytes(void);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_JTAG_H
