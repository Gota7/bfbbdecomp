#include "iTRC.h"

#include <types.h>

extern OSHeapHandle __OSCurrHeap;

#if 1

// func_80180038
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "Init__7ROMFontFv")

#else

// The cast near the bottom does not happen, but it must somehow.
void ROMFont::Init()
{
	uint16 enc = OSGetFontEncode();
	enc == 1 ? ROMFont::mFontData = (OSFontHeader*)OSAllocFromHeap(__OSCurrHeap, 0x120f00) : ROMFont::mFontData = (OSFontHeader*)OSAllocFromHeap(__OSCurrHeap, 0x20120);
	OSInitFont(ROMFont::mFontData);
}

#endif

#if 1

// func_80180094
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "InitDisplay__7ROMFontFP16_GXRenderModeObj")

#else

// WIP.
void ROMFont::InitDisplay(_GXRenderModeObj* renderMode)
{
	local_94 = @415;
	mRenderMode__7ROMFont = renderMode;
	RwGameCubeGetXFBs(&mXFBs__7ROMFont,0x803cc0f8);
	mCurrentFrameBuffer__7ROMFont = mXFBs__7ROMFont._4_4_;
	InitGX();
	InitVI();
	local_98 = local_94;
	GXSetCopyClear(&local_98,0xffffff);
	dVar1 = (double)@422;
	uStack28 = (uint)mRenderMode__7ROMFont->ebfHeight;
	uStack20 = (uint)mRenderMode__7ROMFont->fbWidth;
	local_20 = 0x43300000;
	local_18 = 0x43300000;
	C_MTXOrtho(dVar1,(double)(float)((double)CONCAT44(0x43300000,uStack28) - @425),dVar1,
             (double)(float)((double)CONCAT44(0x43300000,uStack20) - @425),dVar1,(double)@423,
             auStack96);
	GXSetProjection(auStack96,1);
	PSMTXIdentity(auStack144);
	GXLoadPosMtxImm(auStack144,0);
	GXSetCurrentMtx(0);
	GXSetZMode(1,7,1);
	GXSetNumChans(0);
	GXSetNumTevStages(1);
	GXSetTevOp(0,3);
	GXSetTevOrder(0,0,0,0xff);
	GXSetBlendMode(1,1,1,0);
	GXClearVtxDesc();
	GXSetVtxDesc(9,1);
	GXSetVtxDesc(0xd,1);
	GXSetVtxAttrFmt(GX_VTXFMT0, 9,1,3,0);
	GXSetVtxAttrFmt(GX_VTXFMT0, 0xd,1,3,0);
}

#endif

// func_80180214
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "InitGX__7ROMFontFv")

// func_80180338
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "InitVI__7ROMFontFv")

// func_80180384
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "RenderBegin__7ROMFontFv")

// func_80180450
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "RenderEnd__7ROMFontFv")

// func_80180498
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SwapBuffers__7ROMFontFv")

// func_80180508
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "DrawCell__7ROMFontFiiii")

// func_801805F4
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "GXEnd")

// func_801805F8
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "GXTexCoord2s16")

// func_80180608
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "GXPosition3s16")

// func_8018061C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "LoadSheet__7ROMFontFPv")

// func_80180708
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "GXSetTexCoordGen")

// func_80180730
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "DrawString__7ROMFontFiiPc")

// func_801807D4
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "GetWidth__7ROMFontFPc")

// func_8018082C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "DrawTextBox__7ROMFontFiiiiPc")

// func_80180920
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "EnableReset__11ResetButtonFv")

// func_8018092C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "DisableReset__11ResetButtonFv")

// func_80180938
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetSndKillFunction__11ResetButtonFPFv_v")

// func_80180940
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "CheckResetButton__11ResetButtonFv")

// func_80180A10
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "Init__8iTRCDiskFv")

// func_80180A30
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetErrorMessage__8iTRCDiskFPCc")

// func_80180A5C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "ResetMessage__8iTRCDiskFv")

// func_80180A8C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetPadStopRumblingFunction__8iTRCDiskFPFv_v")

// func_80180A94
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetSndSuspendFunction__8iTRCDiskFPFv_v")

// func_80180A9C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetSndResumeFunction__8iTRCDiskFPFv_v")

// func_80180AA4
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetSndKillFunction__8iTRCDiskFPFv_v")

// func_80180AAC
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetMovieSuspendFunction__8iTRCDiskFPFv_v")

// func_80180AB4
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetMovieResumeFunction__8iTRCDiskFPFv_v")

// func_80180ABC
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "IsDiskIDed__8iTRCDiskFv")

// func_80180B04
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "DisplayErrorMessage__8iTRCDiskFv")

// func_80180BB4
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "SetDVDState__8iTRCDiskFv")

// func_80180C8C
#pragma GLOBAL_ASM("asm/Core/p2/iTRC.s", "CheckDVDAndResetState__8iTRCDiskFv")
