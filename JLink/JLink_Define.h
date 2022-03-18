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


/**
 * TODO 值不确定，当前肯定是错的
 */
enum {
    JLINK_EVENT_DATA_BP_SIZE_8BIT,
    JLINK_EVENT_DATA_BP_SIZE_16BIT,
    JLINK_EVENT_DATA_BP_SIZE_32BIT,
    JLINK_EVENT_DATA_BP_DIR_WR,
    JLINK_EVENT_DATA_BP_DIR_RD,
    JLINK_EVENT_DATA_BP_PRIV,
};

/**
 * TODO 值不确定
 */
enum {
    JLINKARM_EVENT_ERR_UNKNOWN,
    JLINKARM_EVENT_ERR_NO_MORE_EVENTS,
    JLINKARM_EVENT_ERR_NO_MORE_ADDR_COMP,
    JLINKARM_EVENT_ERR_NO_MORE_DATA_COMP,
    JLINKARM_EVENT_ERR_INVALID_ADDR_MASK,
    JLINKARM_EVENT_ERR_INVALID_DATA_MASK,
    JLINKARM_EVENT_ERR_INVALID_ACCESS_MASK,
};

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

typedef enum {
    JLINKARM_BP_TYPE_ARM,
    JLINKARM_BP_TYPE_THUMB,
    JLINKARM_BP_IMP_ANY,
    JLINKARM_BP_IMP_SW,
    JLINKARM_BP_IMP_SW_RAM,
    JLINKARM_BP_IMP_SW_FLASH,
    JLINKARM_BP_IMP_HW,
} JLINKARM_BP_TYPE;

enum {
    JLINKARM_HALT_REASON_DBGRQ,              //!<@brief CPU has been halted because DBGRQ signal has been asserted.
    JLINKARM_HALT_REASON_CODE_BREAKPOINT,    //!<@brief CPU has been halted because of code breakpoint match.
    JLINKARM_HALT_REASON_DATA_BREAKPOINT,    //!<@brief CPU has been halted because of data breakpoint match.
    JLINKARM_HALT_REASON_VECTOR_CATCH,       //!<@brief CPU has been halted because of vector catch
};

typedef struct {
    int HaltReason;
    int Index;
} JLINK_MEM_ZONE_INFO;

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_DEFINE_H
