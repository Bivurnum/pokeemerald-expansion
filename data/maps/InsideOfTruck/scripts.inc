InsideOfTruck_MapScripts::
# 6 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
# 7 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
# 8 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InsideOfTruck_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

InsideOfTruck_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/InsideOfTruck/scripts.pory"
	map_script_2 VAR_PLAY_TRUCK_MUSIC, 1, InsideOfTruck_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

InsideOfTruck_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 10 "data/maps/InsideOfTruck/scripts.pory"
	playbgm MUS_FORTREE, FALSE
# 11 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_PLAY_TRUCK_MUSIC, 2
	return


InsideOfTruck_OnLoad::
# 17 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
# 18 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
# 19 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end


InsideOfTruck_OnResume::
# 24 "data/maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
	end


InsideOfTruck_EventScript_SetIntroFlags::
# 29 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 30 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 31 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1
# 32 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 1
# 33 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 1
# 34 "data/maps/InsideOfTruck/scripts.pory"
	checkfriendchoice
# 35 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 36 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_SetIntroFlags_3
# 38 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_SetIntroFlags_4
# 40 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_SetIntroFlags_5
InsideOfTruck_EventScript_SetIntroFlags_1:
	end

InsideOfTruck_EventScript_SetIntroFlags_3:
# 37 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsSpencer
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_4:
# 39 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsBren
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_5:
# 41 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsKyle
	goto InsideOfTruck_EventScript_SetIntroFlags_1


InsideOfTruck_EventScript_SetIntroFlagsSpencer::
# 47 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 48 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 49 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 50 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_RIVAL_MOM
# 51 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 52 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 53 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsBren::
# 58 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 59 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 60 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 61 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_RIVAL_MOM
# 62 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 63 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 64 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsKyle::
# 69 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_KYLES_HOUSE_2F
# 70 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 71 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 72 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 73 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_RIVAL_MOM
# 74 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
# 75 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_MovingBox::
# 80 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end


InsideOfTruck_EventScript_WakeFriend::
# 85 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 86 "data/maps/InsideOfTruck/scripts.pory"
	delay 15
# 87 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_PIN
# 88 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
# 89 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 90 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 91 "data/maps/InsideOfTruck/scripts.pory"
	faceplayer
# 92 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_FriendAwake, MSGBOX_DEFAULT
# 93 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 94 "data/maps/InsideOfTruck/scripts.pory"
	delay 15
# 95 "data/maps/InsideOfTruck/scripts.pory"
	getplayerxy VAR_0x8006, VAR_0x8007
# 96 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8006
# 98 "data/maps/InsideOfTruck/scripts.pory"
	case 1, InsideOfTruck_EventScript_WakeFriend_3
# 100 "data/maps/InsideOfTruck/scripts.pory"
	case 2, InsideOfTruck_EventScript_WakeFriend_4
InsideOfTruck_EventScript_WakeFriend_1:
# 103 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 104 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 105 "data/maps/InsideOfTruck/scripts.pory"
	checkfriendchoice
# 106 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 107 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_WakeFriend_7
# 116 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_WakeFriend_8
# 125 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_WakeFriend_9
InsideOfTruck_EventScript_WakeFriend_5:
# 135 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 136 "data/maps/InsideOfTruck/scripts.pory"
	closemessage
# 137 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8006
# 138 "data/maps/InsideOfTruck/scripts.pory"
	case 1, InsideOfTruck_EventScript_WakeFriend_12
# 141 "data/maps/InsideOfTruck/scripts.pory"
	case 2, InsideOfTruck_EventScript_WakeFriend_13
InsideOfTruck_EventScript_WakeFriend_10:
# 145 "data/maps/InsideOfTruck/scripts.pory"
	waitmovement 0
# 146 "data/maps/InsideOfTruck/scripts.pory"
	playse SE_EXIT
# 147 "data/maps/InsideOfTruck/scripts.pory"
	waitse
# 148 "data/maps/InsideOfTruck/scripts.pory"
	removeobject VAR_0x8009
