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
static void SetItemFlagBits(u8 taskId);
static void Task_SpaGame(u8 taskId);
static void MoveSpriteFromInput(struct Sprite *sprite);
static void SpriteCB_RatBodyLeft(struct Sprite *sprite);
static void SpriteCB_RatBodyRight(struct Sprite *sprite);
static void SpriteCB_RatTail(struct Sprite *sprite);
static void SpriteCB_RatEarLeft(struct Sprite *sprite);
static void SpriteCB_RatEarRight(struct Sprite *sprite);
static void SpriteCB_RatMouth(struct Sprite *sprite);
static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite);
static void SpriteCB_RatWhiskerRight(struct Sprite *sprite);
static void SpriteCB_RatToes(struct Sprite *sprite);
static void SpriteCB_RatEyes(struct Sprite *sprite);
static void SpriteCB_Hand(struct Sprite *sprite);
static u8 GetCurrentPettingArea(struct Sprite *sprite);
static void AdjustToPetArea(struct Sprite *sprite, u8 area);
static void StopPetting(struct Sprite *sprite);
static bool8 IsHandOnItemsIcon(struct Sprite *sprite);
static bool8 IsHandOnExitIcon(struct Sprite *sprite);
static void SpriteCB_ItemsIcon(struct Sprite *sprite);
static void SpriteCB_ExitIcon(struct Sprite *sprite);
static void SpriteCB_ItemTray(struct Sprite *sprite);
static void SpriteCB_Selector(struct Sprite *sprite);
static void SpriteCB_Berry(struct Sprite *sprite);
static void Task_ScriptStartSpa(u8 taskId);

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
static const u32 gRattataEyes_Gfx[] = INCBIN_U32("graphics/_spa/rattata/rattata_eyes.4bpp");

static const u16 gHand_Pal[] = INCBIN_U16("graphics/_spa/hand.gbapal");
static const u32 gHand_Gfx[] = INCBIN_U32("graphics/_spa/hand.4bpp");

static const u16 gItemsIcon_Pal[] = INCBIN_U16("graphics/_spa/items_icon.gbapal");
static const u32 gItemsIcon_Gfx[] = INCBIN_U32("graphics/_spa/items_icon.4bpp");
static const u32 gExitIcon_Gfx[] = INCBIN_U32("graphics/_spa/exit_icon.4bpp");
static const u32 gItemTray_Gfx[] = INCBIN_U32("graphics/_spa/item_tray.4bpp");
static const u32 gSelector_Gfx[] = INCBIN_U32("graphics/_spa/selector.4bpp");

static const u16 gBerry_Pal[] = INCBIN_U16("graphics/_spa/berry.gbapal");
static const u32 gBerry_Gfx[] = INCBIN_U32("graphics/_spa/berry.4bpp");

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

