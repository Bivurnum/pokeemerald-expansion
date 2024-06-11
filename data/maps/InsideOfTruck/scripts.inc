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
	checkfriendchoice
# 26 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 27 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_SetIntroFlags_3
# 29 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_SetIntroFlags_4
# 31 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_SetIntroFlags_5
InsideOfTruck_EventScript_SetIntroFlags_1:
	end

InsideOfTruck_EventScript_SetIntroFlags_3:
# 28 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsSpencer
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_4:
# 30 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsBren
	goto InsideOfTruck_EventScript_SetIntroFlags_1

InsideOfTruck_EventScript_SetIntroFlags_5:
# 32 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SetIntroFlagsKyle
	goto InsideOfTruck_EventScript_SetIntroFlags_1


InsideOfTruck_EventScript_SetIntroFlagsSpencer::
# 38 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 39 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 40 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 41 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_RIVAL_MOM
# 42 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 43 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1
# 44 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 45 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsBren::
# 50 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 51 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 52 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 53 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_RIVAL_MOM
# 54 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_MOM
# 55 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 1
# 56 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 57 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_SetIntroFlagsKyle::
# 62 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_KYLES_HOUSE_2F
# 63 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
# 64 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_MOM
# 65 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_MOM
# 66 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_RIVAL_MOM
# 67 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 1
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
	lock
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
	checkfriendchoice
# 100 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/InsideOfTruck/scripts.pory"
	case SPENCER, InsideOfTruck_EventScript_WakeFriend_7
# 112 "data/maps/InsideOfTruck/scripts.pory"
	case BREN, InsideOfTruck_EventScript_WakeFriend_8
# 123 "data/maps/InsideOfTruck/scripts.pory"
	case KYLE, InsideOfTruck_EventScript_WakeFriend_9
InsideOfTruck_EventScript_WakeFriend_5:
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
	setflag FLAG_HIDE_SPENCER_IN_TRUCK
# 149 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_BREN_IN_TRUCK
# 150 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_KYLE_IN_TRUCK
# 151 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 152 "data/maps/InsideOfTruck/scripts.pory"
	release
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
# 107 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_23
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_8:
# 113 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_18
InsideOfTruck_EventScript_WakeFriend_17:
# 118 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 6
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_25
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_9:
# 124 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 4
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_21
InsideOfTruck_EventScript_WakeFriend_20:
# 129 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_0x8009, 5
	goto_if_eq InsideOfTruck_EventScript_WakeFriend_27
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
# 103 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 104 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
# 105 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_14

InsideOfTruck_EventScript_WakeFriend_18:
# 114 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 115 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
# 116 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetKyleHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_17

InsideOfTruck_EventScript_WakeFriend_21:
# 125 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 126 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 127 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_20

InsideOfTruck_EventScript_WakeFriend_23:
# 108 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 109 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 110 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetBrenHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_25:
# 119 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 120 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 121 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5

InsideOfTruck_EventScript_WakeFriend_27:
# 130 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 131 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 132 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BetSpencerHasPokemonAlready, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_WakeFriend_5


# 156 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpDown:
# 157 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_down
	step_end

# 160 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_JumpRight:
# 161 "data/maps/InsideOfTruck/scripts.pory"
	jump_in_place_right
	step_end

# 164 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck1:
# 165 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 165 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 165 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_right
# 166 "data/maps/InsideOfTruck/scripts.pory"
	set_invisible
	step_end

# 169 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Movement_LeaveTruck2:
# 170 "data/maps/InsideOfTruck/scripts.pory"
	walk_fast_down
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
InsideOfTruck_Movement_PlayerFaceFreindLeaving:
# 176 "data/maps/InsideOfTruck/scripts.pory"
	delay_8
# 177 "data/maps/InsideOfTruck/scripts.pory"
	face_right
	step_end

InsideOfTruck_Text_BoxPrintedWithMonLogo::
# 180 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_FriendAwake::
# 184 "data/maps/InsideOfTruck/scripts.pory"
	.string "HUH?\p WAZZAT?!\n"
	.string "...Oh, it's just you, {PLAYER}.\l"
	.string "I must have fallen asleep\l"
	.string "along the way.$"

InsideOfTruck_Text_BetSpencerHasPokemonAlready::
# 191 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\p"
	.string "We were all supposed to get our first\n"
	.string "POKéMON from PROF. BIRCH today!\l"
	.string "I'll bet Spencer has gotten his already..\n"
	.string "We'd better get going before it's\n"
	.string "too late!\n"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetBrenHasPokemonAlready::
# 201 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\p"
	.string "We were all supposed to get our first\n"
	.string "POKéMON from PROF. BIRCH today!\l"
	.string "I'll bet Bren has gotten his already..\n"
	.string "We'd better get going before it's\n"
	.string "too late!\n"
	.string "C'mon! I'll race you!$"

InsideOfTruck_Text_BetKyleHasPokemonAlready::
# 211 "data/maps/InsideOfTruck/scripts.pory"
	.string "Crud! That's right!\p"
	.string "We were all supposed to get our first\n"
	.string "POKéMON from PROF. BIRCH today!\l"
	.string "I'll bet Kyle has gotten his already..\n"
	.string "We'd better get going before it's\n"
	.string "too late!\n"
	.string "C'mon! I'll race you!$"
