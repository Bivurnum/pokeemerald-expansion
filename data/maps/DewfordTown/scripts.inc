# 6 "data/maps/DewfordTown/scripts.pory"

# 7 "data/maps/DewfordTown/scripts.pory"
@ Sailing to and from Dewford uses local IDs from different maps
# 8 "data/maps/DewfordTown/scripts.pory"
@ e.g. Route 104's sail to Dewford script references local IDs from Dewford's map
# 9 "data/maps/DewfordTown/scripts.pory"
@ All of these local IDs are labeled here
# 10 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_BRINEY_DEWFORD, 2
# 11 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_BOAT_DEWFORD, 4
# 12 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_RIVAL1_DEWFORD, 7
# 13 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_RIVAL2_DEWFORD, 6
# 14 "data/maps/DewfordTown/scripts.pory"

# 15 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_BOAT_R109, 1
# 16 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_BRINEY_R109, 2
# 17 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_RIVAL1_R109, 25
# 18 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_RIVAL2_R109, 26
# 19 "data/maps/DewfordTown/scripts.pory"

# 20 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_BOAT_R104, 7
# 21 "data/maps/DewfordTown/scripts.pory"
.equ LOCALID_BRINEY_R104, 8
# 22 "data/maps/DewfordTown/scripts.pory"

# 23 "data/maps/DewfordTown/scripts.pory"
DewfordTown_MapScripts::
# 24 "data/maps/DewfordTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
# 25 "data/maps/DewfordTown/scripts.pory"
	.byte 0
# 26 "data/maps/DewfordTown/scripts.pory"

# 27 "data/maps/DewfordTown/scripts.pory"
DewfordTown_OnTransition:
# 28 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_VISITED_DEWFORD_TOWN
# 29 "data/maps/DewfordTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 30 "data/maps/DewfordTown/scripts.pory"
	end
# 31 "data/maps/DewfordTown/scripts.pory"

# 32 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_Briney::
# 33 "data/maps/DewfordTown/scripts.pory"
	lock
# 34 "data/maps/DewfordTown/scripts.pory"
	faceplayer
# 35 "data/maps/DewfordTown/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
# 36 "data/maps/DewfordTown/scripts.pory"
	message DewfordTown_Text_WhereAreWeBound
# 37 "data/maps/DewfordTown/scripts.pory"
	waitmessage
# 38 "data/maps/DewfordTown/scripts.pory"
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
# 39 "data/maps/DewfordTown/scripts.pory"
	switch VAR_RESULT
# 40 "data/maps/DewfordTown/scripts.pory"
	case 0, DewfordTown_EventScript_ChoosePetalburg
# 41 "data/maps/DewfordTown/scripts.pory"
	case 1, DewfordTown_EventScript_ChooseSlateport
# 42 "data/maps/DewfordTown/scripts.pory"
	case 2, DewfordTown_EventScript_CancelSailSelect
# 43 "data/maps/DewfordTown/scripts.pory"
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
# 44 "data/maps/DewfordTown/scripts.pory"
	end
# 45 "data/maps/DewfordTown/scripts.pory"

# 46 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_ChoosePetalburg::
# 47 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
# 48 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 49 "data/maps/DewfordTown/scripts.pory"
	goto DewfordTown_EventScript_SailToPetalburg
# 50 "data/maps/DewfordTown/scripts.pory"
	release
# 51 "data/maps/DewfordTown/scripts.pory"
	end
# 52 "data/maps/DewfordTown/scripts.pory"

# 53 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_ChooseSlateport::
# 54 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
# 55 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 56 "data/maps/DewfordTown/scripts.pory"
	goto DewfordTown_EventScript_SailToSlateport
# 57 "data/maps/DewfordTown/scripts.pory"
	release
# 58 "data/maps/DewfordTown/scripts.pory"
	end
# 59 "data/maps/DewfordTown/scripts.pory"

# 60 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_CancelSailSelect::
# 61 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
# 62 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 63 "data/maps/DewfordTown/scripts.pory"
	release
# 64 "data/maps/DewfordTown/scripts.pory"
	end
# 65 "data/maps/DewfordTown/scripts.pory"

# 66 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_ReturnToPetalburgPrompt::
# 67 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
# 68 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
# 69 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
# 70 "data/maps/DewfordTown/scripts.pory"
	release
# 71 "data/maps/DewfordTown/scripts.pory"
	end
# 72 "data/maps/DewfordTown/scripts.pory"

# 73 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_SailBackToPetalburg::
# 74 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
# 75 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 76 "data/maps/DewfordTown/scripts.pory"
	goto DewfordTown_EventScript_SailToPetalburg
# 77 "data/maps/DewfordTown/scripts.pory"
	end
# 78 "data/maps/DewfordTown/scripts.pory"

# 79 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_Woman::
# 80 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
# 81 "data/maps/DewfordTown/scripts.pory"
	end
# 82 "data/maps/DewfordTown/scripts.pory"

# 83 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_TownSign::
# 84 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
# 85 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_DELIVERED_STEVEN_LETTER
# 86 "data/maps/DewfordTown/scripts.pory"
	clearflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 87 "data/maps/DewfordTown/scripts.pory"
	end
# 88 "data/maps/DewfordTown/scripts.pory"

# 89 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_GymSign::
# 90 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
# 91 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_BADGE02_GET
# 92 "data/maps/DewfordTown/scripts.pory"
	end
# 93 "data/maps/DewfordTown/scripts.pory"

