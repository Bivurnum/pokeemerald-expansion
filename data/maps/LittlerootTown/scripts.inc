LittlerootTown_MapScripts::
# 48 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 105 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 113 "data/maps/LittlerootTown/scripts.pory"
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
# 71 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 4
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 76 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_18
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 81 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 86 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 91 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 95 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29:
# 98 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32:
# 101 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35
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
# 67 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 72 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 73 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
# 74 "data/maps/LittlerootTown/scripts.pory"
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

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 68 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 16
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_18:
# 77 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 78 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 79 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21:
# 82 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 83 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 84 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24:
# 87 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 88 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 89 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27:
# 92 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 93 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30:
# 96 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33:
# 99 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35:
# 102 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 106 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckSpencer
# 107 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckBren
# 108 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_EventScript_StepOffTruckKyle
# 109 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_EventScript_JumpOffFriendTruck
# 110 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_JumpOffFriendTruck
# 111 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 114 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0


LittlerootTown_EventScript_CheckForTwin::
# 119 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	return


LittlerootTown_EventScript_SetTwinPos::
# 124 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 125 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 126 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 131 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 132 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 137 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 138 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 139 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 140 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 141 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 142 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 143 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 144 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 145 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 150 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 151 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 152 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 153 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 154 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 155 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 156 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 157 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 158 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 163 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 164 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 165 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 166 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 167 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 168 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 169 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 170 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 171 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 176 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 177 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 178 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 179 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 180 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 181 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 185 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 187 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 182 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 192 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 193 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 194 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 195 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 196 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 197 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 198 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 199 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 200 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 201 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 202 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 203 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 204 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 205 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 206 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 207 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 208 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 209 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 210 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 211 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 212 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 213 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 214 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 215 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 217 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 218 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 219 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 220 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 221 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 222 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 227 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 228 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 229 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 229 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 229 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 293 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 295 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 230 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 230 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 230 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 234 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 235 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 236 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 286 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 231 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 237 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 238 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 239 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 240 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 242 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 243 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 244 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 245 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 257 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 269 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 282 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 283 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 284 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 287 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 246 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 247 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 249 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 252 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 253 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 254 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 255 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 256 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 258 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 259 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 261 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 264 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 265 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 266 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 267 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 268 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 270 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 271 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 273 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 276 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 277 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 278 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 279 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 280 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 248 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 250 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 260 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 262 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 272 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 274 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 299 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 300 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 303 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 304 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 305 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 308 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 309 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 310 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 311 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 314 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 316 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 319 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 320 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 321 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 322 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 323 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 326 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 327 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 327 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 330 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 331 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 332 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 332 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 332 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 335 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 336 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 339 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 340 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 344 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 345 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 346 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 347 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 348 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 349 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 350 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 351 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 352 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 353 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 354 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 355 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 356 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 357 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 362 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 363 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 364 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 365 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 366 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 369 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 372 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 367 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 368 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 370 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 371 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 373 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 374 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 380 "data/maps/LittlerootTown/scripts.pory"
	lock
# 381 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 382 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 383 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 388 "data/maps/LittlerootTown/scripts.pory"
	lock
# 389 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 390 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 391 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 396 "data/maps/LittlerootTown/scripts.pory"
	lock
# 397 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 398 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 399 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 400 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 1
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 410 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 411 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 401 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 402 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 403 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 404 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 405 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 406 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 407 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 416 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 417 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 418 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 423 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 424 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 429 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 430 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 431 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 432 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 433 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 434 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 435 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 440 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 441 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 442 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 443 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 444 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 445 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 446 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 451 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 452 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 453 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 454 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 455 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 456 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 457 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 460 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 461 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 462 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 463 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 464 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 465 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 467 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 467 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 468 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 469 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 472 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 473 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 476 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 478 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 478 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 480 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 481 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 484 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 485 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 486 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 487 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 490 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 491 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 492 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 493 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 494 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 495 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 496 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 496 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 496 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 497 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 497 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 498 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 499 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 502 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 503 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 504 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 505 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 505 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 505 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 506 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 510 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 511 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 512 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 513 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 514 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 515 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 516 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 517 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 518 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 519 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 520 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 521 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 526 "data/maps/LittlerootTown/scripts.pory"
	lock
