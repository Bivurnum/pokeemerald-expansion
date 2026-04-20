#include "global.h"
#include "amie_refresh.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeblock.h"
#include "pokedex.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

EWRAM_DATA struct AmieData *gAmieData = NULL;

static const u32 gAmieBG_Gfx[] = INCBIN_U32("graphics/amie_refresh/amie/amie_bg.4bpp.smol");
static const u32 gAmieBG_Tilemap[] = INCBIN_U32("graphics/amie_refresh/amie/amie_bg.bin.smolTM");
static const u16 gAmieBG_Pal[] = INCBIN_U16("graphics/amie_refresh/amie/amie_bg.gbapal");

static const u32 gPokeblockBarBG_Gfx[] = INCBIN_U32("graphics/amie_refresh/amie/pokeblock_bar.4bpp.smol");
static const u32 gPokeblockBarBG_Tilemap[] = INCBIN_U32("graphics/amie_refresh/amie/pokeblock_bar.bin.smolTM");
static const u16 gPokeblockBarBG_Pal[] = INCBIN_U16("graphics/amie_refresh/amie/pokeblock_bar.gbapal");

static const u16 gHand_Pal[] = INCBIN_U16("graphics/amie_refresh/hand.gbapal");
static const u32 gHand_Gfx[] = INCBIN_U32("graphics/amie_refresh/hand.4bpp");
static const u32 gSpeechBubble_Gfx[] = INCBIN_U32("graphics/amie_refresh/speech_bubble.4bpp");

static const u16 gPokeblock_Icon_Pal[] = INCBIN_U16("graphics/amie_refresh/amie/pokeblock_icon.gbapal");
static const u32 gPokeblock_Icon_Gfx[] = INCBIN_U32("graphics/amie_refresh/amie/pokeblock_icon.4bpp");

static const u16 gSwitch_Icon_Pal[] = INCBIN_U16("graphics/amie_refresh/amie/switch.gbapal");
static const u32 gSwitch_Icon_Gfx[] = INCBIN_U32("graphics/amie_refresh/amie/switch.4bpp");

static const u16 gEmotes_Pal[] = INCBIN_U16("graphics/amie_refresh/heart.gbapal");
static const u32 gHeart_Gfx[] = INCBIN_U32("graphics/amie_refresh/heart.4bpp");
static const u32 gAngry_Gfx[] = INCBIN_U32("graphics/amie_refresh/angry.4bpp");
static const u32 sSpriteTiles_Surprised[] = INCBIN_U32("graphics/amie_refresh/surprised.4bpp.smol");
static const u32 sSpriteTiles_Music[] = INCBIN_U32("graphics/amie_refresh/music.4bpp.smol");
static const u32 sSpriteTiles_Pokeblock[] = INCBIN_U32("graphics/amie_refresh/amie/pokeblock.4bpp.smol");

static const u16 gParty_Icon_Pal[] = INCBIN_U16("graphics/amie_refresh/party_icon.gbapal");
static const u32 sSpriteTiles_Party_Icon[] = INCBIN_U32("graphics/amie_refresh/party_icon.4bpp.smol");

static void CreateAmieSprites(void);
static void Task_AmieFadeIn(u8 taskId);
static void Task_AmieMain(u8 taskId);
static void Task_TurnMonAroundWaitSurprisedEmote(u8 taskId);
static void Task_TurnMonAroundWaitFadeOut(u8 taskId);
static void Task_TurnMonAroundWaitFadeIn(u8 taskId);
static void CreateMusicEmote(void);
static void StartNormalAnim(void);
static void StartHappyAnim(void);
static void ResetAmieHand(void);
static void AmieHandHandleInput(u8 taskId);
static void DestroyPokeblockSprites(void);
static void SpriteCB_Mon(struct Sprite *sprite);
static void SpriteCB_MonBack(struct Sprite *sprite);
static void SpriteCB_Heart(struct Sprite *sprite);
static void SpriteCB_Angry(struct Sprite *sprite);
static void SpriteCB_SpeechBubble(struct Sprite *sprite);

// Task Data
#define tState      gTasks[taskId].data[0]
#define tCounter    gTasks[taskId].data[1]
#define tPetScore   gTasks[taskId].data[2]
#define tPetZone    gTasks[taskId].data[3]
#define tTapCounter gTasks[taskId].data[3]
#define tSECounter  gTasks[taskId].data[4]
#define tSpecies    gTasks[taskId].data[5]

// Sprite Data
#define sCounter        data[1]
#define sCurrAnim       data[2]
#define sLastAnim       data[3]
#define sHeartOffset    data[2]
#define sPkblkNum       data[2]

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
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
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

