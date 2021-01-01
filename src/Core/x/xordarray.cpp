#include "xordarray.h"
#include "xMemMgr.h"

#include <types.h>

// func_80035A00
#pragma GLOBAL_ASM("asm/Core/x/xordarray.s", "XOrdInit__FP16st_XORDEREDARRAYii")

void XOrdReset(st_XORDEREDARRAY* array)
{
    array->cnt = 0;
}

void XOrdDone(st_XORDEREDARRAY* array, int32 wasTempAlloc)
{
    if ((array->max != 0) && (wasTempAlloc != 0))
    {
        xMemPopTemp(array->list);
    }
    array->list = NULL;
    array->cnt = 0;
    array->max = 0;
    array->warnlvl = 0;
}

void XOrdAppend(st_XORDEREDARRAY* array, void* elt)
{
    if (array->cnt >= array->max)
    {
        return;
    }
    array->list[array->cnt++] = elt;
}

#if 1

// func_80035B58
#pragma GLOBAL_ASM("asm/Core/x/xordarray.s", "XOrdInsert__FP16st_XORDEREDARRAYPvPFPvPv_i")

#else

void XOrdInsert(st_XORDEREDARRAY* array, void* elt, int32 (*compare)(const void*, void*))
{
    if (array->cnt < array->max)
    {
        array->cnt = array->cnt + 1;
        iVar3 = array->cnt - 1;
        iVar4 = iVar3 * 4;
        while (0 < iVar3)
        {
            iVar1 = (*compare)(*(void**)((int)array->list + iVar4 + -4), elt);
            if (iVar1 < 1)
            {
                array->list[iVar3] = elt;
                return;
            }
            iVar3 = iVar3 + -1;
            puVar2 = (undefined4*)((int)array->list + iVar4);
            iVar4 = iVar4 + -4;
            *puVar2 = puVar2[-1];
        }
        *array->list = elt;
    }
}

#endif

// func_80035C0C
#pragma GLOBAL_ASM("asm/Core/x/xordarray.s", "XOrdRemove__FP16st_XORDEREDARRAYPvi")

#if 1

// func_80035CF4
#pragma GLOBAL_ASM("asm/Core/x/xordarray.s", "XOrdLookup__FP16st_XORDEREDARRAYPCvPFPCvPv_i")

#else

int32 XOrdLookup(st_XORDEREDARRAY* array, void* key, int32 (*test)(const void*, void*))
{
    int32 v;
    int32 index;
    int32 rightBound;
    int32 leftBound;

    index = array->cnt;
	leftBound = 0;
    while (true)
    {
        rightBound = index;
        if (rightBound <= leftBound)
        {
            return -1;
        }
        index = (leftBound + rightBound) / 2;
        v = (*test)(key, array->list[index]);
        if (v == 0)
            break;
        if (0 < v)
        {
            leftBound = index + 1;
            index = rightBound;
        }
    }
    return index;
}

#endif

// func_80035D8C
#pragma GLOBAL_ASM("asm/Core/x/xordarray.s", "XOrdSort__FP16st_XORDEREDARRAYPFPvPv_i")
