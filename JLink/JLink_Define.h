/**
 * @file JLink_Define.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_DEFINE_H
#define JLINKDLL_JLINK_DEFINE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name JLINK_CORE_DEFINE
 * @brief JLink内核代码表
 * @{
 */
#define JLINK_CORE_NONE (0x00000000U)
#define JLINK_CORE_ANY (0xFFFFFFFFU)
#define JLINK_CORE_CORTEX_M1 (0x010000FFU)
#define JLINK_CORE_COLDFIRE (0x02FFFFFFU)
#define JLINK_CORE_CORTEX_M3 (0x030000FFU)
#define JLINK_CORE_CORTEX_M3_R1P0 (0x03000010U)
#define JLINK_CORE_CORTEX_M3_R1P1 (0x03000011U)
#define JLINK_CORE_CORTEX_M3_R2P0 (0x03000020U)
#define JLINK_CORE_SIM (0x04FFFFFFU)
#define JLINK_CORE_XSCALE (0x05FFFFFFU)
#define JLINK_CORE_CORTEX_M0 (0x060000FFU)
#define JLINK_CORE_ARM7 (0x07FFFFFFU)
#define JLINK_CORE_ARM7TDMI (0x070000FFU)
#define JLINK_CORE_ARM7TDMI_R3 (0x0700003FU)
#define JLINK_CORE_ARM7TDMI_R4 (0x0700004FU)
#define JLINK_CORE_ARM7TDMI_S (0x070001FFU)
#define JLINK_CORE_ARM7TDMI_S_R3 (0x0700013FU)
#define JLINK_CORE_ARM7TDMI_S_R4 (0x0700014FU)
#define JLINK_CORE_CORTEX_A8 (0x080000FFU)
#define JLINK_CORE_CORTEX_A7 (0x080800FFU)
#define JLINK_CORE_CORTEX_A9 (0x080900FFU)
#define JLINK_CORE_CORTEX_A12 (0x080A00FFU)
#define JLINK_CORE_CORTEX_A15 (0x080B00FFU)
#define JLINK_CORE_CORTEX_A17 (0x080C00FFU)
#define JLINK_CORE_ARM9 (0x09FFFFFFU)
#define JLINK_CORE_ARM9TDMI_S (0x090001FFU)
#define JLINK_CORE_ARM920T (0x092000FFU)
#define JLINK_CORE_ARM922T (0x092200FFU)
#define JLINK_CORE_ARM926EJ_S (0x092601FFU)
#define JLINK_CORE_ARM946E_S (0x094601FFU)
#define JLINK_CORE_ARM966E_S (0x096601FFU)
#define JLINK_CORE_ARM968E_S (0x096801FFU)
#define JLINK_CORE_ARM11 (0x0BFFFFFFU)
#define JLINK_CORE_ARM1136 (0x0B36FFFFU)
#define JLINK_CORE_ARM1136J (0x0B3602FFU)
#define JLINK_CORE_ARM1136J_S (0x0B3603FFU)
#define JLINK_CORE_ARM1136JF (0x0B3606FFU)
#define JLINK_CORE_ARM1136JF_S (0x0B3607FFU)
#define JLINK_CORE_ARM1156 (0x0B56FFFFU)
#define JLINK_CORE_ARM1176 (0x0B76FFFFU)
#define JLINK_CORE_ARM1176J (0x0B7602FFU)
#define JLINK_CORE_ARM1176J_S (0x0B7603FFU)
#define JLINK_CORE_ARM1176JF (0x0B7606FFU)
#define JLINK_CORE_ARM1176JF_S (0x0B7607FFU)
#define JLINK_CORE_CORTEX_R4 (0x0C0000FFU)
#define JLINK_CORE_CORTEX_R5 (0x0C0100FFU)
#define JLINK_CORE_RX (0x0DFFFFFFU)
#define JLINK_CORE_RX610 (0x0D00FFFFU)
#define JLINK_CORE_RX62N (0x0D01FFFFU)
#define JLINK_CORE_RX62T (0x0D02FFFFU)
#define JLINK_CORE_RX63N (0x0D03FFFFU)
#define JLINK_CORE_RX630 (0x0D04FFFFU)
#define JLINK_CORE_RX63T (0x0D05FFFFU)
#define JLINK_CORE_RX210 (0x0D10FFFFU)
#define JLINK_CORE_RX111 (0x0D20FFFFU)
#define JLINK_CORE_RX64M (0x0D30FFFFU)
#define JLINK_CORE_CORTEX_M4 (0x0E0000FFU)
#define JLINK_CORE_CORTEX_M7 (0x0E0100FFU)
#define JLINK_CORE_CORTEX_A5 (0x0F0000FFU)
#define JLINK_CORE_POWER_PC (0x10FFFFFFU)
#define JLINK_CORE_POWER_PC_N1 (0x10FF00FFU)
#define JLINK_CORE_POWER_PC_N2 (0x10FF01FFU)
#define JLINK_CORE_MIPS (0x11FFFFFFU)
#define JLINK_CORE_MIPS_M4K (0x1100FFFFU)
#define JLINK_CORE_MIPS_MICROAPTIV (0x1101FFFFU)
#define JLINK_CORE_EFM8_UNSPEC (0x12FFFFFFU)
#define JLINK_CORE_CIP51 (0x1200FFFFU)
/** @} */

