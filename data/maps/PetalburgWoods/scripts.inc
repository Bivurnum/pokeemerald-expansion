# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_RIVAL2, 14

PetalburgWoods_MapScripts::
# 7 "data/maps/PetalburgWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

PetalburgWoods_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
	return


PetalburgWoods_EventScript_DevonResearcherLeft::
# 13 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 14 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 15 "data/maps/PetalburgWoods/scripts.pory"
	addobject LOCALID_RIVAL2
# 16 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HoldUpPlayer, MSGBOX_DEFAULT
# 17 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 18 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 19 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2ApproachBeforeDevonLeft
# 20 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 21 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 22 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_DidYouHearThat
# 23 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 24 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 25 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 26 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 27 "data/maps/PetalburgWoods/scripts.pory"
	waitse
# 28 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 29 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayer
# 30 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 31 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 32 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 33 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayerLeft
# 34 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 35 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 36 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 37 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 38 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 39 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_WEST
# 40 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 41 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_GiveGreatBallsLeft
# 42 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 43 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_GiveGreatBalls
# 44 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExit
# 45 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 46 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_RemoveDevonResearcher
# 47 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_WEST
# 48 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 49 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RivalLeave
	end


PetalburgWoods_EventScript_DevonResearcherRight::
# 54 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 55 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 56 "data/maps/PetalburgWoods/scripts.pory"
	addobject LOCALID_RIVAL2
# 57 "data/maps/PetalburgWoods/scripts.pory"
	setobjectxy LOCALID_DEVON_EMPLOYEE, 26, 17
# 58 "data/maps/PetalburgWoods/scripts.pory"
	setobjectxy LOCALID_GRUNT, 26, 17
# 59 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HoldUpPlayer, MSGBOX_DEFAULT
# 60 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 61 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 62 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2ApproachBeforeDevonRight
# 63 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 64 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 65 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_DidYouHearThat
# 66 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 67 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 68 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 69 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 70 "data/maps/PetalburgWoods/scripts.pory"
	waitse
# 71 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 72 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayer
# 73 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 74 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 75 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayerRight
# 76 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 77 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 78 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 79 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 80 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 81 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_EAST
# 82 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 83 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_GiveGreatBallsRight
# 84 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 85 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_GiveGreatBalls
# 86 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExit
# 87 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 88 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_RemoveDevonResearcher
# 89 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 90 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_EAST
# 91 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RivalLeave
	end


PetalburgWoods_EventScript_DevonResearcherIntro::
# 96 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 97 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 98 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 99 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 100 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayer
# 101 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 102 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 103 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 104 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 105 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 106 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 107 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 108 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 109 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcher
# 110 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 111 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 112 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 113 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 114 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 119 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 120 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 121 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_NORTH
# 122 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 123 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 124 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 125 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 126 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 127 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 128 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_GiveGreatBalls::
# 133 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 134 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 135 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_BagFull::
# 140 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 141 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_DevonResearcherFinish::
# 146 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 147 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 148 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 149 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 150 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_RemoveDevonResearcher::
# 155 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 156 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
	return


PetalburgWoods_EventScript_RivalLeave::
# 161 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_BattleWasFun, MSGBOX_DEFAULT
# 162 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 163 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 164 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_DevonResearcherExit
# 165 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 166 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end


# 193 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonLeft:
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 195 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 195 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 195 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 196 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_left
	step_end

# 199 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonRight:
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 201 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 201 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 201 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 202 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
	step_end

# 205 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 206 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 206 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 206 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 207 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 208 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 209 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 210 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 211 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 212 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 213 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 214 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 215 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 216 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 217 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 218 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 219 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 222 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExit:
# 223 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 224 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 225 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 226 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 227 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
	step_end

# 230 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayer:
# 231 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 232 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 234 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 237 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 238 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 239 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 240 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 241 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 242 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 245 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 246 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 247 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 248 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 249 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 250 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 251 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 252 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 253 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
	step_end