# 94 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_HallSign::
# 95 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
# 96 "data/maps/DewfordTown/scripts.pory"
	end
# 97 "data/maps/DewfordTown/scripts.pory"

# 98 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_OldRodFisherman::
# 99 "data/maps/DewfordTown/scripts.pory"
	lock
# 100 "data/maps/DewfordTown/scripts.pory"
	faceplayer
# 101 "data/maps/DewfordTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
# 102 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
# 103 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
# 104 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
# 105 "data/maps/DewfordTown/scripts.pory"
	end
# 106 "data/maps/DewfordTown/scripts.pory"

# 107 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_GiveOldRod::
# 108 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
# 109 "data/maps/DewfordTown/scripts.pory"
	giveitem ITEM_OLD_ROD
# 110 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 111 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_RECEIVED_OLD_ROD
# 112 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
# 113 "data/maps/DewfordTown/scripts.pory"
	release
# 114 "data/maps/DewfordTown/scripts.pory"
	end
# 115 "data/maps/DewfordTown/scripts.pory"

# 116 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_NotGettingItchToFish::
# 117 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
# 118 "data/maps/DewfordTown/scripts.pory"
	release
# 119 "data/maps/DewfordTown/scripts.pory"
	end
# 120 "data/maps/DewfordTown/scripts.pory"

# 121 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_HowsFishing::
# 122 "data/maps/DewfordTown/scripts.pory"
	message DewfordTown_Text_HowsYourFishing
# 123 "data/maps/DewfordTown/scripts.pory"
	waitmessage
# 124 "data/maps/DewfordTown/scripts.pory"
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
# 125 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
# 126 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
# 127 "data/maps/DewfordTown/scripts.pory"
	end
# 128 "data/maps/DewfordTown/scripts.pory"

# 129 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_FishingExcellent::
# 130 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
# 131 "data/maps/DewfordTown/scripts.pory"
	release
# 132 "data/maps/DewfordTown/scripts.pory"
	end
# 133 "data/maps/DewfordTown/scripts.pory"

# 134 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_FishingNotSoGood::
# 135 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
# 136 "data/maps/DewfordTown/scripts.pory"
	release
# 137 "data/maps/DewfordTown/scripts.pory"
	end
# 138 "data/maps/DewfordTown/scripts.pory"

# 139 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_SailToPetalburg::
# 140 "data/maps/DewfordTown/scripts.pory"
	call EventScript_BackupMrBrineyLocation
# 141 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 142 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 0
# 143 "data/maps/DewfordTown/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
# 144 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 145 "data/maps/DewfordTown/scripts.pory"
	removeobject LOCALID_BRINEY_DEWFORD
# 146 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
# 147 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 148 "data/maps/DewfordTown/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 149 "data/maps/DewfordTown/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 150 "data/maps/DewfordTown/scripts.pory"
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToPetalburg
# 151 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToPetalburg
# 152 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 153 "data/maps/DewfordTown/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 154 "data/maps/DewfordTown/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 155 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
# 156 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 157 "data/maps/DewfordTown/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 158 "data/maps/DewfordTown/scripts.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 159 "data/maps/DewfordTown/scripts.pory"
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 160 "data/maps/DewfordTown/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 161 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 162 "data/maps/DewfordTown/scripts.pory"
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
# 163 "data/maps/DewfordTown/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
# 164 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 165 "data/maps/DewfordTown/scripts.pory"
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
# 166 "data/maps/DewfordTown/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 167 "data/maps/DewfordTown/scripts.pory"
	waitstate
# 168 "data/maps/DewfordTown/scripts.pory"
	release
# 169 "data/maps/DewfordTown/scripts.pory"
	end

DewfordTown_EventScript_SailToSlateport::
# 173 "data/maps/DewfordTown/scripts.pory"
	call EventScript_BackupMrBrineyLocation
# 174 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 175 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_SailToSlateport_2
DewfordTown_EventScript_SailToSlateport_1:
# 182 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 183 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 1
# 184 "data/maps/DewfordTown/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
# 185 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 186 "data/maps/DewfordTown/scripts.pory"
	removeobject LOCALID_BRINEY_DEWFORD
# 187 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
# 188 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 189 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_SailToSlateport_5
DewfordTown_EventScript_SailToSlateport_4:
# 193 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 194 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 195 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_SailToSlateport_8
DewfordTown_EventScript_SailToSlateport_7:
# 199 "data/maps/DewfordTown/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 200 "data/maps/DewfordTown/scripts.pory"
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToSlateport
# 201 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToSlateport
# 202 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 203 "data/maps/DewfordTown/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 204 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 205 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_SailToSlateport_11
DewfordTown_EventScript_SailToSlateport_10:
# 213 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
# 214 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 215 "data/maps/DewfordTown/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_R109, 21, 26
# 216 "data/maps/DewfordTown/scripts.pory"
	addobject LOCALID_BRINEY_R109
# 217 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
# 218 "data/maps/DewfordTown/scripts.pory"
	applymovement LOCALID_BRINEY_R109, DewfordTown_Movement_BrineyExitBoat
# 219 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 220 "data/maps/DewfordTown/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
# 221 "data/maps/DewfordTown/scripts.pory"
	addobject LOCALID_BOAT_R109
