#ifndef GUARD_SPA_H
#define GUARD_SPA_H

// Task Data
#define tState          gTasks[taskId].data[0]
#define tSelectedItem   gTasks[taskId].data[1]
#define tActiveItemId   gTasks[taskId].data[2]
#define tBerryBites     gTasks[taskId].data[3]
#define tItchFadeCount  gTasks[taskId].data[3]
#define tCounter        gTasks[taskId].data[4]
#define tBiteState      gTasks[taskId].data[5]
#define tScratchState   gTasks[taskId].data[5]
#define tPetArea        gTasks[taskId].data[6]
#define tPetScore       gTasks[taskId].data[7]
#define tScratchScore   gTasks[taskId].data[8]
#define tBugsCaught     gTasks[taskId].data[8]
#define tBugsEaten      gTasks[taskId].data[8]

// Sprite Data
#define sTaskId         data[0]
#define sInterval       data[1]
#define sCounter        data[2]
#define sHeartOffset    data[3]
#define sBugDirection   data[3]
#define sBlinkCounter   data[4]
#define sBugId          data[5]
#define sBugInterval    data[6]
#define sFrozen         data[7]

// Rattata Sprite Data
#define sBerryBites data[3]

#define INTERACT_BUTTON     A_BUTTON
#define FAST_BUTTON         B_BUTTON
#define ITEM_MENU_BUTTON    L_BUTTON
#define STATUS_BUTTON       R_BUTTON
#define EXIT_BUTTON         SELECT_BUTTON

#define TAG_HAND        0x1000
#define TAG_ITEMS_ICON  0x1001
#define TAG_BERRY       0x1002
#define TAG_CLAW        0x1003
#define TAG_HONEY       0x1004

#define TAG_MON     0x2000
#define TAG_ITCH    0x2001
#define TAG_BUGS    0x2001

#define ITEM_START_X    -22
#define ITEM_END_X      10

#define HAND_START_X    28
#define HAND_START_Y    45

#define SPA_ITEM_BIT_BERRY  0x1
#define SPA_ITEM_BIT_CLAW   0x2
#define SPA_ITEM_BIT_HONEY  0x4
#define SPA_ITEM_BIT_ORB    0x8

#define SPA_PET_SCORE_TARGET    600

#define BLINK_INTERVAL  180

#define MAX_BUGS            4
#define BUG_BOUND_WIDTH     45
#define BUG_BOUND_HEIGHT    35
#define BUG_MIN_MOVE        4
#define BUG_MAX_MOVE        9
#define BUG_MOVE_DELAY      8

struct SpaData
{
    u8 mon:4;
    u8 isSatisfied:1;
    u8 hasBeenPetBad:1;
    u8 statusIsShowing:1;
    u8 bugsAttacking:1;
    u8 pausedSpriteId;
    u8 monSpriteIds[11];
    u8 bugSpriteIds[4];
    u8 heartSpriteIds[3];
    u8 musicSpriteId;
    u8 angrySpriteId;
    u8 handSpriteId;
    u8 itemsIconSpriteId;
    u8 itemsExitSpriteId;
    u8 itemTraySpriteId1;
    u8 itemTraySpriteId2;
    u8 itemSelectorSpriteId;
    u8 berrySpriteId;
    u8 clawSpriteId;
    u8 honeySpriteId;
    u8 orbSpriteId;
};

enum SpaMons
{
    SPA_RATTATA,
    SPA_TEDDIURSA,
    SPA_PSYDUCK,
    SPA_FLETCHINDER,
    SPA_NUM_MONS
};

enum SpaItems
{
    SPA_BERRY,
    SPA_CLAW,
    SPA_HONEY,
    SPA_ORB
};

enum PetAreas
{
    SPA_PET_NONE,
    SPA_PET_BODY,
    SPA_PET_HEAD,
    SPA_PET_BAD
};

enum SpaTaskStates
{
    STATE_HAND,
    STATE_TRAY_OUT,
    STATE_ITEM_CHOOSE,
    STATE_TRAY_IN_ITEM,
    STATE_TRAY_IN_HAND,
    STATE_ITEM
};

