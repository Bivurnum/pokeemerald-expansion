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
	call LittlerootTown_EventScript_CheckForTwin
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


LittlerootTown_EventScript_CheckForTwin::
# 111 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	return


LittlerootTown_EventScript_SetTwinPos::
# 116 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 117 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 118 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 123 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 124 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 129 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 131 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 132 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 133 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 134 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 135 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 136 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 137 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 142 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 143 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 144 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 145 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 146 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 147 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 148 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 149 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 150 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 155 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 156 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 157 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 158 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 159 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 160 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 161 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 162 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 163 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 168 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 169 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 170 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 171 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 172 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 173 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 177 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 179 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 174 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 184 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 185 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 186 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 187 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 188 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 189 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 190 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 191 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 192 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 193 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 194 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 195 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 196 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 197 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 198 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 199 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 200 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 201 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 202 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 203 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 204 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 205 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 206 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 207 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 208 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 209 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 210 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 211 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 212 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 213 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 214 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 219 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 220 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 221 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 221 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 221 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 285 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 287 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 222 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 222 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 222 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 226 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 227 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 228 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 278 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 223 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 229 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 230 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 231 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 232 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 234 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 235 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 236 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 237 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 249 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 261 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 274 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 275 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 276 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 279 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 238 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 239 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 241 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 244 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 245 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 246 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 247 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 248 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 250 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 251 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 253 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 256 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 257 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 258 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 259 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 260 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 262 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 263 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 265 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 268 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 269 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 270 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 271 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 272 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 240 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 242 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 252 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 254 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 264 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 266 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 291 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 292 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 295 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 297 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 300 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 301 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 302 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 303 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 306 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 307 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 308 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 311 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 312 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 313 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 314 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 315 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 318 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 319 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 319 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 322 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 323 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 324 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 324 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 324 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 327 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 328 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 331 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 332 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 336 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 337 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 338 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 339 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 340 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 341 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 342 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 343 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 344 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 345 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 346 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 347 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 348 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 349 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 354 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 355 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 356 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 357 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 358 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 361 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 364 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 359 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 360 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 362 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 363 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 365 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 366 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 372 "data/maps/LittlerootTown/scripts.pory"
	lock
# 373 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 374 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 375 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 380 "data/maps/LittlerootTown/scripts.pory"
	lock
# 381 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 382 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 383 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 388 "data/maps/LittlerootTown/scripts.pory"
	lock
# 389 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 390 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 391 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 392 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 1
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 402 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 403 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 393 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 394 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 395 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 396 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 397 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 398 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 399 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 408 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 409 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 410 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 415 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 416 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 421 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 422 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 423 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 424 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 425 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 426 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 427 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 432 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 433 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 434 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 435 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 436 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 437 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 438 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 443 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 444 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 445 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 446 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 447 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 448 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 449 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 452 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 453 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 454 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 455 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 456 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 457 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 458 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 458 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 458 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 458 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 459 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 459 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 461 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 464 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 465 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 469 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 470 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 470 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 471 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 471 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 471 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 471 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 472 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 473 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 476 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 477 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 478 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 479 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 482 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 483 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 484 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 485 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 486 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 487 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 488 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 488 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 488 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 489 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 489 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 490 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 491 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 494 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 495 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 496 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 497 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 497 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 497 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 498 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 502 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 503 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 504 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 505 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 506 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 507 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 508 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 509 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 510 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 511 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 512 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 513 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 518 "data/maps/LittlerootTown/scripts.pory"
	lock
# 519 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 520 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 525 "data/maps/LittlerootTown/scripts.pory"
	lock
# 526 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 527 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 532 "data/maps/LittlerootTown/scripts.pory"
	lock
# 533 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 534 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 539 "data/maps/LittlerootTown/scripts.pory"
	lock
# 540 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 541 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 546 "data/maps/LittlerootTown/scripts.pory"
	lock
# 547 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 548 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 565 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 566 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 567 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 10, 9
# 568 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 573 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 574 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 575 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 11, 9
# 576 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 581 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 582 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 583 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 588 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 589 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 590 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 595 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 596 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 597 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 602 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 603 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 604 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 609 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 610 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_2
# 615 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
# 616 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
LittlerootTown_EventScript_GiveRunningShoesTrigger_1:
# 618 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_6
LittlerootTown_EventScript_GiveRunningShoesTrigger_5:
# 622 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_9
LittlerootTown_EventScript_GiveRunningShoesTrigger_8:
# 626 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_12
LittlerootTown_EventScript_GiveRunningShoesTrigger_11:
# 630 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 631 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 632 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 633 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_15
# 645 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_16
# 665 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_17
LittlerootTown_EventScript_GiveRunningShoesTrigger_14:
# 685 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 686 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 687 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 688 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_22
# 698 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_23
# 742 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_24
LittlerootTown_EventScript_GiveRunningShoesTrigger_21:
# 786 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 787 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 788 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 789 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger_2:
# 611 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 612 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_6:
# 619 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 620 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_5

