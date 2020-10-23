#include "xString.h"

uint32 xStrHash(const char* str)
{
    uint32 hash = 0;
    uint32 i;

    while (i = *str, i != NULL)
    {
        hash = (i - (i & (int32)i >> 1 & 0x20) & 0xff) + hash * 0x83;
        str++;
    }

    return hash;
}

uint32 xStrHash(const char* str, ulong32 size)
{
    uint32 hash = 0;
    uint32 i = 0;
    uint32 c;

    while (i < size && (c = *str, c != NULL))
    {
        i++;
        str++;
        hash = (c - (c & (int32)c >> 1 & 0x20) & 0xff) + hash * 0x83;
    }

    return hash;
}

uint32 xStrHashCat(uint32 prefix, const char* str)
{
    uint32 hash;
    uint32 i;

    while (i = *str, i != NULL)
    {
        str++;
        hash = (i - (i & (int32)i >> 1 & 0x20) & 0xff) + hash * 0x83;
    }

    return hash;
}

// char* xStrTok(char* string, char* control, char** nextoken)
#pragma GLOBAL_ASM("asm/Core/x/xString.s", "xStrTok__FPcPCcPPc")

// char* xStrTokBuffer(char* string, char* control, void* buffer)
#pragma GLOBAL_ASM("asm/Core/x/xString.s", "xStrTokBuffer__FPCcPCcPv")

// int xStricmp(char* string1, char* string2)
#pragma GLOBAL_ASM("asm/Core/x/xString.s", "xStricmp__FPCcPCc")

int8* xStrupr(char* string)
{
    int8 p;

    while (p = *string, p != NULL)
    {
        bool isLowercase = false;

        // check if between lowercase ascii a-z
        if ((p >= 97) && (p <= 122))
        {
            isLowercase = true;
        }

        if (isLowercase)
        {
            // Uppercase ascii character is offset by 32
            p -= 32;
        }

        *string = p;
        string++;
    }
}

// int xStrParseFloatList(float* dest, char* strbuf, int max)
#pragma GLOBAL_ASM("asm/Core/x/xString.s", "xStrParseFloatList__FPfPCci")

#pragma GLOBAL_ASM("asm/Core/x/xString.s", "imemcmp__FPCvPCvUl")

// @unnamed@xString_cpp@::tolower(char)
extern "C" {
uint32 tolower__21_esc__2_unnamed_esc__2_xString_cpp_esc__2_Fc(uint32 param_1)
{
    tolower__21_esc__2_unnamed_esc__2_xString_cpp_esc__2_Fi(param_1 & 0xff);
}
}

// @unnamed@xString_cpp@::tolower(int)
extern "C" {
uint32 tolower__21_esc__2_unnamed_esc__2_xString_cpp_esc__2_Fi(uint32 param_1)
{
    return param_1 | ((param_1 >> 1) & 32);
}
}

/*
// Non-matching
int32 icompare(const substr& s1, const substr& s2)
{
    int32 result;
    uint32 len;

    len = s2.size;

    if (s1.size < s2.size)
    {
        len = s1.size;
    }

    result = imemcmp(s1.text, s2.text, len);

    if (result == 0)
    {
        if (s1.size == s2.size)
        {
            result = 0;
        }
        else
        {
            result = 1;
            if (s1.size < s2.size)
            {
                result = -1;
            }
        }
    }
    return result;
}
*/
#pragma GLOBAL_ASM("asm/Core/x/xString.s", "icompare__FRC6substrRC6substr")

#pragma GLOBAL_ASM("asm/Core/x/xString.s", "atox__FRC6substrRUl")

// char* find_char(substr& s, substr& cs)
#pragma GLOBAL_ASM("asm/Core/x/xString.s", "find_char__FRC6substrRC6substr")
