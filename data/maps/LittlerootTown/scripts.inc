LittlerootTown_MapScripts::
# 38 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 92 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 98 "data/maps/LittlerootTown/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 39 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_VISITED_LITTLEROOT_TOWN
# 40 "data/maps/LittlerootTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 41 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 44 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 47 "data/maps/LittlerootTown/scripts.pory"
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
# 48 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7:
# 63 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 4
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10:
# 68 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_BREN, 4
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16:
# 73 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_HOUSES_STATE_KYLE, 4
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23:
# 78 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_OLDALE_RIVAL_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26:
# 82 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29:
# 85 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32:
# 88 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 42 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 8
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
# 45 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 15
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_8:
# 49 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 50 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_ne LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14
LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13:
# 54 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20
# 57 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21
# 59 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_11:
# 64 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 5
# 65 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 5
# 66 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 5
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_10

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_14:
# 51 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 52 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_13

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_17:
# 69 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 5
# 70 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 5
# 71 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 5
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_16

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_20:
# 56 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 5, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_21:
# 58 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 14, 9
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_22:
# 60 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 4, 17, 16
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_7

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_24:
# 74 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BREN, 5
# 75 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_SPENCER, 5
# 76 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_KYLE, 5
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_23

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_27:
# 79 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 2
# 80 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_26

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_30:
# 83 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_29

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_33:
# 86 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	goto LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_32

LittlerootTown_MapScripts_MAP_SCRIPT_ON_TRANSITION_35:
# 89 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 93 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckSpencer
# 94 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckBren
# 95 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_EventScript_StepOffTruckKyle
# 96 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 99 "data/maps/LittlerootTown/scripts.pory"
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0


LittlerootTown_EventScript_SetTwinPos::
# 104 "data/maps/LittlerootTown/scripts.pory"
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
# 105 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 10, 1
# 106 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_EventScript_SetTwinGuardingRoutePos::
# 111 "data/maps/LittlerootTown/scripts.pory"
	setobjectxyperm 1, 7, 2
# 112 "data/maps/LittlerootTown/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return


LittlerootTown_EventScript_StepOffTruckSpencer::
# 117 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 118 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8004, 5
# 119 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8005, 8
# 120 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GoInsideWithMom
# 121 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
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
	call LittlerootTown_EventScript_GoInsideWithMom
# 133 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
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
	warpsilent MAP_LITTLEROOT_TOWN_KYLES_HOUSE_1F, 2, 8
# 147 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 148 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_GoInsideWithMom::
# 153 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 154 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 155 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
# 156 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 157 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 158 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 159 "data/maps/LittlerootTown/scripts.pory"
	addobject 4
# 160 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitHouse
# 161 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 162 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 163 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 164 "data/maps/LittlerootTown/scripts.pory"
	delay 10
# 165 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerAtTruck
# 166 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 167 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
# 168 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 169 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachDoor
# 170 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
# 171 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 172 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8004, VAR_0x8005
# 173 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 174 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomEnterHouse
# 175 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
# 176 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 177 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
# 178 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
# 179 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
# 180 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8004, VAR_0x8005
# 181 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 182 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
# 183 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return


LittlerootTown_EventScript_EnterTruck::
# 188 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 189 "data/maps/LittlerootTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 190 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 4
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 190 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 13
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 190 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8004, 16
	goto_if_eq LittlerootTown_EventScript_EnterTruck_2
# 223 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_1
LittlerootTown_EventScript_EnterTruck_1:
# 225 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end

LittlerootTown_EventScript_EnterTruck_2:
# 191 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_EventScript_EnterTruck_Text_0, MSGBOX_YESNO
# 192 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 193 "data/maps/LittlerootTown/scripts.pory"
	case YES, LittlerootTown_EventScript_EnterTruck_10
	goto LittlerootTown_EventScript_EnterTruck_1

LittlerootTown_EventScript_EnterTruck_10:
# 194 "data/maps/LittlerootTown/scripts.pory"
	delay 15
