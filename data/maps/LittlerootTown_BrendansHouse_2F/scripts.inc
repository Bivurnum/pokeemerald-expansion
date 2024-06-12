LittlerootTown_BrendansHouse_2F_MapScripts::
# 4 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 14 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 5 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_ge LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 10 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 11 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 12 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 6 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
# 7 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 8 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	goto LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 15 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

LittlerootTown_BrendansHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 16 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkfriendchoice
# 17 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, SPENCER, SecretBase_EventScript_InitDecorations
	return


LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
# 23 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkfriendchoice
# 24 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 25 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
# 26 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectxyperm 1, 0, 2
# 27 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_BrendansHouse_2F_EventScript_Ret::
	return


LittlerootTown_BrendansHouse_2F_EventScript_PC::
# 36 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	lockall
# 37 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	checkfriendchoice
# 38 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_PC_1
# 42 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_BrendansHouse_2F_EventScript_PC_1:
# 39 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	goto LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	return


LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
# 47 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 48 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 49 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_ON
# 50 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 51 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special BedroomPC
# 52 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	waitstate
# 53 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
# 58 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 59 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 60 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 61 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
# 66 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 67 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	releaseall
	end


PlayersHouse_2F_EventScript_Notebook::
# 72 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end


PlayersHouse_2F_EventScript_GameCube::
# 77 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end


PlayersHouse_2F_Text_ClockIsStopped::
# 81 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom::
# 86 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "POKéMON movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook::
# 97 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap::
# 106 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"

PlayersHouse_2F_Text_ItsAGameCube::
# 111 "data/maps/LittlerootTown_BrendansHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"