static const union AnimCmd sAnim_HandTap[] =
{
    ANIMCMD_FRAME(.imageValue = 2, .duration = 12),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 1),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Hand[] =
{
    sAnim_Normal,
    sAnim_HandOpen,
    sAnim_HandTap,
};

static const union AnimCmd * const sAnims_SpeechBubble[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_Pokeblock_Icon[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_Switch_Icon[] =
{
    sAnim_Normal,
};

static const union AnimCmd sAnim_Mon_Happy[] =
{
    ANIMCMD_FRAME(.imageValue = 0, .duration = 6),
    ANIMCMD_FRAME(.imageValue = 1, .duration = 16),
    ANIMCMD_FRAME(.imageValue = 0, .duration = 60),
    ANIMCMD_END
};

static const union AnimCmd * const sAnims_Mon[] =
{
    sAnim_Normal,
    sAnim_Mon_Happy,
};

static const union AffineAnimCmd sAffineAnim_MonDoubleSize[] =
{
    AFFINEANIMCMD_FRAME(512, 512, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_MonJump[] =
{
    AFFINEANIMCMD_FRAME(512, 512, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -1, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, 1, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, 0, 1, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 4),
    AFFINEANIMCMD_FRAME(0, 0, -1, 1),
    AFFINEANIMCMD_FRAME(0, 0, 0, 32),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Mon[] =
{
    sAffineAnim_MonDoubleSize,
    sAffineAnim_MonJump,
};

static const struct SpriteFrameImage sPicTable_Hand[] =
{
    amie_frame(gHand_Gfx, 0, 4, 4),
    amie_frame(gHand_Gfx, 1, 4, 4),
    amie_frame(gHand_Gfx, 2, 4, 4),
};

static const struct SpriteFrameImage sPicTable_SpeechBubble[] =
{
    amie_frame(gSpeechBubble_Gfx, 0, 4, 4),
};

static const union AnimCmd * const sAnims_Heart[] =
{
    sAnim_Normal,
};

static const union AnimCmd * const sAnims_Angry[] =
{
    sAnim_Normal,
};

static const union AffineAnimCmd sAffineAnim_AngryPulse[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_FRAME(-4, -4, 0, 16),
    AFFINEANIMCMD_FRAME(4, 4, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -4, 0, 16),
    AFFINEANIMCMD_FRAME(4, 4, 0, 16),
    AFFINEANIMCMD_FRAME(-4, -4, 0, 16),
    AFFINEANIMCMD_FRAME(4, 4, 0, 16),
    AFFINEANIMCMD_FRAME(0, 0, 0, 23),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Angry[] =
{
    sAffineAnim_AngryPulse,
};

static const union AffineAnimCmd sAffineAnim_PokeblockShake[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 1, 5),
    AFFINEANIMCMD_FRAME(0, 0, -1, 10),
    AFFINEANIMCMD_FRAME(0, 0, 1, 5),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Pokeblock[] =
{
    sAffineAnim_PokeblockShake,
};

static const struct SpriteFrameImage sPicTable_Pokeblock_Icon[] =
{
    amie_frame(gPokeblock_Icon_Gfx, 0, 8, 4),
};

static const struct SpriteFrameImage sPicTable_Switch_Icon[] =
{
    amie_frame(gSwitch_Icon_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Heart[] =
{
    amie_frame(gHeart_Gfx, 0, 4, 4),
};

static const struct SpriteFrameImage sPicTable_Angry[] =
{
    amie_frame(gAngry_Gfx, 0, 4, 4),
};

static const struct OamData sOam_32x32_1 =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct OamData sOam_32x32_2 =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const struct OamData sOam_32x32Affine_1 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct OamData sOam_32x32Affine_2 =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const struct OamData sOam_64x32_2 =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_Surprised =
{
    .data = sSpriteTiles_Surprised,
    .size = 512,
    .tag = TAG_SURPRISED,
};

static const struct CompressedSpriteSheet sSpriteSheet_Music =
{
    .data = sSpriteTiles_Music,
    .size = 512,
    .tag = TAG_MUSIC,
};

static const struct CompressedSpriteSheet sSpriteSheet_Party_Icon =
{
    .data = sSpriteTiles_Party_Icon,
    .size = 1024,
    .tag = TAG_PARTY_AMIE,
};

static const struct CompressedSpriteSheet sSpriteSheet_Pokeblock =
{
    .data = sSpriteTiles_Pokeblock,
    .size = 512,
    .tag = TAG_AMIE_POKEBLOCK,
};

static const struct SpriteTemplate sSpriteTemplate_Hand =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32_1,
    .anims = sAnims_Hand,
    .images = sPicTable_Hand,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_SpeechBubble =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32_1,
    .anims = sAnims_SpeechBubble,
    .images = sPicTable_SpeechBubble,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_SpeechBubble
};

static const struct SpriteTemplate sSpriteTemplate_Pokeblock_Icon =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_PKBL_ICON,
    .oam = &sOam_64x32_2,
    .anims = sAnims_Pokeblock_Icon,
    .images = sPicTable_Pokeblock_Icon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Switch_Icon =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_SWITCH_ICON,
    .oam = &sOam_32x32_2,
    .anims = sAnims_Switch_Icon,
    .images = sPicTable_Switch_Icon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Heart =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_EMOTE,
    .oam = &sOam_32x32_1,
    .anims = sAnims_Heart,
    .images = sPicTable_Heart,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Heart
};

static const struct SpriteTemplate sSpriteTemplate_Angry =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_EMOTE,
    .oam = &sOam_32x32Affine_1,
    .anims = sAnims_Angry,
    .images = sPicTable_Angry,
    .affineAnims = sAffineAnims_Angry,
    .callback = SpriteCB_Angry
};

static const struct SpriteTemplate sSpriteTemplate_Surprised =
{
    .tileTag = TAG_SURPRISED,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32_1,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Music =
{
    .tileTag = TAG_MUSIC,
    .paletteTag = TAG_HAND,
    .oam = &sOam_32x32_1,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_Party_Icon =
{
    .tileTag = TAG_PARTY_AMIE,
    .paletteTag = TAG_PARTY_AMIE,
    .oam = &sOam_64x32_2,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpritePalette sSpritePalettes_Amie[] =
{
    {
        .data = gHand_Pal,
        .tag = TAG_HAND
    },
    {
        .data = gPokeblock_Icon_Pal,
        .tag = TAG_PKBL_ICON
    },
    {
        .data = gSwitch_Icon_Pal,
        .tag = TAG_SWITCH_ICON
    },
    {
        .data = gEmotes_Pal,
        .tag = TAG_EMOTE
    },
    {NULL},
};

void LoadAmiePartyMenuSprite(void)
{
    LoadSpritePaletteWithTag(gParty_Icon_Pal, TAG_PARTY_AMIE);
    LoadCompressedSpriteSheet(&sSpriteSheet_Party_Icon);
    CreateSprite(&sSpriteTemplate_Party_Icon, 47, 114, 0);
}

static void SetAmieMonData(u32 *species, u32 *isShiny, u32 *personality)
{
    gAmieData->partySlot = gSpecialVar_0x8004;

    *species = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES_OR_EGG);
    *isShiny = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_IS_SHINY);
    *personality = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_PERSONALITY);
}

static void CB2_Amie(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Amie(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void CB2_InitAmie(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sWindowTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        DecompressDataWithHeaderVram(gAmieBG_Gfx, (void *)(BG_CHAR_ADDR(1)));
        DecompressDataWithHeaderVram(gAmieBG_Tilemap, (u16*) BG_SCREEN_ADDR(6));

        DecompressDataWithHeaderVram(gPokeblockBarBG_Gfx, (void *)(BG_CHAR_ADDR(0)));
        DecompressDataWithHeaderVram(gPokeblockBarBG_Tilemap, (u16*) BG_SCREEN_ADDR(7));
        gMain.state++;
        break;
    case 4:
        LoadPalette(gAmieBG_Pal, BG_PLTT_ID(0), 5 * PLTT_SIZE_4BPP);
        LoadPalette(gPokeblockBarBG_Pal, BG_PLTT_ID(5), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        gAmieData = AllocZeroed(sizeof(struct AmieData));
        if (gAmieData == NULL)
        {
            SetMainCallback2(CB2_PartyMenuFromStartMenu);
            return;
        }
        ShowBg(0);
        ShowBg(3);
        gMain.state++;
        break;
    case 6:
        LoadSpritePalettes(sSpritePalettes_Amie);
        CreateAmieSprites();
        gMain.state++;
        break;
    case 7:
        u32 species = 0, isShiny = 0, personality = 0;

        SetAmieMonData(&species, &isShiny, &personality);
        
        // Create Pokémon sprite
        gAmieData->monSpriteId = CreateMonPicSprite_Affine(species, isShiny, personality, MON_PIC_AFFINE_FRONT, 90, 65, 0, TAG_MON);
        gSprites[gAmieData->monSpriteId].affineAnims = sAffineAnims_Mon;
        gSprites[gAmieData->monSpriteId].anims = sAnims_Mon;
        gSprites[gAmieData->monSpriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        gSprites[gAmieData->monSpriteId].oam.priority = 1;
        gSprites[gAmieData->monSpriteId].subpriority = 3;
        gSprites[gAmieData->monSpriteId].callback = SpriteCB_Mon;
        StartSpriteAffineAnim(&gSprites[gAmieData->monSpriteId], 0);

        if (Random() % 100 < AR_FACE_AWAY_CHANCE)
        {
            gSprites[gAmieData->monSpriteId].invisible = TRUE;
            gAmieData->monBackSpriteId = CreateMonPicSprite_Affine(species, isShiny, personality, MON_PIC_AFFINE_BACK, 90, 85, 0, TAG_MON);
            gSprites[gAmieData->monBackSpriteId].affineAnims = sAffineAnims_Mon;
            gSprites[gAmieData->monBackSpriteId].anims = sAnims_Mon;
            gSprites[gAmieData->monBackSpriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            gSprites[gAmieData->monBackSpriteId].oam.priority = 1;
            gSprites[gAmieData->monBackSpriteId].subpriority = 3;
            gSprites[gAmieData->monBackSpriteId].callback = SpriteCB_MonBack;
            StartSpriteAffineAnim(&gSprites[gAmieData->monBackSpriteId], 0);
        }
        gMain.state++;
        break;
    case 8:
        u32 taskId;

        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        taskId = CreateTask(Task_AmieFadeIn, 0);
        if (gAmieData->monBackSpriteId)
            tState = AMIE_TASK_BACK;
            
        SetVBlankCallback(VBlankCB_Amie);
        SetMainCallback2(CB2_Amie);
        break;
    }
}

static void CreateAmieSprites(void)
{
    gAmieData->handSpriteId = CreateSprite(&sSpriteTemplate_Hand, HAND_START_X, HAND_START_Y, 1);
    gAmieData->pokeblockIconSpriteId = CreateSprite(&sSpriteTemplate_Pokeblock_Icon, 31, 16, 2);
}

static void Task_AmieFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_AmieMain;
}

static void Task_AmieMain(u8 taskId)
{
    switch (tState)
    {
    case AMIE_TASK_NORMAL:
        if (gAmieData->controlsPaused)
        {
            if (gSprites[gAmieData->monSpriteId].animEnded)
            {
                if (gAmieData->emoteSpriteId)
                {
                    DestroySprite(&gSprites[gAmieData->emoteSpriteId]);
                    gAmieData->emoteSpriteId = 0;
                }
                if (gAmieData->emoteBubbleSpriteId)
                {
                    DestroySprite(&gSprites[gAmieData->emoteBubbleSpriteId]);
                    gAmieData->emoteBubbleSpriteId = 0;
                }
                gAmieData->controlsPaused = FALSE;
                gSprites[gAmieData->handSpriteId].invisible = FALSE;
                StartNormalAnim();
                ResetAmieHand();
            }
            return;
        }
        else if (gSprites[gAmieData->handSpriteId].invisible)
        {
            return;
        }

        AmieHandHandleInput(taskId);
        break;
    case AMIE_TASK_BACK:
        AmieHandHandleInput(taskId);
        break;
    case AMIE_TASK_PUFF:
        if (JOY_NEW(B_BUTTON | L_BUTTON))
        {
            PlaySE(SE_WIN_OPEN);
            HideBg(2);
            DestroyPokeblockSprites();
            StartNormalAnim();
            ResetAmieHand();
            tState = AMIE_TASK_NORMAL;
            return;
        }
        break;
    }
}

static void Task_TurnMonAroundWaitSurprisedEmote(u8 taskId)
{
    if (tCounter > 0 && gSprites[gAmieData->handSpriteId].animEnded)
        gSprites[gAmieData->handSpriteId].invisible = TRUE;

    if (tCounter == 60)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 16, RGB_WHITE);
        gTasks[taskId].func = Task_TurnMonAroundWaitFadeOut;
    }
    tCounter++;
}

static void Task_TurnMonAroundWaitFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSprites[gAmieData->monSpriteId].invisible = FALSE;
        DestroySprite(&gSprites[gAmieData->monBackSpriteId]);
        gAmieData->monBackSpriteId = 0;
        DestroySpriteAndFreeResources(&gSprites[gAmieData->emoteBubbleSpriteId]);
        gAmieData->emoteBubbleSpriteId = 0;
        DestroySpriteAndFreeResources(&gSprites[gAmieData->emoteSpriteId]);
        gAmieData->emoteSpriteId = 0;
        BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_WHITE);
        gTasks[taskId].func = Task_TurnMonAroundWaitFadeIn;
    }
}

static void Task_TurnMonAroundWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CreateMusicEmote();
        StartHappyAnim();
        PlayCry_ByMode(GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES), 0, CRY_MODE_GROWL_2);
        gTasks[taskId].func = Task_AmieMain;
    }
}

