#include "global.h"
#include "spa_teddiursa.h"
#include "event_data.h"
#include "random.h"
#include "sound.h"
#include "spa.h"
#include "task.h"
#include "constants/songs.h"

static const u16 gTeddiursa_Pal[] = INCBIN_U16("graphics/_spa/teddiursa/teddiursa_head_left.gbapal");
static const u32 gTeddiursaHeadLeft_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_head_left.4bpp");
static const u32 gTeddiursaHeadRight_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_head_right.4bpp");
static const u32 gTeddiursaBody_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_body.4bpp");
static const u32 gTeddiursaTail_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_tail.4bpp");
static const u32 gTeddiursaFoot_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_foot.4bpp");
static const u32 gTeddiursaEars_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_ears.4bpp");
static const u32 gTeddiursaEye_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_eye.4bpp");
static const u32 gTeddiursaMouth_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_mouth.4bpp");
static const u32 gTeddiursaArm_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_arm.4bpp");

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_TeddyHeadLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyHeadRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyBody[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyTail[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyFoot[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyEars[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyEye[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyMouth[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_TeddyArm[] =
{
    sAnim_Normal,
};

static const struct SpriteFrameImage sPicTable_TeddyHeadLeft[] =
{
    spa_frame(gTeddiursaHeadLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_TeddyHeadRight[] =
{
    spa_frame(gTeddiursaHeadRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_TeddyBody[] =
{
    spa_frame(gTeddiursaBody_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_TeddyTail[] =
{
    spa_frame(gTeddiursaTail_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_TeddyFoot[] =
{
    spa_frame(gTeddiursaFoot_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_TeddyEars[] =
{
    spa_frame(gTeddiursaEars_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_TeddyEye[] =
{
    spa_frame(gTeddiursaEye_Gfx, 0, 2, 2),
};

static const struct SpriteFrameImage sPicTable_TeddyMouth[] =
{
    spa_frame(gTeddiursaMouth_Gfx, 0, 2, 2),
};

static const struct SpriteFrameImage sPicTable_TeddyArm[] =
{
    spa_frame(gTeddiursaArm_Gfx, 0, 8, 8),
};

static const struct SpriteTemplate sSpriteTemplate_TeddyHeadLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyHeadLeft,
    .images = sPicTable_TeddyHeadLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyHeadRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyHeadRight,
    .images = sPicTable_TeddyHeadRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyBody =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyBody,
    .images = sPicTable_TeddyBody,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyTail =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_32x32,
    .anims = sAnims_TeddyTail,
    .images = sPicTable_TeddyTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyFoot =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_32x32,
    .anims = sAnims_TeddyFoot,
    .images = sPicTable_TeddyFoot,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyEars =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyEars,
    .images = sPicTable_TeddyEars,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyEye =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_16x16,
    .anims = sAnims_TeddyEye,
    .images = sPicTable_TeddyEye,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyMouth =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_16x16,
    .anims = sAnims_TeddyMouth,
    .images = sPicTable_TeddyMouth,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyArm =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_TEDDIURSA,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyArm,
    .images = sPicTable_TeddyArm,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct SpritePalette sSpritePalettes_SpaTeddiursa[] =
{
    {
        .data = gTeddiursa_Pal,
        .tag = TAG_TEDDIURSA
    },
};

void CreateTeddiursaSprites(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyHeadLeft, 100, 48, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyHeadRight, 164, 48, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyBody, 133, 94, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyTail, 140, 112, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyFoot, 100, 104, 11);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyEars, 130, 27, 8);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyEye, 115, 50, 8);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyMouth, 107, 64, 8);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_TeddyArm, 109, 80, 9);
    gSprites[spriteId].sTaskId = taskId;
}
