LittlerootTown_MaysHouse_2F_MapScripts::
# 4 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_ge LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 10 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, BREN, SecretBase_EventScript_InitDecorations
	return


LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
# 23 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 8, 2
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return


LittlerootTown_MaysHouse_2F_EventScript_FriendRival::
# 36 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	faceplayer
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 5
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendRival_2
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 6
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendRival_3
LittlerootTown_MaysHouse_2F_EventScript_FriendRival_1:
# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_FriendRival_2:
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_GoFindBirch, MSGBOX_DEFAULT
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 41 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 14, Common_Movement_FaceUp
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 6
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendRival_1

LittlerootTown_MaysHouse_2F_EventScript_FriendRival_3:
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_HesOnRoute101, MSGBOX_DEFAULT
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 14, Common_Movement_FaceUp
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendRival_1


RivalsHouse_2F_EventScript_RivalPostLilycove::
# 54 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, SPENCER, RivalsHouse_2F_EventScript_MayPostLilycove
# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, BREN, RivalsHouse_2F_EventScript_BrendanPostLilycove
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


RivalsHouse_2F_EventScript_MayPostLilycove::
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 66 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_BrendanPostLilycove::
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 72 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return


LittlerootTown_MaysHouse_2F_EventScript_PC::
# 87 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_PC_1
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_MaysHouse_2F_EventScript_PC_1:
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	return


LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
# 98 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 99 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 107 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


RivalsHouse_2F_Text_MayJustCheckingMyPokedex::
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "I was just checking my POKéDEX.\p"
	.string "There's still a lot of POKéMON that\n"
	.string "I've seen but haven't caught.\p"
	.string "And there are many others that\n"
	.string "I think will evolve.\p"
	.string "I wonder where I should go catch\n"
	.string "some POKéMON next?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext::
# 133 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
	.string "some POKéMON next?\p"
	.string "Wouldn't it be funny if we ran into each\n"
	.string "other, {PLAYER}{KUN}?$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex::
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
	.string "I was just checking out my POKéDEX.\p"
	.string "There are still many POKéMON that\n"
	.string "I need to catch, I know, but this\l"
	.string "is looking pretty good.\p"
	.string "Checking this POKéDEX out gives me\n"
	.string "the urge to hit the road again.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext::
# 150 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
	.string "where I should catch POKéMON next.\p"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
	.string "catching POKéMON, I can pitch you a\l"
	.string "battle if you'd like.$"

RivalsHouse_2F_Text_GoFindBirch::
# 158 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Oh, hey!\p"
	.string "Isn't it crazy that the three of us\n"
	.string "all moved here at the same time?\l"
	.string "Now we all get to start our POKéMON\l"
	.string "journey together!\p"
	.string "What?\n"
	.string "You don't have a POKéMON yet?\p"
	.string "I've got mine already.\n"
	.string "Maybe I'll show it to you sometime.\p"
	.string "Well? What are you waiting for?\n"
	.string "Go find PROF. BIRCH and\l"
	.string "get your first POKéMON!$"

RivalsHouse_2F_Text_HesOnRoute101::
# 173 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Last I heard, PROF. BIRCH was\n"
	.string "doing field work on ROUTE 101.$"
