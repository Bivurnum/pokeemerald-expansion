InsideOfTruck_MapScripts::
# 11 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
# 12 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
# 6 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, InsideOfTruck_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

InsideOfTruck_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/InsideOfTruck/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 8, InsideOfTruck_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

InsideOfTruck_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 8 "data/maps/InsideOfTruck/scripts.pory"
	playbgm MUS_FORTREE, TRUE
	return


InsideOfTruck_OnLoad::
# 16 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
# 17 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
# 18 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end


InsideOfTruck_OnResume::
# 23 "data/maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
	end


InsideOfTruck_EventScript_SetIntroFlags::
# 28 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 29 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 30 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1
# 31 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 1
# 32 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 1
# 33 "data/maps/InsideOfTruck/scripts.pory"
	checkfriendchoice
# 34 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 35 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_SetIntroFlags_3
# 37 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_SetIntroFlags_4
# 39 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_SetIntroFlags_5
InsideOfTruck_EventScript_SetIntroFlags_1:
	end

InsideOfTruck_EventScript_SetIntroFlags_3:
# 36 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsSpencer
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_4:
# 38 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsBren
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_5:
# 40 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsKyle
	goto InsideOfTruck_EventScript_SetIntroFlags_1


InsideOfTruck_EventScript_SetIntroFlagsSpencer::
# 46 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 47 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 48 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 49 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_RIVAL_MOM
# 50 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 51 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 52 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsBren::
# 57 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 58 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 59 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 60 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_RIVAL_MOM
# 61 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 62 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 63 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsKyle::
# 68 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_KYLES_HOUSE_2F
# 69 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 70 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 71 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 72 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_RIVAL_MOM
# 73 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
# 74 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_MovingBox::
# 79 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end


InsideOfTruck_EventScript_WakeFriend::
# 84 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 85 "data/maps/InsideOfTruck/scripts.pory"
	delay 15
# 86 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_PIN
# 87 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
# 88 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 89 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 90 "data/maps/InsideOfTruck/scripts.pory"
	faceplayer
# 91 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_FriendAwake, MSGBOX_DEFAULT
# 92 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 93 "data/maps/InsideOfTruck/scripts.pory"
	delay 15
# 94 "data/maps/InsideOfTruck/scripts.pory"
	getplayerxy VAR_0x8006, VAR_0x8007
# 95 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_LEDGE
# 96 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8006
# 97 "data/maps/InsideOfTruck/scripts.pory"
	case 1, InsideOfTruck_EventScript_WakeFriend_3
# 99 "data/maps/InsideOfTruck/scripts.pory"
	case 2, InsideOfTruck_EventScript_WakeFriend_4
InsideOfTruck_EventScript_WakeFriend_1:
# 102 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 103 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 104 "data/maps/InsideOfTruck/scripts.pory"
	checkfriendchoice
# 105 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_WakeFriend_7
# 115 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_WakeFriend_8
# 124 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_WakeFriend_9
InsideOfTruck_EventScript_WakeFriend_5:
# 134 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 135 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 136 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8006
# 137 "data/maps/InsideOfTruck/scripts.pory"
	case 1, InsideOfTruck_EventScript_WakeFriend_12
# 140 "data/maps/InsideOfTruck/scripts.pory"
	case 2, InsideOfTruck_EventScript_WakeFriend_13
InsideOfTruck_EventScript_WakeFriend_10:
# 144 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 145 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_EXIT
# 146 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 147 "data/maps/InsideOfTruck/scripts.pory"
	removeobject VAR_0x8009
# 148 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 149 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 150 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 151 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_SPENCER_IN_TRUCK
# 152 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_BREN_IN_TRUCK
# 153 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_KYLE_IN_TRUCK
# 154 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 155 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8009
# 156 "data/maps/InsideOfTruck/scripts.pory"
	case 4, InsideOfTruck_EventScript_WakeFriend_25
# 158 "data/maps/InsideOfTruck/scripts.pory"
	case 5, InsideOfTruck_EventScript_WakeFriend_26
# 160 "data/maps/InsideOfTruck/scripts.pory"
	case 6, InsideOfTruck_EventScript_WakeFriend_27
InsideOfTruck_EventScript_WakeFriend_23:
# 163 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end

InsideOfTruck_EventScript_WakeFriend_3:
# 98 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_JumpDown
	goto InsideOfTruck_EventScript_WakeFriend_1

InsideOfTruck_EventScript_WakeFriend_4:
# 100 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_JumpRight
	goto InsideOfTruck_EventScript_WakeFriend_1

InsideOfTruck_EventScript_WakeFriend_7:
# 107 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_15
InsideOfTruck_EventScript_WakeFriend_14:
# 111 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_28
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_8:
# 116 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_18
InsideOfTruck_EventScript_WakeFriend_17:
# 120 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_30
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_9:
# 125 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_21
InsideOfTruck_EventScript_WakeFriend_20:
# 129 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_32
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_12:
# 138 "data/maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 139 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_LeaveTruck1
	goto InsideOfTruck_EventScript_WakeFriend_10

InsideOfTruck_EventScript_WakeFriend_13:
# 141 "data/maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, InsideOfTruck_Movement_PlayerFaceFreindLeaving
# 142 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_LeaveTruck2
	goto InsideOfTruck_EventScript_WakeFriend_10

InsideOfTruck_EventScript_WakeFriend_15:
# 108 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 109 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_14

InsideOfTruck_EventScript_WakeFriend_18:
# 117 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 118 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_17

InsideOfTruck_EventScript_WakeFriend_21:
# 126 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 127 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_20

InsideOfTruck_EventScript_WakeFriend_25:
# 157 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_26:
# 159 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_27:
# 161 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_28:
# 112 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 113 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_30:
# 121 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 122 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_32:
# 130 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 131 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5


# 167 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpDown:
# 168 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_down
	step_end

# 171 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpRight:
# 172 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_right
	step_end

# 175 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck1:
# 176 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 176 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 176 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 177 "data/maps/InsideOfTruck/scripts.pory"
	set_invisible
	step_end

# 180 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck2:
# 181 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_down
# 182 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 182 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 182 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 183 "data/maps/InsideOfTruck/scripts.pory"
	set_invisible
	step_end

# 186 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_PlayerFaceFreindLeaving:
# 187 "data/maps/InsideOfTruck/scripts.pory"
	delay_8
# 188 "data/maps/InsideOfTruck/scripts.pory"
	face_right
	step_end

InsideOfTruck_Text_BoxPrintedWithMonLogo::
# 191 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_FriendAwake::
# 195 "data/maps/InsideOfTruck/scripts.pory"
	.string "HUH?\nWAZZAT?!\p"
	.string "...Oh, it's just you, {PLAYER}.\n"
	.string "I must have fallen asleep\l"
	.string "along the way.$"

InsideOfTruck_Text_BetSpencerHasPokemonAlready::
# 202 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet SPENCER has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetBrenHasPokemonAlready::
# 212 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet BREN has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetKyleHasPokemonAlready::
# 222 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet KYLE has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"