# 195 "data/maps/LittlerootTown/scripts.pory"
	playse SE_LEDGE
# 196 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterTruck
# 197 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 199 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_RIVAL_STATE, 1
# 200 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8004
# 201 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_EnterTruck_13
# 206 "data/maps/LittlerootTown/scripts.pory"
	case 13, LittlerootTown_EventScript_EnterTruck_14
# 211 "data/maps/LittlerootTown/scripts.pory"
	case 16, LittlerootTown_EventScript_EnterTruck_15
LittlerootTown_EventScript_EnterTruck_11:
# 217 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_INSIDE_OF_TRUCK, 4, 2
# 218 "data/maps/LittlerootTown/scripts.pory"
	waitstate
	end

LittlerootTown_EventScript_EnterTruck_13:
# 202 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 4
# 203 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_SPENCER_IN_TRUCK
# 204 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
# 205 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
	goto LittlerootTown_EventScript_EnterTruck_11

LittlerootTown_EventScript_EnterTruck_14:
# 207 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 208 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_BREN_IN_TRUCK
# 209 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 210 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_KYLES_HOUSE_TRUCK
	goto LittlerootTown_EventScript_EnterTruck_11

LittlerootTown_EventScript_EnterTruck_15:
# 212 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 6
# 213 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_KYLE_IN_TRUCK
# 214 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_SPENCERS_HOUSE_TRUCK
# 215 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENS_HOUSE_TRUCK
	goto LittlerootTown_EventScript_EnterTruck_11


# 229 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitHouse:
# 230 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 233 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerAtTruck:
# 234 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 235 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_left
	step_end

# 238 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachDoor:
# 239 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 240 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 241 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 244 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomEnterHouse:
# 245 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 246 "data/maps/LittlerootTown/scripts.pory"
	set_invisible
	step_end

# 249 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerApproachDoor:
# 250 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 251 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 252 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 253 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 256 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterHouse:
# 257 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 257 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 260 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerStepOffTruck:
# 261 "data/maps/LittlerootTown/scripts.pory"
	jump_right
# 262 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 262 "data/maps/LittlerootTown/scripts.pory"
	delay_16
# 262 "data/maps/LittlerootTown/scripts.pory"
	delay_16
	step_end

# 265 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PlayerEnterTruck:
# 266 "data/maps/LittlerootTown/scripts.pory"
	jump_left
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
# 270 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 271 "data/maps/LittlerootTown/scripts.pory"
	playse SE_PIN
# 272 "data/maps/LittlerootTown/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 273 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 274 "data/maps/LittlerootTown/scripts.pory"
	delay 80
# 275 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
# 276 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 277 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
# 278 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 279 "data/maps/LittlerootTown/scripts.pory"
	delay 20
# 280 "data/maps/LittlerootTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 281 "data/maps/LittlerootTown/scripts.pory"
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
# 282 "data/maps/LittlerootTown/scripts.pory"
	waitstate
# 283 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
# 288 "data/maps/LittlerootTown/scripts.pory"
	addobject 8
# 289 "data/maps/LittlerootTown/scripts.pory"
	addobject 7
# 290 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 291 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_RESULT
# 292 "data/maps/LittlerootTown/scripts.pory"
	case SPENCER, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3
# 295 "data/maps/LittlerootTown/scripts.pory"
	case BREN, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4
# 298 "data/maps/LittlerootTown/scripts.pory"
	case KYLE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5
LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1:
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_3:
# 293 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 6, 10
# 294 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 5, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_4:
# 296 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 13, 10
# 297 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 14, 10
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_5:
# 299 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 7, 17, 17
# 300 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 8, 18, 17
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade_1


LittlerootTown_EventScript_FatMan::
# 306 "data/maps/LittlerootTown/scripts.pory"
	lock
# 307 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 308 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
# 309 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Boy::
# 314 "data/maps/LittlerootTown/scripts.pory"
	lock
# 315 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 316 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
# 317 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_Twin::
# 322 "data/maps/LittlerootTown/scripts.pory"
	lock
