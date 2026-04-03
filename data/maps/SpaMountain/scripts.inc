SpaMountain_MapScripts::
# 6 "data/maps/SpaMountain/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpaMountain_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpaMountain_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/SpaMountain/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 3, SpaMountain_OnFrame_0
	.2byte 0


SpaMountain_OnFrame_0::
# 12 "data/maps/SpaMountain/scripts.pory"
	lock
# 13 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_OnFrame_0_Movement_0
# 16 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 17 "data/maps/SpaMountain/scripts.pory"
	playse SE_PIN
# 18 "data/maps/SpaMountain/scripts.pory"
	applymovement RED_MTN_ID, SpaMountain_OnFrame_0_Movement_1
# 21 "data/maps/SpaMountain/scripts.pory"
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_1
# 24 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 25 "data/maps/SpaMountain/scripts.pory"
	delay 60
# 26 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_OnFrame_0_Movement_0
# 29 "data/maps/SpaMountain/scripts.pory"
	applymovement RED_MTN_ID, SpaMountain_OnFrame_0_Movement_2
# 33 "data/maps/SpaMountain/scripts.pory"
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_3
# 39 "data/maps/SpaMountain/scripts.pory"
	waitmovement BLUE_MTN_ID
# 40 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_OnFrame_0_Text_0
# 42 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 43 "data/maps/SpaMountain/scripts.pory"
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_4
# 46 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 47 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_OnFrame_0_Text_1
# 52 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 53 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_HIDE_CYNTHIA_SICK_MTN
# 54 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_HIDE_KIMONO_RED_MOUNTAIN
# 55 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_HIDE_KIMONO_BLUE_MOUNTAIN
# 56 "data/maps/SpaMountain/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 4
# 57 "data/maps/SpaMountain/scripts.pory"
	warp MAP_SPA_INTERIOR, 8, 15
# 58 "data/maps/SpaMountain/scripts.pory"
	waitstate
	return


SpaMountain_EventScript_Rattata::
# 62 "data/maps/SpaMountain/scripts.pory"
	lock
# 63 "data/maps/SpaMountain/scripts.pory"
	startspa 0
# 64 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Rattata_2
# 90 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Rattata_3
SpaMountain_EventScript_Rattata_1:
# 100 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Rattata_2:
# 65 "data/maps/SpaMountain/scripts.pory"
	faceplayer
# 66 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_SPA_OBTAINED_CLAW
# 67 "data/maps/SpaMountain/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 68 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Rattata_Text_0
# 69 "data/maps/SpaMountain/scripts.pory"
	waitfanfare
# 70 "data/maps/SpaMountain/scripts.pory"
	waitmessage
# 71 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 72 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 73 "data/maps/SpaMountain/scripts.pory"
	applymovement RATTATA_ID, SpaMountain_EventScript_Rattata_Movement_0
# 76 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 77 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/SpaMountain/scripts.pory"
	applymovement RATTATA_ID, SpaMountain_EventScript_Rattata_Movement_0
# 81 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 82 "data/maps/SpaMountain/scripts.pory"
	applymovement RATTATA_ID, SpaMountain_EventScript_Rattata_Movement_1
# 87 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 88 "data/maps/SpaMountain/scripts.pory"
	removeobject RATTATA_ID
	goto SpaMountain_EventScript_Rattata_1

SpaMountain_EventScript_Rattata_3:
# 91 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 92 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Rattata_Movement_2
# 98 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Rattata_1


SpaMountain_EventScript_Teddiursa::
# 105 "data/maps/SpaMountain/scripts.pory"
	lock
# 106 "data/maps/SpaMountain/scripts.pory"
	startspa 1
# 107 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Teddiursa_2
# 139 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Teddiursa_3
SpaMountain_EventScript_Teddiursa_1:
# 149 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Teddiursa_2:
# 108 "data/maps/SpaMountain/scripts.pory"
	faceplayer
# 109 "data/maps/SpaMountain/scripts.pory"
	setflag FLAG_SPA_OBTAINED_HONEY
# 110 "data/maps/SpaMountain/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 111 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_EventScript_Teddiursa_Text_0
# 112 "data/maps/SpaMountain/scripts.pory"
	waitfanfare
# 113 "data/maps/SpaMountain/scripts.pory"
	waitmessage
# 114 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 115 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_0
# 119 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 120 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 121 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_1
# 125 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 126 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 127 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_2
# 130 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 131 "data/maps/SpaMountain/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/SpaMountain/scripts.pory"
	applymovement TEDDIURSA_ID, SpaMountain_EventScript_Teddiursa_Movement_3
# 136 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 137 "data/maps/SpaMountain/scripts.pory"
	removeobject TEDDIURSA_ID
	goto SpaMountain_EventScript_Teddiursa_1

SpaMountain_EventScript_Teddiursa_3:
# 140 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 141 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Rattata_Movement_2
# 147 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Teddiursa_1


SpaMountain_EventScript_Psyduck::
# 154 "data/maps/SpaMountain/scripts.pory"
	lock
# 155 "data/maps/SpaMountain/scripts.pory"
	startspa 2
# 156 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Psyduck_2
# 159 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Psyduck_3
SpaMountain_EventScript_Psyduck_1:
# 169 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Psyduck_2:
	goto SpaMountain_EventScript_Psyduck_1

