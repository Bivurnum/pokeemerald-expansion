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
	call_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 56 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route116_EventScript_DeclineRivalBattleInitial
# 62 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalLeaveAfterBattle
# 64 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 65 "data/maps/Route116/scripts.pory"
	removeobject 30
# 66 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 67 "data/maps/Route116/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_RIVAL1
# 68 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
# 69 "data/maps/Route116/scripts.pory"
	releaseall
# 70 "data/maps/Route116/scripts.pory"
	end
	end


Route116_EventScript_Rival1::
# 75 "data/maps/Route116/scripts.pory"
	lockall
# 76 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 77 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 78 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Rival1_3
# 80 "data/maps/Route116/scripts.pory"
	case 46, Route116_EventScript_Rival1_4
# 82 "data/maps/Route116/scripts.pory"
	case 47, Route116_EventScript_Rival1_5
Route116_EventScript_Rival1_1:
# 85 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_eq Route116_EventScript_Rival1_7
Route116_EventScript_Rival1_6:
# 90 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_Rival1, MSGBOX_DEFAULT
# 91 "data/maps/Route116/scripts.pory"
	closemessage
# 92 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 93 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_Rival1_3:
# 79 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_WEST
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_4:
# 81 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_SOUTH
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_5:
# 83 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_7:
# 86 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BattleAfterAll, MSGBOX_YESNO
# 87 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 88 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route116_EventScript_DeclineRivalBattle
	goto Route116_EventScript_Rival1_6


Route116_EventScript_RivalBattle::
# 98 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WontHoldAnythingBack
# 99 "data/maps/Route116/scripts.pory"
	checkfriendchoice
# 100 "data/maps/Route116/scripts.pory"
	switch VAR_RESULT
# 101 "data/maps/Route116/scripts.pory"
	case SPENCER, Route116_EventScript_RivalBattle_3
# 103 "data/maps/Route116/scripts.pory"
	case BREN, Route116_EventScript_RivalBattle_4
# 105 "data/maps/Route116/scripts.pory"
	case KYLE, Route116_EventScript_RivalBattle_5
Route116_EventScript_RivalBattle_1:
# 108 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WeShouldReturnGoods, MSGBOX_DEFAULT
# 109 "data/maps/Route116/scripts.pory"
	closemessage
# 110 "data/maps/Route116/scripts.pory"
	setvar VAR_RESULT, YES
	return

Route116_EventScript_RivalBattle_3:
# 102 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_4:
# 104 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_5:
# 106 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1


Route116_EventScript_DeclineRivalBattleInitial::
# 115 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NoBigDeal, MSGBOX_DEFAULT
# 116 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8007, 69
	return


Route116_EventScript_DeclineRivalBattle::
# 121 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_HangingAroundForABit2, MSGBOX_DEFAULT
# 122 "data/maps/Route116/scripts.pory"
	releaseall
	end


Route116_EventScript_Rival2::
# 127 "data/maps/Route116/scripts.pory"
	lock
# 128 "data/maps/Route116/scripts.pory"
	faceplayer
# 129 "data/maps/Route116/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route116_EventScript_Rival2_2
# 134 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ElusiveSkitty, MSGBOX_DEFAULT
Route116_EventScript_Rival2_1:
# 136 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Rival2_2:
# 130 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TakingABreak, MSGBOX_DEFAULT
# 131 "data/maps/Route116/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route116_EventScript_Rival2_1


# 140 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle:
# 141 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 141 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 142 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 143 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 146 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle2:
# 147 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 148 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 148 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 149 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 150 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 199 "data/maps/Route116/scripts.pory"

# 200 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 201 "data/maps/Route116/scripts.pory"
	lock
# 202 "data/maps/Route116/scripts.pory"
	faceplayer
# 203 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 204 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 205 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 206 "data/maps/Route116/scripts.pory"
	release
# 207 "data/maps/Route116/scripts.pory"
	end
# 208 "data/maps/Route116/scripts.pory"

# 209 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 210 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 211 "data/maps/Route116/scripts.pory"
	release
# 212 "data/maps/Route116/scripts.pory"
	end
# 213 "data/maps/Route116/scripts.pory"

# 214 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 215 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 216 "data/maps/Route116/scripts.pory"
	release
# 217 "data/maps/Route116/scripts.pory"
	end
# 218 "data/maps/Route116/scripts.pory"

