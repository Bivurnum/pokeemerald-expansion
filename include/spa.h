#ifndef GUARD_SPA_H
#define GUARD_SPA_H

// Task Data
#define tState          gTasks[taskId].data[0]
#define tSelectedItem   gTasks[taskId].data[1]
#define tActiveItemId   gTasks[taskId].data[2]

// Sprite Data
#define sTaskId     data[0]
#define sInterval   data[1]
#define sCounter    data[2]

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

#define ITEM_START_X    -22
#define ITEM_END_X      10

#define HAND_START_X    28
#define HAND_START_Y    45

#define SPA_ITEM_BIT_BERRY  0x1
#define SPA_ITEM_BIT_CLAW   0x2
#define SPA_ITEM_BIT_HONEY  0x4
#define SPA_ITEM_BIT_ORB    0x8

struct SpaData
{
    u8 mon:7;
    u8 shouldExit:1;
    u8 itemFlagBits;
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
    SPA_FLETCHINDER
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

extern const struct SpritePalette sSpritePalettes_SpaRattata[];

void CreateRattataSprites(u8 taskId);

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

#endif // GUARD_SPA_H
