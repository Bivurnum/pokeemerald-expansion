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
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 1, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 75 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4
# 79 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 18, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 58 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
# 59 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 60 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 61 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighborBren, MSGBOX_DEFAULT
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 65 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 66 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkfriendchoice
# 67 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_RESULT
# 68 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case SPENCER, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3
# 70 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case KYLE, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4
LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1:
# 73 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3:
# 69 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
	goto LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4:
# 71 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
	goto LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4:
# 76 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 19
# 77 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	return


LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
# 86 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkfriendchoice
# 87 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual_1
	return

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual_1:
# 88 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return


RivalsHouse_1F_EventScript_RivalMom::
# 93 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 94 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 95 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 96 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 97 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq RivalsHouse_1F_EventScript_RivalMom_2
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
# 104 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

RivalsHouse_1F_EventScript_RivalMom_2:
# 98 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 99 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


RivalsHouse_1F_EventScript_GoHomeEverySoOften::
# 109 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


RivalsHouse_1F_EventScript_RivalIsOnRoute103::
# 115 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 116 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 122 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 123 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 124 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 125 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


# 130 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
# 131 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 134 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
# 135 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
	step_end

RivalsHouse_1F_Text_OhYoureTheNewNeighborSpencer::
# 139 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello, {PLAYER}!\p"
	.string "If you're looking for SPENCER,\n"
	.string "I think he may still be in\l"
	.string "the moving truck.\p"
	.string "Would you go and check on him\n"
	.string "for me, please?$"

RivalsHouse_1F_Text_OhYoureTheNewNeighborBren::
# 148 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello, {PLAYER}!\p"
	.string "If you're looking for BREN,\n"
	.string "I think he may still be in\l"
	.string "the moving truck.\p"
	.string "Would you go and check on him\n"
	.string "for me, please?$"

RivalsHouse_1F_Text_OhYoureTheNewNeighborKyle::
# 157 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello, {PLAYER}!\p"
	.string "If you're looking for KYLE,\n"
	.string "I think he may still be in\l"
	.string "the moving truck.\p"
	.string "Would you go and check on him\n"
	.string "for me, please?$"

RivalsHouse_1F_Text_LikeChildLikeFather::
# 166 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I sure hope my son is\n"
	.string "getting enough to eat.$"

RivalsHouse_1F_Text_TooBusyToNoticeVisit::
# 171 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
	.string "I guess our child is too busy with\n"
	.string "POKéMON to notice that you came\l"
	.string "to visit, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_WentOutToRoute103::
# 178 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
	.string "just a little while ago.\p"
	.string "Like father, like child.\n"
	.string "{RIVAL} can't stay quietly at home.$"

RivalsHouse_1F_Text_ShouldGoHomeEverySoOften::
# 185 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
	.string "travel with POKéMON.\p"
	.string "But you should go home every so often\n"
	.string "to let your mother know you're okay.\p"
	.string "She might not say it, but I'm sure she\n"
	.string "worries about you, {PLAYER}{KUN}.$"
