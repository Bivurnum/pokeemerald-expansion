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

EWRAM_DATA struct SpaData sSpaData = {0};

static void CB2_StartSpa(void);
static void Task_SpaWaitFade(u8 taskId);
static void Task_Spa(u8 taskId);
static void Task_SpaEndFade(u8 taskId);
static void Task_SpaEndSuccess(u8 taskId);
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

const u8 gText_SpaInstructions[] = _("{A_BUTTON} : Interact     hold{B_BUTTON} : Fast     hold{R_BUTTON} : Status");
const u8 gText_SpaItemSelectInstructions[] = _("{DPAD_UPDOWN} : Move            {A_BUTTON} : Select            {B_BUTTON} : Exit");
const u8 gText_SpaItemInstructions[] = _("{A_BUTTON} : Put Away     hold{B_BUTTON} : Fast     hold{R_BUTTON} : Status");
const u8 gText_GeneralBadTouch[] = _("It doesn't like to be touched there!");
const u8 gText_FeelsBetter[] = _("That feels much better!");

const u8 gText_RattataWary[] = _("Rattata is watching warily.");
const u8 gText_RattataAtEase[] = _("Rattata seems to be more at ease.");
const u8 gText_RattataBadPet[] = _("It doesn't trust you enough to pet it.");
const u8 gText_RattataInterestedBerry[] = _("It seems interested in the berry.");
const u8 gText_RattataEnjoyedSnack[] = _("Rattata enjoyed the snack!");
const u8 gText_RattataSatisfied[] = _("Rattata is completely satisfied!");

const u8 gText_TeddiursaItchy[] = _("Teddiursa looks itchy!");
const u8 gText_TeddiursaGrateful[] = _("Teddiursa appears grateful.");
const u8 gText_TeddiursaNoInterest[] = _("Teddiursa shows no interest.");
const u8 gText_TeddiursaPretend[] = _("It is pretending not to show interest.");
const u8 gText_TeddiursaBadPet[] = _("It doesn't want to be touched right now.");
const u8 gText_TeddiursaSatisfied[] = _("Teddiursa is completely satisfied!");
const u8 gText_TeddiursaEnjoyedSnack[] = _("Teddiursa enjoyed the snack!");
const u8 gText_TeddiursaWondersClaw[] = _("Teddiursa wonders what you'll do.");
const u8 gText_TeddiursaLikesScratches[] = _("Teddiursa likes the back scratches.");

const u8 gText_PsyduckNoInterest[] = _("Psyduck shows no interest.");
const u8 gText_PsyduckInfested[] = _("Psyduck is infested!");
const u8 gText_PsyduckUneasy[] = _("Psyduck is still a bit uneasy.");
const u8 gText_HoneyLooksSticky[] = _("The honey looks very sticky.");
const u8 gText_OuchBugsBite[] = _("Ouch! Those bugs bite!");
const u8 gText_BugsAttacking[] = _("The bugs are attacking!");

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
        LoadSpritePalettes(sSpritePalettes_SpaTeddiursa);
        break;
    case SPA_PSYDUCK:
        LoadSpritePalettes(sSpritePalettes_SpaPsyduck);
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

    spriteId = CreateSprite(&sSpriteTemplate_Hand, HAND_START_X, HAND_START_Y, 5);
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
        CreateTeddiursaSprites(taskId);
        break;
    case SPA_PSYDUCK:
        CreatePsyduckSprites(taskId);
        break;
    }
}

static void DoSpaMonInstructions(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaInstructions, 0, 0, 0, NULL);
}