# 222 "data/maps/DewfordTown/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
# 223 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 224 "data/maps/DewfordTown/scripts.pory"
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
# 225 "data/maps/DewfordTown/scripts.pory"
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
# 226 "data/maps/DewfordTown/scripts.pory"
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
# 227 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 228 "data/maps/DewfordTown/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 229 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 230 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109
# 231 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 232 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_SailToSlateport_14
DewfordTown_EventScript_SailToSlateport_13:
# 237 "data/maps/DewfordTown/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_R109
# 238 "data/maps/DewfordTown/scripts.pory"
	release
	end

DewfordTown_EventScript_SailToSlateport_2:
# 176 "data/maps/DewfordTown/scripts.pory"
	applymovement 7, DewfordTown_Movement_RivalsJoinBoatToSlateport
# 177 "data/maps/DewfordTown/scripts.pory"
	applymovement 6, DewfordTown_Movement_RivalsJoinBoatToSlateport
# 178 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 179 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority 7, MAP_DEWFORD_TOWN, 0
# 180 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority 6, MAP_DEWFORD_TOWN, 0
	goto DewfordTown_EventScript_SailToSlateport_1

DewfordTown_EventScript_SailToSlateport_5:
# 190 "data/maps/DewfordTown/scripts.pory"
	applymovement 7, DewfordTown_Movement_Rival1BoardBoat
# 191 "data/maps/DewfordTown/scripts.pory"
	applymovement 6, DewfordTown_Movement_Rival2BoardBoat
	goto DewfordTown_EventScript_SailToSlateport_4

DewfordTown_EventScript_SailToSlateport_8:
# 196 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority 7, MAP_DEWFORD_TOWN
# 197 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority 6, MAP_DEWFORD_TOWN
	goto DewfordTown_EventScript_SailToSlateport_7

DewfordTown_EventScript_SailToSlateport_11:
# 206 "data/maps/DewfordTown/scripts.pory"
	addobject 25
# 207 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority 25, MAP_ROUTE109, 0
# 208 "data/maps/DewfordTown/scripts.pory"
	addobject 26
# 209 "data/maps/DewfordTown/scripts.pory"
	setobjectsubpriority 26, MAP_ROUTE109, 0
# 210 "data/maps/DewfordTown/scripts.pory"
	applymovement 25, DewfordTown_Movement_Rival1ExitBoatSlateport
# 211 "data/maps/DewfordTown/scripts.pory"
	applymovement 26, DewfordTown_Movement_Rival2ExitBoatSlateport
	goto DewfordTown_EventScript_SailToSlateport_10

DewfordTown_EventScript_SailToSlateport_14:
# 233 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority 25, MAP_ROUTE109
# 234 "data/maps/DewfordTown/scripts.pory"
	resetobjectsubpriority 26, MAP_ROUTE109
# 235 "data/maps/DewfordTown/scripts.pory"
	call DewfordTown_EventScript_RivalsAfterSailToSlateport
	goto DewfordTown_EventScript_SailToSlateport_13


# 242 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_RivalsJoinBoatToSlateport:
# 243 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 243 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 243 "data/maps/DewfordTown/scripts.pory"
	walk_right
	step_end

# 246 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_Rival1BoardBoat:
# 247 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 247 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 248 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 249 "data/maps/DewfordTown/scripts.pory"
	set_invisible
	step_end

# 252 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_Rival2BoardBoat:
# 253 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 253 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 253 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 254 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 255 "data/maps/DewfordTown/scripts.pory"
	set_invisible
	step_end

# 258 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_Rival1ExitBoatSlateport:
# 259 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 259 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 259 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 260 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 261 "data/maps/DewfordTown/scripts.pory"
	face_down
	step_end

# 264 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_Rival2ExitBoatSlateport:
# 265 "data/maps/DewfordTown/scripts.pory"
	delay_4
# 266 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 266 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 266 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 267 "data/maps/DewfordTown/scripts.pory"
	walk_left
# 268 "data/maps/DewfordTown/scripts.pory"
	face_down
	step_end

DewfordTown_EventScript_RivalsAfterSailToSlateport::
# 272 "data/maps/DewfordTown/scripts.pory"
	setflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 273 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 274 "data/maps/DewfordTown/scripts.pory"
	applymovement 26, Common_Movement_FaceRight
# 275 "data/maps/DewfordTown/scripts.pory"
	applymovement 25, Common_Movement_BeginTalkLeft
# 276 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 277 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_GoingToMuseum, MSGBOX_DEFAULT
# 278 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 279 "data/maps/DewfordTown/scripts.pory"
	applymovement 26, Common_Movement_FaceUp
# 280 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 281 "data/maps/DewfordTown/scripts.pory"
	applymovement 25, DewfordTown_Movement_Rival1WalkToSlateport
# 282 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 283 "data/maps/DewfordTown/scripts.pory"
	removeobject 25
# 284 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 285 "data/maps/DewfordTown/scripts.pory"
	applymovement 26, Common_Movement_BeginTalkRight
# 286 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 287 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_HitTheBeach, MSGBOX_DEFAULT
# 288 "data/maps/DewfordTown/scripts.pory"
	closemessage
# 289 "data/maps/DewfordTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 290 "data/maps/DewfordTown/scripts.pory"
	applymovement 26, DewfordTown_Movement_Rival2RunToSlateport
# 291 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 292 "data/maps/DewfordTown/scripts.pory"
	removeobject 26
# 293 "data/maps/DewfordTown/scripts.pory"
	delay 20
	return


# 297 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_Rival1WalkToSlateport:
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 298 "data/maps/DewfordTown/scripts.pory"
	walk_up
	step_end

