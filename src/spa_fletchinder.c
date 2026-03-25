#include "global.h"
#include "spa.h"
#include "event_data.h"
#include "sound.h"
#include "task.h"
#include "constants/songs.h"

#define sFletchinderHeadSpriteId            sSpaData.monSpriteIds[0]
#define sFletchinderBodyRightSpriteId       sSpaData.monSpriteIds[1]
#define sFletchinderBodyLeftSpriteId        sSpaData.monSpriteIds[2]
#define sFletchinderWingRightSpriteId       sSpaData.monSpriteIds[3]
#define sFletchinderWingLeftSpriteId        sSpaData.monSpriteIds[4]
#define sFletchinderTailSpriteId            sSpaData.monSpriteIds[5]
#define sFletchinderFeetSpriteId            sSpaData.monSpriteIds[6]
#define sFletchinderWingBackRightSpriteId   sSpaData.monSpriteIds[7]
#define sFletchinderWingBackLeftSpriteId    sSpaData.monSpriteIds[8]

static const u16 gFletchinder_Pal[] = INCBIN_U16("graphics/_spa/fletchinder/fletchinder_head.gbapal");
static const u32 gFletchinderHead_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_head.4bpp");
static const u32 gFletchinderBodyRight_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_body_right.4bpp");
static const u32 gFletchinderBodyLeft_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_body_left.4bpp");
static const u32 gFletchinderWingRight_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_wing_right.4bpp");
static const u32 gFletchinderWingLeft_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_wing_left.4bpp");
static const u32 gFletchinderTail_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_tail.4bpp");
static const u32 gFletchinderFeet_Gfx[] = INCBIN_U32("graphics/_spa/fletchinder/fletchinder_feet.4bpp");

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadPet[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadFamished[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 30),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 5, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 5, .duration = 30),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 6),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_HeadReactToHoney[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadReturnToFamished[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 30),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 5, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 5, .duration = 30),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 6),
    ANIMCMD_JUMP(1)
};