static void DoSpaMonBerryText(bool8 isSatisfied)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
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
    case SPA_PSYDUCK:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_PsyduckNoInterest, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonClawText(bool8 isSatisfied)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
    {
    case SPA_TEDDIURSA:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaLikesScratches, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaWondersClaw, 0, 0, 0, NULL);
        break;
    case SPA_PSYDUCK:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_PsyduckNoInterest, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonHoneyText(bool8 isSatisfied)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
    {
    case SPA_PSYDUCK:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_PsyduckNoInterest, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_HoneyLooksSticky, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonItemText(u8 taskId, bool8 isSatisfied)
{
    switch (tSelectedItem)
    {
    case SPA_BERRY:
        DoSpaMonBerryText(isSatisfied);
        break;
    case SPA_CLAW:
        DoSpaMonClawText(isSatisfied);
        break;
    case SPA_HONEY:
        DoSpaMonHoneyText(isSatisfied);
        break;
    case SPA_ORB:
        break;
    }
}

static void DoSpaMonStatusText(bool8 isSatisfied)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
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
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaItchy, 0, 0, 0, NULL);
        break;
    case SPA_PSYDUCK:
        if (isSatisfied)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_PsyduckUneasy, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_PsyduckInfested, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonBadTouchText(bool8 isSatisfied)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
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
    case SPA_PSYDUCK:
        if (!sSpaData.hasBeenPetBad)
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_OuchBugsBite, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_BugsAttacking, 0, 0, 0, NULL);
        break;
    }
}

static void DoSpaMonSatisfiedText(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataSatisfied, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
        AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaSatisfied, 0, 0, 0, NULL);
        break;
    }
}

void DoSpaMonEnjoyedSnackText(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataEnjoyedSnack, 0, 0, 0, NULL);
        break;
    case SPA_TEDDIURSA:
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_TeddiursaEnjoyedSnack, 0, 0, 0, NULL);
        break;
    }
}

void DoSpaMonFeelsBetterText(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_FeelsBetter, 0, 0, 0, NULL);
}

static void PlaySpaMonCry(u8 mode)
{
    switch (sSpaData.mon)
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

static void PlaySpaMonAttackSE(void)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        PlaySE(SE_M_BITE);
        break;
    case SPA_TEDDIURSA:
        PlaySE(SE_M_SCRATCH);
        break;
    case SPA_PSYDUCK:
        PlaySE(SE_M_CUT);
        break;
    }
}

static void CheckSpaStateChange(u8 taskId)
{

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

void PauseUntilAnimEnds(u8 taskId, u8 spriteId)
{
    if (tActiveItemId)
    {
        tSelectedItem = 0;
        DestroySprite(&gSprites[tActiveItemId]);
        tActiveItemId = 0;
    }
    gSprites[sSpaData.handSpriteId].invisible = TRUE;
    sSpaData.pausedSpriteId = spriteId;
    tState = STATE_HAND;
}

static const s16 MusicPos[][3] =
{
    [SPA_RATTATA] = { 190, 20, 0 },
    [SPA_TEDDIURSA] = { 84, 26, 1 },
    [SPA_PSYDUCK] = { 64, 37, 1 },
};

void CreateMusicSprite(u8 taskId)
{
    sSpaData.musicSpriteId = CreateSprite(&sSpriteTemplate_Music, MusicPos[sSpaData.mon][0], MusicPos[sSpaData.mon][1], 0);
    gSprites[sSpaData.musicSpriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[sSpaData.musicSpriteId], MusicPos[sSpaData.mon][2]);
}

static const s16 AngryPos[][2] =
{
    [SPA_RATTATA] = { 165, 38 },
    [SPA_TEDDIURSA] = { 155, 40 },
};

void CreateAngrySprite(u8 taskId)
{
    sSpaData.angrySpriteId = CreateSprite(&sSpriteTemplate_Angry, AngryPos[sSpaData.mon][0], AngryPos[sSpaData.mon][1], 0);
    gSprites[sSpaData.angrySpriteId].sTaskId = taskId;
}

static const u16 SpaItemsY[][2] =
{
    { 48, SPA_ITEM_BIT_BERRY }, // Berry.
    { 69, SPA_ITEM_BIT_CLAW }, // Claw.
    { 90, SPA_ITEM_BIT_HONEY }, // Honey.
    { 112, SPA_ITEM_BIT_ORB }, // Orb.
};

static bool32 IsHandOnItemsIcon(void)
{
    if (gSprites[sSpaData.handSpriteId].x < (gSprites[sSpaData.itemsIconSpriteId].x + 20) && gSprites[sSpaData.handSpriteId].y > (gSprites[sSpaData.itemsIconSpriteId].y - 7))
        return TRUE;

    return FALSE;
}

static bool32 IsHandOnExitIcon(void)
{
    if (gSprites[sSpaData.handSpriteId].x < 38 && gSprites[sSpaData.handSpriteId].y < 38)
        return TRUE;

    return FALSE;
}

static void ItemTraySlideOut(u8 taskId)
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
    StartSpriteAnim(&gSprites[sSpaData.berrySpriteId], tBerryBites);

    if (FlagGet(FLAG_SPA_OBTAINED_CLAW))
    {
        sSpaData.clawSpriteId = CreateSprite(&sSpriteTemplate_Claw, (ITEM_START_X), SpaItemsY[1][0], 0);
        gSprites[sSpaData.clawSpriteId].sTaskId = taskId;
        gSprites[sSpaData.clawSpriteId].oam.priority = 0;
    }

    if (FlagGet(FLAG_SPA_OBTAINED_HONEY))
    {
        u8 numBugs = 0;
        u8 i;

        sSpaData.honeySpriteId = CreateSprite(&sSpriteTemplate_Honey, (ITEM_START_X), SpaItemsY[2][0], 0);
        gSprites[sSpaData.honeySpriteId].sTaskId = taskId;
        gSprites[sSpaData.honeySpriteId].oam.priority = 0;
        for (i = 0; i < MAX_BUGS; i++)
        {
            if (FlagGet(FLAG_SPA_PSYDUCK_BUG_0 + i) && !FlagGet(FLAG_SPA_BUG_0_EATEN + i))
                numBugs++;
        }
        StartSpriteAnim(&gSprites[sSpaData.honeySpriteId], numBugs);
    }

    PlaySE(SE_BALL_TRAY_ENTER);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaItemSelectInstructions, 0, 0, 0, NULL);
    tState = STATE_TRAY_OUT;
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
    },
    [SPA_PSYDUCK] =
    {
        { 126, 195, 47, 94, SPA_PET_BODY },
        { 69, 124, 60, 94, SPA_PET_HEAD },
    }
};

