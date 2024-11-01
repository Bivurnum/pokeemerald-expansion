#include "global.h"
#include "battle_anim.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "look_feet.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define TAG_SWIPE_GROUND 0x1000
#define TAG_ITEM  0x1001
//#define TAG_DUST  0x1002

#define LEFT    0
#define RIGHT   1

const u16 gLookFeetGround_Pal[] = INCBIN_U16("graphics/look_feet/tiles.gbapal");
const u32 gLookFeetGroundTilemap[] = INCBIN_U32("graphics/look_feet/birch_grass.bin.lz");
const u32 gLookFeetGround_Gfx[] = INCBIN_U32("graphics/look_feet/tiles.4bpp.lz");
const u32 gSwipeGround_Gfx[] = INCBIN_U32("graphics/look_feet/pokeball_selection.4bpp.lz");
//static const u32 sStarterCircle_Gfx[] = INCBIN_U32("graphics/look_feet/starter_circle.4bpp.lz");
static const u16 sSwipeGround_Pal[] = INCBIN_U16("graphics/look_feet/pokeball_selection.gbapal");
//static const u16 sStarterCircle_Pal[] = INCBIN_U16("graphics/look_feet/starter_circle.gbapal");

static void CB2_StartLookAtFeet(void);
static void Task_InitSprites(u8 taskId);
static void Task_LookAtFeet(u8 taskId);
static void Task_HandleLookFeetInput(u8 taskId);
static void Task_ExitLookFeet(u8 taskId);
static u8 ChangeSwipeSide(u8 side);
static void SpriteCB_Ground(struct Sprite *sprite);
static void LF_AnimHandSwipeLeft(struct Sprite *sprite);
static void LF_AnimHandSwipeRight(struct Sprite *sprite);
static void Task_WaitForHandSwipe(u8 taskId);
static void SpriteCB_Item_Still(struct Sprite *sprite);
static void Task_FoundItem(u8 taskId);
static void Task_ItemToBag(u8 taskId);
static void SpriteCB_Item_Float_To_Pocket(struct Sprite *sprite);
static void CreateDustSprites(void);
static void SpriteCB_Dust(struct Sprite *sprite);

extern const struct CompressedSpriteSheet gBattleAnimPicTable[];

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 17,
        .width = 28,
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
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
};

static const struct OamData sOam_Hand =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Ground =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_Item =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_PokeballSelect[] =
{
    {
        .data = gSwipeGround_Gfx,
        .size = 0x2000,
        .tag = TAG_SWIPE_GROUND
    },
    {}
};

static const struct SpritePalette sSpritePalettes_StarterChoose[] =
{
    {
        .data = sSwipeGround_Pal,
        .tag = TAG_SWIPE_GROUND
    },
    {},
};

