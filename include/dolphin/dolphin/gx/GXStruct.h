#ifndef __GXSTRUCT_H__
#define __GXSTRUCT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../vi/vitypes.h"

typedef struct _GXColor
{
    uint8 r, g, b, a;
} GXColor;

typedef struct _GXRenderModeObj
{
    VITVMode viTVmode;
    uint16 fbWidth;
    uint16 efbHeight;
    uint16 xfbHeight;
    uint16 viXOrigin;
    uint16 viYOrigin;
    uint16 viWidth;
    uint16 viHeight;
    VIXFBMode xFBmode;

    uint8 field_rendering;
    uint8 aa;
    uint8 sample_pattern[12][2];
    uint8 vfilter[7];
} GXRenderModeObj;

typedef struct _GXVtxAttrFmtList
{
    GXAttr attr;
    GXCompCnt cnt;
    GXCompType type;
    uint8 frac;
    
} GXVtxAttrFmtList;

#ifdef __cplusplus
}
#endif

#endif