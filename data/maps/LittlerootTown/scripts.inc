LittlerootTown_MapScripts::
# 48 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 103 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 111 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 49 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 50 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 51 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_CheckForTwin
# 52 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 55 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 58 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 69 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 4
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 74 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 79 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_19:
# 84 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22:
# 89 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_25:
# 93 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_28:
# 96 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_31:
# 99 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_34
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 53 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 8
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 56 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 15
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 59 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 60 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 61 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
# 62 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 63 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
# 65 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_15
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 70 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 71 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
# 72 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 16
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 64 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 5, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_15:
# 66 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 75 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 76 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 77 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 80 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 81 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 82 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_19

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 85 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 86 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 87 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 90 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 91 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_25

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29:
# 94 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_28

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32:
# 97 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_31

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_34:
# 100 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 104 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckSpencer
# 105 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckBren
# 106 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_EventScript_StepOffTruckKyle
# 107 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_EventScript_JumpOffFriendTruck
# 108 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_JumpOffFriendTruck
# 109 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 112 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0


LittlerootTown_EventScript_CheckForTwin::
# 117 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	return


LittlerootTown_EventScript_SetTwinPos::
# 122 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 123 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 124 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 129 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 130 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 135 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 136 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 137 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 138 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 139 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 140 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 141 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 142 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 143 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 148 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 149 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 150 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 151 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 152 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 153 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 154 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 155 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 156 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 161 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 162 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 163 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 164 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 165 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 166 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 167 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 168 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 169 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 174 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 175 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 176 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 177 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 178 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 179 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 183 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 185 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 180 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 190 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 191 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 192 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 193 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 194 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 195 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 196 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 197 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 198 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 199 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 200 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 201 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 202 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 203 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 204 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 205 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 206 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 207 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 208 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 209 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 210 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 211 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 212 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 213 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 214 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 215 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 216 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 217 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 218 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 219 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 220 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 225 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 226 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 227 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 227 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 227 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 291 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 293 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 228 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 228 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 228 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 232 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 233 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 234 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 284 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 229 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 235 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 236 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 237 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 238 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 239 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_PLAY_TRUCK_MUSIC, 1
# 240 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 241 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 242 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 243 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 255 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 267 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 280 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 281 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 282 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 285 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 244 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 245 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 247 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 250 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 251 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 252 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 253 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 254 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 256 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 257 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 259 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 262 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 263 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 264 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 265 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 266 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 268 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 269 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 271 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 274 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 275 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 276 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 277 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 278 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 246 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 248 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 258 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 260 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 270 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 272 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 297 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 298 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 301 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 302 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 303 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 306 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 307 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 308 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 309 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 312 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 313 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 314 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 317 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 318 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 319 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 320 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 321 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 324 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 325 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 325 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 328 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 329 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 330 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 330 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 330 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 333 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 334 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 337 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 338 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 342 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 343 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 344 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 345 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 346 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 347 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 348 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 349 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 350 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 351 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 352 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 353 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 354 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 355 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 360 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 361 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 362 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 363 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 364 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 367 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 370 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 365 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 366 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 368 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 369 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 371 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 372 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 378 "data/maps/LittlerootTown/scripts.pory"
	lock
# 379 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 380 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 381 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 386 "data/maps/LittlerootTown/scripts.pory"
	lock
# 387 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 388 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 389 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 394 "data/maps/LittlerootTown/scripts.pory"
	lock
# 395 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 396 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 397 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 398 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 1
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 408 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 409 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 399 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 400 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 401 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 402 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 403 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 404 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 405 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 414 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 415 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 416 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 421 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 422 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 427 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 428 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 429 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 430 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 431 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 432 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 433 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 438 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 439 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 440 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 441 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 442 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 443 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 444 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 449 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 450 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 451 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 452 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 453 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 454 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 455 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 458 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 459 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 460 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 461 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 462 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 463 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 465 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 465 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 467 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 470 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 471 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 474 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 475 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 476 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 476 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 478 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 482 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 483 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 484 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 485 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 488 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 489 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 490 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 491 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 492 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 493 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 494 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 494 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 494 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 495 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 495 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 496 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 497 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 500 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 501 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 502 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 503 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 503 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 503 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 504 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 508 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 509 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 510 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 511 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 512 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 513 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 514 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 515 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 516 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 517 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 518 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 519 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 524 "data/maps/LittlerootTown/scripts.pory"
	lock