# 527 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 528 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 533 "data/maps/LittlerootTown/scripts.pory"
	lock
# 534 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 535 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 540 "data/maps/LittlerootTown/scripts.pory"
	lock
# 541 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 542 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 547 "data/maps/LittlerootTown/scripts.pory"
	lock
# 548 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 549 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 554 "data/maps/LittlerootTown/scripts.pory"
	lock
# 555 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 556 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 573 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 574 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 575 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 10, 9
# 576 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 581 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 582 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 583 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 11, 9
# 584 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 589 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 590 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 591 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 596 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 597 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 598 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 603 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 604 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 605 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 610 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 611 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 612 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger6::
# 617 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 618 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 6
# 619 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 624 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 625 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_2
# 630 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
LittlerootTown_EventScript_GiveRunningShoesTrigger_1:
# 633 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_6
LittlerootTown_EventScript_GiveRunningShoesTrigger_5:
# 637 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_9
LittlerootTown_EventScript_GiveRunningShoesTrigger_8:
# 641 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_12
LittlerootTown_EventScript_GiveRunningShoesTrigger_11:
# 645 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 646 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 647 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 648 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_15
# 661 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_16
# 681 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_17
# 702 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 703 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_44
# 707 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_45
# 711 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_46
# 715 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_47
# 719 "data/maps/LittlerootTown/scripts.pory"
	case 6, LittlerootTown_EventScript_GiveRunningShoesTrigger_48
LittlerootTown_EventScript_GiveRunningShoesTrigger_14:
# 725 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 726 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 727 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 728 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_23
# 738 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_24
# 782 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_25
# 827 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 828 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_63
# 838 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_64
# 848 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_65
# 858 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_66
# 868 "data/maps/LittlerootTown/scripts.pory"
	case 6, LittlerootTown_EventScript_GiveRunningShoesTrigger_67
LittlerootTown_EventScript_GiveRunningShoesTrigger_22:
# 880 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 881 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 882 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 5
# 883 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger_2:
# 626 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 627 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_6:
# 634 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 635 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_5

LittlerootTown_EventScript_GiveRunningShoesTrigger_9:
# 638 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 639 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_8

LittlerootTown_EventScript_GiveRunningShoesTrigger_12:
# 642 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 643 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_11

LittlerootTown_EventScript_GiveRunningShoesTrigger_15:
# 649 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 10
# 650 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 651 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_31
# 655 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_32
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_16:
# 662 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 663 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_34
# 667 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_35
# 671 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_36
# 675 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_37
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_17:
# 682 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 683 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_39
# 687 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_40
# 691 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_41
# 695 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_42
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_23:
# 729 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 730 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_50
# 733 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_51
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_24:
# 739 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 740 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_53
# 750 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_54
# 760 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_55
# 770 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_56
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_25:
# 783 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 784 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_58
# 794 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_59
# 804 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_60
# 814 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_61
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_31:
# 652 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 653 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 654 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_32:
# 656 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 657 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 658 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer1
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_34:
# 664 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 665 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 666 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_35:
# 668 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 669 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 670 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_36:
# 672 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 673 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 674 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_37:
# 676 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 677 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 678 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_39:
# 684 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 685 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 686 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_40:
# 688 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 689 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 690 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_41:
# 692 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 693 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 694 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_42:
# 696 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 697 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 698 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_44:
# 704 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 705 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 706 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_45:
# 708 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 709 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 710 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_46:
# 712 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 713 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 714 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_47:
# 716 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 717 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 718 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_48:
# 720 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 721 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 722 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale6
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_50:
# 731 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome0
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_51:
# 734 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome1
# 735 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_53:
# 741 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale2
# 742 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 743 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 744 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 745 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 746 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 747 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 748 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 749 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_54:
# 751 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale3
# 752 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 753 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 754 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 755 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 756 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 757 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 758 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 759 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_55:
# 761 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale4
# 762 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 763 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 764 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 765 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 766 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 767 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 768 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 769 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_56:
# 771 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale5
# 772 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 773 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 774 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 775 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 776 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 777 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 778 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 779 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_58:
# 785 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 786 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 787 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 788 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 789 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 790 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 791 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 792 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 793 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_59:
# 795 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 796 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 797 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 798 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 799 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 800 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 801 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 802 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 803 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_60:
# 805 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 806 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 807 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 808 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 809 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 810 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 811 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 812 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 813 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_61:
# 815 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 816 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 817 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 818 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 819 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 820 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 821 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 822 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 823 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_63:
# 829 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 830 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 831 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 832 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 833 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 834 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 835 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 836 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 837 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_64:
# 839 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 840 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 841 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 842 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 843 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 844 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 845 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 846 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 847 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_65:
# 849 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 850 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 851 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 852 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 853 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 854 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 855 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 856 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 857 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_66:
# 859 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 860 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 861 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 862 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 863 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 864 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 865 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 866 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 867 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22

