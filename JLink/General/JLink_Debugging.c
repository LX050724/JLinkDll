//
// Created by yaoji on 2022/3/18.
//

#include "JLink_Debugging.h"
#include <JLink/JLink_Init.h>

static int (*P_JLINKARM_ClrWP)(int WPHandle);
static int (*P_JLINKARM_ClrDataEvent)(uint32_t Handle);
static void (*P_JLINKARM_ClrBP)(unsigned int BPIndex);
static int (*P_JLINKARM_ClrBPEx)(int BPHandle);
static int (*P_JLINKARM_SetDataEvent)(JLINKARM_DATA_EVENT *pEvent, uint32_t *pHandle);
static uint32_t (*P_JLINKARM_CORE_GetFound)(void);
static void (*P_JLINKARM_EnableSoftBPs)(char Enable);
static int (*P_JLINKARM_FindBP)(uint32_t Addr);
static uint32_t (*P_JLINKARM_GetBPInfo)(int BPHandle);
static unsigned (*P_JLINKARM_GetNumBPs)(void);
static int (*P_JLINKARM_GetBPInfoEx)(int iBP, JLINKARM_BP_INFO *pInfo);
static unsigned (*P_JLINKARM_GetNumWPs)(void);
static int (*P_JLINKARM_GetNumBPUnits)(JLINKARM_BP_TYPE Type);
static int (*P_JLINKARM_GetNumWPUnits)(void);
static int (*P_JLINKARM_GetRegisterList)(uint32_t *paList, int MaxNumItems);
static const char *(*P_JLINKARM_GetRegisterName)(uint32_t RegIndex);
static int (*P_JLINKARM_GetWPInfoEx)(int iWP, JLINKARM_WP_INFO *pInfo);
static void (*P_JLINKARM_GoAllowSim)(uint32_t NumInsts);
static int (*P_JLINKARM_ReadCodeMem)(uint32_t Addr, uint32_t NumBytes, void *pData);
static uint32_t (*P_JLINKARM_ReadICEReg)(int RegIndex);
static uint32_t (*P_JLINKARM_ReadReg)(ARM_REG RegIndex);
static int (*P_JLINKARM_ReadRegs)(const uint32_t *paRegIndex, uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs);
static int (*P_JLINKARM_ReadTerminal)(uint8_t *pBuffer, uint32_t BufferSize);
static char (*P_JLINKARM_SimulateInstruction)(uint32_t Inst);
static void (*P_JLINKARM_SetBP)(unsigned BPIndex, uint32_t Addr);
static int (*P_JLINKARM_SetBPEx)(uint32_t Addr, uint32_t TypeFlags);
static int (*P_JLINKARM_SetDataEvent)(JLINKARM_DATA_EVENT *pEvent, uint32_t *pHandle);
static char (*P_JLINKARM_Step)(void);
static char (*P_JLINKARM_StepComposite)(void);
static int (*P_JLINKARM_WaitForHalt)(int TimeOut);
static void (*P_JLINKARM_WriteICEReg)(int RegIndex, uint32_t Value, int AllowDelay);
static char (*P_JLINKARM_WriteReg)(ARM_REG RegIndex, uint32_t Data);
static int (*P_JLINKARM_WriteRegs)(const uint32_t *paRegIndex, const uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs);
static int (*P_JLINKARM_WriteVectorCatch)(uint32_t Value);
static int (*P_JLINKARM_ReadDCC)(uint32_t *pData, uint32_t NumItems, int TimeOut);
static void (*P_JLINKARM_ReadDCCFast)(uint32_t *pData, uint32_t NumItems);
static int (*P_JLINKARM_WaitDCCRead)(int TimeOut);
static int (*P_JLINKARM_WriteDCC)(const uint32_t *pData, uint32_t NumItems, int TimeOut);
static void (*P_JLINKARM_WriteDCCFast)(const uint32_t *pData, uint32_t NumItems);

