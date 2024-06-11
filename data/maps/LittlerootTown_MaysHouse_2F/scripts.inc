LittlerootTown_MaysHouse_2F_MapScripts::
# 2 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_lt LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_ne LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_7
	goto LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	goto LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 19 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 20 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 21 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, BREN, SecretBase_EventScript_InitDecorations
	return


LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 28 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 29 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 30 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 8, 2
# 31 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return


RivalsHouse_2F_EventScript_RivalPostLilycove::
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, SPENCER, RivalsHouse_2F_EventScript_MayPostLilycove
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, BREN, RivalsHouse_2F_EventScript_BrendanPostLilycove
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


RivalsHouse_2F_EventScript_MayPostLilycove::
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_BrendanPostLilycove::
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
# 68 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return


LittlerootTown_MaysHouse_2F_EventScript_PC::
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 74 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_PC_1
# 79 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_MaysHouse_2F_EventScript_PC_1:
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	return


LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 95 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 101 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 102 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


RivalsHouse_2F_Text_MayJustCheckingMyPokedex::
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "I was just checking my POKéDEX.\p"
	.string "There's still a lot of POKéMON that\n"
	.string "I've seen but haven't caught.\p"
	.string "And there are many others that\n"
	.string "I think will evolve.\p"
	.string "I wonder where I should go catch\n"
	.string "some POKéMON next?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext::
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
	.string "some POKéMON next?\p"
	.string "Wouldn't it be funny if we ran into each\n"
	.string "other, {PLAYER}{KUN}?$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex::
# 126 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
	.string "I was just checking out my POKéDEX.\p"
	.string "There are still many POKéMON that\n"
	.string "I need to catch, I know, but this\l"
	.string "is looking pretty good.\p"
	.string "Checking this POKéDEX out gives me\n"
	.string "the urge to hit the road again.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext::
# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
	.string "where I should catch POKéMON next.\p"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
	.string "catching POKéMON, I can pitch you a\l"
	.string "battle if you'd like.$"