static void Task_AmieEndFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gAmieData->monBackSpriteId)
        {
            FreeAndDestroyMonPicSprite(gAmieData->monBackSpriteId);
            gAmieData->monBackSpriteId = 0;
        }
        FreeAndDestroyMonPicSprite(gAmieData->monSpriteId);
        Free(gAmieData);
        SetMainCallback2(CB2_PartyMenuFromStartMenu);
        DestroyTask(taskId);
    }
}

static bool32 IsHandOnPokeblockIcon(void)
{
    if (gSprites[gAmieData->handSpriteId].x < 45 && gSprites[gAmieData->handSpriteId].y < 38)
        return TRUE;

    return FALSE;
}

static void MoveSpriteFromInput(struct Sprite *sprite)
{
    if (JOY_HELD(DPAD_DOWN))
    {
        if (sprite == &gSprites[gAmieData->handSpriteId] && sprite->animNum != 1)
            sprite->y++;

        sprite->y += AMIE_MOVE_SPEED;
        if (sprite->y > 160)
            sprite->y = 160;
    }
    if (JOY_HELD(DPAD_UP))
    {
        if (sprite == &gSprites[gAmieData->handSpriteId] && sprite->animNum != 1)
            sprite->y--;

        sprite->y -= AMIE_MOVE_SPEED;
        if (sprite->y < 9)
            sprite->y = 9;
    }
    if (JOY_HELD(DPAD_RIGHT))
    {
        if (sprite == &gSprites[gAmieData->handSpriteId] && sprite->animNum != 1)
            sprite->x++;

        sprite->x += AMIE_MOVE_SPEED;
        if (sprite->x > 245)
            sprite->x = 245;
    }
    if (JOY_HELD(DPAD_LEFT))
    {
        if (sprite == &gSprites[gAmieData->handSpriteId] && sprite->animNum != 1)
            sprite->x--;

        sprite->x -= AMIE_MOVE_SPEED;
        if (sprite->x < 10)
            sprite->x = 10;
    }
}

