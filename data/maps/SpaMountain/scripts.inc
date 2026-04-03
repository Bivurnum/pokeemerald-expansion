SpaMountain_MapScripts::
# 6 "data/maps/SpaMountain/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SpaMountain_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 11 "data/maps/SpaMountain/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpaMountain_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpaMountain_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 7 "data/maps/SpaMountain/scripts.pory"
	goto_if_set FLAG_BOULDER_MOVED, SpaMountain_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SpaMountain_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 8 "data/maps/SpaMountain/scripts.pory"
	setobjectxyperm BOULDER_ID, 16, 20
	return

SpaMountain_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/SpaMountain/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 3, SpaMountain_OnFrame_0
	.2byte 0


SpaMountain_OnFrame_0::
# 17 "data/maps/SpaMountain/scripts.pory"
	lock
# 18 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_OnFrame_0_Movement_0
# 21 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 22 "data/maps/SpaMountain/scripts.pory"
	playse SE_PIN
# 23 "data/maps/SpaMountain/scripts.pory"
	applymovement RED_MTN_ID, SpaMountain_OnFrame_0_Movement_1
# 26 "data/maps/SpaMountain/scripts.pory"
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_1
# 29 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 30 "data/maps/SpaMountain/scripts.pory"
	delay 60
# 31 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_OnFrame_0_Movement_0
# 34 "data/maps/SpaMountain/scripts.pory"
	applymovement RED_MTN_ID, SpaMountain_OnFrame_0_Movement_2
# 38 "data/maps/SpaMountain/scripts.pory"
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_3
# 44 "data/maps/SpaMountain/scripts.pory"
	waitmovement BLUE_MTN_ID
# 45 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_OnFrame_0_Text_0
# 47 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 48 "data/maps/SpaMountain/scripts.pory"
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_4
# 51 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 52 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_OnFrame_0_Text_1
# 57 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 58 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_HIDE_CYNTHIA_SICK_MTN
# 59 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_HIDE_KIMONO_RED_MOUNTAIN
# 60 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_HIDE_KIMONO_BLUE_MOUNTAIN
# 61 "data/maps/SpaMountain/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 4
# 62 "data/maps/SpaMountain/scripts.pory"
	warp MAP_SPA_INTERIOR, 8, 15
# 63 "data/maps/SpaMountain/scripts.pory"
	waitstate
	return


SpaMountain_EventScript_Rattata::
# 67 "data/maps/SpaMountain/scripts.pory"
	lock
# 68 "data/maps/SpaMountain/scripts.pory"
	startspa 0
# 69 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Rattata_2
# 95 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Rattata_3
SpaMountain_EventScript_Rattata_1:
# 105 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Rattata_2:
# 70 "data/maps/SpaMountain/scripts.pory"
	faceplayer
# 71 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_SPA_OBTAINED_CLAW
# 72 "data/maps/SpaMountain/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 73 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Rattata_Text_0
# 74 "data/maps/SpaMountain/scripts.pory"
	waitfanfare
# 75 "data/maps/SpaMountain/scripts.pory"
	waitmessage
# 76 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 77 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/SpaMountain/scripts.pory"
	applymovement RATTATA_ID, SpaMountain_EventScript_Rattata_Movement_0
# 81 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 82 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 83 "data/maps/SpaMountain/scripts.pory"
	applymovement RATTATA_ID, SpaMountain_EventScript_Rattata_Movement_0
# 86 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 87 "data/maps/SpaMountain/scripts.pory"
	applymovement RATTATA_ID, SpaMountain_EventScript_Rattata_Movement_1
# 92 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 93 "data/maps/SpaMountain/scripts.pory"
	removeobject RATTATA_ID
	goto SpaMountain_EventScript_Rattata_1

SpaMountain_EventScript_Rattata_3:
# 96 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 97 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Rattata_Movement_2
# 103 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Rattata_1


SpaMountain_EventScript_Teddiursa::
# 110 "data/maps/SpaMountain/scripts.pory"
	lock
# 111 "data/maps/SpaMountain/scripts.pory"
	startspa 1
# 112 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Teddiursa_2
# 144 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Teddiursa_3
SpaMountain_EventScript_Teddiursa_1:
# 154 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Teddiursa_2:
# 113 "data/maps/SpaMountain/scripts.pory"
	faceplayer
# 114 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_SPA_OBTAINED_HONEY
# 115 "data/maps/SpaMountain/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 116 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Teddiursa_Text_0
# 117 "data/maps/SpaMountain/scripts.pory"
	waitfanfare
# 118 "data/maps/SpaMountain/scripts.pory"
	waitmessage
# 119 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 120 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_0
# 124 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 125 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 126 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_1
# 130 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 131 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_2
# 135 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 136 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 137 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_3
# 141 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 142 "data/maps/SpaMountain/scripts.pory"
	removeobject TEDDIURSA_ID
	goto SpaMountain_EventScript_Teddiursa_1

SpaMountain_EventScript_Teddiursa_3:
# 145 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 146 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Rattata_Movement_2
# 152 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Teddiursa_1