# 219 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 220 "data/maps/Route116/scripts.pory"
	lock
# 221 "data/maps/Route116/scripts.pory"
	faceplayer
# 222 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 223 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 224 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 225 "data/maps/Route116/scripts.pory"
	end
# 226 "data/maps/Route116/scripts.pory"

# 227 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 228 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 229 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 230 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 231 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 232 "data/maps/Route116/scripts.pory"
	closemessage
# 233 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 234 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 235 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 236 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 237 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 238 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 239 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 240 "data/maps/Route116/scripts.pory"
	release
# 241 "data/maps/Route116/scripts.pory"
	end
# 242 "data/maps/Route116/scripts.pory"

# 243 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 244 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 245 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 246 "data/maps/Route116/scripts.pory"
	return
# 247 "data/maps/Route116/scripts.pory"

# 248 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 249 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 250 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 251 "data/maps/Route116/scripts.pory"
	return
# 252 "data/maps/Route116/scripts.pory"

# 253 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 254 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 255 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 256 "data/maps/Route116/scripts.pory"
	end
# 257 "data/maps/Route116/scripts.pory"

# 258 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 259 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 260 "data/maps/Route116/scripts.pory"
	release
# 261 "data/maps/Route116/scripts.pory"
	end
# 262 "data/maps/Route116/scripts.pory"

# 263 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 264 "data/maps/Route116/scripts.pory"
	walk_left
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
	step_end
# 273 "data/maps/Route116/scripts.pory"

# 274 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 275 "data/maps/Route116/scripts.pory"
	walk_down
# 276 "data/maps/Route116/scripts.pory"
	walk_left
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
	step_end
# 286 "data/maps/Route116/scripts.pory"

# 287 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 288 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 289 "data/maps/Route116/scripts.pory"
	end
# 290 "data/maps/Route116/scripts.pory"

# 291 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 292 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 293 "data/maps/Route116/scripts.pory"
	end
# 294 "data/maps/Route116/scripts.pory"

# 295 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 296 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 297 "data/maps/Route116/scripts.pory"
	end
# 298 "data/maps/Route116/scripts.pory"

# 299 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 300 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 301 "data/maps/Route116/scripts.pory"
	end
# 302 "data/maps/Route116/scripts.pory"

# 303 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 304 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 305 "data/maps/Route116/scripts.pory"
	end

Route116_EventScript_Briney::
# 309 "data/maps/Route116/scripts.pory"
	lock
# 310 "data/maps/Route116/scripts.pory"
	faceplayer
# 311 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BrineyStillMad, MSGBOX_DEFAULT
# 312 "data/maps/Route116/scripts.pory"
	closemessage
# 313 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 314 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 315 "data/maps/Route116/scripts.pory"
	case 44, Route116_EventScript_Briney_3
# 319 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Briney_4
Route116_EventScript_Briney_1:
# 324 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Briney_3:
# 316 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave1
# 317 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 318 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1

Route116_EventScript_Briney_4:
# 320 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave2
# 321 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney2
# 322 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1


Route116_EventScript_BrineyTrigger0::
# 329 "data/maps/Route116/scripts.pory"
	lockall
# 330 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival0
# 331 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 332 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger1::
# 337 "data/maps/Route116/scripts.pory"
	lockall
# 338 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival1
# 339 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 340 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger2::
# 345 "data/maps/Route116/scripts.pory"
	lockall
# 346 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival2
# 347 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 348 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyEvent::
# 353 "data/maps/Route116/scripts.pory"
	delay 10
# 354 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 355 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 356 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThisOldManIsUpset, MSGBOX_DEFAULT
# 357 "data/maps/Route116/scripts.pory"
	closemessage
# 358 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_FaceRight
# 359 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 360 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyWalkToPlayer
# 361 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 362 "data/maps/Route116/scripts.pory"
	applymovement 11, Common_Movement_BeginTalkLeft
# 363 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 364 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 365 "data/maps/Route116/scripts.pory"
	closemessage
# 366 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave
# 367 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 368 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 369 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 370 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 371 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 372 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 373 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoCheckOutTunnel, MSGBOX_DEFAULT
# 374 "data/maps/Route116/scripts.pory"
	closemessage
# 375 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 376 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 377 "data/maps/Route116/scripts.pory"
	releaseall
	return


