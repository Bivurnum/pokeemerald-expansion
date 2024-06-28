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
	waitmovement 0
# 37 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_WEST
# 38 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_PrepareForGruntBattle
# 39 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 40 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 41 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 42 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_GiveGreatBallsLeft
# 43 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 44 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_GiveGreatBalls
# 45 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExit
# 46 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 47 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_RemoveDevonResearcher
# 48 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_WEST
# 49 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 50 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RivalLeave
	end


PetalburgWoods_EventScript_DevonResearcherRight::
# 55 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 56 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 57 "data/maps/PetalburgWoods/scripts.pory"
	addobject LOCALID_RIVAL2
# 58 "data/maps/PetalburgWoods/scripts.pory"
	setobjectxy LOCALID_DEVON_EMPLOYEE, 26, 17
# 59 "data/maps/PetalburgWoods/scripts.pory"
	setobjectxy LOCALID_GRUNT, 26, 17
# 60 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HoldUpPlayer, MSGBOX_DEFAULT
# 61 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 62 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
# 63 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2ApproachBeforeDevonRight
# 64 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 65 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 66 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_DidYouHearThat
# 67 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 68 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 69 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 70 "data/maps/PetalburgWoods/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 71 "data/maps/PetalburgWoods/scripts.pory"
	waitse
# 72 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 73 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayer
# 74 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 75 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 76 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayerRight
# 77 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 78 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 79 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 80 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 81 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2PrepareToFightRight
# 82 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 83 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_EAST
# 84 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_PrepareForGruntBattle
# 85 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 86 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 87 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 88 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_GiveGreatBallsRight
# 89 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 90 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_GiveGreatBalls
# 91 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExit
# 92 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 93 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_RemoveDevonResearcher
# 94 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
# 95 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_EAST
# 96 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RivalLeave
	end


PetalburgWoods_EventScript_DevonResearcherIntro::
# 101 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 102 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 103 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 104 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 105 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayer
# 106 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 107 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 108 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 109 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, TRUE
# 110 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 111 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 112 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 113 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 114 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcher
# 115 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 116 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 117 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 118 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 119 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_PrepareForGruntBattle::
# 124 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TakeHimOnTogether, MSGBOX_DEFAULT
# 125 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 127 "data/maps/PetalburgWoods/scripts.pory"
	special SavePlayerParty
# 128 "data/maps/PetalburgWoods/scripts.pory"
	fadescreen FADE_TO_BLACK
# 129 "data/maps/PetalburgWoods/scripts.pory"
	special ChooseHalfPartyForBattle
# 130 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 131 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_ne VAR_RESULT, 0, PetalburgWoods_EventScript_BeginGruntBattle
# 132 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_QuitPartySelect
	return


PetalburgWoods_EventScript_QuitPartySelect::
# 137 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotGetOutOfThisOne
# 138 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 139 "data/maps/PetalburgWoods/scripts.pory"
	special SavePlayerParty
# 140 "data/maps/PetalburgWoods/scripts.pory"
	fadescreen FADE_TO_BLACK
# 141 "data/maps/PetalburgWoods/scripts.pory"
	special ChooseHalfPartyForBattle
# 142 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 143 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_ne VAR_RESULT, 0, PetalburgWoods_EventScript_BeginGruntBattle
# 144 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_QuitPartySelect
	end


PetalburgWoods_EventScript_BeginGruntBattle::
# 149 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 150 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 151 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_BeginGruntBattle_Text_0, MSGBOX_DEFAULT
# 152 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 153 "data/maps/PetalburgWoods/scripts.pory"
	checkfriendchoice
# 154 "data/maps/PetalburgWoods/scripts.pory"
	switch VAR_RESULT
# 155 "data/maps/PetalburgWoods/scripts.pory"
	case SPENCER, PetalburgWoods_EventScript_BeginGruntBattle_3
# 157 "data/maps/PetalburgWoods/scripts.pory"
	case BREN, PetalburgWoods_EventScript_BeginGruntBattle_4
# 159 "data/maps/PetalburgWoods/scripts.pory"
	case KYLE, PetalburgWoods_EventScript_BeginGruntBattle_5
PetalburgWoods_EventScript_BeginGruntBattle_1:
	return

PetalburgWoods_EventScript_BeginGruntBattle_3:
# 156 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_KYLE_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1

PetalburgWoods_EventScript_BeginGruntBattle_4:
# 158 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_SPENCER_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1

PetalburgWoods_EventScript_BeginGruntBattle_5:
# 160 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_BREN_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1


PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 166 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 167 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 168 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_NORTH
# 169 "data/maps/PetalburgWoods/scripts.pory"
	fadedefaultbgm
# 170 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 171 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 172 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 173 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 174 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 175 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 176 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_GiveGreatBalls::
# 181 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 182 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 183 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_BagFull::
# 188 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 189 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_DevonResearcherFinish::
# 194 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 195 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 196 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 197 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 198 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_RemoveDevonResearcher::
# 203 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 204 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
	return