int JLINK_GERENAL_DEBUGGING_Init() {
    P_JLINKARM_ClrWP = JLinkDLL_getSym("JLINKARM_ClrWP");
    if (P_JLINKARM_ClrWP == NULL) return 0;
    P_JLINKARM_ClrDataEvent = JLinkDLL_getSym("JLINKARM_ClrDataEvent");
    if (P_JLINKARM_ClrDataEvent == NULL) return 0;
    P_JLINKARM_ClrBP = JLinkDLL_getSym("JLINKARM_ClrBP");
    if (P_JLINKARM_ClrBP == NULL) return 0;
    P_JLINKARM_ClrBPEx = JLinkDLL_getSym("JLINKARM_ClrBPEx");
    if (P_JLINKARM_ClrBPEx == NULL) return 0;
    P_JLINKARM_SetDataEvent = JLinkDLL_getSym("JLINKARM_SetDataEvent");
    if (P_JLINKARM_SetDataEvent == NULL) return 0;
    P_JLINKARM_CORE_GetFound = JLinkDLL_getSym("JLINKARM_CORE_GetFound");
    if (P_JLINKARM_CORE_GetFound == NULL) return 0;
    P_JLINKARM_EnableSoftBPs = JLinkDLL_getSym("JLINKARM_EnableSoftBPs");
    if (P_JLINKARM_EnableSoftBPs == NULL) return 0;
    P_JLINKARM_FindBP = JLinkDLL_getSym("JLINKARM_FindBP");
    if (P_JLINKARM_FindBP == NULL) return 0;
    P_JLINKARM_GetBPInfo = JLinkDLL_getSym("JLINKARM_GetBPInfo");
    if (P_JLINKARM_GetBPInfo == NULL) return 0;
    P_JLINKARM_GetNumBPs = JLinkDLL_getSym("JLINKARM_GetNumBPs");
    if (P_JLINKARM_GetNumBPs == NULL) return 0;
    P_JLINKARM_GetBPInfoEx = JLinkDLL_getSym("JLINKARM_GetBPInfoEx");
    if (P_JLINKARM_GetBPInfoEx == NULL) return 0;
    P_JLINKARM_GetNumWPs = JLinkDLL_getSym("JLINKARM_GetNumWPs");
    if (P_JLINKARM_GetNumWPs == NULL) return 0;
    P_JLINKARM_GetNumBPUnits = JLinkDLL_getSym("JLINKARM_GetNumBPUnits");
    if (P_JLINKARM_GetNumBPUnits == NULL) return 0;
    P_JLINKARM_GetNumWPUnits = JLinkDLL_getSym("JLINKARM_GetNumWPUnits");
    if (P_JLINKARM_GetNumWPUnits == NULL) return 0;
    P_JLINKARM_GetRegisterList = JLinkDLL_getSym("JLINKARM_GetRegisterList");
    if (P_JLINKARM_GetRegisterList == NULL) return 0;
    P_JLINKARM_GetRegisterName = JLinkDLL_getSym("JLINKARM_GetRegisterName");
    if (P_JLINKARM_GetRegisterName == NULL) return 0;
    P_JLINKARM_GetWPInfoEx = JLinkDLL_getSym("JLINKARM_GetWPInfoEx");
    if (P_JLINKARM_GetWPInfoEx == NULL) return 0;
    P_JLINKARM_GoAllowSim = JLinkDLL_getSym("JLINKARM_GoAllowSim");
    if (P_JLINKARM_GoAllowSim == NULL) return 0;
    P_JLINKARM_ReadCodeMem = JLinkDLL_getSym("JLINKARM_ReadCodeMem");
    if (P_JLINKARM_ReadCodeMem == NULL) return 0;
    P_JLINKARM_ReadICEReg = JLinkDLL_getSym("JLINKARM_ReadICEReg");
    if (P_JLINKARM_ReadICEReg == NULL) return 0;
    P_JLINKARM_ReadReg = JLinkDLL_getSym("JLINKARM_ReadReg");
    if (P_JLINKARM_ReadReg == NULL) return 0;
    P_JLINKARM_ReadRegs = JLinkDLL_getSym("JLINKARM_ReadRegs");
    if (P_JLINKARM_ReadRegs == NULL) return 0;
    P_JLINKARM_ReadTerminal = JLinkDLL_getSym("JLINKARM_ReadTerminal");
    if (P_JLINKARM_ReadTerminal == NULL) return 0;
    P_JLINKARM_SimulateInstruction = JLinkDLL_getSym("JLINKARM_SimulateInstruction");
    if (P_JLINKARM_SimulateInstruction == NULL) return 0;
    P_JLINKARM_SetBP = JLinkDLL_getSym("JLINKARM_SetBP");
    if (P_JLINKARM_SetBP == NULL) return 0;
    P_JLINKARM_SetBPEx = JLinkDLL_getSym("JLINKARM_SetBPEx");
    if (P_JLINKARM_SetBPEx == NULL) return 0;
    P_JLINKARM_SetDataEvent = JLinkDLL_getSym("JLINKARM_SetDataEvent");
    if (P_JLINKARM_SetDataEvent == NULL) return 0;
    P_JLINKARM_Step = JLinkDLL_getSym("JLINKARM_Step");
    if (P_JLINKARM_Step == NULL) return 0;
    P_JLINKARM_StepComposite = JLinkDLL_getSym("JLINKARM_StepComposite");
    if (P_JLINKARM_StepComposite == NULL) return 0;
    P_JLINKARM_WaitForHalt = JLinkDLL_getSym("JLINKARM_WaitForHalt");
    if (P_JLINKARM_WaitForHalt == NULL) return 0;
    P_JLINKARM_WriteICEReg = JLinkDLL_getSym("JLINKARM_WriteICEReg");
    if (P_JLINKARM_WriteICEReg == NULL) return 0;
    P_JLINKARM_WriteReg = JLinkDLL_getSym("JLINKARM_WriteReg");
    if (P_JLINKARM_WriteReg == NULL) return 0;
    P_JLINKARM_WriteRegs = JLinkDLL_getSym("JLINKARM_WriteRegs");
    if (P_JLINKARM_WriteRegs == NULL) return 0;
    P_JLINKARM_WriteVectorCatch = JLinkDLL_getSym("JLINKARM_WriteVectorCatch");
    if (P_JLINKARM_WriteVectorCatch == NULL) return 0;
    P_JLINKARM_ReadDCC = JLinkDLL_getSym("JLINKARM_ReadDCC");
    if (P_JLINKARM_ReadDCC == NULL) return 0;
    P_JLINKARM_ReadDCCFast = JLinkDLL_getSym("JLINKARM_ReadDCCFast");
    if (P_JLINKARM_ReadDCCFast == NULL) return 0;
    P_JLINKARM_WaitDCCRead = JLinkDLL_getSym("JLINKARM_WaitDCCRead");
    if (P_JLINKARM_WaitDCCRead == NULL) return 0;
    P_JLINKARM_WriteDCC = JLinkDLL_getSym("JLINKARM_WriteDCC");
    if (P_JLINKARM_WriteDCC == NULL) return 0;
    P_JLINKARM_WriteDCCFast = JLinkDLL_getSym("JLINKARM_WriteDCCFast");
    if (P_JLINKARM_WriteDCCFast == NULL) return 0;
    return 1;
}

