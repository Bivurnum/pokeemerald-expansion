LittlerootTown_KylesHouse_2F_MapScripts::
	.byte 0


LittlerootTown_KylesHouse_2F_EventScript_PC::
# 7 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	lockall
# 8 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	checkfriendchoice
# 9 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_KylesHouse_2F_EventScript_PC_1
# 13 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_CheckPlayersPC
	return

LittlerootTown_KylesHouse_2F_EventScript_PC_1:
# 10 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	goto LittlerootTown_KylesHouse_2F_EventScript_CheckRivalsPC
	return


LittlerootTown_KylesHouse_2F_EventScript_CheckRivalsPC::
# 18 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 19 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	releaseall
	end


LittlerootTown_KylesHouse_2F_EventScript_CheckPlayersPC::
# 24 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
# 25 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 26 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	playse SE_PC_ON
# 27 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 28 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	special BedroomPC
# 29 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	waitstate
# 30 "data/maps/LittlerootTown_KylesHouse_2F/scripts.pory"
	releaseall
	end