# 256 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 257 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 258 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 262 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayer:
# 263 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 263 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 263 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 263 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 266 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 267 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 268 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 269 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 272 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 273 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 274 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 275 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 276 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 277 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 278 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 279 "data/maps/PetalburgWoods/scripts.pory"
	face_up
	step_end

# 282 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcher:
# 283 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 284 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
	step_end

# 287 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 288 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 289 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 290 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
	step_end

# 293 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 294 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 295 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 296 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 297 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 298 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 299 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 300 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 303 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 304 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 305 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 307 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 310 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 311 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 312 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 313 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 314 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 317 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerLeft:
# 318 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 319 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 322 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerRight:
# 323 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 324 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 327 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsLeft:
# 328 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 328 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 329 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 330 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 330 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 333 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsRight:
# 334 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 334 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 335 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 336 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 336 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 339 "data/maps/PetalburgWoods/scripts.pory"

# 340 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 341 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 342 "data/maps/PetalburgWoods/scripts.pory"
	end
# 343 "data/maps/PetalburgWoods/scripts.pory"

# 344 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 345 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 346 "data/maps/PetalburgWoods/scripts.pory"
	end
# 347 "data/maps/PetalburgWoods/scripts.pory"

# 348 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 349 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 350 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 351 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 352 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 353 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 354 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 355 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 356 "data/maps/PetalburgWoods/scripts.pory"
	release
# 357 "data/maps/PetalburgWoods/scripts.pory"
	end
# 358 "data/maps/PetalburgWoods/scripts.pory"

# 359 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 360 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 361 "data/maps/PetalburgWoods/scripts.pory"
	release
# 362 "data/maps/PetalburgWoods/scripts.pory"
	end
# 363 "data/maps/PetalburgWoods/scripts.pory"

# 364 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 365 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 366 "data/maps/PetalburgWoods/scripts.pory"
	end
# 367 "data/maps/PetalburgWoods/scripts.pory"

# 368 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 369 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 370 "data/maps/PetalburgWoods/scripts.pory"
	end
# 371 "data/maps/PetalburgWoods/scripts.pory"

# 372 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 373 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 374 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 375 "data/maps/PetalburgWoods/scripts.pory"
	end
# 376 "data/maps/PetalburgWoods/scripts.pory"

# 377 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 378 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 379 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 380 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 381 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 382 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 383 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 384 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 385 "data/maps/PetalburgWoods/scripts.pory"
	release
# 386 "data/maps/PetalburgWoods/scripts.pory"
	end
# 387 "data/maps/PetalburgWoods/scripts.pory"

# 388 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 389 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 390 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 391 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 392 "data/maps/PetalburgWoods/scripts.pory"
	release
# 393 "data/maps/PetalburgWoods/scripts.pory"
	end
# 394 "data/maps/PetalburgWoods/scripts.pory"

# 395 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 396 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 397 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 398 "data/maps/PetalburgWoods/scripts.pory"
	release
# 399 "data/maps/PetalburgWoods/scripts.pory"
	end
# 400 "data/maps/PetalburgWoods/scripts.pory"

# 401 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 402 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 403 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 404 "data/maps/PetalburgWoods/scripts.pory"
	release
# 405 "data/maps/PetalburgWoods/scripts.pory"
	end
# 406 "data/maps/PetalburgWoods/scripts.pory"

# 407 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 408 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 409 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 410 "data/maps/PetalburgWoods/scripts.pory"
	release
# 411 "data/maps/PetalburgWoods/scripts.pory"
	end
# 412 "data/maps/PetalburgWoods/scripts.pory"

# 413 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 414 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 415 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 416 "data/maps/PetalburgWoods/scripts.pory"
	end
# 417 "data/maps/PetalburgWoods/scripts.pory"

# 418 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 420 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 421 "data/maps/PetalburgWoods/scripts.pory"

# 422 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 423 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you kids seen any POKéMON\n"
# 424 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 425 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 426 "data/maps/PetalburgWoods/scripts.pory"

# 427 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 428 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 429 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 430 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 431 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 432 "data/maps/PetalburgWoods/scripts.pory"