int JLINKARM_ClrWP(int WPHandle) {
    return P_JLINKARM_ClrWP(WPHandle);
}

int JLINKARM_ClrDataEvent(uint32_t Handle) {
    return P_JLINKARM_ClrDataEvent(Handle);
}

void JLINKARM_ClrBP(unsigned int BPIndex) {
    P_JLINKARM_ClrBP(BPIndex);
}

int JLINKARM_ClrBPEx(int BPHandle) {
    return P_JLINKARM_ClrBPEx(BPHandle);
}

uint32_t JLINKARM_CORE_GetFound(void) {
    return P_JLINKARM_CORE_GetFound();
}

void JLINKARM_EnableSoftBPs(char Enable) {
    P_JLINKARM_EnableSoftBPs(Enable);
}

int JLINKARM_FindBP(uint32_t Addr) {
    return P_JLINKARM_FindBP(Addr);
}

uint32_t JLINKARM_GetBPInfo(int BPHandle) {
    return P_JLINKARM_GetBPInfo(BPHandle);
}

unsigned JLINKARM_GetNumBPs(void) {
    return P_JLINKARM_GetNumBPs();
}

int JLINKARM_GetBPInfoEx(int iBP, JLINKARM_BP_INFO *pInfo) {
    return P_JLINKARM_GetBPInfoEx(iBP, pInfo);
}

unsigned JLINKARM_GetNumWPs(void) {
    return P_JLINKARM_GetNumWPs();
}

int JLINKARM_GetNumBPUnits(JLINKARM_BP_TYPE Type) {
    return P_JLINKARM_GetNumBPUnits(Type);
}