static u8 GetCurrentPettingArea(void)
{
    u32 i;
    u32 spaMon = sSpaData.mon;
    struct Sprite *sprite = &gSprites[sSpaData.handSpriteId];

    for (i = 0; i < ARRAY_COUNT(PettingZones[spaMon]); i++)
    {
        if (sprite->x > PettingZones[spaMon][i][0] && sprite->x < PettingZones[spaMon][i][1])
        {
            if (sprite->y > PettingZones[spaMon][i][2] && sprite->y < PettingZones[spaMon][i][3])
            {
                if (!sSpaData.isSatisfied)
                    return SPA_PET_BAD;

                return PettingZones[spaMon][i][4];
            }
        }
    }

    return SPA_PET_NONE;
}

static void StartBadTouchAnim(u8 taskId)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        StartRattataBadTouch(taskId);
        PlaySE(SE_CONTEST_CONDITION_LOSE);
        break;
    case SPA_TEDDIURSA:
        StartTeddiursaBadTouch(taskId);
        PlaySE(SE_CONTEST_CONDITION_LOSE);
        break;
    case SPA_PSYDUCK:
        StartPsyduckBugsBadTouch(taskId);
        PlaySE(SE_M_BITE);
        break;
    case SPA_FLETCHINDER:
        break;
    }
}

static void StartAngryAnim(u8 taskId)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        StartRattataAngry(taskId);
        PlaySpaMonCry(CRY_MODE_ROAR_1);
        break;
    case SPA_TEDDIURSA:
        StartTeddiursaAngry(taskId);
        PlaySpaMonCry(CRY_MODE_ROAR_1);
        break;
    case SPA_PSYDUCK:
        break;
    case SPA_FLETCHINDER:
        break;
    }
}

static void StartPetAnim(u8 taskId, u8 petArea)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        StartRattataPet();
        break;
    case SPA_TEDDIURSA:
        StartTeddiursaPet();
        break;
    case SPA_PSYDUCK:
        if (petArea == SPA_PET_HEAD)
            StartPsyduckPetHead();
        else
            StartPsyduckPetBody();
        break;
    case SPA_FLETCHINDER:
        break;
    }
}

static void StopSpaPetAnim(u8 taskId)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        StopRattataPet();
        break;
    case SPA_TEDDIURSA:
        ResetTeddiursaSpritesNormal();
        break;
    case SPA_PSYDUCK:
        ResetPsyduckSprites();
        break;
    case SPA_FLETCHINDER:
        break;
    }
}