# 301 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_Rival2RunToSlateport:
# 302 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 303 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
	step_end

# 318 "data/maps/DewfordTown/scripts.pory"

# 319 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_LandedSlateportDeliverGoods::
# 320 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
# 321 "data/maps/DewfordTown/scripts.pory"
	return
# 322 "data/maps/DewfordTown/scripts.pory"

# 323 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_LandedSlateport::
# 324 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
# 325 "data/maps/DewfordTown/scripts.pory"
	return
# 326 "data/maps/DewfordTown/scripts.pory"

# 327 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_SailToPetalburg:
# 328 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 329 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 330 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 331 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 332 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 333 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 334 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 335 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 336 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 337 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 338 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 339 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 340 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 341 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 342 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 343 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 344 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 345 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 346 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 347 "data/maps/DewfordTown/scripts.pory"
	walk_left
# 348 "data/maps/DewfordTown/scripts.pory"
	walk_left
# 349 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 350 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 351 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 352 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 353 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 354 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 355 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 356 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 357 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 358 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 359 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 360 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 361 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 362 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 363 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 364 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 365 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 366 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 367 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 368 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 369 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 370 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 371 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 372 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 373 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 374 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 375 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 376 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 377 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 378 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 379 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 380 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 381 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 382 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 383 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 384 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 385 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 386 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 387 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 388 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 389 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 390 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 391 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 392 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 393 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 394 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 395 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 396 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 397 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 398 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 399 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 400 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 401 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 402 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 403 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 404 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 405 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 406 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 407 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 408 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 409 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 410 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 411 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 412 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 413 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 414 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 415 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 416 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 417 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 418 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 419 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 420 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 421 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 422 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 423 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 424 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 425 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 426 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 427 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 428 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 429 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 430 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 431 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 432 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 433 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 434 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 435 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 436 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 437 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 438 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 439 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 440 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 441 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 442 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 443 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 444 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 445 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 446 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 447 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 448 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 449 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 450 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 451 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 452 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 453 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 454 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 455 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 456 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 457 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 458 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 459 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 460 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 461 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 462 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 463 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 464 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 465 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 466 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 467 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 468 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 469 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 470 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 471 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 472 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 473 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 474 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 475 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 476 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 477 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 478 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 479 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 480 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 481 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 482 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 483 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 484 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 485 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 486 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 487 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 488 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 489 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 490 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 491 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 492 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 493 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 494 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 495 "data/maps/DewfordTown/scripts.pory"
	walk_faster_left
# 496 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 497 "data/maps/DewfordTown/scripts.pory"
	walk_fast_left
# 498 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 499 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 500 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 501 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 502 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 503 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 504 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 505 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 506 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 507 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 508 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 509 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 510 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 511 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 512 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 513 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 514 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 515 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 516 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 517 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 518 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 519 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 520 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 521 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 522 "data/maps/DewfordTown/scripts.pory"
	step_end
# 523 "data/maps/DewfordTown/scripts.pory"

# 524 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_SailToSlateport:
# 525 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 526 "data/maps/DewfordTown/scripts.pory"
	walk_fast_right
# 527 "data/maps/DewfordTown/scripts.pory"
	walk_fast_right
# 528 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 529 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 530 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 531 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 532 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 533 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 534 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 535 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 536 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 537 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 538 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 539 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 540 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 541 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 542 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 543 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 544 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 545 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 546 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 547 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 548 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 549 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 550 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 551 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 552 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 553 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 554 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 555 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 556 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 557 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 558 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 559 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 560 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 561 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 562 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 563 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 564 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 565 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 566 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 567 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 568 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 569 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 570 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 571 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 572 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 573 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 574 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 575 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 576 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 577 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 578 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 579 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 580 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 581 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 582 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 583 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 584 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 585 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 586 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 587 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 588 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 589 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 590 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 591 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 592 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 593 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 594 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 595 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 596 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 597 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 598 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 599 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 600 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 601 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 602 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 603 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 604 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 605 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 606 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 607 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 608 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 609 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 610 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 611 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 612 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 613 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 614 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 615 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 616 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 617 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 618 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 619 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 620 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 621 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 622 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 623 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 624 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 625 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 626 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 627 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 628 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 629 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 630 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 631 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 632 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 633 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 634 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 635 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 636 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 637 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 638 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 639 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 640 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 641 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 642 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 643 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 644 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 645 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 646 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 647 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 648 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 649 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 650 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 651 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 652 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 653 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 654 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 655 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 656 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 657 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 658 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 659 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 660 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 661 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 662 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 663 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 664 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 665 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 666 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 667 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 668 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 669 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 670 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 671 "data/maps/DewfordTown/scripts.pory"
	walk_faster_right
# 672 "data/maps/DewfordTown/scripts.pory"
	walk_fast_right
# 673 "data/maps/DewfordTown/scripts.pory"
	walk_fast_right
# 674 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 675 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 676 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 677 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 678 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 679 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 680 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 681 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 682 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 683 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 684 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 685 "data/maps/DewfordTown/scripts.pory"
	walk_faster_up
# 686 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 687 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 688 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 689 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 690 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 691 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 692 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 693 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 694 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 695 "data/maps/DewfordTown/scripts.pory"
	walk_fast_up
# 696 "data/maps/DewfordTown/scripts.pory"
	step_end
# 697 "data/maps/DewfordTown/scripts.pory"

# 698 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_PlayerBoardBoat:
# 699 "data/maps/DewfordTown/scripts.pory"
	walk_right
