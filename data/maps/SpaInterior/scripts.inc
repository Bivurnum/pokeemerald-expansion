SpaInterior_MapScripts::
# 6 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpaInterior_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 15 "data/maps/SpaInterior/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SpaInterior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 21 "data/maps/SpaInterior/scripts.pory"
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
	end

SpaInterior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 22 "data/maps/SpaInterior/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 2, SpaInterior_OnFrame_0
# 23 "data/maps/SpaInterior/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 4, SpaInterior_OnFrame_1
	.2byte 0


SpaInterior_OnTransition_0::
# 28 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm RED_INT_ID, 24, 15
# 29 "data/maps/SpaInterior/scripts.pory"
	setobjectxyperm BLUE_INT_ID, 31, 11
	return


SpaInterior_OnFrame_0::
# 34 "data/maps/SpaInterior/scripts.pory"
	lock
# 35 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_0
# 38 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 39 "data/maps/SpaInterior/scripts.pory"
	playse SE_PIN
# 40 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_1
# 44 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 45 "data/maps/SpaInterior/scripts.pory"
	delay 60
# 46 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_2
# 49 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_0
# 52 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 53 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_0
# 54 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 55 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 56 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 57 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_EAST
# 58 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_1
# 59 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 60 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 61 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 62 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 63 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_3
# 68 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 69 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_2
# 70 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 71 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 72 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_3
# 73 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 74 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 75 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 76 "data/maps/SpaInterior/scripts.pory"
	playse SE_LEDGE
# 77 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_4
# 80 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 81 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_4
# 82 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 83 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 84 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 85 "data/maps/SpaInterior/scripts.pory"
	playse SE_LEDGE
# 86 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_5
# 89 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 90 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_5
# 91 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 92 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 93 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_6
# 94 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 95 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 96 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_7
# 97 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 98 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_SOUTH
# 99 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 100 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_SOUTH
# 101 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 102 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_8
# 116 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_9
# 121 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 122 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_WEST
# 123 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 124 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 125 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_10
# 128 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 129 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_EAST
# 130 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 131 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 132 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_11
# 135 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 136 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 137 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_12
# 140 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 141 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 142 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_13
# 146 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_SOUTH
# 147 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_SOUTH
# 148 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 149 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_14
# 150 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 151 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_6
# 157 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_7
# 163 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_8
# 171 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 172 "data/maps/SpaInterior/scripts.pory"
	delay 30
# 173 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_0
# 176 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 177 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_9
# 180 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_15
# 182 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 183 "data/maps/SpaInterior/scripts.pory"
	delay 90
# 184 "data/maps/SpaInterior/scripts.pory"
	turnobject BLUE_INT_ID, DIR_SOUTH
# 185 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_16
# 190 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 191 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 192 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_17
# 197 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 198 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 199 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_0_Text_18
# 201 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 202 "data/maps/SpaInterior/scripts.pory"
	applymovement BLUE_INT_ID, SpaInterior_OnFrame_0_Movement_10
# 207 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_0_Movement_11
# 212 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_0_Movement_12
# 217 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 218 "data/maps/SpaInterior/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 3
# 219 "data/maps/SpaInterior/scripts.pory"
	warp MAP_SPA_MOUNTAIN, 0
# 220 "data/maps/SpaInterior/scripts.pory"
	waitstate
	return


SpaInterior_OnFrame_1::
# 224 "data/maps/SpaInterior/scripts.pory"
	lock
# 225 "data/maps/SpaInterior/scripts.pory"
	delay 60
# 226 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_1_Movement_0
# 231 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 232 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 233 "data/maps/SpaInterior/scripts.pory"
	delay 8
# 234 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_0
# 243 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 244 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 245 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_WEST
# 246 "data/maps/SpaInterior/scripts.pory"
	delay 90
# 247 "data/maps/SpaInterior/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 248 "data/maps/SpaInterior/scripts.pory"
	turnobject RED_INT_ID, DIR_NORTH
# 249 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_1
# 255 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 256 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_1_Movement_1
# 266 "data/maps/SpaInterior/scripts.pory"
	applymovement LOCALID_PLAYER, SpaInterior_OnFrame_1_Movement_2
# 274 "data/maps/SpaInterior/scripts.pory"
	waitmovement LOCALID_PLAYER
# 275 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_2
# 277 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 278 "data/maps/SpaInterior/scripts.pory"
	applymovement RED_INT_ID, SpaInterior_OnFrame_1_Movement_3