SpaMountain_EventScript_Psyduck::
# 159 "data/maps/SpaMountain/scripts.pory"
	lock
# 160 "data/maps/SpaMountain/scripts.pory"
	startspa 2
# 161 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Psyduck_2
# 180 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Psyduck_3
SpaMountain_EventScript_Psyduck_1:
# 190 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Psyduck_2:
# 162 "data/maps/SpaMountain/scripts.pory"
	faceplayer
# 163 "data/maps/SpaMountain/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 164 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Psyduck_Text_0
# 166 "data/maps/SpaMountain/scripts.pory"
	waitmoncry
# 167 "data/maps/SpaMountain/scripts.pory"
	waitmessage
# 168 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 169 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 170 "data/maps/SpaMountain/scripts.pory"
	applymovement PSYDUCK_ID, SpaMountain_EventScript_Psyduck_Movement_0
# 177 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 178 "data/maps/SpaMountain/scripts.pory"
	removeobject PSYDUCK_ID
	goto SpaMountain_EventScript_Psyduck_1

SpaMountain_EventScript_Psyduck_3:
# 181 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 182 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Psyduck_Movement_1
# 188 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Psyduck_1


SpaMountain_EventScript_Fletchinder::
# 195 "data/maps/SpaMountain/scripts.pory"
	lock
# 196 "data/maps/SpaMountain/scripts.pory"
	startspa 3
# 197 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Fletchinder_2
# 213 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Fletchinder_3
SpaMountain_EventScript_Fletchinder_1:
# 223 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Fletchinder_2:
# 198 "data/maps/SpaMountain/scripts.pory"
	faceplayer
# 199 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_SPA_OBTAINED_ORB
# 200 "data/maps/SpaMountain/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 201 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Fletchinder_Text_0
# 202 "data/maps/SpaMountain/scripts.pory"
	waitfanfare
# 203 "data/maps/SpaMountain/scripts.pory"
	waitmessage
# 204 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 205 "data/maps/SpaMountain/scripts.pory"
	playse SE_M_FLY
# 206 "data/maps/SpaMountain/scripts.pory"
	applymovement FLETCHINDER_ID, SpaMountain_EventScript_Fletchinder_Movement_0
# 210 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 211 "data/maps/SpaMountain/scripts.pory"
	removeobject FLETCHINDER_ID
	goto SpaMountain_EventScript_Fletchinder_1

SpaMountain_EventScript_Fletchinder_3:
# 214 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 215 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Rattata_Movement_2
# 221 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Fletchinder_1


SpaMountain_EventScript_Lombre::
# 228 "data/maps/SpaMountain/scripts.pory"
	lock
# 229 "data/maps/SpaMountain/scripts.pory"
	startspa 4
# 230 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Lombre_2
# 261 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Lombre_3
SpaMountain_EventScript_Lombre_1:
# 271 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Lombre_2:
# 231 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 232 "data/maps/SpaMountain/scripts.pory"
	applymovement LOMBRE_ID, SpaMountain_EventScript_Lombre_Movement_0
# 236 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 237 "data/maps/SpaMountain/scripts.pory"
	playse SE_M_STRENGTH
# 238 "data/maps/SpaMountain/scripts.pory"
	applymovement LOMBRE_ID, SpaMountain_EventScript_Lombre_Movement_1
# 241 "data/maps/SpaMountain/scripts.pory"
	applymovement BOULDER_ID, SpaMountain_EventScript_Lombre_Movement_2
# 244 "data/maps/SpaMountain/scripts.pory"
	waitmovement BOULDER_ID
# 245 "data/maps/SpaMountain/scripts.pory"
	waitse
# 246 "data/maps/SpaMountain/scripts.pory"
	applymovement LOMBRE_ID, SpaMountain_EventScript_Lombre_Movement_3
# 250 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 251 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 252 "data/maps/SpaMountain/scripts.pory"
	applymovement LOMBRE_ID, SpaMountain_EventScript_Lombre_Movement_4
# 256 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 257 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_BOULDER_MOVED
# 258 "data/maps/SpaMountain/scripts.pory"
	setobjectxyperm BOULDER_ID, 16, 20
# 259 "data/maps/SpaMountain/scripts.pory"
	removeobject LOMBRE_ID
	goto SpaMountain_EventScript_Lombre_1

SpaMountain_EventScript_Lombre_3:
# 262 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 263 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Lombre_Movement_5
# 269 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Lombre_1


SpaMountain_EventScript_Boulder::
# 276 "data/maps/SpaMountain/scripts.pory"
	lock
# 277 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Boulder_Text_0
# 279 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 280 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end


# 18 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_0:
# 19 "data/maps/SpaMountain/scripts.pory"
	walk_up
	step_end

# 23 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_1:
# 24 "data/maps/SpaMountain/scripts.pory"
	emote_exclamation_mark
	step_end

# 34 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_2:
# 35 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 35 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 35 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 36 "data/maps/SpaMountain/scripts.pory"
	face_left
	step_end

# 38 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_3:
# 39 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 39 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 40 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 41 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 42 "data/maps/SpaMountain/scripts.pory"
	face_right
	step_end

