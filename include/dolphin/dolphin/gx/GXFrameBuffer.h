#ifndef __GXFRAMEBUFFER_H__
#define __GXFRAMEBUFFER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"
#include "GXStruct.h"

void GXSetCopyClear(GXColor clear_clr, uint32 clear_z);

#ifdef __cplusplus
}
#endif

#endif // __GXFRAMEBUFFER_H__
