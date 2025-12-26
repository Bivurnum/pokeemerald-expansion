#ifndef GUARD_FISHING_H
#define GUARD_FISHING_H

void Task_Fishing(u8);
void StartFishing(u8 rod);
void UpdateChainFishingStreak();
u32 CalculateChainFishingShinyRolls(void);
bool32 ShouldUseFishingEnvironmentInBattle();
void AlignFishingAnimationFrames(void);
void ResetPlayerAvatar(u16 gfxId);

#endif // GUARD_FISHING_H