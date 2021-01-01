#include "../Core/x/xEvent.h"
#include "../Core/x/xMemMgr.h"

#include "zGoo.h"

#include <types.h>

extern zGooParams* zgoo_gps;
extern int32 zgoo_ngps;
extern int32 zgoo_nused;

extern float32 lbl_803CEA48; // 0.0f

void zGooInit(int32 nobj)
{
	zgoo_gps = (zGooParams*)xMemAlloc(nobj * sizeof(zGooParams));
	zgoo_ngps = nobj;
}

void zGooExit()
{
	zgoo_gps = NULL;
	zgoo_ngps = 0;
	zgoo_nused = 0;
}

// func_80123794
#pragma GLOBAL_ASM("asm/Game/zGoo.s", "zGooAdd__FP4xEntfi")

// func_80123830
#pragma GLOBAL_ASM("asm/Game/zGoo.s", "zGooIs__FP4xEntRfUi")

// func_801238EC
#pragma GLOBAL_ASM("asm/Game/zGoo.s", "zGooCollsBegin__Fv")

// func_80123998
#pragma GLOBAL_ASM("asm/Game/zGoo.s", "zGooCollsEnd__Fv")

#if 1

// func_80123A20
#pragma GLOBAL_ASM("asm/Game/zGoo.s", "zGooStopTide__Fv")

#else

// Can't figure out loop incrementers.
void zGooStopTide()
{
	int32 i;
	int32 iVar2;

    i = 0;
	iVar2 = 0;
	while (i < zgoo_nused) {
		zEntEvent((xBase*)(zgoo_gps->goo_ent + iVar2), eEventPlatPause, lbl_803CEA48, lbl_803CEA48, lbl_803CEA48, lbl_803CEA48);
		iVar2 = iVar2 + sizeof(zGooParams);
		i++;
	}
}

#endif

// func_80123A90
#pragma GLOBAL_ASM("asm/Game/zGoo.s", "zGooMeltFinished__FP8RpAtomic")