# 525 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 526 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 531 "data/maps/LittlerootTown/scripts.pory"
	lock
# 532 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 533 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 538 "data/maps/LittlerootTown/scripts.pory"
	lock
# 539 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 540 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 545 "data/maps/LittlerootTown/scripts.pory"
	lock
# 546 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 547 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 552 "data/maps/LittlerootTown/scripts.pory"
	lock
# 553 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 554 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 571 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 572 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 573 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 10, 8
# 574 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 10, 8
# 575 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
# 576 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_FaceUp
# 577 "data/maps/LittlerootTown/scripts.pory"
	showobjectat 4, MAP_LITTLEROOT_TOWN
# 578 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 583 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 584 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 585 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 11, 8
# 586 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 11, 8
# 587 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
# 588 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_FaceUp
# 589 "data/maps/LittlerootTown/scripts.pory"
	showobjectat 4, MAP_LITTLEROOT_TOWN
# 590 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 595 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 596 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 597 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 602 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 603 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 604 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 609 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 610 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 611 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 616 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 617 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 618 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger6::
# 623 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 624 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 6
# 625 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 630 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 631 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_5
LittlerootTown_EventScript_GiveRunningShoesTrigger_4:
# 635 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_gt LittlerootTown_EventScript_GiveRunningShoesTrigger_3
LittlerootTown_EventScript_GiveRunningShoesTrigger_1:
# 639 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_9
LittlerootTown_EventScript_GiveRunningShoesTrigger_8:
# 643 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_12
LittlerootTown_EventScript_GiveRunningShoesTrigger_11:
# 647 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_15
LittlerootTown_EventScript_GiveRunningShoesTrigger_14:
# 651 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 652 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 653 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 654 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_18
# 666 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_19
# 686 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_20
# 707 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 708 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_47
# 712 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_48
# 716 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_49
# 720 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_50
# 724 "data/maps/LittlerootTown/scripts.pory"
	case 6, LittlerootTown_EventScript_GiveRunningShoesTrigger_51
LittlerootTown_EventScript_GiveRunningShoesTrigger_17:
# 730 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 731 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 732 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 733 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_26
# 743 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_27
# 787 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_28
# 832 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 833 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_66
# 843 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_67
# 853 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_68
# 863 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_69
# 873 "data/maps/LittlerootTown/scripts.pory"
	case 6, LittlerootTown_EventScript_GiveRunningShoesTrigger_70
LittlerootTown_EventScript_GiveRunningShoesTrigger_25:
# 885 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 886 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 887 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_FORCE_LOAD_OFFSCREEN_OBJEV
# 888 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 10
# 889 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 5
# 890 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger_2:
# 632 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 633 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_3:
# 636 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
# 637 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_5:
# 631 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_gt LittlerootTown_EventScript_GiveRunningShoesTrigger_2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_4

LittlerootTown_EventScript_GiveRunningShoesTrigger_9:
# 640 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 641 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_8

LittlerootTown_EventScript_GiveRunningShoesTrigger_12:
# 644 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 645 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_11

LittlerootTown_EventScript_GiveRunningShoesTrigger_15:
# 648 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 649 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_18:
# 655 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 656 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_34
# 660 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_35
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_19:
# 667 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 668 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_37
# 672 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_38
# 676 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_39
# 680 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_40
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_20:
# 687 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 688 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_42
# 692 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_43
# 696 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_44
# 700 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_45
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_26:
# 734 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 735 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_53
# 738 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_54
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_27:
# 744 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 745 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_56
# 755 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_57
# 765 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_58
# 775 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_59
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_28:
# 788 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 789 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_61
# 799 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_62
# 809 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_63
# 819 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_64
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_34:
# 657 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
# 658 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 659 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_35:
# 661 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
# 662 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 663 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_37:
# 669 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 670 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 671 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_38:
# 673 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 674 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 675 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_39:
# 677 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 678 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 679 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_40:
# 681 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 682 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 683 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_42:
# 689 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 690 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 691 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_43:
# 693 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 694 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 695 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_44:
# 697 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 698 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 699 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_45:
# 701 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 702 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 703 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_47:
# 709 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 710 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 711 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_48:
# 713 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 714 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 715 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_49:
# 717 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 718 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 719 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_50:
# 721 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 722 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 723 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_51:
# 725 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 726 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 727 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale6
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_17

