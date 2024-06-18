# 6 "data/maps/Route116/scripts.pory"

# 7 "data/maps/Route116/scripts.pory"
.set LOCALID_BRINEY, 11
# 8 "data/maps/Route116/scripts.pory"
.set LOCALID_WANDAS_BF_OUTSIDE, 21
# 9 "data/maps/Route116/scripts.pory"
.set LOCALID_RIVAL2, 29
# 10 "data/maps/Route116/scripts.pory"
.set LOCALID_RIVAL1, 30
# 11 "data/maps/Route116/scripts.pory"

# 12 "data/maps/Route116/scripts.pory"
Route116_MapScripts::
# 13 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
# 14 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
# 15 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
# 16 "data/maps/Route116/scripts.pory"
	.byte 0
# 17 "data/maps/Route116/scripts.pory"

# 18 "data/maps/Route116/scripts.pory"
Route116_OnTransition:
# 19 "data/maps/Route116/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 20 "data/maps/Route116/scripts.pory"
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
# 21 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 22 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
# 23 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
# 24 "data/maps/Route116/scripts.pory"
	end

Route116_EventScript_SetWandasBoyfriendPos::
# 28 "data/maps/Route116/scripts.pory"
	setobjectxyperm 21, 38, 10
# 29 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq Route116_EventScript_SetWandasBoyfriendPos_2
# 29 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 5
	goto_if_eq Route116_EventScript_SetWandasBoyfriendPos_2
Route116_EventScript_SetWandasBoyfriendPos_1:
	return

Route116_EventScript_SetWandasBoyfriendPos_2:
# 30 "data/maps/Route116/scripts.pory"
	setobjectxyperm 30, 46, 9
# 31 "data/maps/Route116/scripts.pory"
	setobjectmovementtype 30, MOVEMENT_TYPE_FACE_DOWN
	goto Route116_EventScript_SetWandasBoyfriendPos_1


# 36 "data/maps/Route116/scripts.pory"

# 37 "data/maps/Route116/scripts.pory"
Route116_OnLoad:
# 38 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
# 39 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
# 40 "data/maps/Route116/scripts.pory"
	end
# 41 "data/maps/Route116/scripts.pory"

# 42 "data/maps/Route116/scripts.pory"
Route116_OnFrame:
# 43 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 44 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, Route116_EventScript_TalkToRivalAfterAquaBattle
# 45 "data/maps/Route116/scripts.pory"
	.2byte 0

Route116_EventScript_TalkToRivalAfterAquaBattle::
# 49 "data/maps/Route116/scripts.pory"
	lockall
# 50 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 5
# 51 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 52 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkRight
# 53 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 54 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WouldYouLikeToBattle, MSGBOX_YESNO
# 55 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 56 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_DeclineRivalBattleInitial
	end


Route116_EventScript_Rival1::
# 61 "data/maps/Route116/scripts.pory"
	lockall
# 62 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 63 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 64 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Rival1_3
# 66 "data/maps/Route116/scripts.pory"
	case 46, Route116_EventScript_Rival1_4
# 68 "data/maps/Route116/scripts.pory"
	case 47, Route116_EventScript_Rival1_5
Route116_EventScript_Rival1_1:
# 71 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_eq Route116_EventScript_Rival1_7
Route116_EventScript_Rival1_6:
# 76 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_Rival1, MSGBOX_DEFAULT
# 77 "data/maps/Route116/scripts.pory"
	closemessage
# 78 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 79 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_Rival1_3:
# 65 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_WEST
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_4:
# 67 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_SOUTH
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_5:
# 69 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_7:
# 72 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BattleAfterAll, MSGBOX_YESNO
# 73 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 74 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route116_EventScript_DeclineRivalBattle
	goto Route116_EventScript_Rival1_6


Route116_EventScript_RivalBattle::
# 84 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WontHoldAnythingBack
# 85 "data/maps/Route116/scripts.pory"
	checkfriendchoice
# 86 "data/maps/Route116/scripts.pory"
	switch VAR_RESULT
