#ifndef ZSCRIPT_H
#define ZSCRIPT_H

#include <types.h>
#include "../Core/x/xBase.h"
#include "../Core/x/xDynAsset.h"
#include "../Core/x/xScene.h"

struct xScriptAsset : xBaseAsset
{
    float32 scriptStartTime;
    uint32 eventCount;
};

struct zScript : xBase
{
    xScriptAsset* tasset;
    uint8 state;
    uint8 more;
    uint8 pad[2];
    float32 time;
};

void zScriptInit(void* data, void* asset);
void zScriptInit(xBase* data, xScriptAsset* asset);
void zScriptReset(zScript* script);
void zScript_Save(zScript* script, xSerial* s);
void zScript_Load(zScript* script, xSerial* s);
int32 zScriptEventCB(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* b3);
void zScriptExecuteEvents(zScript* t, float32 start, float32 end);
void zScriptUpdate(xBase* to, xScene* scene, float32 dt);

#endif