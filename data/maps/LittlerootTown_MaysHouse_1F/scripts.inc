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
# 51 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BREN, 1, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3
# 76 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 4, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4
# 82 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
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
	special TurnOnTVScreen
# 47 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, FEMALE
# 48 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 49 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_PetalburgGymReportFemale
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3:
# 52 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 53 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	playse SE_PIN
# 54 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 55 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 56 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, Common_Movement_Delay48
# 57 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 58 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 59 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
# 60 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 61 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 62 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighborBren, MSGBOX_DEFAULT
# 63 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_MET_RIVAL_MOM
# 64 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 65 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 66 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 67 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkfriendchoice
# 68 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_RESULT
# 69 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case SPENCER, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3
# 71 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case KYLE, LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4
LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1:
# 74 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	releaseall
	return

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_3:
# 70 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
	goto LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_4:
# 72 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
	goto LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_3_1

LittlerootTown_MaysHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_4:
# 77 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 5
# 78 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 79 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 80 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
	return


LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
# 89 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkfriendchoice
# 90 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual_1
	return

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual_1:
# 91 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setmetatile 6, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return


RivalsHouse_1F_EventScript_RivalMom::
# 96 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lock
# 97 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	faceplayer
# 98 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 7, RivalsHouse_1F_EventScript_FriendsLeftForAdventure
# 99 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_GoHomeEverySoOften
# 100 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, RivalsHouse_1F_EventScript_RivalIsOnRoute103
# 101 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq RivalsHouse_1F_EventScript_RivalMom_2
# 106 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	special GetRivalSonDaughterString
# 107 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	random 3
# 108 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_RESULT
# 109 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 0, RivalsHouse_1F_EventScript_RivalMom_6
# 111 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 1, RivalsHouse_1F_EventScript_RivalMom_7
# 113 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case 2, RivalsHouse_1F_EventScript_RivalMom_8
RivalsHouse_1F_EventScript_RivalMom_4:
# 116 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

RivalsHouse_1F_EventScript_RivalMom_2:
# 102 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_TooBusyToNoticeVisit, MSGBOX_DEFAULT
# 103 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

RivalsHouse_1F_EventScript_RivalMom_6:
# 110 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_HopeEnoughToEat, MSGBOX_DEFAULT
	goto RivalsHouse_1F_EventScript_RivalMom_4

RivalsHouse_1F_EventScript_RivalMom_7:
# 112 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_BoysBehaving, MSGBOX_DEFAULT
	goto RivalsHouse_1F_EventScript_RivalMom_4

RivalsHouse_1F_EventScript_RivalMom_8:
# 114 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_MomSettlingIn, MSGBOX_DEFAULT
	goto RivalsHouse_1F_EventScript_RivalMom_4


RivalsHouse_1F_EventScript_FriendsLeftForAdventure::
# 121 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	checkfriendchoice
# 122 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	switch VAR_RESULT
# 123 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case SPENCER, RivalsHouse_1F_EventScript_FriendsLeftForAdventure_3
# 125 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case BREN, RivalsHouse_1F_EventScript_FriendsLeftForAdventure_4
# 127 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	case KYLE, RivalsHouse_1F_EventScript_FriendsLeftForAdventure_5
RivalsHouse_1F_EventScript_FriendsLeftForAdventure_1:
# 130 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end

RivalsHouse_1F_EventScript_FriendsLeftForAdventure_3:
# 124 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_KyleAndBrenLeft, MSGBOX_DEFAULT
	goto RivalsHouse_1F_EventScript_FriendsLeftForAdventure_1

RivalsHouse_1F_EventScript_FriendsLeftForAdventure_4:
# 126 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SpencerAndKyleLeft, MSGBOX_DEFAULT
	goto RivalsHouse_1F_EventScript_FriendsLeftForAdventure_1

RivalsHouse_1F_EventScript_FriendsLeftForAdventure_5:
# 128 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_SpencerAndBrenLeft, MSGBOX_DEFAULT
	goto RivalsHouse_1F_EventScript_FriendsLeftForAdventure_1


RivalsHouse_1F_EventScript_GoHomeEverySoOften::
# 135 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_ShouldGoHomeEverySoOften, MSGBOX_DEFAULT
# 136 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


RivalsHouse_1F_EventScript_RivalIsOnRoute103::
# 141 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
# 142 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	release
	end


LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom::
# 147 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	lockall
# 148 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 149 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	setvar VAR_0x8005, FEMALE
# 150 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterRight
# 151 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	waitmovement 0
# 152 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end


# 156 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
# 157 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_up
	step_end

# 160 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
# 161 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_down
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
# 162 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	walk_left
	step_end

RivalsHouse_1F_Text_OhYoureTheNewNeighborSpencer::
# 165 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello, {PLAYER}!\p"
	.string "If you're looking for SPENCER,\n"
	.string "I think he may still be in\l"
	.string "the moving truck.\p"
	.string "Would you go and check on him\n"
	.string "for me, please?$"

RivalsHouse_1F_Text_OhYoureTheNewNeighborBren::
# 174 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello, {PLAYER}!\p"
	.string "If you're looking for BREN,\n"
	.string "I think he may still be in\l"
	.string "the moving truck.\p"
	.string "Would you go and check on him\n"
	.string "for me, please?$"

RivalsHouse_1F_Text_OhYoureTheNewNeighborKyle::
# 183 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, hello, {PLAYER}!\p"
	.string "If you're looking for KYLE,\n"
	.string "I think he may still be in\l"
	.string "the moving truck.\p"
	.string "Would you go and check on him\n"
	.string "for me, please?$"

RivalsHouse_1F_Text_HopeEnoughToEat::
# 192 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I sure hope my son is\n"
	.string "getting enough to eat.$"

RivalsHouse_1F_Text_BoysBehaving::
# 197 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Are you boys behaving?$"

RivalsHouse_1F_Text_MomSettlingIn::
# 201 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "How is your mom settling in?$"

RivalsHouse_1F_Text_TooBusyToNoticeVisit::
# 205 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "That {RIVAL}!\p"
	.string "I guess our child is too busy with\n"
	.string "POKéMON to notice that you came\l"
	.string "to visit, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_WentOutToRoute103::
# 212 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
	.string "just a little while ago.\p"
	.string "Like father, like child.\n"
	.string "{RIVAL} can't stay quietly at home.$"

RivalsHouse_1F_Text_ShouldGoHomeEverySoOften::
# 219 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "I think it's wonderful for people to\n"
	.string "travel with POKéMON.\p"
	.string "But you should go home every so often\n"
	.string "to let your mother know you're okay.\p"
	.string "She might not say it, but I'm sure she\n"
	.string "worries about you, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_SpencerAndBrenLeft::
# 228 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh hey, {PLAYER}.\n"
	.string "SPENCER and BREN said they were headed\l"
	.string "out to train up their new POKéMON."
	.string "You should join them when you're ready.$"

RivalsHouse_1F_Text_SpencerAndKyleLeft::
# 235 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh hey, {PLAYER}.\n"
	.string "SPENCER and KYLE said they were headed\l"
	.string "out to train up their new POKéMON."
	.string "You should join them when you're ready.$"

RivalsHouse_1F_Text_KyleAndBrenLeft::
# 242 "data/maps/LittlerootTown_MaysHouse_1F/scripts.pory"
	.string "Oh hey, {PLAYER}.\n"
	.string "BREN and KYLE said they were headed\l"
	.string "out to train up their new POKéMON."
	.string "You should join them when you're ready.$"
