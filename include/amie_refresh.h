#ifndef GUARD_AMIE_REFRESH_H
#define GUARD_AMIE_REFRESH_H

#define AMIE_PET_SCORE_TARGET       600
#define AMIE_BAD_PET_SCORE_TARGET   -600

#define INTERACT_BUTTON A_BUTTON
#define EXIT_BUTTON     B_BUTTON
#define PUFF_BUTTON     L_BUTTON

#define AMIE_MOVE_SPEED 1

#define TAG_MON         0x3000

#define TAG_HAND        0x2000
#define TAG_PKBL_ICON   0x2001
#define TAG_SWITCH_ICON 0x2002
#define TAG_EMOTE       0x2003

#define TAG_PKBL_0      0x2120
#define TAG_PKBL_1      0x2121
#define TAG_PKBL_2      0x2122
#define TAG_PKBL_3      0x2123
#define TAG_PKBL_4      0x2124
#define TAG_PKBL_5      0x2125

#define NUM_DISPLAYED_PKBL  6

#define TAG_PARTY_AMIE      0x2032
#define TAG_SURPRISED       0x2033
#define TAG_MUSIC           0x2034
#define TAG_AMIE_POKEBLOCK  0x2035

#define HAND_START_X    28
#define HAND_START_Y    45
#define HAND_OFFSET     16

#define PET_SE_DELAY    30

#define NUM_AMIE_PET_AREAS  5

#define AMIE_SLOT_NONE      6

struct AmieData
{
    u8 pokeblockSpriteIds[NUM_DISPLAYED_PKBL];
    u8 pokeblockListStart;
    u8 partySlot:3;
    u8 controlsPaused:1;
    u8 isSwitching:1;
    u8 padding1:3;
    u8 taskId;
    u8 monSpriteId;
    u8 monBackSpriteId;
    u8 handSpriteId;
    u8 pokeblockIconSpriteId;
    u8 emoteBubbleSpriteId;
    u8 emoteSpriteId;
};

enum AmieTaskStates
{
    AMIE_TASK_NORMAL,
    AMIE_TASK_BACK,
    AMIE_TASK_PUFF
};

enum AmiePetZoneTypes
{
    PET_TYPE_NONE,
    PET_TYPE_BAD, 
    PET_TYPE_GOOD,
    PET_TYPE_GREAT
};

enum AmiePetZones
{
    PET_ZONE_BASIC,
    PET_ZONE_COUNT
};

enum AmieMonAnimStates
{
    AMIE_STATE_NORMAL,
    AMIE_STATE_HAPPY,
    AMIE_STATE_ANGRY
};

struct AmiePetZone
{
    enum AmiePetZoneTypes type;
    s16 leftX;
    s16 rightX;
    s16 topY;
    s16 bottomY;
};

extern EWRAM_DATA struct AmieData *gAmieData;

extern const struct AmiePetZone AmieRefreshPetZones[][5];

void LoadAmiePartyMenuSprite(void);
void CB2_InitAmie(void);

#define amie_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#endif // GUARD_AMIE_REFRESH_H
