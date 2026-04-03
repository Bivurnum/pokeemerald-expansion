SpaInterior_MapScripts::
# 6 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SpaInterior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 22 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpaInterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/SpaInterior/scripts.pory"
	switch VAR_SPA_INTRO_STATE
# 8 "data/maps/SpaInterior/scripts.pory"
	case 2, SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
# 11 "data/maps/SpaInterior/scripts.pory"
	case 4, SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	return

SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
# 9 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm RED_INT_ID, 24, 15
# 10 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm BLUE_INT_ID, 31, 11
	return

SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
# 12 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm RED_INT_ID, 4, 14
	return

SpaInterior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 16 "data/maps/SpaInterior/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 4, SpaInterior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

SpaInterior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 17 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 18 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_EAST
	end

SpaInterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 23 "data/maps/SpaInterior/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 2, SpaInterior_OnFrame_0
# 24 "data/maps/SpaInterior/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 4, SpaInterior_OnFrame_1
	.2byte 0


SpaInterior_OnTransition_0::
# 29 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm RED_INT_ID, 24, 15
# 30 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm BLUE_INT_ID, 31, 11
	return


SpaInterior_OnFrame_0::
# 35 "data/maps/SpaInterior/scripts.pory"
	lock
# 36 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_0
# 39 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 40 "data/maps/SpaInterior/scripts.pory"
	playse SE_PIN
# 41 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_1
# 45 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 46 "data/maps/SpaInterior/scripts.pory"
	delay 60
# 47 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_2
# 50 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_0
# 53 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 54 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_0
# 55 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 56 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 57 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 58 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_EAST
# 59 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_1
# 60 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 61 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 62 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 63 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 64 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_3
# 69 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 70 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_2
# 71 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 72 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 73 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_3
# 74 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 75 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 76 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 77 "data/maps/SpaInterior/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_4
# 81 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 82 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_4
# 83 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 84 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 85 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 86 "data/maps/SpaInterior/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_5
# 90 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 91 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_5
# 92 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 93 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 94 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_6
# 95 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 96 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 97 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_7
# 98 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 99 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_SOUTH
# 100 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 101 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_SOUTH
# 102 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 103 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_8
# 117 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_9
# 122 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 123 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_WEST
# 124 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 125 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 126 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_10
# 129 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 130 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_EAST
# 131 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 132 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 133 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_11
# 136 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 137 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 138 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_12
# 141 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 142 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 143 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_13
# 147 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_SOUTH
# 148 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_SOUTH
# 149 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 150 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_14
# 151 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 152 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_6
# 158 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_7
# 164 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_8
# 172 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 173 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 174 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_0
# 177 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 178 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_9
# 181 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_15
# 183 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 184 "data/maps/SpaInterior/scripts.pory"
	delay 90
# 185 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_SOUTH
# 186 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_16
# 191 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 192 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 193 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_17
# 198 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 199 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 200 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_18
# 202 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 203 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_10
# 208 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_11
# 213 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_12
# 218 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 219 "data/maps/SpaInterior/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 3
# 220 "data/maps/SpaInterior/scripts.pory"
	warp MAP_SPA_MOUNTAIN, 0
# 221 "data/maps/SpaInterior/scripts.pory"
	waitstate
	return


SpaInterior_OnFrame_1::
# 225 "data/maps/SpaInterior/scripts.pory"
	lock
# 226 "data/maps/SpaInterior/scripts.pory"
	delay 60
# 227 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_1_Movement_0
# 232 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 233 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 234 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 235 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_0
# 244 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 245 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 246 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_WEST
# 247 "data/maps/SpaInterior/scripts.pory"
	delay 90
# 248 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 249 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_NORTH
# 250 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_1
# 256 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 257 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_1_Movement_1
# 267 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_1_Movement_2
# 275 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 276 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_2
# 278 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 279 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_1_Movement_3
# 288 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 289 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_3
# 290 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 291 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 292 "data/maps/SpaInterior/scripts.pory"
	playfanfare MUS_OBTAIN_BERRY
# 293 "data/maps/SpaInterior/scripts.pory"
	setflag FLAG_SPA_OBTAINED_BERRY
# 294 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_4
# 295 "data/maps/SpaInterior/scripts.pory"
	waitfanfare
