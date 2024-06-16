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
	playbgm MUS_ENCOUNTER_AQUA, FALSE
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
# 124 "data/maps/PetalburgWoods/scripts.pory"
	special SavePlayerParty
# 125 "data/maps/PetalburgWoods/scripts.pory"
	fadescreen FADE_TO_BLACK
# 126 "data/maps/PetalburgWoods/scripts.pory"
	special ChooseHalfPartyForBattle
# 127 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 128 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 129 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_RIVAL2, DIR_NORTH
# 130 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_PrepareForGruntBattle_Text_0, MSGBOX_DEFAULT
# 131 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 132 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_BeginGruntBattle
	return


PetalburgWoods_EventScript_BeginGruntBattle::
# 137 "data/maps/PetalburgWoods/scripts.pory"
	checkfriendchoice
# 138 "data/maps/PetalburgWoods/scripts.pory"
	switch VAR_RESULT
# 139 "data/maps/PetalburgWoods/scripts.pory"
	case SPENCER, PetalburgWoods_EventScript_BeginGruntBattle_3
# 141 "data/maps/PetalburgWoods/scripts.pory"
	case BREN, PetalburgWoods_EventScript_BeginGruntBattle_4
# 143 "data/maps/PetalburgWoods/scripts.pory"
	case KYLE, PetalburgWoods_EventScript_BeginGruntBattle_5
PetalburgWoods_EventScript_BeginGruntBattle_1:
	return

PetalburgWoods_EventScript_BeginGruntBattle_3:
# 140 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_KYLE_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1

PetalburgWoods_EventScript_BeginGruntBattle_4:
# 142 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_SPENCER_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1

PetalburgWoods_EventScript_BeginGruntBattle_5:
# 144 "data/maps/PetalburgWoods/scripts.pory"
	multi_2_vs_1 TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe, PARTNER_BREN_WOODS
	goto PetalburgWoods_EventScript_BeginGruntBattle_1


PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 150 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 151 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 152 "data/maps/PetalburgWoods/scripts.pory"
	turnobject LOCALID_DEVON_EMPLOYEE, DIR_NORTH
# 153 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 154 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 155 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_GRUNT
# 156 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 157 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 158 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 159 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_GiveGreatBalls::
# 164 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 165 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 166 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_BagFull::
# 171 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 172 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end


PetalburgWoods_EventScript_DevonResearcherFinish::
# 177 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 178 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 179 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 180 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 181 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
	return


PetalburgWoods_EventScript_RemoveDevonResearcher::
# 186 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 187 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
	return


PetalburgWoods_EventScript_RivalLeave::
# 192 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_BattleWasFun, MSGBOX_DEFAULT
# 193 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 194 "data/maps/PetalburgWoods/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 195 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_RIVAL2, PetalburgWoods_Movement_Rival2Exit
# 196 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 197 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_RIVAL2
# 198 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_HIDE_PETALBURG_WOODS_RIVAL2
# 199 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 200 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end


# 232 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonLeft:
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 234 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 234 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 234 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 235 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_left
	step_end

# 238 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2ApproachBeforeDevonRight:
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 239 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 240 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 240 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 240 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 241 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
	step_end

# 244 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 245 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 245 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 245 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 246 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 247 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 248 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 249 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 250 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 251 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 252 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 253 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 254 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 255 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 256 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 257 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 258 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 261 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExit:
# 262 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 263 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 264 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 265 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 266 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
	step_end

# 269 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayer:
# 270 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 271 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 272 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 273 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 276 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 277 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 278 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 279 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 280 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 281 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 284 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 285 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 286 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 287 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
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
	step_end

# 295 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 296 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 297 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 298 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 301 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayer:
# 302 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 302 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 302 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 302 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 305 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 306 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 307 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 308 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
	step_end

# 311 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 312 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 313 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 314 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 315 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 316 "data/maps/PetalburgWoods/scripts.pory"
	emote_exclamation_mark
# 317 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 318 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 321 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcher:
# 322 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 323 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
	step_end

# 326 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 327 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 328 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 329 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
	step_end

