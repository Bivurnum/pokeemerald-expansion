#ifndef GUARD_CONSTANTS_FOLLOW_ME_H
#define GUARD_CONSTANTS_FOLLOW_ME_H

#define FOLLOWER_FLAG_HAS_RUNNING_FRAMES    0x1
#define FOLLOWER_FLAG_CAN_LEAVE_ROUTE       0x4     // teleport, dig, fly, etc
#define FOLLOWER_FLAG_CLEAR_ON_WHITE_OUT    0x80

#define FOLLOWER_FLAG_ALL_LAND              FOLLOWER_FLAG_HAS_RUNNING_FRAMES | FOLLOWER_FLAG_CAN_LEAVE_ROUTE
#define FOLLOWER_FLAG_ALL                   FOLLOWER_FLAG_ALL_LAND | FOLLOWER_FLAG_CLEAR_ON_WHITE_OUT

//For ease of use in setfollower macro while scripting
#define RUNNING_FRAMES                      FOLLOWER_FLAG_HAS_RUNNING_FRAMES
#define CAN_LEAVE_ROUTE                     FOLLOWER_FLAG_CAN_LEAVE_ROUTE       // teleport, dig, fly, etc
#define CLEAR_ON_WHITE_OUT                  FOLLOWER_FLAG_CLEAR_ON_WHITE_OUT

#define ALL_LAND                            FOLLOWER_FLAG_ALL_LAND
#define FOLLOWER_ALL                        FOLLOWER_FLAG_ALL


// Replace the 0 with a flag in order to use that flag to toggle whether the Player's party
// will be automatically healed after every follower partner battle.
// If you want this to always be active without using a flag, replace 0 with ALWAYS.
#define F_FLAG_HEAL_AFTER_FOLLOWER_BATTLE   0

// Replace the 0 with a flag in order to use that flag to toggle whether the follower partner will join you for wild battles.
// If you want this to always be active without using a flag, replace 0 with ALWAYS.
#define F_FLAG_PARTNER_WILD_BATTLES         0

// If set to TRUE, two wild Pokemon will show up to the partner battle instead of just one.
#define FOLLOWER_WILD_BATTLE_VS_2           TRUE

// If set to TRUE, a preview of the player's and partner's teams will be shown before every trainer battle.
#define FOLLOWER_PARTY_PREVIEW              TRUE

// If set to TRUE, the player will turn to face the follower when they exit a doorway.
#define FACE_FOLLOWER_ON_DOOR_EXIT          TRUE



// These flags are currently bugged and may cause the game to softlock.
// They have been removed from all of the defines above.
// Use at your own risk.
#define FOLLOWER_FLAG_CAN_BIKE              0x2
#define FOLLOWER_FLAG_CAN_SURF              0x8
#define FOLLOWER_FLAG_CAN_WATERFALL         0x10
#define FOLLOWER_FLAG_CAN_DIVE              0x20


#endif // GUARD_CONSTANTS_FOLLOW_ME_H