static u8 GetCurrentPettingArea(void)
{
    u32 i;
    u32 species = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES);
    struct Sprite *hand = &gSprites[gAmieData->handSpriteId];

    for (i = 0; i < NUM_AMIE_PET_AREAS; i++)
    {
        if (i == 0 && AmieRefreshPetZones[gSpeciesInfo[species].amiePetZone][i].type == PET_TYPE_NONE)
        {
            u32 size;

            #if P_GENDER_DIFFERENCES
            if (gSpeciesInfo[species].frontPicFemale != NULL && GetGenderFromSpeciesAndPersonality(species, GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_PERSONALITY)) == MON_FEMALE)
                size = gSpeciesInfo[species].frontPicSizeFemale;
            else
            #endif
            size = gSpeciesInfo[species].frontPicSize;

            if (hand->x > (gSprites[gAmieData->monSpriteId].x - 32 + HAND_OFFSET + (64 - GET_MON_COORDS_WIDTH(size))) && hand->x < (gSprites[gAmieData->monSpriteId].x + 96 - (64 - GET_MON_COORDS_WIDTH(size))))
                if (hand->y > (gSprites[gAmieData->monSpriteId].y - 32 + HAND_OFFSET + (64 - GET_MON_COORDS_HEIGHT(size))) && hand->y < (gSprites[gAmieData->monSpriteId].y + 96 - (64 - GET_MON_COORDS_HEIGHT(size))))
                    return PET_TYPE_GOOD;
        }
        else if (hand->x > AmieRefreshPetZones[gSpeciesInfo[species].amiePetZone][i].leftX && hand->x < AmieRefreshPetZones[gSpeciesInfo[species].amiePetZone][i].rightX)
        {
            if (hand->y > AmieRefreshPetZones[gSpeciesInfo[species].amiePetZone][i].topY && hand->y < AmieRefreshPetZones[gSpeciesInfo[species].amiePetZone][i].bottomY)
                return AmieRefreshPetZones[gSpeciesInfo[species].amiePetZone][i].type;
        }
    }

    return PET_TYPE_NONE;
}