# 87 "data/maps/Route116/scripts.pory"
	case SPENCER, Route116_EventScript_RivalBattle_3
# 89 "data/maps/Route116/scripts.pory"
	case BREN, Route116_EventScript_RivalBattle_4
# 91 "data/maps/Route116/scripts.pory"
	case KYLE, Route116_EventScript_RivalBattle_5
Route116_EventScript_RivalBattle_1:
# 94 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MeetYouAtBrineysCottage, MSGBOX_DEFAULT
# 95 "data/maps/Route116/scripts.pory"
	closemessage
# 96 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 97 "data/maps/Route116/scripts.pory"
	compare VAR_0x8001, 46
	goto_if_eq Route116_EventScript_RivalBattle_7
# 101 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalLeaveAfterBattle
Route116_EventScript_RivalBattle_6:
# 103 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 104 "data/maps/Route116/scripts.pory"
	removeobject 30
# 105 "data/maps/Route116/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_RIVAL1
# 106 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
# 107 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_RivalBattle_3:
# 88 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_4:
# 90 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_5:
# 92 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_7:
# 98 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalLeaveAfterBattle2
	goto Route116_EventScript_RivalBattle_6


Route116_EventScript_DeclineRivalBattleInitial::
# 112 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_HangingAroundForABit, MSGBOX_DEFAULT
# 113 "data/maps/Route116/scripts.pory"
	releaseall
	end


Route116_EventScript_DeclineRivalBattle::
# 118 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_HangingAroundForABit2, MSGBOX_DEFAULT
# 119 "data/maps/Route116/scripts.pory"
	releaseall
	end


Route116_EventScript_Rival2::
# 124 "data/maps/Route116/scripts.pory"
	lock
# 125 "data/maps/Route116/scripts.pory"
	faceplayer
# 126 "data/maps/Route116/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route116_EventScript_Rival2_2
# 131 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ElusiveSkitty, MSGBOX_DEFAULT
Route116_EventScript_Rival2_1:
# 133 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Rival2_2:
# 127 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TakingABreak, MSGBOX_DEFAULT
# 128 "data/maps/Route116/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route116_EventScript_Rival2_1


# 137 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle:
# 138 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 138 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 139 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 140 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 143 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle2:
# 144 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 147 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 200 "data/maps/Route116/scripts.pory"

# 201 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 202 "data/maps/Route116/scripts.pory"
	lock
# 203 "data/maps/Route116/scripts.pory"
	faceplayer
# 204 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 205 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 206 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 207 "data/maps/Route116/scripts.pory"
	release
# 208 "data/maps/Route116/scripts.pory"
	end
# 209 "data/maps/Route116/scripts.pory"

# 210 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 211 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 212 "data/maps/Route116/scripts.pory"
	release
# 213 "data/maps/Route116/scripts.pory"
	end
# 214 "data/maps/Route116/scripts.pory"

# 215 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 216 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 217 "data/maps/Route116/scripts.pory"
	release
# 218 "data/maps/Route116/scripts.pory"
	end
# 219 "data/maps/Route116/scripts.pory"

# 220 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 221 "data/maps/Route116/scripts.pory"
	lock
# 222 "data/maps/Route116/scripts.pory"
	faceplayer
# 223 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 224 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 225 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 226 "data/maps/Route116/scripts.pory"
	end
# 227 "data/maps/Route116/scripts.pory"

# 228 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 229 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 230 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 231 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 232 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 233 "data/maps/Route116/scripts.pory"
	closemessage
# 234 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 235 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 236 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 237 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 238 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 239 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 240 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 241 "data/maps/Route116/scripts.pory"
	release
# 242 "data/maps/Route116/scripts.pory"
	end
# 243 "data/maps/Route116/scripts.pory"

# 244 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 245 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 246 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 247 "data/maps/Route116/scripts.pory"
	return
# 248 "data/maps/Route116/scripts.pory"

# 249 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 250 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 251 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 252 "data/maps/Route116/scripts.pory"
	return