# 48 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_4:
# 49 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 49 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 49 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 49 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
	step_end

# 78 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Rattata_Movement_0:
# 79 "data/maps/SpaMountain/scripts.pory"
	jump_2_left
	step_end

# 87 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Rattata_Movement_1:
# 88 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 88 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 88 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 88 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 89 "data/maps/SpaMountain/scripts.pory"
	walk_left
# 89 "data/maps/SpaMountain/scripts.pory"
	walk_left
# 90 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 90 "data/maps/SpaMountain/scripts.pory"
	walk_up
	step_end

# 97 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Rattata_Movement_2:
# 98 "data/maps/SpaMountain/scripts.pory"
	face_up
# 99 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 100 "data/maps/SpaMountain/scripts.pory"
	walk_fast_down
# 101 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
	step_end

# 120 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_0:
# 121 "data/maps/SpaMountain/scripts.pory"
	walk_slow_diag_northeast
# 122 "data/maps/SpaMountain/scripts.pory"
	walk_slow_right
	step_end

# 126 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_1:
# 127 "data/maps/SpaMountain/scripts.pory"
	jump_2_right
# 128 "data/maps/SpaMountain/scripts.pory"
	walk_down
	step_end

# 132 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_2:
# 133 "data/maps/SpaMountain/scripts.pory"
	jump_2_down
	step_end

# 137 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_3:
# 138 "data/maps/SpaMountain/scripts.pory"
	jump_2_down
# 139 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 139 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 139 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 139 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 139 "data/maps/SpaMountain/scripts.pory"
	walk_right
	step_end

# 170 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Psyduck_Movement_0:
# 171 "data/maps/SpaMountain/scripts.pory"
	face_right
# 172 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 173 "data/maps/SpaMountain/scripts.pory"
	jump_2_left
# 174 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 175 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
	step_end

# 182 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Psyduck_Movement_1:
# 183 "data/maps/SpaMountain/scripts.pory"
	face_down
# 184 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 185 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 186 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
	step_end

# 206 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Fletchinder_Movement_0:
# 207 "data/maps/SpaMountain/scripts.pory"
	walk_diag_northwest
# 207 "data/maps/SpaMountain/scripts.pory"
	walk_diag_northwest
# 207 "data/maps/SpaMountain/scripts.pory"
	walk_diag_northwest
# 208 "data/maps/SpaMountain/scripts.pory"
	walk_diag_northeast
# 208 "data/maps/SpaMountain/scripts.pory"
	walk_diag_northeast
# 208 "data/maps/SpaMountain/scripts.pory"
	walk_diag_northeast
	step_end

# 232 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_0:
# 233 "data/maps/SpaMountain/scripts.pory"
	jump_2_left
# 234 "data/maps/SpaMountain/scripts.pory"
	walk_left
	step_end

# 238 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_1:
# 239 "data/maps/SpaMountain/scripts.pory"
	walk_slow_left
	step_end

# 241 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_2:
# 242 "data/maps/SpaMountain/scripts.pory"
	walk_left
# 242 "data/maps/SpaMountain/scripts.pory"
	walk_left
	step_end

# 246 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_3:
# 247 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 247 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 247 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 248 "data/maps/SpaMountain/scripts.pory"
	walk_left
	step_end

# 252 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_4:
# 253 "data/maps/SpaMountain/scripts.pory"
	jump_2_up
# 254 "data/maps/SpaMountain/scripts.pory"
	walk_up
	step_end

# 263 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_5:
# 264 "data/maps/SpaMountain/scripts.pory"
	face_right
# 265 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 266 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 267 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
	step_end

SpaMountain_OnFrame_0_Text_0:
# 45 "data/maps/SpaMountain/scripts.pory"
	.string "{COLOR RED}Oh, my!\n"
	.string "Is she alright?$"

SpaMountain_OnFrame_0_Text_1:
# 52 "data/maps/SpaMountain/scripts.pory"
	.string "{COLOR BLUE}She's still breathing,\n"
	.string "But she's out cold.\p"
	.string "Let's get her inside.\n"
	.string "Quickly!$"

SpaMountain_EventScript_Rattata_Text_0:
# 73 "data/maps/SpaMountain/scripts.pory"
	.string "The Rattata gave you a claw!$"

SpaMountain_EventScript_Teddiursa_Text_0:
# 116 "data/maps/SpaMountain/scripts.pory"
	.string "The Teddiursa gave you some honey!$"

SpaMountain_EventScript_Psyduck_Text_0:
# 164 "data/maps/SpaMountain/scripts.pory"
	.string "The Psyduck has nothing to give you,\n"
	.string "but it is thankful nonetheless.$"

SpaMountain_EventScript_Fletchinder_Text_0:
# 201 "data/maps/SpaMountain/scripts.pory"
	.string "The Fletchinder gave you a flame orb!$"

SpaMountain_EventScript_Boulder_Text_0:
# 277 "data/maps/SpaMountain/scripts.pory"
	.string "This boulder is too big for\n"
	.string "you to move.$"
