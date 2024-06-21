static const struct TrainerMon sParty_StevenPartner[] = {
    {
        .species = SPECIES_METANG,
        .lvl = 42,
        .nature = NATURE_BRAVE,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
        .moves = {MOVE_LIGHT_SCREEN, MOVE_PSYCHIC, MOVE_REFLECT, MOVE_METAL_CLAW},
    },
    {
        .species = SPECIES_SKARMORY,
        .lvl = 43,
        .nature = NATURE_IMPISH,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 6, 252),
        .moves = {MOVE_TOXIC, MOVE_AERIAL_ACE, MOVE_PROTECT, MOVE_STEEL_WING},
    },
    {
        .species = SPECIES_AGGRON,
        .lvl = 44,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 6),
        .moves = {MOVE_THUNDER, MOVE_PROTECT, MOVE_SOLAR_BEAM, MOVE_DRAGON_CLAW},
    }
};

static const struct TrainerMon sParty_KylePetalburgWoods[] = {
    {
        .species = SPECIES_CHARMANDER,
        .lvl = 11,
    },
    {
        .species = SPECIES_NIDORAN_M,
        .lvl = 8,
    }
};

static const struct TrainerMon sParty_BrenPetalburgWoods[] = {
    {
        .species = SPECIES_PIPLUP,
        .lvl = 11,
    },
    {
        .species = SPECIES_ZUBAT,
        .lvl = 6,
    }
};

static const struct TrainerMon sParty_SpencerPetalburgWoods[] = {
    {
        .species = SPECIES_TREECKO,
        .lvl = 11,
    },
    {
        .species = SPECIES_MACHOP,
        .lvl = 8,
    }
};