# 253 "data/maps/Route116/scripts.pory"

# 254 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 255 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 256 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 257 "data/maps/Route116/scripts.pory"
	end
# 258 "data/maps/Route116/scripts.pory"

# 259 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 260 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 261 "data/maps/Route116/scripts.pory"
	release
# 262 "data/maps/Route116/scripts.pory"
	end
# 263 "data/maps/Route116/scripts.pory"

# 264 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 265 "data/maps/Route116/scripts.pory"
	walk_left
# 266 "data/maps/Route116/scripts.pory"
	walk_left
# 267 "data/maps/Route116/scripts.pory"
	walk_left
# 268 "data/maps/Route116/scripts.pory"
	walk_left
# 269 "data/maps/Route116/scripts.pory"
	walk_left
# 270 "data/maps/Route116/scripts.pory"
	walk_left
# 271 "data/maps/Route116/scripts.pory"
	walk_left
# 272 "data/maps/Route116/scripts.pory"
	walk_left
# 273 "data/maps/Route116/scripts.pory"
	step_end
# 274 "data/maps/Route116/scripts.pory"

# 275 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 276 "data/maps/Route116/scripts.pory"
	walk_down
# 277 "data/maps/Route116/scripts.pory"
	walk_left
# 278 "data/maps/Route116/scripts.pory"
	walk_left
# 279 "data/maps/Route116/scripts.pory"
	walk_left
# 280 "data/maps/Route116/scripts.pory"
	walk_left
# 281 "data/maps/Route116/scripts.pory"
	walk_left
# 282 "data/maps/Route116/scripts.pory"
	walk_left
# 283 "data/maps/Route116/scripts.pory"
	walk_left
# 284 "data/maps/Route116/scripts.pory"
	walk_left
# 285 "data/maps/Route116/scripts.pory"
	walk_left
# 286 "data/maps/Route116/scripts.pory"
	step_end
# 287 "data/maps/Route116/scripts.pory"

# 288 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 289 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 290 "data/maps/Route116/scripts.pory"
	end
# 291 "data/maps/Route116/scripts.pory"

# 292 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 293 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 294 "data/maps/Route116/scripts.pory"
	end
# 295 "data/maps/Route116/scripts.pory"

# 296 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 297 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 298 "data/maps/Route116/scripts.pory"
	end
# 299 "data/maps/Route116/scripts.pory"

# 300 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 301 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 302 "data/maps/Route116/scripts.pory"
	end
# 303 "data/maps/Route116/scripts.pory"

# 304 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 305 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 306 "data/maps/Route116/scripts.pory"
	end

Route116_EventScript_Briney::
# 310 "data/maps/Route116/scripts.pory"
	lock
# 311 "data/maps/Route116/scripts.pory"
	faceplayer
# 312 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BrineyStillMad, MSGBOX_DEFAULT
# 313 "data/maps/Route116/scripts.pory"
	closemessage
# 314 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 315 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 316 "data/maps/Route116/scripts.pory"
	case 44, Route116_EventScript_Briney_3
# 320 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Briney_4
Route116_EventScript_Briney_1:
# 325 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Briney_3:
# 317 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave1
# 318 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 319 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1

Route116_EventScript_Briney_4:
# 321 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave2
# 322 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney2
# 323 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1


Route116_EventScript_BrineyTrigger0::
# 330 "data/maps/Route116/scripts.pory"
	lockall
# 331 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival0
# 332 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 333 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger1::
# 338 "data/maps/Route116/scripts.pory"
	lockall
# 339 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival1
# 340 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 341 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger2::
# 346 "data/maps/Route116/scripts.pory"
	lockall
# 347 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival2
# 348 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 349 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyEvent::
# 354 "data/maps/Route116/scripts.pory"
	delay 10
# 355 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 356 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 357 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThisOldManIsUpset, MSGBOX_DEFAULT
# 358 "data/maps/Route116/scripts.pory"
	closemessage
