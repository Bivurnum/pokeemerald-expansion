#include "global.h"
#include "spa.h"
#include "event_data.h"
#include "random.h"
#include "sound.h"
#include "spa.h"
#include "sprite.h"
#include "task.h"
#include "constants/songs.h"

#define sRatEyesSpriteId            sSpaData.monSpriteIds[0]
#define sRatBodyLeftSpriteId        sSpaData.monSpriteIds[1]
#define sRatBodyRightSpriteId       sSpaData.monSpriteIds[2]
#define sRatTailSpriteId            sSpaData.monSpriteIds[3]
#define sRatEarLeftSpriteId         sSpaData.monSpriteIds[4]
#define sRatEarRightSpriteId        sSpaData.monSpriteIds[5]
#define sRatMouthSpriteId           sSpaData.monSpriteIds[6]
#define sRatWhiskerLeftSpriteId     sSpaData.monSpriteIds[7]
#define sRatWhiskerRightSpriteId    sSpaData.monSpriteIds[8]
#define sRatToesSpriteId            sSpaData.monSpriteIds[9]

static void SpriteCB_RatBodyLeft(struct Sprite *sprite);
static void SpriteCB_RatBodyRight(struct Sprite *sprite);
static void SpriteCB_RatTail(struct Sprite *sprite);
static void SpriteCB_RatEarLeft(struct Sprite *sprite);
static void SpriteCB_RatEarRight(struct Sprite *sprite);
static void SpriteCB_RatMouth(struct Sprite *sprite);
static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite);
static void SpriteCB_RatWhiskerRight(struct Sprite *sprite);
static void SpriteCB_RatEyes(struct Sprite *sprite);

static const u16 gRattata_Pal[] = INCBIN_U16("graphics/_spa/rattata/rattata_body_left.gbapal");
static const u32 gRattataBodyLeft_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_body_left.4bpp");
static const u32 gRattataBodyRight_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_body_right.4bpp");
static const u32 gRattataTail_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_tail.4bpp");
static const u32 gRattataEarLeft_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_ear_left.4bpp");
static const u32 gRattataEarRight_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_ear_right.4bpp");
static const u32 gRattataMouth_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_mouth.4bpp");
static const u32 gRattataWhiskerLeft_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_whisker_left.4bpp");
static const u32 gRattataWhiskerRight_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_whisker_right.4bpp");
static const u32 gRattataToes_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_toes.4bpp");
static const u32 gRattataEyes_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_eyes.4bpp");

