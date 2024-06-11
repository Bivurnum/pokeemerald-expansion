LittlerootTown_KylesHouse_1F_MapScripts::
# 6 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD
# 13 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 26 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_lt LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2
LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 11 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 8 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 9 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 14 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_LITTLEROOT_INTRO_STATE
# 15 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 4, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 18 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 6, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 21 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 7, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 16 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectxyperm 1, 1, 8
# 17 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 19 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectxyperm 1, 2, 4
# 20 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 22 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectxyperm 1, 6, 5
# 23 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 27 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
# 33 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
# 44 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2
# 50 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 66 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 28 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 29 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 30 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, KYLE
# 31 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 34 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 35 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 36 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	closemessage
# 37 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs
# 38 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 1, LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs
# 39 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 40 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_KYLES_HOUSE_2F, 1, 1
# 41 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitstate
# 42 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2:
# 45 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 46 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, KYLE
# 47 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 48 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3:
# 51 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 52 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_PIN
# 53 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 54 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 55 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 56 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 58 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach
# 59 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 60 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 61 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 62 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 63 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 64 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	return


LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual::
# 73 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	checkfriendchoice
# 74 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual_1
	return

LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual_1:
# 75 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return


LittlerootTown_KylesHouse_1F_EventScript_GoSeeRoom::
# 80 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 81 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 82 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 83 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 84 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 85 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


LittlerootTown_KylesHouse_1F_EventScript_MeetRival0::
# 90 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 91 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 92 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival
	end


LittlerootTown_KylesHouse_1F_EventScript_MeetRival1::
# 97 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 98 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 99 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival
	end


LittlerootTown_KylesHouse_1F_EventScript_MeetRival2::
# 104 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 105 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 106 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival
	end


LittlerootTown_KylesHouse_1F_EventScript_MeetRival::
# 111 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_EXIT
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay 10
# 113 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	addobject 6
# 114 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay 30
# 115 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_PIN
# 116 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, Common_Movement_ExclamationMark
# 117 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 118 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, Common_Movement_Delay48
# 119 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 120 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_ne LittlerootTown_KylesHouse_1F_EventScript_MeetRival_2
LittlerootTown_KylesHouse_1F_EventScript_MeetRival_1:
# 124 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 125 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_0x8008
# 126 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 0, LittlerootTown_KylesHouse_1F_EventScript_MeetRival_6
# 128 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 1, LittlerootTown_KylesHouse_1F_EventScript_MeetRival_7
# 130 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 2, LittlerootTown_KylesHouse_1F_EventScript_MeetRival_8
LittlerootTown_KylesHouse_1F_EventScript_MeetRival_4:
# 133 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 134 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 135 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	closemessage
# 136 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_0x8008
# 137 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 0, LittlerootTown_KylesHouse_1F_EventScript_MeetRival_11
# 140 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 1, LittlerootTown_KylesHouse_1F_EventScript_MeetRival_12
# 143 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 2, LittlerootTown_KylesHouse_1F_EventScript_MeetRival_13
LittlerootTown_KylesHouse_1F_EventScript_MeetRival_9:
# 147 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 148 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_EXIT
# 149 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	removeobject 6
# 150 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
# 151 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 152 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay 30
# 153 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 154 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 155 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 156 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	fadedefaultbgm
# 157 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	end

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_2:
# 121 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 122 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_1

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_6:
# 127 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_KylesHouse_1F_Movement_MayApproachPlayer0
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_4

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_7:
# 129 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_KylesHouse_1F_Movement_MayApproachPlayer1
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_4

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_8:
# 131 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_KylesHouse_1F_Movement_MayApproachPlayer2
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_4

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_11:
# 138 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_KylesHouse_1F_Movement_PlayerWatchMayExit0
# 139 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_KylesHouse_1F_Movement_MayGoUpstairs0
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_9

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_12:
# 141 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_KylesHouse_1F_Movement_PlayerWatchMayExit1
# 142 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_KylesHouse_1F_Movement_MayGoUpstairs1
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_9

LittlerootTown_KylesHouse_1F_EventScript_MeetRival_13:
# 144 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_KylesHouse_1F_Movement_PlayerWatchMayExit2
# 145 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_KylesHouse_1F_Movement_MayGoUpstairs2
	goto LittlerootTown_KylesHouse_1F_EventScript_MeetRival_9


# 161 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs:
# 162 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 165 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach:
# 166 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_down
# 167 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 167 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 167 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 167 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 167 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
	step_end

# 170 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_MayApproachPlayer0:
# 171 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 172 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 173 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 174 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 174 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 174 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 174 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 177 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_MayApproachPlayer1:
# 178 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 178 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 178 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 181 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_MayApproachPlayer2:
# 182 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 183 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_right
# 184 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 185 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 185 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 188 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_PlayerWatchMayExit0:
# 189 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_16
# 190 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_8
# 191 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_right
	step_end

# 194 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_PlayerWatchMayExit1:
# 195 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_16
# 196 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_8
# 197 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 198 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_16
# 198 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_16
# 199 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
	step_end

# 202 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_PlayerWatchMayExit2:
# 203 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_16
# 204 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	delay_8
# 205 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 208 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_MayGoUpstairs0:
# 209 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 210 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_right
# 211 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 212 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 212 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 215 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_MayGoUpstairs1:
# 216 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 217 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_right
# 218 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 219 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 219 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 220 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 221 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 222 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 223 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 226 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_MayGoUpstairs2:
# 227 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 228 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 229 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 230 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
# 230 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end