# 296 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 297 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 298 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 299 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_5
# 309 "data/maps/SpaInterior/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 5
# 310 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end


SpaInterior_EventScript_KimonoRed::
# 315 "data/maps/SpaInterior/scripts.pory"
	lock
# 316 "data/maps/SpaInterior/scripts.pory"
	faceplayer
# 317 "data/maps/SpaInterior/scripts.pory"
	switch VAR_SPA_INTRO_STATE
# 318 "data/maps/SpaInterior/scripts.pory"
	case 5, SpaInterior_EventScript_KimonoRed_3
# 327 "data/maps/SpaInterior/scripts.pory"
	case 6, SpaInterior_EventScript_KimonoRed_4
# 334 "data/maps/SpaInterior/scripts.pory"
	case 7, SpaInterior_EventScript_KimonoRed_5
# 339 "data/maps/SpaInterior/scripts.pory"
	case 8, SpaInterior_EventScript_KimonoRed_6
# 340 "data/maps/SpaInterior/scripts.pory"
	case 12, SpaInterior_EventScript_KimonoRed_6
# 341 "data/maps/SpaInterior/scripts.pory"
	case 14, SpaInterior_EventScript_KimonoRed_6
# 346 "data/maps/SpaInterior/scripts.pory"
	case 9, SpaInterior_EventScript_KimonoRed_7
# 349 "data/maps/SpaInterior/scripts.pory"
	case 10, SpaInterior_EventScript_KimonoRed_8
# 359 "data/maps/SpaInterior/scripts.pory"
	case 11, SpaInterior_EventScript_KimonoRed_9
# 371 "data/maps/SpaInterior/scripts.pory"
	case 13, SpaInterior_EventScript_KimonoRed_10
# 374 "data/maps/SpaInterior/scripts.pory"
	case 15, SpaInterior_EventScript_KimonoRed_11
SpaInterior_EventScript_KimonoRed_1:
# 379 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 380 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end

SpaInterior_EventScript_KimonoRed_3:
# 319 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_0
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_4:
# 328 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_1
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_5:
# 335 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_2
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_6:
# 342 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_3
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_7:
# 347 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_4
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_8:
# 350 "data/maps/SpaInterior/scripts.pory"
	getnumbugs
# 351 "data/maps/SpaInterior/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_gt SpaInterior_EventScript_KimonoRed_12
# 356 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_4
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_9:
# 360 "data/maps/SpaInterior/scripts.pory"
	getnumbugs
# 361 "data/maps/SpaInterior/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_gt SpaInterior_EventScript_KimonoRed_15
# 366 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_3
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_10:
# 372 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_6
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_11:
# 375 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_7
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_12:
# 352 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_5
	goto SpaInterior_EventScript_KimonoRed_1

SpaInterior_EventScript_KimonoRed_15:
# 362 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoRed_Text_5
	goto SpaInterior_EventScript_KimonoRed_1


SpaInterior_EventScript_KimonoBlue::
# 385 "data/maps/SpaInterior/scripts.pory"
	lock
# 386 "data/maps/SpaInterior/scripts.pory"
	faceplayer
# 387 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_KimonoBlue_Text_0
# 389 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 390 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_WEST
# 391 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end


SpaInterior_EventScript_CynthiaSick::
# 396 "data/maps/SpaInterior/scripts.pory"
	lock
# 397 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_CynthiaSick_Text_0
# 398 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 399 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 400 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end


# 36 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_0:
# 37 "data/maps/SpaInterior/scripts.pory"
	walk_up
	step_end

# 41 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_1:
# 42 "data/maps/SpaInterior/scripts.pory"
	face_down
# 43 "data/maps/SpaInterior/scripts.pory"
	emote_exclamation_mark
	step_end

# 47 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_2:
# 48 "data/maps/SpaInterior/scripts.pory"
	walk_down
	step_end

# 64 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_3:
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 66 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 66 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 66 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 66 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 66 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 66 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 67 "data/maps/SpaInterior/scripts.pory"
	delay_8
	step_end

# 78 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_4:
# 79 "data/maps/SpaInterior/scripts.pory"
	jump_in_place_left
	step_end