static const union AnimCmd * const sAnims_RatEarLeft[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_RatEarRight[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_RatMouth[] =
{
    sAnim_Normal,
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
};

static const union AnimCmd * const sAnims_RatWhiskerRight[] =
{
    sAnim_Normal,
    sAnim_RatWhiskerTwitch,
};

static const union AnimCmd * const sAnims_RatToes[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_RatEyesBlink[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 2, .duration = 3),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 2),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesSmile[] =
{
    ANIMCMD_FRAME(.imageValue = 3, .duration = 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RatEyesBad[] =
{
    ANIMCMD_FRAME(.imageValue = 4, .duration = 60),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_RatEyes[] =
{
    sAnim_Normal,
    sAnim_RatEyesBlink,
    sAnim_RatEyesSmile,
    sAnim_RatEyesBad,
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
};

static const struct SpriteFrameImage sPicTable_RatEarRight[] =
{
    spa_frame(gRattataEarRight_Gfx, 0, 8, 8),
};

static const struct SpriteFrameImage sPicTable_RatMouth[] =
{
    spa_frame(gRattataMouth_Gfx, 0, 8, 4),
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
};

static const struct SpriteFrameImage sPicTable_Hand[] =
{
    spa_frame(gHand_Gfx, 0, 4, 4),
    spa_frame(gHand_Gfx, 1, 4, 4),
    spa_frame(gHand_Gfx, 2, 4, 4),
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

static const struct SpriteFrameImage sPicTable_Berry[] =
{
    spa_frame(gBerry_Gfx, 0, 4, 4),
    spa_frame(gBerry_Gfx, 1, 4, 4),
    spa_frame(gBerry_Gfx, 2, 4, 4),
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
    .priority = 1,
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_32x64 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_32x32 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOam_32x8 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
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

static const struct SpriteTemplate sSpriteTemplate_ItemsIcon =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x32,
    .anims = sAnims_Icon,
    .images = sPicTable_ItemsIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ItemsIcon
};

static const struct SpriteTemplate sSpriteTemplate_ExitIcon =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_ITEMS_ICON,
    .oam = &sOam_32x32,
    .anims = sAnims_Icon,
    .images = sPicTable_ExitIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ExitIcon
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

static const struct SpritePalette sSpritePalettes_RattataSpa[] =
{
    {
        .data = gRattata_Pal,
        .tag = TAG_RATTATA
    },
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
    {NULL},
};

// Task data.
#define tCounter        data[0]
#define tPetArea        data[1]
#define tPetActive      data[2]
#define tPetTimer       data[3]
#define tItemActive     data[4]
#define tItemMenuState  data[5]
#define tSelectedItem   data[6]
#define tItemFlagBits   data[14]
#define tShouldExit     data[15]

// Sprite data.
#define sTaskId         data[0]
#define sCounter        data[1]
#define sInterval       data[2]

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
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

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
    gSprites[spriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&sSpriteTemplate_RatBodyRight, 150, 81, 12);
    gSprites[spriteId].sTaskId = taskId;
    StartSpriteAnim(&gSprites[spriteId], 1);

    spriteId = CreateSprite(&sSpriteTemplate_RatTail, 80, 33, 11);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEarLeft, 111, 32, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEarRight, 175, 32, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatMouth, 144, 80, 10);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatWhiskerLeft, 88, 59, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatWhiskerRight, 199, 57, 9);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatToes, 96, 109, 12);
    gSprites[spriteId].sTaskId = taskId;

    spriteId = CreateSprite(&sSpriteTemplate_RatEyes, 146, 63, 8);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].data[2] = (Random() % 180) + 180;

    spriteId = CreateSprite(&sSpriteTemplate_Hand, 16, 45, 5);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].oam.priority = 0;
    VarSet(VAR_HAND_SPRITE_ID, spriteId);

    spriteId = CreateSprite(&sSpriteTemplate_ItemsIcon, 16, 144, 7);
    gSprites[spriteId].sTaskId = taskId;
    VarSet(VAR_ITEMS_ICON_SPRITE_ID, spriteId);

    spriteId = CreateSprite(&sSpriteTemplate_ExitIcon, 16, 16, 7);
    gSprites[spriteId].sTaskId = taskId;
    VarSet(VAR_ITEMS_EXIT_SPRITE_ID, spriteId);
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
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x2A8, 0xD);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_RattataWary, 0, 1, 0, NULL);
    FillPalette(RGB2GBA(238, 195, 154), BG_PLTT_ID(14) + 1, PLTT_SIZEOF(1));
    FillPalette(RGB2GBA(80, 50, 50), BG_PLTT_ID(14) + 2, PLTT_SIZEOF(1));
    FillPalette(RGB2GBA(180, 148, 117), BG_PLTT_ID(14) + 3, PLTT_SIZEOF(1));
    ScheduleBgCopyTilemapToVram(0);

    SetItemFlagBits(taskId);
    gTasks[taskId].func = Task_SpaGame;
}

static void SetItemFlagBits(u8 taskId)
{
    gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_ALWAYS;

    if (FlagGet(FLAG_SPA_OBTAINED_BERRY))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_BERRY;

    if (FlagGet(FLAG_SPA_OBTAINED_CLAW))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_CLAW;

    if (FlagGet(FLAG_SPA_OBTAINED_HONEY))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_HONEY;

    if (FlagGet(FLAG_SPA_OBTAINED_ORB))
        gTasks[taskId].tItemFlagBits |= SPA_ITEM_BIT_ORB;
}

static void Task_SpaGame(u8 taskId)
{
    RunTextPrinters();

    if (gTasks[taskId].tShouldExit && !gPaletteFade.active)
    {
        ResetAllPicSprites();
        PlayBGM(GetCurrLocationDefaultMusic()); // Play the map's default music.
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
    }

    if (gTasks[taskId].tPetActive && !JOY_HELD(DPAD_ANY))
    {
        if (gTasks[taskId].tPetTimer == 60)
        {
            StopPetting(&gSprites[VarGet(VAR_HAND_SPRITE_ID)]);
        }
        gTasks[taskId].tPetTimer++;
    }
}

static const u16 SpaItemsY[][2] =
{
    { 48, SPA_ITEM_BIT_BERRY }, // Berry.
    { 80, SPA_ITEM_BIT_CLAW }, // Claw.
    { 112, SPA_ITEM_BIT_HONEY }, // Honey.
    { 144, SPA_ITEM_BIT_ORB }, // Orb.
};