# 332 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 333 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 334 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 335 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 336 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 337 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 338 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 339 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 342 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 343 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 344 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 345 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 346 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
	step_end

# 349 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 350 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 351 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 352 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 353 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
	step_end

# 356 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerLeft:
# 357 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 358 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 361 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayerRight:
# 362 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 363 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
	step_end

# 366 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsLeft:
# 367 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 367 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 368 "data/maps/PetalburgWoods/scripts.pory"
	walk_left
# 369 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 369 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 372 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_GiveGreatBallsRight:
# 373 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 373 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 374 "data/maps/PetalburgWoods/scripts.pory"
	walk_right
# 375 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
# 375 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_down
	step_end

# 378 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2Exit:
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 379 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 380 "data/maps/PetalburgWoods/scripts.pory"
	set_invisible
	step_end

# 383 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2PrepareToFightRight:
# 384 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_right
# 384 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_right
	step_end

# 387 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_Rival2PrepareToFightLeft:
# 388 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_left
# 388 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_left
	step_end

# 391 "data/maps/PetalburgWoods/scripts.pory"

# 392 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 393 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 394 "data/maps/PetalburgWoods/scripts.pory"
	end
# 395 "data/maps/PetalburgWoods/scripts.pory"

# 396 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 397 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 398 "data/maps/PetalburgWoods/scripts.pory"
	end
# 399 "data/maps/PetalburgWoods/scripts.pory"

# 400 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 401 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 402 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 403 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 404 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 405 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 406 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 407 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 408 "data/maps/PetalburgWoods/scripts.pory"
	release
# 409 "data/maps/PetalburgWoods/scripts.pory"
	end
# 410 "data/maps/PetalburgWoods/scripts.pory"

# 411 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 412 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 413 "data/maps/PetalburgWoods/scripts.pory"
	release
# 414 "data/maps/PetalburgWoods/scripts.pory"
	end
# 415 "data/maps/PetalburgWoods/scripts.pory"

# 416 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 417 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 418 "data/maps/PetalburgWoods/scripts.pory"
	end
# 419 "data/maps/PetalburgWoods/scripts.pory"

# 420 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 421 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 422 "data/maps/PetalburgWoods/scripts.pory"
	end
# 423 "data/maps/PetalburgWoods/scripts.pory"

# 424 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 425 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 426 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 427 "data/maps/PetalburgWoods/scripts.pory"
	end
# 428 "data/maps/PetalburgWoods/scripts.pory"

# 429 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 430 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 431 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 432 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 433 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 434 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 435 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 436 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 437 "data/maps/PetalburgWoods/scripts.pory"
	release
# 438 "data/maps/PetalburgWoods/scripts.pory"
	end
# 439 "data/maps/PetalburgWoods/scripts.pory"

# 440 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 441 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 442 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 443 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 444 "data/maps/PetalburgWoods/scripts.pory"
	release
# 445 "data/maps/PetalburgWoods/scripts.pory"
	end
# 446 "data/maps/PetalburgWoods/scripts.pory"

# 447 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 448 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 449 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 450 "data/maps/PetalburgWoods/scripts.pory"
	release
# 451 "data/maps/PetalburgWoods/scripts.pory"
	end
# 452 "data/maps/PetalburgWoods/scripts.pory"

# 453 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 454 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 455 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 456 "data/maps/PetalburgWoods/scripts.pory"
	release
# 457 "data/maps/PetalburgWoods/scripts.pory"
	end
# 458 "data/maps/PetalburgWoods/scripts.pory"

# 459 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 460 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 461 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 462 "data/maps/PetalburgWoods/scripts.pory"
	release
# 463 "data/maps/PetalburgWoods/scripts.pory"
	end
# 464 "data/maps/PetalburgWoods/scripts.pory"

# 465 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 466 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 467 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 468 "data/maps/PetalburgWoods/scripts.pory"
	end
# 469 "data/maps/PetalburgWoods/scripts.pory"

# 470 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 473 "data/maps/PetalburgWoods/scripts.pory"

# 474 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you kids seen any POKéMON\n"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 478 "data/maps/PetalburgWoods/scripts.pory"

