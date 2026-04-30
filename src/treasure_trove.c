#include "global.h"
#include "treasure_trove.h"
#include "decompress.h"
#include "event_data.h"
#include "fishing_game.h"
#include "main.h"
#include "menu.h"
#include "task.h"
#include "text.h"
#include "text_window.h"

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

/*
static void (*const sFishAfterCaught[])(u8) = {
    [SPECIES_MAGIKARP] =    Task_AfterCaught,
};

static const u8 *const sPyramidFloorNames[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    gText_Floor1,
    gText_Floor2,
    gText_Floor3,
    gText_Floor4,
    gText_Floor5,
    gText_Floor6,
    gText_Floor7,
    gText_Peak
};
*/

static const u8 gText_MagikarpFirst[] = _("Karp!\nWhat do you want?\pA piece of treasure?\nI did find something shiny earlier.\pHere.\nYou can have it.");

static const u8 *const sFirstCaughtText1[] =
{

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

#define taskData            gTasks[taskId]
#define tState              data[0]
#define tCounter            data[1]
#define tMugFrameId         data[2]
#define tMugshotId          data[3]
#define tSpecies            data[4]
#define TaskSpecies             data[5]

void Task_AfterCaught(u8 taskId)
{
    switch (taskData.tState)
    {
    case 0:
        if (taskData.tCounter >= 60)
            taskData.tState++;

        taskData.tCounter++;
        break;
    case 1:
        taskData.tSpecies = sSpeciesToTreasureEnum[GetMonData(&gEnemyParty[0], MON_DATA_SPECIES)];
        LoadMessageBoxAndFrameGfx(0, TRUE);
        LoadCompressedSpriteSheet(&sSpriteSheet_MugshotFrame);
        LoadSpritePalette(&sSpritePalette_MugshotFrame);
        taskData.tMugFrameId = CreateSprite(&sSpriteTemplate_MugshotFrame, 35, 102, 0);
        LoadCompressedSpriteSheet(&sSpriteSheets_Mugshots[taskData.tSpecies]);
        LoadSpritePalette(&sSpritePalettes_Mugshots[taskData.tSpecies]);
        taskData.tMugshotId = CreateSprite(&sSpriteTemplate_Mugshot, 35, 102, 1);
        taskData.tState++;
        break;
    case 2:
        if (FlagGet(FLAG_MAGIKARP_FIRST + taskData.tSpecies))
        {

        }
        else
        {
            FlagSet(FLAG_MAGIKARP_FIRST + taskData.tSpecies);
        }
        break;
    }
}