LittlerootTown_EventScript_GiveRunningShoesTrigger_67:
# 869 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale6
# 870 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 871 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 872 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 873 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 874 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 875 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 876 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 877 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_22


LittlerootTown_EventScript_Mom::
# 888 "data/maps/LittlerootTown/scripts.pory"
	lock
# 889 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 890 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 891 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_Mom_2
LittlerootTown_EventScript_Mom_1:
# 895 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_Mom_5
LittlerootTown_EventScript_Mom_4:
# 899 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_Mom_8
LittlerootTown_EventScript_Mom_7:
# 903 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 904 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
# 905 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 906 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 907 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 908 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 909 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 910 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 911 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 912 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 913 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 914 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 915 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 916 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Mom_2:
# 892 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 893 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_1

LittlerootTown_EventScript_Mom_5:
# 896 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 897 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_4

LittlerootTown_EventScript_Mom_8:
# 900 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 901 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_Mom_7


LittlerootTown_EventScript_GiveRunningShoes::
# 921 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 922 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 923 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 924 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 925 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 926 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 927 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 928 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 929 "data/maps/LittlerootTown/scripts.pory"
	delay 30
	return


# 933 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 934 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 934 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 934 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 934 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 934 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 934 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 937 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 938 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 938 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 938 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 938 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 938 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 938 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 941 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 942 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 942 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 942 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 942 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 945 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 946 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 946 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 946 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 946 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 946 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 949 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 950 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 950 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 953 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 954 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 954 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 954 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 957 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 958 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 958 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 958 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 961 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 962 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 962 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 965 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 966 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 966 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 966 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 966 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 966 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 969 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 970 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 970 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 970 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 970 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 973 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale6:
# 974 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 974 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 974 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 974 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 974 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 974 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 977 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 978 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 978 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 978 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 978 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 978 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 981 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 982 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 982 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 982 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 982 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 982 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 985 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 986 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 986 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 986 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 986 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 987 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 990 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 991 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 991 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 991 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 991 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 991 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 992 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 995 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 996 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 996 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 997 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1000 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 1001 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 1001 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 1001 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 1002 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1005 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 1006 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1006 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1006 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1007 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1010 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 1011 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1011 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1012 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1015 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 1016 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1016 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1016 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1016 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1016 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1017 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1020 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 1021 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1021 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1021 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1021 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1022 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1025 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale6:
# 1026 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1026 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1026 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1026 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1026 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1026 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 1027 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 1030 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 1031 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 231 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 234 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 293 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_Text_SpencersHouse::
# 560 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 564 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 568 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 1034 "data/maps/LittlerootTown/scripts.pory"
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
# 1047 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 1051 "data/maps/LittlerootTown/scripts.pory"
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
# 1063 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 1068 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 1077 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 1088 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 1094 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 1102 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 1108 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 1113 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 1123 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 1128 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 1133 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 1138 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 1142 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
