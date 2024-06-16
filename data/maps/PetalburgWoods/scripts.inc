# 1 "data/maps/PetalburgWoods/scripts.pory"

# 2 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_GRUNT, 3
# 3 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 4
# 4 "data/maps/PetalburgWoods/scripts.pory"
.set LOCALID_RIVAL2, 14

PetalburgWoods_MapScripts::
	.byte 0


PetalburgWoods_EventScript_DevonResearcherLeft::
# 11 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 12 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 13 "data/maps/PetalburgWoods/scripts.pory"
	addobject LOCALID_RIVAL2
# 14 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HoldUpPlayer, MSGBOX_DEFAULT
# 15 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 16 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 17 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2ApproachBeforeDevonLeft
# 18 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 19 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 20 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_DidYouHearThat
# 21 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 22 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 23 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 24 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 25 "data/maps/PetalburgWoods/scripts.pory"
	waitse
# 26 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 27 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayer
# 28 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 29 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 30 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 31 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayerLeft
# 32 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 33 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 34 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 35 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2PrepareToFightLeft
# 36 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_PrepareForGruntBattle
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
	closemessage
# 79 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 80 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2PrepareToFightRight
# 81 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_PrepareForGruntBattle
# 82 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 83 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 84 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_EAST
# 85 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 86 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_GiveGreatBallsRight
# 87 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 88 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_GiveGreatBalls
# 89 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExit
# 90 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 91 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_RemoveDevonResearcher
# 92 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 93 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_EAST
# 94 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RivalLeave
	end


PetalburgWoods_EventScript_DevonResearcherIntro::
# 99 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 100 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 101 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 102 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 103 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayer
# 104 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 105 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 106 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 107 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, TRUE
# 108 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 109 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 110 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 111 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 112 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcher
# 113 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 114 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 115 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 116 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 117 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_PrepareForGruntBattle::
# 122 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TakeHimOnTogether, MSGBOX_DEFAULT
# 123 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 125 "data/maps/PetalburgWoods/scripts.pory"
	special SavePlayerParty
# 126 "data/maps/PetalburgWoods/scripts.pory"
	fadescreen FADE_TO_BLACK
# 127 "data/maps/PetalburgWoods/scripts.pory"
	special ChooseHalfPartyForBattle
# 128 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 129 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 130 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 131 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_PrepareForGruntBattle_Text_0, MSGBOX_DEFAULT
# 132 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 133 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_BeginGruntBattle
	return


PetalburgWoods_EventScript_BeginGruntBattle::
# 138 "data/maps/PetalburgWoods/scripts.pory"
	checkfriendchoice
# 139 "data/maps/PetalburgWoods/scripts.pory"
	switch VAR_RESULT
# 140 "data/maps/PetalburgWoods/scripts.pory"
	case SPENCER, PetalburgWoods_EventScript_BeginGruntBattle_3
# 142 "data/maps/PetalburgWoods/scripts.pory"
	case BREN, PetalburgWoods_EventScript_BeginGruntBattle_4
# 144 "data/maps/PetalburgWoods/scripts.pory"
	case KYLE, PetalburgWoods_EventScript_BeginGruntBattle_5
PetalburgWoods_EventScript_BeginGruntBattle_1:
	return

PetalburgWoods_EventScript_BeginGruntBattle_3:
# 141 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_KYLE_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1

PetalburgWoods_EventScript_BeginGruntBattle_4:
# 143 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_SPENCER_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1

PetalburgWoods_EventScript_BeginGruntBattle_5:
# 145 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_BREN_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1


PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 151 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 152 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 153 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_NORTH
# 154 "data/maps/PetalburgWoods/scripts.pory"
	fadedefaultbgm
# 155 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 156 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 157 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 158 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 159 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 160 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 161 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_GiveGreatBalls::
# 166 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 167 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 168 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_BagFull::
# 173 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 174 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_DevonResearcherFinish::
# 179 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 180 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 181 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 182 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 183 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_RemoveDevonResearcher::
# 188 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 189 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 190 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_RIVAL1
	return


PetalburgWoods_EventScript_RivalLeave::
# 195 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_BattleWasFun, MSGBOX_DEFAULT
# 196 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 197 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 198 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2Exit
# 199 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 200 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_RIVAL2
# 201 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 202 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 203 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end


# 236 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonLeft:
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 238 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 238 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 238 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_left
	step_end

# 242 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonRight:
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 243 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 244 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 244 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 244 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 245 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
	step_end