LittlerootTown_EventScript_GiveRunningShoesTrigger_53:
# 736 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome
# 737 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_54:
# 739 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome
# 740 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_56:
# 746 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale2
# 747 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 748 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 749 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 750 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 751 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 752 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 753 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 754 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_57:
# 756 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale3
# 757 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 758 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 759 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 760 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 761 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 762 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 763 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 764 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_58:
# 766 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale4
# 767 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 768 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 769 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 770 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 771 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 772 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 773 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 774 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_59:
# 776 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale5
# 777 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 778 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 779 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 780 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 781 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 782 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 783 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 784 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_61:
# 790 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 791 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 792 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 793 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 794 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 795 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 796 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 797 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 798 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_62:
# 800 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 801 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 802 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 803 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 804 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 805 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 806 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 807 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 808 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_63:
# 810 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 811 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 812 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 813 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 814 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 815 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 816 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 817 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 818 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_64:
# 820 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 821 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 822 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 823 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 824 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 825 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 826 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 827 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 828 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_66:
# 834 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 835 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 836 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 837 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 838 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 839 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 840 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 841 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 842 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_67:
# 844 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 845 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 846 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 847 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 848 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 849 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 850 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 851 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 852 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_68:
# 854 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 855 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 856 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 857 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 858 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 859 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 860 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 861 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 862 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_69:
# 864 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 865 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 866 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 867 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 868 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 869 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 870 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 871 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 872 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25

LittlerootTown_EventScript_GiveRunningShoesTrigger_70:
# 874 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale6
# 875 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 876 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 877 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 878 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 879 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 880 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 881 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 882 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_25


LittlerootTown_EventScript_Mom::
# 895 "data/maps/LittlerootTown/scripts.pory"
	lock
# 896 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 897 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 898 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_Mom_2
LittlerootTown_EventScript_Mom_1:
# 902 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_Mom_5
LittlerootTown_EventScript_Mom_4:
# 906 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_Mom_8
LittlerootTown_EventScript_Mom_7:
# 910 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 911 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
# 912 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 913 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 914 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 915 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 916 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 917 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 918 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 919 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 920 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 921 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 922 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 923 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Mom_2:
# 899 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 900 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_1

LittlerootTown_EventScript_Mom_5:
# 903 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 904 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_4

LittlerootTown_EventScript_Mom_8:
# 907 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 908 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_Mom_7


LittlerootTown_EventScript_GiveRunningShoes::
# 928 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 929 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 930 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 931 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 932 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 933 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 934 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 935 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 936 "data/maps/LittlerootTown/scripts.pory"
	delay 30
	return


# 940 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer:
# 941 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 941 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 941 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 941 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 943 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 944 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 944 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 944 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 944 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 947 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 948 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 948 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 948 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 948 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 948 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 951 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 952 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 952 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 955 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 956 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 956 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 956 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 959 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 960 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 960 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 960 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 963 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 964 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 964 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 967 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 968 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 968 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 968 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 968 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 968 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 971 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 972 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 972 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 972 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 972 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 975 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale6:
# 976 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 976 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 976 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 976 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 976 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 976 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 979 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome:
# 980 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 980 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 980 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 980 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 980 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 983 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 984 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 984 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 984 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 984 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 985 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 988 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 989 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 989 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 989 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 989 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 989 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 990 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 993 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 994 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 994 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 995 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 998 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 999 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 999 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 999 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 1000 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1003 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 1004 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1004 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1004 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1005 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1008 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 1009 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1009 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1010 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1013 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 1014 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1014 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1014 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1014 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1014 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1015 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1018 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 1019 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1019 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1019 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1019 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1020 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1023 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale6:
# 1024 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1024 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1024 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1024 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1024 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1024 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1025 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1028 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 1029 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 229 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 232 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 291 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_Text_SpencersHouse::
# 558 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 562 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 566 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 1032 "data/maps/LittlerootTown/scripts.pory"
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
# 1045 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 1049 "data/maps/LittlerootTown/scripts.pory"
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
# 1061 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 1066 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 1075 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 1086 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 1092 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 1100 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 1106 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 1111 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 1121 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 1126 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 1131 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 1136 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 1140 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