static void Task_SpaItemChoose(u8 taskId)
{
    u8 spriteId;

    switch (gTasks[taskId].tItemMenuState)
    {
    case 0:
        spriteId = CreateSprite(&sSpriteTemplate_Selector, -32, SpaItemsY[0][0], 0);
        gSprites[spriteId].sTaskId = taskId;

        spriteId = CreateSprite(&sSpriteTemplate_ItemTray, ITEM_START_X, 48, 1);
        gSprites[spriteId].sTaskId = taskId;
        spriteId = CreateSprite(&sSpriteTemplate_ItemTray, ITEM_START_X, 112, 1);
        gSprites[spriteId].sTaskId = taskId;
        gSprites[spriteId].vFlip = TRUE;

        if (FlagGet(FLAG_SPA_OBTAINED_BERRY))
        {
            spriteId = CreateSprite(&sSpriteTemplate_Berry, ITEM_START_X, SpaItemsY[0][0], 0);
            gSprites[spriteId].sTaskId = taskId;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].x2 = 14;
        }

        gTasks[taskId].tItemMenuState = 1;
        break;
    case 1:
        if (gTasks[taskId].tCounter == 16)
        {
            gTasks[taskId].tCounter = 0;
            gTasks[taskId].tItemMenuState = 2;
        }
        else
        {
            gTasks[taskId].tCounter++;
        }
        break;
    case 2:
        if (JOY_NEW(B_BUTTON) || JOY_NEW(L_BUTTON))
        {
            gTasks[taskId].tItemMenuState = 10;
        }
        if (JOY_NEW(A_BUTTON))
        {
            gTasks[taskId].tItemMenuState = 3;
        }
        break;
    case 3:
        if (gTasks[taskId].tCounter == 16)
        {
            gTasks[taskId].tCounter = 0;
            gTasks[taskId].tItemMenuState = 4;
        }
        else
        {
            gTasks[taskId].tCounter++;
        }
        break;
    case 4:
        break;
    case 10:
        if (gTasks[taskId].tCounter == 16)
        {
            gTasks[taskId].tCounter = 0;
            gTasks[taskId].tItemMenuState = 11;
        }
        else
        {
            gTasks[taskId].tCounter++;
        }
        break;
    case 11:
        gTasks[taskId].tItemActive = FALSE;
        gTasks[taskId].tItemMenuState = 0;
        gTasks[taskId].func = Task_SpaGame;
        break;
    }
}

static void MoveSpriteFromInput(struct Sprite *sprite)
{
    if (JOY_HELD(DPAD_DOWN))
    {
        if (JOY_HELD(B_BUTTON))
            sprite->y++;

        sprite->y++;
        if (sprite->y > 155)
            sprite->y = 155;
    }
    if (JOY_HELD(DPAD_UP))
    {
        if (JOY_HELD(B_BUTTON))
            sprite->y--;

        sprite->y--;
        if (sprite->y < 9)
            sprite->y = 9;
    }
    if (JOY_HELD(DPAD_RIGHT))
    {
        if (JOY_HELD(B_BUTTON))
            sprite->x++;

        sprite->x++;
        if (sprite->x > 240)
            sprite->x = 240;
    }
    if (JOY_HELD(DPAD_LEFT))
    {
        if (JOY_HELD(B_BUTTON))
            sprite->x--;

        sprite->x--;
        if (sprite->x < 10)
            sprite->x = 10;
    }
}

#define sTask       gTasks[sprite->sTaskId]

static void SpriteCB_RatBodyLeft(struct Sprite *sprite)
{
    if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (VarGet(VAR_BODY_COUNTER) == 0)
            StartSpriteAnim(sprite, 2);
        else if (VarGet(VAR_BODY_COUNTER) == 60)
            StartSpriteAnim(sprite, 1);
    }
}

static void SpriteCB_RatBodyRight(struct Sprite *sprite)
{
    if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (VarGet(VAR_BODY_COUNTER) == 0)
            StartSpriteAnim(sprite, 0);
        else if (VarGet(VAR_BODY_COUNTER) == 60)
            StartSpriteAnim(sprite, 1);
    }
}

static void SpriteCB_RatTail(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (VarGet(VAR_BODY_COUNTER) == 0)
            sprite->invisible = TRUE;
        else if (VarGet(VAR_BODY_COUNTER) == 60)
            sprite->invisible = FALSE;
    }
    else if (sTask.tPetArea != RAT_PET_BODY)
    {
        if (counter == 0)
        {
            StartSpriteAnim(sprite, 0);
        }
    }
    else
    {
        if (counter == 0)
        {
            StartSpriteAnim(sprite, 1);
        }
    }
}

