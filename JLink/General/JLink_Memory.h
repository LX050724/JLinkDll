/**
 * @file JLink_Memory.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_MEMORY_H
#define JLINKDLL_JLINK_MEMORY_H

#include <JLink/JLink_Define.h>
#ifdef __cplusplus
extern "C" {
#endif


/**
 * Get the different memory zones supported by the currently connected CPU. Some CPUs
 * (Like 8051 based devices) support multiple memory zones where the physical address of
 * the different zones may overlap. For example, the 8051 cores support the following zones,
 * each zone starting at address 0x0:
 *
 *  - IDATA
 *
 *  - DDATA
 *
 *  - XDATA
 *
 *  - CODE
 *
 * To access the different zones, the J-Link API provides some functions to route a memory
 * access to a specific memory zone. These functions will fail if:
 *
 * - The connected CPU core does not provide any zones.
 *
 * - An unknown zone is passed for sZone. All of these function may only be called after
 *   JLINK_Connect() has been called successfully.
 *
 * @code
 * // Shows all memory zones of the target CPU.
 * static int _ShowAllMemZones (void) {
 *     int r;
 *     JLINK_MEM_ZONE_INFO* paZoneInfo;
 *     JLINK_MEM_ZONE_INFO aZoneInfo[10];
 *     r = JLINK_GetMemZones(aZoneInfo, COUNTOF(aZoneInfo));
 *     if (r < 0) {
 *         return -1;
 *     }
 *     if (r > COUNTOF(aZoneInfo)) {
 *         //
 *         // Allocate memory for memory zones info buffer if local buffer is not big enough
 *         //
 *         paZoneInfo = malloc(r * sizeof(JLINK_MEM_ZONE_INFO));
 *         if (paZoneInfo == NULL) {
 *             printf("Failed to allocate memory for memory zones info buffer.\n");
 *             return -1;
 *         }
 *         r = JLINK_GetMemZones(paZoneInfo, r);
 *         for (int i = 0; i < r; i++) {
 *             printf ("Zone Number: %d Zone Name: %s /n", (i + 1), paZoneInfo[i].sName);
 *         }
 *         free(paZoneInfo);
 *         return 0;
 *     }
 *     for (int i = 0; i < r; i++) {
 *         printf ("Zone Number: %d Zone Name: %s /n", (i + 1), aZoneInfo[i].sName);
 *     }
 *     return 0;
 * }
 * @endcode
 * @param paZoneInfo Pointer to an array of JLINK_MEM_ZONE_INFO to get the memory zone info into.
 * @param MaxNumZones Maximum number of memory zones available in the array pointed to by paZoneInfo .
 * @retval >=0 Number of zones supported by the connected CPU.
 * @retval <0 Error
 */
int JLINK_GetMemZones(JLINK_MEM_ZONE_INFO *paZoneInfo, int MaxNumZones);

/**
 * The function reads memory from the target system. If necessary, the target CPU is halted
 * in order to read memory.
 * @param Addr Start address
 * @param NumBytes Number of bytes to read
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of bytes.
 * @retval 0 O.K. Memory could be read
 * @retval 1 Error/Abort. Memory could not be read
 */
int JLINKARM_ReadMem(uint32_t Addr, uint32_t NumBytes, void *pData);

/**
 * Reads memory from the target system {@link JLINKARM_ReadMem} with the given access width.
 * @see JLINKARM_ReadMem
 * @param Addr Start address
 * @param NumBytes Number of bytes to read
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of bytes.
 * @param AccessWidth Forces a specific memory access width.
 * @retval >=0 O.K., number of bytes that could be read.
 * @retval <0 Error while reading memory. No bytes in pData can be assumed as valid.
 */
int JLINKARM_ReadMemEx(uint32_t Addr, uint32_t NumBytes, void *pData, uint32_t AccessWidth);

/**
 * Reads memory from the target system (see description of {@link JLINKARM_ReadMem}).
 * @see JLINKARM_ReadMem
 * @param Addr Start address
 * @param NumBytes Number of bytes to read
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of bytes.
 * @retval >=0 Number of bytes read
 * @retval <0 Error
 */
