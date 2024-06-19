#ifndef GUARD_CONSTANTS_FOLLOW_ME_H
#define GUARD_CONSTANTS_FOLLOW_ME_H

#define FOLLOWER_FLAG_HAS_RUNNING_FRAMES    0x1
#define FOLLOWER_FLAG_CAN_BIKE              0x2
#define FOLLOWER_FLAG_CAN_LEAVE_ROUTE       0x4     // teleport, dig, fly, etc
#define FOLLOWER_FLAG_CAN_SURF              0x8
#define FOLLOWER_FLAG_CAN_WATERFALL         0x10
#define FOLLOWER_FLAG_CAN_DIVE              0x20
#define FOLLOWER_FLAG_CAN_ROCK_CLIMB        0x40    // need rock climb implemented
#define FOLLOWER_FLAG_CLEAR_ON_WHITE_OUT    0x80
#define FOLLOWER_FLAG_CUSTOM_FOLLOW_SCRIPT  0x100   // follower has custom script while following (use loadword prior to setfollower)

#define FOLLOWER_FLAG_ALL_WATER             FOLLOWER_FLAG_CAN_SURF | FOLLOWER_FLAG_CAN_WATERFALL | FOLLOWER_FLAG_CAN_DIVE
#define FOLLOWER_FLAG_ALL_LAND              FOLLOWER_FLAG_HAS_RUNNING_FRAMES | FOLLOWER_FLAG_CAN_BIKE | FOLLOWER_FLAG_CAN_LEAVE_ROUTE
#define FOLLOWER_FLAG_ALL                   FOLLOWER_FLAG_ALL_WATER | FOLLOWER_FLAG_ALL_LAND | FOLLOWER_FLAG_CLEAR_ON_WHITE_OUT

//For ease of use in setfollower macro while scripting
#define RUNNING_FRAMES                      0x1
#define CAN_BIKE                            0x2
#define CAN_LEAVE_ROUTE                     0x4     // teleport, dig, fly, etc
#define CAN_SURF                            0x8
#define CAN_WATERFALL                       0x10
#define CAN_DIVE                            0x20
#define CAN_ROCK_CLIMB                      0x40    // need rock climb implemented
#define CLEAR_ON_WHITE_OUT                  0x80
#define CUSTOM_SCRIPT                       0x100
#define ALL_WATER                           FOLLOWER_FLAG_ALL_WATER
#define ALL_LAND                            FOLLOWER_FLAG_ALL_LAND
#define FOLLOWER_ALL                        FOLLOWER_FLAG_ALL


#endif // GUARD_CONSTANTS_FOLLOW_ME_H