# 380 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival0:
# 381 "data/maps/Route116/scripts.pory"
	walk_right
# 381 "data/maps/Route116/scripts.pory"
	walk_right
# 382 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 385 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival1:
# 386 "data/maps/Route116/scripts.pory"
	walk_right
# 386 "data/maps/Route116/scripts.pory"
	walk_right
# 387 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 390 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival2:
# 391 "data/maps/Route116/scripts.pory"
	walk_right
# 391 "data/maps/Route116/scripts.pory"
	walk_right
# 392 "data/maps/Route116/scripts.pory"
	walk_up
# 392 "data/maps/Route116/scripts.pory"
	walk_up
# 393 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 396 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyWalkToPlayer:
# 397 "data/maps/Route116/scripts.pory"
	walk_fast_down
	step_end

# 400 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave:
# 401 "data/maps/Route116/scripts.pory"
	walk_fast_up
# 402 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 402 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 402 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 403 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 404 "data/maps/Route116/scripts.pory"
	face_right
# 405 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 406 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 406 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 406 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 407 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 408 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 411 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney:
# 412 "data/maps/Route116/scripts.pory"
	delay_4
# 412 "data/maps/Route116/scripts.pory"
	delay_4
# 412 "data/maps/Route116/scripts.pory"
	delay_4
# 413 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 414 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 414 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 414 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 415 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 416 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 416 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 416 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 417 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 418 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 421 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave1:
# 422 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 422 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 422 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 423 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 424 "data/maps/Route116/scripts.pory"
	delay_8
# 425 "data/maps/Route116/scripts.pory"
	face_right
# 426 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 427 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 427 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 427 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 428 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 429 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 432 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave2:
# 433 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 434 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 434 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 434 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 435 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 436 "data/maps/Route116/scripts.pory"
	delay_8
# 437 "data/maps/Route116/scripts.pory"
	face_right
# 438 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 439 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 439 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 439 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 440 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 441 "data/maps/Route116/scripts.pory"
	face_down
# 442 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 443 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 444 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 445 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 448 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney2:
# 449 "data/maps/Route116/scripts.pory"
	delay_4
# 449 "data/maps/Route116/scripts.pory"
	delay_4
# 449 "data/maps/Route116/scripts.pory"
	delay_4
# 450 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 451 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 452 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 452 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 452 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 453 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 454 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 454 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 455 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 456 "data/maps/Route116/scripts.pory"
	face_down
# 457 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 458 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 459 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 460 "data/maps/Route116/scripts.pory"
	face_right
# 461 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 462 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 463 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 464 "data/maps/Route116/scripts.pory"
	face_right
# 465 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 499 "data/maps/Route116/scripts.pory"

# 500 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 501 "data/maps/Route116/scripts.pory"
	lock
# 502 "data/maps/Route116/scripts.pory"
	faceplayer
# 503 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 504 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 505 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 506 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 507 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 508 "data/maps/Route116/scripts.pory"
	release
# 509 "data/maps/Route116/scripts.pory"
	end
# 510 "data/maps/Route116/scripts.pory"

# 511 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 512 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 513 "data/maps/Route116/scripts.pory"
	closemessage
# 514 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 515 "data/maps/Route116/scripts.pory"
	end
# 516 "data/maps/Route116/scripts.pory"

# 517 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 518 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 519 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 520 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 521 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 522 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 523 "data/maps/Route116/scripts.pory"
	release
# 524 "data/maps/Route116/scripts.pory"
	end
# 525 "data/maps/Route116/scripts.pory"

# 526 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 527 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 528 "data/maps/Route116/scripts.pory"
	closemessage
# 529 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 530 "data/maps/Route116/scripts.pory"
	end
# 531 "data/maps/Route116/scripts.pory"

# 532 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 533 "data/maps/Route116/scripts.pory"
	delay 20
# 534 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 535 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 536 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 537 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 538 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 539 "data/maps/Route116/scripts.pory"
	release
# 540 "data/maps/Route116/scripts.pory"
	end
# 541 "data/maps/Route116/scripts.pory"

# 542 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 543 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 544 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 545 "data/maps/Route116/scripts.pory"
	return
# 546 "data/maps/Route116/scripts.pory"

# 547 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 548 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 549 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 550 "data/maps/Route116/scripts.pory"
	return
# 551 "data/maps/Route116/scripts.pory"

