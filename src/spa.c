#include "global.h"
#include "spa.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "spa_rattata.h"
#include "spa_teddiursa.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

static void ResetForMinigame1(void);
static void ResetForMinigame2(void);
static void LoadMonSpritePalettes(void);
static void CreateSpaSprites(u8 taskId);
static void CreateSpaMonSprites(u8 taskId);
static void VblankCB_SpaGame(void);
static void CB2_SpaGame(void);
static void Task_StartSpaGame(u8 taskId);
static void PlaySpaMonCry(u8 mode);
static void SetItemFlagBits(u8 taskId);
static void Task_SpaGame(u8 taskId);
static void MoveSpriteFromInput(struct Sprite *sprite);
static void SpriteCB_Hand(struct Sprite *sprite);
static void SpriteCB_Music(struct Sprite *sprite);
static u8 GetCurrentPettingArea(struct Sprite *sprite);
static void AdjustToPetArea(struct Sprite *sprite, u8 area);
static void StopPetting(struct Sprite *sprite);
static bool8 IsHandOnItemsIcon(struct Sprite *sprite);
static bool8 IsHandOnExitIcon(struct Sprite *sprite);
static void SpriteCB_ItemTray(struct Sprite *sprite);
static void SpriteCB_Selector(struct Sprite *sprite);
static void SpriteCB_Angry(struct Sprite *sprite);
static void SpriteCB_Heart(struct Sprite *sprite);
static void SpriteCB_Berry(struct Sprite *sprite);
static void SpriteCB_Claw(struct Sprite *sprite);
static void Task_ScriptStartSpa(u8 taskId);

static const u32 gSpaBG_Gfx[] = INCBIN_U32("graphics/_spa/spa_bg.4bpp.lz");
static const u32 gSpaBG_Tilemap[] = INCBIN_U32("graphics/_spa/spa_bg.bin.lz");
static const u16 gSpaBG_Pal[] = INCBIN_U16("graphics/_spa/spa_bg.gbapal");

static const u16 gHand_Pal[] = INCBIN_U16("graphics/_spa/hand.gbapal");
static const u32 gHand_Gfx[] = INCBIN_U32("graphics/_spa/hand.4bpp");
static const u32 gMusic_Gfx[] = INCBIN_U32("graphics/_spa/music.4bpp");

static const u16 gItemsIcon_Pal[] = INCBIN_U16("graphics/_spa/items_icon.gbapal");
static const u32 gItemsIcon_Gfx[] = INCBIN_U32("graphics/_spa/items_icon.4bpp");
static const u32 gExitIcon_Gfx[] = INCBIN_U32("graphics/_spa/exit_icon.4bpp");
static const u32 gItemTray_Gfx[] = INCBIN_U32("graphics/_spa/item_tray.4bpp");
static const u32 gSelector_Gfx[] = INCBIN_U32("graphics/_spa/selector.4bpp");
static const u32 gAngry_Gfx[] = INCBIN_U32("graphics/_spa/angry.4bpp");
static const u32 gHeart_Gfx[] = INCBIN_U32("graphics/_spa/heart.4bpp");

static const u16 gBerry_Pal[] = INCBIN_U16("graphics/_spa/berry.gbapal");
static const u32 gBerry_Gfx[] = INCBIN_U32("graphics/_spa/berry.4bpp");

static const u16 gClaw_Pal[] = INCBIN_U16("graphics/_spa/claw.gbapal");
static const u32 gClaw_Gfx[] = INCBIN_U32("graphics/_spa/claw.4bpp");

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 5,
        .tilemapTop = 17,
        .width = 24,
        .height = 2,
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

