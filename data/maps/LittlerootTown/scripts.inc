LittlerootTown_MapScripts::
# 41 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 95 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 103 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 42 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 43 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 44 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 47 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 50 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 51 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 66 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 71 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 76 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 81 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 85 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29:
# 88 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32:
# 91 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 45 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 8
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 48 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 15
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 52 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 53 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_ne LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 57 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 58 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
# 60 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21
# 62 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 67 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 68 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 69 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 54 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 55 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 72 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 73 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 74 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 59 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 5, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21:
# 61 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22:
# 63 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 16
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24:
# 77 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 78 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 79 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27:
# 82 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 83 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30:
# 86 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33:
# 89 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35:
# 92 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 96 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckSpencer
# 97 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckBren
# 98 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_EventScript_StepOffTruckKyle
# 99 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_EventScript_JumpOffFriendTruck
# 100 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_JumpOffFriendTruck
# 101 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 104 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0


LittlerootTown_EventScript_SetTwinPos::
# 109 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 110 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 111 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 116 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 117 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 122 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 123 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 124 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 125 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 126 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 127 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 128 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 129 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 134 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 135 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 136 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 137 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 138 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 139 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 140 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 141 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 146 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 147 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 148 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 149 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 150 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 151 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 152 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 153 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 158 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 159 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 160 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 161 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 162 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 163 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 167 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 169 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 164 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 174 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 175 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 176 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 177 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 178 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 179 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 180 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 181 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 182 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 183 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 184 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 185 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 186 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 187 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 188 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 189 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 190 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 191 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 192 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 193 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 194 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 195 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 196 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 197 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 198 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 199 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 200 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 201 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 202 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 203 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 204 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 209 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 210 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 211 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 211 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 211 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 276 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 278 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 212 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 212 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 212 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 216 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 217 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 218 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 269 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 213 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 219 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 220 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 221 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 222 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 224 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 225 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 226 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 227 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 240 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 252 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 265 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 266 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 267 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 270 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 228 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 229 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 231 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 234 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 235 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 236 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 237 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 238 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 239 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 241 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 242 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 244 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 247 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 248 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 249 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 250 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 251 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 253 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 254 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 256 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 259 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 260 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 261 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 262 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 263 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 230 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 232 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 243 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 245 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 255 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 257 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 282 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 283 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 286 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 287 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 288 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 291 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 292 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 293 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 294 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 297 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 298 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 299 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 302 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 303 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 304 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 305 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 306 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 309 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 310 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 310 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 313 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 314 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 315 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 315 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 315 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 318 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 319 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 322 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 323 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 327 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 328 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 329 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 330 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 331 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 332 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 333 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 334 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 335 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 336 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 337 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 338 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 339 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 340 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 345 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 346 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 347 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 348 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 349 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 352 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 355 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 350 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 351 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 353 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 354 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 356 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 357 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 363 "data/maps/LittlerootTown/scripts.pory"
	lock
# 364 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 365 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 366 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 371 "data/maps/LittlerootTown/scripts.pory"
	lock
# 372 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 373 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 374 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 379 "data/maps/LittlerootTown/scripts.pory"
	lock
# 380 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 381 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 382 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 383 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 393 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 394 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 384 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 385 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 386 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 387 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 388 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 389 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 390 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 399 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 400 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 401 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 406 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 407 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 412 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 413 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 414 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 415 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 416 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 417 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 418 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 423 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 424 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 425 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 426 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 427 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 428 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 429 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 434 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 435 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 436 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 437 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 438 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 439 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 440 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 443 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 444 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 445 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 446 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 447 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 448 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 449 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 449 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 449 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 449 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 450 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 450 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 451 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 452 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 455 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 456 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 459 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 461 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 461 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 462 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 462 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 462 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 462 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 463 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 467 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 468 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 469 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 470 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 473 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 474 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 475 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 476 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 477 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 478 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 480 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 480 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 481 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 482 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 485 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 486 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 487 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 488 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 488 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 488 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 489 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 493 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 494 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 495 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 496 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 497 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 498 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 499 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 500 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 501 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 502 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 503 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 504 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 509 "data/maps/LittlerootTown/scripts.pory"
	lock
# 510 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 511 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 516 "data/maps/LittlerootTown/scripts.pory"
	lock
# 517 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 518 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 523 "data/maps/LittlerootTown/scripts.pory"
	lock
# 524 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 525 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 530 "data/maps/LittlerootTown/scripts.pory"
	lock
# 531 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 532 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 537 "data/maps/LittlerootTown/scripts.pory"
	lock
# 538 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 539 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 556 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 557 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 558 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 10, 9
# 559 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 564 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 565 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 566 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 11, 9
# 567 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 572 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 573 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 574 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 579 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 580 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 581 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 586 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 587 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 588 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 593 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 594 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 595 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 600 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 601 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_2
# 606 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
# 607 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
LittlerootTown_EventScript_GiveRunningShoesTrigger_1:
# 609 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_6
LittlerootTown_EventScript_GiveRunningShoesTrigger_5:
# 613 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_9
LittlerootTown_EventScript_GiveRunningShoesTrigger_8:
# 617 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_12
LittlerootTown_EventScript_GiveRunningShoesTrigger_11:
# 621 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 622 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 623 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_15
# 635 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_16
# 655 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_17
LittlerootTown_EventScript_GiveRunningShoesTrigger_14:
# 675 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 676 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 677 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_22
# 687 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_23
# 731 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_24
LittlerootTown_EventScript_GiveRunningShoesTrigger_21:
# 775 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 776 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 777 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 778 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger_2:
# 602 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 603 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_6:
# 610 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 611 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_5

