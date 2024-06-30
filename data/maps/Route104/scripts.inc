# 6 "data/maps/Route104/scripts.pory"

# 7 "data/maps/Route104/scripts.pory"
@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
# 8 "data/maps/Route104/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 9 "data/maps/Route104/scripts.pory"
.set LOCALID_BRINEY, 8
# 10 "data/maps/Route104/scripts.pory"
.set LOCALID_RIVAL1, 34
# 11 "data/maps/Route104/scripts.pory"
.set LOCALID_RIVAL2, 35
# 12 "data/maps/Route104/scripts.pory"
.set LOCALID_PEEKO, 36

Route104_MapScripts::
# 16 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 19 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 23 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route104_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

Route104_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 17 "data/maps/Route104/scripts.pory"
	call Route104_OnTransition
	return

Route104_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 20 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 21 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 10, Route104_EventScript_StartSailToDewfordAfterWaitForRival
	.2byte 0

Route104_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 24 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
# 27 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 10, Route104_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

Route104_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
# 25 "data/maps/Route104/scripts.pory"
	hideobjectat 36, MAP_ROUTE104
	return

Route104_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
# 28 "data/maps/Route104/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return


Route104_EventScript_StartSailToDewford::
# 34 "data/maps/Route104/scripts.pory"
	lockall
# 35 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
	return


Route104_OnTransition::
# 39 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_102_RIVAL1
# 40 "data/maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 41 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 42 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 43 "data/maps/Route104/scripts.pory"
	compare VAR_BOARD_BRINEY_BOAT_STATE, 10
	goto_if_eq Route104_OnTransition_2
Route104_OnTransition_1:
	return

Route104_OnTransition_2:
# 44 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL1
# 45 "data/maps/Route104/scripts.pory"
	setobjectxyperm 8, 16, 51
# 46 "data/maps/Route104/scripts.pory"
	setobjectxyperm 36, 17, 51
# 47 "data/maps/Route104/scripts.pory"
	setobjectxyperm 34, 18, 51
# 48 "data/maps/Route104/scripts.pory"
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_LEFT
# 49 "data/maps/Route104/scripts.pory"
	setobjectmovementtype 34, MOVEMENT_TYPE_FACE_LEFT
	goto Route104_OnTransition_1


# 54 "data/maps/Route104/scripts.pory"

# 55 "data/maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 56 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 57 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 58 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 59 "data/maps/Route104/scripts.pory"
	return
# 60 "data/maps/Route104/scripts.pory"

# 61 "data/maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 62 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 63 "data/maps/Route104/scripts.pory"
	return
# 64 "data/maps/Route104/scripts.pory"

# 65 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 66 "data/maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 67 "data/maps/Route104/scripts.pory"
	goto_if_le VAR_RUSTBORO_CITY_STATE, 7, Route104_EventScript_DontSetRivalPos
# 68 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL1, 17, 50
# 69 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY, 17, 50
# 70 "data/maps/Route104/scripts.pory"
	turnobject LOCALID_BRINEY, DIR_SOUTH
# 71 "data/maps/Route104/scripts.pory"
	return
# 72 "data/maps/Route104/scripts.pory"

# 73 "data/maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 74 "data/maps/Route104/scripts.pory"
	return

Route104_EventScript_StartSailToDewfordAfterWaitForRival::
# 78 "data/maps/Route104/scripts.pory"
	lockall
# 79 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_LeaveWithoutRival2
	return


Route104_EventScript_Rival1::
# 83 "data/maps/Route104/scripts.pory"
	lockall
# 84 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_FacePlayer
# 85 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 86 "data/maps/Route104/scripts.pory"
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_lt Route104_EventScript_Rival1_2
# 97 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_SeeWhatsTakingSoLong, MSGBOX_DEFAULT
# 98 "data/maps/Route104/scripts.pory"
	releaseall
	end

Route104_EventScript_Rival1_2:
# 87 "data/maps/Route104/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route104_EventScript_Rival1_5
# 92 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsAcrossTheSea, MSGBOX_DEFAULT
Route104_EventScript_Rival1_4:
# 94 "data/maps/Route104/scripts.pory"
	releaseall
	end

Route104_EventScript_Rival1_5:
# 88 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeToSurf, MSGBOX_DEFAULT
# 89 "data/maps/Route104/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route104_EventScript_Rival1_4


Route104_EventScript_RivalTrigger::
# 111 "data/maps/Route104/scripts.pory"
	lockall
# 112 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 113 "data/maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 114 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 115 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 116 "data/maps/Route104/scripts.pory"
	delay 10
# 117 "data/maps/Route104/scripts.pory"
	addobject 34
# 118 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
# 119 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 120 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_RivalExitBrineysCottage
# 121 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 122 "data/maps/Route104/scripts.pory"
	delay 20
# 123 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 124 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 125 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 126 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 127 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 128 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_Delay48
# 129 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 130 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_Rival1Encounter
	return


# 133 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 134 "data/maps/Route104/scripts.pory"
	walk_slow_left
	step_end

# 137 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 138 "data/maps/Route104/scripts.pory"
	walk_down
# 139 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 142 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 143 "data/maps/Route104/scripts.pory"
	delay_4
# 144 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
	step_end

Route104_EventScript_RestoreMusic::
# 148 "data/maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 149 "data/maps/Route104/scripts.pory"
	fadedefaultbgm
	return


Route104_EventScript_Rival1Encounter::
# 154 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyStillPreparing, MSGBOX_DEFAULT
# 155 "data/maps/Route104/scripts.pory"
	closemessage
# 156 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 6, Route104_EventScript_BattleRival1
# 157 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_Rival1HowsYourPokedex
# 158 "data/maps/Route104/scripts.pory"
	waitmessage
# 159 "data/maps/Route104/scripts.pory"
	fadeoutbgm 1
# 160 "data/maps/Route104/scripts.pory"
	savebgm MUS_ROUTE104
# 161 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerWaitForRival2
# 162 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_WaitForRival2
# 163 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 164 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TakingALongTime, MSGBOX_DEFAULT
# 165 "data/maps/Route104/scripts.pory"
	closemessage
# 166 "data/maps/Route104/scripts.pory"
	delay 40
# 167 "data/maps/Route104/scripts.pory"
	playbgm MUS_ROUTE104, TRUE
# 168 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 169 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 170 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 171 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_FaceUp
# 172 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 173 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 174 "data/maps/Route104/scripts.pory"
	addobject 8
# 175 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_StepOutOfBrineysWay
# 176 "data/maps/Route104/scripts.pory"
	applymovement 8, Route104_Movement_StepOutOfCottage
# 177 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 178 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_AreYouReadyToGo, MSGBOX_DEFAULT
# 179 "data/maps/Route104/scripts.pory"
	closemessage
# 180 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_Player1ShallWeWait
# 181 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1ShallWeWait
# 182 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 183 "data/maps/Route104/scripts.pory"
	delay 10
# 184 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DoYouThinkWeShouldWait, MSGBOX_YESNO
# 185 "data/maps/Route104/scripts.pory"
	closemessage
# 186 "data/maps/Route104/scripts.pory"
	switch VAR_RESULT
# 187 "data/maps/Route104/scripts.pory"
	case NO, Route104_EventScript_Rival1Encounter_3
# 189 "data/maps/Route104/scripts.pory"
	case YES, Route104_EventScript_Rival1Encounter_4
Route104_EventScript_Rival1Encounter_1:
# 192 "data/maps/Route104/scripts.pory"
	releaseall
	end

Route104_EventScript_Rival1Encounter_3:
# 188 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_DontWaitForRival
	goto Route104_EventScript_Rival1Encounter_1

Route104_EventScript_Rival1Encounter_4:
# 190 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_WaitForRival
	goto Route104_EventScript_Rival1Encounter_1


Route104_EventScript_BattleRival1::
# 197 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_Rival1BattleIntro, MSGBOX_DEFAULT
# 198 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 7
# 199 "data/maps/Route104/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 200 "data/maps/Route104/scripts.pory"
	checkfriendchoice
# 201 "data/maps/Route104/scripts.pory"
	switch VAR_RESULT
# 202 "data/maps/Route104/scripts.pory"
	case SPENCER, Route104_EventScript_BattleRival1_3
# 204 "data/maps/Route104/scripts.pory"
	case BREN, Route104_EventScript_BattleRival1_4
# 206 "data/maps/Route104/scripts.pory"
	case KYLE, Route104_EventScript_BattleRival1_5
Route104_EventScript_BattleRival1_1:
	return

Route104_EventScript_BattleRival1_3:
# 203 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_RUSTBORO, RustboroCity_Text_RivalEndBattleBren
	goto Route104_EventScript_BattleRival1_1