static const union AnimCmd sAnim_Normal[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HandOpen[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HandFood[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Hand[] =
{
    sAnim_Normal,
    sAnim_HandOpen,
    sAnim_HandFood,
};

static const union AnimCmd * const sAnims_Music[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_IconPress[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Icon[] =
{
    sAnim_Normal,
    sAnim_IconPress,
};

static const union AnimCmd * const sAnims_ItemTray[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_Selector[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_Angry[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 24),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 24),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 24),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 24),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 24),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Angry[] =
{
    sAnim_Angry,
};

static const union AnimCmd * const sAnims_Heart[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_Berry1Bite[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Berry2Bites[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Berry[] =
{
    sAnim_Normal,
    sAnim_Berry1Bite,
    sAnim_Berry2Bites,
};

static const union AnimCmd * const sAnims_Claw[] =
{
    sAnim_Normal,
};

static const struct SpriteFrameImage sPicTable_Hand[] =
{
    spa_frame(gHand_Gfx, 0, 4, 4),
    spa_frame(gHand_Gfx, 1, 4, 4),
    spa_frame(gHand_Gfx, 2, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Music[] =
{
    spa_frame(gMusic_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_ItemsIcon[] =
{
    spa_frame(gItemsIcon_Gfx, 0, 4, 4),
    spa_frame(gItemsIcon_Gfx, 1, 4, 4),
};

static const struct SpriteFrameImage sPicTable_ExitIcon[] =
{
    spa_frame(gExitIcon_Gfx, 0, 4, 4),
    spa_frame(gExitIcon_Gfx, 1, 4, 4),
};

static const struct SpriteFrameImage sPicTable_ItemTray[] =
{
    spa_frame(gItemTray_Gfx, 0, 4, 8),
};

static const struct SpriteFrameImage sPicTable_Selector[] =
{
    spa_frame(gSelector_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Angry[] =
{
    spa_frame(gAngry_Gfx, 0, 4, 4),
    spa_frame(gAngry_Gfx, 1, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Heart[] =
{
    spa_frame(gHeart_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Berry[] =
{
    spa_frame(gBerry_Gfx, 0, 4, 4),
    spa_frame(gBerry_Gfx, 1, 4, 4),
    spa_frame(gBerry_Gfx, 2, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Claw[] =
{
    spa_frame(gClaw_Gfx, 0, 4, 4),
};

static const struct SpriteTemplate sSpriteTemplate_Hand =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32,
    .anims = sAnims_Hand,
    .images = sPicTable_Hand,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Hand
};

static const struct SpriteTemplate sSpriteTemplate_Music =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32,
    .anims = sAnims_Music,
    .images = sPicTable_Music,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Music
};

static const struct SpriteTemplate sSpriteTemplate_ItemsIcon =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x32,
    .anims = sAnims_Icon,
    .images = sPicTable_ItemsIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ExitIcon =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x32,
    .anims = sAnims_Icon,
    .images = sPicTable_ExitIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_ItemTray =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x64,
    .anims = sAnims_ItemTray,
    .images = sPicTable_ItemTray,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ItemTray
};

static const struct SpriteTemplate sSpriteTemplate_Selector =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32,
    .anims = sAnims_Selector,
    .images = sPicTable_Selector,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Selector
};

static const struct SpriteTemplate sSpriteTemplate_Angry =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x32,
    .anims = sAnims_Angry,
    .images = sPicTable_Angry,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Angry
};

static const struct SpriteTemplate sSpriteTemplate_Heart =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x32,
    .anims = sAnims_Heart,
    .images = sPicTable_Heart,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Heart
};

static const struct SpriteTemplate sSpriteTemplate_Berry =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY,
    .oam = &sOam_32x32,
    .anims = sAnims_Berry,
    .images = sPicTable_Berry,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Berry
};

static const struct SpriteTemplate sSpriteTemplate_Claw =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_CLAW,
    .oam = &sOam_32x32,
    .anims = sAnims_Claw,
    .images = sPicTable_Claw,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Claw
};

static const struct SpritePalette sSpritePalettes_Spa[] =
{
    {
        .data = gHand_Pal,
        .tag = TAG_HAND
    },
    {
        .data = gItemsIcon_Pal,
        .tag = TAG_ITEMS_ICON
    },
    {
        .data = gBerry_Pal,
        .tag = TAG_BERRY
    },
    {
        .data = gClaw_Pal,
        .tag = TAG_CLAW
    },
    {NULL},
};

void CB2_InitSpa(void)
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
    LoadSpritePalettes(sSpritePalettes_Spa);
    LoadMonSpritePalettes();

    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaInstructions, 0, 0, 0, NULL);
    FillPalette(RGB2GBA(238, 195, 154), BG_PLTT_ID(14) + 1, PLTT_SIZEOF(1));
    FillPalette(RGB2GBA(80, 50, 50), BG_PLTT_ID(14) + 2, PLTT_SIZEOF(1));
    FillPalette(RGB2GBA(180, 148, 117), BG_PLTT_ID(14) + 3, PLTT_SIZEOF(1));
    ScheduleBgCopyTilemapToVram(0);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_SpaGame);
    SetMainCallback2(CB2_SpaGame);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);

    taskId = CreateTask(Task_StartSpaGame, 1);

    SetItemFlagBits(taskId);
    CreateSpaSprites(taskId);
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

static void LoadMonSpritePalettes(void)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        LoadSpritePalettes(sSpritePalettes_SpaRattata);
        break;
    case SPA_TEDDIURSA:
        LoadSpritePalettes(sSpritePalettes_SpaTeddiursa);
        break;
    }
}

static void CreateSpaSprites(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_Hand, 28, 45, 5);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].oam.priority = 0;
    VarSet(VAR_HAND_SPRITE_ID, spriteId);

    spriteId = CreateSprite(&sSpriteTemplate_ItemsIcon, 16, 144, 7);
    gSprites[spriteId].sTaskId = taskId;
    VarSet(VAR_ITEMS_ICON_SPRITE_ID, spriteId);

    spriteId = CreateSprite(&sSpriteTemplate_ExitIcon, 16, 16, 7);
    gSprites[spriteId].sTaskId = taskId;
    VarSet(VAR_ITEMS_EXIT_SPRITE_ID, spriteId);

    CreateSpaMonSprites(taskId);
}

static void CreateSpaMonSprites(u8 taskId)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        CreateRattataSprites(taskId);
        break;
    case SPA_TEDDIURSA:
        CreateTeddiursaSprites(taskId);
        break;
    }
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
    if (!gPaletteFade.active)
    {
        PlaySpaMonCry(CRY_MODE_NORMAL);
        gTasks[taskId].func = Task_SpaGame;
    }
}

static void PlaySpaMonCry(u8 mode)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        PlayCry_ByMode(SPECIES_RATTATA, 0, mode);
        break;
    case SPA_TEDDIURSA:
        PlayCry_ByMode(SPECIES_TEDDIURSA, 0, mode);
        break;
    }
}