static void StartHappyAnim(u8 taskId)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        StartRattataPet();
        break;
    case SPA_TEDDIURSA:
        StartTeddiursaHappyAnim();
        break;
    case SPA_PSYDUCK:
        StartPsyduckHappyAnim();
        break;
    case SPA_FLETCHINDER:
        break;
    }
}

static const u8 *SpaItemToPointer[4] =
{
    &sSpaData.berrySpriteId, // Berry.
    &sSpaData.clawSpriteId,  // Claw.
    &sSpaData.honeySpriteId, // Honey.
    &sSpaData.orbSpriteId,   // Orb.
};

static void ResetSpaMonSprites(void)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        ResetRattataSprites();
        break;
    case SPA_TEDDIURSA:
        if (sSpaData.isSatisfied)
            ResetTeddiursaSpritesNormal();
        else
            ResetTeddiursaSpritesScratch();
        break;
    case SPA_PSYDUCK:
        ResetPsyduckSprites();
        break;
    case SPA_FLETCHINDER:
        break;
    }
}

static void AdjustToPetArea(u8 taskId, u8 area)
{
    if (tPetArea != area && area != SPA_PET_BAD)
    {
        tPetArea = area;
        if (tPetArea == SPA_PET_BODY && sSpaData.mon == SPA_RATTATA)
        {
            gSprites[sSpaData.handSpriteId].subpriority = 11;
            gSprites[sSpaData.handSpriteId].oam.priority = 1;
        }
    }
}

static void StopPetting(u8 taskId)
{
    if (tPetArea != SPA_PET_NONE)
    {
        tPetArea = SPA_PET_NONE;
        gSprites[sSpaData.handSpriteId].subpriority = 5;
        gSprites[sSpaData.handSpriteId].oam.priority = 0;
        StopSpaPetAnim(taskId);
    }
}

void ResetSpaHand(void)
{
    gSprites[sSpaData.handSpriteId].x = HAND_START_X;
    gSprites[sSpaData.handSpriteId].y = HAND_START_Y;
    gSprites[sSpaData.handSpriteId].invisible = FALSE;
    gSprites[sSpaData.handSpriteId].subpriority = 5;
    gSprites[sSpaData.handSpriteId].oam.priority = 0;
    DoSpaMonInstructions();
    StartSpriteAnim(&gSprites[sSpaData.handSpriteId], 0);
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
    },
    [SPA_PSYDUCK] = {
        { 70, 50 },
        { 90, 45 },
        { 110, 55 },
    }
};