# 323 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 324 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_GoodLuck
# 325 "data/maps/LittlerootTown/scripts.pory"
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_YouSavedBirch
# 326 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_LITTLEROOT_TOWN_STATE, 0
	goto_if_eq LittlerootTown_EventScript_Twin_2
# 336 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 337 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Twin_2:
# 327 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 328 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 329 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 330 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 331 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 332 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 333 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_YouSavedBirch::
# 342 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 343 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
# 344 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GoodLuck::
# 349 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
# 350 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_NeedPokemonTriggerLeft::
# 355 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 356 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerLeft
# 357 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 358 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 359 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnLeft
# 360 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 361 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_NeedPokemonTriggerRight::
# 366 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 367 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinApproachPlayerRight
# 368 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 369 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_DangerousWithoutPokemon
# 370 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinReturnRight
# 371 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 372 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_DangerousWithoutPokemon::
# 377 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
# 378 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 379 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, LittlerootTown_Movement_TwinPushPlayerFromRoute
# 380 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
# 381 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 382 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
# 383 "data/maps/LittlerootTown/scripts.pory"
	closemessage
	return


# 386 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerLeft:
# 387 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 388 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 389 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 390 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 391 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 392 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 392 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 392 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 392 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 393 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 393 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 394 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_left
# 395 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 398 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinPushPlayerFromRoute:
# 399 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 402 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnLeft:
# 403 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 404 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 404 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 405 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 405 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 405 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 405 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 406 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 407 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 410 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_PushPlayerBackFromRoute:
# 411 "data/maps/LittlerootTown/scripts.pory"
	lock_facing_direction
# 412 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 413 "data/maps/LittlerootTown/scripts.pory"
	unlock_facing_direction
	step_end

# 416 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinApproachPlayerRight:
# 417 "data/maps/LittlerootTown/scripts.pory"
	face_right
# 418 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 419 "data/maps/LittlerootTown/scripts.pory"
	disable_jump_landing_ground_effect
# 420 "data/maps/LittlerootTown/scripts.pory"
	jump_in_place_right
# 421 "data/maps/LittlerootTown/scripts.pory"
	delay_8
# 422 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 422 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 422 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 423 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 423 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_up
# 424 "data/maps/LittlerootTown/scripts.pory"
	walk_fast_right
# 425 "data/maps/LittlerootTown/scripts.pory"
	face_down
	step_end

# 428 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_TwinReturnRight:
# 429 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 430 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 431 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 431 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 431 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 432 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
# 436 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 437 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_WalkInPlaceFasterRight
# 438 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 439 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 440 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 441 "data/maps/LittlerootTown/scripts.pory"
	special GetPlayerBigGuyGirlString
# 442 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
# 443 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 444 "data/maps/LittlerootTown/scripts.pory"
	applymovement 1, Common_Movement_FaceOriginalDirection
# 445 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 446 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
# 447 "data/maps/LittlerootTown/scripts.pory"
	releaseall
	end


LittlerootTown_EventScript_TownSign::
# 452 "data/maps/LittlerootTown/scripts.pory"
	lock
# 453 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
# 454 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BirchsLabSign::
# 459 "data/maps/LittlerootTown/scripts.pory"
	lock
# 460 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
# 461 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_SpencersHouseSign::
# 466 "data/maps/LittlerootTown/scripts.pory"
	lock
# 467 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_SpencersHouse, MSGBOX_SIGN
# 468 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_BrensHouseSign::
# 473 "data/maps/LittlerootTown/scripts.pory"
	lock
# 474 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_BrensHouse, MSGBOX_SIGN
# 475 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_KylesHouseSign::
# 480 "data/maps/LittlerootTown/scripts.pory"
	lock
# 481 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_KylesHouse, MSGBOX_SIGN
# 482 "data/maps/LittlerootTown/scripts.pory"
	release
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger0::
# 499 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 500 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 0
# 501 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 10, 9
# 502 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger1::
# 507 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 508 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 1
# 509 "data/maps/LittlerootTown/scripts.pory"
	setobjectxy 4, 11, 9