static void PlaySpaMonAttackSE(void)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        PlaySE(SE_M_BITE);
        break;
    case SPA_TEDDIURSA:
        PlaySE(SE_M_SCRATCH);
        break;
    }
}

static void SetItemFlagBits(u8 taskId)
{
    if (FlagGet(FLAG_SPA_OBTAINED_BERRY))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_BERRY;

    if (FlagGet(FLAG_SPA_OBTAINED_CLAW))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_CLAW;

    if (FlagGet(FLAG_SPA_OBTAINED_HONEY))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_HONEY;

    if (FlagGet(FLAG_SPA_OBTAINED_ORB))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_ORB;
}

static const s16 AngryPos[][2] =
{
    [SPA_RATTATA] = { 165, 38},
    [SPA_TEDDIURSA] = { 155, 40},
};

static void Task_SpaGame(u8 taskId)
{
    RunTextPrinters();
    VarSet(VAR_SPA_COUNTER, VarGet(VAR_SPA_COUNTER) + 1);

    if (gTasks[taskId].tShouldExit && !gPaletteFade.active)
    {
        ResetAllPicSprites();
        PlayBGM(GetCurrLocationDefaultMusic()); // Play the map's default music.
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
    }

    if (gTasks[taskId].tPetActive && gTasks[taskId].tPetScore < SPA_PET_SCORE_TARGET)
    {
        if(!JOY_HELD(DPAD_ANY))
        {
            if (gTasks[taskId].tPetTimer == 60)
            {
                StopPetting(&gSprites[VarGet(VAR_HAND_SPRITE_ID)]);
            }
            gTasks[taskId].tPetTimer++;
        }
    }

    if (gTasks[taskId].tPetArea == SPA_PET_BAD)
    {
        if (VarGet(VAR_SPA_COUNTER) == 61)
        {
            u8 spaMon = VarGet(VAR_SPA_MON);

            PlaySpaMonCry(CRY_MODE_ROAR_1);
            if (gTasks[taskId].tNumBadPets == 0)
                CreateSprite(&sSpriteTemplate_Angry, AngryPos[spaMon][0], AngryPos[spaMon][1], 0);
        }
        else if (VarGet(VAR_SPA_COUNTER) == 181 && gTasks[taskId].tNumBadPets == 0)
        {
            StopPetting(&gSprites[VarGet(VAR_HAND_SPRITE_ID)]);
            gTasks[taskId].tNumBadPets++;
        }
        else if (VarGet(VAR_SPA_COUNTER) == 117 && gTasks[taskId].tNumBadPets == 1)
        {
            PlaySpaMonAttackSE();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 8, RGB_RED);
        }
        else if (VarGet(VAR_SPA_COUNTER) > 117 && gTasks[taskId].tNumBadPets == 1)
        {
            if (!gPaletteFade.active)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 1, 8, 0, RGB_RED);
                gTasks[taskId].tPetArea = SPA_PET_NONE;
                VarSet(VAR_SPA_COUNTER, 0);
                gTasks[taskId].tNumBadPets = 2;
            }
        }
    }
    else if (gTasks[taskId].tNumBadPets == 2)
    {
        if (VarGet(VAR_SPA_COUNTER) == 32)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].tNumBadPets = 3;
            gTasks[taskId].tShouldExit = TRUE;
        }
    }
}