# 287 "data/maps/SpaInterior/scripts.pory"
	waitmovement 0
# 288 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_3
# 289 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 290 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 291 "data/maps/SpaInterior/scripts.pory"
	playfanfare MUS_OBTAIN_BERRY
# 292 "data/maps/SpaInterior/scripts.pory"
	setflag FLAG_SPA_OBTAINED_BERRY
# 293 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_4
# 294 "data/maps/SpaInterior/scripts.pory"
	waitfanfare
# 295 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 296 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 297 "data/maps/SpaInterior/scripts.pory"
	delay 16
# 298 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_OnFrame_1_Text_5
# 308 "data/maps/SpaInterior/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 5
# 309 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end


SpaInterior_EventScript_KimonoRed::
	return


SpaInterior_EventScript_KimonoBlue::
	return


SpaInterior_EventScript_CynthiaSick::
# 322 "data/maps/SpaInterior/scripts.pory"
	lock
# 323 "data/maps/SpaInterior/scripts.pory"
	msgbox SpaInterior_EventScript_CynthiaSick_Text_0
# 324 "data/maps/SpaInterior/scripts.pory"
	waitmessage
# 325 "data/maps/SpaInterior/scripts.pory"
	closemessage
# 326 "data/maps/SpaInterior/scripts.pory"
	releaseall
	end


# 35 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_0:
# 36 "data/maps/SpaInterior/scripts.pory"
	walk_up
	step_end

# 40 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_1:
# 41 "data/maps/SpaInterior/scripts.pory"
	face_down
# 42 "data/maps/SpaInterior/scripts.pory"
	emote_exclamation_mark
	step_end

# 46 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_2:
# 47 "data/maps/SpaInterior/scripts.pory"
	walk_down
	step_end

# 63 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_3:
# 64 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 64 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 64 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 64 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 64 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 65 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 66 "data/maps/SpaInterior/scripts.pory"
	delay_8
	step_end

# 77 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_4:
# 78 "data/maps/SpaInterior/scripts.pory"
	jump_in_place_left
	step_end

# 86 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_5:
# 87 "data/maps/SpaInterior/scripts.pory"
	jump_in_place_right
	step_end

# 151 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_6:
# 152 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 152 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 152 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 152 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 152 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 152 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 153 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 154 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 155 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 157 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_7:
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 158 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 159 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 160 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 161 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 163 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_8:
# 164 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 165 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 166 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 167 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 168 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 169 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 177 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_9:
# 178 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 178 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 178 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
# 178 "data/maps/SpaInterior/scripts.pory"
	walk_in_place_up
	step_end

# 202 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_10:
# 203 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 204 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 204 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 205 "data/maps/SpaInterior/scripts.pory"
	set_invisible
	step_end

# 207 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_11:
# 208 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 209 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 209 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 209 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 210 "data/maps/SpaInterior/scripts.pory"
	set_invisible
	step_end

# 212 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_0_Movement_12:
# 213 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 214 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 215 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 215 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 215 "data/maps/SpaInterior/scripts.pory"
	walk_up
	step_end

# 226 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_0:
# 227 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 227 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 228 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 228 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 228 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 228 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 229 "data/maps/SpaInterior/scripts.pory"
	face_up
	step_end

# 256 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_1:
# 257 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 258 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 259 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 259 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 260 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 261 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 262 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 263 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 264 "data/maps/SpaInterior/scripts.pory"
	face_left
	step_end

# 266 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_2:
# 267 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 267 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 268 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 268 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 268 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 269 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 270 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 271 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 272 "data/maps/SpaInterior/scripts.pory"
	walk_right
	step_end

# 278 "data/maps/SpaInterior/scripts.pory"
SpaInterior_OnFrame_1_Movement_3:
# 279 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 279 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 279 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 279 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 280 "data/maps/SpaInterior/scripts.pory"
	walk_down
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 281 "data/maps/SpaInterior/scripts.pory"
	walk_right
# 282 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 282 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 282 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 282 "data/maps/SpaInterior/scripts.pory"
	delay_16
# 283 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 283 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 283 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 283 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 284 "data/maps/SpaInterior/scripts.pory"
	walk_up
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_left
# 285 "data/maps/SpaInterior/scripts.pory"
	walk_left
	step_end

SpaInterior_OnFrame_0_Text_0:
# 53 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Welcome!\nYou must be the new temple apprentice.\pYou've arrived at a good time.\nEverything's so exciting!\pCome with me.\pI'll introduce you to my partner.$"

