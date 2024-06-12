LittlerootTown_MaysHouse_2F_MapScripts::
# 5 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 6 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_ge LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 11 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 12 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 13 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 7 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
# 8 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 9 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 16 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

LittlerootTown_MaysHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 17 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 18 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, BREN, SecretBase_EventScript_InitDecorations
	return


LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
# 24 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 25 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 26 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
# 27 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectxyperm 1, 8, 2
# 28 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return


LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer::
# 37 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 38 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	faceplayer
# 39 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 4
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_2
LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_1:
# 42 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 5
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_5
# 49 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 6
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_6
LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_4:
# 55 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 56 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 57 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 58 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case BREN, LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_11
# 61 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case KYLE, LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_12
LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_9:
# 65 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_2:
# 40 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_1

LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_5:
# 43 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_GoFindBirch, MSGBOX_DEFAULT
# 44 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 45 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 46 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 47 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 6
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_4

LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_6:
# 50 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_HesOnRoute101, MSGBOX_DEFAULT
# 51 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 52 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 53 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_4

LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_11:
# 59 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 60 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 4
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_9

LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_12:
# 62 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 63 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 4
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendSpencer_9


LittlerootTown_MaysHouse_2F_EventScript_FriendBren::
# 70 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 71 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	faceplayer
# 72 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 4
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendBren_2
LittlerootTown_MaysHouse_2F_EventScript_FriendBren_1:
# 75 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 5
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendBren_5
# 82 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 6
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendBren_6
LittlerootTown_MaysHouse_2F_EventScript_FriendBren_4:
# 88 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 89 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 90 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 91 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPENCER, LittlerootTown_MaysHouse_2F_EventScript_FriendBren_11
# 94 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case KYLE, LittlerootTown_MaysHouse_2F_EventScript_FriendBren_12
LittlerootTown_MaysHouse_2F_EventScript_FriendBren_9:
# 98 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_FriendBren_2:
# 73 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendBren_1

LittlerootTown_MaysHouse_2F_EventScript_FriendBren_5:
# 76 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_GoFindBirch, MSGBOX_DEFAULT
# 77 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 78 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 79 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 80 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 6
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendBren_4

LittlerootTown_MaysHouse_2F_EventScript_FriendBren_6:
# 83 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_HesOnRoute101, MSGBOX_DEFAULT
# 84 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 85 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 86 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendBren_4

LittlerootTown_MaysHouse_2F_EventScript_FriendBren_11:
# 92 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_KYLE
# 93 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 4
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendBren_9

LittlerootTown_MaysHouse_2F_EventScript_FriendBren_12:
# 95 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 96 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 4
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendBren_9


LittlerootTown_MaysHouse_2F_EventScript_FriendKyle::
# 103 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 104 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	faceplayer
# 105 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 4
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_2
LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_1:
# 108 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 5
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_5
# 115 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 6
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_6
LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_4:
# 121 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
# 122 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 123 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	switch VAR_RESULT
# 124 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case SPENCER, LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_11
# 127 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	case BREN, LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_12
LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_9:
# 131 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_2:
# 106 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_1

LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_5:
# 109 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_GoFindBirch, MSGBOX_DEFAULT
# 110 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 111 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 112 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 113 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 6
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_4

LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_6:
# 116 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_HesOnRoute101, MSGBOX_DEFAULT
# 117 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 118 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 119 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_4

LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_11:
# 125 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_BREN
# 126 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 4
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_9

LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_12:
# 128 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	clearflag FLAG_HIDE_INTRO_2F_SPENCER
# 129 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 4
	goto LittlerootTown_MaysHouse_2F_EventScript_FriendKyle_9


LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon::
# 136 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_TEMP_1, 2
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon_2
# 140 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_WhereHaveYouBeen, MSGBOX_DEFAULT
# 141 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_TEMP_1, 2
LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon_1:
# 143 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	closemessage
# 144 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement 15, Common_Movement_FaceUp
# 145 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 146 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon_2:
# 137 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_GettingSupplies, MSGBOX_DEFAULT
	goto LittlerootTown_MaysHouse_2F_EventScript_Friend2GotPokemon_1


RivalsHouse_2F_EventScript_RivalPostLilycove::
# 151 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 152 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitmovement 0
# 153 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkplayergender
# 154 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, SPENCER, RivalsHouse_2F_EventScript_MayPostLilycove
# 155 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	call_if_eq VAR_RESULT, BREN, RivalsHouse_2F_EventScript_BrendanPostLilycove
# 156 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
# 157 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


RivalsHouse_2F_EventScript_MayPostLilycove::
# 162 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
# 163 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_BrendanPostLilycove::
# 168 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
# 169 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
# 174 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return


RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
# 179 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return


LittlerootTown_MaysHouse_2F_EventScript_PC::
# 184 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	lockall
# 185 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	checkfriendchoice
# 186 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_PC_1
# 190 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_MaysHouse_2F_EventScript_PC_1:
# 187 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	return


LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
# 195 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 196 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
# 201 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 202 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 203 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_ON
# 204 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 205 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special BedroomPC
# 206 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	waitstate
# 207 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
# 212 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 213 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 214 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 215 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	releaseall
	end


RivalsHouse_2F_Text_MayJustCheckingMyPokedex::
# 219 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "I was just checking my POKéDEX.\p"
	.string "There's still a lot of POKéMON that\n"
	.string "I've seen but haven't caught.\p"
	.string "And there are many others that\n"
	.string "I think will evolve.\p"
	.string "I wonder where I should go catch\n"
	.string "some POKéMON next?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext::
# 230 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "MAY: I wonder where I should go catch\n"
	.string "some POKéMON next?\p"
	.string "Wouldn't it be funny if we ran into each\n"
	.string "other, {PLAYER}{KUN}?$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex::
# 237 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
	.string "I was just checking out my POKéDEX.\p"
	.string "There are still many POKéMON that\n"
	.string "I need to catch, I know, but this\l"
	.string "is looking pretty good.\p"
	.string "Checking this POKéDEX out gives me\n"
	.string "the urge to hit the road again.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext::
# 247 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "BRENDAN: I'm having a hard time deciding\n"
	.string "where I should catch POKéMON next.\p"
	.string "Hey, {PLAYER}, if I see you while I'm out\n"
	.string "catching POKéMON, I can pitch you a\l"
	.string "battle if you'd like.$"

RivalsHouse_2F_Text_GoFindBirch::
# 255 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
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
# 270 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Last I heard, PROF. BIRCH was\n"
	.string "doing field work on ROUTE 101.$"

RivalsHouse_2F_Text_WhereHaveYouBeen::
# 275 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Where have you been?\p"
	.string "PROF. BIRCH is kind of a strange dude,\n"
	.string "but the POKéMON he gave me is super cool!\l"
	.string "You should hurry up and get yours!\p"
	.string "Once I'm finished getting supplies together,\n"
	.string "I'll be ready for our adventure.$"

RivalsHouse_2F_Text_GettingSupplies::
# 284 "data/maps/LittlerootTown_MaysHouse_2F/scripts.pory"
	.string "Once I'm finished getting supplies together,\n"
	.string "I'll be ready for our adventure.$"
