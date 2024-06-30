LittlerootTown_MapScripts::
# 44 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 83 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 91 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 45 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 46 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 47 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_CheckForTwin
# 48 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 51 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 54 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 59 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 64 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 69 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 73 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 19
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_19:
# 76 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22:
# 79 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_25
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 49 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 8
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 52 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 15
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 55 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 56 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 57 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 60 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 61 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 62 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 65 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 20
# 66 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 20
# 67 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 20
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 71 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 74 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_19

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 77 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_25:
# 80 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 84 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckSpencer
# 85 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckBren
# 86 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_EventScript_StepOffTruckKyle
# 87 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_EventScript_JumpOffFriendTruck
# 88 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_JumpOffFriendTruck
# 89 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 92 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0


LittlerootTown_EventScript_CheckForTwin::
# 97 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	return


LittlerootTown_EventScript_SetTwinPos::
# 102 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 103 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 104 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 109 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 110 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 115 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 116 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 117 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 118 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 119 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 120 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 121 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 122 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 123 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 124 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 129 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 131 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 132 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 133 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 134 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 135 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 136 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 137 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 138 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 143 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 144 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 145 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 146 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 147 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 148 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 149 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 150 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 151 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 152 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 157 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 158 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 159 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 160 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 161 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 162 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 166 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 168 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 163 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 173 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 174 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 175 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 176 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 177 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 178 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 179 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 180 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 181 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 182 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 183 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 184 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 185 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 186 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 187 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 188 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 189 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 190 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 191 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 192 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 193 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 194 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 195 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 196 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 197 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 198 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 199 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 200 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 201 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 202 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 203 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 208 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 209 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 210 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 210 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 210 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 274 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 276 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 211 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 211 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 211 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 215 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 216 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 217 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 267 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 212 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 218 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 219 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 220 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 221 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 222 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_PLAY_TRUCK_MUSIC, 1
# 223 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 224 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 225 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 226 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 238 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 250 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 263 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 264 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 265 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 268 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 227 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 228 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 230 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 233 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 234 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 235 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 236 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 237 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 239 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 240 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 242 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 245 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 246 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 247 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 248 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 249 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 251 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 252 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 254 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 257 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 258 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 259 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 260 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 261 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 229 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 231 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 241 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 243 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 253 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 255 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 280 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 281 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 284 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 285 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 286 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 289 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 290 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 291 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 292 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 295 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 296 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 297 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 300 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 301 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 302 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 303 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 304 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 307 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 308 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 308 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 311 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 312 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 313 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 313 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 313 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 316 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 317 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 320 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 321 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 325 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 326 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 327 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 328 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 329 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 330 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 331 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 332 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 333 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 334 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 335 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 336 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 337 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 338 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 343 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 344 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 345 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 346 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 347 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 350 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 353 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 348 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 349 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 351 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 352 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 354 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 355 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 361 "data/maps/LittlerootTown/scripts.pory"
	lock
# 362 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 363 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 364 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 369 "data/maps/LittlerootTown/scripts.pory"
	lock
# 370 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 371 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 372 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 377 "data/maps/LittlerootTown/scripts.pory"
	lock
# 378 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 379 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 380 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 381 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 1
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 391 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 392 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 382 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 383 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 384 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 385 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 386 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 387 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 388 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 397 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 398 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 399 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 404 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 405 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 410 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 411 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 412 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 413 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 414 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 415 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 416 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 421 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 422 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 423 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 424 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 425 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 426 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 427 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 432 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 433 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 434 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 435 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 436 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 437 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 438 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 441 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 442 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 443 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 444 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 445 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 446 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 447 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 447 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 447 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 447 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 448 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 448 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 449 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 450 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 453 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 454 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 457 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 458 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 459 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 459 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 460 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 461 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 462 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 465 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 466 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 467 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 468 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 471 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 472 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 473 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 474 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 475 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 476 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 477 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 478 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 478 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 479 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 480 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 483 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 484 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 485 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 486 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 486 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 486 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 487 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 491 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 492 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 493 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 494 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 495 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 496 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 497 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 498 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 499 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 500 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 501 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 502 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 507 "data/maps/LittlerootTown/scripts.pory"
	lock
# 509 "data/maps/LittlerootTown/scripts.pory"
	checkflag FLAG_BADGE02_GET
# 510 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_EventScript_TownSign_2
LittlerootTown_EventScript_TownSign_1:
# 513 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_EventScript_TownSign_5
LittlerootTown_EventScript_TownSign_4:
# 516 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_TownSign_2:
# 511 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	goto LittlerootTown_EventScript_TownSign_1

LittlerootTown_EventScript_TownSign_5:
# 514 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_TownSign_Text_1, MSGBOX_SIGN
	goto LittlerootTown_EventScript_TownSign_4


LittlerootTown_EventScript_BirchsLabSign::
# 521 "data/maps/LittlerootTown/scripts.pory"
	lock
# 522 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 523 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 528 "data/maps/LittlerootTown/scripts.pory"
	lock
# 529 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 530 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 535 "data/maps/LittlerootTown/scripts.pory"
	lock
# 536 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 537 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 542 "data/maps/LittlerootTown/scripts.pory"
	lock
# 543 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 544 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Mom::
# 561 "data/maps/LittlerootTown/scripts.pory"
	lock
# 562 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 563 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_Mom_Text_0, MSGBOX_DEFAULT
# 564 "data/maps/LittlerootTown/scripts.pory"
	release
	end


# 568 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer:
# 569 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 569 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 569 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 569 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 571 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 572 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 572 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 572 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 572 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 575 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 576 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 576 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 576 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 576 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 576 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 579 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 580 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 580 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 583 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 584 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 584 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 584 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 587 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 588 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 588 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 588 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 591 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 592 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 592 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 595 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 596 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 596 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 596 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 596 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 596 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 599 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 600 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 600 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 600 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 600 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 603 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale6:
# 604 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 604 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 604 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 604 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 604 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 604 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 607 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome:
# 608 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 608 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 608 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 608 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 608 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 611 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 612 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 612 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 612 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 612 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 613 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 616 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 617 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 617 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 617 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 617 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 617 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 618 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 621 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 622 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 622 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 623 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 626 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 627 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 627 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 627 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 628 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 631 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 632 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 632 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 632 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 633 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 636 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 637 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 637 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 638 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 641 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 642 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 642 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 642 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 642 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 642 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 643 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 646 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 647 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 647 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 647 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 647 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 648 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 651 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale6:
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 652 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 653 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 656 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 657 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 212 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 215 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 274 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_EventScript_TownSign_Text_0:
# 511 "data/maps/LittlerootTown/scripts.pory"
	.string "The flag is set.$"

LittlerootTown_EventScript_TownSign_Text_1:
# 514 "data/maps/LittlerootTown/scripts.pory"
	.string "The flag is NOT set.$"

LittlerootTown_EventScript_Mom_Text_0:
# 563 "data/maps/LittlerootTown/scripts.pory"
	.string "Hi.$"

LittlerootTown_Text_SpencersHouse::
# 548 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 552 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 556 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 660 "data/maps/LittlerootTown/scripts.pory"
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
# 673 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 677 "data/maps/LittlerootTown/scripts.pory"
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
# 689 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 694 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 703 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 714 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 720 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 728 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 734 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 739 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 749 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 754 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 759 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 764 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 768 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