SpaMountain_EventScript_Psyduck_3:
# 160 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 161 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Psyduck_Movement_0
# 167 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Psyduck_1


SpaMountain_EventScript_Fletchinder::
# 174 "data/maps/SpaMountain/scripts.pory"
	lock
# 175 "data/maps/SpaMountain/scripts.pory"
	startspa 3
# 176 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Fletchinder_2
# 179 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Fletchinder_3
SpaMountain_EventScript_Fletchinder_1:
# 189 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Fletchinder_2:
	goto SpaMountain_EventScript_Fletchinder_1

SpaMountain_EventScript_Fletchinder_3:
# 180 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 181 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Rattata_Movement_2
# 187 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Fletchinder_1


SpaMountain_EventScript_Lombre::
# 194 "data/maps/SpaMountain/scripts.pory"
	lock
# 195 "data/maps/SpaMountain/scripts.pory"
	startspa 4
# 196 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SpaMountain_EventScript_Lombre_2
# 199 "data/maps/SpaMountain/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SpaMountain_EventScript_Lombre_3
SpaMountain_EventScript_Lombre_1:
# 209 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end

SpaMountain_EventScript_Lombre_2:
	goto SpaMountain_EventScript_Lombre_1

SpaMountain_EventScript_Lombre_3:
# 200 "data/maps/SpaMountain/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 201 "data/maps/SpaMountain/scripts.pory"
	applymovement LOCALID_PLAYER, SpaMountain_EventScript_Lombre_Movement_0
# 207 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
	goto SpaMountain_EventScript_Lombre_1


# 13 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_0:
# 14 "data/maps/SpaMountain/scripts.pory"
	walk_up
	step_end

# 18 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_1:
# 19 "data/maps/SpaMountain/scripts.pory"
	emote_exclamation_mark
	step_end

# 29 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_2:
# 30 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 30 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 30 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 31 "data/maps/SpaMountain/scripts.pory"
	face_left
	step_end

# 33 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_3:
# 34 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 34 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 35 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 36 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 37 "data/maps/SpaMountain/scripts.pory"
	face_right
	step_end

# 43 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_4:
# 44 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 44 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 44 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 44 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
	step_end

# 73 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Rattata_Movement_0:
# 74 "data/maps/SpaMountain/scripts.pory"
	jump_2_left
	step_end

# 82 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Rattata_Movement_1:
# 83 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 83 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 83 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 83 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 84 "data/maps/SpaMountain/scripts.pory"
	walk_left
# 84 "data/maps/SpaMountain/scripts.pory"
	walk_left
# 85 "data/maps/SpaMountain/scripts.pory"
	walk_up
# 85 "data/maps/SpaMountain/scripts.pory"
	walk_up
	step_end

# 92 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Rattata_Movement_2:
# 93 "data/maps/SpaMountain/scripts.pory"
	face_up
# 94 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 95 "data/maps/SpaMountain/scripts.pory"
	walk_fast_down
# 96 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
	step_end

# 115 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_0:
# 116 "data/maps/SpaMountain/scripts.pory"
	walk_slow_diag_northeast
# 117 "data/maps/SpaMountain/scripts.pory"
	walk_slow_right
	step_end

# 121 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_1:
# 122 "data/maps/SpaMountain/scripts.pory"
	jump_2_right
# 123 "data/maps/SpaMountain/scripts.pory"
	walk_down
	step_end

# 127 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_2:
# 128 "data/maps/SpaMountain/scripts.pory"
	jump_2_down
	step_end

# 132 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Teddiursa_Movement_3:
# 133 "data/maps/SpaMountain/scripts.pory"
	jump_2_down
# 134 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 134 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 134 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 134 "data/maps/SpaMountain/scripts.pory"
	walk_right
# 134 "data/maps/SpaMountain/scripts.pory"
	walk_right
	step_end

# 161 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Psyduck_Movement_0:
# 162 "data/maps/SpaMountain/scripts.pory"
	face_down
# 163 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 164 "data/maps/SpaMountain/scripts.pory"
	walk_fast_up
# 165 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
	step_end

# 201 "data/maps/SpaMountain/scripts.pory"
SpaMountain_EventScript_Lombre_Movement_0:
# 202 "data/maps/SpaMountain/scripts.pory"
	face_right
# 203 "data/maps/SpaMountain/scripts.pory"
	lock_facing_direction
# 204 "data/maps/SpaMountain/scripts.pory"
	walk_fast_left
# 205 "data/maps/SpaMountain/scripts.pory"
	unlock_facing_direction
	step_end

SpaMountain_OnFrame_0_Text_0:
# 40 "data/maps/SpaMountain/scripts.pory"
	.string "{COLOR RED}Oh, my!\n"
	.string "Is she alright?$"

SpaMountain_OnFrame_0_Text_1:
# 47 "data/maps/SpaMountain/scripts.pory"
	.string "{COLOR BLUE}She's still breathing,\n"
	.string "But she's out cold.\p"
	.string "Let's get her inside.\n"
	.string "Quickly!$"

SpaMountain_EventScript_Rattata_Text_0:
# 68 "data/maps/SpaMountain/scripts.pory"
	.string "The Rattata gave you a claw!$"

SpaMountain_EventScript_Teddiursa_Text_0:
# 111 "data/maps/SpaMountain/scripts.pory"
	.string "The Teddiursa gave you some honey!$"
