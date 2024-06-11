LittlerootTown_BrendansHouse_1F_MapScripts::
# 6 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD
# 13 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 27 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_lt LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2
LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 11 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 8 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 9 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	goto LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 14 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_LITTLEROOT_INTRO_STATE
# 15 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 4, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 18 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 6, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 21 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 7, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 16 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm 1, 9, 8
# 17 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 19 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm 1, 8, 4
# 20 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 22 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectxyperm 1, 4, 5
# 23 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
# 24 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special TurnOnTVScreen
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 28 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
# 34 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
# 45 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2
# 51 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 1, LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 67 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 29 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 30 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 31 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, SPENCER
# 32 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 35 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 36 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 37 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 38 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 39 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 1, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
# 40 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
# 42 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitstate
# 43 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2:
# 46 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 47 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, MALE
# 48 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 49 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	return

LittlerootTown_BrendansHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3:
# 52 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 53 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 54 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 55 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 57 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 58 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 59 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
# 60 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 61 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 62 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 63 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 64 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 65 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	return


LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
# 75 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	checkfriendchoice
# 76 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual_2
LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual_1:
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual_2:
# 77 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	goto LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual_1


LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
# 83 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 84 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 85 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 86 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 87 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 88 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
# 93 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 94 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 95 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
# 100 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 101 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 102 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
# 107 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	lockall
# 108 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 109 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end


LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
# 114 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 115 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 10
# 116 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	addobject 6
# 117 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 118 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_PIN
# 119 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, Common_Movement_ExclamationMark
# 120 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 121 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, Common_Movement_Delay48
# 122 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 123 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_ne LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_2
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_1:
# 127 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 128 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_0x8008
# 129 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 0, LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_6
# 131 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 1, LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_7
# 133 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 2, LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_8
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_4:
# 136 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 137 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
# 138 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	closemessage
# 139 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	switch VAR_0x8008
# 140 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 0, LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_11
# 143 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 1, LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_12
# 146 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	case 2, LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_13
LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_9:
# 150 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
# 151 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	playse SE_EXIT
# 152 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	removeobject 6
# 153 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
# 154 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 155 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay 30
# 156 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 157 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 158 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 159 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	fadedefaultbgm
# 160 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_2:
# 124 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 125 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	waitmovement 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_1

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_6:
# 130 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_4

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_7:
# 132 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_4

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_8:
# 134 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_4

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_11:
# 141 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
# 142 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_9

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_12:
# 144 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
# 145 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_9

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_13:
# 147 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
# 148 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival_9


# 164 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
# 165 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

# 167 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
# 168 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_down
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 169 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
	step_end

# 172 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
# 173 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 174 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 175 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 176 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

# 179 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
# 180 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 180 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 180 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

# 183 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
# 184 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 185 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 186 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 187 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

# 190 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
# 191 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 192 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 193 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
	step_end

# 196 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
# 197 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 198 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 199 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 200 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 200 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 201 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
	step_end

# 204 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
# 205 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_16
# 206 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	delay_8
# 207 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 210 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
# 211 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 212 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 213 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 214 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 214 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

# 217 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
# 218 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 219 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_right
# 220 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 221 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 221 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 222 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 223 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 224 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 225 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

# 228 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
# 229 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 230 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_left
# 231 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 232 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
# 232 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere::
# 235 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock::
# 240 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom::
# 251 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"

PlayersHouse_1F_Text_GoSetTheClock::
# 257 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_OhComeQuickly::
# 262 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn::
# 267 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim::
# 272 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor::
# 278 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. BIRCH is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"

PlayersHouse_1F_Text_SeeYouHoney::
# 286 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch::
# 290 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit::
# 295 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_TakeCareHoney::
# 301 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Take care, honey!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom::
# 305 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard::
# 310 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav::
# 316 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom::
# 324 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1::
# 329 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2::
# 333 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym::
# 337 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV::
# 342 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual::
# 349 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou::
# 358 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove::
# 370 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym::
# 376 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger::
# 382 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory::
# 389 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash::
# 393 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay::
# 405 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon::
# 411 "data/maps/LittlerootTown_BrendansHouse_1F/scripts.pory"
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
