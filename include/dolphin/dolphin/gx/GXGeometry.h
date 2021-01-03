#ifndef __GXGEOMETRY_H__
#define __GXGEOMETRY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"
#include "GXEnum.h"

void GXSetVtxAttrFmt(GXVtxFmt vtxfmt, GXAttr attr, GXCompCnt cnt, GXCompType type, uint8 frac);
void GXSetVtxAttrFmtv(GXVtxFmt vtxfmt, const GXVtxAttrFmtList *list);

#endif