static const union AnimCmd sAnim_Hand[] =
{
    ANIMCMD_FRAME(192, 50),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GroundStart[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ground1[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Ground2[] =
{
    ANIMCMD_FRAME(128, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Item[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Dust[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(64, 5),
    ANIMCMD_FRAME(96, 5),
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_END,
};

static const union AnimCmd * const sAnims_Hand[] =
{
    sAnim_Hand,
};

static const union AnimCmd * const sAnims_Ground[] =
{
    sAnim_GroundStart,
    sAnim_Ground1,
    sAnim_Ground2,
};

static const union AnimCmd * const sAnims_Item[] =
{
    sAnim_Item,
};

static const union AnimCmd * const sAnims_Dust[] =
{
    sAnim_Dust,
};

static const union AffineAnimCmd sAffineAnim_Item_Still[] =
{
    AFFINEANIMCMD_FRAME(512, 512, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Item_Shake[] =
{
    AFFINEANIMCMD_FRAME(512, 512, 0, 0),
    AFFINEANIMCMD_FRAME(3, 3, 0, 15),
    AFFINEANIMCMD_FRAME(0, 0, 254, 10),
    AFFINEANIMCMD_FRAME(0, 0, 2, 15),
    AFFINEANIMCMD_FRAME(0, 0, 254, 15),
    AFFINEANIMCMD_FRAME(0, 0, 2, 10),
    AFFINEANIMCMD_FRAME(-3, -3, 0, 15),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_Item_To_Bag[] =
{
    AFFINEANIMCMD_FRAME(512, 512, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, -1, 50),
    AFFINEANIMCMD_END,
};

enum {
    ANIM_ITEM_STILL,
    ANIM_ITEM_SHAKE,
    ANIM_ITEM_TO_BAG,
};

static const union AffineAnimCmd * const sAffineAnims_Item[] =
{
    [ANIM_ITEM_STILL] = sAffineAnim_Item_Still,
    [ANIM_ITEM_SHAKE] = sAffineAnim_Item_Shake,
    [ANIM_ITEM_TO_BAG] = sAffineAnim_Item_To_Bag,
};

static const struct SpriteTemplate sSpriteTemplate_HandLeft =
{
    .tileTag = TAG_SWIPE_GROUND,
    .paletteTag = TAG_SWIPE_GROUND,
    .oam = &sOam_Hand,
    .anims = sAnims_Hand,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = LF_AnimHandSwipeLeft
};

static const struct SpriteTemplate sSpriteTemplate_HandRight =
{
    .tileTag = TAG_SWIPE_GROUND,
    .paletteTag = TAG_SWIPE_GROUND,
    .oam = &sOam_Hand,
    .anims = sAnims_Hand,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = LF_AnimHandSwipeRight
};

static const struct SpriteTemplate sSpriteTemplate_Ground =
{
    .tileTag = TAG_SWIPE_GROUND,
    .paletteTag = TAG_SWIPE_GROUND,
    .oam = &sOam_Ground,
    .anims = sAnims_Ground,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Ground
};

static const struct SpriteTemplate sSpriteTemplate_Item =
{
    .tileTag = TAG_ITEM,
    .paletteTag = TAG_ITEM,
    .oam = &sOam_Item,
    .anims = sAnims_Item,
    .images = NULL,
    .affineAnims = sAffineAnims_Item,
    .callback = SpriteCB_Item_Still
};

static const struct SpriteTemplate sSpriteTemplate_Dust =
{
    .tileTag = ANIM_TAG_GRAY_SMOKE,
    .paletteTag = ANIM_TAG_GRAY_SMOKE,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_Dust,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Dust
};

void LookAtFeet(void)
{
/*
    if (IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }
    LockPlayerFieldControls();
    */
    SetMainCallback2(CB2_StartLookAtFeet);
    gMain.savedCallback = CB2_ReturnToField;
}

static void VblankCB_LookFeet(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Data for sSpriteTemplate_Ground
#define sTaskId data[0]
#define sBallId data[1]

static void CB2_StartLookAtFeet(void)
{
    //u8 taskId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gLookFeetGround_Gfx, (void *)VRAM);
    LZ77UnCompVram(gLookFeetGroundTilemap, (void *)(BG_SCREEN_ADDR(6)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);

    DeactivateAllTextPrinters();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    //LoadPalette(sMapPreviewImageData[sMapPreviewScreenData[idx].image].palptr, BG_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
    LoadPalette(gLookFeetGround_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadUserWindowBorderGfx(0, 0x2A8, BG_PLTT_ID(13));
    LoadCompressedSpriteSheet(&sSpriteSheet_PokeballSelect[0]);
    //LoadCompressedSpriteSheet(&sSpriteSheet_StarterCircle[0]);
    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_GRAY_SMOKE)]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_GRAY_SMOKE)]);
    LoadSpritePalettes(sSpritePalettes_StarterChoose);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_LookFeet);
    SetMainCallback2(CB2_LookAtFeet);

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    CreateTask(Task_InitSprites, 0);
}

static void Task_InitSprites(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u8 spriteId;

        // Create Ground Sprite
        spriteId = CreateSprite(&sSpriteTemplate_Ground, 120, 60, 2);
        gSprites[spriteId].sTaskId = taskId;
        gTasks[taskId].data[3] = spriteId;
        gTasks[taskId].data[0] = 2;

        FreeSpriteTilesByTag(102); // TAG_ITEM_ICON
        FreeSpritePaletteByTag(102); // TAG_ITEM_ICON

        // Create Item Sprite
        spriteId = AddCustomItemIconSprite(&sSpriteTemplate_Item, TAG_ITEM, TAG_ITEM, gSpecialVar_0x8005);
        gSprites[spriteId].callback = SpriteCB_Item_Still;
        gSprites[spriteId].subpriority = 3;
        gSprites[spriteId].sTaskId = taskId;
        gTasks[taskId].data[4] = spriteId;

        gTasks[taskId].func = Task_LookAtFeet;
    }
}

void CB2_LookAtFeet(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

// Data for Task_LookAtFeet
#define tCurrSide           data[0]
#define tHandSpriteId       data[1]
#define tNumSwipes          data[2]
#define tGroundSpriteId     data[3]
#define tItemSpriteId       data[4]
#define tFrameCounter       data[5]

static void Task_LookAtFeet(u8 taskId)
{
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_HandleLookFeetInput;
}

static void Task_HandleLookFeetInput(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tNumSwipes >= 3)
    {
        s32 xPos;

        gSpecialVar_Result = AddBagItem(gSpecialVar_0x8005, 1);
        if (gSpecialVar_Result)
            PlayFanfare(MUS_OBTAIN_ITEM);

        StartSpriteAffineAnim(&gSprites[gTasks[taskId].tItemSpriteId], ANIM_ITEM_SHAKE);
        CopyItemName(gSpecialVar_0x8005, gStringVar1);
        gSpecialVar_0x8003 = gSpecialVar_0x8004;
        gSpecialVar_0x8004 = gSpecialVar_0x8005;
        if (BufferTMHMMoveName())
            StringExpandPlaceholders(gStringVar4, gText_FoundAHiddenTMHM);
        else
            StringExpandPlaceholders(gStringVar4, gText_FoundAHiddenItem);

        DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
        xPos = GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 226);
        AddTextPrinterParameterized(0, FONT_NORMAL, gStringVar4, xPos, 1, 0, NULL);
        PutWindowTilemap(0);
        ScheduleBgCopyTilemapToVram(0);
        gTasks[taskId].func = Task_FoundItem;
    }
    else if (JOY_NEW(DPAD_LEFT) && gTasks[taskId].tCurrSide > 0)
    {
        if (gTasks[taskId].tCurrSide == 2)
            gTasks[taskId].tCurrSide = RIGHT;

        // Create hand sprite
        spriteId = CreateSprite(&sSpriteTemplate_HandLeft, 180, 70, 0);
        gSprites[spriteId].data[0] = taskId;
        gSprites[spriteId].tFrameCounter = 0;
        gTasks[taskId].tHandSpriteId = spriteId;
        gTasks[taskId].tCurrSide = ChangeSwipeSide(gTasks[taskId].tCurrSide);
        gTasks[taskId].func = Task_WaitForHandSwipe;
        PlaySE(SE_M_SCRATCH);
    }
    else if (JOY_NEW(DPAD_RIGHT) && gTasks[taskId].tCurrSide != RIGHT)
    {
        if (gTasks[taskId].tCurrSide == 2)
            gTasks[taskId].tCurrSide = LEFT;
            
        // Create hand sprite
        spriteId = CreateSprite(&sSpriteTemplate_HandRight, 70, 70, 0);
        gSprites[spriteId].data[0] = taskId;
        gSprites[spriteId].tFrameCounter = 0;
        gTasks[taskId].tHandSpriteId = spriteId;
        gTasks[taskId].tCurrSide = ChangeSwipeSide(gTasks[taskId].tCurrSide);
        gTasks[taskId].func = Task_WaitForHandSwipe;
        PlaySE(SE_M_SCRATCH);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        DestroySprite(&gSprites[gTasks[taskId].tItemSpriteId]);
        DestroySprite(&gSprites[gTasks[taskId].tGroundSpriteId]);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_ExitLookFeet;
    }
}

static u8 ChangeSwipeSide(u8 side)
{
    if (side == LEFT)
        return RIGHT;

    if (side == RIGHT)
        return LEFT;

    return LEFT;
}

static void Task_WaitForHandSwipe(u8 taskId)
{
    u8 spriteId;

    if (gSprites[gTasks[taskId].tHandSpriteId].animEnded)
    {
        spriteId = gTasks[taskId].tHandSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        gTasks[taskId].func = Task_HandleLookFeetInput;
    }
}

static void Task_FoundItem(u8 taskId)
{
    if (IsFanfareTaskInactive() && gSprites[gTasks[taskId].tItemSpriteId].affineAnimEnded && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        u32 xPos;
            
        PlaySE(SE_SELECT);
        if (gSpecialVar_Result)
        {
            FlagSet(gSpecialVar_0x8003); // Set hidden item flag
            StringExpandPlaceholders(gStringVar4, gText_PutAwayHiddenItem);
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            xPos = GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 226);
            AddTextPrinterParameterized(0, FONT_NORMAL, gStringVar4, xPos, 1, 0, NULL);
            gTasks[taskId].tFrameCounter = 0;
            
            gTasks[taskId].func = Task_ItemToBag;
            gSprites[gTasks[taskId].tItemSpriteId].callback = SpriteCB_Item_Float_To_Pocket;
            StartSpriteAffineAnim(&gSprites[gTasks[taskId].tItemSpriteId], ANIM_ITEM_TO_BAG);
        }
        else {
            StringExpandPlaceholders(gStringVar4, gText_PocketIsFull);
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            xPos = GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 226);
            AddTextPrinterParameterized(0, FONT_NORMAL, gStringVar4, xPos, 1, 0, NULL);
            gTasks[taskId].tFrameCounter = 0;
            
            gTasks[taskId].func = Task_ItemToBag;
        }
    }
}

static void Task_ItemToBag(u8 taskId)
{
    if (gTasks[taskId].tFrameCounter < 40)
        gTasks[taskId].tFrameCounter++;

    if (gTasks[taskId].tFrameCounter >= 20 && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))) {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Task_ExitLookFeet;
    }
}

