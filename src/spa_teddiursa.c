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

static void SpriteCB_TeddyEye(struct Sprite *sprite);
static void SpriteCB_TeddyMouth(struct Sprite *sprite);
static void SpriteCB_TeddyArm(struct Sprite *sprite);
static void SpriteCB_TeddyItch(struct Sprite *sprite);

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
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_EyeHappy[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_EyeShutBad[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 16),
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

static const union AnimCmd * const sAnims_TeddyMouth[] =
{
    sAnim_Normal,
    sAnim_MouthHappyOpen,
    sAnim_MouthO,
    sAnim_MouthFrown,
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
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
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

static const union AnimCmd * const sAnims_TeddyArm[] =
{
    sAnim_Normal,
    sAnim_ArmScratch,
    sAnim_ArmScratchToNormal,
    sAnim_ArmBadTouch,
    sAnim_ArmAttack,
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
};

static const struct SpriteFrameImage sPicTable_TeddyMouth[] =
{
    spa_frame(gTeddiursaMouth_Gfx, 0, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 1, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 2, 2, 2),
    spa_frame(gTeddiursaMouth_Gfx, 3, 2, 2),
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
    .callback = SpriteCB_TeddyMouth
};

static const struct SpriteTemplate sSpriteTemplate_TeddyArm =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_MON,
    .oam = &sOam_64x64,
    .anims = sAnims_TeddyArm,
    .images = sPicTable_TeddyArm,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TeddyArm
};

static const struct SpriteTemplate sSpriteTemplate_TeddyItch =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITCH,
    .oam = &sOam_32x32,
    .anims = sAnims_TeddyItch,
    .images = sPicTable_TeddyItch,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TeddyItch
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
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 3);
    gSprites[sTeddyEyeSpriteId].sInterval = (Random() % 180) + 180;

    sTeddyMouthSpriteId = CreateSprite(&sSpriteTemplate_TeddyMouth, 106, 63, 8);
    gSprites[sTeddyMouthSpriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 3);

    sTeddyArmSpriteId = CreateSprite(&sSpriteTemplate_TeddyArm, 109, 81, 8);
    gSprites[sTeddyArmSpriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 1);

    sTeddyItchSpriteId = CreateSprite(&sSpriteTemplate_TeddyItch, 141, 92, 9);
    gSprites[sTeddyItchSpriteId].sTaskId = taskId;
}

void TeddiursaReactToClaw(void)
{
    StartSpriteAnim(&gSprites[sTeddyArmSpriteId], 2);
    StartSpriteAnim(&gSprites[sTeddyMouthSpriteId], 0);
    StartSpriteAnim(&gSprites[sTeddyEyeSpriteId], 0);
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
        break;
    case SPA_CLAW:
        if (IsClawInItchArea())
        {
            if (JOY_HELD(DPAD_ANY))
            {
                tScratchScore++;
                if (tScratchScore % 15 == 0)
                {
                    if (tItchFadeCount < 16)
                    {
                        tItchFadeCount++;
                    }
                    else
                    {
                        sSpaData.isSatisfied = TRUE;
                        DestroySprite(&gSprites[sTeddyItchSpriteId]);
                        return;
                    }

                    BlendPalettes(1 << (IndexOfSpritePaletteTag(TAG_ITCH) + 16), tItchFadeCount, RGB2GBA(230, 148, 92));
                }
            }
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

}

static void SpriteCB_TeddyMouth(struct Sprite *sprite)
{
    
}

static void SpriteCB_TeddyArm(struct Sprite *sprite)
{
    
}

static void SpriteCB_TeddyItch(struct Sprite *sprite)
{
    
}