Route104_EventScript_BattleRival1_4:
# 205 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_RUSTBORO, RustboroCity_Text_RivalEndBattleKyle
	goto Route104_EventScript_BattleRival1_1

Route104_EventScript_BattleRival1_5:
# 207 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_RUSTBORO, RustboroCity_Text_RivalEndBattleSpencer
	goto Route104_EventScript_BattleRival1_1


Route104_EventScript_WaitForRival::
# 213 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 9
# 214 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 215 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_FaceUp
# 216 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_BeginTalkDown
# 217 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 218 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LetMeKnowWhenReadyToSail, MSGBOX_DEFAULT
# 219 "data/maps/Route104/scripts.pory"
	closemessage
# 220 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_WalkInPlaceFasterUp
# 221 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route104/scripts.pory"
	applymovement 8, Route104_Movement_EnterCottage
# 223 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 224 "data/maps/Route104/scripts.pory"
	removeobject 8
# 225 "data/maps/Route104/scripts.pory"
	delay 10
# 226 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 227 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_WalkInPlaceFasterLeft
# 228 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_SeeWhatsTakingSoLong, MSGBOX_DEFAULT
# 230 "data/maps/Route104/scripts.pory"
	closemessage
# 231 "data/maps/Route104/scripts.pory"
	delay 5
# 232 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_GoWaitForOtherRival
# 233 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 234 "data/maps/Route104/scripts.pory"
	releaseall
	end


Route104_EventScript_GoFindRivalTrigger1::
# 239 "data/maps/Route104/scripts.pory"
	lock
# 240 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8006, 1
# 241 "data/maps/Route104/scripts.pory"
	addobject 35
# 242 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2WalksIn
# 243 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 244 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 245 "data/maps/Route104/scripts.pory"
	applymovement 35, Common_Movement_ExclamationMark
# 246 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 247 "data/maps/Route104/scripts.pory"
	delay 20
# 248 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2ApproachPlayer1
# 249 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 250 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_Rival2ShowsUp
	return


Route104_EventScript_GoFindRivalTrigger2::
# 254 "data/maps/Route104/scripts.pory"
	lock
# 255 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8006, 2
# 256 "data/maps/Route104/scripts.pory"
	setobjectxyperm 35, 23, 46
# 257 "data/maps/Route104/scripts.pory"
	addobject 35
# 258 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2WalksIn
# 259 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 260 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 261 "data/maps/Route104/scripts.pory"
	applymovement 35, Common_Movement_ExclamationMark
# 262 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 263 "data/maps/Route104/scripts.pory"
	delay 20
# 264 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForApproach2
# 265 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2ApproachPlayer2
# 266 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 267 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_Rival2ShowsUp
	return


Route104_EventScript_GoFindRivalTrigger3::
# 271 "data/maps/Route104/scripts.pory"
	lock
# 272 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8006, 3
# 273 "data/maps/Route104/scripts.pory"
	setobjectxyperm 35, 23, 47
# 274 "data/maps/Route104/scripts.pory"
	addobject 35
# 275 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2WalksIn
# 276 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 277 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 278 "data/maps/Route104/scripts.pory"
	applymovement 35, Common_Movement_ExclamationMark
# 279 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 280 "data/maps/Route104/scripts.pory"
	delay 20
# 281 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForApproach3
# 282 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2ApproachPlayer3
# 283 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 284 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_Rival2ShowsUp
	return


Route104_EventScript_BeachTriggerLeft::
# 288 "data/maps/Route104/scripts.pory"
	lockall
# 289 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 290 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_ApproachPlayerBeachLeft
# 291 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 292 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_NotTheWayToRustboro, MSGBOX_DEFAULT
# 293 "data/maps/Route104/scripts.pory"
	closemessage
# 294 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Walk_Up
# 295 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1ReturnFromBeachBlockLeft
	return


Route104_EventScript_BeachTriggerRight::
# 299 "data/maps/Route104/scripts.pory"
	lockall
# 300 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 301 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_ApproachPlayerBeachRight
# 302 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 303 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_NotTheWayToRustboro, MSGBOX_DEFAULT
# 304 "data/maps/Route104/scripts.pory"
	closemessage
# 305 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Walk_Up
# 306 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1ReturnFromBeachBlockRight
	return


# 309 "data/maps/Route104/scripts.pory"
Route104_Movement_ApproachPlayerBeachLeft:
# 310 "data/maps/Route104/scripts.pory"
	walk_down
# 311 "data/maps/Route104/scripts.pory"
	walk_left
# 311 "data/maps/Route104/scripts.pory"
	walk_left
# 312 "data/maps/Route104/scripts.pory"
	walk_down
	step_end

# 315 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1ReturnFromBeachBlockLeft:
# 316 "data/maps/Route104/scripts.pory"
	walk_up
# 317 "data/maps/Route104/scripts.pory"
	walk_right
# 317 "data/maps/Route104/scripts.pory"
	walk_right
# 318 "data/maps/Route104/scripts.pory"
	walk_up
# 319 "data/maps/Route104/scripts.pory"
	face_down
	step_end

# 322 "data/maps/Route104/scripts.pory"
Route104_Movement_ApproachPlayerBeachRight:
# 323 "data/maps/Route104/scripts.pory"
	walk_down
# 324 "data/maps/Route104/scripts.pory"
	walk_left
# 325 "data/maps/Route104/scripts.pory"
	walk_down
	step_end

# 328 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1ReturnFromBeachBlockRight:
# 329 "data/maps/Route104/scripts.pory"
	walk_up
# 330 "data/maps/Route104/scripts.pory"
	walk_right
# 331 "data/maps/Route104/scripts.pory"
	walk_up
# 332 "data/maps/Route104/scripts.pory"
	face_down
	step_end

Route104_EventScript_Rival2ShowsUp::
# 342 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_AfraidYouLeftWithoutMe
# 343 "data/maps/Route104/scripts.pory"
	closemessage
# 344 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1Approach
# 345 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 346 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 347 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_ApproachRival1
# 348 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_BeginTalkRight
# 349 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 350 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_IllGoLetBrineyKnow, MSGBOX_DEFAULT
# 351 "data/maps/Route104/scripts.pory"
	closemessage
# 352 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 353 "data/maps/Route104/scripts.pory"
	applymovement 35, Common_Movement_Walk_Left
# 354 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_GoTellBriney
# 355 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 356 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_EnterCottage
# 357 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 358 "data/maps/Route104/scripts.pory"
	delay 5
# 359 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 360 "data/maps/Route104/scripts.pory"
	applymovement 35, Common_Movement_BeginTalkUp
# 361 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 362 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WeShouldRegister
# 363 "data/maps/Route104/scripts.pory"
	closemessage
# 364 "data/maps/Route104/scripts.pory"
	delay 30
# 365 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 366 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_RegisteredRival2, MSGBOX_DEFAULT
# 367 "data/maps/Route104/scripts.pory"
	waitfanfare
# 368 "data/maps/Route104/scripts.pory"
	closemessage
# 369 "data/maps/Route104/scripts.pory"
	checkfriendchoice
# 370 "data/maps/Route104/scripts.pory"
	switch VAR_RESULT
# 371 "data/maps/Route104/scripts.pory"
	case SPENCER, Route104_EventScript_Rival2ShowsUp_3
# 373 "data/maps/Route104/scripts.pory"
	case BREN, Route104_EventScript_Rival2ShowsUp_4
# 375 "data/maps/Route104/scripts.pory"
	case KYLE, Route104_EventScript_Rival2ShowsUp_5
Route104_EventScript_Rival2ShowsUp_1:
# 378 "data/maps/Route104/scripts.pory"
	setvar VAR_0x800A, 2
# 379 "data/maps/Route104/scripts.pory"
	delay 30
# 380 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 381 "data/maps/Route104/scripts.pory"
	applymovement 35, Common_Movement_FaceLeft
# 382 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1ComesBackOutOfCottage
# 383 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 384 "data/maps/Route104/scripts.pory"
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_DOWN
# 385 "data/maps/Route104/scripts.pory"
	addobject 8
# 386 "data/maps/Route104/scripts.pory"
	applymovement 8, Route104_Movement_StepOutOfCottage
# 387 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 388 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_BeginTalkRight
# 389 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 390 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_AnchorsAweigh, MSGBOX_DEFAULT
# 391 "data/maps/Route104/scripts.pory"
	closemessage
# 392 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_BeginTalkUp
# 393 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 394 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_PeekoSettingSail, MSGBOX_DEFAULT
# 395 "data/maps/Route104/scripts.pory"
	closemessage
