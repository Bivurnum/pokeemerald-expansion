#ifndef GUARD_SPA_PSYDUCK_H
#define GUARD_SPA_PSYDUCK_H

#define TAG_PSYDUCK     0x2000
#define TAG_BUGS        0x2001

#define MAX_BUGS        4

void CreatePsyduckSprites(u8 taskId);

extern const struct SpritePalette sSpritePalettes_SpaPsyduck[];

#endif // GUARD_SPA_PSYDUCK_H
