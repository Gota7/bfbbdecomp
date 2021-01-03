#ifndef __GXTEV_H__
#define __GXTEV_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"
#include "GXEnum.h"

void GXSetTevOp(GXTevStageID id, GXTevMode mode);
void GXSetNumTevStages(uint8 nStages);
void GXSetTevOrder(GXTevStageID stage, GXTexCoordID coord, GXTexMapID map, GXChannelID color);

#ifdef __cplusplus
}
#endif

#endif