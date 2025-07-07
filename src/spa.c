#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

static void ResetForMinigame1(void);
static void ResetForMinigame2(void);
static void VblankCB_SpaGame(void);
static void CB2_SpaGame(void);
static void Task_StartSpa(u8 taskId);

static const u32 gSpaBG_Gfx[] = INCBIN_U32("graphics/_spa/spa_bg.4bpp.lz");
static const u32 gSpaBG_Tilemap[] = INCBIN_U32("graphics/_spa/spa_bg.bin.lz");
static const u16 gSpaBG_Pal[] = INCBIN_U16("graphics/_spa/spa_bg.gbapal");
static const u32 gRattataBG_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata.4bpp.lz");
static const u32 gRattataBG_Tilemap[] = INCBIN_U32("graphics/_spa/rattata/rattata.bin.lz");
static const u16 gRattataBG_Pal[] = INCBIN_U16("graphics/_spa/rattata/rattata.gbapal");

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
        .mapBaseIndex = 20,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

void CB2_InitRattata(void)
{
    ResetForMinigame1();
    
    LZ77UnCompVram(gSpaBG_Gfx, (void*) BG_CHAR_ADDR(1));
    LZ77UnCompVram(gSpaBG_Tilemap, (u16*) BG_SCREEN_ADDR(20));
    LZ77UnCompVram(gRattataBG_Gfx, (void*) BG_CHAR_ADDR(0));
    LZ77UnCompVram(gRattataBG_Tilemap, (u16*) BG_SCREEN_ADDR(6));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    
    ResetForMinigame2();

    LoadPalette(gSpaBG_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(gRattataBG_Pal, BG_PLTT_ID(2), 1 * PLTT_SIZE_4BPP);
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    //LoadFishingSpritesheets();
    //LoadSpritePalettes(sSpritePalettes_FishingGame);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_SpaGame);
    SetMainCallback2(CB2_SpaGame);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    //CreateMinigameSprites(taskId);
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