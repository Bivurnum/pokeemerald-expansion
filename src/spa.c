#include "global.h"
#include "spa.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

static EWRAM_DATA struct SpaData sSpaData = {0};

static void CB2_StartSpa(void);
static void Task_SpaWaitFade(u8 taskId);
static void Task_Spa(u8 taskId);
static void Task_SpaEndFade(u8 taskId);
static void CreateSpaSprites(u8 taskId);
static void CreateSpaMonSprites(u8 taskId);

static void SpriteCB_Hand(struct Sprite *sprite);
static void SpriteCB_Music(struct Sprite *sprite);
static void SpriteCB_ItemTray(struct Sprite *sprite);
static void SpriteCB_Selector(struct Sprite *sprite);
static void SpriteCB_Angry(struct Sprite *sprite);
static void SpriteCB_Heart(struct Sprite *sprite);
static void SpriteCB_Berry(struct Sprite *sprite);
static void SpriteCB_Claw(struct Sprite *sprite);
static void SpriteCB_Honey(struct Sprite *sprite);

static const u32 gSpaBG_Gfx[] = INCBIN_U32("graphics/_spa/spa_bg.4bpp.smol");
static const u32 gSpaBG_Tilemap[] = INCBIN_U32("graphics/_spa/spa_bg.bin.smolTM");
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

static const u16 gHoney_Pal[] = INCBIN_U16("graphics/_spa/honey.gbapal");
static const u32 gHoney_Gfx[] = INCBIN_U32("graphics/_spa/honey.4bpp");

const u8 gText_SpaInstructions[] = _("Spa Instruction");

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

static const union AnimCmd sAnim_MusicFlipped[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Music[] =
{
    sAnim_Normal,
    sAnim_MusicFlipped,
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

static const union AnimCmd sAnim_Honey1Bug[] =
{
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Honey2Bugs[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Honey3Bugs[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Honey4Bugs[] =
{
    ANIMCMD_FRAME(.imageValue = 4, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Honey[] =
{
    sAnim_Normal,
    sAnim_Honey1Bug,
    sAnim_Honey2Bugs,
    sAnim_Honey3Bugs,
    sAnim_Honey4Bugs,
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
    spa_frame(gMusic_Gfx, 1, 4, 4),
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

static const struct SpriteFrameImage sPicTable_Honey[] =
{
    spa_frame(gHoney_Gfx, 0, 4, 4),
    spa_frame(gHoney_Gfx, 1, 4, 4),
    spa_frame(gHoney_Gfx, 2, 4, 4),
    spa_frame(gHoney_Gfx, 3, 4, 4),
    spa_frame(gHoney_Gfx, 4, 4, 4),
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

static const struct SpriteTemplate sSpriteTemplate_Honey =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_HONEY,
    .oam = &sOam_32x32,
    .anims = sAnims_Honey,
    .images = sPicTable_Honey,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Honey
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
    {
        .data = gHoney_Pal,
        .tag = TAG_HONEY
    },
    {NULL},
};

static void SetItemFlagBits(u8 taskId)
{
    if (FlagGet(FLAG_SPA_OBTAINED_BERRY))
        sSpaData.itemFlagBits |= SPA_ITEM_BIT_BERRY;

    if (FlagGet(FLAG_SPA_OBTAINED_CLAW))
        sSpaData.itemFlagBits |= SPA_ITEM_BIT_CLAW;

    if (FlagGet(FLAG_SPA_OBTAINED_HONEY))
        sSpaData.itemFlagBits |= SPA_ITEM_BIT_HONEY;

    if (FlagGet(FLAG_SPA_OBTAINED_ORB))
        sSpaData.itemFlagBits |= SPA_ITEM_BIT_ORB;
}

static void LoadMonSpritePalettes(void)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        LoadSpritePalettes(sSpritePalettes_SpaRattata);
        break;
    case SPA_TEDDIURSA:
        //LoadSpritePalettes(sSpritePalettes_SpaTeddiursa);
        break;
    case SPA_PSYDUCK:
        //LoadSpritePalettes(sSpritePalettes_SpaPsyduck);
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

void StartSpa(struct ScriptContext *ctx)
{
    u8 mon = ScriptReadByte(ctx);

    memset(&sSpaData, 0, sizeof(sSpaData));
    sSpaData.mon = mon;
    PlayRainStoppingSoundEffect();
    CleanupOverworldWindowsAndTilemaps();
    SetMainCallback2(CB2_StartSpa);
}

static void CB2_StartSpa(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        gMain.state = 1;
        break;
    case 1:
        ScanlineEffect_Stop();
        DeactivateAllTextPrinters();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        ResetAllPicSprites();
        gMain.state++;
        break;
    case 2:
        u8 taskId;

        DecompressDataWithHeaderVram(gSpaBG_Gfx, (void*) BG_CHAR_ADDR(1));
        DecompressDataWithHeaderVram(gSpaBG_Tilemap, (u16*) BG_SCREEN_ADDR(6));

        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWindowTemplates);

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

        taskId = CreateTask(Task_SpaWaitFade, 1);

        SetItemFlagBits(taskId);
        CreateSpaSprites(taskId);
        gMain.state++;
        break;
    }
}

static void CreateSpaSprites(u8 taskId)
{
    u8 spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_Hand, 28, 45, 5);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].oam.priority = 0;
    sSpaData.handSpriteId = spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_ItemsIcon, 16, 144, 7);
    gSprites[spriteId].sTaskId = taskId;
    sSpaData.itemsIconSpriteId = spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_ExitIcon, 16, 16, 7);
    gSprites[spriteId].sTaskId = taskId;
    sSpaData.itemsExitSpriteId = spriteId;

    CreateSpaMonSprites(taskId);
}

static void CreateSpaMonSprites(u8 taskId)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        CreateRattataSprites(taskId);
        break;
    case SPA_TEDDIURSA:
        //CreateTeddiursaSprites(taskId);
        break;
    case SPA_PSYDUCK:
        //CreatePsyduckSprites(taskId);
        break;
    }
}

