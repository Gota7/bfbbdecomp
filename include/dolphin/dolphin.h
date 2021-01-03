#ifndef __DOLPHIN_H__
#define __DOLPHIN_H__

#include "dolphin/types.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "dolphin/os.h"
#include "dolphin/vi.h"

extern "C" {
void PADInit();
void PADControlMotor(int32 chan, uint32 command);
}

#endif