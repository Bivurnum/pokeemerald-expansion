#ifndef GUARD_FISHING_GAME_ABILITY_EFFECTS_H
#define GUARD_FISHING_GAME_ABILITY_EFFECTS_H

#include "constants/abilities.h"

static const struct FishingAbilityModifier sAbilityEffects[] = 
{
    {0},
/*
    {
        .ability = ,
        .happensWhen = ,
        .effectType = ,
        .operand = ,
        .effectAmount = ,
        .hasMoreEffects = 
    },
*/
    {
        .ability = ABILITY_STICKY_HOLD,
        .happensWhen = FG_HAPPENS_WHEN_FISH_INSIDE_BAR,
        .effectType = FG_EFFECT_FISH_SPEED,
        .operand = FG_SUBTRACT,
        .effectAmount = 2,
        .hasMoreEffects = TRUE
    },
    {
        .ability = ABILITY_STICKY_HOLD,
        .happensWhen = FG_HAPPENS_ALWAYS,
        .effectType = FG_EFFECT_BAR_SIZE,
        .operand = FG_ADD,
        .effectAmount = 8,
        .hasMoreEffects = FALSE
    },
    {
        .ability = ABILITY_SUCTION_CUPS,
        .happensWhen = FG_HAPPENS_WHEN_FISH_INSIDE_BAR,
        .effectType = FG_EFFECT_FISH_MOVE_DELAY,
        .operand = FG_ADD,
        .effectAmount = 20,
        .hasMoreEffects = TRUE
    },
    {
        .ability = ABILITY_SUCTION_CUPS,
        .happensWhen = FG_HAPPENS_ALWAYS,
        .effectType = FG_EFFECT_BAR_SIZE,
        .operand = FG_ADD,
        .effectAmount = 8,
        .hasMoreEffects = FALSE
    }
};

#endif // GUARD_FISHING_GAME_ABILITY_EFFECTS_H