int JLINKARM_GetNumWPUnits(void) {
    return P_JLINKARM_GetNumWPUnits();
}

int JLINKARM_GetRegisterList(uint32_t *paList, int MaxNumItems) {
    return P_JLINKARM_GetRegisterList(paList, MaxNumItems);
}

const char *JLINKARM_GetRegisterName(uint32_t RegIndex) {
    return P_JLINKARM_GetRegisterName(RegIndex);
}

int JLINKARM_GetWPInfoEx(int iWP, JLINKARM_WP_INFO *pInfo) {
    return P_JLINKARM_GetWPInfoEx(iWP, pInfo);
}

void JLINKARM_GoAllowSim(uint32_t NumInsts) {
     P_JLINKARM_GoAllowSim(NumInsts);
}

int JLINKARM_ReadCodeMem(uint32_t Addr, uint32_t NumBytes, void *pData) {
    return P_JLINKARM_ReadCodeMem(Addr, NumBytes, pData);
}

uint32_t JLINKARM_ReadICEReg(int RegIndex) {
    return P_JLINKARM_ReadICEReg(RegIndex);
}

uint32_t JLINKARM_ReadReg(ARM_REG RegIndex) {
    return P_JLINKARM_ReadReg(RegIndex);
}

int JLINKARM_ReadRegs(const uint32_t *paRegIndex, uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs) {
    return P_JLINKARM_ReadRegs(paRegIndex, paData, paStatus, NumRegs);
}

int JLINKARM_ReadTerminal(uint8_t *pBuffer, uint32_t BufferSize) {
    return P_JLINKARM_ReadTerminal(pBuffer, BufferSize);
}

char JLINKARM_SimulateInstruction(uint32_t Inst) {
    return P_JLINKARM_SimulateInstruction(Inst);
}

void JLINKARM_SetBP(uint32_t BPIndex, uint32_t Addr) {
     P_JLINKARM_SetBP(BPIndex, Addr);
}

int JLINKARM_SetBPEx(uint32_t Addr, uint32_t TypeFlags) {
    return P_JLINKARM_SetBPEx(Addr, TypeFlags);
}

int JLINKARM_SetDataEvent(JLINKARM_DATA_EVENT *pEvent, uint32_t *pHandle) {
    return P_JLINKARM_SetDataEvent(pEvent, pHandle);
}

char JLINKARM_Step(void) {
    return P_JLINKARM_Step();
}

char JLINKARM_StepComposite(void) {
    return P_JLINKARM_StepComposite();
}

int JLINKARM_WaitForHalt(int TimeOut) {
    return P_JLINKARM_WaitForHalt(TimeOut);
}

void JLINKARM_WriteICEReg(int RegIndex, uint32_t Value, int AllowDelay) {
     P_JLINKARM_WriteICEReg(RegIndex, Value, AllowDelay);
}

char JLINKARM_WriteReg(ARM_REG RegIndex, uint32_t Data) {
    return P_JLINKARM_WriteReg(RegIndex, Data);
}

int JLINKARM_WriteRegs(const uint32_t *paRegIndex, const uint32_t *paData, uint8_t *paStatus, uint32_t NumRegs) {
    return P_JLINKARM_WriteRegs(paRegIndex, paData, paStatus, NumRegs);
}

int JLINKARM_WriteVectorCatch(uint32_t Value) {
    return P_JLINKARM_WriteVectorCatch(Value);
}

int JLINKARM_ReadDCC(uint32_t *pData, uint32_t NumItems, int TimeOut) {
    return P_JLINKARM_ReadDCC(pData, NumItems, TimeOut);
}

void JLINKARM_ReadDCCFast(uint32_t *pData, uint32_t NumItems) {
     P_JLINKARM_ReadDCCFast(pData, NumItems);
}

int JLINKARM_WaitDCCRead(int TimeOut) {
    return P_JLINKARM_WaitDCCRead(TimeOut);
}

int JLINKARM_WriteDCC(const uint32_t *pData, uint32_t NumItems, int TimeOut) {
    return P_JLINKARM_WriteDCC(pData, NumItems, TimeOut);
}

void JLINKARM_WriteDCCFast(const uint32_t *pData, uint32_t NumItems) {
     P_JLINKARM_WriteDCCFast(pData, NumItems);
}

