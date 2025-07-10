#ifndef GUARD_SPA_H
#define GUARD_SPA_H

#define TAG_RATTATA     0x1000
#define TAG_HAND        0x1001
#define TAG_ITEMS_ICON  0x1002
#define TAG_BERRY       0x1003

#define ITEM_START_X    -22
#define ITEM_END_X      10

#define SPA_ITEM_BIT_BERRY  0x1
#define SPA_ITEM_BIT_CLAW   0x2
#define SPA_ITEM_BIT_HONEY  0x4
#define SPA_ITEM_BIT_ORB    0x8
#define SPA_ITEM_BIT_ALWAYS 0x10

enum HandStates
{
    HAND_NORMAL,
    HAND_PET,
    HAND_ITEM
};

enum RatPetAreas
{
    RAT_PET_NONE,
    RAT_PET_BODY,
    RAT_PET_HEAD,
    RAT_PET_BAD
};

#define spa_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#endif // GUARD_SPA_H