/**
 * @file JLink_SPI.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_SPI_H
#define JLINKDLL_JLINK_SPI_H

#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif

int JLINK_SPI_Transfer(const uint8_t* pDataDown, uint8_t* pDataUp, uint32_t NumBits, uint32_t Flags);

#ifdef __cplusplus
};
#endif

#endif //JLINKDLL_JLINK_SPI_H
