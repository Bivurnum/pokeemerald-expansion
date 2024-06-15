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
	call LittlerootTown_EventScript_GoInsideWithMom
# 119 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 120 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
# 121 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 8, 8
# 122 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 123 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckBren::
# 128 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 129 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 14
# 130 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 131 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 132 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 133 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
# 134 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 2, 8
# 135 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 136 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_StepOffTruckKyle::
# 141 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 142 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 17
# 143 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 15
# 144 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 145 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 146 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
# 147 "data/maps/LittlerootTown/scripts.pory"
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 148 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 149 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_JumpOffFriendTruck::
# 154 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 155 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 156 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 157 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_JumpOffFriendTruck
# 158 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 159 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_EventScript_JumpOffFriendTruck_2
# 163 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
LittlerootTown_EventScript_JumpOffFriendTruck_1:
# 165 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_JumpOffFriendTruck_2:
# 160 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
	goto LittlerootTown_EventScript_JumpOffFriendTruck_1


LittlerootTown_EventScript_GoInsideWithMom::
# 170 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 171 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 172 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 173 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 174 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 175 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 176 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 177 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 178 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 179 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 180 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 181 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 182 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 183 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 184 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 185 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 186 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 187 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 188 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 189 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 190 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 191 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 192 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 193 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 194 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 195 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 196 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 197 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 198 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 199 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 200 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 205 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 206 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 207 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 207 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 207 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 271 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_2
LittlerootTown_EventScript_EnterTruck_1:
# 273 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 208 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 208 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 208 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_ge LittlerootTown_EventScript_EnterTruck_9
# 212 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1, MSGBOX_YESNO
# 213 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 214 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_17
# 264 "data/maps/LittlerootTown/scripts.pory"
	case NO, LittlerootTown_EventScript_EnterTruck_18
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_9:
# 209 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_17:
# 215 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 216 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 217 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 218 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 219 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_PLAY_TRUCK_MUSIC, 1
# 220 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 221 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 222 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 223 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_21
# 235 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_22
# 247 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_23
LittlerootTown_EventScript_EnterTruck_19:
# 260 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
# 261 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 262 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_18:
# 265 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_21:
# 224 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 225 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_26
# 227 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_27
LittlerootTown_EventScript_EnterTruck_24:
# 230 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 231 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 232 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 233 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 234 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_22:
# 236 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 237 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_30
# 239 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_EnterTruck_31
LittlerootTown_EventScript_EnterTruck_28:
# 242 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 243 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 244 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 245 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
# 246 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_23:
# 248 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 249 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_EnterTruck_34
# 251 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_EnterTruck_35
LittlerootTown_EventScript_EnterTruck_32:
# 254 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 255 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 256 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 257 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 258 "data/maps/LittlerootTown/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 15, 17
	goto LittlerootTown_EventScript_EnterTruck_19

LittlerootTown_EventScript_EnterTruck_26:
# 226 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_27:
# 228 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_24

LittlerootTown_EventScript_EnterTruck_30:
# 238 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_31:
# 240 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_28

LittlerootTown_EventScript_EnterTruck_34:
# 250 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 2
	goto LittlerootTown_EventScript_EnterTruck_32

LittlerootTown_EventScript_EnterTruck_35:
# 252 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 2
	goto LittlerootTown_EventScript_EnterTruck_32


# 277 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 278 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 281 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 282 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 283 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 286 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 287 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 288 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 289 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 292 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 293 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 294 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 297 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 298 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 299 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 300 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 301 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 304 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 305 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 305 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 308 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 309 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 310 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 310 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 310 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 313 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 314 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

# 317 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_JumpOffFriendTruck:
# 318 "data/maps/LittlerootTown/scripts.pory"
	jump_right
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 322 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 323 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 324 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 325 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 326 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 327 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 328 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 329 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 330 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 331 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 332 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 333 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 334 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 335 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 340 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 341 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 342 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 343 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 344 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 347 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 350 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 345 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 346 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 348 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 349 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 351 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 352 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 358 "data/maps/LittlerootTown/scripts.pory"
	lock
