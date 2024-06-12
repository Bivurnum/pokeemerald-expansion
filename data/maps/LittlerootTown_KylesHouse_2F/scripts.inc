LittlerootTown_KylesHouse_2F_MapScripts::
# 2 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 12 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_ge LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 8 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
# 9 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 10 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 4 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_KylesHouse_2F_EventScript_TryUpdateMayPos
# 5 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_KylesHouse_2F_EventScript_Ret
# 6 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_TryUpdateMayPos
	goto LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 13 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

LittlerootTown_KylesHouse_2F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 14 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 15 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, KYLE, SecretBase_EventScript_InitDecorations
	return


LittlerootTown_KylesHouse_2F_EventScript_TryUpdateMayPos::
# 21 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 22 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_KylesHouse_2F_EventScript_Ret
# 23 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_KylesHouse_2F_EventScript_Ret
# 24 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 8, 2
# 25 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_KylesHouse_2F_EventScript_Ret::
	return


LittlerootTown_KylesHouse_2F_EventScript_PC::
# 35 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	lockall
# 36 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 37 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_KylesHouse_2F_EventScript_PC_1
# 41 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_KylesHouse_2F_EventScript_PC_1:
# 38 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_CheckPlayersPC
	return


LittlerootTown_KylesHouse_2F_EventScript_CheckRivalsPC::
# 46 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 47 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_KylesHouse_2F_EventScript_CheckPlayersPC::
# 52 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 53 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 54 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	playse SE_PC_ON
# 55 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 56 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	special BedroomPC
# 57 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	waitstate
# 58 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	releaseall
	end

