/**
 * @file JLink_DeviceSpecific.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_DEVICESPECIFIC_H
#define JLINKDLL_JLINK_DEVICESPECIFIC_H

#include <stdint.h>
#include <JLink/JLink_Define.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * This function can be used to acquire information about which devices are supported by
 * the J-Link DLL. Moreover, more detailed information for a specific device can be acquired
 * (CoreId, Flash addr, ...).
 * @param DeviceIndex Index of device for which information is acquired.
 * @param pDeviceInfo Pointer to structure variable which is used to hold information for the
 *                    specified device.
 * @return Number of devices which are supported by the J-Link DLL.
 */
int JLINKARM_DEVICE_GetInfo(int DeviceIndex, JLINKARM_DEVICE_INFO *pDeviceInfo);


#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_DEVICESPECIFIC_H
