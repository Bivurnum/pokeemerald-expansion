#include "global.h"
#include "spa_rattata.h"
#include "event_data.h"
#include "random.h"
#include "sound.h"
#include "spa.h"
#include "task.h"
#include "constants/songs.h"

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
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
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
    ANIMCMD_FRAME(.imageValue = 7, .duration = 16),
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
    ANIMCMD_FRAME(.imageValue = 10, .duration = 16),
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
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x64,
    .anims = sAnims_RatBodyLeft,
    .images = sPicTable_RatBodyLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatBodyLeft
};

static const struct SpriteTemplate sSpriteTemplate_RatBodyRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x64,
    .anims = sAnims_RatBodyRight,
    .images = sPicTable_RatBodyRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatBodyRight
};

static const struct SpriteTemplate sSpriteTemplate_RatTail =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x64,
    .anims = sAnims_RatTail,
    .images = sPicTable_RatTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatTail
};

static const struct SpriteTemplate sSpriteTemplate_RatEarLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x64,
    .anims = sAnims_RatEarLeft,
    .images = sPicTable_RatEarLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatEarLeft
};

static const struct SpriteTemplate sSpriteTemplate_RatEarRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x64,
    .anims = sAnims_RatEarRight,
    .images = sPicTable_RatEarRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatEarRight
};

static const struct SpriteTemplate sSpriteTemplate_RatMouth =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x32,
    .anims = sAnims_RatMouth,
    .images = sPicTable_RatMouth,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatMouth
};

static const struct SpriteTemplate sSpriteTemplate_RatWhiskerLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x32,
    .anims = sAnims_RatWhiskerLeft,
    .images = sPicTable_RatWhiskerLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatWhiskerLeft
};

static const struct SpriteTemplate sSpriteTemplate_RatWhiskerRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_64x32,
    .anims = sAnims_RatWhiskerRight,
    .images = sPicTable_RatWhiskerRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_RatWhiskerRight
};

static const struct SpriteTemplate sSpriteTemplate_RatToes =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
    .oam = &sOam_16x8,
    .anims = sAnims_RatToes,
    .images = sPicTable_RatToes,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_RatEyes =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_RATTATA,
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
        .tag = TAG_RATTATA
    },
    {NULL},
};

void CreateRattataSprites(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEyes, 154, 63, 8);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sInterval = (Random() % 180) + 180;

    spriteId = CreateSprite(&sSpriteTemplate_RatBodyLeft, 94, 73, 12);
    gSprites[spriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&sSpriteTemplate_RatBodyRight, 158, 81, 12);
    gSprites[spriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&sSpriteTemplate_RatTail, 88, 33, 11);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEarLeft, 119, 32, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEarRight, 183, 32, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatMouth, 152, 80, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatWhiskerLeft, 96, 59, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatWhiskerRight, 207, 57, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatToes, 104, 109, 12);
    gSprites[spriteId].sTaskId = taskId;
}

static void SpriteCB_RatBodyLeft(struct Sprite *sprite)
{
    if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (VarGet(VAR_SPA_COUNTER) == 1)
            StartSpriteAnim(sprite, 2);
        else if (VarGet(VAR_SPA_COUNTER) == 60)
            StartSpriteAnim(sprite, 1);
    }
}

static void SpriteCB_RatBodyRight(struct Sprite *sprite)
{
    if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (VarGet(VAR_SPA_COUNTER) == 1)
            StartSpriteAnim(sprite, 0);
        else if (VarGet(VAR_SPA_COUNTER) == 60)
            StartSpriteAnim(sprite, 1);
    }
}

static void SpriteCB_RatTail(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (VarGet(VAR_SPA_COUNTER) == 1)
            sprite->invisible = TRUE;
        else if (VarGet(VAR_SPA_COUNTER) == 60)
            sprite->invisible = FALSE;
    }
    else if (sTask.tPetArea != SPA_PET_BODY)
    {
        if (counter == 1)
        {
            StartSpriteAnim(sprite, 0);
        }
    }
    else
    {
        if (counter == 1)
        {
            StartSpriteAnim(sprite, 1);
        }
    }
}

static void SpriteCB_RatEarLeft(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
    {
        if (sprite->animNum != 2)
            StartSpriteAnim(sprite, 2);

        return;
    }
    else if (sTask.tPetActive && sTask.tPetArea == SPA_PET_HEAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2--;
        }
        if (counter < 10 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            sprite->y2 = 0;
            sprite->x2 = 0;
        }
    }
    else
    {
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }
    
    if (sTask.tIsBiting && sprite->animNum != 1)
    {
        StartSpriteAnim(sprite, 1);
    }
    else if (!sTask.tIsBiting && sprite->animNum == 1)
    {
        StartSpriteAnim(sprite, 0);
    }
}

static void SpriteCB_RatEarRight(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
    {
        if (sprite->animNum != 2)
            StartSpriteAnim(sprite, 2);

        return;
    }
    else if (sTask.tPetActive && sTask.tPetArea == SPA_PET_HEAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2--;
        }
        if (counter < 10 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            sprite->y2 = 0;
            sprite->x2 = 0;
        }
    }
    else
    {
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }
    
    if (sTask.tIsBiting && sprite->animNum != 1)
    {
        StartSpriteAnim(sprite, 1);
    }
    else if (!sTask.tIsBiting && sprite->animNum == 1)
    {
        StartSpriteAnim(sprite, 0);
    }
}