# 552 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
# 553 "data/maps/Route116/scripts.pory"
	walk_left
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
	step_end
# 563 "data/maps/Route116/scripts.pory"

# 564 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 565 "data/maps/Route116/scripts.pory"
	walk_up
# 566 "data/maps/Route116/scripts.pory"
	walk_left
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
	step_end
# 576 "data/maps/Route116/scripts.pory"

# 577 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 578 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 579 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 580 "data/maps/Route116/scripts.pory"
	end
# 581 "data/maps/Route116/scripts.pory"

# 582 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 583 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 584 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 585 "data/maps/Route116/scripts.pory"
	end
# 586 "data/maps/Route116/scripts.pory"

# 587 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 588 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 589 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 590 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 591 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 592 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 593 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 594 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 595 "data/maps/Route116/scripts.pory"
	release
# 596 "data/maps/Route116/scripts.pory"
	end
# 597 "data/maps/Route116/scripts.pory"

# 598 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 599 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 600 "data/maps/Route116/scripts.pory"
	release
# 601 "data/maps/Route116/scripts.pory"
	end
# 602 "data/maps/Route116/scripts.pory"

# 603 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 604 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 605 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 606 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 607 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 608 "data/maps/Route116/scripts.pory"
	release
# 609 "data/maps/Route116/scripts.pory"
	end
# 610 "data/maps/Route116/scripts.pory"

# 611 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 612 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 613 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 614 "data/maps/Route116/scripts.pory"
	release
# 615 "data/maps/Route116/scripts.pory"
	end
# 616 "data/maps/Route116/scripts.pory"

# 617 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 618 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 619 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 620 "data/maps/Route116/scripts.pory"
	release
# 621 "data/maps/Route116/scripts.pory"
	end
# 622 "data/maps/Route116/scripts.pory"

# 623 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 624 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 625 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 626 "data/maps/Route116/scripts.pory"
	end
# 627 "data/maps/Route116/scripts.pory"

# 628 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 629 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 630 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 631 "data/maps/Route116/scripts.pory"
	end
# 632 "data/maps/Route116/scripts.pory"

# 633 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 634 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 635 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 636 "data/maps/Route116/scripts.pory"
	end
# 637 "data/maps/Route116/scripts.pory"

# 638 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 639 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 640 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 641 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 642 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 643 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 644 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 645 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 646 "data/maps/Route116/scripts.pory"
	release
# 647 "data/maps/Route116/scripts.pory"
	end
# 648 "data/maps/Route116/scripts.pory"

# 649 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 650 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 651 "data/maps/Route116/scripts.pory"
	release
# 652 "data/maps/Route116/scripts.pory"
	end
# 653 "data/maps/Route116/scripts.pory"

# 654 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 655 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 656 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 657 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 658 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 659 "data/maps/Route116/scripts.pory"
	release
# 660 "data/maps/Route116/scripts.pory"
	end
# 661 "data/maps/Route116/scripts.pory"

# 662 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 663 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 664 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 665 "data/maps/Route116/scripts.pory"
	release
# 666 "data/maps/Route116/scripts.pory"
	end
# 667 "data/maps/Route116/scripts.pory"

# 668 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 669 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 670 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 671 "data/maps/Route116/scripts.pory"
	release
# 672 "data/maps/Route116/scripts.pory"
	end
# 673 "data/maps/Route116/scripts.pory"

# 674 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 675 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 676 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 677 "data/maps/Route116/scripts.pory"
	end
# 678 "data/maps/Route116/scripts.pory"

# 679 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 680 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 681 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 682 "data/maps/Route116/scripts.pory"
	end
# 683 "data/maps/Route116/scripts.pory"

# 684 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 685 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 686 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 687 "data/maps/Route116/scripts.pory"
	end
# 688 "data/maps/Route116/scripts.pory"

# 689 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 690 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 691 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 692 "data/maps/Route116/scripts.pory"
	end
# 693 "data/maps/Route116/scripts.pory"

# 694 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 695 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 696 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 697 "data/maps/Route116/scripts.pory"
	end
# 698 "data/maps/Route116/scripts.pory"

# 699 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 700 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 701 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 702 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 703 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 704 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 705 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 706 "data/maps/Route116/scripts.pory"

# 707 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 708 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 709 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 710 "data/maps/Route116/scripts.pory"