# 433 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 435 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 436 "data/maps/PetalburgWoods/scripts.pory"

# 437 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're both POKéMON TRAINERS,\laren't you?\n"
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 441 "data/maps/PetalburgWoods/scripts.pory"

# 442 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 443 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 446 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even kids!\p"
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 448 "data/maps/PetalburgWoods/scripts.pory"

# 449 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 451 "data/maps/PetalburgWoods/scripts.pory"

# 452 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 455 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 456 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 460 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 461 "data/maps/PetalburgWoods/scripts.pory"

# 462 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you two, he didn't rob me\n"
# 466 "data/maps/PetalburgWoods/scripts.pory"
	.string "of these important papers.\p"
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 469 "data/maps/PetalburgWoods/scripts.pory"

# 470 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 473 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 474 "data/maps/PetalburgWoods/scripts.pory"

# 475 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 478 "data/maps/PetalburgWoods/scripts.pory"

# 479 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 480 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 481 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 482 "data/maps/PetalburgWoods/scripts.pory"

# 483 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 484 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 485 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 486 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 487 "data/maps/PetalburgWoods/scripts.pory"

# 488 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 489 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 490 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 491 "data/maps/PetalburgWoods/scripts.pory"

# 492 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 493 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 494 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 495 "data/maps/PetalburgWoods/scripts.pory"

# 496 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 497 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 498 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 499 "data/maps/PetalburgWoods/scripts.pory"

# 500 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 501 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 502 "data/maps/PetalburgWoods/scripts.pory"

# 503 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 504 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 505 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 506 "data/maps/PetalburgWoods/scripts.pory"

# 507 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 508 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 509 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 510 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 511 "data/maps/PetalburgWoods/scripts.pory"

# 512 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 513 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 514 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 515 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 516 "data/maps/PetalburgWoods/scripts.pory"

# 517 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 518 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 519 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 520 "data/maps/PetalburgWoods/scripts.pory"

# 521 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 522 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 523 "data/maps/PetalburgWoods/scripts.pory"

# 524 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 525 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 526 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 527 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 528 "data/maps/PetalburgWoods/scripts.pory"

# 529 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 530 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 531 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 532 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 533 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 534 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 535 "data/maps/PetalburgWoods/scripts.pory"

# 536 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 537 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 538 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 539 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 540 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 541 "data/maps/PetalburgWoods/scripts.pory"

# 542 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 543 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 544 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 545 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 546 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 547 "data/maps/PetalburgWoods/scripts.pory"

# 548 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 549 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 550 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 551 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 552 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 553 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 554 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 555 "data/maps/PetalburgWoods/scripts.pory"

# 556 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 557 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 558 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 559 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 560 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 561 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 562 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 563 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 564 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 565 "data/maps/PetalburgWoods/scripts.pory"

# 566 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 567 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 568 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 569 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 570 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 571 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 572 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

PetalburgWoods_Text_HoldUpPlayer::
# 170 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hold up, {PLAYER}!$"

PetalburgWoods_Text_DidYouHearThat::
# 174 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's much darker inside this forest.\n"
	.string "Things might be lurking in the shadows,\l"
	.string "waiting to ambush you.\p"
	.string "Wait!\n"
	.string "… … …\l"
	.string "… … …\l"
	.string "Do you hear that?$"

PetalburgWoods_Text_BattleWasFun::
# 181 "data/maps/PetalburgWoods/scripts.pory"
	.string "It was so awesome to battle alongside\n"
	.string "you!\l"
	.string "We sure make a great team.\p"
	.string "I hope that guy will be okay.\n"
	.string "It sound like there might be some more\l"
	.string "trouble brewing.\p"
	.string "Regardless, you've definitely shown\n"
	.string "that you can handle yourself.\l"
	.string "The rest of this forest should be a\l"
	.string "cake walk.\p"
	.string "That guy said there were SHROOMISH in\n"
	.string "these woods? I'd sure like to get one\l"
	.string "for my POKéDEX.\p"
	.string "I'll see you later. I have a SHROOMISH\n"
	.string "to find!$"