static const s16 HeartPos[5][2] =
{
    { 110, 40 },
    { 130, 35 },
    { 150, 45 },
    { 120, 55 },
    { 140, 57 },
};

static void CreateHeartSprites(u32 num)
{
    u32 i, spriteId;

    if (num > 5)
        num = 5;

    for (i = 0; i < num; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Heart, HeartPos[i][0], HeartPos[i][1], 0);
        gSprites[spriteId].sHeartOffset = Random() % 120;
        gSprites[spriteId].sCounter = gSprites[spriteId].sHeartOffset;
    }

}

static void CreateAngrySprite(void)
{
    u32 size;
    u32 spriteId;
    u32 species = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES);

    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].frontPicFemale != NULL && GetGenderFromSpeciesAndPersonality(species, GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_PERSONALITY)) == MON_FEMALE)
            size = gSpeciesInfo[species].frontPicSizeFemale;
        else
    #endif
            size = gSpeciesInfo[species].frontPicSize;
    
    spriteId = CreateSprite(&sSpriteTemplate_Angry, 55 + (64 - GET_MON_COORDS_WIDTH(size)), 50 + (64 - GET_MON_COORDS_HEIGHT(size)), 0);
    gSprites[gAmieData->emoteSpriteId].oam.priority = 0;
    StartSpriteAffineAnim(&gSprites[spriteId], 0);
    gAmieData->emoteBubbleSpriteId = CreateSprite(&sSpriteTemplate_SpeechBubble, 55 + (64 - GET_MON_COORDS_WIDTH(size)), 50 + (64 - GET_MON_COORDS_HEIGHT(size)), 1);
    gSprites[gAmieData->emoteBubbleSpriteId].oam.priority = 0;
}