# 149 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 150 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 151 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 152 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_SPENCER_IN_TRUCK
# 153 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_BREN_IN_TRUCK
# 154 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_KYLE_IN_TRUCK
# 155 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 156 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_0x8009
# 157 "data/maps/InsideOfTruck/scripts.pory"
	case 4, InsideOfTruck_EventScript_WakeFriend_25
# 159 "data/maps/InsideOfTruck/scripts.pory"
	case 5, InsideOfTruck_EventScript_WakeFriend_26
# 161 "data/maps/InsideOfTruck/scripts.pory"
	case 6, InsideOfTruck_EventScript_WakeFriend_27
InsideOfTruck_EventScript_WakeFriend_23:
# 164 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end

InsideOfTruck_EventScript_WakeFriend_3:
# 99 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_JumpDown
	goto InsideOfTruck_EventScript_WakeFriend_1

InsideOfTruck_EventScript_WakeFriend_4:
# 101 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_JumpRight
	goto InsideOfTruck_EventScript_WakeFriend_1

InsideOfTruck_EventScript_WakeFriend_7:
# 108 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_15
InsideOfTruck_EventScript_WakeFriend_14:
# 112 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_28
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_8:
# 117 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_18
InsideOfTruck_EventScript_WakeFriend_17:
# 121 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_30
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_9:
# 126 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_21
InsideOfTruck_EventScript_WakeFriend_20:
# 130 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_32
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_12:
# 139 "data/maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 140 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_LeaveTruck1
	goto InsideOfTruck_EventScript_WakeFriend_10

InsideOfTruck_EventScript_WakeFriend_13:
# 142 "data/maps/InsideOfTruck/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, InsideOfTruck_Movement_PlayerFaceFreindLeaving
# 143 "data/maps/InsideOfTruck/scripts.pory"
	applymovement VAR_0x8009, InsideOfTruck_Movement_LeaveTruck2
	goto InsideOfTruck_EventScript_WakeFriend_10

InsideOfTruck_EventScript_WakeFriend_15:
# 109 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 110 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_14

InsideOfTruck_EventScript_WakeFriend_18:
# 118 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 119 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_17

InsideOfTruck_EventScript_WakeFriend_21:
# 127 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 128 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_20

InsideOfTruck_EventScript_WakeFriend_25:
# 158 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_26:
# 160 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_27:
# 162 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto InsideOfTruck_EventScript_WakeFriend_23

InsideOfTruck_EventScript_WakeFriend_28:
# 113 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 114 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_30:
# 122 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 123 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_32:
# 131 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 132 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5


# 168 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpDown:
# 169 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_down
	step_end

# 172 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpRight:
# 173 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_right
	step_end

# 176 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck1:
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
InsideOfTruck_Movement_LeaveTruck2:
# 182 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_down
# 183 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 183 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 183 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 184 "data/maps/InsideOfTruck/scripts.pory"
	set_invisible
	step_end

# 187 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_PlayerFaceFreindLeaving:
# 188 "data/maps/InsideOfTruck/scripts.pory"
	delay_8
# 189 "data/maps/InsideOfTruck/scripts.pory"
	face_right
	step_end

InsideOfTruck_Text_BoxPrintedWithMonLogo::
# 192 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_FriendAwake::
# 196 "data/maps/InsideOfTruck/scripts.pory"
	.string "HUH?\nWAZZAT?!\p"
	.string "...Oh, it's just you, {PLAYER}.\n"
	.string "I must have fallen asleep\l"
	.string "along the way.$"

InsideOfTruck_Text_BetSpencerHasPokemonAlready::
# 203 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet SPENCER has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetBrenHasPokemonAlready::
# 213 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet BREN has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetKyleHasPokemonAlready::
# 223 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\n"
	.string "We were all supposed to get our first\l"
	.string "POKéMON from PROF. BIRCH today!\p"
	.string "I'll bet KYLE has gotten his already..\n"
	.string "We'd better get going before it's\l"
	.string "too late!\p"
	.string "C'mon! I'll race you!$"