# 479 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 480 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 481 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 482 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 483 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 484 "data/maps/PetalburgWoods/scripts.pory"

# 485 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 486 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 487 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 488 "data/maps/PetalburgWoods/scripts.pory"

# 489 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 490 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 491 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're both POKéMON TRAINERS,\laren't you?\n"
# 492 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 493 "data/maps/PetalburgWoods/scripts.pory"

# 494 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 495 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 496 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 497 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 498 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even kids!\p"
# 499 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 500 "data/maps/PetalburgWoods/scripts.pory"

# 501 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 502 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 503 "data/maps/PetalburgWoods/scripts.pory"

# 504 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 505 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 506 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 507 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 508 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 509 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 510 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 511 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 512 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 513 "data/maps/PetalburgWoods/scripts.pory"

# 514 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 515 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 516 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 517 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you two, he didn't rob me\n"
# 518 "data/maps/PetalburgWoods/scripts.pory"
	.string "of these important papers.\p"
# 519 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 520 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 521 "data/maps/PetalburgWoods/scripts.pory"

# 522 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 523 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 524 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 525 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 526 "data/maps/PetalburgWoods/scripts.pory"

# 527 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 528 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 529 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 530 "data/maps/PetalburgWoods/scripts.pory"

# 531 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 532 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 533 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 534 "data/maps/PetalburgWoods/scripts.pory"

# 535 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 536 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 537 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 538 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 539 "data/maps/PetalburgWoods/scripts.pory"

# 540 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 541 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 542 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 543 "data/maps/PetalburgWoods/scripts.pory"

# 544 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 545 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 546 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 547 "data/maps/PetalburgWoods/scripts.pory"

# 548 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 549 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 550 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 551 "data/maps/PetalburgWoods/scripts.pory"

# 552 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 553 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 554 "data/maps/PetalburgWoods/scripts.pory"

# 555 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 556 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 557 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 558 "data/maps/PetalburgWoods/scripts.pory"

# 559 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 560 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 561 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 562 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 563 "data/maps/PetalburgWoods/scripts.pory"

# 564 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 565 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 566 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 567 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 568 "data/maps/PetalburgWoods/scripts.pory"

# 569 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 570 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 571 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 572 "data/maps/PetalburgWoods/scripts.pory"

# 573 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 574 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 575 "data/maps/PetalburgWoods/scripts.pory"

# 576 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 577 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 578 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 579 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 580 "data/maps/PetalburgWoods/scripts.pory"

# 581 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 582 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 583 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 584 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 585 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 586 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 587 "data/maps/PetalburgWoods/scripts.pory"

# 588 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 589 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 590 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 591 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 592 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 593 "data/maps/PetalburgWoods/scripts.pory"

# 594 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 595 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 596 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 597 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 598 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 599 "data/maps/PetalburgWoods/scripts.pory"

# 600 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 601 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 602 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 603 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 604 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 605 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 606 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 607 "data/maps/PetalburgWoods/scripts.pory"

# 608 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 609 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 610 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 611 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 612 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 613 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 614 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 615 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 616 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 617 "data/maps/PetalburgWoods/scripts.pory"

# 618 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 619 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 620 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 621 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 622 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 623 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 624 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

PetalburgWoods_EventScript_PrepareForGruntBattle_Text_0:
# 130 "data/maps/PetalburgWoods/scripts.pory"
	.string "Bring it on!$"

PetalburgWoods_Text_HoldUpPlayer::
# 204 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hold up, {PLAYER}!$"

PetalburgWoods_Text_DidYouHearThat::
# 208 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's much darker inside this forest.\n"
	.string "Things might be lurking in the shadows,\l"
	.string "waiting to ambush you.\p"
	.string "Wait!\n"
	.string "… … …\l"
	.string "Do you hear that?$"

PetalburgWoods_Text_BattleWasFun::
# 215 "data/maps/PetalburgWoods/scripts.pory"
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
# 227 "data/maps/PetalburgWoods/scripts.pory"
	.string "This guy looks pretty tough.\n"
	.string "Let's take him on together!$"
