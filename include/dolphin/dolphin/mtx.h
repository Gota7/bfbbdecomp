#ifndef __MTX_H__
#define __MTX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"
#include "mtx/GeoTypes.h"

void PSMTXIdentity(Mtx m);
void C_MTXOrtho(Mtx44 m, float32 t, float32 b, float32 l, float32 r, float32 n, float32 f);

#ifdef __cplusplus
}
#endif

#endif