# 510 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger2::
# 515 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 516 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 2
# 517 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger3::
# 522 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 523 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 3
# 524 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger4::
# 529 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 530 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 4
# 531 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger5::
# 536 "data/maps/LittlerootTown/scripts.pory"
	lockall
# 537 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8008, 5
# 538 "data/maps/LittlerootTown/scripts.pory"
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end


LittlerootTown_EventScript_GiveRunningShoesTrigger::
# 543 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 544 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_2
# 549 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
# 550 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
LittlerootTown_EventScript_GiveRunningShoesTrigger_1:
# 552 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_6
LittlerootTown_EventScript_GiveRunningShoesTrigger_5:
# 556 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_9
LittlerootTown_EventScript_GiveRunningShoesTrigger_8:
# 560 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_12
LittlerootTown_EventScript_GiveRunningShoesTrigger_11:
# 564 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
# 565 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 566 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_15
# 578 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_16
# 598 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_17
LittlerootTown_EventScript_GiveRunningShoesTrigger_14:
# 618 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 619 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 620 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_0x8008, 1
	goto_if_le LittlerootTown_EventScript_GiveRunningShoesTrigger_22
# 630 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_23
# 674 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_GiveRunningShoesTrigger_24
LittlerootTown_EventScript_GiveRunningShoesTrigger_21:
# 718 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 719 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 720 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 721 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger_2:
# 545 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
# 546 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_1

LittlerootTown_EventScript_GiveRunningShoesTrigger_6:
# 553 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 554 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_5

LittlerootTown_EventScript_GiveRunningShoesTrigger_9:
# 557 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 558 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_8

LittlerootTown_EventScript_GiveRunningShoesTrigger_12:
# 561 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 562 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_11

LittlerootTown_EventScript_GiveRunningShoesTrigger_15:
# 567 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 568 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_29
# 572 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_30
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_16:
# 579 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 580 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_32
# 584 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_33
# 588 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_34
# 592 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_35
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_17:
# 599 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 600 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_37
# 604 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_38
# 608 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_39
# 612 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_40
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_22:
# 621 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 622 "data/maps/LittlerootTown/scripts.pory"
	case 0, LittlerootTown_EventScript_GiveRunningShoesTrigger_42
# 625 "data/maps/LittlerootTown/scripts.pory"
	case 1, LittlerootTown_EventScript_GiveRunningShoesTrigger_43
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_23:
# 631 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 632 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_45
# 642 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_46
# 652 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_47
# 662 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_48
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_24:
# 675 "data/maps/LittlerootTown/scripts.pory"
	switch VAR_0x8008
# 676 "data/maps/LittlerootTown/scripts.pory"
	case 2, LittlerootTown_EventScript_GiveRunningShoesTrigger_50
# 686 "data/maps/LittlerootTown/scripts.pory"
	case 3, LittlerootTown_EventScript_GiveRunningShoesTrigger_51
# 696 "data/maps/LittlerootTown/scripts.pory"
	case 4, LittlerootTown_EventScript_GiveRunningShoesTrigger_52
# 706 "data/maps/LittlerootTown/scripts.pory"
	case 5, LittlerootTown_EventScript_GiveRunningShoesTrigger_53
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_29:
# 569 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 570 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 571 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_30:
# 573 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 574 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 575 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayer1
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_32:
# 581 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 582 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 583 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_33:
# 585 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 586 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 587 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_34:
# 589 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 590 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 591 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_35:
# 593 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 594 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 595 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerMale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_37:
# 601 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 602 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 603 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_38:
# 605 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 606 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 607 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_39:
# 609 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 610 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 611 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_40:
# 613 "data/maps/LittlerootTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 614 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 615 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomApproachPlayerFemale5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_14

