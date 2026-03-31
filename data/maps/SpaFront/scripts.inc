SpaFront_MapScripts::
	.byte 0


SpaFront_EventScript_RoadRight::
# 6 "data/maps/SpaFront/scripts.pory"
	lock
# 7 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_RoadRight_Text_0
# 8 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 9 "data/maps/SpaFront/scripts.pory"
	closemessage
# 10 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_EventScript_RoadRight_Movement_0
# 13 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 14 "data/maps/SpaFront/scripts.pory"
	releaseall
	end


SpaFront_EventScript_RoadLeft::
# 19 "data/maps/SpaFront/scripts.pory"
	lock
# 20 "data/maps/SpaFront/scripts.pory"
	msgbox SpaFront_EventScript_RoadRight_Text_0
# 21 "data/maps/SpaFront/scripts.pory"
	waitmessage
# 22 "data/maps/SpaFront/scripts.pory"
	closemessage
# 23 "data/maps/SpaFront/scripts.pory"
	applymovement LOCALID_PLAYER, SpaFront_EventScript_RoadLeft_Movement_0
# 26 "data/maps/SpaFront/scripts.pory"
	waitmovement 0
# 27 "data/maps/SpaFront/scripts.pory"
	releaseall
	end


# 10 "data/maps/SpaFront/scripts.pory"
SpaFront_EventScript_RoadRight_Movement_0:
# 11 "data/maps/SpaFront/scripts.pory"
	walk_left
	step_end

# 23 "data/maps/SpaFront/scripts.pory"
SpaFront_EventScript_RoadLeft_Movement_0:
# 24 "data/maps/SpaFront/scripts.pory"
	walk_right
	step_end

SpaFront_EventScript_RoadRight_Text_0:
# 7 "data/maps/SpaFront/scripts.pory"
	.string "You should make your way to the temple.$"