static const union AnimCmd sAnim_HeadBite[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 19),
    ANIMCMD_FRAME(.imageValue = 6, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 7, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 8, .duration = 7),
    ANIMCMD_FRAME(.imageValue = 8, .duration = 1),
    ANIMCMD_FRAME(.imageValue = 7, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 6, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadMusic[] =
{
    ANIMCMD_FRAME(.imageValue = 9, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 9, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadBadTouch[] =
{
    ANIMCMD_FRAME(.imageValue = 10, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 11, .duration = 54),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadAngry[] =
{
    ANIMCMD_FRAME(.imageValue = 10, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 12, .duration = 54),
    ANIMCMD_FRAME(.imageValue = 12, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HeadEndSpaAngry[] =
{
    ANIMCMD_FRAME(.imageValue = 10, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_FletchinderHead[] =
{
    sAnim_Normal,
    sAnim_HeadPet,
    sAnim_HeadFamished,
    sAnim_HeadReactToHoney,
    sAnim_HeadReturnToFamished,
    sAnim_HeadBite,
    sAnim_HeadMusic,
    sAnim_HeadBadTouch,
    sAnim_HeadAngry,
    sAnim_HeadEndSpaAngry,
};

static const union AnimCmd * const sAnims_FletchinderBodyRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_FletchinderBodyLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_WingFamished[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_WingBadTouch[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_WingEndSpaAngry[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 10),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 10),
    ANIMCMD_JUMP(1)
};

static const union AnimCmd sAnim_WingAngry[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_FletchinderWingRight[] =
{
    sAnim_Normal,
    sAnim_WingFamished,
    sAnim_WingBadTouch,
    sAnim_WingEndSpaAngry,
    sAnim_WingAngry,
};

static const union AnimCmd * const sAnims_FletchinderWingLeft[] =
{
    sAnim_Normal,
    sAnim_WingFamished,
    sAnim_WingBadTouch,
    sAnim_WingEndSpaAngry,
    sAnim_WingAngry,
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
    spa_frame(gFletchinderHead_Gfx, 1, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 2, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 3, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 4, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 5, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 6, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 7, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 8, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 9, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 10, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 11, 8, 8),
    spa_frame(gFletchinderHead_Gfx, 12, 8, 8),
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
    spa_frame(gFletchinderWingRight_Gfx, 1, 8, 8),
    spa_frame(gFletchinderWingRight_Gfx, 2, 8, 8),
    spa_frame(gFletchinderWingRight_Gfx, 3, 8, 8),
};

static const struct SpriteFrameImage sPicTable_FletchinderWingLeft[] =
{
    spa_frame(gFletchinderWingLeft_Gfx, 0, 8, 8),
    spa_frame(gFletchinderWingLeft_Gfx, 1, 8, 8),
    spa_frame(gFletchinderWingLeft_Gfx, 2, 8, 8),
    spa_frame(gFletchinderWingLeft_Gfx, 3, 8, 8),
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
    u32 i;

    for (i = 0; i < MAX_BUGS; i++)
    {
        if (FlagGet(FLAG_SPA_BUG_0_EATEN + i))
            tBugsEaten++;
    }

    if (tBugsEaten >= 4)
    {
        sSpaData.isSatisfied = TRUE;
    }

    sFletchinderHeadSpriteId = CreateSprite(&sSpriteTemplate_FletchinderHead, 157, 62, 9);
    gSprites[sFletchinderHeadSpriteId].sTaskId = taskId;
    if (!sSpaData.isSatisfied)
    {
        StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 2);
    }

    sFletchinderBodyRightSpriteId = CreateSprite(&sSpriteTemplate_FletchinderBodyRight, 128, 71, 10);
    gSprites[sFletchinderBodyRightSpriteId].sTaskId = taskId;

    sFletchinderBodyLeftSpriteId = CreateSprite(&sSpriteTemplate_FletchinderBodyLeft, 104, 71, 10);
    gSprites[sFletchinderBodyLeftSpriteId].sTaskId = taskId;

    sFletchinderWingRightSpriteId = CreateSprite(&sSpriteTemplate_FletchinderWingRight, 103, 66, 8);
    gSprites[sFletchinderWingRightSpriteId].sTaskId = taskId;
    if (!sSpaData.isSatisfied)
    {
        StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 1);
    }

    sFletchinderWingLeftSpriteId = CreateSprite(&sSpriteTemplate_FletchinderWingLeft, 39, 56, 8);
    gSprites[sFletchinderWingLeftSpriteId].sTaskId = taskId;
    if (!sSpaData.isSatisfied)
    {
        StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 1);
    }

    sFletchinderTailSpriteId = CreateSprite(&sSpriteTemplate_FletchinderTail, 74, 28, 9);
    gSprites[sFletchinderTailSpriteId].sTaskId = taskId;

    sFletchinderFeetSpriteId = CreateSprite(&sSpriteTemplate_FletchinderFeet, 128, 119, 10);
    gSprites[sFletchinderFeetSpriteId].sTaskId = taskId;

    sFletchinderWingBackRightSpriteId = CreateSprite(&sSpriteTemplate_FletchinderWingRight, 150, 69, 11);
    gSprites[sFletchinderWingBackRightSpriteId].sTaskId = taskId;
    gSprites[sFletchinderWingBackRightSpriteId].hFlip = TRUE;
    gSprites[sFletchinderWingBackRightSpriteId].invisible = TRUE;

    sFletchinderWingBackLeftSpriteId = CreateSprite(&sSpriteTemplate_FletchinderWingLeft, 214, 59, 11);
    gSprites[sFletchinderWingBackLeftSpriteId].sTaskId = taskId;
    gSprites[sFletchinderWingBackLeftSpriteId].hFlip = TRUE;
    gSprites[sFletchinderWingBackLeftSpriteId].invisible = TRUE;
}

bool32 HoneyHasBugs(void)
{
    u32 i;
    u32 bugsCollected = 0;
    u32 bugsEaten = 0;

    for (i = 0; i < MAX_BUGS; i++)
    {
        if (FlagGet(FLAG_SPA_PSYDUCK_BUG_0 + i))
            bugsCollected++;

        if (FlagGet(FLAG_SPA_BUG_0_EATEN + i))
            bugsEaten++;
    }

    return (bugsCollected > bugsEaten);
}

void StartFletchinderPet(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 1);
}

void StartFletchinderHappyAnim(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 6);
}

static void StartFletchinderBite(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 5);
}

void StartFletchinderBadTouch(u8 taskId)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 7);
    StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 2);
    StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 2);
    gSprites[sFletchinderWingBackRightSpriteId].invisible = FALSE;
    gSprites[sFletchinderWingBackLeftSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sFletchinderWingBackRightSpriteId], 2);
    StartSpriteAnim(&gSprites[sFletchinderWingBackLeftSpriteId], 2);
    PauseUntilAnimEnds(taskId, sFletchinderHeadSpriteId);
}

void StartFletchinderAngry(u8 taskId)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 8);
    StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 4);
    StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 4);
    PauseUntilAnimEnds(taskId, sFletchinderHeadSpriteId);
    CreateAngrySprite(taskId);
}

void FletchinderReactToHoney(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 3);
    StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 0);
}

