#ifndef GUARD_AMIE_REFRESH_H
#define GUARD_AMIE_REFRESH_H

#define AR_ENABLE_AMIE_REFRESH  TRUE
#define AR_ENABLE_AMIE_FLAG  FLAG_UNUSED_0x863

#define AMIE_PET_SCORE_TARGET       600
#define AMIE_BAD_PET_SCORE_TARGET   -600

#define INTERACT_BUTTON A_BUTTON
#define EXIT_BUTTON     B_BUTTON

#define TAG_MON         0x1000

#define TAG_HAND        0x2000
#define TAG_PUFF_ICON   0x2001
#define TAG_EMOTE       0x2002

#define HAND_START_X    28
#define HAND_START_Y    45

#define NUM_AMIE_PET_AREAS  5

struct AmieData
{
    u16 species:11;
    u16 isShiny:1;
    u16 isFemale:1;
    u16 controlsPaused:1;
    u16 padding1:2;
    u8 taskId;
    u8 monSpriteId;
    u8 handSpriteId;
    u8 puffIconSpriteId;
    u8 musicSpriteId;
};

enum AmieTaskStates
{
    STATE_HAND
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

struct AmiePetZone
{
    enum AmiePetZoneTypes type;
    s16 leftX;
    s16 rightX;
    s16 topY;
    s16 bottomY;
};

extern const struct AmiePetZone AmieRefreshPetZones[][5];

void CB2_InitAmie(void);

#define amie_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#endif // GUARD_AMIE_REFRESH_H