int JLINKARM_ReadMemIndirect(uint32_t Addr, uint32_t NumBytes, void *pData);

/**
 * Reads memory from the target system (see description of {@link JLINKARM_ReadMem}). This
 * function reads memory immediately from the hardware without caching the memory contents.
 * @see JLINKARM_ReadMem
 * @param Addr Start address
 * @param NumBytes Number of bytes to read
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of bytes.
 * @retval 0 O.K. Memory could be read
 * @retval 1 Error/Abort. Memory could not be read
 */
int JLINKARM_ReadMemHW(uint32_t Addr, uint32_t NumBytes, void *pData);

/**
 * The function reads memory from the target system in units of bytes.
 * @param Addr Start address
 * @param NumItems Number of bytes to read
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area.
 * @param pStatus Pointer to a memory area of min. NumItems bytes in size, to receive
 *                status information for each item. May be NULL.
 * @retval >=0 Number of data units (bytes) successfully read.
 * @retval <0 Error, such as JTAG problem, communication problem.
 */
int JLINKARM_ReadMemU8(uint32_t Addr, uint32_t NumItems, uint8_t *pData, uint8_t *pStatus);

/**
 * The function reads memory from the target system in units of 16-bits.
 * @param Addr Start address
 * @param NumItems Number of bytes to read @bug 官方文档对此处的描写可能存在问题，猜测是Number of 16-bit units (half words) to read.
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of 16-bit units.
 * @param pStatus Pointer to a memory area of min. NumItems bytes in size, to receive
 *                status information for each item. May be NULL.
 * @retval >=0 Number of data units (half words) successfully read.
 * @retval <0 Error, such as JTAG problem, communication problem.
 */
int JLINKARM_ReadMemU16(uint32_t Addr, uint32_t NumItems, uint16_t *pData, uint8_t *pStatus);

/**
 * The function reads memory from the target system in units of 32-bits.
 * @param Addr Start address
 * @param NumItems Number of 32-bit units (words) to read.
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of 32-bit units.
 * @param pStatus Pointer to a memory area of min. NumItems bytes in size, to receive
 *                status information for each item. May be NULL.
 * @retval >=0 Number of data units (bytes) successfully read.
 * @retval <0 Error, such as JTAG problem, communication problem.
 */
int JLINKARM_ReadMemU32(uint32_t Addr, uint32_t NumItems, uint32_t *pData, uint8_t *pStatus);

/**
 * The function reads memory from the target system in units of 64-bits.
 * @param Addr Start address
 * @param NumItems Number of 64-bit units (long words) to read.
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of 64-bit units.
 * @param pStatus Pointer to a memory area of min. NumItems bytes in size, to receive
 *                status information for each item. May be NULL.
 * @retval >=0 Number of data units (bytes) successfully read.
 * @retval <0 Error, such as JTAG problem, communication problem.
 */
int JLINKARM_ReadMemU64(uint32_t Addr, uint32_t NumItems, uint64_t *pData, uint8_t *pStatus);

/**
 * Reads from a specific memory zone.
 * Some CPUs (Like 8051 based devices) support multiple memory zones where the physical
 * address of the different zones may overlap. For example, the 8051 cores support the
 * following zones, each zone starting at address 0x0:
 *
 *  - IDATA
 *
 *  - DDATA
 *
 *  - XDATA
 *
 *  - CODE
 *
 * To access the different zones, the J-Link API provides some functions to route a memory
 * access to a specific memory zone.
 *
 * - The connected CPU core does not provide any zones.
 *
 * - An unknown zone is passed for sZone.
 *
 * All of these function may only be called after {@link JLINK_Connect} has been called successfully.
 * @param Addr Start address
 * @param NumBytes Number of bytes to read
 * @param pData Pointer to the memory area where the data should be stored. Make
 *              sure that it points to a valid memory area and that there is sufficient
 *              space for the entire number of bytes.
 * @param AccessWidth Forces a specific memory access width.
 * @param sZone Name of memory zone to access.
 * @retval >=0 Number of items read successfully.
 * @retval <0 Error
 * @retval -1,-2,-3,-4 Reserved for regular ReadMem error codes
 * @retval -5 Zone not found
 */