static void DoSpaMonBerryText(bool8 isSatisfied)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataInterestedBerry, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaPretend, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaNoInterest, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonStatusText(bool8 isSatisfied)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataAtEase, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataWary, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaGrateful, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaStruggle, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonBadTouchText(bool8 isSatisfied)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_GeneralBadTouch, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NARROW, gText_RattataBadPet, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_GeneralBadTouch, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NARROW, gText_TeddiursaBadPet, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonSatisfiedText(void)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataSatisfied, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaSatisfied, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonEnjoyedSnackText(void)
{
    switch (VarGet(VAR_SPA_MON))
    {
    case SPA_RATTATA:
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataEnjoyedSnack, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaEnjoyedSnack, 0, 0, 0, NULL);
        break;
    }
}

static const u16 SpaItemsY[][3] =
{
    { 48, SPA_ITEM_BIT_BERRY, VAR_BERRY_SPRITE_ID }, // Berry.
    { 69, SPA_ITEM_BIT_CLAW, VAR_CLAW_SPRITE_ID }, // Claw.
    { 90, SPA_ITEM_BIT_HONEY, VAR_HONEY_SPRITE_ID }, // Honey.
    { 112, SPA_ITEM_BIT_ORB, VAR_ORB_SPRITE_ID }, // Orb.
};

static void Task_SpaItemChoose(u8 taskId)
{
    u8 spriteId;

    switch (gTasks[taskId].tItemMenuState)
    {
    case ITEM_STATE_START:
        spriteId = CreateSprite(&sSpriteTemplate_Selector, -32, SpaItemsY[0][0], 0);
        gSprites[spriteId].sTaskId = taskId;

        spriteId = CreateSprite(&sSpriteTemplate_ItemTray, ITEM_START_X, 48, 1);
        gSprites[spriteId].sTaskId = taskId;
        spriteId = CreateSprite(&sSpriteTemplate_ItemTray, ITEM_START_X, 112, 1);
        gSprites[spriteId].sTaskId = taskId;
        gSprites[spriteId].vFlip = TRUE;

        if (FlagGet(FLAG_SPA_OBTAINED_BERRY))
        {
            spriteId = CreateSprite(&sSpriteTemplate_Berry, (ITEM_START_X + 14), SpaItemsY[0][0], 0);
            gSprites[spriteId].sTaskId = taskId;
            gSprites[spriteId].oam.priority = 0;
            VarSet(VAR_BERRY_SPRITE_ID, spriteId);
            StartSpriteAnim(&gSprites[spriteId], gTasks[taskId].tBerryBites);
        }

        if (FlagGet(FLAG_SPA_OBTAINED_CLAW))
        {
            spriteId = CreateSprite(&sSpriteTemplate_Claw, (ITEM_START_X), SpaItemsY[1][0], 0);
            gSprites[spriteId].sTaskId = taskId;
            gSprites[spriteId].oam.priority = 0;
            VarSet(VAR_CLAW_SPRITE_ID, spriteId);
        }

        PlaySE(SE_BALL_TRAY_ENTER);
        gTasks[taskId].tItemMenuState = ITEM_STATE_TRAY_OUT;
        break;
    case ITEM_STATE_TRAY_OUT:
        if (gTasks[taskId].tCounter == 16)
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaItemSelectInstructions, 0, 0, 0, NULL);
            gTasks[taskId].tCounter = 0;
            gTasks[taskId].tItemMenuState = ITEM_STATE_TRAY_INPUT;
        }
        else
        {
            gTasks[taskId].tCounter++;
        }
        break;
    case ITEM_STATE_TRAY_INPUT:
        if (JOY_NEW(FAST_BUTTON) || JOY_NEW(ITEM_MENU_BUTTON))
        {
            gTasks[taskId].tItemMenuState = ITEM_STATE_NO_SELECTION;
        }
        if (JOY_NEW(INTERACT_BUTTON))
        {
            gTasks[taskId].tItemMenuState = ITEM_STATE_ITEM_SELECTED;
            gSprites[VarGet(VAR_HAND_SPRITE_ID)].x = 28;
            gSprites[VarGet(VAR_HAND_SPRITE_ID)].y = 45;
            PlaySE(SE_SELECT);
        }
        break;
    case ITEM_STATE_ITEM_SELECTED:
        if (gTasks[taskId].tCounter == 16)
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaItemInstructions, 0, 0, 0, NULL);
            gTasks[taskId].tCounter = 0;
            gTasks[taskId].tItemMenuState = ITEM_STATE_ITEM_HELD;
        }
        else
        {
            gTasks[taskId].tCounter++;
        }
        break;
    case ITEM_STATE_ITEM_HELD:
        if (gTasks[taskId].tStatusShowing && !JOY_HELD(STATUS_BUTTON))
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaItemInstructions, 0, 0, 0, NULL);
            gTasks[taskId].tStatusShowing = FALSE;
        }

        if (JOY_NEW(STATUS_BUTTON) || (!gTasks[taskId].tStatusShowing && JOY_HELD(STATUS_BUTTON)))
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            DoSpaMonBerryText(gTasks[taskId].tIsSatisfied);

            gTasks[taskId].tStatusShowing = TRUE;
        }
        break;
    case ITEM_STATE_NO_SELECTION:
        if (gTasks[taskId].tCounter == 16)
        {
            gTasks[taskId].tCounter = 0;
            gTasks[taskId].tItemMenuState = ITEM_STATE_END;
        }
        else
        {
            gTasks[taskId].tCounter++;
        }
        break;
    case ITEM_STATE_END:
        if (gTasks[taskId].tBerryBites != 3)
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaInstructions, 0, 0, 0, NULL);
        }
        gTasks[taskId].tSelectedItem = 0;
        gTasks[taskId].tItemActive = FALSE;
        gTasks[taskId].tItemMenuState = ITEM_STATE_START;
        gTasks[taskId].func = Task_SpaGame;
        break;
    }
}

