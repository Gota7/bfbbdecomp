#ifndef __OSALLOC_H__
#define __OSALLOC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"

typedef int32 OSHeapHandle;

void* OSAllocFromHeap(OSHeapHandle heap, uint32 size);
void OSFreeToHeap(OSHeapHandle heap, void* ptr);

#ifdef __cplusplus
}
#endif

#endif