LittlerootTown_EventScript_GiveRunningShoesTrigger_42:
# 623 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome0
# 624 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_43:
# 626 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHome1
# 627 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_45:
# 633 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale2
# 634 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 635 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 636 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 637 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 638 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 639 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 640 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 641 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_46:
# 643 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale3
# 644 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 645 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 646 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 647 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 648 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 649 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 650 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 651 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_47:
# 653 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale4
# 654 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 655 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 656 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 657 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 658 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 659 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 660 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 661 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_48:
# 663 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeMale5
# 664 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 665 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 666 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 667 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 668 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 669 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 670 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 671 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_50:
# 677 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale2
# 678 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 679 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 680 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 681 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 682 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 683 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 684 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 685 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_51:
# 687 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale3
# 688 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 689 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 690 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 691 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 692 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 693 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 694 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 695 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_52:
# 697 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale4
# 698 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 699 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 700 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 701 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 702 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 703 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 704 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 705 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21

LittlerootTown_EventScript_GiveRunningShoesTrigger_53:
# 707 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomReturnHomeFemale5
# 708 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 709 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 710 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 711 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 712 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 713 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 714 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 715 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger_21


LittlerootTown_EventScript_Mom::
# 726 "data/maps/LittlerootTown/scripts.pory"
	lock
# 727 "data/maps/LittlerootTown/scripts.pory"
	faceplayer
# 728 "data/maps/LittlerootTown/scripts.pory"
	checkfriendchoice
# 729 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, SPENCER
	goto_if_eq LittlerootTown_EventScript_Mom_2
LittlerootTown_EventScript_Mom_1:
# 733 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, BREN
	goto_if_eq LittlerootTown_EventScript_Mom_5
LittlerootTown_EventScript_Mom_4:
# 737 "data/maps/LittlerootTown/scripts.pory"
	compare VAR_RESULT, KYLE
	goto_if_eq LittlerootTown_EventScript_Mom_8
LittlerootTown_EventScript_Mom_7:
# 741 "data/maps/LittlerootTown/scripts.pory"
	call LittlerootTown_EventScript_GiveRunningShoes
# 742 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
# 743 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 744 "data/maps/LittlerootTown/scripts.pory"
	opendoor VAR_0x8009, VAR_0x800A
# 745 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 746 "data/maps/LittlerootTown/scripts.pory"
	applymovement 4, LittlerootTown_Movement_MomExitThroughDoor
# 747 "data/maps/LittlerootTown/scripts.pory"
	waitmovement 0
# 748 "data/maps/LittlerootTown/scripts.pory"
	hideobjectat 4, MAP_LITTLEROOT_TOWN
# 749 "data/maps/LittlerootTown/scripts.pory"
	closedoor VAR_0x8009, VAR_0x800A
# 750 "data/maps/LittlerootTown/scripts.pory"
	waitdooranim
# 751 "data/maps/LittlerootTown/scripts.pory"
	removeobject 4
# 752 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 753 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
# 754 "data/maps/LittlerootTown/scripts.pory"
	release
	end

LittlerootTown_EventScript_Mom_2:
# 730 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 5
# 731 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_1

LittlerootTown_EventScript_Mom_5:
# 734 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 14
# 735 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 8
	goto LittlerootTown_EventScript_Mom_4

LittlerootTown_EventScript_Mom_8:
# 738 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x8009, 17
# 739 "data/maps/LittlerootTown/scripts.pory"
	setvar VAR_0x800A, 15
	goto LittlerootTown_EventScript_Mom_7


LittlerootTown_EventScript_GiveRunningShoes::
# 759 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
# 760 "data/maps/LittlerootTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 761 "data/maps/LittlerootTown/scripts.pory"
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
# 762 "data/maps/LittlerootTown/scripts.pory"
	waitfanfare
# 763 "data/maps/LittlerootTown/scripts.pory"
	setflag FLAG_RECEIVED_RUNNING_SHOES
# 764 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
# 765 "data/maps/LittlerootTown/scripts.pory"
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
# 766 "data/maps/LittlerootTown/scripts.pory"
	closemessage
