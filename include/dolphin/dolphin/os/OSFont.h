#ifndef __OSFONT_H__
#define __OSFONT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../types.h"

typedef struct OSFontHeader
{
    u16 fontType;
    u16 firstChar;
    u16 lastChar;
    u16 invalChar;
    u16 ascent;
    u16 descent;
    u16 width;
    u16 leading;
    u16 cellWidth;
    u16 cellHeight;
    u32 sheetSize;
    u16 sheetFormat;
    u16 sheetColumn;
    u16 sheetRow;
    u16 sheetWidth;
    u16 sheetHeight;
    u16 widthTable;
    u32 sheetImage;
    u32 sheetFullSize;
    u8  c0;
    u8  c1;
    u8  c2;
    u8  c3;
} OSFontHeader;

uint16 OSGetFontEncode();
bool OSInitFont(OSFontHeader* fontData);

#ifdef __cplusplus
}
#endif

#endif