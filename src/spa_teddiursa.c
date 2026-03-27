#include "global.h"
#include "spa.h"
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

#define sTeddyHeadLeftSpriteId      sSpaData.monSpriteIds[0]
#define sTeddyHeadRightSpriteId     sSpaData.monSpriteIds[1]
#define sTeddyBodySpriteId          sSpaData.monSpriteIds[2]
#define sTeddyTailSpriteId          sSpaData.monSpriteIds[3]
#define sTeddyFootSpriteId          sSpaData.monSpriteIds[4]
#define sTeddyEarsSpriteId          sSpaData.monSpriteIds[5]
#define sTeddyEyeSpriteId           sSpaData.monSpriteIds[6]
#define sTeddyMouthSpriteId         sSpaData.monSpriteIds[7]
#define sTeddyArmSpriteId           sSpaData.monSpriteIds[8]
#define sTeddyItchSpriteId          sSpaData.monSpriteIds[9]

#define TEDDIURSA_SNATCH_BERRY_THRESHOLD   75

static void SpriteCB_TeddyEye(struct Sprite *sprite);

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

static const u16 gTeddiursaItch_Pal[] = INCBIN_U16("graphics/_spa/teddiursa/teddiursa_itch.gbapal");
static const u32 gTeddiursaItch_Gfx[] = INCBIN_U32("graphics/_spa/teddiursa/teddiursa_itch.4bpp");

enum TeddiursaScratchStates
{
    SCRATCH_STATE_NONE,
    SCRATCH_STATE_ACTIVE,
    SCRATCH_STATE_END
};

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

