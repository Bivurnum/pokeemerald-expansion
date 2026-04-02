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
	applymovement BLUE_MTN_ID, SpaMountain_OnFrame_0_Movement_4
# 45 "data/maps/SpaMountain/scripts.pory"
	waitmovement 0
# 46 "data/maps/SpaMountain/scripts.pory"
	msgbox SpaMountain_OnFrame_0_Text_1
# 51 "data/maps/SpaMountain/scripts.pory"
	closemessage
# 52 "data/maps/SpaMountain/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 4
# 53 "data/maps/SpaMountain/scripts.pory"
	warp MAP_SPA_INTERIOR, 8, 15
# 54 "data/maps/SpaMountain/scripts.pory"
	waitstate
	return


SpaMountain_EventScript_Rattata::
# 58 "data/maps/SpaMountain/scripts.pory"
	lock
# 59 "data/maps/SpaMountain/scripts.pory"
	startspa 0
# 60 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end


SpaMountain_EventScript_Teddiursa::
# 65 "data/maps/SpaMountain/scripts.pory"
	lock
# 66 "data/maps/SpaMountain/scripts.pory"
	startspa 1
# 67 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end


SpaMountain_EventScript_Psyduck::
# 72 "data/maps/SpaMountain/scripts.pory"
	lock
# 73 "data/maps/SpaMountain/scripts.pory"
	startspa 2
# 74 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end


SpaMountain_EventScript_Fletchinder::
# 79 "data/maps/SpaMountain/scripts.pory"
	lock
# 80 "data/maps/SpaMountain/scripts.pory"
	startspa 3
# 81 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end


SpaMountain_EventScript_Lombre::
# 86 "data/maps/SpaMountain/scripts.pory"
	lock
# 87 "data/maps/SpaMountain/scripts.pory"
	startspa 4
# 88 "data/maps/SpaMountain/scripts.pory"
	releaseall
	end


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

# 42 "data/maps/SpaMountain/scripts.pory"
SpaMountain_OnFrame_0_Movement_4:
# 43 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 43 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 43 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
# 43 "data/maps/SpaMountain/scripts.pory"
	walk_in_place_right
	step_end

SpaMountain_OnFrame_0_Text_0:
# 40 "data/maps/SpaMountain/scripts.pory"
	.string "{COLOR RED}Oh, my!\n"
	.string "Is she alright?$"

SpaMountain_OnFrame_0_Text_1:
# 46 "data/maps/SpaMountain/scripts.pory"
	.string "She's still breathing,\n"
	.string "But she's out cold.\p"
	.string "Let's get her inside.\n"
	.string "Quickly!$"