# 87 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_5:
# 88 "data/maps/SpaInterior/scripts.pory"
	jump_in_place_right
	step_end

# 152 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_6:
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 156 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 158 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_7:
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 161 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 161 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 161 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 161 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 161 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 161 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 162 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 164 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_8:
# 165 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 169 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 169 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 169 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 169 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 169 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 170 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 178 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_9:
# 179 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 179 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 179 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 179 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
	step_end

# 203 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_10:
# 204 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 205 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 205 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 206 "data/maps/SpaInterior/scripts.pory"
	set_invisible
	step_end

# 208 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_11:
# 209 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 210 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 210 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 210 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 211 "data/maps/SpaInterior/scripts.pory"
	set_invisible
	step_end

# 213 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_12:
# 214 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 215 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 216 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 216 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 216 "data/maps/SpaInterior/scripts.pory"
	walk_up
	step_end

# 227 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_0:
# 228 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 228 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 229 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 229 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 229 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 229 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 230 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 257 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_1:
# 258 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 259 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 265 "data/maps/SpaInterior/scripts.pory"
	face_left
	step_end

# 267 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_2:
# 268 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 268 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 273 "data/maps/SpaInterior/scripts.pory"
	walk_right
	step_end

# 279 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_3:
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 282 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 282 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 282 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 282 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 283 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 283 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 283 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 283 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 286 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 286 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 286 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 286 "data/maps/SpaInterior/scripts.pory"
	walk_left
	step_end

SpaInterior_OnFrame_0_Text_0:
# 54 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Welcome!\nYou must be the new temple apprentice.\pYou've arrived at a good time.\nEverything's so exciting!\pCome with me.\pI'll introduce you to my partner.$"

SpaInterior_OnFrame_0_Text_1:
# 59 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}URESHI!!!!!$"

SpaInterior_OnFrame_0_Text_2:
# 70 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}What do you want, Itami?!$"

SpaInterior_OnFrame_0_Text_3:
# 73 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}New apprentice, I'd like you to\nmeet Ureshi.\pWhile I'm keeping the temple clean\nand proper, she's outside playing\lin the dirt.$"

SpaInterior_OnFrame_0_Text_4:
# 82 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Humph!\nI keep the plants healthy and\lthe grounds beautiful.\pAt least I get some sun instead of\nsitting inside all day.$"

SpaInterior_OnFrame_0_Text_5:
# 91 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Harumph!$"

SpaInterior_OnFrame_0_Text_6:
# 94 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Aren't you going to tell our\nnew apprentice about the excitement\laround here?$"

SpaInterior_OnFrame_0_Text_7:
# 97 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}I was just about to!$"

SpaInterior_OnFrame_0_Text_8:
# 103 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Ahem.\n"
	.string "As you know, hundreds of years ago\l"
	.string "this temple was a place for\l"
	.string "mythical Pokémon to come and be cared\l"
	.string "for by the temple stewards.\p"
	.string "It has been many ages since any\n"
	.string "mythical Pokémon have been seen.\l"
	.string "However, just recently some Pokémon\l"
	.string "with strange patterns have been\l"
	.string "showing up in droves on the mountain!\p"
	.string "Isn't that inte--?$"

SpaInterior_OnFrame_0_Text_9:
# 117 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}So we called in an expert on\n"
	.string "Pokémon mythology.\l"
	.string "She's out there right now\l"
	.string "figuring out what to do.$"

SpaInterior_OnFrame_0_Text_10:
# 126 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}What was her name?\n"
	.string "Korrina?$"

SpaInterior_OnFrame_0_Text_11:
# 133 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}No, no,\n"
	.string "I think it was Candice.$"

SpaInterior_OnFrame_0_Text_12:
# 138 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}In any case, she's been out there\n"
	.string "a long time.\l"
	.string "Do you think we should check on her?$"

SpaInterior_OnFrame_0_Text_13:
# 143 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Why, Ureshi!\n"
	.string "I do believe that is the first good\l"
	.string "idea you've had all day.\l"
	.string "Let's go find her.$"

SpaInterior_OnFrame_0_Text_14:
# 150 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You should come too, apprentice.$"