static void CreateSurprisedEmote(void)
{
    u32 size;
    u32 species = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES);

    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].frontPicFemale != NULL && GetGenderFromSpeciesAndPersonality(species, GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_PERSONALITY)) == MON_FEMALE)
            size = gSpeciesInfo[species].frontPicSizeFemale;
        else
    #endif
            size = gSpeciesInfo[species].frontPicSize;
    
    LoadCompressedSpriteSheet(&sSpriteSheet_Surprised);
    gAmieData->emoteSpriteId = CreateSprite(&sSpriteTemplate_Surprised, 55 + (64 - GET_MON_COORDS_WIDTH(size)), 50 + (64 - GET_MON_COORDS_HEIGHT(size)), 0);
    gSprites[gAmieData->emoteSpriteId].oam.priority = 0;
    gAmieData->emoteBubbleSpriteId = CreateSprite(&sSpriteTemplate_SpeechBubble, 55 + (64 - GET_MON_COORDS_WIDTH(size)), 50 + (64 - GET_MON_COORDS_HEIGHT(size)), 1);
    gSprites[gAmieData->emoteBubbleSpriteId].oam.priority = 0;
}

static void CreateMusicEmote(void)
{
    u32 size;
    u32 species = GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES);

    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].frontPicFemale != NULL && GetGenderFromSpeciesAndPersonality(species, GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_PERSONALITY)) == MON_FEMALE)
            size = gSpeciesInfo[species].frontPicSizeFemale;
        else
    #endif
            size = gSpeciesInfo[species].frontPicSize;
    
    LoadCompressedSpriteSheet(&sSpriteSheet_Music);
    gAmieData->emoteSpriteId = CreateSprite(&sSpriteTemplate_Music, 55 + (64 - GET_MON_COORDS_WIDTH(size)), 50 + (64 - GET_MON_COORDS_HEIGHT(size)), 0);
    gSprites[gAmieData->emoteSpriteId].oam.priority = 0;
    gAmieData->emoteBubbleSpriteId = CreateSprite(&sSpriteTemplate_SpeechBubble, 55 + (64 - GET_MON_COORDS_WIDTH(size)), 50 + (64 - GET_MON_COORDS_HEIGHT(size)), 1);
    gSprites[gAmieData->emoteBubbleSpriteId].oam.priority = 0;
}

static void StartNormalAnim(void)
{
    gSprites[gAmieData->monSpriteId].sCurrAnim = 0;
    gSprites[gAmieData->monSpriteId].sCounter = 0;
    StartSpriteAnim(&gSprites[gAmieData->monSpriteId], 0);
    StartSpriteAffineAnim(&gSprites[gAmieData->monSpriteId], 0);
}

static void StartHappyAnim(void)
{
    gSprites[gAmieData->monSpriteId].sCurrAnim = 1;
    gSprites[gAmieData->monSpriteId].sCounter = 0;
    StartSpriteAnim(&gSprites[gAmieData->monSpriteId], 1);
    StartSpriteAffineAnim(&gSprites[gAmieData->monSpriteId], 1);
    gAmieData->controlsPaused = TRUE;
}