# 396 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_Walk_Left
# 397 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 398 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_FaceRight
# 399 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 400 "data/maps/Route104/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 401 "data/maps/Route104/scripts.pory"
	addobject 36
# 402 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Movement_StepOutOfCottage
# 403 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_JoinBoatCrew
# 404 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 405 "data/maps/Route104/scripts.pory"
	waitmoncry
# 406 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 407 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 408 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 10
# 409 "data/maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 410 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 411 "data/maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 412 "data/maps/Route104/scripts.pory"
	setobjectsubpriority 34, MAP_ROUTE104, 0
# 413 "data/maps/Route104/scripts.pory"
	setobjectsubpriority 35, MAP_ROUTE104, 0
# 414 "data/maps/Route104/scripts.pory"
	setobjectsubpriority 36, MAP_ROUTE104, 0
# 415 "data/maps/Route104/scripts.pory"
	applymovement 8, Route104_Movement_BrineyBoardShip
# 416 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Movement_PeekoBoardShip
# 417 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1BoardShip
# 418 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2BoardShip
# 419 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardShip
# 420 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 421 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 422 "data/maps/Route104/scripts.pory"
	removeobject 36
# 423 "data/maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 424 "data/maps/Route104/scripts.pory"
	hideobjectat 34, MAP_ROUTE104
# 425 "data/maps/Route104/scripts.pory"
	hideobjectat 35, MAP_ROUTE104
# 426 "data/maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 427 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewfordDadCalls
	end

Route104_EventScript_Rival2ShowsUp_3:
# 372 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_KYLE_MATCH_CALL
	goto Route104_EventScript_Rival2ShowsUp_1

Route104_EventScript_Rival2ShowsUp_4:
# 374 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
	goto Route104_EventScript_Rival2ShowsUp_1

Route104_EventScript_Rival2ShowsUp_5:
# 376 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_BREN_MATCH_CALL
	goto Route104_EventScript_Rival2ShowsUp_1


Route104_EventScript_DontWaitForRival::
# 432 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 10
# 433 "data/maps/Route104/scripts.pory"
	setvar VAR_0x800A, 0
# 434 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 435 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_FaceUp
# 436 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_BeginTalkDown
# 437 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 438 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_AnchorsAweigh, MSGBOX_DEFAULT
# 439 "data/maps/Route104/scripts.pory"
	closemessage
# 440 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_FaceUp
# 441 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 442 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_BeginTalkUp
# 443 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 444 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_PeekoSettingSail, MSGBOX_DEFAULT
# 445 "data/maps/Route104/scripts.pory"
	closemessage
# 446 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_Walk_Left
# 447 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 448 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_FaceRight
# 449 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 450 "data/maps/Route104/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 451 "data/maps/Route104/scripts.pory"
	addobject 36
# 452 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Movement_StepOutOfCottage
# 453 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 454 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_Walk_Up
# 455 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 456 "data/maps/Route104/scripts.pory"
	waitmoncry
# 457 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_LeaveWithoutRival2
	return


Route104_EventScript_LeaveWithoutRival2::
# 461 "data/maps/Route104/scripts.pory"
	applymovement 8, Route104_Movement_WalkToBoatInterrupted
# 462 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Movement_WalkToBoatInterrupted
# 463 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_WalkToBoatInterrupted
# 464 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 465 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_WaitForMe
# 466 "data/maps/Route104/scripts.pory"
	waitmessage
# 467 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_FaceRight
# 468 "data/maps/Route104/scripts.pory"
	applymovement 36, Common_Movement_FaceRight
# 469 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_FaceRight
# 470 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 471 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 472 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 473 "data/maps/Route104/scripts.pory"
	applymovement 8, Common_Movement_ExclamationMark
# 474 "data/maps/Route104/scripts.pory"
	applymovement 36, Common_Movement_ExclamationMark
# 475 "data/maps/Route104/scripts.pory"
	applymovement 34, Common_Movement_ExclamationMark
# 476 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 477 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 478 "data/maps/Route104/scripts.pory"
	delay 40
# 479 "data/maps/Route104/scripts.pory"
	waitse
# 480 "data/maps/Route104/scripts.pory"
	closemessage
# 481 "data/maps/Route104/scripts.pory"
	addobject 35
# 482 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2RunToCatchUp
# 483 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 484 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 485 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 486 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 10
# 487 "data/maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 488 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 489 "data/maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 490 "data/maps/Route104/scripts.pory"
	setobjectsubpriority 34, MAP_ROUTE104, 0
# 491 "data/maps/Route104/scripts.pory"
	setobjectsubpriority 35, MAP_ROUTE104, 0
# 492 "data/maps/Route104/scripts.pory"
	setobjectsubpriority 36, MAP_ROUTE104, 0
# 493 "data/maps/Route104/scripts.pory"
	applymovement 8, Route104_Movement_BrineyBoardShipAfterInterrupted
# 494 "data/maps/Route104/scripts.pory"
	applymovement 36, Route104_Movement_PeekoBoardShipAfterInterrupted
# 495 "data/maps/Route104/scripts.pory"
	applymovement 34, Route104_Movement_Rival1BoardShipAfterInterrupted
# 496 "data/maps/Route104/scripts.pory"
	applymovement 35, Route104_Movement_Rival2BoardShipAfterInterrupted
# 497 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardShipAfterInterrupted
# 498 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 499 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 500 "data/maps/Route104/scripts.pory"
	removeobject 36
# 501 "data/maps/Route104/scripts.pory"
	removeobject 34
# 502 "data/maps/Route104/scripts.pory"
	removeobject 35
# 503 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_RIVAL1
# 504 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_OUTDOOR_DEWFORD_RIVALS
# 505 "data/maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 506 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewfordDadCalls
	end


# 510 "data/maps/Route104/scripts.pory"
Route104_Movement_WaitForRival2:
# 511 "data/maps/Route104/scripts.pory"
	delay_16
# 511 "data/maps/Route104/scripts.pory"
	delay_16
# 512 "data/maps/Route104/scripts.pory"
	face_right
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 513 "data/maps/Route104/scripts.pory"
	delay_16
# 514 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_down
	step_end

# 517 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerWaitForRival2:
# 518 "data/maps/Route104/scripts.pory"
	delay_16
# 518 "data/maps/Route104/scripts.pory"
	delay_16
# 518 "data/maps/Route104/scripts.pory"
	delay_16
# 519 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 522 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerReturnFromWait:
# 523 "data/maps/Route104/scripts.pory"
	delay_4
# 524 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_up
	step_end

# 527 "data/maps/Route104/scripts.pory"
Route104_Movement_StepOutOfBrineysWay:
# 528 "data/maps/Route104/scripts.pory"
	face_left
# 529 "data/maps/Route104/scripts.pory"
	lock_facing_direction
# 530 "data/maps/Route104/scripts.pory"
	walk_right
# 531 "data/maps/Route104/scripts.pory"
	unlock_facing_direction
	step_end

# 534 "data/maps/Route104/scripts.pory"
Route104_Movement_StepOutOfCottage:
# 535 "data/maps/Route104/scripts.pory"
	delay_4
# 536 "data/maps/Route104/scripts.pory"
	walk_down
	step_end

# 539 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1ShallWeWait:
# 540 "data/maps/Route104/scripts.pory"
	walk_down
# 541 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
	step_end

# 544 "data/maps/Route104/scripts.pory"
Route104_Movement_Player1ShallWeWait:
# 545 "data/maps/Route104/scripts.pory"
	delay_4
# 546 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_right
	step_end

# 549 "data/maps/Route104/scripts.pory"
Route104_Movement_EnterCottage:
# 550 "data/maps/Route104/scripts.pory"
	walk_up
# 551 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 554 "data/maps/Route104/scripts.pory"
Route104_Movement_GoWaitForOtherRival:
# 555 "data/maps/Route104/scripts.pory"
	walk_up
# 556 "data/maps/Route104/scripts.pory"
	face_down
	step_end

# 559 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2WalksIn:
# 560 "data/maps/Route104/scripts.pory"
	walk_down
# 560 "data/maps/Route104/scripts.pory"
	walk_down
# 560 "data/maps/Route104/scripts.pory"
	walk_down
	step_end

# 563 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2ApproachPlayer1:
# 564 "data/maps/Route104/scripts.pory"
	walk_down
# 564 "data/maps/Route104/scripts.pory"
	walk_down
# 564 "data/maps/Route104/scripts.pory"
	walk_down
# 565 "data/maps/Route104/scripts.pory"
	walk_left
# 565 "data/maps/Route104/scripts.pory"
	walk_left
	step_end

# 568 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2ApproachPlayer2:
# 569 "data/maps/Route104/scripts.pory"
	walk_down