static void SpaHandHandleInput(u8 taskId)
{
    if (JOY_NEW(EXIT_BUTTON))
    {
        gSprites[sSpaData.handSpriteId].invisible = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
        gTasks[taskId].func = Task_SpaEndFade;
        return;
    }
    else if (JOY_NEW(INTERACT_BUTTON) && IsHandOnExitIcon())
    {
        StartSpriteAnim(&gSprites[sSpaData.itemsExitSpriteId], 1);
        gSprites[sSpaData.handSpriteId].invisible = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
        gTasks[taskId].func = Task_SpaEndFade;
        return;
    }

    if (JOY_NEW(ITEM_MENU_BUTTON) && FlagGet(FLAG_SPA_OBTAINED_BERRY))
    {
        ItemTraySlideOut(taskId);
        return;
    }
    else if ((JOY_NEW(INTERACT_BUTTON) && IsHandOnItemsIcon()) && FlagGet(FLAG_SPA_OBTAINED_BERRY))
    {
        StartSpriteAnim(&gSprites[sSpaData.itemsIconSpriteId], 1);
        ItemTraySlideOut(taskId);
        return;
    }

    if (!JOY_HELD(STATUS_BUTTON) && sSpaData.statusIsShowing)
    {
        DoSpaMonInstructions();
        sSpaData.statusIsShowing = FALSE;
    }
    else if (JOY_NEW(STATUS_BUTTON) && !sSpaData.statusIsShowing)
    {
        DoSpaMonStatusText(sSpaData.isSatisfied);
        sSpaData.statusIsShowing = TRUE;
    }

    u32 petArea = GetCurrentPettingArea();

    if (tPetScore > 0 && tPetScore < SPA_PET_SCORE_TARGET)
        tPetScore--;

    if (JOY_NEW(INTERACT_BUTTON))
    {
        if (petArea == SPA_PET_BAD)
        {
            tPetArea = SPA_PET_BAD;
            StartBadTouchAnim(taskId);
            DoSpaMonBadTouchText(sSpaData.isSatisfied);
            return;
        }
    }
    else if (JOY_HELD(INTERACT_BUTTON))
    {
        if (petArea)
        {
            if (tPetArea != petArea)
            {
                tCounter = 0;
                if (petArea == SPA_PET_BAD)
                {
                    tPetArea = SPA_PET_BAD;
                    StartBadTouchAnim(taskId);
                    gSprites[sSpaData.handSpriteId].invisible = TRUE;
                    DoSpaMonBadTouchText(sSpaData.isSatisfied);
                    return;
                }
                else if (JOY_HELD(DPAD_ANY))
                {
                    AdjustToPetArea(taskId, petArea);
                    StartPetAnim(taskId, petArea);
                }
                StartSpriteAnim(&gSprites[sSpaData.handSpriteId], 1);
            }
            else
            {
                if (tPetScore >= SPA_PET_SCORE_TARGET)
                {
                    u8 spaMon = sSpaData.mon;
                    u8 spriteId;
                    u8 i;
                
                    for (i = 0; i < 3; i++)
                    {
                        spriteId = CreateSprite(&sSpriteTemplate_Heart, HeartPos[spaMon][i][0], HeartPos[spaMon][i][1], 0);
                        sSpaData.heartSpriteIds[i] = taskId;
                        gSprites[spriteId].sHeartOffset = Random() % 120;
                        gSprites[spriteId].sCounter = gSprites[spriteId].sHeartOffset;
                    }
                
                    StartHappyAnim(taskId);
                    PlaySpaMonCry(CRY_MODE_GROWL_1);
                    DoSpaMonSatisfiedText();
                    gSprites[sSpaData.handSpriteId].invisible = TRUE;
                    tCounter = 0;
                    gTasks[taskId].func = Task_SpaEndSuccess;
                    return;
                }
                else if (!petArea)
                {
                    StartSpriteAnim(&gSprites[sSpaData.handSpriteId], 0);
                    StopPetting(taskId);
                }
                else if (JOY_HELD(DPAD_ANY))
                {
                    tPetScore += 4;
                    tCounter = 0;
                }

                if (tPetScore < SPA_PET_SCORE_TARGET)
                {
                    if(!JOY_HELD(DPAD_ANY))
                    {
                        if (tCounter == 60)
                        {
                            StopPetting(taskId);
                        }
                        tCounter++;
                    }
                }
            }
        }
        else
        {
            StopPetting(taskId);
            StartSpriteAnim(&gSprites[sSpaData.handSpriteId], 0);
        }
    }
    else
    {
        StopPetting(taskId);
        StartSpriteAnim(&gSprites[sSpaData.handSpriteId], 0);
    }

    MoveSpriteFromInput(&gSprites[sSpaData.handSpriteId]);
}

