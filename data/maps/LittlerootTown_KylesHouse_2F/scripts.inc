LittlerootTown_KylesHouse_2F_MapScripts::
# 2 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 18 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_lt LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_ge LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 14 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 15 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 16 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 5 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_ne LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_7
	goto LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 10 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_KylesHouse_2F_EventScript_TryUpdateMayPos
# 11 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_KylesHouse_2F_EventScript_Ret
# 12 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_TryUpdateMayPos
	goto LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 6 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	goto LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 19 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 20 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 21 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, KYLE, SecretBase_EventScript_InitDecorations
	return


LittlerootTown_KylesHouse_2F_EventScript_TryUpdateMayPos::
# 27 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 28 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_KylesHouse_2F_EventScript_Ret
# 29 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_KylesHouse_2F_EventScript_Ret
# 30 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 8, 2
# 31 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_KylesHouse_2F_EventScript_Ret::
	return


LittlerootTown_KylesHouse_2F_EventScript_PC::
# 41 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	lockall
# 42 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 43 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_KylesHouse_2F_EventScript_PC_1
# 47 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_KylesHouse_2F_EventScript_PC_1:
# 44 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_CheckPlayersPC
	return


LittlerootTown_KylesHouse_2F_EventScript_CheckRivalsPC::
# 52 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 53 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_KylesHouse_2F_EventScript_CheckPlayersPC::
# 58 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 59 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 60 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	playse SE_PC_ON
# 61 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 62 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	special BedroomPC
# 63 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	waitstate
# 64 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	releaseall
	end