static void MoveSpriteFromInput(struct Sprite *sprite)
{
    if (JOY_HELD(DPAD_DOWN))
    {
        if (JOY_HELD(FAST_BUTTON))
            sprite->y++;

        sprite->y++;
        if (sprite->y > 155)
            sprite->y = 155;
    }
    if (JOY_HELD(DPAD_UP))
    {
        if (JOY_HELD(FAST_BUTTON))
            sprite->y--;

        sprite->y--;
        if (sprite->y < 9)
            sprite->y = 9;
    }
    if (JOY_HELD(DPAD_RIGHT))
    {
        if (JOY_HELD(FAST_BUTTON))
            sprite->x++;

        sprite->x++;
        if (sprite->x > 240)
            sprite->x = 240;
    }
    if (JOY_HELD(DPAD_LEFT))
    {
        if (JOY_HELD(FAST_BUTTON))
            sprite->x--;

        sprite->x--;
        if (sprite->x < 0)
            sprite->x = 0;
    }
}

static const s16 HeartPos[][3][2] =
{
    [SPA_RATTATA] = {
        { 130, 40 },
        { 150, 35 },
        { 170, 45 },
    },
    [SPA_TEDDIURSA] = {
        { 110, 40 },
        { 130, 35 },
        { 150, 45 },
    }
};