static void SpriteCB_RatEarLeft(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetActive && sTask.tPetArea == RAT_PET_HEAD)
    {
        if (counter == 0)
        {
            sprite->y2 = 0;
            sprite->y2--;
        }
        if (counter < 9 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (counter == 0)
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
}

static void SpriteCB_RatEarRight(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetActive && sTask.tPetArea == RAT_PET_HEAD)
    {
        if (counter == 0)
        {
            sprite->y2 = 0;
            sprite->y2--;
        }
        if (counter < 9 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (counter == 0)
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
}

static void SpriteCB_RatMouth(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetActive && sTask.tPetArea == RAT_PET_HEAD)
    {
        if (counter == 0)
        {
            sprite->y2 = 0;
            sprite->y2--;
        }
        if (counter < 9 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (counter == 0)
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
}

static void SpriteCB_RatWhiskerLeft(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetActive && sTask.tPetArea == RAT_PET_HEAD)
    {
        if (counter == 0)
        {
            sprite->y2 = 0;
            sprite->y2--;
            StartSpriteAnim(sprite, 1);
        }
        if (counter < 9 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (counter == 0)
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
        if (counter == 0)
        {
            StartSpriteAnim(sprite, 0);
        }
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }
}

static void SpriteCB_RatWhiskerRight(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetActive && sTask.tPetArea == RAT_PET_HEAD)
    {
        if (counter == 0)
        {
            sprite->y2 = 0;
            sprite->y2--;
            StartSpriteAnim(sprite, 1);
        }
        if (counter < 9 && counter % 4 == 0)
        {
            sprite->y2--;
        }
    }
    else if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (counter == 0)
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
        if (counter == 0)
        {
            StartSpriteAnim(sprite, 0);
        }
        if (sprite->y2 < 0)
        {
            sprite->y2++;
        }
    }
}

static void SpriteCB_RatToes(struct Sprite *sprite)
{

}

#define sHandState  sprite->data[3]

static void SpriteCB_Hand(struct Sprite *sprite)
{
    u8 petArea = GetCurrentPettingArea(sprite);

    if (sprite->invisible == TRUE)
    {
        if (!sTask.tShouldExit && sTask.tPetArea != RAT_PET_BAD && !sTask.tItemActive)
            sprite->invisible = FALSE;

        return;
    }

    switch (sHandState)
    {
    case HAND_NORMAL:
        if (JOY_NEW(L_BUTTON))
        {
            sTask.tItemActive = TRUE;
            sprite->invisible = TRUE;
            sTask.func = Task_SpaItemChoose;
            return;
        }
        if (JOY_NEW(A_BUTTON))
        {
            if (petArea == RAT_PET_BAD)
            {
                sTask.tPetArea = RAT_PET_BAD;
                VarSet(VAR_BODY_COUNTER, 0);
                sprite->invisible = TRUE;
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
        else if (JOY_HELD(A_BUTTON))
        {
            if (petArea)
            {
                if (petArea == RAT_PET_BAD)
                {
                    sTask.tPetArea = RAT_PET_BAD;
                    VarSet(VAR_BODY_COUNTER, 0);
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
        if (!JOY_HELD(A_BUTTON) || !petArea)
        {
            StartSpriteAnim(sprite, 0);
            StopPetting(sprite);
        }
        else if (JOY_HELD(DPAD_ANY))
        {
            sTask.tPetTimer = 0;
            if (!sTask.tPetActive)
            {
                VarSet(VAR_BODY_COUNTER, 0);
                sTask.tPetActive = TRUE;
            }
        }
        break;
    }

    MoveSpriteFromInput(sprite);
}

static const s16 RatPettingZones[][5] =
{
    // { MIN_X, MAX_X, MIN_Y, MAX_Y, BODY_PART }
    { 70, 110, 49, 97, RAT_PET_BODY },
    { 119, 167, 32, 72, RAT_PET_HEAD },
    { 64, 104, 8, 31, RAT_PET_BAD },
    { 56, 72, 25, 73, RAT_PET_BAD },
    { 147, 160, 91, 104, RAT_PET_BAD }
};

static u8 GetCurrentPettingArea(struct Sprite *sprite)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(RatPettingZones); i++)
    {
        if (sprite->x > RatPettingZones[i][0] && sprite->x < RatPettingZones[i][1])
        {
            if (sprite->y > RatPettingZones[i][2] && sprite->y < RatPettingZones[i][3])
            {
                return RatPettingZones[i][4];
            }
        }
    }

    return RAT_PET_NONE;
}

static void AdjustToPetArea(struct Sprite *sprite, u8 area)
{
    if (sTask.tPetArea != area && area != RAT_PET_BAD)
    {
        sTask.tPetArea = area;
        if (sTask.tPetArea == RAT_PET_BODY)
            sprite->subpriority = 11;
    }
}

static void StopPetting(struct Sprite *sprite)
{
    if (sTask.tPetArea != RAT_PET_NONE)
    {
        sTask.tPetArea = RAT_PET_NONE;
        VarSet(VAR_BODY_COUNTER, 0);
        sprite->subpriority = 5;
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

static void SpriteCB_RatEyes(struct Sprite *sprite)
{
    u16 counter = VarGet(VAR_BODY_COUNTER);

    if (sTask.tPetActive)
    {
        switch (sTask.tPetArea)
        {
        case RAT_PET_NONE:
            break;
        case RAT_PET_BODY:
            if (counter == 0)
            {
                sprite->y2 = 0;
                StartSpriteAnim(sprite, 2);
                counter++;
                VarSet(VAR_BODY_COUNTER, counter);
            }
            if (sprite->y2 < 0)
            {
                sprite->y2++;
            }
            break;
        case RAT_PET_HEAD:
            if (counter == 0)
            {
                sprite->y2 = 0;
                StartSpriteAnim(sprite, 2);
                sprite->y2--;
            }
            if (counter < 9)
            {
                if (counter % 4 == 0)
                    sprite->y2--;

                counter++;
                VarSet(VAR_BODY_COUNTER, counter);
            }
            break;
        }
    }
    else if (sTask.tPetArea == RAT_PET_BAD)
    {
        if (counter == 0)
        {
            sprite->y2 = 0;
            StartSpriteAnim(sprite, 3);
            PlaySE(SE_CONTEST_CONDITION_LOSE);
            sprite->y2 = 2;
            sprite->x2 = -2;
        }
        else if (counter == 60)
        {
            struct Sprite *handSprite = &gSprites[VarGet(VAR_HAND_SPRITE_ID)];
            sprite->y2 = 0;
            sprite->x2 = 0;
            handSprite->x = 225;
            handSprite->y = 45;
            StartSpriteAnim(sprite, 0);
            StopPetting(handSprite);
        }
        if (counter < 60)
        {
            counter++;
            VarSet(VAR_BODY_COUNTER, counter);
        }
    }
    else
    {
        if (counter == 0)
        {
            StartSpriteAnim(sprite, 0);
            counter++;
            VarSet(VAR_BODY_COUNTER, counter);
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

static void SpriteCB_ItemsIcon(struct Sprite *sprite)
{

}

static void SpriteCB_ExitIcon(struct Sprite *sprite)
{

}

static void SpriteCB_ItemTray(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == 1 && sprite->x < ITEM_END_X)
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == 3)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == 10)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == 11 || sTask.tItemMenuState == 4)
    {
        DestroySprite(sprite);
    }
}

static void SpriteCB_Selector(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == 1 && sprite->x < 0)
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == 2)
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
                    sTask.tSelectedItem = newPosition;
                    break;
                }
            }
        }

        if (sprite->sCounter == 48)
        {
            sprite->x2++;
        }
        else if (sprite->sCounter == 96)
        {
            sprite->x2--;
            sprite->sCounter = 0;
        }

        sprite->sCounter++;
    }
    else if (sTask.tItemMenuState == 3)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == 10)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == 11 || sTask.tItemMenuState == 4)
    {
        DestroySprite(sprite);
    }
}

static void SpriteCB_Berry(struct Sprite *sprite)
{
    if (sTask.tItemMenuState == 1 && sprite->x < ITEM_END_X)
    {
        sprite->x += 2;
    }
    else if (sTask.tItemMenuState == 3 && sTask.tSelectedItem != 0)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == 4)
    {
        if (sTask.tSelectedItem != 0 || JOY_NEW(A_BUTTON))
        {
            sTask.tItemMenuState = 11;
            DestroySprite(sprite);
        }
        
        MoveSpriteFromInput(sprite);
    }
    else if (sTask.tItemMenuState == 10)
    {
        sprite->x -= 2;
    }
    else if (sTask.tItemMenuState == 11)
    {
        DestroySprite(sprite);
    }
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
        PlayBGM(MUS_TRICK_HOUSE);
        SetMainCallback2(CB2_InitRattata);
        gMain.savedCallback = CB2_ReturnToField;
        DestroyTask(taskId);
    }
}