enum RattataBiteStates
{
    BITE_STATE_NONE,
    BITE_STATE_ACTIVE,
    BITE_STATE_END
};

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatBodyBreathing[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 48),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 48),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 48),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 48),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_RatBodyLeftBadTouch[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatBodyLeft[] =
{
    sAnim_Normal,
    sAnim_RatBodyBreathing,
    sAnim_RatBodyLeftBadTouch,
};

static const union AnimCmd * const sAnims_RatBodyRight[] =
{
    sAnim_Normal,
    sAnim_RatBodyBreathing,
};

static const union AnimCmd sAnim_RatTailWag[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd * const sAnims_RatTail[] =
{
    sAnim_Normal,
    sAnim_RatTailWag,
};

static const union AnimCmd sAnim_RatBite[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 32),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatSmile[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatEarLeft[] =
{
    sAnim_Normal,
    sAnim_RatBite,
    sAnim_RatSmile,
};

static const union AnimCmd * const sAnims_RatEarRight[] =
{
    sAnim_Normal,
    sAnim_RatBite,
    sAnim_RatSmile,
};

static const union AnimCmd * const sAnims_RatMouth[] =
{
    sAnim_Normal,
    sAnim_RatBite,
    sAnim_RatSmile,
};

static const union AnimCmd sAnim_RatWhiskerTwitch[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 32),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 48),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 3),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd * const sAnims_RatWhiskerLeft[] =
{
    sAnim_Normal,
    sAnim_RatWhiskerTwitch,
    sAnim_RatBite,
    sAnim_RatSmile,
};

static const union AnimCmd * const sAnims_RatWhiskerRight[] =
{
    sAnim_Normal,
    sAnim_RatWhiskerTwitch,
    sAnim_RatBite,
    sAnim_RatSmile,
};

static const union AnimCmd * const sAnims_RatToes[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_RatEyesBlink[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesJoy[] =
{
    ANIMCMD_FRAME(.imageValue = 5, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesBad[] =
{
    ANIMCMD_FRAME(.imageValue = 6, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesBiteGood[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 32),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesAngry[] =
{
    ANIMCMD_FRAME(.imageValue = 7, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 7, .duration = 59),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesBiteBad[] =
{
    ANIMCMD_FRAME(.imageValue = 7, .duration = 32),
    ANIMCMD_FRAME(.imageValue = 8, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 9, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 8, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 7, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesSmile[] =
{
    ANIMCMD_FRAME(.imageValue = 10, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 10, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatEyes[] =
{
    sAnim_Normal,
    sAnim_RatEyesBlink,
    sAnim_RatEyesJoy,
    sAnim_RatEyesBad,
    sAnim_RatEyesBiteGood,
    sAnim_RatEyesAngry,
    sAnim_RatEyesBiteBad,
    sAnim_RatEyesSmile,
};

static const struct SpriteFrameImage sPicTable_RatBodyLeft[] =
{
    spa_frame(gRattataBodyLeft_Gfx, 0, 8, 8),
    spa_frame(gRattataBodyLeft_Gfx, 1, 8, 8),
    spa_frame(gRattataBodyLeft_Gfx, 2, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatBodyRight[] =
{
    spa_frame(gRattataBodyRight_Gfx, 0, 8, 8),
    spa_frame(gRattataBodyRight_Gfx, 1, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatTail[] =
{
    spa_frame(gRattataTail_Gfx, 0, 8, 8),
    spa_frame(gRattataTail_Gfx, 1, 8, 8),
    spa_frame(gRattataTail_Gfx, 2, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatEarLeft[] =
{
    spa_frame(gRattataEarLeft_Gfx, 0, 8, 8),
    spa_frame(gRattataEarLeft_Gfx, 1, 8, 8),
    spa_frame(gRattataEarLeft_Gfx, 2, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatEarRight[] =
{
    spa_frame(gRattataEarRight_Gfx, 0, 8, 8),
    spa_frame(gRattataEarRight_Gfx, 1, 8, 8),
    spa_frame(gRattataEarRight_Gfx, 2, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatMouth[] =
{
    spa_frame(gRattataMouth_Gfx, 0, 8, 4),
    spa_frame(gRattataMouth_Gfx, 1, 8, 4),
    spa_frame(gRattataMouth_Gfx, 2, 8, 4),
};

static const struct SpriteFrameImage sPicTable_RatWhiskerLeft[] =
{
    spa_frame(gRattataWhiskerLeft_Gfx, 0, 8, 4),
    spa_frame(gRattataWhiskerLeft_Gfx, 1, 8, 4),
    spa_frame(gRattataWhiskerLeft_Gfx, 2, 8, 4),
};

static const struct SpriteFrameImage sPicTable_RatWhiskerRight[] =
{
    spa_frame(gRattataWhiskerRight_Gfx, 0, 8, 4),
    spa_frame(gRattataWhiskerRight_Gfx, 1, 8, 4),
    spa_frame(gRattataWhiskerRight_Gfx, 2, 8, 4),
};

static const struct SpriteFrameImage sPicTable_RatToes[] =
{
    spa_frame(gRattataToes_Gfx, 0, 2, 1),
};

static const struct SpriteFrameImage sPicTable_RatEyes[] =
{
    spa_frame(gRattataEyes_Gfx, 0, 8, 4),
    spa_frame(gRattataEyes_Gfx, 1, 8, 4),
    spa_frame(gRattataEyes_Gfx, 2, 8, 4),
    spa_frame(gRattataEyes_Gfx, 3, 8, 4),
    spa_frame(gRattataEyes_Gfx, 4, 8, 4),
    spa_frame(gRattataEyes_Gfx, 5, 8, 4),
    spa_frame(gRattataEyes_Gfx, 6, 8, 4),
    spa_frame(gRattataEyes_Gfx, 7, 8, 4),
    spa_frame(gRattataEyes_Gfx, 8, 8, 4),
    spa_frame(gRattataEyes_Gfx, 9, 8, 4),
    spa_frame(gRattataEyes_Gfx, 10, 8, 4),
};

static const struct SpriteTemplate sSpriteTemplate_RatBodyLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_RatBodyLeft,
    .images = sPicTable_RatBodyLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatBodyLeft
};

static const struct SpriteTemplate sSpriteTemplate_RatBodyRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_RatBodyRight,
    .images = sPicTable_RatBodyRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatBodyRight
};

static const struct SpriteTemplate sSpriteTemplate_RatTail =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_RatTail,
    .images = sPicTable_RatTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatTail
};

static const struct SpriteTemplate sSpriteTemplate_RatEarLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_RatEarLeft,
    .images = sPicTable_RatEarLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatEarLeft
};

static const struct SpriteTemplate sSpriteTemplate_RatEarRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_RatEarRight,
    .images = sPicTable_RatEarRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatEarRight
};

static const struct SpriteTemplate sSpriteTemplate_RatMouth =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_RatMouth,
    .images = sPicTable_RatMouth,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatMouth
};

static const struct SpriteTemplate sSpriteTemplate_RatWhiskerLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_RatWhiskerLeft,
    .images = sPicTable_RatWhiskerLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatWhiskerLeft
};

static const struct SpriteTemplate sSpriteTemplate_RatWhiskerRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_RatWhiskerRight,
    .images = sPicTable_RatWhiskerRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatWhiskerRight
};

static const struct SpriteTemplate sSpriteTemplate_RatToes =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_16x8,
    .anims = sAnims_RatToes,
    .images = sPicTable_RatToes,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_RatEyes =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x32,
    .anims = sAnims_RatEyes,
    .images = sPicTable_RatEyes,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatEyes
};

const struct SpritePalette sSpritePalettes_SpaRattata[] =
{
    {
        .data = gRattata_Pal,
        .tag = TAG_MON
    },
    {NULL},
};

void CreateRattataSprites(u8 taskId)
{
    sRatEyesSpriteId = CreateSprite(&sSpriteTemplate_RatEyes, 154, 63, 8);
    gSprites[sRatEyesSpriteId].sTaskId = taskId;
    gSprites[sRatEyesSpriteId].sInterval = (Random() % 180) + 180;

    sRatBodyLeftSpriteId = CreateSprite(&sSpriteTemplate_RatBodyLeft, 94, 73, 12);
    gSprites[sRatBodyLeftSpriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[sRatBodyLeftSpriteId], 1);

    sRatBodyRightSpriteId = CreateSprite(&sSpriteTemplate_RatBodyRight, 158, 81, 12);
    gSprites[sRatBodyRightSpriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[sRatBodyRightSpriteId], 1);

    sRatTailSpriteId = CreateSprite(&sSpriteTemplate_RatTail, 88, 33, 11);
    gSprites[sRatTailSpriteId].sTaskId = taskId;

    sRatEarLeftSpriteId = CreateSprite(&sSpriteTemplate_RatEarLeft, 119, 32, 10);
    gSprites[sRatEarLeftSpriteId].sTaskId = taskId;

    sRatEarRightSpriteId = CreateSprite(&sSpriteTemplate_RatEarRight, 183, 32, 10);
    gSprites[sRatEarRightSpriteId].sTaskId = taskId;

    sRatMouthSpriteId = CreateSprite(&sSpriteTemplate_RatMouth, 152, 80, 10);
    gSprites[sRatMouthSpriteId].sTaskId = taskId;

    sRatWhiskerLeftSpriteId = CreateSprite(&sSpriteTemplate_RatWhiskerLeft, 96, 59, 9);
    gSprites[sRatWhiskerLeftSpriteId].sTaskId = taskId;

    sRatWhiskerRightSpriteId = CreateSprite(&sSpriteTemplate_RatWhiskerRight, 207, 57, 9);
    gSprites[sRatWhiskerRightSpriteId].sTaskId = taskId;

    sRatToesSpriteId = CreateSprite(&sSpriteTemplate_RatToes, 104, 109, 12);
    gSprites[sRatToesSpriteId].sTaskId = taskId;
}

static void StartRattataHappyAnim(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 7);
    StartSpriteAnim(&gSprites[sRatMouthSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatEarLeftSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatEarRightSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatWhiskerLeftSpriteId], 3);
    StartSpriteAnim(&gSprites[sRatWhiskerRightSpriteId], 3);
}

static void StartRattataBite(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 4);
    StartSpriteAnim(&gSprites[sRatMouthSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatEarLeftSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatEarRightSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatWhiskerLeftSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatWhiskerRightSpriteId], 2);
}

void StartRattataBadTouch(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatBodyLeftSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 3);
    gSprites[sRatTailSpriteId].invisible = TRUE;
    PauseUntilAnimEnds(taskId, sRatEyesSpriteId);
}

void StartRattataAngry(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 5);
    PauseUntilAnimEnds(taskId, sRatEyesSpriteId);
    CreateAngrySprite(taskId);
}

void StartRattataPet(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatWhiskerLeftSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatWhiskerRightSpriteId], 1);
}

void StopRattataPet(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 0);
    StartSpriteAnim(&gSprites[sRatWhiskerLeftSpriteId], 0);
    StartSpriteAnim(&gSprites[sRatWhiskerRightSpriteId], 0);
}

void ResetRattataSprites(void)
{
    gSprites[sRatTailSpriteId].invisible = FALSE;
}

void HandleItemsRattata(u8 taskId)
{
    switch (tSelectedItem)
    {
    case SPA_BERRY:
        if (tBerryBites >= 3)
        {
            StartRattataHappyAnim(taskId);
            PauseUntilAnimEnds(taskId, sRatEyesSpriteId);
            CreateMusicSprite(taskId);
            DoSpaMonEnjoyedSnackText();
            sSpaData.isSatisfied = TRUE;
            tBerryBites = 0;
        }
        else if (IsBerryInFeedingZone())
        {
            switch (tBiteState)
            {
            case BITE_STATE_NONE:
                StartRattataBite(taskId);
                tCounter = 0;
                tBiteState = BITE_STATE_ACTIVE;
                break;
            case BITE_STATE_ACTIVE:
                if (gSprites[sRatMouthSpriteId].animEnded)
                {
                    tBerryBites++;
                    if (tBerryBites >= 3)
                        DestroySprite(&gSprites[sSpaData.berrySpriteId]);
                    else
                        StartSpriteAnim(&gSprites[sSpaData.berrySpriteId], tBerryBites);

                    tBiteState = BITE_STATE_NONE;
                }
                else if (tCounter == 56)
                {
                    PlaySE(SE_M_SCRATCH);
                    tCounter++;
                }
                else if (tCounter < 56)
                {
                    tCounter++;
                }
                break;
            }
        }
        else
        {
            tBiteState = BITE_STATE_NONE;
        }
        break;
    case SPA_CLAW:
        break;
    case SPA_HONEY:
        break;
    case SPA_ORB:
        break;
    }
}

void EndSpaBadRattata(u8 taskId)
{
    StartSpriteAnim(&gSprites[sRatEyesSpriteId], 6);
    StartSpriteAnim(&gSprites[sRatMouthSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatEarLeftSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatEarRightSpriteId], 1);
    StartSpriteAnim(&gSprites[sRatWhiskerLeftSpriteId], 2);
    StartSpriteAnim(&gSprites[sRatWhiskerRightSpriteId], 2);
    //PauseUntilAnimEnds(taskId, sRatMouthSpriteId);
}

static void SpriteCB_RatBodyLeft(struct Sprite *sprite)
{

}

static void SpriteCB_RatBodyRight(struct Sprite *sprite)
{

}

static void SpriteCB_RatTail(struct Sprite *sprite)
{

}

static void SpriteCB_RatEarLeft(struct Sprite *sprite)
{
    u32 taskId = sprite->sTaskId;

        if (tPetArea == SPA_PET_HEAD)
        {
            if (sprite->y2 > -3 && sprite->sCounter % 4 == 0)
            {
                sprite->y2--;
            }
            sprite->sCounter++;
        }
        else if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
}

static void SpriteCB_RatEarRight(struct Sprite *sprite)
{
    u32 taskId = sprite->sTaskId;

        if (tPetArea == SPA_PET_HEAD)
        {
            if (sprite->y2 > -3 && sprite->sCounter % 4 == 0)
            {
                sprite->y2--;
            }
            sprite->sCounter++;
        }
        else if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
}

static void SpriteCB_RatMouth(struct Sprite *sprite)
{
    u32 taskId = sprite->sTaskId;

        if (tPetArea == SPA_PET_HEAD)
        {
            if (sprite->y2 > -3 && sprite->sCounter % 4 == 0)
            {
                sprite->y2--;
            }
            sprite->sCounter++;
        }
        else if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
}

static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite)
{
    u32 taskId = sprite->sTaskId;

        if (tPetArea == SPA_PET_HEAD)
        {
            if (sprite->y2 > -3 && sprite->sCounter % 4 == 0)
            {
                sprite->y2--;
            }
            sprite->sCounter++;
        }
        else if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
}

static void SpriteCB_RatWhiskerRight(struct Sprite *sprite)
{
    u32 taskId = sprite->sTaskId;

        if (tPetArea == SPA_PET_HEAD)
        {
            if (sprite->y2 > -3 && sprite->sCounter % 4 == 0)
            {
                sprite->y2--;
            }
            sprite->sCounter++;
        }
        else if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
}

static void SpriteCB_RatEyes(struct Sprite *sprite)
{
    u32 taskId = sprite->sTaskId;

        if (tPetArea == SPA_PET_HEAD)
        {
            if (sprite->y2 > -3 && sprite->sCounter % 4 == 0)
            {
                sprite->y2--;
            }
            sprite->sCounter++;
        }
        else if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
}