# 767 "data/maps/LittlerootTown/scripts.pory"
	delay 30
	return


# 771 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer0:
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 772 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 775 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayer1:
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
# 776 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

# 779 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale2:
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 780 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 783 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale3:
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 784 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 787 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale4:
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 788 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 791 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerMale5:
# 792 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 792 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 792 "data/maps/LittlerootTown/scripts.pory"
	walk_right
	step_end

# 795 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale2:
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 796 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 799 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale3:
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 800 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 803 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale4:
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 804 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 807 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomApproachPlayerFemale5:
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 808 "data/maps/LittlerootTown/scripts.pory"
	walk_left
	step_end

# 811 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome0:
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 812 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 815 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHome1:
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_down
# 816 "data/maps/LittlerootTown/scripts.pory"
	walk_down
	step_end

# 819 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale2:
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 820 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 821 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 824 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale3:
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 825 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 826 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 829 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale4:
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 830 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 831 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 834 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeMale5:
# 835 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 835 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 835 "data/maps/LittlerootTown/scripts.pory"
	walk_left
# 836 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 839 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale2:
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 840 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 841 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 844 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale3:
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 845 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 846 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 849 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale4:
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 850 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 851 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 854 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomReturnHomeFemale5:
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 855 "data/maps/LittlerootTown/scripts.pory"
	walk_right
# 856 "data/maps/LittlerootTown/scripts.pory"
	walk_in_place_faster_up
	step_end

# 859 "data/maps/LittlerootTown/scripts.pory"
LittlerootTown_Movement_MomExitThroughDoor:
# 860 "data/maps/LittlerootTown/scripts.pory"
	walk_up
	step_end

LittlerootTown_EventScript_EnterTruck_Text_0:
# 191 "data/maps/LittlerootTown/scripts.pory"
	.string "Would you like to enter the truck?$"

LittlerootTown_EventScript_EnterTruck_Text_1:
# 223 "data/maps/LittlerootTown/scripts.pory"
	.string "This truck has a cool logo!$"

LittlerootTown_Text_SpencersHouse::
# 486 "data/maps/LittlerootTown/scripts.pory"
	.string "SPENCER'S HOUSE$"

LittlerootTown_Text_BrensHouse::
# 490 "data/maps/LittlerootTown/scripts.pory"
	.string "BREN'S HOUSE$"

LittlerootTown_Text_KylesHouse::
# 494 "data/maps/LittlerootTown/scripts.pory"
	.string "KYLE'S HOUSE$"

LittlerootTown_Text_OurNewHomeLetsGoInside::
# 863 "data/maps/LittlerootTown/scripts.pory"
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
# 876 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes::
# 880 "data/maps/LittlerootTown/scripts.pory"
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
# 892 "data/maps/LittlerootTown/scripts.pory"
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes::
# 897 "data/maps/LittlerootTown/scripts.pory"
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens::
# 906 "data/maps/LittlerootTown/scripts.pory"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems::
# 917 "data/maps/LittlerootTown/scripts.pory"
	.string "If you use a PC, you can store items\n"
	.string "and POKéMON.\p"
	.string "The power of science is staggering!$"

LittlerootTown_Text_BirchSpendsDaysInLab::
# 923 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH spends days in his LAB\n"
	.string "studying, then he'll suddenly go out in\l"
	.string "the wild to do more research…\p"
	.string "When does PROF. BIRCH spend time\n"
	.string "at home?$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut::
# 931 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon::
# 937 "data/maps/LittlerootTown/scripts.pory"
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening::
# 942 "data/maps/LittlerootTown/scripts.pory"
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch::
# 952 "data/maps/LittlerootTown/scripts.pory"
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon::
# 957 "data/maps/LittlerootTown/scripts.pory"
	.string "Are you going to catch POKéMON?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign::
# 962 "data/maps/LittlerootTown/scripts.pory"
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab::
# 967 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab::
# 971 "data/maps/LittlerootTown/scripts.pory"
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"