# 700 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 701 "data/maps/DewfordTown/scripts.pory"
	set_invisible
# 702 "data/maps/DewfordTown/scripts.pory"
	step_end
# 703 "data/maps/DewfordTown/scripts.pory"

# 704 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_ExitBoatPetalburg:
# 705 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 706 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 707 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 708 "data/maps/DewfordTown/scripts.pory"
	step_end

# 711 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_ExitBoatSlateport:
# 712 "data/maps/DewfordTown/scripts.pory"
	set_visible
# 713 "data/maps/DewfordTown/scripts.pory"
	delay_4
# 713 "data/maps/DewfordTown/scripts.pory"
	delay_4
# 713 "data/maps/DewfordTown/scripts.pory"
	delay_4
# 714 "data/maps/DewfordTown/scripts.pory"
	delay_2
# 715 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 715 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 715 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 716 "data/maps/DewfordTown/scripts.pory"
	walk_in_place_faster_down
	step_end

# 719 "data/maps/DewfordTown/scripts.pory"

# 720 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_BrineyBoardBoat:
# 721 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 722 "data/maps/DewfordTown/scripts.pory"
	step_end
# 723 "data/maps/DewfordTown/scripts.pory"

# 724 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Movement_BrineyExitBoat:
# 725 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 726 "data/maps/DewfordTown/scripts.pory"
	walk_up
# 727 "data/maps/DewfordTown/scripts.pory"
	step_end
# 728 "data/maps/DewfordTown/scripts.pory"

# 729 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_TrendyPhraseBoy::
# 730 "data/maps/DewfordTown/scripts.pory"
	lock
# 731 "data/maps/DewfordTown/scripts.pory"
	faceplayer
# 732 "data/maps/DewfordTown/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 733 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
# 734 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
# 735 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
# 736 "data/maps/DewfordTown/scripts.pory"
	end
# 737 "data/maps/DewfordTown/scripts.pory"

# 738 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_ConfirmTrendyPhrase::
# 739 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
# 740 "data/maps/DewfordTown/scripts.pory"
	release
# 741 "data/maps/DewfordTown/scripts.pory"
	end
# 742 "data/maps/DewfordTown/scripts.pory"

# 743 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_RejectTrendyPhrase::
# 744 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
# 745 "data/maps/DewfordTown/scripts.pory"
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
# 746 "data/maps/DewfordTown/scripts.pory"
	call Common_ShowEasyChatScreen
# 747 "data/maps/DewfordTown/scripts.pory"
	lock
# 748 "data/maps/DewfordTown/scripts.pory"
	faceplayer
# 749 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
# 750 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
# 751 "data/maps/DewfordTown/scripts.pory"
	end
# 752 "data/maps/DewfordTown/scripts.pory"

# 753 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_GiveNewTrendyPhrase::
# 754 "data/maps/DewfordTown/scripts.pory"
	incrementgamestat GAME_STAT_STARTED_TRENDS
# 755 "data/maps/DewfordTown/scripts.pory"
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
# 756 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
# 757 "data/maps/DewfordTown/scripts.pory"
	release
# 758 "data/maps/DewfordTown/scripts.pory"
	end
# 759 "data/maps/DewfordTown/scripts.pory"

# 760 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_CancelNewTrendyPhrase::
# 761 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
# 762 "data/maps/DewfordTown/scripts.pory"
	release
# 763 "data/maps/DewfordTown/scripts.pory"
	end
# 764 "data/maps/DewfordTown/scripts.pory"

# 765 "data/maps/DewfordTown/scripts.pory"
DewfordTown_EventScript_PhraseNotTrendyEnough::
# 766 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
# 767 "data/maps/DewfordTown/scripts.pory"
	release
# 768 "data/maps/DewfordTown/scripts.pory"
	end

DewfordTown_EventScript_Rival1::
# 772 "data/maps/DewfordTown/scripts.pory"
	lock
# 773 "data/maps/DewfordTown/scripts.pory"
	applymovement 7, Common_Movement_FacePlayer
# 774 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 775 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_StevenWasWellHidden, MSGBOX_DEFAULT
# 776 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_BADGE02_GET
# 777 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_Rival1_2
# 781 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_CongratsBeatingBrawly, MSGBOX_DEFAULT
DewfordTown_EventScript_Rival1_1:
# 783 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_JustLetBrineyKnow, MSGBOX_DEFAULT
# 784 "data/maps/DewfordTown/scripts.pory"
	applymovement 7, Common_Movement_FaceLeft
# 785 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 786 "data/maps/DewfordTown/scripts.pory"
	release
	end

DewfordTown_EventScript_Rival1_2:
# 778 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_WhyNotBeatTheGym, MSGBOX_DEFAULT
	goto DewfordTown_EventScript_Rival1_1


DewfordTown_EventScript_Rival2::
# 812 "data/maps/DewfordTown/scripts.pory"
	lock
# 813 "data/maps/DewfordTown/scripts.pory"
	applymovement 6, Common_Movement_FacePlayer
# 814 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 815 "data/maps/DewfordTown/scripts.pory"
	checkflag FLAG_BADGE02_GET
# 816 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_EventScript_Rival2_2
DewfordTown_EventScript_Rival2_1:
# 819 "data/maps/DewfordTown/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq DewfordTown_EventScript_Rival2_5
DewfordTown_EventScript_Rival2_4:
# 822 "data/maps/DewfordTown/scripts.pory"
	applymovement 6, Common_Movement_FaceRight
