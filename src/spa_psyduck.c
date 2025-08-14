#include "global.h"
#include "spa_psyduck.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "palette.h"
#include "random.h"
#include "sound.h"
#include "spa.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static const u16 gPsyduck_Pal[] = INCBIN_U16("graphics/_spa/psyduck/psyduck_head_left.gbapal");
static const u32 gPsyduckHeadLeft_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_head_left.4bpp");
static const u32 gPsyduckHeadRight_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_head_right.4bpp");
static const u32 gPsyduckBill_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_bill.4bpp");
static const u32 gPsyduckHair_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_hair.4bpp");
static const u32 gPsyduckEyes_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_eyes.4bpp");
static const u32 gPsyduckBodyLeft_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_body_left.4bpp");
static const u32 gPsyduckBodyRight_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_body_right.4bpp");
static const u32 gPsyduckTail_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_tail.4bpp");
static const u32 gPsyduckFoot_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_foot.4bpp");
static const u32 gPsyduckArmFront_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_arm_front.4bpp");
static const u32 gPsyduckArmBack_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/psyduck_arm_back.4bpp");

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_PsyduckHeadLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_PsyduckHeadRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_PsyduckBill[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_PsyduckHair[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_EyesScared[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_PsyduckEyes[] =
{
    sAnim_Normal,
    sAnim_EyesScared,
};

static const union AnimCmd * const sAnims_PsyduckBodyLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_PsyduckBodyRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_PsyduckTail[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_PsyduckFoot[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_ArmFrontScared[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_PsyduckArmFront[] =
{
    sAnim_Normal,
    sAnim_ArmFrontScared,
};

static const union AnimCmd * const sAnims_PsyduckArmBack[] =
{
    sAnim_Normal,
};

static const struct SpriteFrameImage sPicTable_PsyduckHeadLeft[] =
{
    spa_frame(gPsyduckHeadLeft_Gfx, 0, 4, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckHeadRight[] =
{
    spa_frame(gPsyduckHeadRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckBill[] =
{
    spa_frame(gPsyduckBill_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckHair[] =
{
    spa_frame(gPsyduckHair_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_PsyduckEyes[] =
{
    spa_frame(gPsyduckEyes_Gfx, 0, 8, 4),
    spa_frame(gPsyduckEyes_Gfx, 1, 8, 4),
};

static const struct SpriteFrameImage sPicTable_PsyduckBodyLeft[] =
{
    spa_frame(gPsyduckBodyLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckBodyRight[] =
{
    spa_frame(gPsyduckBodyRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckTail[] =
{
    spa_frame(gPsyduckTail_Gfx, 0, 4, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckFoot[] =
{
    spa_frame(gPsyduckFoot_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_PsyduckArmFront[] =
{
    spa_frame(gPsyduckArmFront_Gfx, 0, 8, 8),
    spa_frame(gPsyduckArmFront_Gfx, 1, 8, 8),
};

static const struct SpriteFrameImage sPicTable_PsyduckArmBack[] =
{
    spa_frame(gPsyduckArmBack_Gfx, 0, 4, 4),
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckHeadLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_32x64,
    .anims = sAnims_PsyduckHeadLeft,
    .images = sPicTable_PsyduckHeadLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckHeadRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_64x64,
    .anims = sAnims_PsyduckHeadRight,
    .images = sPicTable_PsyduckHeadRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckBill =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_64x64,
    .anims = sAnims_PsyduckBill,
    .images = sPicTable_PsyduckBill,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckHair =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_32x32,
    .anims = sAnims_PsyduckHair,
    .images = sPicTable_PsyduckHair,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckEyes =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_64x32,
    .anims = sAnims_PsyduckEyes,
    .images = sPicTable_PsyduckEyes,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckBodyLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_64x64,
    .anims = sAnims_PsyduckBodyLeft,
    .images = sPicTable_PsyduckBodyLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckBodyRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_64x64,
    .anims = sAnims_PsyduckBodyRight,
    .images = sPicTable_PsyduckBodyRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckTail =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_32x64,
    .anims = sAnims_PsyduckTail,
    .images = sPicTable_PsyduckTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckFoot =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_32x32,
    .anims = sAnims_PsyduckFoot,
    .images = sPicTable_PsyduckFoot,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckArmFront =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_64x64,
    .anims = sAnims_PsyduckArmFront,
    .images = sPicTable_PsyduckArmFront,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_PsyduckArmBack =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PSYDUCK,
    .oam = &sOam_32x32,
    .anims = sAnims_PsyduckArmBack,
    .images = sPicTable_PsyduckArmBack,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct SpritePalette sSpritePalettes_SpaPsyduck[] =
{
    {
        .data = gPsyduck_Pal,
        .tag = TAG_PSYDUCK
    },
    {NULL},
};

void CreatePsyduckSprites(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckHeadLeft, 72, 77, 8);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckHeadRight, 120, 77, 8);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckBill, 73, 98, 7);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckHair, 104, 44, 7);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckEyes, 89, 73, 6);
    gSprites[spriteId].sTaskId = taskId;
    if (!FlagGet(FLAG_SPA_PSYDUCK_SATISFIED))
    {
        StartSpriteAnim(&gSprites[spriteId], 1);
    }

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckBodyLeft, 128, 67, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckBodyRight, 192, 67, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckTail, 180, 33, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckFoot, 205, 76, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_PsyduckArmFront, 138, 92, 5);
    gSprites[spriteId].sTaskId = taskId;
    if (FlagGet(FLAG_SPA_PSYDUCK_SATISFIED))
    {
        gTasks[taskId].tIsSatisfied = TRUE;
        StartSpriteAnim(&gSprites[spriteId], 0);
    }
    else
    {
        StartSpriteAnim(&gSprites[spriteId], 1);
        gSprites[spriteId].x2 = -16;

        spriteId = CreateSprite(&sSpriteTemplate_PsyduckArmBack, 57, 78, 5);
        gSprites[spriteId].sTaskId = taskId;
    }
}