# 569 "data/maps/Route104/scripts.pory"
	walk_down
# 570 "data/maps/Route104/scripts.pory"
	walk_left
# 570 "data/maps/Route104/scripts.pory"
	walk_left
	step_end

# 573 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2ApproachPlayer3:
# 574 "data/maps/Route104/scripts.pory"
	walk_down
# 575 "data/maps/Route104/scripts.pory"
	walk_left
# 575 "data/maps/Route104/scripts.pory"
	walk_left
	step_end

# 578 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForApproach2:
# 579 "data/maps/Route104/scripts.pory"
	walk_up
# 580 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 583 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForApproach3:
# 584 "data/maps/Route104/scripts.pory"
	walk_up
# 584 "data/maps/Route104/scripts.pory"
	walk_up
# 585 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 588 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1Approach:
# 589 "data/maps/Route104/scripts.pory"
	walk_right
# 590 "data/maps/Route104/scripts.pory"
	walk_down
# 591 "data/maps/Route104/scripts.pory"
	walk_right
	step_end

# 594 "data/maps/Route104/scripts.pory"
Route104_Movement_ApproachRival1:
# 595 "data/maps/Route104/scripts.pory"
	walk_down
# 596 "data/maps/Route104/scripts.pory"
	face_left
	step_end

# 599 "data/maps/Route104/scripts.pory"
Route104_Movement_GoTellBriney:
# 600 "data/maps/Route104/scripts.pory"
	walk_left
# 600 "data/maps/Route104/scripts.pory"
	walk_left
# 600 "data/maps/Route104/scripts.pory"
	walk_left
# 601 "data/maps/Route104/scripts.pory"
	walk_up
	step_end

# 604 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1ComesBackOutOfCottage:
# 605 "data/maps/Route104/scripts.pory"
	face_down
# 606 "data/maps/Route104/scripts.pory"
	set_visible
# 607 "data/maps/Route104/scripts.pory"
	delay_4
# 608 "data/maps/Route104/scripts.pory"
	walk_down
# 609 "data/maps/Route104/scripts.pory"
	walk_right
# 610 "data/maps/Route104/scripts.pory"
	face_left
	step_end

# 613 "data/maps/Route104/scripts.pory"
Route104_Movement_JoinBoatCrew:
# 614 "data/maps/Route104/scripts.pory"
	walk_left
# 615 "data/maps/Route104/scripts.pory"
	walk_up
# 616 "data/maps/Route104/scripts.pory"
	face_left
	step_end

# 619 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardShip:
# 620 "data/maps/Route104/scripts.pory"
	walk_left
# 620 "data/maps/Route104/scripts.pory"
	walk_left
# 620 "data/maps/Route104/scripts.pory"
	walk_left
# 620 "data/maps/Route104/scripts.pory"
	walk_left
# 621 "data/maps/Route104/scripts.pory"
	walk_down
# 621 "data/maps/Route104/scripts.pory"
	walk_down
# 622 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 625 "data/maps/Route104/scripts.pory"
Route104_Movement_PeekoBoardShip:
# 626 "data/maps/Route104/scripts.pory"
	walk_left
# 626 "data/maps/Route104/scripts.pory"
	walk_left
# 626 "data/maps/Route104/scripts.pory"
	walk_left
# 626 "data/maps/Route104/scripts.pory"
	walk_left
# 626 "data/maps/Route104/scripts.pory"
	walk_left
# 627 "data/maps/Route104/scripts.pory"
	walk_down
# 627 "data/maps/Route104/scripts.pory"
	walk_down
# 628 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 631 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1BoardShip:
# 632 "data/maps/Route104/scripts.pory"
	walk_left
# 632 "data/maps/Route104/scripts.pory"
	walk_left
# 632 "data/maps/Route104/scripts.pory"
	walk_left
# 632 "data/maps/Route104/scripts.pory"
	walk_left
# 632 "data/maps/Route104/scripts.pory"
	walk_left
# 632 "data/maps/Route104/scripts.pory"
	walk_left
# 633 "data/maps/Route104/scripts.pory"
	walk_down
# 633 "data/maps/Route104/scripts.pory"
	walk_down
# 634 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 637 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2BoardShip:
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 638 "data/maps/Route104/scripts.pory"
	walk_left
# 639 "data/maps/Route104/scripts.pory"
	walk_down
# 639 "data/maps/Route104/scripts.pory"
	walk_down
# 640 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 643 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardShip:
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 644 "data/maps/Route104/scripts.pory"
	walk_left
# 645 "data/maps/Route104/scripts.pory"
	walk_down
# 645 "data/maps/Route104/scripts.pory"
	walk_down
# 646 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 649 "data/maps/Route104/scripts.pory"
Route104_Movement_WalkToBoatInterrupted:
# 650 "data/maps/Route104/scripts.pory"
	walk_left
# 650 "data/maps/Route104/scripts.pory"
	walk_left
	step_end

# 653 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2RunToCatchUp:
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 654 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 655 "data/maps/Route104/scripts.pory"
	walk_fast_left
# 655 "data/maps/Route104/scripts.pory"
	walk_fast_left
# 655 "data/maps/Route104/scripts.pory"
	walk_fast_left
# 655 "data/maps/Route104/scripts.pory"
	walk_fast_left
# 655 "data/maps/Route104/scripts.pory"
	walk_fast_left
# 655 "data/maps/Route104/scripts.pory"
	walk_fast_left
	step_end

# 658 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardShipAfterInterrupted:
# 659 "data/maps/Route104/scripts.pory"
	walk_left
# 659 "data/maps/Route104/scripts.pory"
	walk_left
# 660 "data/maps/Route104/scripts.pory"
	walk_down
# 660 "data/maps/Route104/scripts.pory"
	walk_down
# 661 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 664 "data/maps/Route104/scripts.pory"
Route104_Movement_PeekoBoardShipAfterInterrupted:
# 665 "data/maps/Route104/scripts.pory"
	walk_left
# 665 "data/maps/Route104/scripts.pory"
	walk_left
# 665 "data/maps/Route104/scripts.pory"
	walk_left
# 666 "data/maps/Route104/scripts.pory"
	walk_down
# 666 "data/maps/Route104/scripts.pory"
	walk_down
# 667 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 670 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1BoardShipAfterInterrupted:
# 671 "data/maps/Route104/scripts.pory"
	walk_left
# 671 "data/maps/Route104/scripts.pory"
	walk_left
# 671 "data/maps/Route104/scripts.pory"
	walk_left
# 671 "data/maps/Route104/scripts.pory"
	walk_left
# 672 "data/maps/Route104/scripts.pory"
	walk_down
# 672 "data/maps/Route104/scripts.pory"
	walk_down
# 673 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 676 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2BoardShipAfterInterrupted:
# 677 "data/maps/Route104/scripts.pory"
	walk_left
# 677 "data/maps/Route104/scripts.pory"
	walk_left
# 677 "data/maps/Route104/scripts.pory"
	walk_left
# 677 "data/maps/Route104/scripts.pory"
	walk_left
# 677 "data/maps/Route104/scripts.pory"
	walk_left
# 678 "data/maps/Route104/scripts.pory"
	walk_down
# 678 "data/maps/Route104/scripts.pory"
	walk_down
# 679 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 682 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardShipAfterInterrupted:
# 683 "data/maps/Route104/scripts.pory"
	walk_up
# 684 "data/maps/Route104/scripts.pory"
	walk_left
# 684 "data/maps/Route104/scripts.pory"
	walk_left
# 684 "data/maps/Route104/scripts.pory"
	walk_left
# 684 "data/maps/Route104/scripts.pory"
	walk_left
# 684 "data/maps/Route104/scripts.pory"
	walk_left
# 685 "data/maps/Route104/scripts.pory"
	walk_down
# 685 "data/maps/Route104/scripts.pory"
	walk_down
# 686 "data/maps/Route104/scripts.pory"
	set_invisible
	step_end

# 750 "data/maps/Route104/scripts.pory"

# 751 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 752 "data/maps/Route104/scripts.pory"
	face_up
# 753 "data/maps/Route104/scripts.pory"
	lock_facing_direction
# 754 "data/maps/Route104/scripts.pory"
	walk_down
# 755 "data/maps/Route104/scripts.pory"
	unlock_facing_direction
# 756 "data/maps/Route104/scripts.pory"
	step_end
# 757 "data/maps/Route104/scripts.pory"

# 758 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 759 "data/maps/Route104/scripts.pory"
	walk_down
# 760 "data/maps/Route104/scripts.pory"
	step_end
# 761 "data/maps/Route104/scripts.pory"