# 359 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_FaceRight
# 360 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 361 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyWalkToPlayer
# 362 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 363 "data/maps/Route116/scripts.pory"
	applymovement 11, Common_Movement_BeginTalkLeft
# 364 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 365 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 366 "data/maps/Route116/scripts.pory"
	closemessage
# 367 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave
# 368 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 369 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 370 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 371 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 372 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 373 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 374 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoCheckOutTunnel, MSGBOX_DEFAULT
# 375 "data/maps/Route116/scripts.pory"
	closemessage
# 376 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 377 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 378 "data/maps/Route116/scripts.pory"
	releaseall
	return


# 381 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival0:
# 382 "data/maps/Route116/scripts.pory"
	walk_right
# 382 "data/maps/Route116/scripts.pory"
	walk_right
# 383 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 386 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival1:
# 387 "data/maps/Route116/scripts.pory"
	walk_right
# 387 "data/maps/Route116/scripts.pory"
	walk_right
# 388 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 391 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival2:
# 392 "data/maps/Route116/scripts.pory"
	walk_right
# 392 "data/maps/Route116/scripts.pory"
	walk_right
# 393 "data/maps/Route116/scripts.pory"
	walk_up
# 393 "data/maps/Route116/scripts.pory"
	walk_up
# 394 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 397 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyWalkToPlayer:
# 398 "data/maps/Route116/scripts.pory"
	walk_fast_down
	step_end

# 401 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave:
# 402 "data/maps/Route116/scripts.pory"
	walk_fast_up
# 403 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 403 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 403 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 404 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 405 "data/maps/Route116/scripts.pory"
	face_right
# 406 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 407 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 407 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 407 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 408 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 409 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 412 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney:
# 413 "data/maps/Route116/scripts.pory"
	delay_4
# 413 "data/maps/Route116/scripts.pory"
	delay_4
# 413 "data/maps/Route116/scripts.pory"
	delay_4
# 414 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 415 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 415 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 415 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 416 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 417 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 417 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 417 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 418 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 419 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 422 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave1:
# 423 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 423 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 423 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 424 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 425 "data/maps/Route116/scripts.pory"
	delay_8
# 426 "data/maps/Route116/scripts.pory"
	face_right
# 427 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 428 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 428 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 428 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 429 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 430 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 433 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave2:
# 434 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 435 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 435 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 435 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 436 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 437 "data/maps/Route116/scripts.pory"
	delay_8
# 438 "data/maps/Route116/scripts.pory"
	face_right
# 439 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 440 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 440 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 440 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 441 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 442 "data/maps/Route116/scripts.pory"
	face_down
# 443 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 444 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 445 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 446 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 449 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney2:
# 450 "data/maps/Route116/scripts.pory"
	delay_4
# 450 "data/maps/Route116/scripts.pory"
	delay_4
# 450 "data/maps/Route116/scripts.pory"
	delay_4
# 451 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 452 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 453 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 453 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 453 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 454 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 455 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 455 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 456 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 457 "data/maps/Route116/scripts.pory"
	face_down
# 458 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 459 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 460 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 461 "data/maps/Route116/scripts.pory"
	face_right
# 462 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 463 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 464 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 465 "data/maps/Route116/scripts.pory"
	face_right
# 466 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 500 "data/maps/Route116/scripts.pory"

# 501 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 502 "data/maps/Route116/scripts.pory"
	lock
# 503 "data/maps/Route116/scripts.pory"
	faceplayer
# 504 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 505 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 506 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 507 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 508 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 509 "data/maps/Route116/scripts.pory"
	release
# 510 "data/maps/Route116/scripts.pory"
	end
# 511 "data/maps/Route116/scripts.pory"

# 512 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 513 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 514 "data/maps/Route116/scripts.pory"
	closemessage
# 515 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 516 "data/maps/Route116/scripts.pory"
	end
# 517 "data/maps/Route116/scripts.pory"