PetalburgWoods_EventScript_RivalLeave::
# 209 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_BattleWasFun, MSGBOX_DEFAULT
# 210 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 211 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 212 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2Exit
# 213 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 214 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_RIVAL2
# 215 "data/maps/PetalburgWoods/scripts.pory"
	savebgm MUS_DUMMY
# 216 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 217 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_RIVAL1
# 218 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_ROUTE_102_RIVAL2
# 219 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 220 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end


# 258 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonLeft:
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 259 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 260 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 260 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 260 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 261 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_left
	step_end

# 264 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonRight:
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 266 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 266 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 266 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 267 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
	step_end

# 270 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 271 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 271 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 271 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 272 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 273 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 274 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 275 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 276 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 277 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 278 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 279 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 280 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 281 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 282 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 283 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 284 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 287 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExit:
# 288 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 289 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 290 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 291 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 292 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 293 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 293 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 296 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayer:
# 297 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 298 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 299 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 300 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 303 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 304 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 305 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 307 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 308 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 311 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 312 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 313 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 314 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 315 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 316 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 317 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 318 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 319 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
	step_end

# 322 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 323 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 324 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 325 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 328 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayer:
# 329 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 329 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 329 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 329 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 332 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 333 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 334 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 335 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 338 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 339 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 340 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 341 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 342 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 343 "data/maps/PetalburgWoods/scripts.pory"
	emote_exclamation_mark
# 344 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 345 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 348 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcher:
# 349 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 350 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
	step_end

# 353 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 354 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 355 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 356 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
	step_end

# 359 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 360 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 361 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 362 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 363 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 364 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 365 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 366 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 369 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 370 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 371 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 372 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 373 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 376 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 377 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 378 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 379 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 380 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 383 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerLeft:
# 384 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 385 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 388 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerRight:
# 389 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 390 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 393 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsLeft:
# 394 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 394 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 395 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 396 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 396 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 399 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsRight:
# 400 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 400 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 401 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 402 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 402 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 405 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2Exit:
# 406 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 406 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 406 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 406 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 406 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 406 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 407 "data/maps/PetalburgWoods/scripts.pory"
	set_invisible
	step_end

# 410 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2PrepareToFightRight:
# 411 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_right
# 411 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_right
	step_end

# 414 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2PrepareToFightLeft:
# 415 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_left
# 415 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_left
	step_end

# 418 "data/maps/PetalburgWoods/scripts.pory"

# 419 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 420 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 421 "data/maps/PetalburgWoods/scripts.pory"
	end
# 422 "data/maps/PetalburgWoods/scripts.pory"

# 423 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 424 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 425 "data/maps/PetalburgWoods/scripts.pory"
	end
# 426 "data/maps/PetalburgWoods/scripts.pory"

# 427 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 428 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 429 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 430 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 431 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 432 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 433 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 434 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 435 "data/maps/PetalburgWoods/scripts.pory"
	release
# 436 "data/maps/PetalburgWoods/scripts.pory"
	end
# 437 "data/maps/PetalburgWoods/scripts.pory"

# 438 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 439 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 440 "data/maps/PetalburgWoods/scripts.pory"
	release
# 441 "data/maps/PetalburgWoods/scripts.pory"
	end
# 442 "data/maps/PetalburgWoods/scripts.pory"

# 443 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 444 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 445 "data/maps/PetalburgWoods/scripts.pory"
	end
# 446 "data/maps/PetalburgWoods/scripts.pory"

# 447 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 448 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 449 "data/maps/PetalburgWoods/scripts.pory"
	end
# 450 "data/maps/PetalburgWoods/scripts.pory"

# 451 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 452 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 453 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 454 "data/maps/PetalburgWoods/scripts.pory"
	end
# 455 "data/maps/PetalburgWoods/scripts.pory"

# 456 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 457 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 458 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 459 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 460 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 461 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 462 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 463 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 464 "data/maps/PetalburgWoods/scripts.pory"
	release
# 465 "data/maps/PetalburgWoods/scripts.pory"
	end
# 466 "data/maps/PetalburgWoods/scripts.pory"

# 467 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 468 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 469 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 470 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 471 "data/maps/PetalburgWoods/scripts.pory"
	release
# 472 "data/maps/PetalburgWoods/scripts.pory"
	end
# 473 "data/maps/PetalburgWoods/scripts.pory"

# 474 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 475 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 476 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 477 "data/maps/PetalburgWoods/scripts.pory"
	release
# 478 "data/maps/PetalburgWoods/scripts.pory"
	end
# 479 "data/maps/PetalburgWoods/scripts.pory"

# 480 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 481 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 482 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 483 "data/maps/PetalburgWoods/scripts.pory"
	release
# 484 "data/maps/PetalburgWoods/scripts.pory"
	end
# 485 "data/maps/PetalburgWoods/scripts.pory"

# 486 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 487 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 488 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 489 "data/maps/PetalburgWoods/scripts.pory"
	release
