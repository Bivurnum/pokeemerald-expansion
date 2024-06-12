InsideOfTruck_MapScripts::
# 6 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
# 7 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0


InsideOfTruck_OnLoad::
# 11 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
# 12 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
# 13 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end


InsideOfTruck_OnResume::
# 18 "data/maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
	end


InsideOfTruck_EventScript_SetIntroFlags::
# 23 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 24 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 25 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1
# 26 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 1
# 27 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 1
# 28 "data/maps/InsideOfTruck/scripts.pory"
	checkplayergender
# 29 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 30 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_SetIntroFlags_3
# 32 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_SetIntroFlags_4
# 34 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_SetIntroFlags_5
InsideOfTruck_EventScript_SetIntroFlags_1:
	end

InsideOfTruck_EventScript_SetIntroFlags_3:
# 31 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsSpencer
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_4:
# 33 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsBren
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_5:
# 35 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsKyle
	goto InsideOfTruck_EventScript_SetIntroFlags_1


InsideOfTruck_EventScript_SetIntroFlagsSpencer::
# 41 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 42 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 43 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 44 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_RIVAL_MOM
# 45 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 46 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 47 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsBren::
# 52 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 53 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 54 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 55 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_RIVAL_MOM
# 56 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 57 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 58 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsKyle::
# 63 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_KYLES_HOUSE_2F
# 64 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 65 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 66 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 67 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_RIVAL_MOM
# 68 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
# 69 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_MovingBox::
# 74 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end


InsideOfTruck_EventScript_WakeFriend::
# 79 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 80 "data/maps/InsideOfTruck/scripts.pory"
	delay 15
# 81 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_PIN
# 82 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
# 83 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 84 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 85 "data/maps/InsideOfTruck/scripts.pory"
	faceplayer
# 86 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_FriendAwake, MSGBOX_DEFAULT
# 87 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 88 "data/maps/InsideOfTruck/scripts.pory"
	delay 15
# 89 "data/maps/InsideOfTruck/scripts.pory"
	getplayerxy VAR_0x8006, VAR_0x8007
# 90 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8006
# 92 "data/maps/InsideOfTruck/scripts.pory"
	case 1, InsideOfTruck_EventScript_WakeFriend_3
# 94 "data/maps/InsideOfTruck/scripts.pory"
	case 2, InsideOfTruck_EventScript_WakeFriend_4
InsideOfTruck_EventScript_WakeFriend_1:
# 97 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 98 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 99 "data/maps/InsideOfTruck/scripts.pory"
	checkplayergender
# 100 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_WakeFriend_7
# 110 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_WakeFriend_8
# 119 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_WakeFriend_9
InsideOfTruck_EventScript_WakeFriend_5:
# 129 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 130 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 131 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8006
# 132 "data/maps/InsideOfTruck/scripts.pory"
	case 1, InsideOfTruck_EventScript_WakeFriend_12
# 135 "data/maps/InsideOfTruck/scripts.pory"
	case 2, InsideOfTruck_EventScript_WakeFriend_13
InsideOfTruck_EventScript_WakeFriend_10:
# 139 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 140 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_EXIT
# 141 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 142 "data/maps/InsideOfTruck/scripts.pory"
	removeobject VAR_0x8009
# 143 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 144 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 145 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 146 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_SPENCER_IN_TRUCK
# 147 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_BREN_IN_TRUCK
# 148 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_KYLE_IN_TRUCK
# 149 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 150 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8009
# 151 "data/maps/InsideOfTruck/scripts.pory"
	case 4, InsideOfTruck_EventScript_WakeFriend_25
# 153 "data/maps/InsideOfTruck/scripts.pory"
	case 5, InsideOfTruck_EventScript_WakeFriend_26
# 155 "data/maps/InsideOfTruck/scripts.pory"
	case 6, InsideOfTruck_EventScript_WakeFriend_27
InsideOfTruck_EventScript_WakeFriend_23:
# 158 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end

InsideOfTruck_EventScript_WakeFriend_3:
# 93 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_JumpDown
	goto InsideOfTruck_EventScript_WakeFriend_1

InsideOfTruck_EventScript_WakeFriend_4:
# 95 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_JumpRight
	goto InsideOfTruck_EventScript_WakeFriend_1

InsideOfTruck_EventScript_WakeFriend_7:
# 102 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_15
InsideOfTruck_EventScript_WakeFriend_14:
# 106 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_28
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_8:
# 111 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_18
InsideOfTruck_EventScript_WakeFriend_17:
# 115 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_30
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_9:
# 120 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_21
InsideOfTruck_EventScript_WakeFriend_20:
# 124 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_32
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_12:
# 133 "data/maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 134 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_LeaveTruck1
	goto InsideOfTruck_EventScript_WakeFriend_10

InsideOfTruck_EventScript_WakeFriend_13:
# 136 "data/maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, InsideOfTruck_Movement_PlayerFaceFreindLeaving
# 137 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_LeaveTruck2
	goto InsideOfTruck_EventScript_WakeFriend_10

InsideOfTruck_EventScript_WakeFriend_15:
# 103 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 104 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_14

InsideOfTruck_EventScript_WakeFriend_18:
# 112 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 113 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_17

InsideOfTruck_EventScript_WakeFriend_21:
# 121 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 122 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_20

InsideOfTruck_EventScript_WakeFriend_25:
# 152 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_26:
# 154 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_27:
# 156 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_28:
# 107 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 108 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_30:
# 116 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 117 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_32:
# 125 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 126 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5


# 162 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpDown:
# 163 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_down
	step_end

# 166 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpRight:
# 167 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_right
	step_end

# 170 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck1:
# 171 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 171 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 171 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 172 "data/maps/InsideOfTruck/scripts.pory"
	set_invisible
	step_end

# 175 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck2:
# 176 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_down
# 177 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 177 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 177 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 178 "data/maps/InsideOfTruck/scripts.pory"
	set_invisible
	step_end

# 181 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_PlayerFaceFreindLeaving:
# 182 "data/maps/InsideOfTruck/scripts.pory"
	delay_8
# 183 "data/maps/InsideOfTruck/scripts.pory"
	face_right
	step_end

InsideOfTruck_Text_BoxPrintedWithMonLogo::
# 186 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_FriendAwake::
# 190 "data/maps/InsideOfTruck/scripts.pory"
	.string "HUH?\nWAZZAT?!\p"
	.string "...Oh, it's just you, {PLAYER}.\n"
	.string "I must have fallen asleep\l"
	.string "along the way.$"

InsideOfTruck_Text_BetSpencerHasPokemonAlready::
# 197 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet SPENCER has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetBrenHasPokemonAlready::
# 207 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet BREN has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetKyleHasPokemonAlready::
# 217 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet KYLE has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"