# 518 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 519 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 520 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 521 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 522 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 523 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 524 "data/maps/Route116/scripts.pory"
	release
# 525 "data/maps/Route116/scripts.pory"
	end
# 526 "data/maps/Route116/scripts.pory"

# 527 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 528 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 529 "data/maps/Route116/scripts.pory"
	closemessage
# 530 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 531 "data/maps/Route116/scripts.pory"
	end
# 532 "data/maps/Route116/scripts.pory"

# 533 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 534 "data/maps/Route116/scripts.pory"
	delay 20
# 535 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 536 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 537 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 538 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 539 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 540 "data/maps/Route116/scripts.pory"
	release
# 541 "data/maps/Route116/scripts.pory"
	end
# 542 "data/maps/Route116/scripts.pory"

# 543 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 544 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 545 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 546 "data/maps/Route116/scripts.pory"
	return
# 547 "data/maps/Route116/scripts.pory"

# 548 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 549 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 550 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 551 "data/maps/Route116/scripts.pory"
	return
# 552 "data/maps/Route116/scripts.pory"

# 553 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
# 554 "data/maps/Route116/scripts.pory"
	walk_left
# 555 "data/maps/Route116/scripts.pory"
	walk_left
# 556 "data/maps/Route116/scripts.pory"
	walk_left
# 557 "data/maps/Route116/scripts.pory"
	walk_left
# 558 "data/maps/Route116/scripts.pory"
	walk_left
# 559 "data/maps/Route116/scripts.pory"
	walk_left
# 560 "data/maps/Route116/scripts.pory"
	walk_left
# 561 "data/maps/Route116/scripts.pory"
	walk_left
# 562 "data/maps/Route116/scripts.pory"
	walk_left
# 563 "data/maps/Route116/scripts.pory"
	step_end
# 564 "data/maps/Route116/scripts.pory"

# 565 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 566 "data/maps/Route116/scripts.pory"
	walk_up
# 567 "data/maps/Route116/scripts.pory"
	walk_left
# 568 "data/maps/Route116/scripts.pory"
	walk_left
# 569 "data/maps/Route116/scripts.pory"
	walk_left
# 570 "data/maps/Route116/scripts.pory"
	walk_left
# 571 "data/maps/Route116/scripts.pory"
	walk_left
# 572 "data/maps/Route116/scripts.pory"
	walk_left
# 573 "data/maps/Route116/scripts.pory"
	walk_left
# 574 "data/maps/Route116/scripts.pory"
	walk_left
# 575 "data/maps/Route116/scripts.pory"
	walk_left
# 576 "data/maps/Route116/scripts.pory"
	step_end
# 577 "data/maps/Route116/scripts.pory"

# 578 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 579 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 580 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 581 "data/maps/Route116/scripts.pory"
	end
# 582 "data/maps/Route116/scripts.pory"

# 583 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 584 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 585 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 586 "data/maps/Route116/scripts.pory"
	end
# 587 "data/maps/Route116/scripts.pory"

# 588 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 589 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 590 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 591 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 592 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 593 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 594 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 595 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 596 "data/maps/Route116/scripts.pory"
	release
# 597 "data/maps/Route116/scripts.pory"
	end
# 598 "data/maps/Route116/scripts.pory"

# 599 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 600 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 601 "data/maps/Route116/scripts.pory"
	release
# 602 "data/maps/Route116/scripts.pory"
	end
# 603 "data/maps/Route116/scripts.pory"

# 604 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 605 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 606 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 607 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 608 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 609 "data/maps/Route116/scripts.pory"
	release
# 610 "data/maps/Route116/scripts.pory"
	end
# 611 "data/maps/Route116/scripts.pory"

# 612 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 613 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 614 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 615 "data/maps/Route116/scripts.pory"
	release
# 616 "data/maps/Route116/scripts.pory"
	end
# 617 "data/maps/Route116/scripts.pory"

# 618 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 619 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 620 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 621 "data/maps/Route116/scripts.pory"
	release
# 622 "data/maps/Route116/scripts.pory"
	end
