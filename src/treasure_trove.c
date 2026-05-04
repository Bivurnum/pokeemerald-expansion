#include "global.h"
#include "treasure_trove.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "fishing_game.h"
#include "item_menu.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

static const u32 gMugshotFrame_Gfx[] = INCBIN_U32("graphics/treasure_trove/mugshot_frame.4bpp.lz");
static const u16 sMugshotFrame_Pal[] = INCBIN_U16("graphics/treasure_trove/mugshot_frame.gbapal");

static const u32 gMagikarpMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/magikarp_mug.4bpp.lz");
static const u16 sMagikarpMug_Pal[] = INCBIN_U16("graphics/treasure_trove/magikarp_mug.gbapal");

static const u32 gKrabbyMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/krabby_mug.4bpp.lz");
static const u16 sKrabbyMug_Pal[] = INCBIN_U16("graphics/treasure_trove/krabby_mug.gbapal");

static const u32 gGyaradosMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/gyarados_mug.4bpp.lz");
static const u16 sGyaradosMug_Pal[] = INCBIN_U16("graphics/treasure_trove/gyarados_mug.gbapal");

static const u32 gOctilleryMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/octillery_mug.4bpp.lz");
static const u16 sOctilleryMug_Pal[] = INCBIN_U16("graphics/treasure_trove/octillery_mug.gbapal");

static const u32 gWooperMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/wooper_mug.4bpp.lz");
static const u16 sWooperMug_Pal[] = INCBIN_U16("graphics/treasure_trove/wooper_mug.gbapal");

static const u32 gShellderMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/shellder_mug.4bpp.lz");
static const u16 sShellderMug_Pal[] = INCBIN_U16("graphics/treasure_trove/shellder_mug.gbapal");

static const u32 gStaryuMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/staryu_mug.4bpp.lz");
static const u16 sStaryuMug_Pal[] = INCBIN_U16("graphics/treasure_trove/staryu_mug.gbapal");

static const u32 gDondozoMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/dondozo_mug.4bpp.lz");
static const u16 sDondozoMug_Pal[] = INCBIN_U16("graphics/treasure_trove/dondozo_mug.gbapal");

static const u32 gCramorantMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/cramorant_mug.4bpp.lz");
static const u16 sCramorantMug_Pal[] = INCBIN_U16("graphics/treasure_trove/cramorant_mug.gbapal");

static const u32 gKyogreMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/kyogre_mug.4bpp.lz");
static const u16 sKyogreMug_Pal[] = INCBIN_U16("graphics/treasure_trove/kyogre_mug.gbapal");

static const u32 gLumineonMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/lumineon_mug.4bpp.lz");
static const u16 sLumineonMug_Pal[] = INCBIN_U16("graphics/treasure_trove/lumineon_mug.gbapal");

static const u32 gDragonairMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/dragonair_mug.4bpp.lz");
static const u16 sDragonairMug_Pal[] = INCBIN_U16("graphics/treasure_trove/dragonair_mug.gbapal");

static const u32 gBarboachMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/barboach_mug.4bpp.lz");
static const u16 sBarboachMug_Pal[] = INCBIN_U16("graphics/treasure_trove/barboach_mug.gbapal");

static const u32 gCarvanhaMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/carvanha_mug.4bpp.lz");
static const u16 sCarvanhaMug_Pal[] = INCBIN_U16("graphics/treasure_trove/carvanha_mug.gbapal");

static const u32 gFinizenMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/finizen_mug.4bpp.lz");
static const u16 sFinizenMug_Pal[] = INCBIN_U16("graphics/treasure_trove/finizen_mug.gbapal");

static const u32 gArrokudaMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/arrokuda_mug.4bpp.lz");
static const u16 sArrokudaMug_Pal[] = INCBIN_U16("graphics/treasure_trove/arrokuda_mug.gbapal");

static const u32 gBruxishMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/bruxish_mug.4bpp.lz");
static const u16 sBruxishMug_Pal[] = INCBIN_U16("graphics/treasure_trove/bruxish_mug.gbapal");

static const u32 gSkrelpMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/skrelp_mug.4bpp.lz");
static const u16 sSkrelpMug_Pal[] = INCBIN_U16("graphics/treasure_trove/skrelp_mug.gbapal");

static const u32 gWailmerMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/wailmer_mug.4bpp.lz");
static const u16 sWailmerMug_Pal[] = INCBIN_U16("graphics/treasure_trove/wailmer_mug.gbapal");

