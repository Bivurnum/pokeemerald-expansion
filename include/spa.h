#ifndef GUARD_SPA_H
#define GUARD_SPA_H

#define TAG_RATTATA     0x1000
#define TAG_HAND        0x1001
#define TAG_ITEMS_ICON  0x1002

enum HandStates
{
    HAND_NORMAL,
    HAND_PET,
    HAND_ITEM
};

#define spa_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#endif // GUARD_SPA_H