SpaInterior_OnFrame_0_Text_1:
# 58 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}URESHI!!!!!$"

SpaInterior_OnFrame_0_Text_2:
# 69 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}What do you want, Itami?!$"

SpaInterior_OnFrame_0_Text_3:
# 72 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}New apprentice, I'd like you to\nmeet Ureshi.\pWhile I'm keeping the temple clean\nand proper, she's outside playing\lin the dirt.$"

SpaInterior_OnFrame_0_Text_4:
# 81 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Humph!\nI keep the plants healthy and\lthe grounds beautiful.\pAt least I get some sun instead of\nsitting inside all day.$"

SpaInterior_OnFrame_0_Text_5:
# 90 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Harumph!$"

SpaInterior_OnFrame_0_Text_6:
# 93 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Aren't you going to tell our\nnew apprentice about the excitement\laround here?$"

SpaInterior_OnFrame_0_Text_7:
# 96 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}I was just about to!$"

SpaInterior_OnFrame_0_Text_8:
# 102 "data/maps/SpaInterior/scripts.pory"
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
# 116 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}So we called in an expert on\n"
	.string "Pokémon mythology.\l"
	.string "She's out there right now\l"
	.string "figuring out what to do.$"

SpaInterior_OnFrame_0_Text_10:
# 125 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}What was her name?\n"
	.string "Korrina?$"

SpaInterior_OnFrame_0_Text_11:
# 132 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}No, no,\n"
	.string "I think it was Candice.$"

SpaInterior_OnFrame_0_Text_12:
# 137 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}In any case, she's been out there\n"
	.string "a long time.\l"
	.string "Do you think we should check on her?$"

SpaInterior_OnFrame_0_Text_13:
# 142 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Why, Ureshi!\n"
	.string "I do believe that is the first good\l"
	.string "idea you've had all day.\l"
	.string "Let's go find her.$"

SpaInterior_OnFrame_0_Text_14:
# 149 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You should come too, apprentice.$"

SpaInterior_OnFrame_0_Text_15:
# 180 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}Oh, Clair! Can you hear us?\n"
	.string "Come meet our new apprentice!$"

SpaInterior_OnFrame_0_Text_16:
# 185 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}That's peculiar.\n"
	.string "She ALWAYS responds to me.\p"
	.string "Do you think something could've\n"
	.string "happened to her?$"

SpaInterior_OnFrame_0_Text_17:
# 192 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}You're right.\n"
	.string "This is concerning.\p"
	.string "I know she told us not to go out there,\n"
	.string "but should we check on her?$"

SpaInterior_OnFrame_0_Text_18:
# 199 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR BLUE}There's no harm in taking a peek, right?\n"
	.string "Come on.$"

SpaInterior_OnFrame_1_Text_0:
# 234 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}She doesn't seem to be in bad shape, but\n"
	.string "we just can't seem to wake her.\p"
	.string "We fear the Pokémon of myth were\n"
	.string "displeased and put a curse on her.\p"
	.string "The only way to wake her might be to\n"
	.string "calm the deities by tending to them\l"
	.string "like in ancient times.$"

SpaInterior_OnFrame_1_Text_1:
# 249 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}We'd, uh, love to do it ourselves,\n"
	.string "but we've been explicitly told not to go\l"
	.string "up onto the mountain.\p"
	.string "I'm sure you understand.\n"
	.string "C'mon. I'll get you set up.$"

SpaInterior_OnFrame_1_Text_2:
# 275 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Wait right here. I'm going to go get some\n"
	.string "supplies for you.$"

SpaInterior_OnFrame_1_Text_3:
# 288 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Here. Take these.$"

SpaInterior_OnFrame_1_Text_4:
# 293 "data/maps/SpaInterior/scripts.pory"
	.string "Received a bunch of berries!$"

SpaInterior_OnFrame_1_Text_5:
# 298 "data/maps/SpaInterior/scripts.pory"
	.string "{COLOR RED}Even some Pokémon deities should\n"
	.string "like to eat berries.\l"
	.string "I hope they'll come in handy.\p"
	.string "Now go out and pamper those Pokémon!\n"
	.string "Consider this your first assignment\l"
	.string "as temple apprentice.\p"
	.string "Come talk to me if you need\n"
	.string "any assistance.$"

SpaInterior_EventScript_CynthiaSick_Text_0:
# 323 "data/maps/SpaInterior/scripts.pory"
	.string "She's sleeping peacefully.$"