static void SpaItemChooseHandleInput(u8 taskId)
{
    u32 i;
    s32 newPosition;

    if (JOY_NEW(B_BUTTON | EXIT_BUTTON))
    {
        tState = STATE_TRAY_IN_HAND;
    }
    else if (JOY_NEW(INTERACT_BUTTON))
    {
        if (sSpaData.mon == SPA_TEDDIURSA && tSelectedItem == SPA_CLAW && !sSpaData.isSatisfied)
        {
            TeddiursaReactToClaw();
        }
        tState = STATE_TRAY_IN_ITEM;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        for (i = 1; i < ARRAY_COUNT(SpaItemsY); i++)
        {
            newPosition = tSelectedItem + i;
            if (newPosition > 3)
                newPosition -= 4;

            if (sSpaData.itemFlagBits & SpaItemsY[newPosition][1])
            {
                gSprites[sSpaData.itemSelectorSpriteId].y = SpaItemsY[newPosition][0];
                gSprites[*SpaItemToPointer[newPosition]].x += 14;
                gSprites[*SpaItemToPointer[tSelectedItem]].x -= 14;
                tSelectedItem = newPosition;
                break;
            }
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        for (i = 1; i < ARRAY_COUNT(SpaItemsY); i++)
        {
            newPosition = tSelectedItem - i;
            if (newPosition < 0)
                newPosition += 4;

            if (sSpaData.itemFlagBits & SpaItemsY[newPosition][1])
            {
                gSprites[sSpaData.itemSelectorSpriteId].y = SpaItemsY[newPosition][0];
                gSprites[*SpaItemToPointer[newPosition]].x += 14;
                gSprites[*SpaItemToPointer[tSelectedItem]].x -= 14;
                tSelectedItem = newPosition;
                break;
            }
        }
    }
}

static void SpaItemHandleInput(u8 taskId)
{
    if (JOY_NEW(INTERACT_BUTTON))
    {
        if (sSpaData.mon == SPA_TEDDIURSA && !sSpaData.isSatisfied && tSelectedItem == SPA_CLAW)
            ResetTeddiursaSpritesScratch();

        tSelectedItem = 0;
        DestroySprite(&gSprites[tActiveItemId]);
        tActiveItemId = 0;
        ResetSpaHand();
        tState = STATE_HAND;
        return;
    }
    else if (JOY_NEW(ITEM_MENU_BUTTON))
    {
        if (sSpaData.mon == SPA_TEDDIURSA && !sSpaData.isSatisfied && tSelectedItem == SPA_CLAW)
            ResetTeddiursaSpritesScratch();
            
        tSelectedItem = 0;
        DestroySprite(&gSprites[tActiveItemId]);
        tActiveItemId = 0;
        ItemTraySlideOut(taskId);
        return;
    }

    if (!JOY_HELD(STATUS_BUTTON) && sSpaData.statusIsShowing)
    {
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaItemInstructions, 0, 0, 0, NULL);
        sSpaData.statusIsShowing = FALSE;
    }
    else if (JOY_NEW(STATUS_BUTTON) && !sSpaData.statusIsShowing)
    {
        DoSpaMonItemText(taskId, sSpaData.isSatisfied);
        sSpaData.statusIsShowing = TRUE;
    }

    MoveSpriteFromInput(&gSprites[tActiveItemId]);

    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        HandleItemsRattata(taskId);
        break;
    case SPA_TEDDIURSA:
        HandleItemsTeddiursa(taskId);
        break;
    case SPA_PSYDUCK:
        HandleItemsPsyduck(taskId);
        break;
    case SPA_FLETCHINDER:
        break;
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
    if (gSprites[sSpaData.berrySpriteId].x > FeedingZones[sSpaData.mon][0][0] && gSprites[sSpaData.berrySpriteId].x < FeedingZones[sSpaData.mon][0][1] 
     && gSprites[sSpaData.berrySpriteId].y > FeedingZones[sSpaData.mon][1][0] && gSprites[sSpaData.berrySpriteId].y < FeedingZones[sSpaData.mon][1][1])
    {
        return TRUE;
    }

    return FALSE;
}