static void SpriteCB_RatMouth(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetScore > 0 && sTask.tPetScore < SPA_PET_SCORE_TARGET)
        sTask.tPetScore--;

    if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
    {
        if (sprite->animNum != 2)
            StartSpriteAnim(sprite, 2);

        return;
    }
    else if (sTask.tPetActive && sTask.tPetArea == SPA_PET_HEAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2--;
        }
        if (counter < 10 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            sprite->y2 = 0;
            sprite->x2 = 0;
        }
    }
    else
    {
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }
    
    if (sTask.tIsBiting && sprite->animNum != 1)
    {
        StartSpriteAnim(sprite, 1);
    }
    else if (!sTask.tIsBiting && sprite->animNum == 1)
    {
        StartSpriteAnim(sprite, 0);
    }
}

static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
    {
        if (sprite->animNum != 3)
            StartSpriteAnim(sprite, 3);

        return;
    }
    else if (sTask.tPetActive && sTask.tPetArea == SPA_PET_HEAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2--;
            StartSpriteAnim(sprite, 1);
        }
        if (counter < 10 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            sprite->y2 = 0;
            sprite->x2 = 0;
        }
    }
    else
    {
        if (counter == 1)
        {
            StartSpriteAnim(sprite, 0);
        }
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }
    
    if (sTask.tIsBiting && sprite->animNum != 2)
    {
        StartSpriteAnim(sprite, 2);
    }
    else if (!sTask.tIsBiting && sprite->animNum == 2)
    {
        StartSpriteAnim(sprite, 0);
    }
}

static void SpriteCB_RatWhiskerRight(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
    {
        if (sprite->animNum != 3)
            StartSpriteAnim(sprite, 3);

        return;
    }
    else if (sTask.tPetActive && sTask.tPetArea == SPA_PET_HEAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2--;
            StartSpriteAnim(sprite, 1);
        }
        if (counter < 10 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            sprite->y2 = 0;
            sprite->x2 = 0;
        }
    }
    else
    {
        if (counter == 1)
        {
            StartSpriteAnim(sprite, 0);
        }
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }

    if (sTask.tIsBiting && sprite->animNum != 2)
    {
        StartSpriteAnim(sprite, 2);
    }
    else if (!sTask.tIsBiting && sprite->animNum == 2)
    {
        StartSpriteAnim(sprite, 0);
    }
}

static void SpriteCB_RatEyes(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_SPA_COUNTER);

    if (sTask.tPetActive)
    {
        if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
        {
            if (sprite->animNum != 7)
                StartSpriteAnim(sprite, 7);

            return;
        }
        switch (sTask.tPetArea)
        {
        case SPA_PET_NONE:
            break;
        case SPA_PET_BODY:
            if (counter == 1)
            {
                sprite->y2 = 0;
                StartSpriteAnim(sprite, 2);
            }
            if (sprite->y2 < 0)
            {
                sprite->y2++;
            }
            break;
        case SPA_PET_HEAD:
            if (counter == 1)
            {
                sprite->y2 = 0;
                StartSpriteAnim(sprite, 2);
                sprite->y2--;
            }
            if (counter < 10 && counter % 4 == 0)
            {
                sprite->y2--;
            }
            break;
        }
    }
    else if (sTask.tPetArea == SPA_PET_BAD)
    {
        if (counter == 1)
        {
            sprite->y2 = 0;
            StartSpriteAnim(sprite, 3);
            PlaySE(SE_CONTEST_CONDITION_LOSE);
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            sprite->y2 = 0;
            sprite->x2 = 0;
            gSprites[VarGet(VAR_HAND_SPRITE_ID)].x = 28;
            gSprites[VarGet(VAR_HAND_SPRITE_ID)].y = 45;
            StartSpriteAnim(sprite, 5);

            if (sTask.tNumBadPets == 1)
            {
                StartSpriteAnim(sprite, 6);
                sTask.tIsBiting = TRUE;
            }
        }
        else if (sTask.tIsBiting)
        {
            if (sprite->animEnded)
                sTask.tIsBiting = FALSE;
        }
    }
    else if (sTask.tIsBiting)
    {
        if (sprite->animEnded)
        {
            StartSpriteAnim(sprite, 0);
            sTask.tIsBiting = FALSE;
            sprite->sCounter = 0;
            if (IsBerryInFeedingZone())
                sTask.tBerryBites++;
        }
        else if (sprite->sCounter == 56)
        {
            PlaySE(SE_M_SCRATCH);
            sprite->sCounter++;
        }
        else
        {
            sprite->sCounter++;
        }

    }
    else if (!sTask.tIsBiting)
    {
        if (sTask.tBerryBites == 3)
        {
            if (counter == 1)
            {
                StartSpriteAnim(sprite, 2);
            }
        }
        else if (IsBerryInFeedingZone())
        {
            StartSpriteAnim(sprite, 4);
            sTask.tIsBiting = TRUE;
            sprite->sCounter = 0;
        }
        else if (sTask.tNumBadPets != 2)
        {
            if (counter == 1)
            {
                StartSpriteAnim(sprite, 0);
                sprite->sCounter = 0;
            }
            if (sprite->y2 < 0)
            {
                sprite->y2++;
            }
            if (sprite->sCounter == sprite->sInterval)
            {
                StartSpriteAnim(sprite, 1); // Blink.
                sprite->sInterval = (Random() % 180) + 180; // 3 to 6 seconds.
                sprite->sCounter = 0;
            }
            else
            {
                sprite->sCounter++;
            }
        }
    }
}