enum BiteStates
{
    BITE_STATE_NONE,
    BITE_STATE_ACTIVE,
    BITE_STATE_END
};

enum BugDirections {
    BUG_NONE,
    BUG_NORTH,
    BUG_EAST,
    BUG_SOUTH,
    BUG_WEST,
    BUG_NE,
    BUG_SE,
    BUG_SW,
    BUG_NW
};

extern struct SpaData sSpaData;

extern const struct SpritePalette sSpritePalettes_SpaRattata[];
extern const struct SpritePalette sSpritePalettes_SpaTeddiursa[];
extern const struct SpritePalette sSpritePalettes_SpaPsyduck[];
extern const struct SpritePalette sSpritePalettes_SpaFletchinder[];

extern const struct SpriteTemplate sSpriteTemplate_Bug;

void CreateRattataSprites(u8 taskId);
void ResetRattataSprites(void);
void HandleItemsRattata(u8 taskId);
void StartRattataBadTouch(u8 taskId);
void StartRattataAngry(u8 taskId);
void StartRattataPet(void);
void StopRattataPet(void);
void EndSpaBadRattata(void);

void CreateTeddiursaSprites(u8 taskId);
void HandleItemsTeddiursa(u8 taskId);
void TeddiursaReactToClaw(void);
void ResetTeddiursaSpritesNormal(void);
void ResetTeddiursaSpritesScratch(void);
void StartTeddiursaHappyAnim(void);
void StartTeddiursaBadTouch(u8 taskId);
void StartTeddiursaAngry(u8 taskId);
void StartTeddiursaPet(void);
void EndSpaBadTeddiursa(void);

void CreatePsyduckSprites(u8 taskId);
void StartPsyduckBugsBadTouch(u8 taskId);
void EndPsyduckBugsBadTouch(u8 taskId);
void StartPsyduckPetHead(void);
void StartPsyduckPetBody(void);
void StartPsyduckHappyAnim(void);
void ResetPsyduckSprites(void);
void HandleItemsPsyduck(u8 taskId);

void CreateFletchinderSprites(u8 taskId);
bool32 HoneyHasBugs(void);
void StartFletchinderPet(void);
void StartFletchinderBadTouch(u8 taskId);
void StartFletchinderAngry(u8 taskId);
void StartFletchinderHappyAnim(void);
void FletchinderReactToHoney(void);
void ResetFletchinderSpritesSatisfied(void);
void ResetFletchinderSpritesFamished(void);
void EndSpaBadFletchinder(void);
void HandleItemsFletchinder(u8 taskId);

void PauseUntilAnimEnds(u8 taskId, u8 spriteId);
void CreateMusicSprite(u8 taskId);
void CreateAngrySprite(u8 taskId);
bool32 IsBerryInFeedingZone(void);
void DoSpaMonEnjoyedSnackText(void);
void DoSpaMonFeelsBetterText(void);
void ResetSpaHand(void);
void Task_SpaEndBad(u8 taskId);

static const struct OamData sOam_64x64 =
{
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
};

static const struct OamData sOam_64x32 =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1,
};

static const struct OamData sOam_32x64 =
{
    .shape = SPRITE_SHAPE(32x64),
    .size = SPRITE_SIZE(32x64),
    .priority = 1,
};

static const struct OamData sOam_32x32 =
{
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const struct OamData sOam_16x8 =
{
    .shape = SPRITE_SHAPE(16x8),
    .size = SPRITE_SIZE(16x8),
    .priority = 1,
};

static const struct OamData sOam_32x8 =
{
    .shape = SPRITE_SHAPE(32x8),
    .size = SPRITE_SIZE(32x8),
    .priority = 0,
};

static const struct OamData sOam_16x16 =
{
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const struct OamData sOam_16x16_Affine =
{
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

#define spa_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#define SPA_FONT_WIDTH(string) GetFontIdToFit(string, FONT_NORMAL, 0, 192)

#endif // GUARD_SPA_H
