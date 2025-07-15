#ifndef GUARD_SPA_H
#define GUARD_SPA_H

// Task data.
#define tCounter        data[0]
#define tPetArea        data[1]
#define tPetActive      data[2]
#define tPetTimer       data[3]
#define tItemActive     data[4]
#define tItemMenuState  data[5]
#define tSelectedItem   data[6]
#define tBerryBites     data[7]
#define tIsBiting       data[8]
#define tIsFed          data[9]
#define tNumBadPets     data[10]
#define tPetScore       data[11]
#define tStatusShowing  data[12]
#define tItemFlagBits   data[14]
#define tShouldExit     data[15]

// Sprite data.
#define sTaskId         data[0]
#define sCounter        data[1]
#define sInterval       data[2]
#define sHeartOffset    data[3]
#define sHeartId        data[4]
#define sFadeStarted    data[5]
#define sBerryBites     data[6]
#define sTask       gTasks[sprite->sTaskId]
#define sHandState  sprite->data[3]

#define INTERACT_BUTTON     A_BUTTON
#define FAST_BUTTON         B_BUTTON
#define ITEM_MENU_BUTTON    L_BUTTON
#define STATUS_BUTTON       R_BUTTON
#define EXIT_BUTTON         SELECT_BUTTON

#define TAG_HAND        0x1000
#define TAG_ITEMS_ICON  0x1001
#define TAG_BERRY       0x1002

#define ITEM_START_X    -22
#define ITEM_END_X      10

#define SPA_ITEM_BIT_BERRY  0x1
#define SPA_ITEM_BIT_CLAW   0x2
#define SPA_ITEM_BIT_HONEY  0x4
#define SPA_ITEM_BIT_ORB    0x8

#define SPA_PET_SCORE_TARGET    600

enum SpaMons
{
    SPA_RATTATA,
    SPA_TEDDIURSA
};

enum HandStates
{
    HAND_NORMAL,
    HAND_PET,
    HAND_ITEM
};

enum PetAreas
{
    SPA_PET_NONE,
    SPA_PET_BODY,
    SPA_PET_HEAD,
    SPA_PET_BAD
};

enum ItemChooseStates
{
    ITEM_STATE_START,
    ITEM_STATE_TRAY_OUT,
    ITEM_STATE_TRAY_INPUT,
    ITEM_STATE_ITEM_SELECTED,
    ITEM_STATE_ITEM_HELD,
    ITEM_STATE_NO_SELECTION,
    ITEM_STATE_END,
};

bool32 IsBerryInFeedingZone(void);

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

#define spa_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#endif // GUARD_SPA_H