LittlerootTown_EventScript_GiveRunningShoesTrigger_9:
# 623 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 624 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_8

LittlerootTown_EventScript_GiveRunningShoesTrigger_12:
# 627 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 628 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_11

LittlerootTown_EventScript_GiveRunningShoesTrigger_15:
# 634 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 635 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_29
# 639 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_30
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_16:
# 646 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 647 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_32
# 651 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_33
# 655 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_34
# 659 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_35
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_17:
# 666 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 667 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_37
# 671 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_38
# 675 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_39
# 679 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_40
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_22:
# 689 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 690 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_42
# 693 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_43
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_23:
# 699 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 700 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_45
# 710 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_46
# 720 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_47
# 730 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_48
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_24:
# 743 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 744 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_50
# 754 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_51
# 764 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_52
# 774 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_53
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_29:
# 636 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 637 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 638 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_30:
# 640 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 641 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 642 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer1
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_32:
# 648 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 649 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 650 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_33:
# 652 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 653 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 654 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_34:
# 656 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 657 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 658 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_35:
# 660 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 661 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 662 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_37:
# 668 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 669 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 670 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_38:
# 672 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 673 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 674 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_39:
# 676 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 677 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 678 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_40:
# 680 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 681 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 682 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_42:
# 691 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome0
# 692 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_43:
# 694 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome1
# 695 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_45:
# 701 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale2
# 702 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 703 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 704 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 705 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 706 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 707 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 708 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 709 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_46:
# 711 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale3
# 712 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 713 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 714 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 715 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 716 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 717 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 718 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 719 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_47:
# 721 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale4
# 722 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 723 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 724 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 725 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 726 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 727 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 728 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 729 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_48:
# 731 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale5
# 732 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 733 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 734 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 735 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 736 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 737 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 738 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 739 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_50:
# 745 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 746 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 747 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 748 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 749 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 750 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 751 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 752 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 753 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_51:
# 755 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 756 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 757 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 758 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 759 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 760 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 761 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 762 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 763 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_52:
# 765 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 766 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 767 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 768 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 769 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 770 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 771 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 772 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 773 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_53:
# 775 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 776 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 777 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 778 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 779 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 780 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 781 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 782 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 783 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21


LittlerootTown_EventScript_Mom::
# 794 "data/maps/LittlerootTown/scripts.pory"
	lock
# 795 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 796 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 797 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_Mom_2
LittlerootTown_EventScript_Mom_1:
# 801 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_Mom_5
LittlerootTown_EventScript_Mom_4:
# 805 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_Mom_8
LittlerootTown_EventScript_Mom_7:
# 809 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 810 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
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
# 819 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 820 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 821 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 822 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Mom_2:
# 798 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 799 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_1

LittlerootTown_EventScript_Mom_5:
# 802 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 803 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_4

LittlerootTown_EventScript_Mom_8:
# 806 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 807 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_Mom_7


LittlerootTown_EventScript_GiveRunningShoes::
# 827 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 828 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 829 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 830 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 831 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 832 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 833 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 834 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 835 "data/maps/LittlerootTown/scripts.pory"
	delay 30
	return


# 839 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 843 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 844 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 847 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 848 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 851 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 852 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 855 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 859 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 863 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 864 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 867 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 868 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 871 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 872 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 875 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 876 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 876 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 876 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 876 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 879 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 880 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 883 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 884 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 887 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 888 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 888 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 888 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 888 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 889 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 892 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 893 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 894 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 897 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 898 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 898 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 899 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 902 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 903 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 903 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 903 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 904 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 907 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 908 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 908 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 908 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 909 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 912 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 913 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 913 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 914 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 917 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 918 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 918 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 918 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 918 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 918 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 919 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 922 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 923 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 923 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 923 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 923 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 924 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 927 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 928 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 223 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 226 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 285 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_Text_SpencersHouse::
# 552 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 556 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 560 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 931 "data/maps/LittlerootTown/scripts.pory"
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
# 944 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 948 "data/maps/LittlerootTown/scripts.pory"
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
# 960 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 965 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 974 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 985 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 991 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 999 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 1005 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 1010 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 1020 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 1025 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 1030 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 1035 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 1039 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