int JLINK_ReadMemZonedEx(uint32_t Addr, uint32_t NumBytes, void *pData, uint32_t AccessWidth, const char *sZone);


/**
 * The function writes memory to the target system.
 * @param Addr Start address
 * @param Count Number of bytes to write.
 * @param pData Pointer to buffer containing the data bytes to write.
 * @retval >=0 Number of bytes transferred successfully.
 * @retval <0 Error.
 */
int JLINKARM_WriteMem(uint32_t Addr, uint32_t Count, const void *pData);

/**
 * Writes memory to the target system (see description of {@link JLINKARM_WriteMem}).
 * This function does not write the data immediately to the target hardware. The data will be
 * cached. This function is obsolete and should not be used for future software development.
 * @see JLINKARM_WriteMem
 * @param Addr Start address
 * @param Count Number of bytes to write.
 * @param pData Pointer to buffer containing the data bytes to write.
 * @retval >=0 Number of bytes transferred successfully.
 * @retval <0 Error.
 */
int JLINKARM_WriteMemDelayed(uint32_t Addr, uint32_t Count, const void *pData);

/**
 * Writes memory to the target system (see description of {@link JLINKARM_WriteMem}) with the
 * given maximum assess width.
 * @see JLINKARM_WriteMem
 * @retval >=0 Number of items transferred successfully.
 * @retval <0 Error.
 */
int JLINKARM_WriteMemEx(uint32_t Addr, uint32_t NumBytes, const void *p, uint32_t AccessWidth);

/**
 * Writes to a specific memory zone.
 * Some CPUs (Like 8051 based devices) support multiple memory zones where the physical
 * address of the different zones may overlap. For example, the 8051 cores support the
 * following zones, each zone starting at address 0x0:
 *
 * - IDATA
 *
 * - DDATA
 *
 * - XDATA
 *
 * - CODE
 *
 * To access the different zones, the J-Link API provides some functions to route a memory
 * access to a specific memory zone. These functions will fail if:
 *
 * - The connected CPU core does not provide any zones.
 *
 * - An unknown zone is passed for sZone.
 *
 * All of these function may only be called after JLINK_Connect() has been called successfully.
 *
 * @param Addr Start address
 * @param NumBytes Number of bytes to write
 * @param p Pointer to the memory area containing the data that should be
 *          stored. Make sure that it points to a valid memory area.
 * @param AccessWidth Forces a specific memory access width.
 * @param sZone Name of memory zone to access.
 * @retval >=0 Number of items written successfully.
 * @retval <0 Error
 * @retval -1,-2,-3,-4 Reserved for regular WriteMem error codes
 * @retval -5 Zone not found
 * */
int JLINK_WriteMemZonedEx(uint32_t Addr, uint32_t NumBytes, const void *p, uint32_t AccessWidth, const char *sZone);

/**
 * The function writes one single byte to the target system.
 * @param Addr Address
 * @param Data Data byte to write
 * @retval 0 ok
 * @retval !=0 Error
 */
int JLINKARM_WriteU8(uint32_t Addr, uint8_t Data);

/**
 * The function writes a unit of 16-bits to the target system.
 * @param Addr Address
 * @param Data 16-bits of data to write.
 * @retval 0 ok
 * @retval !=0 Error
 */
int JLINKARM_WriteU16(uint32_t Addr, uint16_t Data);

/**
 * The function writes a unit of 32-bits to the target system.
 * @param Addr Address
 * @param Data 32-bits of data to write.
 * @retval 0 ok
 * @retval !=0 Error
 */
int JLINKARM_WriteU32(uint32_t Addr, uint32_t Data);

/**
 * The function writes a unit of 64-bits to the target system.
 * @param Addr Address
 * @param Data 64-bits of data to write.
 * @retval 0 ok
 * @retval !=0 Error
 */
int JLINKARM_WriteU64(uint32_t Addr, uint64_t Data);

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_MEMORY_H