static void SpriteCB_Hand(struct Sprite *sprite)
{
    u8 petArea = GetCurrentPettingArea(sprite);

    if (sprite->invisible == TRUE)
    {
        if (!sTask.tShouldExit && sTask.tPetArea != SPA_PET_BAD && !sTask.tItemActive && sTask.tNumBadPets != 2 && sTask.tBerryBites != 3 && sTask.tPetScore < SPA_PET_SCORE_TARGET)
            sprite->invisible = FALSE;

        return;
    }

    if (sTask.tStatusShowing && !JOY_HELD(STATUS_BUTTON))
    {
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaInstructions, 0, 0, 0, NULL);
        sTask.tStatusShowing = FALSE;
    }

    if (JOY_NEW(STATUS_BUTTON) || (!sTask.tStatusShowing && JOY_HELD(STATUS_BUTTON)))
    {
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        DoSpaMonStatusText(sTask.tIsSatisfied);

        sTask.tStatusShowing = TRUE;
    }

    switch (sHandState)
    {
    case HAND_NORMAL:
        if (JOY_NEW(EXIT_BUTTON))
        {
            sprite->invisible = TRUE;
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
            sTask.tShouldExit = TRUE;
            return;
        }
        if (JOY_NEW(ITEM_MENU_BUTTON))
        {
            sTask.tItemActive = TRUE;
            sprite->invisible = TRUE;

            sTask.func = Task_SpaItemChoose;
            return;
        }
        if (JOY_NEW(INTERACT_BUTTON))
        {
            if (petArea == SPA_PET_BAD)
            {
                sTask.tPetArea = SPA_PET_BAD;
                VarSet(VAR_SPA_COUNTER, 0);
                sprite->invisible = TRUE;
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                DoSpaMonBadTouchText(sTask.tIsSatisfied);
                return;
            }
            if (IsHandOnItemsIcon(sprite))
            {
                StartSpriteAnim(&gSprites[VarGet(VAR_ITEMS_ICON_SPRITE_ID)], 1);
                sTask.tItemActive = TRUE;
                sprite->invisible = TRUE;
                sTask.func = Task_SpaItemChoose;
                return;
            }
            else if (IsHandOnExitIcon(sprite))
            {
                StartSpriteAnim(&gSprites[VarGet(VAR_ITEMS_EXIT_SPRITE_ID)], 1);
                sprite->invisible = TRUE;
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
                sTask.tShouldExit = TRUE;
                return;
            }
        }
        else if (JOY_HELD(INTERACT_BUTTON))
        {
            if (petArea)
            {
                if (petArea == SPA_PET_BAD)
                {
                    sTask.tPetArea = SPA_PET_BAD;
                    VarSet(VAR_SPA_COUNTER, 0);
                    sprite->invisible = TRUE;
                    return;
                }
                AdjustToPetArea(sprite, petArea);
                StartSpriteAnim(sprite, 1);
                sHandState = HAND_PET;
            }
            else
            {
                StopPetting(sprite);
            }
        }
        else
        {
            StopPetting(sprite);
        }
        break;
    case HAND_PET:
        if (JOY_NEW(EXIT_BUTTON))
        {
            sprite->invisible = TRUE;
            StopPetting(sprite);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
            sTask.tShouldExit = TRUE;
            return;
        }

        if (sTask.tPetScore >= SPA_PET_SCORE_TARGET)
        {
            u8 spaMon = VarGet(VAR_SPA_MON);
            u8 spriteId;
            u8 i;

            for (i = 0; i < 3; i++)
            {
                spriteId = CreateSprite(&sSpriteTemplate_Heart, HeartPos[spaMon][i][0], HeartPos[spaMon][i][1], 0);
                gSprites[spriteId].sTaskId = sprite->sTaskId;
                gSprites[spriteId].sHeartOffset = Random() % 120;
                gSprites[spriteId].sCounter = gSprites[spriteId].sHeartOffset;
                gSprites[spriteId].sHeartId = i + 1;
            }

            PlaySpaMonCry(CRY_MODE_GROWL_1);
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            DoSpaMonSatisfiedText();
            sprite->invisible = TRUE;
        }
        else if (!JOY_HELD(INTERACT_BUTTON) || !petArea)
        {
            StartSpriteAnim(sprite, 0);
            StopPetting(sprite);
        }
        else if (JOY_HELD(DPAD_ANY))
        {
            sTask.tPetScore += 4;
            sTask.tPetTimer = 0;
            if (!sTask.tPetActive)
            {
                VarSet(VAR_SPA_COUNTER, 0);
                sTask.tPetActive = TRUE;
            }
        }
        break;
    }

    MoveSpriteFromInput(sprite);
}

static void SpriteCB_Music(struct Sprite *sprite)
{
    if (sprite->sCounter == 10)
    {
        PlaySpaMonCry(CRY_MODE_HIGH_PITCH);
    }
    else if (sprite->sCounter == 120)
    {
        sTask.tBerryBites = 0;
        VarSet(VAR_SPA_COUNTER, 0);
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaInstructions, 0, 0, 0, NULL);
        DestroySprite(sprite);
    }
    sprite->sCounter++;
}

const s16 PettingZones[][5][5] =
{
    // { MIN_X, MAX_X, MIN_Y, MAX_Y, BODY_PART }

    [SPA_RATTATA] =
    {
        { 78, 118, 49, 97, SPA_PET_BODY },
        { 127, 175, 32, 72, SPA_PET_HEAD },
        { 72, 112, 8, 31, SPA_PET_BAD },
        { 64, 80, 25, 73, SPA_PET_BAD },
        { 155, 168, 91, 104, SPA_PET_BAD }
    },
    [SPA_TEDDIURSA] =
    {
        { 117, 165, 70, 118, SPA_PET_BODY },
        { 108, 164, 24, 74, SPA_PET_HEAD },
    }
};