static void StartAngryAnim(void)
{
    gSprites[gAmieData->monSpriteId].sCurrAnim = 2;
    gSprites[gAmieData->monSpriteId].sCounter = 0;
}

static void StopPetting(u8 taskId)
{
    if (tPetZone != PET_TYPE_NONE)
    {
        tPetZone = PET_TYPE_NONE;
        StartNormalAnim();
    }
}

static void ResetAmieHand(void)
{
    gSprites[gAmieData->handSpriteId].x = HAND_START_X;
    gSprites[gAmieData->handSpriteId].y = HAND_START_Y;
    gSprites[gAmieData->handSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[gAmieData->handSpriteId], 0);
}

static const s16 sPokeblockPositionsX[NUM_DISPLAYED_PKBL] =
{
    50, 82, 114, 146, 178, 210
};

static void CreatePokeblockSprites(void)
{
    u32 color, palTag, count = 0;

    LoadCompressedSpriteSheet(&sSpriteSheet_Pokeblock);

    for (u32 i = gAmieData->pokeblockListStart; i < (gAmieData->pokeblockListStart + NUM_DISPLAYED_PKBL); i++)
    {
        color = gSaveBlock1Ptr->pokeblocks[i].color;

        if (color == PBLOCK_CLR_NONE)
            return;

        palTag = TAG_PKBL_0 + count;
        LoadSpritePaletteWithTag(gPokeblocksPals[color - 1], palTag);

        struct SpriteTemplate pkblkTemplate = {
            .tileTag = TAG_AMIE_POKEBLOCK,
            .paletteTag = palTag,
            .oam = &sOam_32x32Affine_1,
            .anims = gDummySpriteAnimTable,
            .images = NULL,
            .affineAnims = sAffineAnims_Pokeblock,
            .callback = SpriteCallbackDummy
        };
        gAmieData->pokeblockSpriteIds[count] = CreateSprite(&pkblkTemplate, sPokeblockPositionsX[count], 17, 2);
        gSprites[gAmieData->pokeblockSpriteIds[count]].sPkblkNum = count;

        count++;
    }
}

static void DestroyPokeblockSprites(void)
{
    for (u32 i = 0; i < NUM_DISPLAYED_PKBL; i++)
    {
        if (gAmieData->pokeblockSpriteIds[i] == 0)
            return;

        DestroySpriteAndFreeResources(&gSprites[gAmieData->pokeblockSpriteIds[i]]);
        gAmieData->pokeblockSpriteIds[i] = 0;
    }
}

static void CreateAmiePokeblocks(void)
{
    CreatePokeblockSprites();
}