#define JLINKARM_ERR_EMU_NO_CONNECTION         //!<@brief TODO 值未知
#define JLINKARM_ERR_EMU_COMM_ERROR            //!<@brief TODO 值未知
#define JLINKARM_ERR_DLL_NOT_OPEN              //!<@brief TODO 值未知
#define JLINKARM_ERR_VCC_FAILURE               //!<@brief TODO 值未知
#define JLINK_ERR_INVALID_HANDLE               //!<@brief TODO 值未知
#define JLINK_ERR_NO_CPU_FOUND                 //!<@brief TODO 值未知
#define JLINK_ERR_EMU_FEATURE_NOT_SUPPORTED    //!<@brief TODO 值未知
#define JLINK_ERR_EMU_NO_MEMORY                //!<@brief TODO 值未知
#define JLINK_ERR_TIF_STATUS_ERROR             //!<@brief TODO 值未知


typedef struct {
    uint32_t Addr;
    uint32_t Size;
} RAM_AREA_INFO, FLASH_AREA_INFO;

typedef struct {
    uint32_t SizeOfStruct;          //!<@brief Size of the struct.
    char *sName;                    //!<@brief This element holds the name of the device.
    uint32_t CoreId;                //!<@brief This element holds the core id of the device.
    uint32_t FlashAddr;             //!<@brief This element holds the base address of the internal flash of the device.o
    uint32_t RAMAddr;               //!<@brief This element holds the base address of the internal RAM of the device.
    /**
     * 0: Supports only little endian.
     * 1: Supports only big endian.
     * 2: Supports little and big endian.
     */
    char EndianMode;
    uint32_t FlashSize;             //!<@brief Total FLASH size in bytes. Note: Flash may contain gaps. For exact address & size of each region, please refer to aFlashArea .
    uint32_t RAMSize;               //!<@brief Total RAM size in bytes. Note: Ram may contain gaps. For exact address & size of each region, please refer to aRamArea .
    char *sManu;                    //!<@brief Device Manufacturer.
    FLASH_AREA_INFO aFlashArea;     //!<@brief A list of FLASH_AREA_INFO. Region size of 0 bytes marks the end of the list.
    RAM_AREA_INFO aRamArea;         //!<@brief A list of RAM_AREA_INFO. Region size of 0 bytes marks the end of the list.
    uint32_t Core;                  //!<@brief CPU core. (See JLINKARM_Const.h for a list of all core-defines e.g. {@link JLINK_CORE_CORTEX_M3})
} JLINKARM_DEVICE_INFO;

/**
 * TODO 类型不确定
 */
typedef struct {
    uint32_t SizeOfStruct;
    uint32_t Type;
    uint32_t Addr;
    uint32_t AddrMask;
    uint32_t Data;
    uint32_t DataMask;
    uint32_t Access;
    uint32_t AccessMask;
} JLINKARM_DATA_EVENT;


#define JLINK_EVENT_DATA_BP_SIZE_8BIT  //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_SIZE_16BIT //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_SIZE_32BIT //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_DIR_WR     //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_DIR_RD     //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_PRIV       //!<@brief TODO 值未知

#define JLINK_EVENT_DATA_BP_MASK_SIZE  //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_MASK_DIR   //!<@brief TODO 值未知
#define JLINK_EVENT_DATA_BP_MASK_PRIV  //!<@brief TODO 值未知
#define JLINKARM_EVENT_TYPE_DATA_BP    //!<@brief TODO 值未知

#define JLINKARM_EVENT_ERR_UNKNOWN                 //!<@brief TODO 值未知
#define JLINKARM_EVENT_ERR_NO_MORE_EVENTS          //!<@brief TODO 值未知
#define JLINKARM_EVENT_ERR_NO_MORE_ADDR_COMP       //!<@brief TODO 值未知
#define JLINKARM_EVENT_ERR_NO_MORE_DATA_COMP       //!<@brief TODO 值未知
#define JLINKARM_EVENT_ERR_INVALID_ADDR_MASK       //!<@brief TODO 值未知
#define JLINKARM_EVENT_ERR_INVALID_DATA_MASK       //!<@brief TODO 值未知
#define JLINKARM_EVENT_ERR_INVALID_ACCESS_MASK     //!<@brief TODO 值未知

/**
 * TODO 值未知
 */