# 248 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 249 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 249 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 249 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 250 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 251 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 252 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 253 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 254 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 255 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 256 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 257 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 258 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 260 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 261 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 262 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 265 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExit:
# 266 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 267 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 268 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 269 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 270 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
	step_end

# 273 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayer:
# 274 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 275 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 276 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 277 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 280 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 281 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 282 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 283 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 284 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 285 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 288 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 289 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 290 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 291 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 292 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 293 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 294 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 295 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 296 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
	step_end

# 299 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 300 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 301 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 302 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 305 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayer:
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 309 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 310 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 311 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 312 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 315 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 316 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 317 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 318 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 319 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 320 "data/maps/PetalburgWoods/scripts.pory"
	emote_exclamation_mark
# 321 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 322 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 325 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcher:
# 326 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 327 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
	step_end

# 330 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 331 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 332 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 333 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
	step_end

# 336 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 337 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 338 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 339 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 340 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 341 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 342 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 343 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 346 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 347 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 348 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 349 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 350 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 353 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 354 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 355 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 356 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 357 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 360 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerLeft:
# 361 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 362 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 365 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerRight:
# 366 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 367 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 370 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsLeft:
# 371 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 371 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 372 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 373 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 373 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 376 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsRight:
# 377 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 377 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 378 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 382 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2Exit:
# 383 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 383 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 383 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 383 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 383 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 383 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 384 "data/maps/PetalburgWoods/scripts.pory"
	set_invisible
	step_end

# 387 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2PrepareToFightRight:
# 388 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_right
# 388 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_right
	step_end

# 391 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2PrepareToFightLeft:
# 392 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_left
# 392 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_left
	step_end

# 395 "data/maps/PetalburgWoods/scripts.pory"

# 396 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 397 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 398 "data/maps/PetalburgWoods/scripts.pory"
	end
# 399 "data/maps/PetalburgWoods/scripts.pory"

# 400 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 401 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 402 "data/maps/PetalburgWoods/scripts.pory"
	end
# 403 "data/maps/PetalburgWoods/scripts.pory"

# 404 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 405 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 406 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 407 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 408 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 409 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 410 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 411 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 412 "data/maps/PetalburgWoods/scripts.pory"
	release
# 413 "data/maps/PetalburgWoods/scripts.pory"
	end
# 414 "data/maps/PetalburgWoods/scripts.pory"

# 415 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 416 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 417 "data/maps/PetalburgWoods/scripts.pory"
	release
# 418 "data/maps/PetalburgWoods/scripts.pory"
	end
# 419 "data/maps/PetalburgWoods/scripts.pory"

# 420 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 421 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 422 "data/maps/PetalburgWoods/scripts.pory"
	end
# 423 "data/maps/PetalburgWoods/scripts.pory"

# 424 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 425 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 426 "data/maps/PetalburgWoods/scripts.pory"
	end
# 427 "data/maps/PetalburgWoods/scripts.pory"

# 428 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 429 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 430 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 431 "data/maps/PetalburgWoods/scripts.pory"
	end
# 432 "data/maps/PetalburgWoods/scripts.pory"

# 433 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 434 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 435 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 436 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 437 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 438 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 439 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 440 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 441 "data/maps/PetalburgWoods/scripts.pory"
	release
# 442 "data/maps/PetalburgWoods/scripts.pory"
	end
# 443 "data/maps/PetalburgWoods/scripts.pory"

# 444 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 445 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 446 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 447 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 448 "data/maps/PetalburgWoods/scripts.pory"
	release
# 449 "data/maps/PetalburgWoods/scripts.pory"
	end
# 450 "data/maps/PetalburgWoods/scripts.pory"

# 451 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 452 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 453 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 454 "data/maps/PetalburgWoods/scripts.pory"
	release
# 455 "data/maps/PetalburgWoods/scripts.pory"
	end
# 456 "data/maps/PetalburgWoods/scripts.pory"

# 457 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 458 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 459 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 460 "data/maps/PetalburgWoods/scripts.pory"
	release
# 461 "data/maps/PetalburgWoods/scripts.pory"
	end
# 462 "data/maps/PetalburgWoods/scripts.pory"

# 463 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 464 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 465 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 466 "data/maps/PetalburgWoods/scripts.pory"
	release
# 467 "data/maps/PetalburgWoods/scripts.pory"
	end
# 468 "data/maps/PetalburgWoods/scripts.pory"

# 469 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 470 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 471 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 472 "data/maps/PetalburgWoods/scripts.pory"
	end