# 711 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 712 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 713 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 714 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 715 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 716 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 717 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 718 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 719 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 720 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 721 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 722 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 723 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 724 "data/maps/Route116/scripts.pory"

# 725 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 726 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 727 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 728 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 729 "data/maps/Route116/scripts.pory"

# 730 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 731 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 732 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 733 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 734 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 735 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 736 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 737 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 738 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 739 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 740 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 741 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 742 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 743 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 744 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 745 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 746 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 747 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 748 "data/maps/Route116/scripts.pory"

# 749 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 750 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 751 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 752 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 753 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 754 "data/maps/Route116/scripts.pory"

# 755 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 756 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 757 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 758 "data/maps/Route116/scripts.pory"

# 759 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 760 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 761 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 762 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 763 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 764 "data/maps/Route116/scripts.pory"

# 765 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 766 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 767 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 768 "data/maps/Route116/scripts.pory"

# 769 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 770 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 771 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 772 "data/maps/Route116/scripts.pory"

# 773 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 774 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 775 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 776 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 777 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 778 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 779 "data/maps/Route116/scripts.pory"

# 780 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 781 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 782 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 783 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 784 "data/maps/Route116/scripts.pory"

# 785 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 786 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 787 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 788 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 789 "data/maps/Route116/scripts.pory"

# 790 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 791 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 792 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 793 "data/maps/Route116/scripts.pory"

# 794 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 795 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 796 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 797 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 798 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 799 "data/maps/Route116/scripts.pory"

# 800 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 801 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 802 "data/maps/Route116/scripts.pory"

# 803 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 804 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 805 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 806 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 807 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 808 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 809 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 810 "data/maps/Route116/scripts.pory"

# 811 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 812 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 813 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 814 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 815 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 816 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 817 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"

Route116_Text_TakingABreak::
# 153 "data/maps/Route116/scripts.pory"
	.string "I'm taking a break from hunting rare\n"
	.string "POKéMON.$"

Route116_Text_ElusiveSkitty::
# 157 "data/maps/Route116/scripts.pory"
	.string "Why does SKITTY have to be so elusive?$"

Route116_Text_WouldYouLikeToBattle::
# 161 "data/maps/Route116/scripts.pory"
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
# 171 "data/maps/Route116/scripts.pory"
	.string "Excellent!\n"
	.string "I won't hold anything back!$"

Route116_Text_RivalDefeated::
# 176 "data/maps/Route116/scripts.pory"
	.string "You really are the real deal, huh?$"

Route116_Text_WeShouldReturnGoods::
# 180 "data/maps/Route116/scripts.pory"
	.string "You've certainly gotten stronger, but I\n"
	.string "got some licks in!\l"
	.string "I thought since I beat ROXANNE that I\l"
	.string "would have an easier time against you,\l"
	.string "though.\l"
	.string "But I suppose I should've expected it,\l"
	.string "since you've obviously beaten her too.\p"
	.string "Well, I suppose we should go return\n"
	.string "those GOODS.\l"
	.string "Come on!$"

Route116_Text_NoBigDeal::
# 188 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "We should go return those GOODS\l"
	.string "anyway.\l"
	.string "Come on!$"

Route116_Text_HangingAroundForABit2::
# 194 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "If you change your mind, I'll be hanging\l"
	.string "around here for a bit.$"

Route116_Text_ThisOldManIsUpset::
# 468 "data/maps/Route116/scripts.pory"
	.string "Hey. This old man is super upset!\n"
	.string "I'm trying to calm him down, but…$"

Route116_Text_GoCheckOutTunnel::
# 473 "data/maps/Route116/scripts.pory"
	.string "This guy wants to go save his POKéMON,\n"
	.string "but I'm afraid he's going to hurt\l"
	.string "himself.\l"
	.string "Would you go check out the tunnel?\l"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_StayPutOldMan::
# 479 "data/maps/Route116/scripts.pory"
	.string "Stay put, old man!\n"
	.string "{PLAYER} has got this.$"

Route116_Text_Rival1::
# 484 "data/maps/Route116/scripts.pory"
	.string "Would you go check out the tunnel?\n"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_BrineyStillMad::
# 489 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
	.string "darling PEEKO!\p"
	.string "Wrrrooooooaaaar! PEEKO!$"

Route116_Text_BattleAfterAll::
# 495 "data/maps/Route116/scripts.pory"
	.string "Are you ready to have that battle after\n"
	.string "all?$"
