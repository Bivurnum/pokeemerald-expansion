LittlerootTown_MapScripts::
# 43 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 97 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 105 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 44 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 45 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 46 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 47 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 50 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 53 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 68 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 73 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 78 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 83 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 87 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29:
# 90 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32:
# 93 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 48 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 8
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 51 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 15
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 54 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 55 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_ne LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 59 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 60 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
# 62 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21
# 64 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 69 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 71 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 56 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 57 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 74 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 75 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 76 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 61 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 5, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21:
# 63 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22:
# 65 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 16
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24:
# 79 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 80 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 81 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27:
# 84 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 85 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30:
# 88 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33:
# 91 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35:
# 94 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 98 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckSpencer
# 99 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckBren
# 100 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_EventScript_StepOffTruckKyle
# 101 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_EventScript_JumpOffFriendTruck
# 102 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_JumpOffFriendTruck
# 103 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 106 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0


LittlerootTown_EventScript_SetTwinPos::
# 111 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 112 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 113 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 118 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 119 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 124 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 125 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 126 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 127 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 128 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 129 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 130 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 131 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 132 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 137 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 138 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 139 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 140 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 141 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 142 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 143 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 144 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 145 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 150 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 151 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 152 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 153 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 154 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 155 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 156 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 157 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 158 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 163 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 164 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 165 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 166 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 167 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 168 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 172 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 174 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 169 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 179 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 180 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 181 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 182 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 183 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 184 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 185 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 186 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 187 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 188 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 189 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 190 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 191 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 192 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 193 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 194 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 195 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 196 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 197 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 198 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 199 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 200 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 201 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 202 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 203 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 204 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 205 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 206 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 207 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 208 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 209 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 214 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 215 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 216 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 216 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 216 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 280 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 282 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 217 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 217 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 217 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 221 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 222 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 223 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 273 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 218 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 224 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 225 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 226 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 227 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 229 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 230 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 231 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 232 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 244 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 256 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 269 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 270 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 271 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 274 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 233 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 234 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 236 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 239 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 240 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 241 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 242 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 243 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 245 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 246 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 248 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 251 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 252 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 253 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 254 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 255 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 257 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 260 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 263 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 264 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 265 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 266 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 267 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 235 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 237 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 247 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 249 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 259 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 261 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 286 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 287 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 290 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 291 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 292 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 295 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 296 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 297 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 298 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 301 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 302 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 303 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 306 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 307 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 308 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 309 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 310 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 313 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 314 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 314 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 317 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 318 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 319 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 319 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 319 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 322 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 323 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 326 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 327 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 331 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 332 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 333 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 334 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 335 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 336 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 337 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 338 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 339 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 340 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 341 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 342 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 343 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 344 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 349 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 350 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 351 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 352 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 353 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 356 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 359 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 354 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 355 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 357 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 358 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 360 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 361 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 367 "data/maps/LittlerootTown/scripts.pory"
	lock
# 368 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 369 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 370 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 375 "data/maps/LittlerootTown/scripts.pory"
	lock
# 376 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 377 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 378 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 383 "data/maps/LittlerootTown/scripts.pory"
	lock
# 384 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 385 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 386 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 387 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 397 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 398 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 388 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 389 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 390 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 391 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 392 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 393 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 394 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 403 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 404 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 405 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 410 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 411 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 416 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 417 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 418 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 419 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 420 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 421 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 422 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 427 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 428 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 429 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 430 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 431 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 432 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 433 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 438 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 439 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 440 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 441 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 442 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 443 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 444 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 447 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 448 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 449 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 450 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 451 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 452 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 453 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 453 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 453 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 453 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 454 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 454 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 455 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 456 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 459 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 463 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 465 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 465 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 466 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 467 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 468 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 471 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 472 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 473 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 474 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 477 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 478 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 479 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 480 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 481 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 482 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 483 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 483 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 483 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 484 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 484 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 485 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 486 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 489 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 490 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 491 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 492 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 492 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 492 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 493 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 497 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 498 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 499 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 500 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 501 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 502 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 503 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 504 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 505 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 506 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 507 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 508 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 513 "data/maps/LittlerootTown/scripts.pory"
	lock
# 514 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 515 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 520 "data/maps/LittlerootTown/scripts.pory"
	lock
# 521 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 522 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 527 "data/maps/LittlerootTown/scripts.pory"
	lock
# 528 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 529 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 534 "data/maps/LittlerootTown/scripts.pory"
	lock
# 535 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 536 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 541 "data/maps/LittlerootTown/scripts.pory"
	lock
