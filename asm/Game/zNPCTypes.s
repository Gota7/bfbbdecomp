.include "macros.inc"

.section .text  # 0x800EED74 - 0x800EEE4C

.global func_800EED74
func_800EED74:
/* 800EED74 000EBB74  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800EED78 000EBB78  7C 08 02 A6 */	mflr r0
/* 800EED7C 000EBB7C  90 01 00 14 */	stw r0, 0x14(r1)
/* 800EED80 000EBB80  48 00 01 65 */	bl func_800EEEE4
/* 800EED84 000EBB84  48 00 5C E9 */	bl func_800F4A6C
/* 800EED88 000EBB88  48 01 A8 01 */	bl func_80109588
/* 800EED8C 000EBB8C  48 03 64 31 */	bl func_801251BC
/* 800EED90 000EBB90  48 01 3E 9D */	bl func_80102C2C
/* 800EED94 000EBB94  48 01 8A 0D */	bl func_801077A0
/* 800EED98 000EBB98  48 04 71 09 */	bl func_80135EA0
/* 800EED9C 000EBB9C  48 04 73 91 */	bl func_8013612C
/* 800EEDA0 000EBBA0  48 04 6D 2D */	bl func_80135ACC
/* 800EEDA4 000EBBA4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800EEDA8 000EBBA8  7C 08 03 A6 */	mtlr r0
/* 800EEDAC 000EBBAC  38 21 00 10 */	addi r1, r1, 0x10
/* 800EEDB0 000EBBB0  4E 80 00 20 */	blr 

.global func_800EEDB4
func_800EEDB4:
/* 800EEDB4 000EBBB4  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 800EEDB8 000EBBB8  7C 08 02 A6 */	mflr r0
/* 800EEDBC 000EBBBC  90 01 00 14 */	stw r0, 0x14(r1)
/* 800EEDC0 000EBBC0  48 04 6D 75 */	bl func_80135B34
/* 800EEDC4 000EBBC4  48 04 73 D1 */	bl func_80136194
/* 800EEDC8 000EBBC8  48 04 71 41 */	bl func_80135F08
/* 800EEDCC 000EBBCC  48 01 8A 3D */	bl func_80107808
/* 800EEDD0 000EBBD0  48 01 3E F1 */	bl func_80102CC0
/* 800EEDD4 000EBBD4  48 03 64 51 */	bl func_80125224
/* 800EEDD8 000EBBD8  48 01 A8 11 */	bl func_801095E8
/* 800EEDDC 000EBBDC  48 00 5D E5 */	bl func_800F4BC0
/* 800EEDE0 000EBBE0  48 00 01 7D */	bl func_800EEF5C
/* 800EEDE4 000EBBE4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 800EEDE8 000EBBE8  7C 08 03 A6 */	mtlr r0
/* 800EEDEC 000EBBEC  38 21 00 10 */	addi r1, r1, 0x10
/* 800EEDF0 000EBBF0  4E 80 00 20 */	blr 

.global func_800EEDF4
func_800EEDF4:
/* 800EEDF4 000EBBF4  94 21 FC A0 */	stwu r1, -0x360(r1)
/* 800EEDF8 000EBBF8  7C 08 02 A6 */	mflr r0
/* 800EEDFC 000EBBFC  3C 80 80 27 */	lis r4, lbl_802688D0@ha
/* 800EEE00 000EBC00  90 01 03 64 */	stw r0, 0x364(r1)
/* 800EEE04 000EBC04  38 84 88 D0 */	addi r4, r4, lbl_802688D0@l
/* 800EEE08 000EBC08  38 00 00 6A */	li r0, 0x6a
/* 800EEE0C 000EBC0C  38 C1 00 04 */	addi r6, r1, 4
/* 800EEE10 000EBC10  38 A4 FF FC */	addi r5, r4, -4
/* 800EEE14 000EBC14  7C 09 03 A6 */	mtctr r0
lbl_800EEE18:
/* 800EEE18 000EBC18  80 85 00 04 */	lwz r4, 4(r5)
/* 800EEE1C 000EBC1C  84 05 00 08 */	lwzu r0, 8(r5)
/* 800EEE20 000EBC20  90 86 00 04 */	stw r4, 4(r6)
/* 800EEE24 000EBC24  94 06 00 08 */	stwu r0, 8(r6)
/* 800EEE28 000EBC28  42 00 FF F0 */	bdnz lbl_800EEE18
/* 800EEE2C 000EBC2C  80 05 00 04 */	lwz r0, 4(r5)
/* 800EEE30 000EBC30  38 81 00 08 */	addi r4, r1, 8
/* 800EEE34 000EBC34  90 06 00 04 */	stw r0, 4(r6)
/* 800EEE38 000EBC38  48 02 05 71 */	bl func_8010F3A8
/* 800EEE3C 000EBC3C  80 01 03 64 */	lwz r0, 0x364(r1)
/* 800EEE40 000EBC40  7C 08 03 A6 */	mtlr r0
/* 800EEE44 000EBC44  38 21 03 60 */	addi r1, r1, 0x360
/* 800EEE48 000EBC48  4E 80 00 20 */	blr 