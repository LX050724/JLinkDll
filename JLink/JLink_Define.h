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

//typedef uint8_t U8;
//typedef uint16_t U16;
//typedef uint32_t U32;
//typedef uint64_t U64;

typedef void (*JLINKARM_LOG)(const char *sError);

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


typedef struct AREA_INFO {
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
typedef struct JLINKARM_DATA_EVENT {
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

typedef struct JLINKARM_BP_INFO {
    /** Size of this structure. This element has to be filled in before calling the API function. */
    uint32_t SizeOfStruct;

    /** Breakpoint handle. */
    uint32_t Handle;

    /** Address where breakpoint has been set. */
    uint32_t Addr;

    /** Type flags which has been specified when the breakpoint was set. */
    uint32_t Type;

    /**
     * Describes the current implementation of the breakpoint. For more information
     * please refer to Implementation flags below.
     */
    uint32_t ImpFlags;

    /** Describes how often the breakpoint is set at the same address. */
    uint32_t UseCnt;
} JLINKARM_BP_INFO;

typedef struct JLINKARM_WP_INFO {
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
typedef enum JLINKARM_BP_TYPE {

    /** Specifies a breakpoint in ARM mode. (Can not be used with JLINKARM_BP_TYPE_THUMB). */
    JLINKARM_BP_TYPE_ARM,

    /** Specifies a breakpoint in THUMB mode. (Can not be used with JLINKARM_BP_TYPE_ARM). */
    JLINKARM_BP_TYPE_THUMB,

    /**
     * Allows any type of implementation, software or any hardware unit.
     * This is the same as specifying JLINKARM_BP_IMP_SW | JLINKARM_BP_IMP_HW and is
     * also default if no Implementation flag is given.
     */
    JLINKARM_BP_IMP_ANY,

    /** Allows implementation as software breakpoint if the address is located in RAM or Flash. */
    JLINKARM_BP_IMP_SW,

    /** Allows implementation as software breakpoint if the address is located in RAM. */
    JLINKARM_BP_IMP_SW_RAM,

    /** Allows implementation as software breakpoint if the address is located in Flash. */
    JLINKARM_BP_IMP_SW_FLASH,

    /** Allows using of any hardware breakpoint unit. */
    JLINKARM_BP_IMP_HW,
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

typedef struct JLINKARM_MOE_INFO {
    int HaltReason;
    int Index;
} JLINKARM_MOE_INFO;

typedef struct JLINKARM_EMU_CONNECT_INFO {
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

    /** J-Link via IP only: Hardware version of JLink */
    uint32_t HWVersion;

    /** J-Link via IP only: MAC Addr */
    uint8_t abMACAddr;

    /** J-Link via IP only: Product name */
    char acProduct[32];

    /** J-Link via IP only: Nickname of J-Link */
    char acNickName[32];

    /** J-Link via IP only: Firmware string of JLink */
    char acFWString[112];

    /** J-Link via IP only: Is J-Link configured for IP address reception via DHCP? */
    char IsDHCPAssignedIP;

    /** J-Link via IP only */
    char IsDHCPAssignedIPIsValid;

    /** J-Link via IP only: Number of IP connections which are currently established to this J-Link */
    char NumIPConnections;

    /** J-Link via IP only */
    char NumIPConnectionsIsValid;

    /** Dummy bytes to pad the structure size to 264 bytes. Reserved for future use. */
    char aPadding[34];
} JLINKARM_EMU_CONNECT_INFO;


// 弃用结构体，结构未知
//typedef struct JLINKARM_EMU_INFO {
//
//} JLINKARM_EMU_INFO;

/**
 *
 */
typedef struct JLINK_MEM_ZONE_INFO {
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

typedef struct JLINKARM_JTAG_DEVICE_CONF {
    uint32_t SizeofStruct;
    uint32_t IRLen;
    uint32_t IRPrint;
    uint32_t Id;
    const char *sName;
} JLINKARM_JTAG_DEVICE_CONF;

typedef struct JLINKARM_JTAG_DEVICE_INFO {
    const char *sName;
    uint32_t IRLen;
    uint32_t IRPrint;
} JLINKARM_JTAG_DEVICE_INFO;

/**
 * This structure is used to configure SWO when calling the {@link JLINKARM_SWO_Control} function
 * with command JLINKARM_SWO_CMD_START.
 */
typedef struct JLINKARM_SWO_START_INFO {
    /**
     * Size of structure. This value must be filled by the application
     * and is used to allow future extension of the structure
     */
    uint32_t SizeofStruct;

    /** Specifies the interface type to be used for SWO. */
    uint32_t Interface;

    /** Selects the frequency used for SWO communication in Hz. */
    uint32_t Speed;
} JLINKARM_SWO_START_INFO;

/**
 * This structure is used to retrieve information about the supported SWO speeds.
 */
typedef struct JLINKARM_SWO_SPEED_INFO {
    /**
     * Size of structure. This value must be filled by the application
     * and is used to allow future extension of the structure.
     */
    uint32_t SizeofStruct;

    /**
     * Specifies the interface type for which the speed information
     * should be retrieved.
     */
    uint32_t Interface;

    /** Base frequency (in Hz) used to calculate supported SWO speeds. */
    uint32_t BaseFreq;

    /** Minimum divider allowed to divide the base frequency. */
    uint32_t MinDiv;

    /** Maximum divider allowed to divide the base frequency. */
    uint32_t MaxDiv;

    /** Minimum prescaler allowed to adjust the base frequency. */
    uint32_t MinPrescale;

    /** Maximum prescaler allowed to adjust the base frequency. */
    uint32_t MaxPrescale;
} JLINKARM_SWO_SPEED_INFO;

#define JLINKARM_SWO_IF_UART //!<@brief Selects UART encoding. TODO 值未知

/**
 * Starts collecting SWO data.
 * pData is a pointer to a structure of type
 * JLINKARM_SWO_START_INFO. For more detailed information please refer to JLINKARM_SWO_START_INFO on page 262.
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_START

/**
 * Stops collecting SWO data.
 * pData is not used.
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_STOP

/**
 * Flushes data from the SWO buffer. After this operation,
 * the flushed part of the SWO buffer is empty.
 * pData is a pointer to an uint32_t value containing the number of bytes to be flushed.
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_FLUSH

/**
 * Retrieves information about the supported SWO speeds.
 * pData is a pointer to a structure of type JLINKARM_SWO_SPEED_INFO.
 * @see JLINKARM_SWO_SPEED_INFO
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_GET_SPEED_INFO

/**
 * Returns the number of bytes in the SWO buffer.
 * pData is not used.
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_GET_NUM_BYTES

/**
 * Sets the size of buffer used by the host to collect SWO data.
 * By default this value is set to 4MB.
 * pData is a pointer to an uint32_t value containing the new buffersize.
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_SET_BUFFERSIZE_HOST

/**
 * Sets the size of buffer used by the emulator to collect SWO data.
 * By default this value is set to 4KB.
 * pData is a pointer to an uint32_t value containing the new buffersize.
 * TODO 值未知
 */
#define JLINKARM_SWO_CMD_SET_BUFFERSIZE_EMU

typedef struct JLINK_RTTERMINAL_START {
    /** Address of RTT block */
    uint32_t ConfigBlockAddress;
    uint32_t Dummy0;
    uint32_t Dummy1;
    uint32_t Dummy2;
} JLINK_RTTERMINAL_START;

typedef struct JLINK_RTTERMINAL_STOP {
    /** If set, RTTCB will be invalidated on target. */
    uint8_t InvalidateTargetCB;
    uint8_t acDummy[3];
    uint32_t Dummy0;
    uint32_t Dummy1;
    uint32_t Dummy2;
} JLINK_RTTERMINAL_STOP;

typedef struct JLINK_RTTERMINAL_BUFDESC {
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

#define JLINKARM_DEV_FAMILY_CM0             //!<@brief Target CPU/MCU is a Cortex-M0 device. TODO 值未知
#define JLINKARM_DEV_FAMILY_CM1             //!<@brief Target CPU/MCU is a Cortex-M1 device. TODO 值未知
#define JLINKARM_DEV_FAMILY_CM3             //!<@brief Target CPU/MCU is a Cortex-M3 device. TODO 值未知
#define JLINKARM_DEV_FAMILY_CORTEX_R4       //!<@brief Target CPU/MCU is an Cortex-R4 core. TODO 值未知
#define JLINKARM_DEV_FAMILY_SIM             //!<@brief Target CPU/MCU simulator. TODO 值未知
#define JLINKARM_DEV_FAMILY_XSCALE          //!<@brief Target CPU/MCU is a XScale device. TODO 值未知
#define JLINKARM_DEV_FAMILY_ARM7            //!<@brief Target CPU/MCU is an ARM7 device. TODO 值未知
#define JLINKARM_DEV_FAMILY_ARM9            //!<@brief Target CPU/MCU is a ARM9 device. TODO 值未知
#define JLINKARM_DEV_FAMILY_ARM10           //!<@brief Target CPU/MCU is a ARM10 device. TODO 值未知
#define JLINKARM_DEV_FAMILY_ARM11           //!<@brief Target CPU/MCU is an ARM11 core. TODO 值未知

typedef struct JLINKARM_DEVICE_SELECT_INFO {
    /** Size of this structure. This element has to be filled in before calling the API function. */
    uint32_t SizeOfStruct;

    /** Will be set to the core index selected by the user (default 0). */
    uint32_t CoreIndex;
} JLINKARM_DEVICE_SELECT_INFO;


/** Measured state of pin is low (logical 0). */
#define JLINKARM_HW_PIN_STATUS_LOW

/** Measured state of pin is high (logical 1). */
#define JLINKARM_HW_PIN_STATUS_HIGH

/** Pin state could not be measured. Measuring JTAG pin state is not supported by JLink / J-Trace. */
#define JLINKARM_HW_PIN_STATUS_UNKNOWN

typedef struct JLINKARM_HW_STATUS {
    /** Target supply voltage. */
    uint16_t VTarget;

    /** Measured state of TCK pin. The valid values for the pin state are described below. */
    uint8_t tck;

    /** Measured state of TDI pin. The valid values for the pin state are described below. */
    uint8_t tdi;

    /** Measured state of TDO pin. The valid values for the pin state are described below. */
    uint8_t tdo;

    /** Measured state of TMS pin. The valid values for the pin state are described below. */
    uint8_t tms;

    /** Measured state of TRES pin. The valid values for the pin state are described below. */
    uint8_t tres;

    /** Measured state of TRST pin. The valid values for the pin state are described below. */
    uint8_t trst;
} JLINKARM_HW_STATUS;

typedef struct JTAG_ID_DATA {
    /** Number of devices in this scan chain */
    int NumDevices;

    /** Total Number of bits in all scan chain select registers */
    uint16_t ScanLen;

    /** JTAG ID of device */
    uint32_t aId[3];

    /** Number of bits in individual scan chain select registers */
    uint8_t aScanLen[3];

    /** Data read back from instruction register */
    uint8_t aIrRead[3];

    /** Data read back from scan chain select register */
    uint8_t aScanRead[3];
} JTAG_ID_DATA;

typedef struct JLINKARM_SPEED_INFO {

    /** Size of this structure. This element has to be filled in before calling the API function. */
    uint32_t SizeOfStruct;

    /** Base frequency (in Hz) used to calculate supported target interface speeds. */
    uint32_t BaseFreq;

    /** Minimum divider allowed to divide the base frequency. */
    uint16_t MinDiv;

    /** Indicates whether the emulator supports adaptive clocking or not. */
    uint16_t SupportAdaptive;
} JLINKARM_SPEED_INFO;

typedef struct JLINK_HSS_MEM_BLOCK_DESC {
    /** Address that shall be read from when sampling. */
    uint32_t Addr;

    /** Number of bytes that shall be read when sampling. */
    uint32_t NumBytes;

    /** SBZ. Reserved for future use. */
    uint32_t Flags;

    /** SBZ. Reserved for future use. */
    uint32_t Dummy;
} JLINK_HSS_MEM_BLOCK_DESC;

/** Setup the POWERTRACE functionality. */
#define JLINK_POWERTRACE_CMD_SETUP

/** Starts capturing measurement data. */
#define JLINK_POWERTRACE_CMD_START

/** Flush POWERTRACE data buffer. Any data which has not been read is lost. */
#define JLINK_POWERTRACE_CMD_FLUSH

/** Stops capturing measurement data. */
#define JLINK_POWERTRACE_CMD_STOP

/** Get POWERTRACE capabilities of the connected emulator. */
#define JLINK_POWERTRACE_CMD_GET_CAPS

/** Get capabilities of a specific measurement channel. */
#define JLINK_POWERTRACE_CMD_GET_CHANNEL_CAPS

/** Get the number of POWERTRACE items which are available to read. */
#define JLINK_POWERTRACE_CMD_GET_NUM_ITEMS

typedef struct JLINK_POWERTRACE_SETUP {
    /**
     * Size of this structure. Needs to be filled by
     * the user. Used for backward-compatibility
     * if the structure is enhanced in future versions.
     */
    int SizeofStruct;

    /**
     * Bitmask to setup which channels shall be
     * enabled for capturing data.
     *
     *  - Bits 0-7: Internal channel 0-7
     *
     *  - Bits 8-31: Reserved
     *
     * If a bit is 1, the corresponding channel is enabled.
     * If it is set to 0, the corresponding channel is disabled.
     */
    uint32_t ChannelMask;

    /**
     * Sampling frequency in Hz. Please note that
     * the maximum sample frequency which can
     * be used depends on the number of channels which are enabled.
     * For more information about how to determine the maximum sampling
     * frequency for your configuration
     * @see JLINK_POWERTRACE_CMD_GET_CHANNEL_CAPS
     */
    uint32_t SampleFreq;

    /**
     * Reference value which shall be stored for
     * every sampled value.
     *
     * 0: No reference value is stored
     *
     * 1: Number of bytes transferred via SWO
     * since capturing has been started. Only
     * available for ARM Cortex-M devices which
     * support SWO.
     *
     * 2: Number of miliseconds elapsed, since
     * powertrace capturing has been started.
     */
    int RefSelect;

    /**
     * Capturing enable condition.
     *
     * 0: Data is always captured, even if the CPU is halted. Capturing is only
     *    stopped when receiving a JLINK_POWERTRACE_CMD_STOP command.
     *
     * 1: Data is only captured while the CPU is running
     */
    int EnableCond;
} JLINK_POWERTRACE_SETUP;

typedef struct JLINK_POWERTRACE_DATA_ITEM {
    /**
     * Reference value (can be used to correlate
     * the measured value to the time when it
     * has been measured), if enabled. For more
     * information about how to setup the POWERTRACE functionality to store a reference value,
     * @see JLINK_POWERTRACE_CMD_SETUP
     */
    uint32_t RefValue;

    /**
     * Measured data.
     * Reserved for future use. Currently 0.
     */
    uint32_t Data;
} JLINK_POWERTRACE_DATA_ITEM;

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_DEFINE_H