LittlerootTown_EventScript_GiveRunningShoesTrigger_9:
# 614 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 615 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_8

LittlerootTown_EventScript_GiveRunningShoesTrigger_12:
# 618 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 619 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_11

LittlerootTown_EventScript_GiveRunningShoesTrigger_15:
# 624 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 625 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_29
# 629 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_30
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_16:
# 636 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 637 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_32
# 641 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_33
# 645 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_34
# 649 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_35
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_17:
# 656 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 657 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_37
# 661 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_38
# 665 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_39
# 669 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_40
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_22:
# 678 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 679 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_42
# 682 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_43
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_23:
# 688 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 689 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_45
# 699 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_46
# 709 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_47
# 719 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_48
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_24:
# 732 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 733 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_50
# 743 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_51
# 753 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_52
# 763 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_53
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_29:
# 626 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 627 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 628 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_30:
# 630 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer1
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_32:
# 638 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 639 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 640 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_33:
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_34:
# 646 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 647 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 648 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_35:
# 650 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 651 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_37:
# 658 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 659 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 660 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_38:
# 662 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 663 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 664 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_39:
# 666 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 667 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 668 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_40:
# 670 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 671 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 672 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_42:
# 680 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome0
# 681 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_43:
# 683 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome1
# 684 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_45:
# 690 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale2
# 691 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 692 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 693 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 694 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 695 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 696 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 697 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 698 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_46:
# 700 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale3
# 701 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 702 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 703 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 704 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 705 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 706 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 707 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 708 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_47:
# 710 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale4
# 711 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 712 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 713 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 714 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 716 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 717 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 718 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_48:
# 720 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale5
# 721 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 722 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 723 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 724 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 725 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 726 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 727 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 728 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_50:
# 734 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 735 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 736 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 737 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 738 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 739 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 740 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 741 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 742 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_51:
# 744 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 745 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 746 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 747 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 748 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 749 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 750 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 751 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 752 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_52:
# 754 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 755 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 756 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 757 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 758 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 759 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 760 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 761 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 762 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_53:
# 764 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 765 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 766 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 767 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 768 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 769 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 770 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 771 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 772 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21


LittlerootTown_EventScript_Mom::
# 783 "data/maps/LittlerootTown/scripts.pory"
	lock
# 784 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 785 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 786 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_Mom_2
LittlerootTown_EventScript_Mom_1:
# 790 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_Mom_5
LittlerootTown_EventScript_Mom_4:
# 794 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_Mom_8
LittlerootTown_EventScript_Mom_7:
# 798 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 799 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
# 800 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 801 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 802 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 803 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 804 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 805 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 806 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 807 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 808 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 809 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 810 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 811 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Mom_2:
# 787 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 788 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_1

LittlerootTown_EventScript_Mom_5:
# 791 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 792 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_4

LittlerootTown_EventScript_Mom_8:
# 795 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 796 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_Mom_7


LittlerootTown_EventScript_GiveRunningShoes::
# 816 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 817 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 818 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 819 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 820 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 821 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 822 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 823 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 824 "data/maps/LittlerootTown/scripts.pory"
	delay 30
	return


# 828 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 829 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 832 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 833 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 836 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 840 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 844 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 848 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 852 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 856 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 860 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 864 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 868 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 872 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 873 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 876 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 878 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 881 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 883 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 886 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 887 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 887 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 888 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 891 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 896 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 897 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 897 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 897 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 898 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 901 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 902 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 902 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 903 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 906 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 908 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 911 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 912 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 912 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 912 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 912 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 913 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 916 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 917 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 213 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 216 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 276 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_Text_SpencersHouse::
# 543 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 547 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 551 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 920 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, we're here, honey!\p"
	.string "It must be tiring riding with our things\n"
	.string "in the moving truck.\p"
	.string "Well, this is LITTLEROOT TOWN.\p"
	.string "How do you like it?\n"
	.string "This is our new home!\p"
	.string "It has a quaint feel, but it seems to be\n"
	.string "an easy place to live, don't you think?\p"
	.string "And, you get your own room, {PLAYER}!\n"
	.string "Let's go inside.$"

LittlerootTown_Text_WaitPlayer::
# 933 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to PROF. BIRCH?\p"
	.string "Oh! What an adorable POKéMON!\n"
	.string "You got it from PROF. BIRCH. How nice!\p"
	.string "You're your father's child, all right.\n"
	.string "You look good together with POKéMON!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes::
# 949 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 954 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 963 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 980 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 988 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 994 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 999 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 1009 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 1014 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 1019 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 1024 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 1028 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
