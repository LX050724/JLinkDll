/**
 * @file JLinkDLL_Init.h
 * @author yao
 */

#ifndef JLINKDLL_JLINK_INIT_H
#define JLINKDLL_JLINK_INIT_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

#define JLinkDLL_CALLPTR(PTR, ...) ((PTR == NULL) ? \
    (JLinkDLL_Init(NULL) ? PTR(__VA_ARGS__) : (JLinkDLL_Error(__FUNCTION__, __FILE__, __LINE__), PTR(__VA_ARGS__))) : PTR(__VA_ARGS__))

/**
 * 初始化动态加载库
 * @param dl_path JLink共享库路径，传入NULL使用内置共享库
 * @retval 0 失败
 * @retval 1 成功
 */
int JLinkDLL_Init(const char *dl_path);

/**
 * 获取符号，需要先使用{@link JLinkDLL_Init}加载库
 * @param sym 符号名
 * @return 符号指针
 */
void *JLinkDLL_getSym(const char *sym);

/**
 * 释放动态库
 */
int JLinkDLL_DeInit();

/**
 * JLink错误处理函数，该函数会直接退出程序，用户不应调用
 * @param fun_name 出错函数名
 * @param filename 文件名
 * @param line 所在行
 * @return 0
 */
int JLinkDLL_Error(const char *fun_name, const char *filename, int line);

/**
 * 设置调试输出，默认关闭
 * @param enable
 */
void JLinkDLL_SetDebugOutput(int enable);

#ifdef __cplusplus
}
#endif

#endif //JLINKDLL_JLINK_INIT_H