# 359 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 360 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 361 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 366 "data/maps/LittlerootTown/scripts.pory"
	lock
# 367 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 368 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 369 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 374 "data/maps/LittlerootTown/scripts.pory"
	lock
# 375 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 376 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 377 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 378 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 1
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 388 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 389 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 379 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 380 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 381 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 382 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 383 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 384 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 385 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 394 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 395 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 396 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 401 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 402 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 407 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 408 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 409 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 410 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 411 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 412 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 413 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 418 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 419 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 420 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 421 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 422 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 423 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 424 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 429 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 430 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 431 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 432 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 433 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 434 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 435 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 438 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 439 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 440 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 441 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 442 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 443 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 444 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 444 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 444 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 444 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 445 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 445 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 446 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 447 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 450 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 451 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 454 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 455 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 456 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 456 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 457 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 457 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 457 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 457 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 458 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 459 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 462 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 463 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 464 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 465 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 468 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 469 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 470 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 471 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 472 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 473 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 474 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 474 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 474 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 475 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 475 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 476 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 477 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 480 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 481 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 482 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 483 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 483 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 483 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 484 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 488 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 489 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 490 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 491 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 492 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 493 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 494 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 495 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 496 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 497 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 498 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 499 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 504 "data/maps/LittlerootTown/scripts.pory"
	lock
# 505 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 506 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 511 "data/maps/LittlerootTown/scripts.pory"
	lock
# 512 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 513 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 518 "data/maps/LittlerootTown/scripts.pory"
	lock
# 519 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 520 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 525 "data/maps/LittlerootTown/scripts.pory"
	lock
# 526 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 527 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 532 "data/maps/LittlerootTown/scripts.pory"
	lock
# 533 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 534 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Mom::
# 551 "data/maps/LittlerootTown/scripts.pory"
	lock
# 552 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 553 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_Mom_Text_0, MSGBOX_DEFAULT
# 554 "data/maps/LittlerootTown/scripts.pory"
	release
	end


# 558 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer:
# 559 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 559 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 559 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 559 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 561 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 562 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 562 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 562 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 562 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 565 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 566 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 566 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 566 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 566 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 566 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 569 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 570 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 570 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 573 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 574 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 574 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 574 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 577 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 578 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 578 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 578 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 581 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 582 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 582 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 585 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 586 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 586 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 586 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 586 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 586 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 589 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 590 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 590 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 590 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 590 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 593 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale6:
# 594 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 594 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 594 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 594 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 594 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 594 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 597 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome:
# 598 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 598 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 598 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 598 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 598 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 601 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 602 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 602 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 602 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 602 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 603 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 606 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 607 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 607 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 607 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 607 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 607 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 608 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 611 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 612 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 612 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 613 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 616 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
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
LittlerootTown_Movement_MomReturnHomeFemale2:
# 622 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 622 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 622 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 623 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 626 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 627 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 627 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 628 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 631 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 632 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 632 "data/maps/LittlerootTown/scripts.pory"
	walk_right
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
LittlerootTown_Movement_MomReturnHomeFemale5:
# 637 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 637 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 637 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 637 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 638 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 641 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale6:
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
# 642 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 643 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 646 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 647 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 209 "data/maps/LittlerootTown/scripts.pory"
	.string "They must've locked the truck.$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 212 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_2:
# 271 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_EventScript_Mom_Text_0:
# 553 "data/maps/LittlerootTown/scripts.pory"
	.string "Hi.$"

LittlerootTown_Text_SpencersHouse::
# 538 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 542 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 546 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 650 "data/maps/LittlerootTown/scripts.pory"
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
# 663 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 667 "data/maps/LittlerootTown/scripts.pory"
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
# 679 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 684 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 693 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 704 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 710 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 718 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 724 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 729 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 739 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 744 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 749 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 754 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 758 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