# 490 "data/maps/PetalburgWoods/scripts.pory"
	end
# 491 "data/maps/PetalburgWoods/scripts.pory"

# 492 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 493 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 494 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 495 "data/maps/PetalburgWoods/scripts.pory"
	end
# 496 "data/maps/PetalburgWoods/scripts.pory"

# 497 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 498 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 499 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 500 "data/maps/PetalburgWoods/scripts.pory"

# 501 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 502 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you kids seen any POKéMON\n"
# 503 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 504 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 505 "data/maps/PetalburgWoods/scripts.pory"

# 506 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 507 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 508 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 509 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 510 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 511 "data/maps/PetalburgWoods/scripts.pory"

# 512 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 513 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 514 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 515 "data/maps/PetalburgWoods/scripts.pory"

# 516 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 517 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 518 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're both POKéMON TRAINERS,\naren't you?\p"
# 519 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 520 "data/maps/PetalburgWoods/scripts.pory"

# 521 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 522 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 523 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 524 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 525 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even kids!\p"
# 526 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 527 "data/maps/PetalburgWoods/scripts.pory"

# 528 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 529 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 530 "data/maps/PetalburgWoods/scripts.pory"

# 531 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 532 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 533 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 534 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 535 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 536 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 537 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 538 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 539 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 540 "data/maps/PetalburgWoods/scripts.pory"

# 541 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 542 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 543 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 544 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you two, he didn't rob me\n"
# 545 "data/maps/PetalburgWoods/scripts.pory"
	.string "of these important papers.\p"
# 546 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 547 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 548 "data/maps/PetalburgWoods/scripts.pory"

# 549 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 550 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 551 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 552 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 553 "data/maps/PetalburgWoods/scripts.pory"

# 554 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 555 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 556 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 557 "data/maps/PetalburgWoods/scripts.pory"

# 558 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 559 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 560 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 561 "data/maps/PetalburgWoods/scripts.pory"

# 562 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 563 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 564 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 565 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 566 "data/maps/PetalburgWoods/scripts.pory"

# 567 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 568 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 569 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 570 "data/maps/PetalburgWoods/scripts.pory"

# 571 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 572 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 573 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 574 "data/maps/PetalburgWoods/scripts.pory"

# 575 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 576 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 577 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 578 "data/maps/PetalburgWoods/scripts.pory"

# 579 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 580 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 581 "data/maps/PetalburgWoods/scripts.pory"

# 582 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 583 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 584 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 585 "data/maps/PetalburgWoods/scripts.pory"

# 586 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 587 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 588 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 589 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 590 "data/maps/PetalburgWoods/scripts.pory"

# 591 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 592 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 593 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 594 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 595 "data/maps/PetalburgWoods/scripts.pory"

# 596 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 597 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 598 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 599 "data/maps/PetalburgWoods/scripts.pory"

# 600 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 601 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 602 "data/maps/PetalburgWoods/scripts.pory"

# 603 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 604 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 605 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 606 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 607 "data/maps/PetalburgWoods/scripts.pory"

# 608 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 609 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 610 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 611 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 612 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 613 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 614 "data/maps/PetalburgWoods/scripts.pory"

# 615 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 616 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 617 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 618 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 619 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 620 "data/maps/PetalburgWoods/scripts.pory"

# 621 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 622 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 623 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 624 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 625 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 626 "data/maps/PetalburgWoods/scripts.pory"

# 627 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 628 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 629 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 630 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 631 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 632 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 633 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 634 "data/maps/PetalburgWoods/scripts.pory"

# 635 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 636 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 637 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 638 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 639 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 640 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 641 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 642 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 643 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 644 "data/maps/PetalburgWoods/scripts.pory"

# 645 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 646 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 647 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 648 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 649 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 650 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 651 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

PetalburgWoods_EventScript_BeginGruntBattle_Text_0:
# 151 "data/maps/PetalburgWoods/scripts.pory"
	.string "Bring it on!$"

PetalburgWoods_Text_HoldUpPlayer::
# 224 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hold up, {PLAYER}!$"

PetalburgWoods_Text_DidYouHearThat::
# 228 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's much darker inside this forest.\n"
	.string "Things might be lurking in the shadows,\l"
	.string "waiting to ambush you.\p"
	.string "Wait!\n"
	.string "… … …\l"
	.string "Do you hear that?$"

PetalburgWoods_Text_BattleWasFun::
# 235 "data/maps/PetalburgWoods/scripts.pory"
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
# 247 "data/maps/PetalburgWoods/scripts.pory"
	.string "This guy looks pretty tough.\n"
	.string "Let's take him on together!\p"
	.string "Pick the POKéMON you want to use.$"

PetalburgWoods_Text_NotGetOutOfThisOne::
# 253 "data/maps/PetalburgWoods/scripts.pory"
	.string "I don't think we're getting out of this\n"
	.string "one.\l"
	.string "Go on, pick the POKéMON you'd like to\l"
	.string "battle with.$"
