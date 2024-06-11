LittlerootTown_MaysHouse_1F_MapScripts::
# 6 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD
# 13 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 26 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
# 7 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_lt LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2
LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
# 11 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
# 8 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 9 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	goto LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 14 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_LITTLEROOT_INTRO_STATE
# 15 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 4, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 18 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 6, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
# 21 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 7, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 16 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm 1, 1, 8
# 17 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 19 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm 1, 2, 4
# 20 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 22 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectxyperm 1, 6, 5
# 23 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 27 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
# 33 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1
# 44 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2
# 50 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 1, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 66 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
# 28 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 29 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 30 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, BREN
# 31 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_1:
# 34 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 35 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
# 36 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 37 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 38 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 1, LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs
# 39 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 40 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 1, 1
# 41 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitstate
# 42 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_2:
# 45 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 46 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, FEMALE
# 47 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 48 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3:
# 51 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 52 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 53 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 54 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 55 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 56 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 58 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
# 59 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 60 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 61 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	return


LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
# 73 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkfriendchoice
# 74 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual_1
	return

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual_1:
# 75 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return


RivalsHouse_1F_EventScript_RivalMom::
# 80 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 81 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 82 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 83 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 84 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_eq RivalsHouse_1F_EventScript_RivalMom_2
# 89 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 90 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
# 91 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

RivalsHouse_1F_EventScript_RivalMom_2:
# 85 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


RivalsHouse_1F_EventScript_GoHomeEverySoOften::
# 96 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 97 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


RivalsHouse_1F_EventScript_RivalIsOnRoute103::
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
# 108 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 109 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 113 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


LittlerootTown_MaysHouse_1F_EventScript_MeetRival0::
# 118 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 119 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 0
# 120 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end


LittlerootTown_MaysHouse_1F_EventScript_MeetRival1::
# 125 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end


LittlerootTown_MaysHouse_1F_EventScript_MeetRival2::
# 132 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 133 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 134 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival
	end


LittlerootTown_MaysHouse_1F_EventScript_MeetRival::
# 139 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 140 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 10
# 141 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	addobject 6
# 142 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 143 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 144 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, Common_Movement_ExclamationMark
# 145 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 146 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, Common_Movement_Delay48
# 147 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 148 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_ne LittlerootTown_MaysHouse_1F_EventScript_MeetRival_2
LittlerootTown_MaysHouse_1F_EventScript_MeetRival_1:
# 152 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 153 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_0x8008
# 154 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 0, LittlerootTown_MaysHouse_1F_EventScript_MeetRival_6
# 156 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 1, LittlerootTown_MaysHouse_1F_EventScript_MeetRival_7
# 158 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 2, LittlerootTown_MaysHouse_1F_EventScript_MeetRival_8
LittlerootTown_MaysHouse_1F_EventScript_MeetRival_4:
# 161 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MayWhoAreYou, MSGBOX_DEFAULT
# 163 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	closemessage
# 164 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_0x8008
# 165 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 0, LittlerootTown_MaysHouse_1F_EventScript_MeetRival_11
# 168 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 1, LittlerootTown_MaysHouse_1F_EventScript_MeetRival_12
# 171 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 2, LittlerootTown_MaysHouse_1F_EventScript_MeetRival_13
LittlerootTown_MaysHouse_1F_EventScript_MeetRival_9:
# 175 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 176 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_EXIT
# 177 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	removeobject 6
# 178 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
# 179 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 180 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay 30
# 181 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
# 182 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 183 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	savebgm MUS_DUMMY
# 184 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	fadedefaultbgm
# 185 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_2:
# 149 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 150 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_1

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_6:
# 155 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_4

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_7:
# 157 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_4

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_8:
# 159 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_4

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_11:
# 166 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
# 167 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_9

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_12:
# 169 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
# 170 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_9

LittlerootTown_MaysHouse_1F_EventScript_MeetRival_13:
# 172 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
# 173 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 6, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
	goto LittlerootTown_MaysHouse_1F_EventScript_MeetRival_9


