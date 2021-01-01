#ifndef ZGOO_H
#define ZGOO_H

#include "../Core/x/xEnt.h"
#include "../Core/x/xVec3.h"

#include <types.h>
#include <rwcore.h>
#include <rpworld.h>

struct zGooParams
{
    float32 depth;
    float32 orig_depth;
    xEnt* goo_ent;
};

enum zFXGooState
{
    zFXGooStateNormal,
    zFXGooStateFreezing,
    zFXGooStateFrozen,
    zFXGooStateMelting,
    zFXGooStateInactive = 0xdeadbeef,
    zFXGooStateForce32Bit = 0xffffffff
};

struct zFXGooInstance
{
    RpAtomic* atomic;
    int32 freezeGroup;
    xVec3* orig_verts;
    RwRGBA* orig_colors;
    float32 time;
    float32 timer;
    float32 w0;
    float32 w2;
    float32 warbc[4];
    float32 state_time[4];
    xVec3 center;
    int32 padding; // Padding used for zFXGoo_SceneExit().
    zFXGooState state;
    float32 warb_time;
    float32 alpha;
    float32 min;
    float32 max;
    xVec3* ref_parentPos;
    xVec3 pos_parentOnFreeze;
};

void zGooInit(int32 nobj);
void zGooExit();
int32 zGooAdd(xEnt* obj, float32 depth, int32 freezeGroup);
int32 zGooIs(xEnt* obj, float32& depth, uint32 playerCheck);
void zGooCollsBegin();
void zGooCollsEnd();
void zGooStopTide();
void zGooMeltFinished(RpAtomic* atomic);

#endif