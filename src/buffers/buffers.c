#include <ultra64.h>
#include <hvqm2dec.h>

#include "buffers.h"
#ifdef HVQM
#include <hvqm/hvqm.h>
#endif
#include "config.h"

ALIGNED8 u8 gDecompressionHeap[0xD000];
#if defined(VERSION_EU)
ALIGNED16 u8 gAudioHeap[DOUBLE_SIZE_ON_64_BIT(0x31200) - 0x3800];
#elif defined(VERSION_SH)
ALIGNED16 u8 gAudioHeap[DOUBLE_SIZE_ON_64_BIT(0x31200) - 0x4800];
#else
ALIGNED16 u8 gAudioHeap[DOUBLE_SIZE_ON_64_BIT(0x31200  + 0x2C400)];
#endif

ALIGNED8 u8 gIdleThreadStack[0x800];
ALIGNED8 u8 gThread3Stack[0x2000];
ALIGNED8 u8 gThread4Stack[0x2000];
ALIGNED8 u8 gThread5Stack[0x2000];
ALIGNED8 u8 gThread6Stack[0x2000];
// 0x400 bytes
ALIGNED8 u8 gGfxSPTaskStack[SP_DRAM_STACK_SIZE8];
// 0xc00 bytes for f3dex, 0x900 otherwise
ALIGNED8 u8 gGfxSPTaskYieldBuffer[OS_YIELD_DATA_SIZE];
// 0x200 bytes
struct SaveBuffer __attribute__ ((aligned (8))) gSaveBuffer;
// 0x190a0 bytes
struct GfxPool gGfxPools[2];
