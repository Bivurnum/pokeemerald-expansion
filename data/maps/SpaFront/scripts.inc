SpaFront_MapScripts::
# 5 "data/maps/SpaFront/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SpaFront_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 13 "data/maps/SpaFront/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SpaFront_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SpaFront_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/SpaFront/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 0, SpaFront_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

SpaFront_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 7 "data/maps/SpaFront/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 8 "data/maps/SpaFront/scripts.pory"
	hideplayer
# 9 "data/maps/SpaFront/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 1
	end

SpaFront_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 14 "data/maps/SpaFront/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 1, SpaFront_OnFrame_0
	.2byte 0


SpaFront_OnFrame_0::
# 19 "data/maps/SpaFront/scripts.pory"
	lock
# 20 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_MOVE
# 21 "data/maps/SpaFront/scripts.pory"
	delay 32
# 22 "data/maps/SpaFront/scripts.pory"
	applymovement 1, SpaFront_OnFrame_0_Movement_0
# 25 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 26 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_STOP
# 27 "data/maps/SpaFront/scripts.pory"
	applymovement 1, SpaFront_OnFrame_0_Movement_1
# 30 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 31 "data/maps/SpaFront/scripts.pory"
	waitse
# 32 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_DOOR
# 33 "data/maps/SpaFront/scripts.pory"
	showplayer
# 34 "data/maps/SpaFront/scripts.pory"
	delay 16
# 35 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_OnFrame_0_Movement_2
# 39 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 40 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_OnFrame_0_Text_0
# 41 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 42 "data/maps/SpaFront/scripts.pory"
	closemessage
# 43 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_OnFrame_0_Movement_3
# 46 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 47 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_OnFrame_0_Text_1
# 48 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 49 "data/maps/SpaFront/scripts.pory"
	closemessage
# 50 "data/maps/SpaFront/scripts.pory"
	delay 8
# 51 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_MOVE
# 52 "data/maps/SpaFront/scripts.pory"
	delay 8
# 53 "data/maps/SpaFront/scripts.pory"
	applymovement 1, SpaFront_OnFrame_0_Movement_4
# 57 "data/maps/SpaFront/scripts.pory"
	delay 28
# 58 "data/maps/SpaFront/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 59 "data/maps/SpaFront/scripts.pory"
	delay 100
# 60 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_STOP
# 61 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 62 "data/maps/SpaFront/scripts.pory"
	playbgm MUS_ABANDONED_SHIP, TRUE
# 63 "data/maps/SpaFront/scripts.pory"
	removeobject 1
# 64 "data/maps/SpaFront/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 65 "data/maps/SpaFront/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 2
# 66 "data/maps/SpaFront/scripts.pory"
	releaseall
	end


SpaFront_EventScript_RoadRight::
# 71 "data/maps/SpaFront/scripts.pory"
	lock
# 72 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_RoadRight_Text_0
# 73 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 74 "data/maps/SpaFront/scripts.pory"
	closemessage
# 75 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_EventScript_RoadRight_Movement_0
# 78 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 79 "data/maps/SpaFront/scripts.pory"
	releaseall
	end


SpaFront_EventScript_RoadLeft::
# 84 "data/maps/SpaFront/scripts.pory"
	lock
# 85 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_RoadRight_Text_0
# 86 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 87 "data/maps/SpaFront/scripts.pory"
	closemessage
# 88 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_EventScript_RoadLeft_Movement_0
# 91 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 92 "data/maps/SpaFront/scripts.pory"
	releaseall
	end


# 22 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_0:
# 23 "data/maps/SpaFront/scripts.pory"
	walk_left
# 23 "data/maps/SpaFront/scripts.pory"
	walk_left
# 23 "data/maps/SpaFront/scripts.pory"
	walk_left
# 23 "data/maps/SpaFront/scripts.pory"
	walk_left
# 23 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 27 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_1:
# 28 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 28 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 28 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
	step_end

# 35 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_2:
# 36 "data/maps/SpaFront/scripts.pory"
	walk_up
# 37 "data/maps/SpaFront/scripts.pory"
	face_down
	step_end

# 43 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_3:
# 44 "data/maps/SpaFront/scripts.pory"
	walk_in_place_down
# 44 "data/maps/SpaFront/scripts.pory"
	walk_in_place_down
	step_end

# 53 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_4:
# 54 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 54 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 54 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
# 55 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 75 "data/maps/SpaFront/scripts.pory"
SpaFront_EventScript_RoadRight_Movement_0:
# 76 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 88 "data/maps/SpaFront/scripts.pory"
SpaFront_EventScript_RoadLeft_Movement_0:
# 89 "data/maps/SpaFront/scripts.pory"
	walk_right
	step_end

SpaFront_OnFrame_0_Text_0:
# 40 "data/maps/SpaFront/scripts.pory"
	.string "You sure this is the place?\nNot a lot of folks come by here.\pAnd I hear there are some\nstrange people up at the temple.\pThis is your destination?$"

SpaFront_OnFrame_0_Text_1:
# 47 "data/maps/SpaFront/scripts.pory"
	.string "Alright, then.\nYou take care of yourself.\pSee ya!$"

SpaFront_EventScript_RoadRight_Text_0:
# 72 "data/maps/SpaFront/scripts.pory"
	.string "You should make your way to the temple.$"
