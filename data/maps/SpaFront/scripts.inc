SpaFront_MapScripts::
# 5 "data/maps/SpaFront/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SpaFront_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 14 "data/maps/SpaFront/scripts.pory"
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
	playbgm MUS_DUMMY, FALSE
# 10 "data/maps/SpaFront/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 1
	end

SpaFront_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 15 "data/maps/SpaFront/scripts.pory"
	map_script_2 VAR_SPA_INTRO_STATE, 1, SpaFront_OnFrame_0
	.2byte 0


SpaFront_OnFrame_0::
# 20 "data/maps/SpaFront/scripts.pory"
	lock
# 21 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_MOVE
# 22 "data/maps/SpaFront/scripts.pory"
	delay 32
# 23 "data/maps/SpaFront/scripts.pory"
	applymovement 1, SpaFront_OnFrame_0_Movement_0
# 26 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 27 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_STOP
# 28 "data/maps/SpaFront/scripts.pory"
	applymovement 1, SpaFront_OnFrame_0_Movement_1
# 31 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 32 "data/maps/SpaFront/scripts.pory"
	waitse
# 33 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_DOOR
# 34 "data/maps/SpaFront/scripts.pory"
	showplayer
# 35 "data/maps/SpaFront/scripts.pory"
	delay 16
# 36 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_OnFrame_0_Movement_2
# 40 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 41 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_OnFrame_0_Text_0
# 42 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 43 "data/maps/SpaFront/scripts.pory"
	closemessage
# 44 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_OnFrame_0_Movement_3
# 47 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 48 "data/maps/SpaFront/scripts.pory"
	delay 32
# 49 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_OnFrame_0_Text_1
# 50 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 51 "data/maps/SpaFront/scripts.pory"
	closemessage
# 52 "data/maps/SpaFront/scripts.pory"
	delay 8
# 53 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_MOVE
# 54 "data/maps/SpaFront/scripts.pory"
	delay 8
# 55 "data/maps/SpaFront/scripts.pory"
	applymovement 1, SpaFront_OnFrame_0_Movement_4
# 59 "data/maps/SpaFront/scripts.pory"
	delay 28
# 60 "data/maps/SpaFront/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 61 "data/maps/SpaFront/scripts.pory"
	delay 100
# 62 "data/maps/SpaFront/scripts.pory"
	playse SE_TRUCK_STOP
# 63 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 64 "data/maps/SpaFront/scripts.pory"
	playbgm MUS_ABANDONED_SHIP, TRUE
# 65 "data/maps/SpaFront/scripts.pory"
	removeobject 1
# 66 "data/maps/SpaFront/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 67 "data/maps/SpaFront/scripts.pory"
	setvar VAR_SPA_INTRO_STATE, 2
# 68 "data/maps/SpaFront/scripts.pory"
	release
	end


SpaFront_EventScript_RoadRight::
# 73 "data/maps/SpaFront/scripts.pory"
	lock
# 74 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_RoadRight_Text_0
# 75 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 76 "data/maps/SpaFront/scripts.pory"
	closemessage
# 77 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_EventScript_RoadRight_Movement_0
# 80 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 81 "data/maps/SpaFront/scripts.pory"
	release
	end


SpaFront_EventScript_RoadLeft::
# 86 "data/maps/SpaFront/scripts.pory"
	lock
# 87 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_RoadRight_Text_0
# 88 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 89 "data/maps/SpaFront/scripts.pory"
	closemessage
# 90 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_EventScript_RoadLeft_Movement_0
# 93 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 94 "data/maps/SpaFront/scripts.pory"
	release
	end


SpaFront_EventScript_Sign::
# 99 "data/maps/SpaFront/scripts.pory"
	lock
# 100 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_Sign_Text_0
# 101 "data/maps/SpaFront/scripts.pory"
	closemessage
# 102 "data/maps/SpaFront/scripts.pory"
	release
	end


# 23 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_0:
# 24 "data/maps/SpaFront/scripts.pory"
	walk_left
# 24 "data/maps/SpaFront/scripts.pory"
	walk_left
# 24 "data/maps/SpaFront/scripts.pory"
	walk_left
# 24 "data/maps/SpaFront/scripts.pory"
	walk_left
# 24 "data/maps/SpaFront/scripts.pory"
	walk_left
# 24 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 28 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_1:
# 29 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 29 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
	step_end

# 36 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_2:
# 37 "data/maps/SpaFront/scripts.pory"
	walk_up
# 38 "data/maps/SpaFront/scripts.pory"
	face_down
	step_end

# 44 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_3:
# 45 "data/maps/SpaFront/scripts.pory"
	walk_in_place_down
# 45 "data/maps/SpaFront/scripts.pory"
	walk_in_place_down
	step_end

# 55 "data/maps/SpaFront/scripts.pory"
SpaFront_OnFrame_0_Movement_4:
# 56 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 56 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 56 "data/maps/SpaFront/scripts.pory"
	walk_slow_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
# 57 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 77 "data/maps/SpaFront/scripts.pory"
SpaFront_EventScript_RoadRight_Movement_0:
# 78 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 90 "data/maps/SpaFront/scripts.pory"
SpaFront_EventScript_RoadLeft_Movement_0:
# 91 "data/maps/SpaFront/scripts.pory"
	walk_right
	step_end

SpaFront_OnFrame_0_Text_0:
# 41 "data/maps/SpaFront/scripts.pory"
	.string "You sure this is the place?\nNot a lot of folks come by here.\pAnd I hear there are some\nstrange people up at the temple.\pThis is your destination?$"

SpaFront_OnFrame_0_Text_1:
# 49 "data/maps/SpaFront/scripts.pory"
	.string "Alright, then.\nYou take care of yourself.\pSee ya!$"

SpaFront_EventScript_RoadRight_Text_0:
# 74 "data/maps/SpaFront/scripts.pory"
	.string "You should make your way to the temple.$"

SpaFront_EventScript_Sign_Text_0:
# 100 "data/maps/SpaFront/scripts.pory"
	.string "'Kodai Temple'$"