# 762 "data/maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 763 "data/maps/Route104/scripts.pory"
	lock
# 764 "data/maps/Route104/scripts.pory"
	faceplayer
# 765 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 766 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 767 "data/maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 768 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 769 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 770 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 771 "data/maps/Route104/scripts.pory"
	release
# 772 "data/maps/Route104/scripts.pory"
	end
# 773 "data/maps/Route104/scripts.pory"

# 774 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 775 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 776 "data/maps/Route104/scripts.pory"
	release
# 777 "data/maps/Route104/scripts.pory"
	end
# 778 "data/maps/Route104/scripts.pory"

# 779 "data/maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 780 "data/maps/Route104/scripts.pory"
	lock
# 781 "data/maps/Route104/scripts.pory"
	faceplayer
# 782 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 783 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 784 "data/maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 785 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 786 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 787 "data/maps/Route104/scripts.pory"
	release
# 788 "data/maps/Route104/scripts.pory"
	end
# 789 "data/maps/Route104/scripts.pory"

# 790 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 791 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 792 "data/maps/Route104/scripts.pory"
	release
# 793 "data/maps/Route104/scripts.pory"
	end
# 794 "data/maps/Route104/scripts.pory"

# 795 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl1::
# 796 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
# 797 "data/maps/Route104/scripts.pory"
	end
# 798 "data/maps/Route104/scripts.pory"

# 799 "data/maps/Route104/scripts.pory"
Route104_EventScript_BugCatcher::
# 800 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
# 801 "data/maps/Route104/scripts.pory"
	end
# 802 "data/maps/Route104/scripts.pory"

# 803 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 804 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 805 "data/maps/Route104/scripts.pory"
	end
# 806 "data/maps/Route104/scripts.pory"

# 807 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 808 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 809 "data/maps/Route104/scripts.pory"
	end
# 810 "data/maps/Route104/scripts.pory"

# 811 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 812 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 813 "data/maps/Route104/scripts.pory"
	end
# 814 "data/maps/Route104/scripts.pory"

# 815 "data/maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 816 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 817 "data/maps/Route104/scripts.pory"
	end
# 818 "data/maps/Route104/scripts.pory"

# 819 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 820 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 821 "data/maps/Route104/scripts.pory"
	end
# 822 "data/maps/Route104/scripts.pory"

# 823 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy1::
# 824 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
# 825 "data/maps/Route104/scripts.pory"
	end
# 826 "data/maps/Route104/scripts.pory"

# 827 "data/maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 828 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 829 "data/maps/Route104/scripts.pory"
	end
# 830 "data/maps/Route104/scripts.pory"

# 831 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 832 "data/maps/Route104/scripts.pory"
	lock
# 833 "data/maps/Route104/scripts.pory"
	faceplayer
# 834 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 835 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 836 "data/maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED
# 837 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 838 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 839 "data/maps/Route104/scripts.pory"
	release
# 840 "data/maps/Route104/scripts.pory"
	end
# 841 "data/maps/Route104/scripts.pory"

# 842 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 843 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 844 "data/maps/Route104/scripts.pory"
	release
# 845 "data/maps/Route104/scripts.pory"
	end
# 846 "data/maps/Route104/scripts.pory"

# 847 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 848 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 849 "data/maps/Route104/scripts.pory"
	end
# 850 "data/maps/Route104/scripts.pory"

# 851 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 852 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 853 "data/maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 854 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
# 855 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 856 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 857 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
# 858 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 859 "data/maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 860 "data/maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 861 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
# 862 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
# 863 "data/maps/Route104/scripts.pory"
	end
# 864 "data/maps/Route104/scripts.pory"

# 865 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 866 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
# 867 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
# 868 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 869 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford

Route104_EventScript_SailToDewfordDadCalls::
# 873 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
# 874 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 875 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 876 "data/maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 877 "data/maps/Route104/scripts.pory"
	waitmessage
# 878 "data/maps/Route104/scripts.pory"
	delay 30
# 879 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 880 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 881 "data/maps/Route104/scripts.pory"
	waitfanfare
# 882 "data/maps/Route104/scripts.pory"
	closemessage
# 883 "data/maps/Route104/scripts.pory"
	delay 30
# 884 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 885 "data/maps/Route104/scripts.pory"
	compare VAR_0x800A, 2
	goto_if_ne Route104_EventScript_SailToDewfordDadCalls_2
Route104_EventScript_SailToDewfordDadCalls_1:
# 905 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 906 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 907 "data/maps/Route104/scripts.pory"
	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
# 908 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 909 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford2
	return

Route104_EventScript_SailToDewfordDadCalls_2:
# 886 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RivalBoatRegister
# 887 "data/maps/Route104/scripts.pory"
	waitmessage
# 888 "data/maps/Route104/scripts.pory"
	delay 30
# 889 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 890 "data/maps/Route104/scripts.pory"
	msgbox RustboroCity_Text_RegisteredRival2, MSGBOX_DEFAULT
# 891 "data/maps/Route104/scripts.pory"
	waitfanfare
# 892 "data/maps/Route104/scripts.pory"
	closemessage
# 893 "data/maps/Route104/scripts.pory"
	checkfriendchoice
# 894 "data/maps/Route104/scripts.pory"
	switch VAR_RESULT
# 895 "data/maps/Route104/scripts.pory"
	case SPENCER, Route104_EventScript_SailToDewfordDadCalls_6
# 897 "data/maps/Route104/scripts.pory"
	case BREN, Route104_EventScript_SailToDewfordDadCalls_7
# 899 "data/maps/Route104/scripts.pory"
	case KYLE, Route104_EventScript_SailToDewfordDadCalls_8
Route104_EventScript_SailToDewfordDadCalls_4:
# 902 "data/maps/Route104/scripts.pory"
	delay 30
# 903 "data/maps/Route104/scripts.pory"
	setvar VAR_0x800A, 0
	goto Route104_EventScript_SailToDewfordDadCalls_1

Route104_EventScript_SailToDewfordDadCalls_6:
# 896 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_KYLE_MATCH_CALL
	goto Route104_EventScript_SailToDewfordDadCalls_4

Route104_EventScript_SailToDewfordDadCalls_7:
# 898 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
	goto Route104_EventScript_SailToDewfordDadCalls_4

Route104_EventScript_SailToDewfordDadCalls_8:
# 900 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_BREN_MATCH_CALL
	goto Route104_EventScript_SailToDewfordDadCalls_4


# 918 "data/maps/Route104/scripts.pory"

# 919 "data/maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 920 "data/maps/Route104/scripts.pory"
	delay 50
# 921 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
# 922 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 923 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 924 "data/maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 925 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 926 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 927 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 928 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 929 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 930 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 931 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
# 932 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 933 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 934 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 935 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 936 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 937 "data/maps/Route104/scripts.pory"
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
# 938 "data/maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 939 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 940 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 941 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 942 "data/maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 943 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 944 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 945 "data/maps/Route104/scripts.pory"
	end

Route104_EventScript_ArriveInDewford2::
# 949 "data/maps/Route104/scripts.pory"
	delay 50
# 950 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL1_DEWFORD, 12, 8
# 951 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL2_DEWFORD, 12, 8
# 952 "data/maps/Route104/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL1_DEWFORD, MOVEMENT_TYPE_FACE_DOWN
# 953 "data/maps/Route104/scripts.pory"
	setobjectmovementtype LOCALID_RIVAL2_DEWFORD, MOVEMENT_TYPE_FACE_DOWN
# 954 "data/maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL1_DEWFORD
# 955 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_RIVAL1_DEWFORD, MAP_DEWFORD_TOWN, 0
# 956 "data/maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL2_DEWFORD
# 957 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_RIVAL2_DEWFORD, MAP_DEWFORD_TOWN, 0
# 958 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL1_DEWFORD, Route104_Movement_Rival1ExitBoat
# 959 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL2_DEWFORD, Route104_Movement_Rival2ExitBoat
# 960 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoatAfterRivals
# 961 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 962 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 963 "data/maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 964 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 965 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 966 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 967 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 968 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
# 969 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 970 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 971 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 972 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 973 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 974 "data/maps/Route104/scripts.pory"
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
# 975 "data/maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 976 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 977 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 978 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_RIVAL1_DEWFORD, MAP_DEWFORD_TOWN
# 979 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_RIVAL2_DEWFORD, MAP_DEWFORD_TOWN
# 980 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 981 "data/maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 982 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 983 "data/maps/Route104/scripts.pory"
	closemessage
# 984 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 985 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL2_DEWFORD, Common_Movement_BeginTalkRight
# 986 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 987 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WeShouldSplitUp, MSGBOX_DEFAULT
# 988 "data/maps/Route104/scripts.pory"
	closemessage
