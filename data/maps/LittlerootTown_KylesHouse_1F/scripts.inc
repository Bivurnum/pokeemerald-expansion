LittlerootTown_KylesHouse_1F_MapScripts::
# 7 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD
# 14 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 27 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 8 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_lt LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2
LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 12 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 9 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 10 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 15 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_LITTLEROOT_INTRO_STATE
# 16 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 4, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 19 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 6, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 22 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case 7, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 17 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectxyperm 1, 1, 8
# 18 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 20 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectxyperm 1, 2, 4
# 21 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 23 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectxyperm 1, 6, 5
# 24 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 28 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
# 34 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
# 45 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2
# 52 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_KYLE, 1, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 77 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 4, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4
# 83 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_KYLE, 18, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 29 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 30 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 31 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, KYLE
# 32 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 35 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 36 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 37 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	closemessage
# 38 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs
# 39 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 1, LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs
# 40 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_KYLES_HOUSE_2F, 1, 1
# 42 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitstate
# 43 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2:
# 46 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 47 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	special TurnOnTVScreen
# 48 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, KYLE
# 49 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 50 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3:
# 53 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 54 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	playse SE_PIN
# 55 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 56 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 58 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 59 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 60 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach
# 61 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 62 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 63 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighborKyle, MSGBOX_DEFAULT
# 64 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 65 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 66 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 67 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 68 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	checkfriendchoice
# 69 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	switch VAR_RESULT
# 70 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case SPENCER, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3
# 72 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	case BREN, LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4
LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1:
# 75 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3:
# 71 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4:
# 73 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
	goto LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_KylesHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4:
# 78 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 5
# 79 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 80 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 81 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
	return


LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual::
# 90 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	checkfriendchoice
# 91 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual_1
	return

LittlerootTown_KylesHouse_1F_EventScript_CheckShowShoesManual_1:
# 92 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return


LittlerootTown_KylesHouse_1F_EventScript_GoSeeRoom::
# 97 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	lockall
# 98 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 99 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 100 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 101 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	waitmovement 0
# 102 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


# 106 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_PushTowardStairs:
# 107 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_up
	step_end

# 110 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
LittlerootTown_KylesHouse_1F_Movement_RivalMomApproach:
# 111 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_down
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
# 112 "data/maps/LittlerootTown_KylesHouse_1F/scripts.pory"
	walk_left
	step_end