# 823 "data/maps/DewfordTown/scripts.pory"
	waitmovement 0
# 824 "data/maps/DewfordTown/scripts.pory"
	release
	end

DewfordTown_EventScript_Rival2_2:
# 817 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_BadgeAsGoodAsYours, MSGBOX_DEFAULT
	goto DewfordTown_EventScript_Rival2_1

DewfordTown_EventScript_Rival2_5:
# 820 "data/maps/DewfordTown/scripts.pory"
	msgbox DewfordTown_Text_NiceBadge
	goto DewfordTown_EventScript_Rival2_4


# 841 "data/maps/DewfordTown/scripts.pory"

# 842 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_TinyIslandCommunity:
# 843 "data/maps/DewfordTown/scripts.pory"
	.string "DEWFORD is a tiny island community.\n"
# 844 "data/maps/DewfordTown/scripts.pory"
	.string "If something gets trendy here,\l"
# 845 "data/maps/DewfordTown/scripts.pory"
	.string "everyone picks up on it right away.$"
# 846 "data/maps/DewfordTown/scripts.pory"

# 847 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_TownSign:
# 848 "data/maps/DewfordTown/scripts.pory"
	.string "DEWFORD TOWN\n"
# 849 "data/maps/DewfordTown/scripts.pory"
	.string "“A tiny island in the blue sea.”$"
# 850 "data/maps/DewfordTown/scripts.pory"

# 851 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_GymSign:
# 852 "data/maps/DewfordTown/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM\n"
# 853 "data/maps/DewfordTown/scripts.pory"
	.string "LEADER: BRAWLY\l"
# 854 "data/maps/DewfordTown/scripts.pory"
	.string "“A big wave in fighting!”$"
# 855 "data/maps/DewfordTown/scripts.pory"

# 856 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_HallSign:
# 857 "data/maps/DewfordTown/scripts.pory"
	.string "DEWFORD HALL\n"
# 858 "data/maps/DewfordTown/scripts.pory"
	.string "“Everyone's information exchange!”$"
# 859 "data/maps/DewfordTown/scripts.pory"

# 860 "data/maps/DewfordTown/scripts.pory"
Route104_Text_LandedInDewfordDeliverLetter:
# 861 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 862 "data/maps/DewfordTown/scripts.pory"
	.string "We've hit land in DEWFORD.\p"
# 863 "data/maps/DewfordTown/scripts.pory"
	.string "I suppose you're off to deliver that\n"
# 864 "data/maps/DewfordTown/scripts.pory"
	.string "LETTER to, who was it now, STEVEN!$"
# 865 "data/maps/DewfordTown/scripts.pory"

# 866 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_SetSailBackToPetalburg:
# 867 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: Have you delivered your\n"
# 868 "data/maps/DewfordTown/scripts.pory"
	.string "LETTER?\p"
# 869 "data/maps/DewfordTown/scripts.pory"
	.string "Or were you meaning to sail back to\n"
# 870 "data/maps/DewfordTown/scripts.pory"
	.string "PETALBURG?$"
# 871 "data/maps/DewfordTown/scripts.pory"

# 872 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_PetalburgWereSettingSail2:
# 873 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: PETALBURG it is, then!\p"
# 874 "data/maps/DewfordTown/scripts.pory"
	.string "Anchors aweigh!\n"
# 875 "data/maps/DewfordTown/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"
# 876 "data/maps/DewfordTown/scripts.pory"

# 877 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_GoDeliverIllBeWaiting:
# 878 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: Then you go on and deliver\n"
# 879 "data/maps/DewfordTown/scripts.pory"
	.string "the LETTER. I'll be waiting.$"
# 880 "data/maps/DewfordTown/scripts.pory"

# 881 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_BrineyLandedInDewford:
# 882 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 883 "data/maps/DewfordTown/scripts.pory"
	.string "We've hit land in DEWFORD!\p"
# 884 "data/maps/DewfordTown/scripts.pory"
	.string "You just go on and tell me whenever\n"
# 885 "data/maps/DewfordTown/scripts.pory"
	.string "you want to set sail again!$"
# 886 "data/maps/DewfordTown/scripts.pory"

# 887 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_WhereAreWeBound:
# 888 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: Ahoy!\n"
# 889 "data/maps/DewfordTown/scripts.pory"
	.string "For you, I'll go out to sea anytime!\p"
# 890 "data/maps/DewfordTown/scripts.pory"
	.string "Now, my friend, where are we bound?$"
# 891 "data/maps/DewfordTown/scripts.pory"

# 892 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_PetalburgWereSettingSail:
# 893 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: PETALBURG, is it?\p"
# 894 "data/maps/DewfordTown/scripts.pory"
	.string "Anchors aweigh!\n"
# 895 "data/maps/DewfordTown/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"
# 896 "data/maps/DewfordTown/scripts.pory"

# 897 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_SlateportWereSettingSail:
# 898 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: SLATEPORT, is it?\p"
# 899 "data/maps/DewfordTown/scripts.pory"
	.string "Anchors aweigh!\n"
# 900 "data/maps/DewfordTown/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"
# 901 "data/maps/DewfordTown/scripts.pory"

# 902 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
# 903 "data/maps/DewfordTown/scripts.pory"
	.string "MR. BRINEY: You just tell me whenever\n"
# 904 "data/maps/DewfordTown/scripts.pory"
	.string "you need to set sail again!$"