typedef enum {
    ARM_REG_R0,
    ARM_REG_R1,
    ARM_REG_R2,
    ARM_REG_R3,
    ARM_REG_R4,
    ARM_REG_R5,
    ARM_REG_R6,
    ARM_REG_R7,
    ARM_REG_R15,
    ARM_REG_CPSR,
    ARM_REG_R8_USR,
    ARM_REG_R9_USR,
    ARM_REG_R10_USR,
    ARM_REG_R11_USR,
    ARM_REG_R12_USR,
    ARM_REG_R13_USR,
    ARM_REG_R14_USR,
    ARM_REG_R13_SVC,
    ARM_REG_R14_SVC,
    ARM_REG_SPSR_SVC,
    ARM_REG_R13_ABT,
    ARM_REG_R14_ABT,
    ARM_REG_SPSR_ABT,
    ARM_REG_R13_UND,
    ARM_REG_R14_UND,
    ARM_REG_SPSR_UND,
    ARM_REG_R13_IRQ,
    ARM_REG_R14_IRQ,
    ARM_REG_SPSR_IRQ,
    ARM_REG_R8_FIQ,
    ARM_REG_R9_FIQ,
    ARM_REG_R10_FIQ,
    ARM_REG_R11_FIQ,
    ARM_REG_R12_FIQ,
    ARM_REG_R13_FIQ,
    ARM_REG_R14_FIQ,
    ARM_REG_SPSR_FIQ,
    ARM_NUM_REGS,
} ARM_REG;

typedef struct {
    uint32_t SizeOfStruct;  //!<@brief Size of this structure. This element has to be filled in before calling the API function.
    uint32_t Handle;        //!<@brief Breakpoint handle.
    uint32_t Addr;          //!<@brief Address where breakpoint has been set.
    uint32_t Type;          //!<@brief Type flags which has been specified when the breakpoint was set.
    uint32_t ImpFlags;      //!<@brief Describes the current implementation of the breakpoint. For more information
                            //!<       please refer to Implementation flags below.
    uint32_t UseCnt;        //!<@brief Describes how often the breakpoint is set at the same address.
} JLINKARM_BP_INFO;

typedef struct {
    uint32_t SizeOfStruct;  //!<@brief Size of the struct
    uint32_t Handle;        //!<@brief Watchpoint handle.
    uint32_t Addr;          //!<@brief Contains the address on which watchpoint has been set.
    uint32_t AddrMask;      //!<@brief Contains the address mask used for comparison.
    uint32_t Data;          //!<@brief Contains the data on which watchpoint has been set.
    uint32_t DataMask;      //!<@brief Contains data mask used for comparison.
    uint32_t Ctrl;          //!<@brief Contains the control data on which breakpoint has been set (e.g. read access).
    uint32_t CtrlMask;      //!<@brief Contains the control mask used for comparison.
    uint8_t WPUnit;         //!<@brief Describes the watchpoint index.
} JLINKARM_WP_INFO;

/**
 * TODO 值未知
 */
typedef enum {
    JLINKARM_BP_TYPE_ARM,       //!<@brief Specifies a breakpoint in ARM mode. (Can not be used with JLINKARM_BP_TYPE_THUMB).
    JLINKARM_BP_TYPE_THUMB,     //!<@brief Specifies a breakpoint in THUMB mode. (Can not be used with JLINKARM_BP_TYPE_ARM).
    JLINKARM_BP_IMP_ANY,        //!<@brief Allows any type of implementation, software or any hardware unit.
                                //!< This is the same as specifying JLINKARM_BP_IMP_SW | JLINKARM_BP_IMP_HW and is
                                //!< also default if no Implementation flag is given.
    JLINKARM_BP_IMP_SW,         //!<@brief Allows implementation as software breakpoint if the address is located in RAM or Flash.
    JLINKARM_BP_IMP_SW_RAM,     //!<@brief Allows implementation as software breakpoint if the address is located in RAM.
    JLINKARM_BP_IMP_SW_FLASH,   //!<@brief Allows implementation as software breakpoint if the address is located in Flash.
    JLINKARM_BP_IMP_HW,         //!<@brief Allows using of any hardware breakpoint unit.
} JLINKARM_BP_TYPE;

/**
 * TODO 值未知
 */
enum {
    JLINKARM_HALT_REASON_DBGRQ,              //!<@brief CPU has been halted because DBGRQ signal has been asserted.
    JLINKARM_HALT_REASON_CODE_BREAKPOINT,    //!<@brief CPU has been halted because of code breakpoint match.
    JLINKARM_HALT_REASON_DATA_BREAKPOINT,    //!<@brief CPU has been halted because of data breakpoint match.
    JLINKARM_HALT_REASON_VECTOR_CATCH,       //!<@brief CPU has been halted because of vector catch
};

typedef struct {
    int HaltReason;
    int Index;
} JLINKARM_MOE_INFO;

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
 *
 */
typedef struct {
    uint16_t VTarget;      //!<@brief Target supply voltage.
    const char *sName;     //!<@brief Initials of the memory zone.
    const char *sDesc;     //!<@brief Name of the memory zone.
    uint64_t VirtAddr;     //!<@brief Start address of the virtual address space of the memory zone.
    uint8_t abDummy[16];   //!<@brief Reserved for future use.
} JLINK_MEM_ZONE_INFO;

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

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_DEFINE_H