static const u32 gAzumarillMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/azumarill_mug.4bpp.lz");
static const u16 sAzumarillMug_Pal[] = INCBIN_U16("graphics/treasure_trove/azumarill_mug.gbapal");

static const u32 gTentacruelMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/tentacruel_mug.4bpp.lz");
static const u16 sTentacruelMug_Pal[] = INCBIN_U16("graphics/treasure_trove/tentacruel_mug.gbapal");

static const u32 gLuvdiscMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/luvdisc_mug.4bpp.lz");
static const u16 sLuvdiscMug_Pal[] = INCBIN_U16("graphics/treasure_trove/luvdisc_mug.gbapal");

static const u32 gMurkrowMug_Gfx[] = INCBIN_U32("graphics/treasure_trove/murkrow_mug.4bpp.lz");
static const u16 sMurkrowMug_Pal[] = INCBIN_U16("graphics/treasure_trove/murkrow_mug.gbapal");

static const struct CompressedSpriteSheet sSpriteSheet_MugshotFrame =
{
    .data = gMugshotFrame_Gfx,
    .size = 2048,
    .tag = TAG_MUGSHOT_FRAME
};

static const struct CompressedSpriteSheet sSpriteSheets_Mugshots[] =
{
    [TT_KRABBY] = {
        .data = gKrabbyMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_MAGIKARP] = {
        .data = gMagikarpMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_GYARADOS] = {
        .data = gGyaradosMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_OCTILLERY] = {
        .data = gOctilleryMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_WOOPER] = {
        .data = gWooperMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_SHELLDER] = {
        .data = gShellderMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_STARYU] = {
        .data = gStaryuMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_DONDOZO] = {
        .data = gDondozoMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_CRAMORANT] = {
        .data = gCramorantMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_KYOGRE] = {
        .data = gKyogreMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_LUMINEON] = {
        .data = gLumineonMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_DRAGONAIR] = {
        .data = gDragonairMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_BARBOACH] = {
        .data = gBarboachMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_CARVANHA] = {
        .data = gCarvanhaMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_FINIZEN] = {
        .data = gFinizenMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_ARROKUDA] = {
        .data = gArrokudaMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_BRUXISH] = {
        .data = gBruxishMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_SKRELP] = {
        .data = gSkrelpMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_WAILMER] = {
        .data = gWailmerMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_AZUMARILL] = {
        .data = gAzumarillMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_TENTACRUEL] = {
        .data = gTentacruelMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_LUVDISC] = {
        .data = gLuvdiscMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
    [TT_MURKROW] = {
        .data = gMurkrowMug_Gfx,
        .size = 2048,
        .tag = TAG_MUGSHOT
    },
};

static const struct SpritePalette sSpritePalette_MugshotFrame =
{
    .data = sMugshotFrame_Pal,
    .tag = TAG_MUGSHOT_FRAME
};

static const struct SpritePalette sSpritePalettes_Mugshots[] =
{
    [TT_MAGIKARP] = {
        .data = sMagikarpMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_KRABBY] = {
        .data = sKrabbyMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_GYARADOS] = {
        .data = sGyaradosMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_OCTILLERY] = {
        .data = sOctilleryMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_WOOPER] = {
        .data = sWooperMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_SHELLDER] = {
        .data = sShellderMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_STARYU] = {
        .data = sStaryuMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_DONDOZO] = {
        .data = sDondozoMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_CRAMORANT] = {
        .data = sCramorantMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_KYOGRE] = {
        .data = sKyogreMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_LUMINEON] = {
        .data = sLumineonMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_DRAGONAIR] = {
        .data = sDragonairMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_BARBOACH] = {
        .data = sBarboachMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_CARVANHA] = {
        .data = sCarvanhaMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_FINIZEN] = {
        .data = sFinizenMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_ARROKUDA] = {
        .data = sArrokudaMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_BRUXISH] = {
        .data = sBruxishMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_SKRELP] = {
        .data = sSkrelpMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_WAILMER] = {
        .data = sWailmerMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_AZUMARILL] = {
        .data = sAzumarillMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_TENTACRUEL] = {
        .data = sTentacruelMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_LUVDISC] = {
        .data = sLuvdiscMug_Pal,
        .tag = TAG_MUGSHOT
    },
    [TT_MURKROW] = {
        .data = sMurkrowMug_Pal,
        .tag = TAG_MUGSHOT
    },
};

static const struct OamData sOam_Mugshot =
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

static const struct SpriteTemplate sSpriteTemplate_MugshotFrame =
{
    .tileTag = TAG_MUGSHOT_FRAME,
    .paletteTag = TAG_MUGSHOT_FRAME,
    .oam = &sOam_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Mugshot =
{
    .tileTag = TAG_MUGSHOT,
    .paletteTag = TAG_MUGSHOT,
    .oam = &sOam_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const u8 gText_MagikarpFirst[] = _("Karp!\nWhat do you want?\pA piece of treasure?\nI did find something shiny earlier.\pHere.\nYou can have it.{PAUSE_UNTIL_PRESS}");
static const u8 gText_KrabbyFirst[] = _("Alright!\nYou're really asking for a pinching!\pGet ready for-\pOh!\nYou're just looking for lost loot?\pI think I've got a piece right here.{PAUSE_UNTIL_PRESS}");
static const u8 gText_ArrokudaFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_GyaradosFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_OctilleryFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_SkrelpFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BruxishFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_TentacruelFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WailmerFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WooperFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BarboachFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CarvanhaFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_AzumarillFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LuvdiscFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_FinizenFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CramorantFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DondozoFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_StaryuFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ShellderFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LumineonFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DragonairFirst[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");

static const u8 gText_MagikarpCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_KrabbyCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ArrokudaCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_GyaradosCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_OctilleryCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_SkrelpCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BruxishCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_TentacruelCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WailmerCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WooperCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BarboachCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CarvanhaCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_AzumarillCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LuvdiscCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_FinizenCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CramorantCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DondozoCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_StaryuCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ShellderCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LumineonCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DragonairCaughtAgain[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");

static const u8 gText_MagikarpCaughtAgainNoTreasure[] = _("Karp!\pWe Magikarp don't have any more of\nthose shiny things.\pIt is very fun to be caught, though.\nSee you next time!{PAUSE_UNTIL_PRESS}");
static const u8 gText_KrabbyCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ArrokudaCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_GyaradosCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_OctilleryCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_SkrelpCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BruxishCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_TentacruelCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WailmerCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WooperCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BarboachCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CarvanhaCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_AzumarillCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LuvdiscCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_FinizenCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CramorantCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DondozoCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_StaryuCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ShellderCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LumineonCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DragonairCaughtAgainNoTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");

static const u8 gText_MagikarpAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_KrabbyAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ArrokudaAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_GyaradosAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_OctilleryAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_SkrelpAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BruxishAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_TentacruelAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WailmerAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_WooperAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_BarboachAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CarvanhaAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_AzumarillAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LuvdiscAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_FinizenAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_CramorantAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DondozoAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_StaryuAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_ShellderAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_LumineonAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");
static const u8 gText_DragonairAfterTreasure[] = _("PLACEHOLDER{PAUSE_UNTIL_PRESS}");

static const u8 gText_GotPieceOfTreasure[] = _("You got a piece of treasure!");

static const u8 *const sTreasureText[][4] =
{
    [TT_MAGIKARP]   = {gText_MagikarpFirst,   gText_MagikarpCaughtAgain,   gText_MagikarpAfterTreasure,   gText_MagikarpCaughtAgainNoTreasure  },
    [TT_KRABBY]     = {gText_KrabbyFirst,     gText_KrabbyCaughtAgain,     gText_KrabbyAfterTreasure,     gText_KrabbyCaughtAgainNoTreasure    },
    [TT_ARROKUDA]   = {gText_ArrokudaFirst,   gText_ArrokudaCaughtAgain,   gText_ArrokudaAfterTreasure,   gText_ArrokudaCaughtAgainNoTreasure  },
    [TT_GYARADOS]   = {gText_GyaradosFirst,   gText_GyaradosCaughtAgain,   gText_GyaradosAfterTreasure,   gText_GyaradosCaughtAgainNoTreasure  },
    [TT_OCTILLERY]  = {gText_OctilleryFirst,  gText_OctilleryCaughtAgain,  gText_OctilleryAfterTreasure,  gText_OctilleryCaughtAgainNoTreasure },
    [TT_SKRELP]     = {gText_SkrelpFirst,     gText_SkrelpCaughtAgain,     gText_SkrelpAfterTreasure,     gText_SkrelpCaughtAgainNoTreasure    },
    [TT_BRUXISH]    = {gText_BruxishFirst,    gText_BruxishCaughtAgain,    gText_BruxishAfterTreasure,    gText_BruxishCaughtAgainNoTreasure   },
    [TT_TENTACRUEL] = {gText_TentacruelFirst, gText_TentacruelCaughtAgain, gText_TentacruelAfterTreasure, gText_TentacruelCaughtAgainNoTreasure},
    [TT_WAILMER]    = {gText_WailmerFirst,    gText_WailmerCaughtAgain,    gText_WailmerAfterTreasure,    gText_WailmerCaughtAgainNoTreasure   },
    [TT_WOOPER]     = {gText_WooperFirst,     gText_WooperCaughtAgain,     gText_WooperAfterTreasure,     gText_WooperCaughtAgainNoTreasure    },
    [TT_BARBOACH]   = {gText_BarboachFirst,   gText_BarboachCaughtAgain,   gText_BarboachAfterTreasure,   gText_BarboachCaughtAgainNoTreasure  },
    [TT_CARVANHA]   = {gText_CarvanhaFirst,   gText_CarvanhaCaughtAgain,   gText_CarvanhaAfterTreasure,   gText_CarvanhaCaughtAgainNoTreasure  },
    [TT_AZUMARILL]  = {gText_AzumarillFirst,  gText_AzumarillCaughtAgain,  gText_AzumarillAfterTreasure,  gText_AzumarillCaughtAgainNoTreasure },
    [TT_LUVDISC]    = {gText_LuvdiscFirst,    gText_LuvdiscCaughtAgain,    gText_LuvdiscAfterTreasure,    gText_LuvdiscCaughtAgainNoTreasure   },
    [TT_FINIZEN]    = {gText_FinizenFirst,    gText_FinizenCaughtAgain,    gText_FinizenAfterTreasure,    gText_FinizenCaughtAgainNoTreasure   },
    [TT_CRAMORANT]  = {gText_CramorantFirst,  gText_CramorantCaughtAgain,  gText_CramorantAfterTreasure,  gText_CramorantCaughtAgainNoTreasure },
    [TT_DONDOZO]    = {gText_DondozoFirst,    gText_DondozoCaughtAgain,    gText_DondozoAfterTreasure,    gText_DondozoCaughtAgainNoTreasure   },
    [TT_STARYU]     = {gText_StaryuFirst,     gText_StaryuCaughtAgain,     gText_StaryuAfterTreasure,     gText_StaryuCaughtAgainNoTreasure    },
    [TT_SHELLDER]   = {gText_ShellderFirst,   gText_ShellderCaughtAgain,   gText_ShellderAfterTreasure,   gText_ShellderCaughtAgainNoTreasure  },
    [TT_LUMINEON]   = {gText_LumineonFirst,   gText_LumineonCaughtAgain,   gText_LumineonAfterTreasure,   gText_LumineonCaughtAgainNoTreasure  },
    [TT_DRAGONAIR]  = {gText_DragonairFirst,  gText_DragonairCaughtAgain,  gText_DragonairAfterTreasure,  gText_DragonairCaughtAgainNoTreasure }
};

static const u8 sSpeciesToTreasureEnum[] =
{
    [SPECIES_MAGIKARP]   = TT_MAGIKARP,
    [SPECIES_KRABBY]     = TT_KRABBY,
    [SPECIES_ARROKUDA]   = TT_ARROKUDA,
    [SPECIES_GYARADOS]   = TT_GYARADOS,
    [SPECIES_OCTILLERY]  = TT_OCTILLERY,
    [SPECIES_SKRELP]     = TT_SKRELP,
    [SPECIES_BRUXISH]    = TT_BRUXISH,
    [SPECIES_TENTACRUEL] = TT_TENTACRUEL,
    [SPECIES_WAILMER]    = TT_WAILMER,
    [SPECIES_WOOPER]     = TT_WOOPER,
    [SPECIES_BARBOACH]   = TT_BARBOACH,
    [SPECIES_CARVANHA]   = TT_CARVANHA,
    [SPECIES_AZUMARILL]  = TT_AZUMARILL,
    [SPECIES_LUVDISC]    = TT_LUVDISC,
    [SPECIES_FINIZEN]    = TT_FINIZEN,
    [SPECIES_CRAMORANT]  = TT_CRAMORANT,
    [SPECIES_DONDOZO]    = TT_DONDOZO,
    [SPECIES_STARYU]     = TT_STARYU,
    [SPECIES_SHELLDER]   = TT_SHELLDER,
    [SPECIES_LUMINEON]   = TT_LUMINEON,
    [SPECIES_DRAGONAIR]  = TT_DRAGONAIR,
    [SPECIES_MURKROW]    = TT_MURKROW,
    [SPECIES_KYOGRE]     = TT_KYOGRE,
};

u32 GetTreasureSpeciesFromSpecies(void)
{
    return sSpeciesToTreasureEnum[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)];
}

#define taskData            gTasks[taskId]
#define tState              data[0]
#define tCounter            data[1]
#define tMugFrameId         data[2]
#define tMugshotId          data[3]
#define tSpecies            data[4]
#define tObjId              data[5]

static void HideMugshot(u8 taskId)
{
    gSprites[taskData.tMugFrameId].invisible = TRUE;
    gSprites[taskData.tMugshotId].invisible = TRUE;
}

static void ShowMugshot(u8 taskId)
{
    gSprites[taskData.tMugFrameId].invisible = FALSE;
    gSprites[taskData.tMugshotId].invisible = FALSE;
}

enum AfterCaughtTaskStates
{
    STATE_WAIT_START,
    STATE_CREATE_MUGSHOT_DIALOGUE_BOX,
    STATE_FIRST_DIALOGUE,
    STATE_CLEAR_DIALOGUE_1,
    STATE_GOT_TREASURE,
    STATE_CLEAR_DIALOGUE_2,
    STATE_DIALOGUE_AFTER_TREASURE,
    STATE_MON_START_LEAVE,
    STATE_MON_LEAVE_SPLASH,
    STATE_FINISH
};

static const u8 sSpeciesTreasureCounts[] =
{
    [TT_MAGIKARP]   = 50,
    [TT_KRABBY]     = 30,
    [TT_ARROKUDA]   = 20,
    [TT_GYARADOS]   = 10,
    [TT_OCTILLERY]  = 10,
    [TT_SKRELP]     = 30,
    [TT_BRUXISH]    = 20,
    [TT_TENTACRUEL] = 10,
    [TT_WAILMER]    = 10,
    [TT_WOOPER]     = 30,
    [TT_BARBOACH]   = 20,
    [TT_CARVANHA]   = 10,
    [TT_AZUMARILL]  = 10,
    [TT_LUVDISC]    = 30,
    [TT_FINIZEN]    = 20,
    [TT_CRAMORANT]  = 10,
    [TT_DONDOZO]    = 10,
    [TT_STARYU]     = 30,
    [TT_SHELLDER]   = 20,
    [TT_LUMINEON]   = 10,
    [TT_DRAGONAIR]  = 10,
};

void Task_AfterCaught(u8 taskId)
{
    switch (taskData.tState)
    {
    case STATE_WAIT_START:
        if (taskData.tCounter >= 60)
            taskData.tState = STATE_CREATE_MUGSHOT_DIALOGUE_BOX;

        taskData.tCounter++;
        break;
    case STATE_CREATE_MUGSHOT_DIALOGUE_BOX:
        taskData.tSpecies = sSpeciesToTreasureEnum[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)];
        LoadMessageBoxAndFrameGfx(0, TRUE);
        LoadCompressedSpriteSheet(&sSpriteSheet_MugshotFrame);
        LoadSpritePalette(&sSpritePalette_MugshotFrame);
        taskData.tMugFrameId = CreateSprite(&sSpriteTemplate_MugshotFrame, 35, 102, 0);
        LoadCompressedSpriteSheet(&sSpriteSheets_Mugshots[taskData.tSpecies]);
        LoadSpritePalette(&sSpritePalettes_Mugshots[taskData.tSpecies]);
        taskData.tMugshotId = CreateSprite(&sSpriteTemplate_Mugshot, 35, 102, 1);
        taskData.tState = STATE_FIRST_DIALOGUE;
        break;
    case STATE_FIRST_DIALOGUE:
        if (FlagGet(FLAG_MAGIKARP_FIRST + taskData.tSpecies))
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            if (gSaveBlock3Ptr->trove.speciesTreasureCounts[taskData.tSpecies] < sSpeciesTreasureCounts[taskData.tSpecies])
            {
                AddTextPrinterParameterized(0, FONT_NORMAL, sTreasureText[taskData.tSpecies][1], 0, 1, 1, NULL);
                taskData.tState = STATE_CLEAR_DIALOGUE_1;
            }
            else
            {
                AddTextPrinterParameterized(0, FONT_NORMAL, sTreasureText[taskData.tSpecies][3], 0, 1, 1, NULL);
                taskData.tState = STATE_MON_START_LEAVE;
            }
        }
        else
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NORMAL, sTreasureText[taskData.tSpecies][0], 0, 1, 1, NULL);
            FlagSet(FLAG_MAGIKARP_FIRST + taskData.tSpecies);
            taskData.tState = STATE_CLEAR_DIALOGUE_1;
        }
        break;
    case STATE_CLEAR_DIALOGUE_1:
        if (!IsTextPrinterActiveOnWindow(0))
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_EmptyString2, 0, 1, 0, NULL);
            RunTextPrinters();
            HideMugshot(taskId);
            HideBg(0);
            taskData.tCounter = 0;
            taskData.tState = STATE_GOT_TREASURE;
            return;
        }

        RunTextPrinters();
        break;
    case STATE_GOT_TREASURE:
        if (taskData.tCounter == 30)
        {
            ShowBg(0);
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_GotPieceOfTreasure, 0, 1, 1, NULL);
            PlayFanfare(MUS_OBTAIN_ITEM);
            gSaveBlock3Ptr->trove.speciesTreasureCounts[taskData.tSpecies]++;
            taskData.tState = STATE_CLEAR_DIALOGUE_2;
            return;
        }

        taskData.tCounter++;
        break;
    case STATE_CLEAR_DIALOGUE_2:
        if (IsFanfareTaskInactive() && JOY_NEW(A_BUTTON | B_BUTTON))
        {
            PlaySE(SE_SELECT);
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized(0, FONT_NORMAL, gText_EmptyString2, 0, 1, 0, NULL);
            RunTextPrinters();
            HideBg(0);
            taskData.tCounter = 0;
            taskData.tState = STATE_DIALOGUE_AFTER_TREASURE;
            return;
        }

        RunTextPrinters();
        break;
    case STATE_DIALOGUE_AFTER_TREASURE:
        if (taskData.tCounter == 30)
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            ShowBg(0);
            ShowMugshot(taskId);
            AddTextPrinterParameterized(0, FONT_NORMAL, sTreasureText[taskData.tSpecies][2], 0, 1, 1, NULL);
            taskData.tState = STATE_MON_START_LEAVE;
            return;
        }

        taskData.tCounter++;
        break;
    case STATE_MON_START_LEAVE:
        if (!IsTextPrinterActiveOnWindow(0))
        {
            struct ObjectEvent *obj = &gObjectEvents[GetObjectEventIdByLocalId(OBJ_EVENT_ID_FOLLOWER)];

            EraseFieldMessageBox(TRUE);
            DestroySpriteAndFreeResources(&gSprites[taskData.tMugFrameId]);
            DestroySpriteAndFreeResources(&gSprites[taskData.tMugshotId]);
            ObjectEventSetHeldMovement(obj, GetJumpInPlaceMovementAction(obj->facingDirection));
            taskData.tState = STATE_MON_LEAVE_SPLASH;
        }

        RunTextPrinters();
        break;
    case STATE_MON_LEAVE_SPLASH:
        struct ObjectEvent *obj = &gObjectEvents[GetObjectEventIdByLocalId(OBJ_EVENT_ID_FOLLOWER)];

        if (ObjectEventClearHeldMovementIfFinished(obj))
        {
            PlaySE(SE_M_DIVE);
            gFieldEffectArguments[0] = obj->currentCoords.x;
            gFieldEffectArguments[1] = obj->currentCoords.y;
            gFieldEffectArguments[2] = 3; // Elevation.
            gFieldEffectArguments[3] = 1; // Priority.
            FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
            RemoveObjectEvent(obj);
            taskData.tCounter = 0;
            taskData.tState = STATE_FINISH;
        }
        break;
    case STATE_FINISH:
        if (taskData.tCounter == 30)
        {
            if (!FlagGet(FLAG_GOT_ITEM_BOX))
            {
                gPlayerAvatar.preventStep = FALSE;
                UnlockPlayerFieldControls();
                UnfreezeObjectEvents();
                DestroyTask(taskId);
            }
            else
            {
                taskData.data[1] = 0; 
                taskData.func = Task_DoReturnToFieldFishTreasure;
            }
            return;
        }

        taskData.tCounter++;
        break;
    }
}
