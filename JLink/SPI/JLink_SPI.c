//
// Created by yaoji on 2022/3/20.
//

#include "JLink_SPI.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINK_SPI_Transfer)(const uint8_t *pDataDown, uint8_t *pDataUp, uint32_t NumBits, uint32_t Flags);

int JLINK_SPI_Init() {
    P_JLINK_SPI_Transfer = JLinkDLL_getSym("JLINK_SPI_Transfer");
    return P_JLINK_SPI_Transfer != NULL;
}

int JLINK_SPI_Transfer(const uint8_t *pDataDown, uint8_t *pDataUp, uint32_t NumBits, uint32_t Flags) {
    return P_JLINK_SPI_Transfer(pDataDown, pDataUp, NumBits, Flags);
}