static void EndSpaBad(u8 taskId)
{
    switch (sSpaData.mon)
    {
    case SPA_RATTATA:
        EndSpaBadRattata();
        PlaySpaMonCry(CRY_MODE_ROAR_1);
        break;
    case SPA_TEDDIURSA:
        EndSpaBadTeddiursa();
        PlaySpaMonCry(CRY_MODE_ROAR_1);
        break;
    case SPA_PSYDUCK:
        break;
    case SPA_FLETCHINDER:
        break;
    }
    gTasks[taskId].func = Task_SpaEndBad;
    tState = 0;
    tCounter = 0;
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
        if (sSpaData.pausedSpriteId)
        {
            if (gSprites[sSpaData.pausedSpriteId].animEnded)
            {
                if (tPetArea == SPA_PET_BAD)
                {
                    if (sSpaData.hasBeenPetBad)
                    {
                        ResetSpaMonSprites();
                        EndSpaBad(taskId);
                    }
                    else
                    {
                        ResetSpaMonSprites();
                        if (sSpaData.mon == SPA_PSYDUCK)
                            EndPsyduckBugsBadTouch(taskId);
                        else
                            StartAngryAnim(taskId);

                        sSpaData.hasBeenPetBad = TRUE;
                    }
                    tPetArea = SPA_PET_NONE;
                    return;
                }
                if (sSpaData.musicSpriteId)
                {
                    DestroySprite(&gSprites[sSpaData.musicSpriteId]);
                    sSpaData.musicSpriteId = 0;
                }
                if (sSpaData.angrySpriteId)
                {
                    DestroySprite(&gSprites[sSpaData.angrySpriteId]);
                    sSpaData.angrySpriteId = 0;
                }
                ResetSpaHand();
                ResetSpaMonSprites();
                DoSpaMonInstructions();
                sSpaData.pausedSpriteId = 0;
            }
            return;
        }
        else if (gSprites[sSpaData.handSpriteId].invisible)
        {
            return;
        }
        SpaHandHandleInput(taskId);
        break;
    case STATE_TRAY_OUT:
        if (gSprites[sSpaData.berrySpriteId].x < (ITEM_END_X + 14))
        {
            if (gSprites[sSpaData.itemTraySpriteId1].x < ITEM_END_X)
            {
                gSprites[sSpaData.itemTraySpriteId1].x += 2;
                gSprites[sSpaData.itemTraySpriteId2].x += 2;
            }
            if (gSprites[sSpaData.itemSelectorSpriteId].x < 0)
                gSprites[sSpaData.itemSelectorSpriteId].x += 2;

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
        break;
    case STATE_ITEM_CHOOSE:
        SpaItemChooseHandleInput(taskId);
        break;
    case STATE_TRAY_IN_ITEM:
        if (gSprites[sSpaData.itemTraySpriteId1].x > ITEM_START_X)
        {
            switch (tSelectedItem)
            {
            case SPA_BERRY:
                tActiveItemId = sSpaData.berrySpriteId;
                break;
            case SPA_CLAW:
                tActiveItemId = sSpaData.clawSpriteId;
                break;
            case SPA_HONEY:
                tActiveItemId = sSpaData.honeySpriteId;
                break;
            case SPA_ORB:
                tActiveItemId = sSpaData.orbSpriteId;
                break;
            }

            gSprites[sSpaData.itemTraySpriteId1].x -= 2;
            gSprites[sSpaData.itemTraySpriteId2].x -= 2;
            if (gSprites[sSpaData.itemSelectorSpriteId].x > ITEM_START_X)
                gSprites[sSpaData.itemSelectorSpriteId].x -= 2;
            if (tSelectedItem != SPA_BERRY && gSprites[sSpaData.berrySpriteId].x > (ITEM_START_X + 10))
                gSprites[sSpaData.berrySpriteId].x -= 2;
            if (tSelectedItem != SPA_CLAW && sSpaData.clawSpriteId)
                gSprites[sSpaData.clawSpriteId].x -= 2;
            if (tSelectedItem != SPA_HONEY && sSpaData.honeySpriteId)
                gSprites[sSpaData.honeySpriteId].x -= 2;
        }
        else
        {
            DestroySprite(&gSprites[sSpaData.itemTraySpriteId1]);
            sSpaData.itemTraySpriteId1 = 0;
            DestroySprite(&gSprites[sSpaData.itemTraySpriteId2]);
            sSpaData.itemTraySpriteId2 = 0;
            DestroySprite(&gSprites[sSpaData.itemSelectorSpriteId]);
            sSpaData.itemSelectorSpriteId = 0;
            if (tSelectedItem != SPA_BERRY)
            {
                DestroySprite(&gSprites[sSpaData.berrySpriteId]);
                sSpaData.berrySpriteId = 0;
            }
            if (tSelectedItem != SPA_CLAW && sSpaData.clawSpriteId)
            {
                DestroySprite(&gSprites[sSpaData.clawSpriteId]);
                sSpaData.clawSpriteId = 0;
            }
            if (tSelectedItem != SPA_HONEY && sSpaData.honeySpriteId)
            {
                DestroySprite(&gSprites[sSpaData.honeySpriteId]);
                sSpaData.honeySpriteId = 0;
            }
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NARROWER, gText_SpaItemInstructions, 0, 0, 0, NULL);
            tState = STATE_ITEM;
        }
        break;
    case STATE_TRAY_IN_HAND:
        if (gSprites[sSpaData.itemTraySpriteId1].x > ITEM_START_X)
        {
            gSprites[sSpaData.itemTraySpriteId1].x -= 2;
            gSprites[sSpaData.itemTraySpriteId2].x -= 2;

            if (gSprites[sSpaData.itemSelectorSpriteId].x > ITEM_START_X)
                gSprites[sSpaData.itemSelectorSpriteId].x -= 2;
            if (gSprites[sSpaData.berrySpriteId].x > (ITEM_START_X + 10))
                gSprites[sSpaData.berrySpriteId].x -= 2;
            if (sSpaData.clawSpriteId)
                gSprites[sSpaData.clawSpriteId].x -= 2;
            if (sSpaData.honeySpriteId)
                gSprites[sSpaData.honeySpriteId].x -= 2;
        }
        else
        {
            DestroySprite(&gSprites[sSpaData.itemTraySpriteId1]);
            sSpaData.itemTraySpriteId1 = 0;
            DestroySprite(&gSprites[sSpaData.itemTraySpriteId2]);
            sSpaData.itemTraySpriteId2 = 0;
            DestroySprite(&gSprites[sSpaData.itemSelectorSpriteId]);
            sSpaData.itemSelectorSpriteId = 0;
            DestroySprite(&gSprites[sSpaData.berrySpriteId]);
            sSpaData.berrySpriteId = 0;
            if (sSpaData.clawSpriteId)
            {
                DestroySprite(&gSprites[sSpaData.clawSpriteId]);
                sSpaData.clawSpriteId = 0;
            }
            if (sSpaData.honeySpriteId)
            {
                DestroySprite(&gSprites[sSpaData.honeySpriteId]);
                sSpaData.honeySpriteId = 0;
            }
            ResetSpaHand();
            tSelectedItem = 0;
            tState = STATE_HAND;
        }
        break;
    case STATE_ITEM:
        SpaItemHandleInput(taskId);
        break;
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

static const u8 SpaMonAttackDelay[SPA_NUM_MONS] =
{
    60, // Rattata
    60, // Teddiursa
    30, // Psyduck
    60  // Fletchinder
};

void Task_SpaEndBad(u8 taskId)
{
    if (tCounter == SpaMonAttackDelay[sSpaData.mon])
    {
        PlaySpaMonAttackSE();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 8, RGB_RED);
    }
    else if (tCounter > SpaMonAttackDelay[sSpaData.mon])
    {
        if (!gPaletteFade.active)
        {
            if (tState == 0)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 1, 8, 0, RGB_RED);
                tState++;
            }
            else if (tState > 0 && sSpaData.mon == SPA_PSYDUCK && tCounter > 120)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
                gTasks[taskId].func = Task_SpaEndFade;
            }
            else if (tState > 0 && sSpaData.mon != SPA_PSYDUCK )
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
                gTasks[taskId].func = Task_SpaEndFade;
            }
        }
    }
    tCounter++;
}

static void Task_SpaEndSuccess(u8 taskId)
{
    if (tCounter == 180)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
        gTasks[taskId].func = Task_SpaEndFade;
    }
    tCounter++;
}

static void SpriteCB_Hand(struct Sprite *sprite)
{

}

static void SpriteCB_Music(struct Sprite *sprite)
{
    if (sprite->sCounter == 10)
    {
        PlaySpaMonCry(CRY_MODE_HIGH_PITCH);
    }
    sprite->sCounter++;
}

static void SpriteCB_ItemTray(struct Sprite *sprite)
{

}

static void SpriteCB_Selector(struct Sprite *sprite)
{
    if (gTasks[sprite->sTaskId].sTaskId == STATE_ITEM_CHOOSE)
    {
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
}

static void SpriteCB_Angry(struct Sprite *sprite)
{

}

static void SpriteCB_Heart(struct Sprite *sprite)
{
    sprite->sCounter++;
    sprite->x2 = Sin2(0 - sprite->sCounter * 3) / 512;
    if (sprite->sCounter % 4 == 0)
        sprite->y--;
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