void ResetFletchinderSpritesSatisfied(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderBodyRightSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderBodyLeftSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderTailSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderFeetSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingBackRightSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingBackLeftSpriteId], 0);
    gSprites[sFletchinderWingBackRightSpriteId].invisible = TRUE;
    gSprites[sFletchinderWingBackLeftSpriteId].invisible = TRUE;
}

void ResetFletchinderSpritesFamished(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 4);
    StartSpriteAnim(&gSprites[sFletchinderBodyRightSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderBodyLeftSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 1);
    StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 1);
    StartSpriteAnim(&gSprites[sFletchinderTailSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderFeetSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingBackRightSpriteId], 0);
    StartSpriteAnim(&gSprites[sFletchinderWingBackLeftSpriteId], 0);
    gSprites[sFletchinderWingBackRightSpriteId].invisible = TRUE;
    gSprites[sFletchinderWingBackLeftSpriteId].invisible = TRUE;
}

void EndSpaBadFletchinder(void)
{
    StartSpriteAnim(&gSprites[sFletchinderHeadSpriteId], 9);
    StartSpriteAnim(&gSprites[sFletchinderWingRightSpriteId], 3);
    StartSpriteAnim(&gSprites[sFletchinderWingLeftSpriteId], 3);
    gSprites[sFletchinderWingBackRightSpriteId].invisible = FALSE;
    gSprites[sFletchinderWingBackLeftSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sFletchinderWingBackRightSpriteId], 3);
    StartSpriteAnim(&gSprites[sFletchinderWingBackLeftSpriteId], 3);
}

static const u16 FletchinderFeedingZone[4] =
{
    // MIN_X, MAX_X, MIN_Y, MAX_Y
       170,   195,   80,    95
};

static bool32 IsHoneyInFeedingZone(void)
{
    if (gSprites[sSpaData.honeySpriteId].x > FletchinderFeedingZone[0] && gSprites[sSpaData.honeySpriteId].x < FletchinderFeedingZone[1] 
     && gSprites[sSpaData.honeySpriteId].y > FletchinderFeedingZone[2] && gSprites[sSpaData.honeySpriteId].y < FletchinderFeedingZone[3])
    {
        return TRUE;
    }

    return FALSE;
}

static void FletchinderEatBug(u8 taskId)
{
    u32 i;

    for (i = 0; i < MAX_BUGS; i++)
    {
        if (!FlagGet(FLAG_SPA_BUG_0_EATEN + i))
        {
            FlagSet(FLAG_SPA_BUG_0_EATEN + i);
            break;
        }
    }
    tBugsEaten++;
    StartSpriteAnim(&gSprites[sSpaData.honeySpriteId], gSprites[sSpaData.honeySpriteId].animNum - 1);
}

void HandleItemsFletchinder(u8 taskId)
{
    switch (tSelectedItem)
    {
    case SPA_BERRY:
        break;
    case SPA_CLAW:
        break;
    case SPA_HONEY:
        if (tBiteState == BITE_STATE_ACTIVE && gSprites[sSpaData.honeySpriteId].oam.priority != 0 && !IsHoneyInFeedingZone())
        {
            gSprites[sSpaData.honeySpriteId].oam.priority = 0;
            gSprites[sSpaData.honeySpriteId].subpriority = 5;
        }

        if (gSprites[sSpaData.honeySpriteId].oam.priority != 1 && IsHoneyInFeedingZone())
        {
            gSprites[sSpaData.honeySpriteId].oam.priority = 1;
            gSprites[sSpaData.honeySpriteId].subpriority = 11;
        }

        if (tBiteState == BITE_STATE_ACTIVE && gSprites[sFletchinderHeadSpriteId].animEnded)
        {
            if (tBugsEaten >= 4)
            {
                DestroySprite(&gSprites[sSpaData.honeySpriteId]);
                StartFletchinderHappyAnim();
                PauseUntilAnimEnds(taskId, sFletchinderHeadSpriteId);
                CreateMusicSprite(taskId);
                DoSpaMonEnjoyedSnackText();
                sSpaData.isSatisfied = TRUE;
            }
            tBiteState = BITE_STATE_NONE;
        }

        if (!sSpaData.isSatisfied && HoneyHasBugs() && IsHoneyInFeedingZone())
            switch (tBiteState)
            {
            case BITE_STATE_NONE:
                StartFletchinderBite();
                tCounter = 0;
                tBiteState = BITE_STATE_ACTIVE;
                break;
            case BITE_STATE_ACTIVE:
                if (gSprites[sFletchinderHeadSpriteId].animCmdIndex == 4)
                {
                    FletchinderEatBug(taskId);
                }
                else if (tCounter == 25)
                {
                    PlaySE(SE_M_ABSORB);
                    tCounter++;
                }
                    tCounter++;
                break;
            }
        break;
    case SPA_ORB:
        break;
    }
}
