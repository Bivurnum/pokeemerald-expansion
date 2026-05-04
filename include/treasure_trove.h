#ifndef GUARD_TREASURE_TROVE_H
#define GUARD_TREASURE_TROVE_H

#define TAG_MUGSHOT             0x100A
#define TAG_MUGSHOT_FRAME       0x100B

#define NUM_TREASURE_ITEMS      5
#define TOTAL_TREASURE          400

enum TreasureSpecies
{
    TT_MAGIKARP,
    TT_KRABBY,
    TT_ARROKUDA,
    TT_GYARADOS,
    TT_OCTILLERY,
    TT_SKRELP,
    TT_BRUXISH,
    TT_TENTACRUEL,
    TT_WAILMER,
    TT_WOOPER,
    TT_BARBOACH,
    TT_CARVANHA,
    TT_AZUMARILL,
    TT_LUVDISC,
    TT_FINIZEN,
    TT_CRAMORANT,
    TT_DONDOZO,
    TT_STARYU,
    TT_SHELLDER,
    TT_LUMINEON,
    TT_DRAGONAIR,
    TT_SPECIES_COUNT,
    TT_MURKROW,
    TT_KYOGRE
};

u32 GetTreasureSpeciesFromSpecies(void);
void Task_AfterCaught(u8 taskId);

#endif // GUARD_TREASURE_TROVE_H