static u8 GetCurrentPettingArea(struct Sprite *sprite)
{
    u8 i;
    u8 spaMon = VarGet(VAR_SPA_MON);

    for (i = 0; i < ARRAY_COUNT(PettingZones[spaMon]); i++)
    {
        if (sprite->x > PettingZones[spaMon][i][0] && sprite->x < PettingZones[spaMon][i][1])
        {
            if (sprite->y > PettingZones[spaMon][i][2] && sprite->y < PettingZones[spaMon][i][3])
            {
                if (!sTask.tIsSatisfied)
                    return SPA_PET_BAD;

                return PettingZones[spaMon][i][4];
            }
        }
    }

    return SPA_PET_NONE;
}

static void AdjustToPetArea(struct Sprite *sprite, u8 area)
{
    if (sTask.tPetArea != area && area != SPA_PET_BAD)
    {
        sTask.tPetArea = area;
        if (sTask.tPetArea == SPA_PET_BODY && VarGet(VAR_SPA_MON) == 0)
            sprite->subpriority = 11;
            sprite->oam.priority = 1;
    }
}

static void StopPetting(struct Sprite *sprite)
{
    if (sTask.tPetArea != SPA_PET_NONE)
    {
        sTask.tPetArea = SPA_PET_NONE;
        VarSet(VAR_SPA_COUNTER, 0);
        sprite->subpriority = 5;
        sprite->oam.priority = 0;
        sTask.tPetActive = FALSE;
        sHandState = HAND_NORMAL;
    }
}

static bool8 IsHandOnItemsIcon(struct Sprite *sprite)
{
    if (sprite->x < (gSprites[VarGet(VAR_ITEMS_ICON_SPRITE_ID)].x + 20) && sprite->y > (gSprites[VarGet(VAR_ITEMS_ICON_SPRITE_ID)].y - 7))
        return TRUE;

    return FALSE;
}

static bool8 IsHandOnExitIcon(struct Sprite *sprite)
{
    if (sprite->x < 38 && sprite->y < 38)
        return TRUE;

    return FALSE;
}

static void SpriteCB_ItemTray(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == ITEM_STATE_TRAY_OUT && sprite->x < ITEM_END_X)
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_ITEM_SELECTED)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_NO_SELECTION)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_END || sTask.tItemMenuState == ITEM_STATE_ITEM_HELD)
    {
        DestroySprite(sprite);
    }
}

static void SpriteCB_Selector(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == ITEM_STATE_TRAY_OUT && sprite->x < 0)
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_TRAY_INPUT)
    {
        u32 i;
        s32 newPosition;

        if (JOY_NEW(DPAD_DOWN))
        {
            for (i = 1; i < ARRAY_COUNT(SpaItemsY); i++)
            {
                newPosition = sTask.tSelectedItem + i;
                if (newPosition > 3)
                    newPosition -= 4;

                if (sTask.tItemFlagBits & SpaItemsY[newPosition][1])
                {
                    sprite->y = SpaItemsY[newPosition][0];
                    gSprites[VarGet(SpaItemsY[newPosition][2])].x += 14;
                    gSprites[VarGet(SpaItemsY[sTask.tSelectedItem][2])].x -= 14;
                    sTask.tSelectedItem = newPosition;
                    break;
                }
            }
        }
        else if (JOY_NEW(DPAD_UP))
        {
            for (i = 1; i < ARRAY_COUNT(SpaItemsY); i++)
            {
                newPosition = sTask.tSelectedItem - i;
                if (newPosition < 0)
                    newPosition += 4;

                if (sTask.tItemFlagBits & SpaItemsY[newPosition][1])
                {
                    sprite->y = SpaItemsY[newPosition][0];
                    gSprites[VarGet(SpaItemsY[newPosition][2])].x += 14;
                    gSprites[VarGet(SpaItemsY[sTask.tSelectedItem][2])].x -= 14;
                    sTask.tSelectedItem = newPosition;
                    break;
                }
            }
        }

        if (sprite->sCounter == 32)
        {
            sprite->x2++;
        }
        else if (sprite->sCounter == 64)
        {
            sprite->x2--;
            sprite->sCounter = 0;
        }

        sprite->sCounter++;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_ITEM_SELECTED)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_NO_SELECTION)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_END || sTask.tItemMenuState == ITEM_STATE_ITEM_HELD)
    {
        DestroySprite(sprite);
    }
}

