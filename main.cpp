#include <iostream>
#include <JLink/JLink.h>

int main() {
    if (JLinkDLL_Init(nullptr)) {
        printf("Load DLL success\n");
    }
//    uint32_t num;
//    int ret = JLINK_RTTERMINAL_Control(JLINKARM_RTTERMINAL_CMD_GETNUMBUF, &num);
    uint32_t version = JLINKARM_GetDLLVersion();
    printf("%d\n", version);

//    const char *err_msg = JLINKARM_Open();
//    if (err_msg) printf("Error: %s\n", err_msg);

//    for (int i = 0; i < ARM_NUM_REGS; i++)
//        printf("%-2d, %s\n", i, JLINKARM_GetRegisterName(i));

    JLinkDLL_DeInit();
    return 0;
}
