#include "global.h"
#include "spa.h"

#define sFletchinderHeadSpriteId        sSpaData.monSpriteIds[0]
#define sFletchinderBodyRightSpriteId   sSpaData.monSpriteIds[1]
#define sFletchinderBodyLeftSpriteId    sSpaData.monSpriteIds[2]
#define sFletchinderWingRightSpriteId   sSpaData.monSpriteIds[3]
#define sFletchinderWingLeftSpriteId    sSpaData.monSpriteIds[4]
#define sFletchinderTailSpriteId        sSpaData.monSpriteIds[5]
#define sFletchinderFeetSpriteId        sSpaData.monSpriteIds[6]

static const u16 gFletchinder_Pal[] = INCBIN_U16("graphics/_spa/fletchinder/fletchinder_head.gbapal");
static const u32 gFletchinderHead_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_head.4bpp");
static const u32 gFletchinderBodyRight_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_body_right.4bpp");
static const u32 gFletchinderBodyLeft_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_body_left.4bpp");
static const u32 gFletchinderWingRight_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_wing_right.4bpp");
static const u32 gFletchinderWingLeft_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_wing_left.4bpp");
static const u32 gFletchinderTail_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_tail.4bpp");
static const u32 gFletchinderFeet_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_feet.4bpp");
//static const u32 gBug_Gfx[] = INCBIN_U32("graphics/_spa/psyduck/bug.4bpp");

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_FletchinderHead[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderBodyRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderBodyLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderWingRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderWingLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderTail[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderFeet[] =
{
    sAnim_Normal,
};

static const struct SpriteFrameImage sPicTable_FletchinderHead[] =
{
    spa_frame(gFletchinderHead_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderBodyRight[] =
{
    spa_frame(gFletchinderBodyRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderBodyLeft[] =
{
    spa_frame(gFletchinderBodyLeft_Gfx, 0, 4, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderWingRight[] =
{
    spa_frame(gFletchinderWingRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderWingLeft[] =
{
    spa_frame(gFletchinderWingLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderTail[] =
{
    spa_frame(gFletchinderTail_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderFeet[] =
{
    spa_frame(gFletchinderFeet_Gfx, 0, 8, 4),
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderHead =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_FletchinderHead,
    .images = sPicTable_FletchinderHead,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderBodyRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_FletchinderBodyRight,
    .images = sPicTable_FletchinderBodyRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderBodyLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_32x64,
    .anims = sAnims_FletchinderBodyLeft,
    .images = sPicTable_FletchinderBodyLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderWingRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_FletchinderWingRight,
    .images = sPicTable_FletchinderWingRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderWingLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_FletchinderWingLeft,
    .images = sPicTable_FletchinderWingLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderTail =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_FletchinderTail,
    .images = sPicTable_FletchinderTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_FletchinderFeet =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_FletchinderFeet,
    .images = sPicTable_FletchinderFeet,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct SpritePalette sSpritePalettes_SpaFletchinder[] =
{
    {
        .data = gFletchinder_Pal,
        .tag = TAG_MON
    },
    {NULL},
};

void CreateFletchinderSprites(u8 taskId)
{
    sFletchinderHeadSpriteId = CreateSprite(&sSpriteTemplate_FletchinderHead, 157, 62, 9);
    gSprites[sFletchinderHeadSpriteId].sTaskId = taskId;

    sFletchinderBodyRightSpriteId = CreateSprite(&sSpriteTemplate_FletchinderBodyRight, 128, 71, 10);
    gSprites[sFletchinderBodyRightSpriteId].sTaskId = taskId;

    sFletchinderBodyLeftSpriteId = CreateSprite(&sSpriteTemplate_FletchinderBodyLeft, 104, 71, 10);
    gSprites[sFletchinderBodyLeftSpriteId].sTaskId = taskId;

    sFletchinderWingRightSpriteId = CreateSprite(&sSpriteTemplate_FletchinderWingRight, 103, 66, 8);
    gSprites[sFletchinderWingRightSpriteId].sTaskId = taskId;

    sFletchinderWingLeftSpriteId = CreateSprite(&sSpriteTemplate_FletchinderWingLeft, 39, 52, 8);
    gSprites[sFletchinderWingLeftSpriteId].sTaskId = taskId;

    sFletchinderTailSpriteId = CreateSprite(&sSpriteTemplate_FletchinderTail, 74, 28, 9);
    gSprites[sFletchinderTailSpriteId].sTaskId = taskId;

    sFletchinderFeetSpriteId = CreateSprite(&sSpriteTemplate_FletchinderFeet, 128, 119, 10);
    gSprites[sFletchinderFeetSpriteId].sTaskId = taskId;
}