static void SpriteCB_Angry(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaInstructions, 0, 0, 0, NULL);
        DestroySprite(sprite);
    }
}

static void SpriteCB_Heart(struct Sprite *sprite)
{
    if (sprite->sCounter == (180 + sprite->sHeartOffset))
    {
        if (sprite->sHeartId == 1 && !sprite->sFadeStarted)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 16, RGB_BLACK);
            sprite->sFadeStarted = TRUE;
            sTask.tShouldExit = TRUE;
        }
    }
    sprite->sCounter++;
    sprite->x2 = Sin2(0 - sprite->sCounter * 3) / 512;
    if (sprite->sCounter % 4 == 0)
        sprite->y--;
}

static void SpriteCB_Berry(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == ITEM_STATE_TRAY_OUT && sprite->x < (ITEM_END_X + 14))
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_ITEM_SELECTED && sTask.tSelectedItem != 0)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_ITEM_HELD)
    {
        if (sTask.tSelectedItem != 0)
        {
            DestroySprite(sprite);
        }
        if (JOY_NEW(INTERACT_BUTTON))
        {
            sTask.tItemMenuState = ITEM_STATE_END;
            DestroySprite(sprite);
        }
        else if (JOY_NEW(L_BUTTON))
        {
            sTask.tItemMenuState = ITEM_STATE_START;
            DestroySprite(sprite);
        }
        else if (sprite->sBerryBites != sTask.tBerryBites)
        {
            if (sTask.tBerryBites == 3)
            {
                u8 spriteId = CreateSprite(&sSpriteTemplate_Music, 190, 20, 0);
                gSprites[spriteId].sTaskId = sprite->sTaskId;
                VarSet(VAR_SPA_COUNTER, 0);
                sTask.tItemMenuState = ITEM_STATE_END;
                sTask.tIsSatisfied = TRUE;
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                DoSpaMonEnjoyedSnackText();
                DestroySprite(sprite);
            }

            sprite->sBerryBites = sTask.tBerryBites;
            StartSpriteAnim(sprite, sprite->sBerryBites);
        }
        
        MoveSpriteFromInput(sprite);
    }
    else if (sTask.tItemMenuState == ITEM_STATE_NO_SELECTION)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_END)
    {
        DestroySprite(sprite);
    }
}

static void SpriteCB_Claw(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == ITEM_STATE_TRAY_OUT && sprite->x < ITEM_END_X)
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_ITEM_SELECTED && sTask.tSelectedItem != 1)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_ITEM_HELD)
    {
        if (sTask.tSelectedItem != 1)
        {
            DestroySprite(sprite);
        }
        if (JOY_NEW(INTERACT_BUTTON))
        {
            sTask.tItemMenuState = ITEM_STATE_END;
            DestroySprite(sprite);
        }
        else if (JOY_NEW(L_BUTTON))
        {
            sTask.tItemMenuState = ITEM_STATE_START;
            DestroySprite(sprite);
        }
        
        MoveSpriteFromInput(sprite);
    }
    else if (sTask.tItemMenuState == ITEM_STATE_NO_SELECTION)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == ITEM_STATE_END)
    {
        DestroySprite(sprite);
    }
}

static const s16 FeedingZones[][2][2] =
{
    [SPA_RATTATA] =
    {
        { 135, 170 },
        { 83, 110 }
    },
    [SPA_TEDDIURSA] =
    {
        { 60, 80 },
        { 60, 110 }
    }
};

bool32 IsBerryInFeedingZone(void)
{
    u8 spaMon = VarGet(VAR_SPA_MON);
    u8 berrySprite = VarGet(VAR_BERRY_SPRITE_ID);

    if (gSprites[berrySprite].x > FeedingZones[spaMon][0][0] && gSprites[berrySprite].x < FeedingZones[spaMon][0][1] 
     && gSprites[berrySprite].y > FeedingZones[spaMon][1][0]  && gSprites[berrySprite].y < FeedingZones[spaMon][1][1] )
    {
        return TRUE;
    }

    return FALSE;
}

void Script_StartSpa(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ScriptStartSpa, 1);
}

static void Task_ScriptStartSpa(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        PlayBGM(MUS_NONE);
        SetMainCallback2(CB2_InitSpa);
        gMain.savedCallback = CB2_ReturnToField;
        DestroyTask(taskId);
    }
}