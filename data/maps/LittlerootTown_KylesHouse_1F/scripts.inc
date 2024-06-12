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
# 51 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 75 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 1, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4
# 99 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_5
# 103 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_KYLE, 18, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
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
	special TurnOnTVScreen
# 47 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, KYLE
# 48 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 49 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3:
# 52 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 53 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_PIN
# 54 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 55 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 57 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 58 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 59 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach
# 60 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 61 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 62 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighborKyle, MSGBOX_DEFAULT
# 63 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 64 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 65 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 66 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	checkfriendchoice
# 67 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_RESULT
# 68 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case SPENCER, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3
# 70 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case BREN, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4
LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1:
# 73 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3:
# 69 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4:
# 71 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4:
# 76 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 77 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_PIN
# 78 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 79 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 80 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 81 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 82 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 83 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach
# 84 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 85 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 86 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighborKyle, MSGBOX_DEFAULT
# 87 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 88 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 89 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 90 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	checkfriendchoice
# 91 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_RESULT
# 92 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case SPENCER, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_3
# 94 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case BREN, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_4
LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_1:
# 97 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_3:
# 93 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_4:
# 95 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_5:
# 100 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 19
# 101 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	return


LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual::
# 110 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	checkfriendchoice
# 111 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual_1
	return

LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual_1:
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return


LittlerootTown_KylesHouse_1F_EventScript_GoSeeRoom::
# 117 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 118 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 119 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 120 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 121 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 122 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


# 126 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs:
# 127 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 130 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach:
# 131 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_down
# 132 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 132 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 132 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 132 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 132 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
	step_end