# 989 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL1_DEWFORD, Route104_Movement_Rival1LeavesAfterBoat
# 990 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL2_DEWFORD, Route104_Movement_Rival2LeavesAfterBoat
# 991 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 992 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_RIVAL1_DEWFORD
# 993 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_RIVAL2_DEWFORD
# 994 "data/maps/Route104/scripts.pory"
	setflag FLAG_MR_BRINEY_SAILING_INTRO
# 995 "data/maps/Route104/scripts.pory"
	delay 20
# 996 "data/maps/Route104/scripts.pory"
	releaseall
	end


Route104_EventScript_EndOfDemo::
# 1001 "data/maps/Route104/scripts.pory"
	lock
# 1002 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_EndOfDemo, MSGBOX_DEFAULT
# 1003 "data/maps/Route104/scripts.pory"
	closemessage
# 1004 "data/maps/Route104/scripts.pory"
	release
	end


# 1008 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1ExitBoat:
# 1009 "data/maps/Route104/scripts.pory"
	walk_down
# 1010 "data/maps/Route104/scripts.pory"
	walk_left
# 1010 "data/maps/Route104/scripts.pory"
	walk_left
# 1010 "data/maps/Route104/scripts.pory"
	walk_left
# 1011 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 1014 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2ExitBoat:
# 1015 "data/maps/Route104/scripts.pory"
	walk_in_place_down
# 1016 "data/maps/Route104/scripts.pory"
	walk_down
# 1017 "data/maps/Route104/scripts.pory"
	walk_left
# 1017 "data/maps/Route104/scripts.pory"
	walk_left
# 1018 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 1021 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoatAfterRivals:
# 1022 "data/maps/Route104/scripts.pory"
	walk_down
# 1023 "data/maps/Route104/scripts.pory"
	set_visible
# 1024 "data/maps/Route104/scripts.pory"
	delay_4
# 1024 "data/maps/Route104/scripts.pory"
	delay_4
# 1024 "data/maps/Route104/scripts.pory"
	delay_4
# 1025 "data/maps/Route104/scripts.pory"
	delay_2
# 1026 "data/maps/Route104/scripts.pory"
	walk_down
# 1027 "data/maps/Route104/scripts.pory"
	walk_left
# 1028 "data/maps/Route104/scripts.pory"
	face_right
	step_end

# 1031 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival1LeavesAfterBoat:
# 1032 "data/maps/Route104/scripts.pory"
	walk_left
# 1032 "data/maps/Route104/scripts.pory"
	walk_left
# 1032 "data/maps/Route104/scripts.pory"
	walk_left
# 1033 "data/maps/Route104/scripts.pory"
	walk_down
# 1033 "data/maps/Route104/scripts.pory"
	walk_down
# 1034 "data/maps/Route104/scripts.pory"
	walk_left
# 1034 "data/maps/Route104/scripts.pory"
	walk_left
# 1035 "data/maps/Route104/scripts.pory"
	walk_down
# 1035 "data/maps/Route104/scripts.pory"
	walk_down
# 1035 "data/maps/Route104/scripts.pory"
	walk_down
# 1035 "data/maps/Route104/scripts.pory"
	walk_down
# 1035 "data/maps/Route104/scripts.pory"
	walk_down
	step_end

# 1038 "data/maps/Route104/scripts.pory"
Route104_Movement_Rival2LeavesAfterBoat:
# 1039 "data/maps/Route104/scripts.pory"
	walk_left
# 1039 "data/maps/Route104/scripts.pory"
	walk_left
# 1039 "data/maps/Route104/scripts.pory"
	walk_left
# 1039 "data/maps/Route104/scripts.pory"
	walk_left
# 1040 "data/maps/Route104/scripts.pory"
	walk_up
# 1040 "data/maps/Route104/scripts.pory"
	walk_up
# 1040 "data/maps/Route104/scripts.pory"
	walk_up
# 1040 "data/maps/Route104/scripts.pory"
	walk_up
# 1041 "data/maps/Route104/scripts.pory"
	walk_left
# 1041 "data/maps/Route104/scripts.pory"
	walk_left
# 1041 "data/maps/Route104/scripts.pory"
	walk_left
# 1041 "data/maps/Route104/scripts.pory"
	walk_left
	step_end

# 1054 "data/maps/Route104/scripts.pory"

# 1055 "data/maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 1056 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 1057 "data/maps/Route104/scripts.pory"
	releaseall
# 1058 "data/maps/Route104/scripts.pory"
	end
# 1059 "data/maps/Route104/scripts.pory"

# 1060 "data/maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 1061 "data/maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 1062 "data/maps/Route104/scripts.pory"
	releaseall
# 1063 "data/maps/Route104/scripts.pory"
	end
# 1064 "data/maps/Route104/scripts.pory"

# 1065 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 1066 "data/maps/Route104/scripts.pory"
	walk_down
# 1067 "data/maps/Route104/scripts.pory"
	walk_down
# 1068 "data/maps/Route104/scripts.pory"
	walk_down
# 1069 "data/maps/Route104/scripts.pory"
	walk_down
# 1070 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1071 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1072 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1073 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1074 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1075 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1076 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1077 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1078 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1079 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1080 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1081 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1082 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1083 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1084 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1085 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1086 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1087 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1088 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1089 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1090 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1091 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1092 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1093 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1094 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1095 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1096 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1097 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1098 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1099 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1100 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1101 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1102 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1103 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1104 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1105 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1106 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1107 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1108 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1109 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1110 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1111 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1112 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1113 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1114 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1115 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1116 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1117 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1118 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1119 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1120 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1121 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1122 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1123 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1124 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1125 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1126 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1127 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1128 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1129 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1130 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1131 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1132 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1133 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1134 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1135 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1136 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1137 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1138 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1139 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1140 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1141 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1142 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1143 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1144 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1145 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1146 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1147 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1148 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1149 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1150 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1151 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1152 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1153 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1154 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1155 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1156 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1157 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1158 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1159 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1160 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1161 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1162 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1163 "data/maps/Route104/scripts.pory"
	step_end
# 1164 "data/maps/Route104/scripts.pory"

# 1165 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 1166 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1167 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1168 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1169 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1170 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1171 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1172 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1173 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1174 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1175 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1176 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1177 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1178 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1179 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1180 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1181 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1182 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1183 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1184 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1185 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1186 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1187 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1188 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1189 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1190 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1191 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1192 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1193 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1194 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1195 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1196 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1197 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1198 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1199 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1200 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1201 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1202 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1203 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1204 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1205 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1206 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1207 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1208 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1209 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1210 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1211 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1212 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1213 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1214 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1215 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1216 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1217 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1218 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1219 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1220 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1221 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1222 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1223 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1224 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1225 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1226 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1227 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1228 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1229 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1230 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1231 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1232 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1233 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1234 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1235 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1236 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1237 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1238 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1239 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1240 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1241 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1242 "data/maps/Route104/scripts.pory"
	walk_right
# 1243 "data/maps/Route104/scripts.pory"
	walk_right
# 1244 "data/maps/Route104/scripts.pory"
	walk_down
# 1245 "data/maps/Route104/scripts.pory"
	walk_down
# 1246 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1247 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1248 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1249 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1250 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1251 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1252 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1253 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1254 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1255 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1256 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1257 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1258 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1259 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1260 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1261 "data/maps/Route104/scripts.pory"
	walk_down
# 1262 "data/maps/Route104/scripts.pory"
	walk_down
# 1263 "data/maps/Route104/scripts.pory"
	step_end
# 1264 "data/maps/Route104/scripts.pory"

# 1265 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 1266 "data/maps/Route104/scripts.pory"
	walk_down
# 1267 "data/maps/Route104/scripts.pory"
	walk_down
# 1268 "data/maps/Route104/scripts.pory"
	walk_down
# 1269 "data/maps/Route104/scripts.pory"
	walk_down
