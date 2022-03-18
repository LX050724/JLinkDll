//
// Created by yaoji on 2022/3/18.
//

#include "JLink_DeviceSpecific.h"
#include "JLink/JLink_Init.h"

static int (*P_JLINKARM_DEVICE_GetInfo)(int DeviceIndex, JLINKARM_DEVICE_INFO *pDeviceInfo);

int JLINK_GERENAL_DEVICE_SPECIFIC_Init() {
    P_JLINKARM_DEVICE_GetInfo = JLinkDLL_getSym("JLINKARM_DEVICE_GetInfo");
    return P_JLINKARM_DEVICE_GetInfo != NULL;
}

int JLINKARM_DEVICE_GetInfo(int DeviceIndex, JLINKARM_DEVICE_INFO *pDeviceInfo) {
    return P_JLINKARM_DEVICE_GetInfo(DeviceIndex, pDeviceInfo);
}