# 189 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
# 190 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 193 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
# 194 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 195 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
	step_end

# 198 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0:
# 199 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 200 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 201 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 202 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 202 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 205 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1:
# 206 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 206 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 206 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 209 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2:
# 210 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 211 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 212 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 213 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 213 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 216 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
# 217 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 218 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 219 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
	step_end

# 222 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
# 223 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 224 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 225 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 226 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 226 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 227 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
	step_end

# 230 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
# 231 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_16
# 232 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	delay_8
# 233 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
	step_end

# 236 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
# 237 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 238 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 239 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 240 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 240 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 243 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
# 244 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_right
# 245 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_right
# 246 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 247 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 247 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 248 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 249 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 250 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 251 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 254 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
# 255 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_left
# 256 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 257 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_in_place_faster_up
# 258 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
# 258 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

RivalsHouse_1F_Text_OhYoureTheNewNeighbor::
# 261 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello. And you are?\p"
	.string "… … … … … … … … …\n"
	.string "… … … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}, our new next-door\n"
	.string "neighbor! Hi!\p"
	.string "We have a {STR_VAR_1} about the same\n"
	.string "age as you.\p"
	.string "Our {STR_VAR_1} was excited about making\n"
	.string "a new friend.\p"
	.string "Our {STR_VAR_1} is upstairs, I think.$"

RivalsHouse_1F_Text_LikeChildLikeFather::
# 274 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Like child, like father.\p"
	.string "My husband is as wild about POKéMON\n"
	.string "as our child.\p"
	.string "If he's not at his LAB, he's likely\n"
	.string "scrabbling about in grassy places.$"

RivalsHouse_1F_Text_TooBusyToNoticeVisit::
# 282 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
	.string "I guess our child is too busy with\n"
	.string "POKéMON to notice that you came\l"
	.string "to visit, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_WentOutToRoute103::
# 289 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
	.string "just a little while ago.\p"
	.string "Like father, like child.\n"
	.string "{RIVAL} can't stay quietly at home.$"

RivalsHouse_1F_Text_ShouldGoHomeEverySoOften::
# 296 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
	.string "travel with POKéMON.\p"
	.string "But you should go home every so often\n"
	.string "to let your mother know you're okay.\p"
	.string "She might not say it, but I'm sure she\n"
	.string "worries about you, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_MayWhoAreYou::
# 305 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Huh?\n"
	.string "Who… Who are you?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}.\n"
	.string "So your move was today.\p"
	.string "Um… I'm MAY.\n"
	.string "Glad to meet you!\p"
	.string "I…\n"
	.string "I have this dream of becoming friends\l"
	.string "with POKéMON all over the world.\p"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
	.string "my dad, PROF. BIRCH.\p"
	.string "I was hoping that you would be nice,\n"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
	.string "Oh, this is silly, isn't it?\n"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
	.string "Eheheh…\p"
	.string "Oh, no! I forgot!\p"
	.string "I was supposed to go help Dad catch\n"
	.string "some wild POKéMON!\p"
	.string "{PLAYER}{KUN}, I'll catch you later!$"

RivalsHouse_1F_Text_BrendanWhoAreYou::
# 330 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Hey!\n"
	.string "You…\p"
	.string "Who are you?\p"
	.string "Oh, you're {PLAYER}, aren't you?\n"
	.string "Moved in next door, right?\p"
	.string "I didn't know that you're a girl.\p"
	.string "Dad, PROF. BIRCH, said that our new\n"
	.string "next-door neighbor is a GYM LEADER's\l"
	.string "kid, so I assumed you'd be a guy.\p"
	.string "My name's BRENDAN.\n"
	.string "So, hi, neighbor!\p"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
	.string "a POKéMON?\p"
	.string "Do you want me to go catch you one?\p"
	.string "Aw, darn, I forgot…\p"
	.string "I'm supposed to go help my dad catch\n"
	.string "some wild POKéMON.\p"
	.string "Some other time, okay?$"
