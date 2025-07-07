#ifndef GUARD_SPA_H
#define GUARD_SPA_H

#define TAG_RATTATA 0x1000

#define treasure_score_frame(ptr, frame, width, height) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

#endif // GUARD_SPA_H