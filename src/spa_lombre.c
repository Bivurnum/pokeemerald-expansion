#include "global.h"
#include "spa.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "sound.h"
#include "task.h"
#include "constants/songs.h"

#define sLombreHeadTopLeftSpriteId      sSpaData.monSpriteIds[0]
#define sLombreHeadTopRightSpriteId     sSpaData.monSpriteIds[1]
#define sLombreHeadBottomLeftSpriteId   sSpaData.monSpriteIds[2]
#define sLombreHeadBottomRightSpriteId  sSpaData.monSpriteIds[3]
#define sLombreBodySpriteId             sSpaData.monSpriteIds[4]
#define sLombreLegLeftSpriteId          sSpaData.monSpriteIds[5]
#define sLombreLegRightSpriteId         sSpaData.monSpriteIds[6]
#define sLombreArmLeftSpriteId          sSpaData.monSpriteIds[7]
#define sLombreArmRightSpriteId         sSpaData.monSpriteIds[8]
#define sLombreIceArmLeftSpriteId       sSpaData.monSpriteIds[9]
#define sLombreIceArmRightSpriteId      sSpaData.monSpriteIds[10]

#define sLombreIceBlankLeft             sSpaData.iceSpriteIds[0]
#define sLombreIceBlankRight            sSpaData.iceSpriteIds[1]
#define sLombreIceMeltBackLeft          sSpaData.iceSpriteIds[2]
#define sLombreIceMeltBackRight         sSpaData.iceSpriteIds[3]
#define sLombreIceMeltFrontLeft         sSpaData.iceSpriteIds[4]
#define sLombreIceMeltFrontRight        sSpaData.iceSpriteIds[5]

static void SpriteCB_IceBlank(struct Sprite *sprite);

static const u16 gLombre_Pal[] = INCBIN_U16("graphics/_spa/lombre/lombre_body.gbapal");
static const u32 gLombreHeadTopLeft_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_head_top_left.4bpp");
static const u32 gLombreHeadTopRight_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_head_top_right.4bpp");
static const u32 gLombreHeadBottomLeft_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_head_bottom_left.4bpp");
static const u32 gLombreHeadBottomRight_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_head_bottom_right.4bpp");
static const u32 gLombreBody_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_body.4bpp");
static const u32 gLombreLegLeft_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_leg_left.4bpp");
static const u32 gLombreLegRight_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_leg_right.4bpp");
static const u32 gLombreArmLeft_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_arm_left.4bpp");
static const u32 gLombreArmRight_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_arm_right.4bpp");

static const u16 gIce_Pal[] = INCBIN_U16("graphics/_spa/lombre/lombre_ice_arm_left.gbapal");
static const u32 gLombreIceArmLeft_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_ice_arm_left.4bpp");
static const u32 gLombreIceArmRight_Gfx[] = INCBIN_U32("graphics/_spa/lombre/lombre_ice_arm_right.4bpp");
static const u32 gIceBlank_Gfx[] = INCBIN_U32("graphics/_spa/lombre/ice_blank.4bpp");