static const union AnimCmd sAnim_EyeMad[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_EyeHappy[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_EyeShutBad[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_EyeGrabBerry[] =
{
    ANIMCMD_FRAME(.imageValue = 6, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_EyesBlink[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 5, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_TeddyEye[] =
{
    sAnim_Normal,
    sAnim_EyeMad,
    sAnim_EyeHappy,
    sAnim_EyeShutBad,
    sAnim_EyesBlink,
    sAnim_EyeGrabBerry,
};

static const union AnimCmd sAnim_MouthHappyOpen[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MouthO[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MouthFrown[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MouthHappyClosed[] =
{
    ANIMCMD_FRAME(.imageValue = 4, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MouthEatBerry[] =
{
    ANIMCMD_FRAME(.imageValue = 4, .duration = 32),
    ANIMCMD_FRAME(.imageValue = 6, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 5, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 6, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 4),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_TeddyMouth[] =
{
    sAnim_Normal,
    sAnim_MouthHappyOpen,
    sAnim_MouthO,
    sAnim_MouthFrown,
    sAnim_MouthHappyClosed,
    sAnim_MouthEatBerry,
};

static const union AnimCmd sAnim_ArmScratch[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 4, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 3, .duration = 16),
    ANIMCMD_JUMP(2)
};

static const union AnimCmd sAnim_ArmScratchToNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ArmBadTouch[] =
{
    ANIMCMD_FRAME(.imageValue = 5, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ArmAttack[] =
{
    ANIMCMD_FRAME(.imageValue = 6, .duration = 52),
    ANIMCMD_FRAME(.imageValue = 7, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 8, .duration = 4),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ArmGrabBerry[] =
{
    ANIMCMD_FRAME(.imageValue = 9, .duration = 8),
    ANIMCMD_FRAME(.imageValue = 10, .duration = 52),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_TeddyArm[] =
{
    sAnim_Normal,
    sAnim_ArmScratch,
    sAnim_ArmScratchToNormal,
    sAnim_ArmBadTouch,
    sAnim_ArmAttack,
    sAnim_ArmGrabBerry,
};

static const union AnimCmd * const sAnims_TeddyItch[] =
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
    spa_frame(gTeddiursaEye_Gfx, 1, 2, 2),
    spa_frame(gTeddiursaEye_Gfx, 2, 2, 2),
    spa_frame(gTeddiursaEye_Gfx, 3, 2, 2),
    spa_frame(gTeddiursaEye_Gfx, 4, 2, 2),
    spa_frame(gTeddiursaEye_Gfx, 5, 2, 2),
    spa_frame(gTeddiursaEye_Gfx, 6, 2, 2),
};

static const struct SpriteFrameImage sPicTable_TeddyMouth[] =
{
    spa_frame(gTeddiursaMouth_Gfx, 0, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 1, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 2, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 3, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 4, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 5, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 6, 2, 2),
};

static const struct SpriteFrameImage sPicTable_TeddyArm[] =
{
    spa_frame(gTeddiursaArm_Gfx, 0, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 1, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 2, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 3, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 4, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 5, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 6, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 7, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 8, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 9, 8, 8),
    spa_frame(gTeddiursaArm_Gfx, 10, 8, 8),
};

static const struct SpriteFrameImage sPicTable_TeddyItch[] =
{
    spa_frame(gTeddiursaItch_Gfx, 0, 4, 4),
};

static const struct SpriteTemplate sSpriteTemplate_TeddyHeadLeft =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyHeadLeft,
    .images = sPicTable_TeddyHeadLeft,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyHeadRight =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyHeadRight,
    .images = sPicTable_TeddyHeadRight,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyBody =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyBody,
    .images = sPicTable_TeddyBody,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyTail =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_32x32,
    .anims = sAnims_TeddyTail,
    .images = sPicTable_TeddyTail,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyFoot =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_32x32,
    .anims = sAnims_TeddyFoot,
    .images = sPicTable_TeddyFoot,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyEars =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyEars,
    .images = sPicTable_TeddyEars,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyEye =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_16x16,
    .anims = sAnims_TeddyEye,
    .images = sPicTable_TeddyEye,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TeddyEye
};

static const struct SpriteTemplate sSpriteTemplate_TeddyMouth =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_16x16,
    .anims = sAnims_TeddyMouth,
    .images = sPicTable_TeddyMouth,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyArm =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyArm,
    .images = sPicTable_TeddyArm,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_TeddyItch =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITCH,
    .oam = &sOam_32x32,
    .anims = sAnims_TeddyItch,
    .images = sPicTable_TeddyItch,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct SpritePalette sSpritePalettes_SpaTeddiursa[] =
{
    {
        .data = gTeddiursa_Pal,
        .tag = TAG_MON
    },
    {
        .data = gTeddiursaItch_Pal,
        .tag = TAG_ITCH
    },
    {NULL},
};

void CreateTeddiursaSprites(u8 taskId)
{
    if (FlagGet(FLAG_SPA_TEDDIURSA_SATISFIED))
        sSpaData.isSatisfied = TRUE;

    sTeddyHeadLeftSpriteId = CreateSprite(&sSpriteTemplate_TeddyHeadLeft, 100, 48, 9);
    gSprites[sTeddyHeadLeftSpriteId].sTaskId = taskId;

    sTeddyHeadRightSpriteId = CreateSprite(&sSpriteTemplate_TeddyHeadRight, 164, 48, 9);
    gSprites[sTeddyHeadRightSpriteId].sTaskId = taskId;

    sTeddyBodySpriteId = CreateSprite(&sSpriteTemplate_TeddyBody, 133, 94, 10);
    gSprites[sTeddyBodySpriteId].sTaskId = taskId;

    sTeddyTailSpriteId = CreateSprite(&sSpriteTemplate_TeddyTail, 142, 112, 7);
    gSprites[sTeddyTailSpriteId].sTaskId = taskId;

    sTeddyFootSpriteId = CreateSprite(&sSpriteTemplate_TeddyFoot, 100, 104, 11);
    gSprites[sTeddyFootSpriteId].sTaskId = taskId;

    sTeddyEarsSpriteId = CreateSprite(&sSpriteTemplate_TeddyEars, 130, 27, 8);
    gSprites[sTeddyEarsSpriteId].sTaskId = taskId;

    sTeddyEyeSpriteId = CreateSprite(&sSpriteTemplate_TeddyEye, 115, 50, 8);
    gSprites[sTeddyEyeSpriteId].sTaskId = taskId;
    gSprites[sTeddyEyeSpriteId].sInterval = (Random() % BLINK_INTERVAL) + BLINK_INTERVAL;
    if (!sSpaData.isSatisfied)
        StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 3);

    sTeddyMouthSpriteId = CreateSprite(&sSpriteTemplate_TeddyMouth, 106, 63, 8);
    gSprites[sTeddyMouthSpriteId].sTaskId = taskId;
    if (!sSpaData.isSatisfied)
        StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 3);

    sTeddyArmSpriteId = CreateSprite(&sSpriteTemplate_TeddyArm, 109, 81, 8);
    gSprites[sTeddyArmSpriteId].sTaskId = taskId;
    if (!sSpaData.isSatisfied)
        StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 1);

    if (!sSpaData.isSatisfied)
    {
        sTeddyItchSpriteId = CreateSprite(&sSpriteTemplate_TeddyItch, 141, 92, 9);
        gSprites[sTeddyItchSpriteId].sTaskId = taskId;
    }
}

void TeddiursaReactToClaw(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 2);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 0);
}

void ResetTeddiursaSpritesNormal(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 0);
}

void ResetTeddiursaSpritesScratch(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 1);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 3);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 3);
}

static void StartTeddiursaBeingScratched(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 2);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 2);
}

void StartTeddiursaHappyAnim(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 1);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 2);
}

void StartTeddiursaPet(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 4);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 2);
}

void StartTeddiursaBadTouch(u8 taskId)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 3);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 3);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 3);
    PauseUntilAnimEnds(taskId, sTeddyEyeSpriteId);
}

void StartTeddiursaAngry(u8 taskId)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 3);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 1);
    PauseUntilAnimEnds(taskId, sTeddyEyeSpriteId);
    CreateAngrySprite(taskId);
}