# 1270 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1271 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1272 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1273 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1274 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1275 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1276 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1277 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1278 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1279 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1280 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1281 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1282 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1283 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1284 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1285 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1286 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1287 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1288 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1289 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1290 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1291 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1292 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1293 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1294 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1295 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1296 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1297 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1298 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1299 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1300 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1301 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1302 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1303 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1304 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1305 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1306 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1307 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1308 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1309 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1310 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1311 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1312 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1313 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1314 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1315 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1316 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1317 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1318 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1319 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1320 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1321 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1322 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1323 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1324 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1325 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1326 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1327 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1328 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1329 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1330 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1331 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1332 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1333 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1334 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1335 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1336 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1337 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1338 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1339 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1340 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1341 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1342 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1343 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1344 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1345 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1346 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1347 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1348 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1349 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1350 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1351 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1352 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1353 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1354 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1355 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1356 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1357 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1358 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1359 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1360 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1361 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1362 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1363 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1364 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1365 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1366 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1367 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1368 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1369 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1370 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1371 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1372 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1373 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1374 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1375 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1376 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1377 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1378 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1379 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1380 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1381 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1382 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1383 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1384 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1385 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1386 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 1387 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1388 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1389 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1390 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1391 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1392 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1393 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1394 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1395 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1396 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1397 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1398 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1399 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1400 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1401 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1402 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1403 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1404 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1405 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1406 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1407 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1408 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1409 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1410 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1411 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1412 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1413 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1414 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1415 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1416 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1417 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1418 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1419 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1420 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1421 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1422 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1423 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1424 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1425 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1426 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1427 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1428 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1429 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1430 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1431 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1432 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1433 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1434 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 1435 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1436 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1437 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1438 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 1439 "data/maps/Route104/scripts.pory"
	walk_right
# 1440 "data/maps/Route104/scripts.pory"
	walk_right
# 1441 "data/maps/Route104/scripts.pory"
	walk_down
# 1442 "data/maps/Route104/scripts.pory"
	walk_down
# 1443 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1444 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1445 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1446 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1447 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1448 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1449 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1450 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1451 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1452 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1453 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1454 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1455 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1456 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1457 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 1458 "data/maps/Route104/scripts.pory"
	walk_down
# 1459 "data/maps/Route104/scripts.pory"
	walk_down
# 1460 "data/maps/Route104/scripts.pory"
	step_end
# 1461 "data/maps/Route104/scripts.pory"

# 1462 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 1463 "data/maps/Route104/scripts.pory"
	walk_left
# 1464 "data/maps/Route104/scripts.pory"
	walk_down
# 1465 "data/maps/Route104/scripts.pory"
	walk_down
# 1466 "data/maps/Route104/scripts.pory"
	step_end
# 1467 "data/maps/Route104/scripts.pory"

# 1468 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 1469 "data/maps/Route104/scripts.pory"
	walk_down
# 1470 "data/maps/Route104/scripts.pory"
	step_end
# 1471 "data/maps/Route104/scripts.pory"

# 1472 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 1473 "data/maps/Route104/scripts.pory"
	walk_down
# 1474 "data/maps/Route104/scripts.pory"
	walk_left
# 1475 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 1476 "data/maps/Route104/scripts.pory"
	step_end
# 1477 "data/maps/Route104/scripts.pory"

# 1478 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 1479 "data/maps/Route104/scripts.pory"
	walk_down
# 1480 "data/maps/Route104/scripts.pory"
	walk_down
# 1481 "data/maps/Route104/scripts.pory"
	step_end
# 1482 "data/maps/Route104/scripts.pory"

# 1483 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 1484 "data/maps/Route104/scripts.pory"
	walk_down
# 1485 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 1486 "data/maps/Route104/scripts.pory"
	step_end
# 1487 "data/maps/Route104/scripts.pory"

# 1488 "data/maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 1489 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
# 1490 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 1491 "data/maps/Route104/scripts.pory"
	end
# 1492 "data/maps/Route104/scripts.pory"

# 1493 "data/maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 1494 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
# 1495 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 1496 "data/maps/Route104/scripts.pory"
	end
# 1497 "data/maps/Route104/scripts.pory"

# 1498 "data/maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 1499 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
# 1500 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 1501 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
# 1502 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_HALEY_1
# 1503 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 1504 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
# 1505 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 1506 "data/maps/Route104/scripts.pory"
	release
# 1507 "data/maps/Route104/scripts.pory"
	end
# 1508 "data/maps/Route104/scripts.pory"

# 1509 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 1510 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1511 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 1512 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 1513 "data/maps/Route104/scripts.pory"
	release
# 1514 "data/maps/Route104/scripts.pory"
	end
# 1515 "data/maps/Route104/scripts.pory"

# 1516 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 1517 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 1518 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 1519 "data/maps/Route104/scripts.pory"
	release
# 1520 "data/maps/Route104/scripts.pory"
	end
# 1521 "data/maps/Route104/scripts.pory"

# 1522 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 1523 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 1524 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 1525 "data/maps/Route104/scripts.pory"
	release
# 1526 "data/maps/Route104/scripts.pory"
	end
# 1527 "data/maps/Route104/scripts.pory"

# 1528 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 1529 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 1530 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 1531 "data/maps/Route104/scripts.pory"
	release
# 1532 "data/maps/Route104/scripts.pory"
	end
# 1533 "data/maps/Route104/scripts.pory"

# 1534 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 1535 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 1536 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 1537 "data/maps/Route104/scripts.pory"
	end
# 1538 "data/maps/Route104/scripts.pory"

# 1539 "data/maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 1540 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
# 1541 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 1542 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
# 1543 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_WINSTON_1
# 1544 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 1545 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
# 1546 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 1547 "data/maps/Route104/scripts.pory"
	release
# 1548 "data/maps/Route104/scripts.pory"
	end
# 1549 "data/maps/Route104/scripts.pory"

# 1550 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 1551 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1552 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 1553 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 1554 "data/maps/Route104/scripts.pory"
	release
# 1555 "data/maps/Route104/scripts.pory"
	end
# 1556 "data/maps/Route104/scripts.pory"

# 1557 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 1558 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 1559 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 1560 "data/maps/Route104/scripts.pory"
	release
# 1561 "data/maps/Route104/scripts.pory"
	end
# 1562 "data/maps/Route104/scripts.pory"

# 1563 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 1564 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 1565 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 1566 "data/maps/Route104/scripts.pory"
	release
# 1567 "data/maps/Route104/scripts.pory"
	end
# 1568 "data/maps/Route104/scripts.pory"

# 1569 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 1570 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 1571 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 1572 "data/maps/Route104/scripts.pory"
	release
# 1573 "data/maps/Route104/scripts.pory"
	end
# 1574 "data/maps/Route104/scripts.pory"

# 1575 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 1576 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 1577 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 1578 "data/maps/Route104/scripts.pory"
	end
# 1579 "data/maps/Route104/scripts.pory"

# 1580 "data/maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 1581 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_EventScript_TryRegisterCindyAfterBattle
# 1582 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 1583 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
# 1584 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_CINDY_1
# 1585 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 1586 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
# 1587 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1588 "data/maps/Route104/scripts.pory"
	release
# 1589 "data/maps/Route104/scripts.pory"
	end
# 1590 "data/maps/Route104/scripts.pory"

# 1591 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 1592 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 1593 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 1594 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 1595 "data/maps/Route104/scripts.pory"
	release
# 1596 "data/maps/Route104/scripts.pory"
	end
# 1597 "data/maps/Route104/scripts.pory"

# 1598 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 1599 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 1600 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1601 "data/maps/Route104/scripts.pory"
	release
# 1602 "data/maps/Route104/scripts.pory"
	end
# 1603 "data/maps/Route104/scripts.pory"

# 1604 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 1605 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 1606 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 1607 "data/maps/Route104/scripts.pory"
	release
# 1608 "data/maps/Route104/scripts.pory"
	end
# 1609 "data/maps/Route104/scripts.pory"

# 1610 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 1611 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 1612 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1613 "data/maps/Route104/scripts.pory"
	release
# 1614 "data/maps/Route104/scripts.pory"
	end
# 1615 "data/maps/Route104/scripts.pory"

# 1616 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 1617 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 1618 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 1619 "data/maps/Route104/scripts.pory"
	end
# 1620 "data/maps/Route104/scripts.pory"

# 1621 "data/maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 1622 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
# 1623 "data/maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1624 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 1625 "data/maps/Route104/scripts.pory"
	release
# 1626 "data/maps/Route104/scripts.pory"
	end
# 1627 "data/maps/Route104/scripts.pory"

# 1628 "data/maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 1629 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
# 1630 "data/maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1631 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 1632 "data/maps/Route104/scripts.pory"
	release
# 1633 "data/maps/Route104/scripts.pory"
	end
# 1634 "data/maps/Route104/scripts.pory"

# 1635 "data/maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 1636 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
# 1637 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 1638 "data/maps/Route104/scripts.pory"
	end
# 1639 "data/maps/Route104/scripts.pory"

# 1640 "data/maps/Route104/scripts.pory"
Route104_Text_BrineyLivesInSeasideCottage:
# 1641 "data/maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
# 1642 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY lives.\p"
# 1643 "data/maps/Route104/scripts.pory"
	.string "He was once a mighty sailor who never\n"