static void PlaySpaMonCry(u8 mode)
{
    switch (VarGet(sSpaData.mon))
    {
    case SPA_RATTATA:
        PlayCry_ByMode(SPECIES_RATTATA, 0, mode);
        break;
    case SPA_TEDDIURSA:
        PlayCry_ByMode(SPECIES_TEDDIURSA, 0, mode);
        break;
    case SPA_PSYDUCK:
        PlayCry_ByMode(SPECIES_PSYDUCK, 0, mode);
        break;
    }
}

static void CheckSpaStateChange(u8 taskId)
{

}

static bool32 IsHandOnItemsIcon(void)
{
    if (gSprites[sSpaData.handSpriteId].x < (gSprites[sSpaData.itemsIconSpriteId].x + 20) && gSprites[sSpaData.handSpriteId].y > (gSprites[sSpaData.itemsIconSpriteId].y - 7))
        return TRUE;

    return FALSE;
}

static const u16 SpaItemsY[][2] =
{
    { 48, SPA_ITEM_BIT_BERRY }, // Berry.
    { 69, SPA_ITEM_BIT_CLAW }, // Claw.
    { 90, SPA_ITEM_BIT_HONEY }, // Honey.
    { 112, SPA_ITEM_BIT_ORB }, // Orb.
};

static void SpaHandHandleInput(u8 taskId)
{
    if (JOY_NEW(EXIT_BUTTON))
    {
        gSprites[sSpaData.handSpriteId].invisible = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
        gTasks[taskId].func = Task_SpaEndFade;
    }
    if ((JOY_NEW(ITEM_MENU_BUTTON) || (JOY_NEW(INTERACT_BUTTON) && IsHandOnItemsIcon())) && FlagGet(FLAG_SPA_OBTAINED_BERRY))
    {
        gSprites[sSpaData.handSpriteId].invisible = TRUE;
        sSpaData.itemSelectorSpriteId = CreateSprite(&sSpriteTemplate_Selector, -32, SpaItemsY[0][0], 0);
        gSprites[sSpaData.itemSelectorSpriteId].sTaskId = taskId;

        sSpaData.itemTraySpriteId1 = CreateSprite(&sSpriteTemplate_ItemTray, ITEM_START_X, 48, 1);
        gSprites[sSpaData.itemTraySpriteId1].sTaskId = taskId;
        sSpaData.itemTraySpriteId2 = CreateSprite(&sSpriteTemplate_ItemTray, ITEM_START_X, 112, 1);
        gSprites[sSpaData.itemTraySpriteId2].sTaskId = taskId;
        gSprites[sSpaData.itemTraySpriteId2].vFlip = TRUE;

        sSpaData.berrySpriteId = CreateSprite(&sSpriteTemplate_Berry, (ITEM_START_X + 14), SpaItemsY[0][0], 0);
        gSprites[sSpaData.berrySpriteId].sTaskId = taskId;
        gSprites[sSpaData.berrySpriteId].oam.priority = 0;
        //StartSpriteAnim(&gSprites[sSpaData.berrySpriteId], gTasks[taskId].tBerryBites);

        if (FlagGet(FLAG_SPA_OBTAINED_CLAW))
        {
            sSpaData.clawSpriteId = CreateSprite(&sSpriteTemplate_Claw, (ITEM_START_X), SpaItemsY[1][0], 0);
            gSprites[sSpaData.clawSpriteId].sTaskId = taskId;
            gSprites[sSpaData.clawSpriteId].oam.priority = 0;
        }

        if (FlagGet(FLAG_SPA_OBTAINED_HONEY))
        {
            //u8 numBugs = 0;
            //u8 i;

            sSpaData.honeySpriteId = CreateSprite(&sSpriteTemplate_Honey, (ITEM_START_X), SpaItemsY[2][0], 0);
            gSprites[sSpaData.honeySpriteId].sTaskId = taskId;
            gSprites[sSpaData.honeySpriteId].oam.priority = 0;
            /*for (i = 0; i < MAX_BUGS; i++)
            {
                if (FlagGet(FLAG_SPA_PSYDUCK_BUG_0 + i) && !FlagGet(FLAG_SPA_BUG_0_EATEN + i))
                    numBugs++;
            }
            StartSpriteAnim(&gSprites[spriteId], numBugs);*/
        }

        PlaySE(SE_BALL_TRAY_ENTER);
        tState = STATE_TRAY_OUT;
        return;
    }
}