static void AmieHandHandleInput(u8 taskId)
{
    if (JOY_NEW(EXIT_BUTTON)/* || (JOY_NEW(INTERACT_BUTTON) && IsHandOnExitIcon())*/)
    {
        gSprites[gAmieData->handSpriteId].invisible = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK); // Fade the screen to black.
        gTasks[taskId].func = Task_AmieEndFade;
        return;
    }

    switch (tState)
    {
    case AMIE_TASK_NORMAL:
        if (JOY_NEW(PUFF_BUTTON) || (JOY_NEW(INTERACT_BUTTON) && IsHandOnPokeblockIcon()))
        {
            PlaySE(SE_WIN_OPEN);
            ShowBg(2);
            CreateAmiePokeblocks();
            gSprites[gAmieData->handSpriteId].invisible = TRUE;
            tState = AMIE_TASK_PUFF;
            return;
        }

        if (tPetScore > 0 && tPetScore < AMIE_PET_SCORE_TARGET)
            tPetScore--;

        if (tPetScore < 0 && tPetScore > AMIE_BAD_PET_SCORE_TARGET)
            tPetScore--;

        if (JOY_HELD(INTERACT_BUTTON))
        {
            u32 petZone = GetCurrentPettingArea();

            if (petZone)
            {
                if (tPetZone != petZone)
                {
                    tCounter = 0;
                    if (JOY_HELD(DPAD_ANY))
                    {
                        tPetZone = petZone;
                    }
                    StartSpriteAnim(&gSprites[gAmieData->handSpriteId], 1);
                }
                else
                {
                    if (tPetZone == PET_TYPE_GOOD)
                    {
                        if (tPetScore >= AMIE_PET_SCORE_TARGET)
                        {
                            CreateHeartSprites(3);
                        
                            StartHappyAnim();
                            PlayCry_ByMode(GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES), 0, CRY_MODE_GROWL_2);
                            gSprites[gAmieData->handSpriteId].invisible = TRUE;
                            tPetScore = 0;
                            tCounter = 0;
                            return;
                        }
                        else if (JOY_HELD(DPAD_ANY))
                        {
                            if (tSECounter == 0)
                            {
                                PlaySE(SE_CONTEST_CURTAIN_RISE);
                                tSECounter = PET_SE_DELAY;
                            }
                            tPetScore += 4;
                            tCounter = 0;
                            tSECounter--;
                        }
                    }
                    else if (tPetZone == PET_TYPE_BAD)
                    {
                        if (tPetScore <= AMIE_BAD_PET_SCORE_TARGET)
                        {
                            CreateAngrySprite();
                            StartAngryAnim();
                            PlayCry_ByMode(GetMonData(&gPlayerParty[gAmieData->partySlot], MON_DATA_SPECIES), 0, CRY_MODE_FAINT);
                            gSprites[gAmieData->handSpriteId].invisible = TRUE;
                            tPetScore = 0;
                            tCounter = 0;
                            return;
                        }
                        else if (JOY_HELD(DPAD_ANY))
                        {
                            if (tSECounter == 0)
                            {
                                PlaySE(SE_CONTEST_CURTAIN_FALL);
                                tSECounter = PET_SE_DELAY;
                            }
                            tPetScore -= 4;
                            tCounter = 0;
                            tSECounter--;
                        }
                    }

                    if (tPetScore < AMIE_PET_SCORE_TARGET)
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

                    if (tPetScore > AMIE_BAD_PET_SCORE_TARGET)
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
                StartSpriteAnim(&gSprites[gAmieData->handSpriteId], 0);
            }
        }
        else
        {
            tPetZone = PET_TYPE_NONE;
            StopPetting(taskId);
            StartSpriteAnim(&gSprites[gAmieData->handSpriteId], 0);
        }
        break;
    case AMIE_TASK_BACK:
        if (JOY_NEW(INTERACT_BUTTON))
        {
            StartSpriteAnim(&gSprites[gAmieData->handSpriteId], 2);
            PlaySE(SE_M_ABSORB);
            tTapCounter++;
            tCounter = 1;
        }

        if (tCounter > 0 && gSprites[gAmieData->handSpriteId].animEnded)
        {
            tCounter++;
            if (tCounter > 32)
            {
                tTapCounter = 0;
                tCounter = 0;
            }
        }

        if (tTapCounter == 2)
        {
            tCounter = 0;
            tState = AMIE_TASK_NORMAL;
            PlaySE(SE_PIN);
            CreateSurprisedEmote();
            gTasks[taskId].func = Task_TurnMonAroundWaitSurprisedEmote;
        }
        break;
    }

    MoveSpriteFromInput(&gSprites[gAmieData->handSpriteId]);
}

static void SpriteCB_Mon(struct Sprite *sprite)
{
    switch (sprite->sCurrAnim)
    {
    case AMIE_STATE_NORMAL:
        if (sprite->sCounter == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            sprite->sCounter++;
        }
        break;
    case AMIE_STATE_HAPPY:
        if (sprite->sCounter == 0 || sprite->sCounter == 27)
            sprite->x2--;
        else if (sprite->sCounter == 5 || sprite->sCounter == 22)
            sprite->x2++;

        if (sprite->sCounter >= 6 && sprite->sCounter <= 15)
            sprite->y2 -= 2;
        else if (sprite->sCounter >= 16 && sprite->sCounter <= 25)
            sprite->y2 += 2;

        if (sprite->sCounter <= 27)
            sprite->sCounter++;
        break;
    case AMIE_STATE_ANGRY:
        if (sprite->sCounter <= 2 || (sprite->sCounter > 8 && sprite->sCounter <= 14) || (sprite->sCounter > 20 && sprite->sCounter <= 23))
            sprite->x2 -= 4;
        else if ((sprite->sCounter > 2 && sprite->sCounter <= 8) || (sprite->sCounter > 14 && sprite->sCounter <= 20))
            sprite->x2 += 4;

        if (sprite->sCounter >= 60)
        {
            StartNormalAnim();
            ResetAmieHand();
        }

        sprite->sCounter++;
        break;
    }
}

static void SpriteCB_MonBack(struct Sprite *sprite)
{

}

static void SpriteCB_Heart(struct Sprite *sprite)
{
    sprite->sCounter++;
    sprite->x2 = Sin2(0 - sprite->sCounter * 3) / 512;
    if (sprite->sCounter % 2 == 0)
        sprite->y -= 1;

    if (sprite->y < -16)
        DestroySprite(sprite);
}

static void SpriteCB_Angry(struct Sprite *sprite)
{
}

static void SpriteCB_SpeechBubble(struct Sprite *sprite)
{
}