# 905 "data/maps/DewfordTown/scripts.pory"

# 906 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_GettingItchToFish:
# 907 "data/maps/DewfordTown/scripts.pory"
	.string "This is a renowned fishing spot.\n"
# 908 "data/maps/DewfordTown/scripts.pory"
	.string "Are you getting the itch to fish?$"
# 909 "data/maps/DewfordTown/scripts.pory"

# 910 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_GiveYouOneOfMyRods:
# 911 "data/maps/DewfordTown/scripts.pory"
	.string "I hear you, and I like what\n"
# 912 "data/maps/DewfordTown/scripts.pory"
	.string "you're saying!\p"
# 913 "data/maps/DewfordTown/scripts.pory"
	.string "I'll give you one of my fishing RODS.$"
# 914 "data/maps/DewfordTown/scripts.pory"

# 915 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_ThrowInFishingAdvice:
# 916 "data/maps/DewfordTown/scripts.pory"
	.string "And, as an added bonus, I'll even throw\n"
# 917 "data/maps/DewfordTown/scripts.pory"
	.string "in a little fishing advice!\p"
# 918 "data/maps/DewfordTown/scripts.pory"
	.string "First, you want to face the water,\n"
# 919 "data/maps/DewfordTown/scripts.pory"
	.string "then use the ROD.\p"
# 920 "data/maps/DewfordTown/scripts.pory"
	.string "Focus your mind…\n"
# 921 "data/maps/DewfordTown/scripts.pory"
	.string "If you get a bite, pull on the ROD.\p"
# 922 "data/maps/DewfordTown/scripts.pory"
	.string "Sometimes you can snag something\n"
# 923 "data/maps/DewfordTown/scripts.pory"
	.string "immediately, but with bigger catches,\l"
# 924 "data/maps/DewfordTown/scripts.pory"
	.string "you need to time the pulls on your ROD\l"
# 925 "data/maps/DewfordTown/scripts.pory"
	.string "to haul them in.$"
# 926 "data/maps/DewfordTown/scripts.pory"

# 927 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_ThatsTooBadThen:
# 928 "data/maps/DewfordTown/scripts.pory"
	.string "Oh, is that so?\n"
# 929 "data/maps/DewfordTown/scripts.pory"
	.string "That's too bad, then.$"
# 930 "data/maps/DewfordTown/scripts.pory"

# 931 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_HowsYourFishing:
# 932 "data/maps/DewfordTown/scripts.pory"
	.string "Yo!\n"
# 933 "data/maps/DewfordTown/scripts.pory"
	.string "How's your fishing?$"
# 934 "data/maps/DewfordTown/scripts.pory"

# 935 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_GreatHaulInSomeBigOnes:
# 936 "data/maps/DewfordTown/scripts.pory"
	.string "Is that right! That's great!\n"
# 937 "data/maps/DewfordTown/scripts.pory"
	.string "Haul in some big ones!$"
# 938 "data/maps/DewfordTown/scripts.pory"

# 939 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_FishingAdvice:
# 940 "data/maps/DewfordTown/scripts.pory"
	.string "Oh, hey, don't get down on yourself!\n"
# 941 "data/maps/DewfordTown/scripts.pory"
	.string "I'll give you a little fishing advice.\p"
# 942 "data/maps/DewfordTown/scripts.pory"
	.string "First, you want to face the water,\n"
# 943 "data/maps/DewfordTown/scripts.pory"
	.string "then use the ROD.\p"
# 944 "data/maps/DewfordTown/scripts.pory"
	.string "Focus your mind…\n"
# 945 "data/maps/DewfordTown/scripts.pory"
	.string "If you get a bite, pull the ROD.\p"
# 946 "data/maps/DewfordTown/scripts.pory"
	.string "Sometimes you can snag something\n"
# 947 "data/maps/DewfordTown/scripts.pory"
	.string "immediately, but with bigger catches,\l"
# 948 "data/maps/DewfordTown/scripts.pory"
	.string "you need to time the pulls on your ROD\l"
# 949 "data/maps/DewfordTown/scripts.pory"
	.string "to haul them in.$"
# 950 "data/maps/DewfordTown/scripts.pory"

# 951 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_XIsTheBiggestHappeningThingRight:
# 952 "data/maps/DewfordTown/scripts.pory"
	.string "I like what's hip, happening, and trendy.\n"
# 953 "data/maps/DewfordTown/scripts.pory"
	.string "I'm always checking it out.\p"
# 954 "data/maps/DewfordTown/scripts.pory"
	.string "Listen, have you heard about this new\n"
# 955 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_1}”?\p"
# 956 "data/maps/DewfordTown/scripts.pory"
	.string "That's right!\n"
# 957 "data/maps/DewfordTown/scripts.pory"
	.string "Of course you know!\p"
# 958 "data/maps/DewfordTown/scripts.pory"
	.string "I mean, sheesh,\n"
# 959 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_1}”…\l"
# 960 "data/maps/DewfordTown/scripts.pory"
	.string "It's the hottest thing in cool!\p"
# 961 "data/maps/DewfordTown/scripts.pory"
	.string "Wherever you're from,\n"
# 962 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 963 "data/maps/DewfordTown/scripts.pory"
	.string "is the biggest happening thing, right?$"
# 964 "data/maps/DewfordTown/scripts.pory"

# 965 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_TellMeWhatsNewAndIn:
# 966 "data/maps/DewfordTown/scripts.pory"
	.string "Hunh?\n"