static void Task_SpaWaitFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        PlaySpaMonCry(CRY_MODE_NORMAL);
        gTasks[taskId].func = Task_Spa;
    }
}

static void Task_Spa(u8 taskId)
{
    switch (tState)
    {
    case STATE_HAND:
        SpaHandHandleInput(taskId);
        break;
    case STATE_TRAY_OUT:
        if (gSprites[sSpaData.berrySpriteId].x < (ITEM_END_X + 14))
        {
            if (gSprites[sSpaData.itemTraySpriteId1].x < 0)
            {
                gSprites[sSpaData.itemTraySpriteId1].x += 2;
                gSprites[sSpaData.itemTraySpriteId2].x += 2;
            }
            gSprites[sSpaData.berrySpriteId].x += 2;
            if (sSpaData.clawSpriteId)
                gSprites[sSpaData.clawSpriteId].x += 2;
            if (sSpaData.honeySpriteId)
                gSprites[sSpaData.honeySpriteId].x += 2;
        }
        else
        {
            tState = STATE_ITEM_CHOOSE;
        }
    }

    CheckSpaStateChange(taskId);
}

static void Task_SpaEndFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
        DestroyTask(taskId);
    }
}

static void SpriteCB_Hand(struct Sprite *sprite)
{

}

static void SpriteCB_Music(struct Sprite *sprite)
{

}

static void SpriteCB_ItemTray(struct Sprite *sprite)
{

}

static void SpriteCB_Selector(struct Sprite *sprite)
{

}

static void SpriteCB_Angry(struct Sprite *sprite)
{

}

static void SpriteCB_Heart(struct Sprite *sprite)
{

}

static void SpriteCB_Berry(struct Sprite *sprite)
{

}

static void SpriteCB_Claw(struct Sprite *sprite)
{

}

static void SpriteCB_Honey(struct Sprite *sprite)
{

}