# 1644 "data/maps/Route104/scripts.pory"
	.string "feared the sea, however stormy.$"
# 1645 "data/maps/Route104/scripts.pory"

# 1646 "data/maps/Route104/scripts.pory"
Route104_Text_WhatsItLikeAtBottomOfSea:
# 1647 "data/maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
# 1648 "data/maps/Route104/scripts.pory"
	.string "I wonder what it's like at the bottom\n"
# 1649 "data/maps/Route104/scripts.pory"
	.string "of the sea?$"
# 1650 "data/maps/Route104/scripts.pory"

# 1651 "data/maps/Route104/scripts.pory"
Route104_Text_ThrowBallAtWeakenedPokemon:
# 1652 "data/maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
# 1653 "data/maps/Route104/scripts.pory"
	.string "weaken the wild POKéMON first.\p"
# 1654 "data/maps/Route104/scripts.pory"
	.string "It will be easier to catch if it's been\n"
# 1655 "data/maps/Route104/scripts.pory"
	.string "poisoned, burned, or lulled to sleep.$"
# 1656 "data/maps/Route104/scripts.pory"

# 1657 "data/maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 1658 "data/maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 1659 "data/maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 1660 "data/maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 1661 "data/maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 1662 "data/maps/Route104/scripts.pory"

# 1663 "data/maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 1664 "data/maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 1665 "data/maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1666 "data/maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1667 "data/maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1668 "data/maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1669 "data/maps/Route104/scripts.pory"

# 1670 "data/maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1671 "data/maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1672 "data/maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1673 "data/maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1674 "data/maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1675 "data/maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1676 "data/maps/Route104/scripts.pory"

# 1677 "data/maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1678 "data/maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1679 "data/maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1680 "data/maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1681 "data/maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1682 "data/maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1683 "data/maps/Route104/scripts.pory"

# 1684 "data/maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1685 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1686 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1687 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1688 "data/maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1689 "data/maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1690 "data/maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1691 "data/maps/Route104/scripts.pory"

# 1692 "data/maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1693 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1694 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1695 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1696 "data/maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1697 "data/maps/Route104/scripts.pory"

# 1698 "data/maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1699 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1700 "data/maps/Route104/scripts.pory"

# 1701 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1702 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1703 "data/maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1704 "data/maps/Route104/scripts.pory"

# 1705 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1706 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1707 "data/maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1708 "data/maps/Route104/scripts.pory"

# 1709 "data/maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1710 "data/maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1711 "data/maps/Route104/scripts.pory"

# 1712 "data/maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1713 "data/maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1714 "data/maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1715 "data/maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1716 "data/maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1717 "data/maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1718 "data/maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1719 "data/maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1720 "data/maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1721 "data/maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"

Route104_Text_WhatsItLikeToSurf::
# 102 "data/maps/Route104/scripts.pory"
	.string "Wouldn't it be awesome to ride a\n"
	.string "POKéMON over the water?$"

Route104_Text_WhatsAcrossTheSea::
# 106 "data/maps/Route104/scripts.pory"
	.string "I wonder what's out there beyond the\n"
	.string "sea…$"

Route104_Text_NotTheWayToRustboro::
# 335 "data/maps/Route104/scripts.pory"
	.string "That's not the way to RUSTBORO!\n"
	.string "{RIVAL2} said he was going to the DEVON\l"
	.string "building.\l"
	.string "You should go look for him there.$"

Route104_Text_TakingALongTime::
# 689 "data/maps/Route104/scripts.pory"
	.string "{RIVAL}: {RIVAL2} sure is taking a long time…$"

Route104_Text_AreYouReadyToGo::
# 693 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY: Well now, boys.\n"
	.string "I'm all set to take a boat trip to\l"
	.string "DEWFORD.\l"
	.string "Are you ready to go?$"

Route104_Text_DoYouThinkWeShouldWait::
# 699 "data/maps/Route104/scripts.pory"
	.string "{RIVAL}: {RIVAL2} isn't here yet.\n"
	.string "Do you think we should wait for him?$"

Route104_Text_LetMeKnowWhenReadyToSail::
# 704 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY: I'm in no rush to shove off.\n"
	.string "You just let me know when you're ready\l"
	.string "to sail.$"

Route104_Text_SeeWhatsTakingSoLong::
# 709 "data/maps/Route104/scripts.pory"
	.string "{RIVAL}: Will you go see what's\n"
	.string "taking {RIVAL2} so long?\l"
	.string "I'll stay here in case he shows up.$"

Route104_Text_AfraidYouLeftWithoutMe::
# 714 "data/maps/Route104/scripts.pory"
	.string "{RIVAL2}: Boy, am I glad you're still here.\n"
	.string "I was afraid you guys left without me!$"

Route104_Text_IllGoLetBrineyKnow::
# 719 "data/maps/Route104/scripts.pory"
	.string "{RIVAL}: Good.\n"
	.string "Now that we're all here, we can make our\l"
	.string "way to DEWFORD. I'll go let BRINEY know\l"
	.string "we are ready to set sail!$"

Route104_Text_WeShouldRegister::
# 725 "data/maps/Route104/scripts.pory"
	.string "{RIVAL2}: Oh, hey look!\n"
	.string "I got a POKéNAV, too!\l"
	.string "We should register each other.$"

RustboroCity_Text_RegisteredRival2::
# 731 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered {RIVAL2}\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_AnchorsAweigh::
# 736 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!$"

RustboroCity_Text_PeekoSettingSail::
# 741 "data/maps/Route104/scripts.pory"
	.string "PEEKO, we're setting sail, my darling!$"

RustboroCity_Text_WaitForMe::
# 745 "data/maps/Route104/scripts.pory"
	.string "{RIVAL2}: Wait for me!\n"
	.string "I'm coming too!$"

Route104_Text_RivalBoatRegister::
# 912 "data/maps/Route104/scripts.pory"
	.string "{RIVAL2}: Oh, that reminds me, {PLAYER}!\n"
	.string "I got a POKéNAV from the DEVON\l"
	.string "PRESIDENT.\p"
	.string "We should register each other.$"

Route104_Text_WeShouldSplitUp::
# 1044 "data/maps/Route104/scripts.pory"
	.string "{RIVAL2}: We should split up and\n"
	.string "look around for this STEVEN guy.\l"
	.string "We have a letter to deliver!$"

Route104_Text_EndOfDemo::
# 1050 "data/maps/Route104/scripts.pory"
	.string "// END OF DEMO //$"

Route104_Text_BrineyStillPreparing::
# 1724 "data/maps/Route104/scripts.pory"
	.string "{RIVAL}: Oh, hey, {PLAYER}!\p"
	.string "I spoke to MR. BRINEY and he agreed to\n"
	.string "ferry us to DEWFORD.\p"
	.string "You say {RIVAL2} is coming with us?\n"
	.string "Awesome!\l"
	.string "He's got some time to catch up.\l"
	.string "BRINEY is still preparing for the trip.$"

Route104_Text_RegisteredBrendan::
# 1733 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
	.string "in the POKéNAV.$"

Route104_Text_Rival1HowsYourPokedex::
# 1738 "data/maps/Route104/scripts.pory"
	.string "{RIVAL}: {PLAYER}, how's your\n"
	.string "POKéDEX?\l"
	.string "Are you close to 50 species yet?\l"
	.string "I've barely been able to reach a dozen\l"
	.string "so far!\l"
	.string "Hopefully we'll find more different\l"
	.string "kinds around DEWFORD.\p"
	.string "Anyway…\n"
	.string "… … …\l"
	.string "$"

Route104_Text_BrendanDoingGreatLetsBattle::
# 1747 "data/maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
	.string "Want to check out how good I am with\n"
	.string "a battle?$"

Route104_Text_BrendanNoConfidence::
# 1753 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
	.string "any confidence in your POKéMON?$"

Route104_Text_BrendanLetsBattle::
# 1758 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
	.string "Want to have a battle with me?$"

Route104_Text_Rival1BattleIntro::
# 1763 "data/maps/Route104/scripts.pory"
	.string "Since we have some time to kill, why\n"
	.string "don't we battle?\l"
	.string "You can't say no to me this time!$"

Route104_Text_BrendanDefeat::
# 1768 "data/maps/Route104/scripts.pory"
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route104_Text_BrendanPostBattle::
# 1773 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
	.string "at handling POKéMON.\p"
	.string "But, you know, you shouldn't just be\n"
	.string "making POKéMON battle.\p"
	.string "Like MR. BRINEY, it's important to\n"
	.string "become friends with your POKéMON.$"
