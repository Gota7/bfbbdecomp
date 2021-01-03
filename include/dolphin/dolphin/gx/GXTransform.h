#ifndef __GXTRANSFORM_H__
#define __GXTRANSFORM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"
#include "GXEnum.h"

void GXSetProjection(const float32 mtx[4][4], GXProjectionType type);
void GXLoadPosMtxImm(const float32 mtx[3][4], uint32 id);
void GXSetCurrentMtx(uint32 id);

#ifdef __cplusplus
}
#endif

#endif