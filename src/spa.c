#include "global.h"
#include "spa.h"
#include "bg.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

static void ResetForMinigame1(void);
static void ResetForMinigame2(void);
static void CreateRattataSprites(u8 taskId);
static void VblankCB_SpaGame(void);
static void CB2_SpaGame(void);
static void Task_StartSpaGame(u8 taskId);
static void Task_StartSpa(u8 taskId);
static void SpriteCB_RatBodyLeft(struct Sprite *sprite);
static void SpriteCB_RatBodyRight(struct Sprite *sprite);
static void SpriteCB_RatTail(struct Sprite *sprite);
static void SpriteCB_RatEarLeft(struct Sprite *sprite);
static void SpriteCB_RatEarRight(struct Sprite *sprite);
static void SpriteCB_RatMouth(struct Sprite *sprite);
static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite);
static void SpriteCB_RatWhiskerRight(struct Sprite *sprite);
static void SpriteCB_RatToes(struct Sprite *sprite);

static const u32 gSpaBG_Gfx[] = INCBIN_U32("graphics/_spa/spa_bg.4bpp.lz");
static const u32 gSpaBG_Tilemap[] = INCBIN_U32("graphics/_spa/spa_bg.bin.lz");
static const u16 gSpaBG_Pal[] = INCBIN_U16("graphics/_spa/spa_bg.gbapal");

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

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 0x0200
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sBgTemplates[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const union AnimCmd sAnim_RatBodyLeftNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatBodyLeft[] =
{
    sAnim_RatBodyLeftNormal,
};

static const union AnimCmd sAnim_RatBodyRightNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatBodyRight[] =
{
    sAnim_RatBodyRightNormal,
};

static const union AnimCmd sAnim_RatTailNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatTail[] =
{
    sAnim_RatTailNormal,
};

static const union AnimCmd sAnim_RatEarLeftNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatEarLeft[] =
{
    sAnim_RatEarLeftNormal,
};

static const union AnimCmd sAnim_RatEarRightNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatEarRight[] =
{
    sAnim_RatEarRightNormal,
};

static const union AnimCmd sAnim_RatMouthNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatMouth[] =
{
    sAnim_RatMouthNormal,
};

static const union AnimCmd sAnim_RatWhiskerLeftNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatWhiskerLeft[] =
{
    sAnim_RatWhiskerLeftNormal,
};

static const union AnimCmd sAnim_RatWhiskerRightNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatWhiskerRight[] =
{
    sAnim_RatWhiskerRightNormal,
};

static const union AnimCmd sAnim_RatToesNormal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatToes[] =
{
    sAnim_RatToesNormal,
};

static const struct SpriteFrameImage sPicTable_RatBodyLeft[] =
{
    treasure_score_frame(gRattataBodyLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatBodyRight[] =
{
    treasure_score_frame(gRattataBodyRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatTail[] =
{
    treasure_score_frame(gRattataTail_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatEarLeft[] =
{
    treasure_score_frame(gRattataEarLeft_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatEarRight[] =
{
    treasure_score_frame(gRattataEarRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatMouth[] =
{
    treasure_score_frame(gRattataMouth_Gfx, 0, 8, 4),
};

static const struct SpriteFrameImage sPicTable_RatWhiskerLeft[] =
{
    treasure_score_frame(gRattataWhiskerLeft_Gfx, 0, 8, 4),
};

static const struct SpriteFrameImage sPicTable_RatWhiskerRight[] =
{
    treasure_score_frame(gRattataWhiskerRight_Gfx, 0, 8, 4),
};

static const struct SpriteFrameImage sPicTable_RatToes[] =
{
    treasure_score_frame(gRattataToes_Gfx, 0, 2, 1),
};

static const struct OamData sOam_64x64 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_64x32 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_16x8 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
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
    .callback = SpriteCB_RatToes
};

static const struct SpritePalette sSpritePalettes_RattataSpa[] =
{
    {
        .data = gRattata_Pal,
        .tag = TAG_RATTATA
    },
    {NULL},
};

void CB2_InitRattata(void)
{
    u8 taskId;

    ResetForMinigame1();
    
    LZ77UnCompVram(gSpaBG_Gfx, (void*) BG_CHAR_ADDR(1));
    LZ77UnCompVram(gSpaBG_Tilemap, (u16*) BG_SCREEN_ADDR(6));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    
    ResetForMinigame2();

    LoadPalette(gSpaBG_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    LoadSpritePalettes(sSpritePalettes_RattataSpa);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_SpaGame);
    SetMainCallback2(CB2_SpaGame);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    taskId = CreateTask(Task_StartSpaGame, 1);

    CreateRattataSprites(taskId);
}

static void ResetForMinigame1(void)
{
    SetVBlankCallback(NULL);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
}

static void ResetForMinigame2(void)
{
    DeactivateAllTextPrinters();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
}

static void CreateRattataSprites(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_RatBodyLeft, 86, 73, 12);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatBodyRight, 150, 81, 12);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatTail, 80, 33, 11);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEarLeft, 111, 32, 10);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEarRight, 175, 32, 10);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatMouth, 144, 80, 10);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatWhiskerLeft, 88, 59, 9);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatWhiskerRight, 199, 57, 9);
    gSprites[spriteId].data[0] = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatToes, 96, 109, 12);
    gSprites[spriteId].data[0] = taskId;
}

static void VblankCB_SpaGame(void)
{
    RunTextPrinters();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_SpaGame(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_StartSpaGame(u8 taskId)
{
    RunTextPrinters();

    if (gTasks[taskId].data[1] == 0)
    {
        DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_YouHaveNoBerries, 0, 1, 0, NULL);
        ScheduleBgCopyTilemapToVram(0);
        gTasks[taskId].data[1]++;
    }
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

}

static void SpriteCB_RatEarRight(struct Sprite *sprite)
{

}

static void SpriteCB_RatMouth(struct Sprite *sprite)
{

}

static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite)
{

}

static void SpriteCB_RatWhiskerRight(struct Sprite *sprite)
{

}

static void SpriteCB_RatToes(struct Sprite *sprite)
{

}

void Script_StartSpa(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_StartSpa, 1);
}

static void Task_StartSpa(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        PlayBGM(MUS_TRICK_HOUSE);
        SetMainCallback2(CB2_InitRattata);
        gMain.savedCallback = CB2_ReturnToField;
        DestroyTask(taskId);
    }
}