enum IceZones
{
    ICE_ZONE_NONE,
    ICE_ZONE_LEFT,
    ICE_ZONE_RIGHT
};

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_LombreHeadTopLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreHeadTopRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreHeadBottomLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreHeadBottomRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreBody[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreLegLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreLegRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreArmLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreArmRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreIceArmLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreIceArmRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_LombreIceBlank[] =
{
    sAnim_Normal,
};

static const struct SpriteFrameImage sPicTable_LombreHeadTopLeft[] =
{
    spa_frame(gLombreHeadTopLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_LombreHeadTopRight[] =
{
    spa_frame(gLombreHeadTopRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_LombreHeadBottomLeft[] =
{
    spa_frame(gLombreHeadBottomLeft_Gfx, 0, 8, 4),
};

static const struct SpriteFrameImage sPicTable_LombreHeadBottomRight[] =
{
    spa_frame(gLombreHeadBottomRight_Gfx, 0, 8, 4),
};

static const struct SpriteFrameImage sPicTable_LombreBody[] =
{
    spa_frame(gLombreBody_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_LombreLegLeft[] =
{
    spa_frame(gLombreLegLeft_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_LombreLegRight[] =
{
    spa_frame(gLombreLegRight_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_LombreArmLeft[] =
{
    spa_frame(gLombreArmLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_LombreArmRight[] =
{
    spa_frame(gLombreArmRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_LombreIceArmLeft[] =
{
    spa_frame(gLombreIceArmLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_LombreIceArmRight[] =
{
    spa_frame(gLombreIceArmRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_IceBlank[] =
{
    spa_frame(gIceBlank_Gfx, 0, 8, 8),
};

static const struct SpriteTemplate sSpriteTemplate_LombreHeadTopLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreHeadTopLeft,
    .images = sPicTable_LombreHeadTopLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreHeadTopRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreHeadTopRight,
    .images = sPicTable_LombreHeadTopRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreHeadBottomLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_LombreHeadBottomLeft,
    .images = sPicTable_LombreHeadBottomLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreHeadBottomRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_LombreHeadBottomRight,
    .images = sPicTable_LombreHeadBottomRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreBody =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreBody,
    .images = sPicTable_LombreBody,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreLegLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_32x32,
    .anims = sAnims_LombreLegLeft,
    .images = sPicTable_LombreLegLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreLegRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_32x32,
    .anims = sAnims_LombreLegRight,
    .images = sPicTable_LombreLegRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreArmLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreArmLeft,
    .images = sPicTable_LombreArmLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreArmRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreArmRight,
    .images = sPicTable_LombreArmRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreIceArmLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ICE,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreIceArmLeft,
    .images = sPicTable_LombreIceArmLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_LombreIceArmRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ICE,
    .oam = &sOam_64x64,
    .anims = sAnims_LombreIceArmRight,
    .images = sPicTable_LombreIceArmRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_IceBlank =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ICE,
    .oam = &sOam_64x64_Blend,
    .anims = sAnims_LombreIceBlank,
    .images = sPicTable_IceBlank,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_IceBlank
};

const struct SpritePalette sSpritePalettes_SpaLombre[] =
{
    {
        .data = gLombre_Pal,
        .tag = TAG_MON
    },
    {
        .data = gIce_Pal,
        .tag = TAG_ICE
    },
    {NULL},
};

void CreateLombreSprites(u8 taskId)
{
    if (FlagGet(FLAG_SPA_LOMBRE_SATISFIED))
        sSpaData.isSatisfied = TRUE;

    sLombreHeadTopLeftSpriteId = CreateSprite(&sSpriteTemplate_LombreHeadTopLeft, 100, 33, 9);
    gSprites[sLombreHeadTopLeftSpriteId].sTaskId = taskId;

    sLombreHeadTopRightSpriteId = CreateSprite(&sSpriteTemplate_LombreHeadTopRight, 164, 33, 9);
    gSprites[sLombreHeadTopRightSpriteId].sTaskId = taskId;

    sLombreHeadBottomLeftSpriteId = CreateSprite(&sSpriteTemplate_LombreHeadBottomLeft, 100, 81, 9);
    gSprites[sLombreHeadBottomLeftSpriteId].sTaskId = taskId;

    sLombreHeadBottomRightSpriteId = CreateSprite(&sSpriteTemplate_LombreHeadBottomRight, 164, 81, 9);
    gSprites[sLombreHeadBottomRightSpriteId].sTaskId = taskId;

    sLombreBodySpriteId = CreateSprite(&sSpriteTemplate_LombreBody, 132, 90, 10);
    gSprites[sLombreBodySpriteId].sTaskId = taskId;

    sLombreLegLeftSpriteId = CreateSprite(&sSpriteTemplate_LombreLegLeft, 112, 115, 9);
    gSprites[sLombreLegLeftSpriteId].sTaskId = taskId;

    sLombreLegRightSpriteId = CreateSprite(&sSpriteTemplate_LombreLegRight, 156, 115, 9);
    gSprites[sLombreLegRightSpriteId].sTaskId = taskId;

    sLombreArmLeftSpriteId = CreateSprite(&sSpriteTemplate_LombreArmLeft, 75, 95, 9);
    gSprites[sLombreArmLeftSpriteId].sTaskId = taskId;

    sLombreArmRightSpriteId = CreateSprite(&sSpriteTemplate_LombreArmRight, 191, 97, 9);
    gSprites[sLombreArmRightSpriteId].sTaskId = taskId;

    if (!sSpaData.isSatisfied)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));

        if (!FlagGet(FLAG_SPA_LOMBRE_THAWED_LEFT))
        {
            gSprites[sLombreArmLeftSpriteId].invisible = TRUE;

            sLombreIceArmLeftSpriteId = CreateSprite(&sSpriteTemplate_LombreIceArmLeft, 75, 97, 8);
            gSprites[sLombreIceArmLeftSpriteId].sTaskId = taskId;

            sLombreIceBlankLeft = CreateSprite(&sSpriteTemplate_IceBlank, 67, 38, 6);
            gSprites[sLombreIceBlankLeft].sTaskId = taskId;
            gSprites[sLombreIceBlankLeft].sIceId = sLombreIceBlankLeft;
        }

        if (!FlagGet(FLAG_SPA_LOMBRE_THAWED_RIGHT))
        {
            gSprites[sLombreArmRightSpriteId].invisible = TRUE;

            sLombreIceArmRightSpriteId = CreateSprite(&sSpriteTemplate_LombreIceArmRight, 191, 97, 8);
            gSprites[sLombreIceArmRightSpriteId].sTaskId = taskId;

            sLombreIceBlankRight = CreateSprite(&sSpriteTemplate_IceBlank, 197, 38, 6);
            gSprites[sLombreIceBlankRight].sTaskId = taskId;
            gSprites[sLombreIceBlankRight].sIceId = sLombreIceBlankRight;
        }
    }
}

static const u16 IceZones[][4] =
{
    [ICE_ZONE_LEFT] =  {  40, 104, 60, 130 },
    [ICE_ZONE_RIGHT] = { 157, 225, 60, 130 }
};

static u32 GetCurrentIceMeltZone(void)
{
    u32 i;

    for (i = 1; i <= ICE_ZONE_RIGHT; i++)
    {
        if (gSprites[sSpaData.orbSpriteId].x > IceZones[i][0] && gSprites[sSpaData.orbSpriteId].x < IceZones[i][1] 
         && gSprites[sSpaData.orbSpriteId].y > IceZones[i][2] && gSprites[sSpaData.orbSpriteId].y < IceZones[i][3])
            return i;
    }

    return ICE_ZONE_NONE;
}

void HandleItemsLombre(u8 taskId)
{
    switch (tSelectedItem)
    {
    case SPA_BERRY:
        break;
    case SPA_CLAW:
        break;
    case SPA_HONEY:
        break;
    case SPA_ORB:
        if (!sSpaData.isSatisfied)
        {
            u32 iceZone = GetCurrentIceMeltZone();

            if (iceZone && !sSpaData.iceMelting)
            {
                if (iceZone == ICE_ZONE_LEFT && !FlagGet(FLAG_SPA_LOMBRE_THAWED_LEFT))
                {
                    gSprites[sLombreIceBlankLeft].sIceMelting = TRUE;
                }
                else if (iceZone == ICE_ZONE_RIGHT && !FlagGet(FLAG_SPA_LOMBRE_THAWED_RIGHT))
                {
                    gSprites[sLombreIceBlankRight].sIceMelting = TRUE;
                }

                sSpaData.iceMelting = TRUE;
            }
            else if (!iceZone && sSpaData.iceMelting)
            {
                gSprites[sLombreIceBlankLeft].sIceMelting = FALSE;
                gSprites[sLombreIceBlankLeft].sCounter = 0;
                gSprites[sLombreIceBlankRight].sIceMelting = FALSE;
                gSprites[sLombreIceBlankRight].sCounter = 0;
                sSpaData.iceMelting = FALSE;
            }
        }
        break;
    }
}

static void IncrementIceScore(u32 id)
{
    if (id == sLombreIceBlankLeft)
        VarSet(VAR_ICE_LEFT_SCORE, VarGet(VAR_ICE_LEFT_SCORE) + 1);
    else
        VarSet(VAR_ICE_RIGHT_SCORE, VarGet(VAR_ICE_RIGHT_SCORE) + 1);
}

static void SpriteCB_IceBlank(struct Sprite *sprite)
{
    if (sprite->sIceMelting)
    {
        if (sprite->sCounter % 8 == 0)
        {
            sprite->y++;
            IncrementIceScore(sprite->sIceId);
        }

        if (sprite->y >= 78)
        {
            sSpaData.iceMelting = FALSE;
            PlaySE(SE_ICE_BREAK);
            if (sprite->sIceId == sLombreIceBlankLeft)
            {
                FlagSet(FLAG_SPA_LOMBRE_THAWED_LEFT);
                DestroySprite(&gSprites[sLombreIceArmLeftSpriteId]);
            }
            else
            {
                FlagSet(FLAG_SPA_LOMBRE_THAWED_RIGHT);
                DestroySprite(&gSprites[sLombreIceArmRightSpriteId]);
            }

            DestroySprite(sprite);
        }

        sprite->sCounter++;
    }
}