SpaInterior_OnFrame_0_Text_15:
# 181 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Oh, Clair! Can you hear us?\n"
	.string "Come meet our new apprentice!$"

SpaInterior_OnFrame_0_Text_16:
# 186 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}That's peculiar.\n"
	.string "She ALWAYS responds to me.\p"
	.string "Do you think something could've\n"
	.string "happened to her?$"

SpaInterior_OnFrame_0_Text_17:
# 193 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You're right.\n"
	.string "This is concerning.\p"
	.string "I know she told us not to go out there,\n"
	.string "but should we check on her?$"

SpaInterior_OnFrame_0_Text_18:
# 200 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}There's no harm in taking a peek, right?\n"
	.string "Come on.$"

SpaInterior_OnFrame_1_Text_0:
# 235 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}She doesn't seem to be in bad shape, but\n"
	.string "we just can't seem to wake her.\p"
	.string "We fear the Pokémon of myth were\n"
	.string "displeased and put a curse on her.\p"
	.string "The only way to wake her might be to\n"
	.string "calm the deities by tending to them\l"
	.string "like in ancient times.$"

SpaInterior_OnFrame_1_Text_1:
# 250 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}We'd, uh, love to do it ourselves,\n"
	.string "but we've been explicitly told not to go\l"
	.string "up onto the mountain.\p"
	.string "I'm sure you understand.\n"
	.string "C'mon. I'll get you set up.$"

SpaInterior_OnFrame_1_Text_2:
# 276 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Wait right here. I'm going to go get some\n"
	.string "supplies for you.$"

SpaInterior_OnFrame_1_Text_3:
# 289 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Here. Take these.$"

SpaInterior_OnFrame_1_Text_4:
# 294 "data/maps/SpaInterior/scripts.pory"
	.string "Received a bunch of berries!$"

SpaInterior_OnFrame_1_Text_5:
# 299 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Even some Pokémon deities should\n"
	.string "like to eat berries.\l"
	.string "I hope they'll come in handy.\p"
	.string "Now go out and pamper those Pokémon!\n"
	.string "Consider this your first assignment\l"
	.string "as temple apprentice.\p"
	.string "Come talk to me if you need\n"
	.string "any assistance.$"

SpaInterior_EventScript_KimonoRed_Text_0:
# 319 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}See if any of the Pokémon will\n"
	.string "eat a berry.\p"
	.string "I'm sure they'd love to be hand fed,\n"
	.string "so hold it close to their mouth.\p"
	.string "Try different Pokémon and see if\n"
	.string "you get any takers.$"

SpaInterior_EventScript_KimonoRed_Text_1:
# 328 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}If a Pokémon trusts you enough\n"
	.string "to eat a berry from your hand,\l"
	.string "try petting it.\p"
	.string "All Pokémon love to be pet,\n"
	.string "especially on the head.$"

SpaInterior_EventScript_KimonoRed_Text_2:
# 335 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}That claw look perfect for\n"
	.string "satisfying a persistent itch.\p"
	.string "Maybe you can help a Pokémon with it.$"

SpaInterior_EventScript_KimonoRed_Text_3:
# 342 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Don't forget to pet those Pokémon\n"
	.string "if they'll let you.\p"
	.string "Nothing beats a good head pat!$"

SpaInterior_EventScript_KimonoRed_Text_4:
# 347 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Carful with that sticky honey!\n"
	.string "It might attract bugs.$"

SpaInterior_EventScript_KimonoRed_Text_5:
# 352 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}AHH! Bugs belong outside where\n"
	.string "the birds can eat them!$"

SpaInterior_EventScript_KimonoRed_Text_6:
# 372 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Yow! That orb looks hot!\n"
	.string "Careful that it doesn't melt anything.$"

SpaInterior_EventScript_KimonoRed_Text_7:
# 375 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You helped all of the Pokémon?\n"
	.string "I think there might be one more\l"
	.string "somewhere.$"

SpaInterior_EventScript_KimonoBlue_Text_0:
# 387 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}I'm making sure she's comfortable.\n"
	.string "Hopefully she will wake soon.$"

SpaInterior_EventScript_CynthiaSick_Text_0:
# 397 "data/maps/SpaInterior/scripts.pory"
	.string "She's sleeping peacefully.$"