static void Task_ExitLookFeet(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ResetAllPicSprites();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToField);
    }
}

static void CreateDustSprites(void)
{
    //s32 limit = (Random() % 2) + 3;
    s32 i;

    for (i = 0; i < 5; i++)
    {
        u16 rand;
        s32 x, y;
        u8 spriteId;

        rand = (Random() % 20);

        x = gSineTable[(rand & 0xFF) + 64] / 4;
        y = gSineTable[(rand & 0xFF)] / 4;

        spriteId = CreateSprite(&sSpriteTemplate_Dust, x + 60, y + 45, 1);
        gSprites[spriteId].data[0] = 16 - (Random() % 32);
        gSprites[spriteId].data[1] = 16 - (Random() % 32);

        gSprites[spriteId].callback = SpriteCB_Dust;
        gSprites[spriteId].oam.priority = 1;
    }
}

#define sFrameCounter       data[1]
    
static void LF_AnimHandSwipeLeft(struct Sprite *sprite)
{
    if (sprite->sFrameCounter == 10)
    {
        gTasks[sprite->sTaskId].tNumSwipes++;
        CreateDustSprites();
    }

    sprite->sFrameCounter++;
    sprite->y2 = Sin2(200 + sprite->sFrameCounter * 6) / 512;
    //sprite->y2 = Sin(sprite->sFrameCounter, 8);
    //sprite->data[1] = (u8)(sprite->data[1]) - 2;

    if (sprite->sFrameCounter <= 5)
    {
        sprite->x -= 3;
    }
    else if (sprite->sFrameCounter <= 15)
    {
        sprite->x -= 6;
    }
    else if (sprite->sFrameCounter <= 25)
    {
        sprite->x -= 3;
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

static void LF_AnimHandSwipeRight(struct Sprite *sprite)
{
    if (sprite->sFrameCounter == 10)
    {
        gTasks[sprite->sTaskId].tNumSwipes++;
        CreateDustSprites();
    }

    sprite->sFrameCounter++;
    sprite->y2 = Sin2(200 + sprite->sFrameCounter * 6) / 512;
    //sprite->y2 = Sin(sprite->sFrameCounter, 8);
    //sprite->data[1] = (u8)(sprite->data[1]) - 2;

    if (sprite->sFrameCounter <= 5)
    {
        sprite->x += 3;
    }
    else if (sprite->sFrameCounter <= 15)
    {
        sprite->x += 6;
    }
    else if (sprite->sFrameCounter <= 25)
    {
        sprite->x += 3;
    }
    else
    {
        sprite->invisible = TRUE;
    }
}

static void SpriteCB_Ground(struct Sprite *sprite)
{
    u8 spriteId;

    switch (gTasks[sprite->sTaskId].tNumSwipes)
    {
        case 0:
            break;
        case 1:
        case 2:
            StartSpriteAnimIfDifferent(sprite, gTasks[sprite->sTaskId].tNumSwipes);
            break;
        default:
            spriteId = gTasks[sprite->sTaskId].tGroundSpriteId;
            FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
            DestroySprite(&gSprites[spriteId]);
    }
}

static void SpriteCB_Item_Still(struct Sprite *sprite)
{
    sprite->x = 127;
    sprite->y = 70;
}

static void SpriteCB_Item_Float_To_Pocket(struct Sprite *sprite)
{
    if (sprite->sFrameCounter <= 5)
        sprite->y2-=2;
    else if ((sprite->sFrameCounter >= 6 && sprite->sFrameCounter <= 8) || sprite->sFrameCounter == 10 || sprite->sFrameCounter == 12)
        sprite->y2-=1;
    else if (sprite->sFrameCounter == 16 || sprite->sFrameCounter == 18 || (sprite->sFrameCounter >= 20 && sprite->sFrameCounter <= 24))
        sprite->y2+=1;
    else if (sprite->sFrameCounter > 24 && sprite->sFrameCounter < 30)
        sprite->y2+=2;
    else if (sprite->sFrameCounter >= 30 && sprite->sFrameCounter < 40)
        sprite->y2+=3;
    else if (sprite->sFrameCounter >= 40)
        sprite->y2+=4;

    sprite->x2 = Sin2(-200 - sprite->sFrameCounter * 3) / 64;

    if (sprite->y2 > 150)
    {
        u8 spriteId;

        spriteId = gTasks[sprite->sTaskId].tItemSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
    }

    sprite->sFrameCounter++;
}

static void SpriteCB_Dust(struct Sprite *sprite)
{
    sprite->data[2] += sprite->data[0];
    sprite->data[3] += sprite->data[1];
    sprite->x2 = sprite->data[2] / 8;
    sprite->y2 = sprite->data[3] / 8;

    if (sprite->data[5] >= 40)
        DestroySprite(sprite);

    sprite->data[5]++;
}