# 473 "data/maps/PetalburgWoods/scripts.pory"

# 474 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 477 "data/maps/PetalburgWoods/scripts.pory"

# 478 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 479 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you kids seen any POKéMON\n"
# 480 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 481 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 482 "data/maps/PetalburgWoods/scripts.pory"

# 483 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 484 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 485 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 486 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 487 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 488 "data/maps/PetalburgWoods/scripts.pory"

# 489 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 490 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 491 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 492 "data/maps/PetalburgWoods/scripts.pory"

# 493 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 494 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 495 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're both POKéMON TRAINERS,\naren't you?\p"
# 496 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 497 "data/maps/PetalburgWoods/scripts.pory"

# 498 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 499 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 500 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 501 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 502 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even kids!\p"
# 503 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 504 "data/maps/PetalburgWoods/scripts.pory"

# 505 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 506 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 507 "data/maps/PetalburgWoods/scripts.pory"

# 508 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 509 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 510 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 511 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 512 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 513 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 514 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 515 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 516 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 517 "data/maps/PetalburgWoods/scripts.pory"

# 518 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 519 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 520 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 521 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you two, he didn't rob me\n"
# 522 "data/maps/PetalburgWoods/scripts.pory"
	.string "of these important papers.\p"
# 523 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 524 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 525 "data/maps/PetalburgWoods/scripts.pory"

# 526 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 527 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 528 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 529 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 530 "data/maps/PetalburgWoods/scripts.pory"

# 531 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 532 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 533 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 534 "data/maps/PetalburgWoods/scripts.pory"

# 535 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 536 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 537 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 538 "data/maps/PetalburgWoods/scripts.pory"

# 539 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 540 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 541 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 542 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 543 "data/maps/PetalburgWoods/scripts.pory"

# 544 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 545 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 546 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 547 "data/maps/PetalburgWoods/scripts.pory"

# 548 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 549 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 550 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 551 "data/maps/PetalburgWoods/scripts.pory"

# 552 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 553 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 554 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 555 "data/maps/PetalburgWoods/scripts.pory"

# 556 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 557 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 558 "data/maps/PetalburgWoods/scripts.pory"

# 559 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 560 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 561 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 562 "data/maps/PetalburgWoods/scripts.pory"

# 563 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 564 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 565 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 566 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 567 "data/maps/PetalburgWoods/scripts.pory"

# 568 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 569 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 570 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 571 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 572 "data/maps/PetalburgWoods/scripts.pory"

# 573 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 574 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 575 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 576 "data/maps/PetalburgWoods/scripts.pory"

# 577 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 578 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 579 "data/maps/PetalburgWoods/scripts.pory"

# 580 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 581 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 582 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 583 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 584 "data/maps/PetalburgWoods/scripts.pory"

# 585 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 586 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 587 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 588 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 589 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 590 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 591 "data/maps/PetalburgWoods/scripts.pory"

# 592 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 593 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 594 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 595 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 596 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 597 "data/maps/PetalburgWoods/scripts.pory"

# 598 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 599 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 600 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 601 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 602 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 603 "data/maps/PetalburgWoods/scripts.pory"

# 604 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 605 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 606 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 607 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 608 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 609 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 610 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 611 "data/maps/PetalburgWoods/scripts.pory"

# 612 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 613 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 614 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 615 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 616 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 617 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 618 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 619 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 620 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 621 "data/maps/PetalburgWoods/scripts.pory"

# 622 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 623 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 624 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 625 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 626 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 627 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 628 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

PetalburgWoods_EventScript_PrepareForGruntBattle_Text_0:
# 131 "data/maps/PetalburgWoods/scripts.pory"
	.string "Bring it on!$"

PetalburgWoods_Text_HoldUpPlayer::
# 207 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hold up, {PLAYER}!$"

PetalburgWoods_Text_DidYouHearThat::
# 211 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's much darker inside this forest.\n"
	.string "Things might be lurking in the shadows,\l"
	.string "waiting to ambush you.\p"
	.string "Wait!\n"
	.string "… … …\l"
	.string "Do you hear that?$"

PetalburgWoods_Text_BattleWasFun::
# 218 "data/maps/PetalburgWoods/scripts.pory"
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

PetalburgWoods_Text_TakeHimOnTogether::
# 230 "data/maps/PetalburgWoods/scripts.pory"
	.string "This guy looks pretty tough.\n"
	.string "Let's take him on together!\p"
	.string "Pick the POKéMON you want to use.$"