# 623 "data/maps/Route116/scripts.pory"

# 624 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 625 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 626 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 627 "data/maps/Route116/scripts.pory"
	end
# 628 "data/maps/Route116/scripts.pory"

# 629 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 630 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 631 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 632 "data/maps/Route116/scripts.pory"
	end
# 633 "data/maps/Route116/scripts.pory"

# 634 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 635 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 636 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 637 "data/maps/Route116/scripts.pory"
	end
# 638 "data/maps/Route116/scripts.pory"

# 639 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 640 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 641 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 642 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 643 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 644 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 645 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 646 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 647 "data/maps/Route116/scripts.pory"
	release
# 648 "data/maps/Route116/scripts.pory"
	end
# 649 "data/maps/Route116/scripts.pory"

# 650 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 651 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 652 "data/maps/Route116/scripts.pory"
	release
# 653 "data/maps/Route116/scripts.pory"
	end
# 654 "data/maps/Route116/scripts.pory"

# 655 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 656 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 657 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 658 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 659 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 660 "data/maps/Route116/scripts.pory"
	release
# 661 "data/maps/Route116/scripts.pory"
	end
# 662 "data/maps/Route116/scripts.pory"

# 663 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 664 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 665 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 666 "data/maps/Route116/scripts.pory"
	release
# 667 "data/maps/Route116/scripts.pory"
	end
# 668 "data/maps/Route116/scripts.pory"

# 669 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 670 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 671 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 672 "data/maps/Route116/scripts.pory"
	release
# 673 "data/maps/Route116/scripts.pory"
	end
# 674 "data/maps/Route116/scripts.pory"

# 675 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 676 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 677 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 678 "data/maps/Route116/scripts.pory"
	end
# 679 "data/maps/Route116/scripts.pory"

# 680 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 681 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 682 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 683 "data/maps/Route116/scripts.pory"
	end
# 684 "data/maps/Route116/scripts.pory"

# 685 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 686 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 687 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 688 "data/maps/Route116/scripts.pory"
	end
# 689 "data/maps/Route116/scripts.pory"

# 690 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 691 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 692 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 693 "data/maps/Route116/scripts.pory"
	end
# 694 "data/maps/Route116/scripts.pory"

# 695 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 696 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 697 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 698 "data/maps/Route116/scripts.pory"
	end
# 699 "data/maps/Route116/scripts.pory"

# 700 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 701 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 702 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 703 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 704 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 705 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 706 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 707 "data/maps/Route116/scripts.pory"

# 708 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 709 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 710 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 711 "data/maps/Route116/scripts.pory"

# 712 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 713 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 714 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 715 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 716 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 717 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 718 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 719 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 720 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 721 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 722 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 723 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 724 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 725 "data/maps/Route116/scripts.pory"

# 726 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 727 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 728 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 729 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 730 "data/maps/Route116/scripts.pory"

# 731 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 732 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 733 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 734 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 735 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 736 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 737 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 738 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 739 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 740 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 741 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 742 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 743 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 744 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 745 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 746 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 747 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 748 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 749 "data/maps/Route116/scripts.pory"

# 750 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 751 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 752 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 753 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 754 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 755 "data/maps/Route116/scripts.pory"

# 756 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 757 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 758 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 759 "data/maps/Route116/scripts.pory"

# 760 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 761 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 762 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 763 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 764 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 765 "data/maps/Route116/scripts.pory"

# 766 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 767 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 768 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 769 "data/maps/Route116/scripts.pory"

# 770 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 771 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 772 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 773 "data/maps/Route116/scripts.pory"

# 774 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 775 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 776 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 777 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 778 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 779 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 780 "data/maps/Route116/scripts.pory"

# 781 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 782 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 783 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 784 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 785 "data/maps/Route116/scripts.pory"

# 786 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 787 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 788 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 789 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 790 "data/maps/Route116/scripts.pory"

# 791 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 792 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 793 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 794 "data/maps/Route116/scripts.pory"