static void StartTeddiursaGrabBerry(u8 taskId)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 5);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 5);
    gSprites[sSpaData.berrySpriteId].oam.priority = 1;
    gSprites[sSpaData.berrySpriteId].subpriority = 12;
}

void EndSpaBadTeddiursa(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 4);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 3);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 1);
}

static bool32 IsClawInItchArea(void)
{
    if (gSprites[sSpaData.clawSpriteId].x > 135 && gSprites[sSpaData.clawSpriteId].x < 165 
     && gSprites[sSpaData.clawSpriteId].y > 86  && gSprites[sSpaData.clawSpriteId].y < 108)
    {
        return TRUE;
    }

    return FALSE;
}

void HandleItemsTeddiursa(u8 taskId)
{
    switch (tSelectedItem)
    {
    case SPA_BERRY:
        if (sSpaData.isSatisfied)
        {
            if (tBerryBites >= 3)
            {
                tBerryBites = 0;
                StartTeddiursaHappyAnim();
                PauseUntilAnimEnds(taskId, sTeddyEyeSpriteId);
                DoSpaMonEnjoyedSnackText();
                CreateMusicSprite(taskId);
                return;
            }

            if (!sSpaData.pausedSpriteId && gSprites[sSpaData.berrySpriteId].sCounter == 0 && gSprites[sSpaData.berrySpriteId].x > TEDDIURSA_SNATCH_BERRY_THRESHOLD)
            {
                gSprites[sSpaData.berrySpriteId].sCounter = 1;
                PlaySE(SE_CLICK);
                StartTeddiursaGrabBerry(taskId);
            }

            if (gSprites[sSpaData.berrySpriteId].sCounter != 0 && gSprites[sTeddyArmSpriteId].animEnded)
            {
                switch (tBiteState)
                {
                case BITE_STATE_NONE:
                    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 5);
                    tCounter = 0;
                    tBiteState = BITE_STATE_ACTIVE;
                    break;
                case BITE_STATE_ACTIVE:
                    if (gSprites[sTeddyMouthSpriteId].animEnded)
                    {
                        tBerryBites++;
                        if (tBerryBites < 3)
                            StartSpriteAnim(&gSprites[sSpaData.berrySpriteId], gSprites[sSpaData.berrySpriteId].animNum + 1);
                        else
                            DestroySprite(&gSprites[sSpaData.berrySpriteId]);
                        tBiteState = BITE_STATE_NONE;
                    }
                    else if (tCounter == 56)
                    {
                        PlaySE(SE_M_BITE);
                        tCounter++;
                    }
                    else if (tCounter < 56)
                    {
                        tCounter++;
                    }
                    break;
                }
            }
        }
        break;
    case SPA_CLAW:
        if (tItchFadeCount >= 16)
        {
            StartTeddiursaHappyAnim();
            PauseUntilAnimEnds(taskId, sTeddyEyeSpriteId);
            CreateMusicSprite(taskId);
            DoSpaMonFeelsBetterText();
            DestroySprite(&gSprites[sTeddyItchSpriteId]);
            FlagSet(FLAG_SPA_TEDDIURSA_SATISFIED);
            sSpaData.isSatisfied = TRUE;
        }
        else if (IsClawInItchArea())
        {
            switch (tScratchState)
            {
            case SCRATCH_STATE_NONE:
                if (JOY_HELD(DPAD_ANY))
                {
                    StartTeddiursaBeingScratched();
                    tCounter = 0;
                    tScratchState = SCRATCH_STATE_ACTIVE;
                }
                break;
            case SCRATCH_STATE_ACTIVE:
                if (JOY_HELD(DPAD_ANY))
                {
                    tCounter = 0;
                    tScratchScore++;
                    if (tScratchScore % 15 == 0)
                    {
                        tItchFadeCount++;
                        BlendPalettes(1 << (IndexOfSpritePaletteTag(TAG_ITCH) + 16), tItchFadeCount, RGB2GBA(230, 148, 92));
                    }
                }
                else
                {
                    if (tItchFadeCount < 16)
                    {
                        if (tCounter == 60)
                        {
                            ResetTeddiursaSpritesNormal();
                            tScratchState = SCRATCH_STATE_NONE;
                        }
                        tCounter++;
                    }
                }
                break;
            }
        }
        else if (tScratchState == SCRATCH_STATE_ACTIVE)
        {
            ResetTeddiursaSpritesNormal();
            tScratchState = SCRATCH_STATE_NONE;
        }
        break;
    case SPA_HONEY:
        break;
    case SPA_ORB:
        break;
    }
}

static void SpriteCB_TeddyEye(struct Sprite *sprite)
{
    if (sprite->animNum == 0 || sprite->animNum == 4)
    {
        if (sprite->sBlinkCounter == sprite->sInterval)
        {
            StartSpriteAnim(sprite, 4); // Blink.
            sprite->sInterval = (Random() % BLINK_INTERVAL) + BLINK_INTERVAL; // 3 to 6 seconds.
            sprite->sBlinkCounter = 0;
        }
        else
        {
            sprite->sBlinkCounter++;
        }
    }
}