# 542 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 543 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 560 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 561 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 562 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 10, 9
# 563 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 568 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 569 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 570 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 11, 9
# 571 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 576 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 577 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 578 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 583 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 584 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 585 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 590 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 591 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 592 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 597 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 598 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 599 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 604 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 605 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_2
# 610 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
# 611 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
LittlerootTown_EventScript_GiveRunningShoesTrigger_1:
# 613 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_6
LittlerootTown_EventScript_GiveRunningShoesTrigger_5:
# 617 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_9
LittlerootTown_EventScript_GiveRunningShoesTrigger_8:
# 621 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_12
LittlerootTown_EventScript_GiveRunningShoesTrigger_11:
# 625 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 626 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 627 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_15
# 639 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_16
# 659 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_17
LittlerootTown_EventScript_GiveRunningShoesTrigger_14:
# 679 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 680 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 681 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_22
# 691 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_23
# 735 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_24
LittlerootTown_EventScript_GiveRunningShoesTrigger_21:
# 779 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 780 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 781 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 782 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger_2:
# 606 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 607 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_6:
# 614 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 615 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_5

LittlerootTown_EventScript_GiveRunningShoesTrigger_9:
# 618 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 619 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_8

LittlerootTown_EventScript_GiveRunningShoesTrigger_12:
# 622 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 623 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_11

LittlerootTown_EventScript_GiveRunningShoesTrigger_15:
# 628 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 629 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_29
# 633 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_30
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_16:
# 640 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 641 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_32
# 645 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_33
# 649 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_34
# 653 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_35
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_17:
# 660 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 661 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_37
# 665 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_38
# 669 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_39
# 673 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_40
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_22:
# 682 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 683 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_42
# 686 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_43
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_23:
# 692 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 693 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_45
# 703 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_46
# 713 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_47
# 723 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_48
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_24:
# 736 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 737 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_50
# 747 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_51
# 757 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_52
# 767 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_53
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_29:
# 630 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 631 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 632 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_30:
# 634 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 635 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 636 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer1
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_32:
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 643 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 644 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_33:
# 646 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 647 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 648 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_34:
# 650 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 651 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 652 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_35:
# 654 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 655 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 656 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_37:
# 662 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 663 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 664 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_38:
# 666 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 667 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 668 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_39:
# 670 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 671 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 672 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_40:
# 674 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 675 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 676 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_42:
# 684 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome0
# 685 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_43:
# 687 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome1
# 688 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_45:
# 694 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale2
# 695 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 696 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 697 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 698 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 699 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 700 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 701 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 702 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_46:
# 704 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale3
# 705 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 706 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 707 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 708 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 709 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 710 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 711 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 712 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_47:
# 714 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale4
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 716 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 717 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 718 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 719 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 720 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 721 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 722 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_48:
# 724 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale5
# 725 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 726 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 727 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 728 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 729 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 730 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 731 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_50:
# 738 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 739 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 740 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 741 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 742 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 743 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 744 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 745 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 746 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_51:
# 748 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 749 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 750 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 751 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 752 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 753 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 754 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 755 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 756 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_52:
# 758 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 759 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 760 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 761 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 762 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 763 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 764 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 765 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 766 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_53:
# 768 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 769 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 770 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 771 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 772 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 773 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 774 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 775 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 776 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21


LittlerootTown_EventScript_Mom::
# 787 "data/maps/LittlerootTown/scripts.pory"
	lock
# 788 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 789 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 790 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_Mom_2
LittlerootTown_EventScript_Mom_1:
# 794 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_Mom_5
LittlerootTown_EventScript_Mom_4:
# 798 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_Mom_8
LittlerootTown_EventScript_Mom_7:
# 802 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 803 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
# 804 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 805 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 806 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 807 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 808 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 809 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 810 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 811 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 812 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 813 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 814 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 815 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Mom_2:
# 791 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 792 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_1

LittlerootTown_EventScript_Mom_5:
# 795 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 796 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_4

LittlerootTown_EventScript_Mom_8:
# 799 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 800 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_Mom_7


LittlerootTown_EventScript_GiveRunningShoes::
# 820 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 821 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 822 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 823 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 824 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 825 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 826 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 827 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 828 "data/maps/LittlerootTown/scripts.pory"
	delay 30
	return


# 832 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
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
LittlerootTown_Movement_MomApproachPlayer1:
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 837 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 840 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
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
LittlerootTown_Movement_MomApproachPlayerMale3:
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 848 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 849 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 852 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 853 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 856 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 857 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 860 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 861 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 864 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 865 "data/maps/LittlerootTown/scripts.pory"
	walk_left
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
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 869 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 872 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
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
LittlerootTown_Movement_MomReturnHome1:
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 877 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 880 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 881 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 881 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 881 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 881 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 882 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 885 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 886 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 887 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 890 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 891 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 891 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 892 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 895 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 896 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 896 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 896 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 897 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 900 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 901 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 901 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 901 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 902 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 905 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 906 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 906 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 907 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 910 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 911 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 911 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 911 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 911 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 911 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 912 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 915 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 916 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 916 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 916 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 916 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 917 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 920 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 921 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 218 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 221 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 280 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_Text_SpencersHouse::
# 547 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 551 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 555 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 924 "data/maps/LittlerootTown/scripts.pory"
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
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 941 "data/maps/LittlerootTown/scripts.pory"
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
# 953 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 958 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 978 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 984 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 992 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 998 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 1003 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 1013 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 1018 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 1023 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 1028 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 1032 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