# 795 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 796 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 797 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 798 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 799 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 800 "data/maps/Route116/scripts.pory"

# 801 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 802 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 803 "data/maps/Route116/scripts.pory"

# 804 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 805 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 806 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 807 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 808 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 809 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 810 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 811 "data/maps/Route116/scripts.pory"

# 812 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 813 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 814 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 815 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 816 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 817 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 818 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"

Route116_Text_TakingABreak::
# 150 "data/maps/Route116/scripts.pory"
	.string "I'm taking a break from hunting rare\n"
	.string "POKéMON.$"

Route116_Text_ElusiveSkitty::
# 154 "data/maps/Route116/scripts.pory"
	.string "Why does SKITTY have to be so elusive?$"

Route116_Text_WouldYouLikeToBattle::
# 158 "data/maps/Route116/scripts.pory"
	.string "Ah! Fresh air!\n"
	.string "Feels good to be in the sun again.\p"
	.string "All that excitement has me energized!\n"
	.string "I know you just went through a whole\l"
	.string "ordeal, but would you be up for a battle\l"
	.string "with me?\l"
	.string "I'd love to experience your heroic\l"
	.string "skills first hand.\p"
	.string "What do you say?\n"
	.string "Would you like to battle?$"

Route116_Text_WontHoldAnythingBack::
# 168 "data/maps/Route116/scripts.pory"
	.string "Excellent!\n"
	.string "I won't hold anything back!$"

Route116_Text_RivalDefeated::
# 173 "data/maps/Route116/scripts.pory"
	.string "You really are the real deal, huh?$"

Route116_Text_MeetYouAtBrineysCottage::
# 177 "data/maps/Route116/scripts.pory"
	.string "You've certainly gotten stronger, but I\n"
	.string "got some licks in!\l"
	.string "I thought since I beat ROXANNE that I\l"
	.string "would have an easier time against you,\l"
	.string "though.\l"
	.string "But I suppose I should've expected it,\l"
	.string "since you've obviously beaten her too.\p"
	.string "Well, I suppose we should make our way\n"
	.string "to the next GYM. I hear it's on an island\l"
	.string "in town called DEWFORD, but I don't have\l"
	.string "the slightest idea how we are going to\l"
	.string "get there.\l"
	.string "Maybe MR. BRINEY can help us.\l"
	.string "It can't hurt to ask.\p"
	.string "I'll meet you at his cottage!$"

Route116_Text_HangingAroundForABit::
# 188 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "If you change your mind, I'll be hanging\l"
	.string "around here for a bit.\l"
	.string "I'm sure {RIVAL2} has gotten his hands on a\l"
	.string "SKITTY for his POKéDEX already.\l"
	.string "I can't let him beat me!$"

Route116_Text_HangingAroundForABit2::
# 195 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "If you change your mind, I'll be hanging\l"
	.string "around here for a bit.$"

Route116_Text_ThisOldManIsUpset::
# 469 "data/maps/Route116/scripts.pory"
	.string "Hey. This old man is super upset!\n"
	.string "I'm trying to calm him down, but…$"

Route116_Text_GoCheckOutTunnel::
# 474 "data/maps/Route116/scripts.pory"
	.string "This guy wants to go save his POKéMON,\n"
	.string "but I'm afraid he's going to hurt\l"
	.string "himself.\l"
	.string "Would you go check out the tunnel?\l"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_StayPutOldMan::
# 480 "data/maps/Route116/scripts.pory"
	.string "Stay put, old man!\n"
	.string "{PLAYER} has got this.$"

Route116_Text_Rival1::
# 485 "data/maps/Route116/scripts.pory"
	.string "Would you go check out the tunnel?\n"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_BrineyStillMad::
# 490 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
	.string "darling PEEKO!\p"
	.string "Wrrrooooooaaaar! PEEKO!$"

Route116_Text_BattleAfterAll::
# 496 "data/maps/Route116/scripts.pory"
	.string "Are you ready to have that battle after\n"
	.string "all?$"
