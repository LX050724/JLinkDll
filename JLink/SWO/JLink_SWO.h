/**
 * @file SWO.h
 * @author yao
 */
#ifndef JLINKDLL_JLINK_SWO_H
#define JLINKDLL_JLINK_SWO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <JLink/JLink_Define.h>

/**
 * This function allows a debug controller to start/stop collecting SWO data, to flush the SWO
 * buffer and to read/write various SWO settings.
 * @param Cmd Specifies which command should be executed.
 * @param pData Pointer to data value or structure. Meaning depends on Cmd.
 * @retval 0 on success
 * @retval -1 if an error has occurred
 */
int JLINKARM_SWO_Control(uint32_t Cmd, void *pData);

/**
 * Disables SWO output on the target. This mainly means disabling of ITM & stimulus ports.
 * SWO data capturing on J-Link side is also stopped when calling this function (equivalent to
 * calling {@link JLINKARM_SWO_Control}(JLINKARM_SWO_CMD_STOP)).
 * @param PortMask Port mask used to describe which stimulus ports shall be disabled. A
 *                 1 in the mask disables the corresponding stimulus port.
 * @retval 0 O.K.
 * @retval <0 Error
 */
int JLINKARM_SWO_DisableTarget(uint32_t PortMask);

/**
 * Enables SWO output on the target. This mainly means configuration of the output protocol (UART / manchester),
 * configuration of the SWO output speed and enabling of ITM &
 * stimulus ports. SWO data capturing on J-Link side is also started when calling this function
 * (equivalent to calling {@link JLINKARM_SWO_Control}(JLINKARM_SWO_CMD_START)).
 * @param CPUSpeed Target CPU frequency in Hz. Needed to adjust dividers for SWO frequency accordingly.
 * @param SWOSpeed Frequency in Hz that should be used by target to output SWO data and by J-Link to capture SWO data.
 * @param Mode SWO mode (UART/manchester). Currently only UART (0) is supported.
 * @param PortMask Port mask used to describe which stimulus ports shall be enabled. A 1
 *                 in the mask enables the corresponding stimulus port.
 * @retval 0 O.K.
 * @retval <0 Error
 */
int JLINKARM_SWO_EnableTarget(uint32_t CPUSpeed, uint32_t SWOSpeed, int Mode, uint32_t PortMask);

/**
 * Returns a list of SWO speeds which are supported by both, the target and the connected
 * J-Link. Due to different CPUs on the target side and on the J-Link models, the supported
 * speeds may vary.
 * @param CPUSpeed Target CPU frequency in Hz.
 * @param MaxSWOSpeed Usually 0, so the list returned by this function will start with the highest
 *                    possible SWO speed supported by both sides. Can be used to set
 *                    an upper limit in Hz of the SWO speeds that will be added to the list.
 *                    Example: If MaxSWOSpeed = 3000000 (3 MHz) but highest possible speed would be 6 MHz,
 *                    the list will start with Speeds ≤ 3000000.
 *                    Useful to verify if a manually selected speed is a compatible one or to
 *                    get the closest compatible speed to the defined one
 * @param paSWOSpeed Pointer to an array of U32, used to store the list of compatible speeds.
 * @param NumEntries Determines number of compatible speeds that shall be stored in the list buffer.
 * @retval >=0 O.K., number of entries (compatible speeds) stored in the given list buffer.
 * @retval <0 Error
 */
int JLINKARM_SWO_GetCompatibleSpeeds(uint32_t CPUSpeed, uint32_t MaxSWOSpeed,
                                     uint32_t *paSWOSpeed, uint32_t NumEntries);

/**
 * This function reads data from the SWO buffer. The data will not automatically be removed
 * from the SWO buffer after reading. The application have to use the {@link JLINKARM_SWO_Control}
 * function with JLINKARM_SWO_CMD_FLUSH to remove the data from the buffer.
 * @code
 * U8 abData[0x100];
 * U32 NumBytes;
 * //
 * // Read and flush data
 * //
 * NumBytes = sizeof(abData);
 * JLINKARM_SWO_Read(&abData[0], 0, &NumBytes);
 * JLINKARM_SWO_Control(JLINKARM_SWO_CMD_FLUSH, &NumBytes);
 * printf("%d bytes read successfully\n", NumBytes);
 * @endcode
 * @param pData Buffer to be filled with the requested data.
 * @param Offset Offset of first byte to be retrieved from the SWO buffer.
 * @param pNumBytes Pointer to a U32 value containing the number of bytes to be read
 *                  from the SWO buffer. This value will be filled with the number of
 *                  bytes that could be read from the SWO buffer.
 */
void JLINKARM_SWO_Read(uint8_t *pData, uint32_t Offset, uint32_t *pNumBytes);

/**
 * This function reads the data which is output via SWO for one stimulus port, which is the
 * printable data.
 * @param Port Stimulus port to read data from. May be 0 - 31
 * @param pData Buffer to be filled with the requested data.
 * @param NumBytes Maximum number of bytes to read.
 */
void JLINKARM_SWO_ReadStimulus(int Port, uint8_t *pData, uint32_t NumBytes);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_SWO_H
