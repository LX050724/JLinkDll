#include <iostream>
#include <JLink/JLink.h>

int main() {
    if (JLinkDLL_Init(nullptr)) {
        printf("Load DLL success\n");
        uint32_t version = JLINKARM_GetDLLVersion();
        printf("DLL version %d\n", version);
    } else {
        fprintf(stderr, "Error\n");
    }
    JLinkDLL_DeInit();
    return 0;
}