# 967 "data/maps/DewfordTown/scripts.pory"
	.string "It's not the hip and happening thing?\p"
# 968 "data/maps/DewfordTown/scripts.pory"
	.string "Well, hey, you have to tell me,\n"
# 969 "data/maps/DewfordTown/scripts.pory"
	.string "what's new and what's “in”?$"
# 970 "data/maps/DewfordTown/scripts.pory"

# 971 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_OfCourseIKnowAboutThat:
# 972 "data/maps/DewfordTown/scripts.pory"
	.string "Hunh?\n"
# 973 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_2}”?\p"
# 974 "data/maps/DewfordTown/scripts.pory"
	.string "… …\p"
# 975 "data/maps/DewfordTown/scripts.pory"
	.string "…Uh… Yeah! That's right!\n"
# 976 "data/maps/DewfordTown/scripts.pory"
	.string "Yeah, I knew that! Knew it all along!\p"
# 977 "data/maps/DewfordTown/scripts.pory"
	.string "Of course I know about that!\n"
# 978 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_2},” right?\p"
# 979 "data/maps/DewfordTown/scripts.pory"
	.string "Yeah, that's it, it's there!\n"
# 980 "data/maps/DewfordTown/scripts.pory"
	.string "Isn't “{STR_VAR_2}”\l"
# 981 "data/maps/DewfordTown/scripts.pory"
	.string "the coolest, or what?\p"
# 982 "data/maps/DewfordTown/scripts.pory"
	.string "It's the hippest thing in hip.\n"
# 983 "data/maps/DewfordTown/scripts.pory"
	.string "You think I'd not know about it?\p"
# 984 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_1}”…\n"
# 985 "data/maps/DewfordTown/scripts.pory"
	.string "It's, like, so five minutes ago.\p"
# 986 "data/maps/DewfordTown/scripts.pory"
	.string "Now, “{STR_VAR_2}” is\n"
# 987 "data/maps/DewfordTown/scripts.pory"
	.string "what's vital and in tune with the times!$"
# 988 "data/maps/DewfordTown/scripts.pory"

# 989 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_XHuhIThinkYIsCool:
# 990 "data/maps/DewfordTown/scripts.pory"
	.string "Hmm…\n"
# 991 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_2},” huh?\p"
# 992 "data/maps/DewfordTown/scripts.pory"
	.string "But personally, I think\n"
# 993 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 994 "data/maps/DewfordTown/scripts.pory"
	.string "is what's real in cool.$"
# 995 "data/maps/DewfordTown/scripts.pory"

# 996 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
# 997 "data/maps/DewfordTown/scripts.pory"
	.string "Well, if you hear of any happening new\n"
# 998 "data/maps/DewfordTown/scripts.pory"
	.string "trends, come share them with me, okay?$"
# 999 "data/maps/DewfordTown/scripts.pory"

# 1000 "data/maps/DewfordTown/scripts.pory"
DewfordTown_Text_YeahDefinitionOfInRightNow:
# 1001 "data/maps/DewfordTown/scripts.pory"
	.string "Yeah, absolutely right!\p"
# 1002 "data/maps/DewfordTown/scripts.pory"
	.string "“{STR_VAR_1}” is the\n"
# 1003 "data/maps/DewfordTown/scripts.pory"
	.string "definition of “in” right now.$"

DewfordTown_Text_GoingToMuseum::
# 306 "data/maps/DewfordTown/scripts.pory"
	.string "I'm gonna go check out SLATEPORT.\n"
	.string "I hear they have an awesome museum!\p"
	.string "Come find me when you locate CAPT.\n"
	.string "STERN.$"

DewfordTown_Text_HitTheBeach::
# 312 "data/maps/DewfordTown/scripts.pory"
	.string "Man, museums sound boring.\n"
	.string "I'm going to hit the beach!\p"
	.string "See you later!$"

DewfordTown_Text_StevenWasWellHidden::
# 790 "data/maps/DewfordTown/scripts.pory"
	.string "You found STEVEN?\n"
	.string "He sure was well hidden, wasn't he!$"

DewfordTown_Text_WhyNotBeatTheGym::
# 795 "data/maps/DewfordTown/scripts.pory"
	.string "We're in no hurry to continue on.\n"
	.string "Why not beat the gym while we're here?$"

DewfordTown_Text_CongratsBeatingBrawly::
# 800 "data/maps/DewfordTown/scripts.pory"
	.string "Congrats on beating BRAWLEY!\n"
	.string "That gym was so dark!$"

DewfordTown_Text_JustLetBrineyKnow::
# 805 "data/maps/DewfordTown/scripts.pory"
	.string "We can head to SLATEPORT\n"
	.string "whenever you want.\l"
	.string "Just let BRINEY know when you're ready\l"
	.string "and we can go deliver those GOODS.$"

DewfordTown_Text_BadgeAsGoodAsYours::
# 828 "data/maps/DewfordTown/scripts.pory"
	.string "You're afraid to face the gym, eh?\n"
	.string "I get it. BRAWLEY was no joke for me.\l"
	.string "Tougher than ROXANNE, for sure!\l"
	.string "But I'm sure you can win if you give it\l"
	.string "your all.\l"
	.string "That KNUCKLE BADGE is as good as yours!$"

DewfordTown_Text_NiceBadge::
# 836 "data/maps/DewfordTown/scripts.pory"
	.string "Nice badge!\n"
	.string "I knew you could do it!$"
