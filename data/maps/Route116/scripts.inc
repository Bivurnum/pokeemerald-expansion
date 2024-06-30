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
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_eq Route116_EventScript_TalkToRivalAfterAquaBattle_2
Route116_EventScript_TalkToRivalAfterAquaBattle_1:
# 71 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_TalkToRivalAfterAquaBattle_2:
# 69 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	goto Route116_EventScript_TalkToRivalAfterAquaBattle_1


Route116_EventScript_Rival1::
# 76 "data/maps/Route116/scripts.pory"
	lockall
# 77 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 78 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 79 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Rival1_3
# 81 "data/maps/Route116/scripts.pory"
	case 46, Route116_EventScript_Rival1_4
# 83 "data/maps/Route116/scripts.pory"
	case 47, Route116_EventScript_Rival1_5
Route116_EventScript_Rival1_1:
# 86 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_eq Route116_EventScript_Rival1_7
Route116_EventScript_Rival1_6:
# 91 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_Rival1, MSGBOX_DEFAULT
# 92 "data/maps/Route116/scripts.pory"
	closemessage
# 93 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 94 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_Rival1_3:
# 80 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_WEST
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_4:
# 82 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_SOUTH
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_5:
# 84 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
	goto Route116_EventScript_Rival1_1

Route116_EventScript_Rival1_7:
# 87 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BattleAfterAll, MSGBOX_YESNO
# 88 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 89 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route116_EventScript_DeclineRivalBattle
	goto Route116_EventScript_Rival1_6


Route116_EventScript_RivalBattle::
# 99 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WontHoldAnythingBack
# 100 "data/maps/Route116/scripts.pory"
	checkfriendchoice
# 101 "data/maps/Route116/scripts.pory"
	switch VAR_RESULT
# 102 "data/maps/Route116/scripts.pory"
	case SPENCER, Route116_EventScript_RivalBattle_3
# 104 "data/maps/Route116/scripts.pory"
	case BREN, Route116_EventScript_RivalBattle_4
# 106 "data/maps/Route116/scripts.pory"
	case KYLE, Route116_EventScript_RivalBattle_5
Route116_EventScript_RivalBattle_1:
# 109 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WeShouldReturnGoods, MSGBOX_DEFAULT
# 110 "data/maps/Route116/scripts.pory"
	closemessage
# 111 "data/maps/Route116/scripts.pory"
	setvar VAR_RESULT, YES
# 112 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 7
	return

Route116_EventScript_RivalBattle_3:
# 103 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_RUSTBORO, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_4:
# 105 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_RUSTBORO, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_5:
# 107 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_RUSTBORO, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1


Route116_EventScript_DeclineRivalBattleInitial::
# 117 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NoBigDeal, MSGBOX_DEFAULT
# 118 "data/maps/Route116/scripts.pory"
	closemessage
# 119 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8007, 69
	return


Route116_EventScript_DeclineRivalBattle::
# 124 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_HangingAroundForABit2, MSGBOX_DEFAULT
# 125 "data/maps/Route116/scripts.pory"
	releaseall
	end


Route116_EventScript_Rival2::
# 130 "data/maps/Route116/scripts.pory"
	lock
# 131 "data/maps/Route116/scripts.pory"
	faceplayer
# 132 "data/maps/Route116/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route116_EventScript_Rival2_2
# 137 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ElusiveSkitty, MSGBOX_DEFAULT
Route116_EventScript_Rival2_1:
# 139 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Rival2_2:
# 133 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TakingABreak, MSGBOX_DEFAULT
# 134 "data/maps/Route116/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route116_EventScript_Rival2_1


# 143 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle:
# 144 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 144 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 145 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 146 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 149 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle2:
# 150 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 151 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 151 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 152 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 153 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 202 "data/maps/Route116/scripts.pory"

# 203 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 204 "data/maps/Route116/scripts.pory"
	lock
# 205 "data/maps/Route116/scripts.pory"
	faceplayer
# 206 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 207 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 208 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 209 "data/maps/Route116/scripts.pory"
	release
# 210 "data/maps/Route116/scripts.pory"
	end
# 211 "data/maps/Route116/scripts.pory"

# 212 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 213 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 214 "data/maps/Route116/scripts.pory"
	release
# 215 "data/maps/Route116/scripts.pory"
	end
# 216 "data/maps/Route116/scripts.pory"

# 217 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 218 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 219 "data/maps/Route116/scripts.pory"
	release
# 220 "data/maps/Route116/scripts.pory"
	end
# 221 "data/maps/Route116/scripts.pory"

# 222 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 223 "data/maps/Route116/scripts.pory"
	lock
# 224 "data/maps/Route116/scripts.pory"
	faceplayer
# 225 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 226 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 227 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 228 "data/maps/Route116/scripts.pory"
	end
# 229 "data/maps/Route116/scripts.pory"

# 230 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 231 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 232 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 233 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 234 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 235 "data/maps/Route116/scripts.pory"
	closemessage
# 236 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 237 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 238 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 239 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 240 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 241 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 242 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 243 "data/maps/Route116/scripts.pory"
	release
# 244 "data/maps/Route116/scripts.pory"
	end
# 245 "data/maps/Route116/scripts.pory"

# 246 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 247 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 248 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 249 "data/maps/Route116/scripts.pory"
	return
# 250 "data/maps/Route116/scripts.pory"

# 251 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 252 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 253 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 254 "data/maps/Route116/scripts.pory"
	return
# 255 "data/maps/Route116/scripts.pory"

# 256 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 257 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 258 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 259 "data/maps/Route116/scripts.pory"
	end
# 260 "data/maps/Route116/scripts.pory"

# 261 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 262 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 263 "data/maps/Route116/scripts.pory"
	release
# 264 "data/maps/Route116/scripts.pory"
	end
# 265 "data/maps/Route116/scripts.pory"

# 266 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
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
	walk_left
# 274 "data/maps/Route116/scripts.pory"
	walk_left
# 275 "data/maps/Route116/scripts.pory"
	step_end
# 276 "data/maps/Route116/scripts.pory"

# 277 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 278 "data/maps/Route116/scripts.pory"
	walk_down
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
	walk_left
# 287 "data/maps/Route116/scripts.pory"
	walk_left
# 288 "data/maps/Route116/scripts.pory"
	step_end
# 289 "data/maps/Route116/scripts.pory"

# 290 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 291 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 292 "data/maps/Route116/scripts.pory"
	end
# 293 "data/maps/Route116/scripts.pory"

# 294 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 295 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 296 "data/maps/Route116/scripts.pory"
	end
# 297 "data/maps/Route116/scripts.pory"

# 298 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 299 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 300 "data/maps/Route116/scripts.pory"
	end
# 301 "data/maps/Route116/scripts.pory"

# 302 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 303 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 304 "data/maps/Route116/scripts.pory"
	end
# 305 "data/maps/Route116/scripts.pory"

# 306 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 307 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 308 "data/maps/Route116/scripts.pory"
	end

Route116_EventScript_Briney::
# 312 "data/maps/Route116/scripts.pory"
	lock
# 313 "data/maps/Route116/scripts.pory"
	faceplayer
# 314 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BrineyStillMad, MSGBOX_DEFAULT
# 315 "data/maps/Route116/scripts.pory"
	closemessage
# 316 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 317 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 318 "data/maps/Route116/scripts.pory"
	case 44, Route116_EventScript_Briney_3
# 322 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Briney_4
Route116_EventScript_Briney_1:
# 327 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Briney_3:
# 319 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave1
# 320 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 321 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1

Route116_EventScript_Briney_4:
# 323 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave2
# 324 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney2
# 325 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1


Route116_EventScript_BrineyTrigger0::
# 332 "data/maps/Route116/scripts.pory"
	lockall
# 333 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival0
# 334 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 335 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger1::
# 340 "data/maps/Route116/scripts.pory"
	lockall
# 341 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival1
# 342 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 343 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger2::
# 348 "data/maps/Route116/scripts.pory"
	lockall
# 349 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival2
# 350 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 351 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger3::
# 356 "data/maps/Route116/scripts.pory"
	lockall
# 357 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival3
# 358 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 359 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyEvent::
# 364 "data/maps/Route116/scripts.pory"
	delay 10
# 365 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 366 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 367 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThisOldManIsUpset, MSGBOX_DEFAULT
# 368 "data/maps/Route116/scripts.pory"
	closemessage
# 369 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_FaceRight
# 370 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 371 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyWalkToPlayer
# 372 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 373 "data/maps/Route116/scripts.pory"
	applymovement 11, Common_Movement_BeginTalkLeft
# 374 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 375 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 376 "data/maps/Route116/scripts.pory"
	closemessage
# 377 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave
# 378 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 379 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 380 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 381 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 382 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 383 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 384 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoCheckOutTunnel, MSGBOX_DEFAULT
# 385 "data/maps/Route116/scripts.pory"
	closemessage
# 386 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 387 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 388 "data/maps/Route116/scripts.pory"
	releaseall
	return


# 391 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival0:
# 392 "data/maps/Route116/scripts.pory"
	walk_right
# 392 "data/maps/Route116/scripts.pory"
	walk_right
# 393 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 396 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival1:
# 397 "data/maps/Route116/scripts.pory"
	walk_right
# 397 "data/maps/Route116/scripts.pory"
	walk_right
# 398 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 401 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival2:
# 402 "data/maps/Route116/scripts.pory"
	walk_right
# 402 "data/maps/Route116/scripts.pory"
	walk_right
# 403 "data/maps/Route116/scripts.pory"
	walk_up
# 403 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 406 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival3:
# 407 "data/maps/Route116/scripts.pory"
	walk_right
# 407 "data/maps/Route116/scripts.pory"
	walk_right
# 408 "data/maps/Route116/scripts.pory"
	walk_up
# 408 "data/maps/Route116/scripts.pory"
	walk_up
# 408 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 411 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyWalkToPlayer:
# 412 "data/maps/Route116/scripts.pory"
	walk_fast_down
	step_end

# 415 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave:
# 416 "data/maps/Route116/scripts.pory"
	walk_fast_up
# 417 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 417 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 417 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 418 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 419 "data/maps/Route116/scripts.pory"
	face_right
# 420 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 421 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 421 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 421 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 422 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 423 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 426 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney:
# 427 "data/maps/Route116/scripts.pory"
	delay_4
# 427 "data/maps/Route116/scripts.pory"
	delay_4
# 427 "data/maps/Route116/scripts.pory"
	delay_4
# 428 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 429 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 429 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 429 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 430 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 431 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 431 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 431 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 432 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 433 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 436 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave1:
# 437 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 437 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 437 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 438 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 439 "data/maps/Route116/scripts.pory"
	delay_8
# 440 "data/maps/Route116/scripts.pory"
	face_right
# 441 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 442 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 442 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 442 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 443 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 444 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 447 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave2:
# 448 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 449 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 449 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 449 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 450 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 451 "data/maps/Route116/scripts.pory"
	delay_8
# 452 "data/maps/Route116/scripts.pory"
	face_right
# 453 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 454 "data/maps/Route116/scripts.pory"
	walk_slow_left
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
	face_left
	step_end

# 463 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney2:
# 464 "data/maps/Route116/scripts.pory"
	delay_4
# 464 "data/maps/Route116/scripts.pory"
	delay_4
# 464 "data/maps/Route116/scripts.pory"
	delay_4
# 465 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 466 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 467 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 467 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 467 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 468 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 469 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 469 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 470 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 471 "data/maps/Route116/scripts.pory"
	face_down
# 472 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 473 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 474 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 475 "data/maps/Route116/scripts.pory"
	face_right
# 476 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 477 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 478 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 479 "data/maps/Route116/scripts.pory"
	face_right
# 480 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 514 "data/maps/Route116/scripts.pory"

# 515 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 516 "data/maps/Route116/scripts.pory"
	lock
# 517 "data/maps/Route116/scripts.pory"
	faceplayer
# 518 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 519 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 520 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 521 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 522 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 523 "data/maps/Route116/scripts.pory"
	release
# 524 "data/maps/Route116/scripts.pory"
	end
# 525 "data/maps/Route116/scripts.pory"

# 526 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 527 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 528 "data/maps/Route116/scripts.pory"
	closemessage
# 529 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 530 "data/maps/Route116/scripts.pory"
	end
# 531 "data/maps/Route116/scripts.pory"

# 532 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 533 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 534 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 535 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 536 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 537 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 538 "data/maps/Route116/scripts.pory"
	release
# 539 "data/maps/Route116/scripts.pory"
	end
# 540 "data/maps/Route116/scripts.pory"

# 541 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 542 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 543 "data/maps/Route116/scripts.pory"
	closemessage
# 544 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 545 "data/maps/Route116/scripts.pory"
	end
# 546 "data/maps/Route116/scripts.pory"

# 547 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 548 "data/maps/Route116/scripts.pory"
	delay 20
# 549 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 550 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 551 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 552 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 553 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 554 "data/maps/Route116/scripts.pory"
	release
# 555 "data/maps/Route116/scripts.pory"
	end
# 556 "data/maps/Route116/scripts.pory"

# 557 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 558 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 559 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 560 "data/maps/Route116/scripts.pory"
	return
# 561 "data/maps/Route116/scripts.pory"

# 562 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 563 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 564 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 565 "data/maps/Route116/scripts.pory"
	return
# 566 "data/maps/Route116/scripts.pory"

# 567 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
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
	walk_left
# 577 "data/maps/Route116/scripts.pory"
	step_end
# 578 "data/maps/Route116/scripts.pory"

# 579 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 580 "data/maps/Route116/scripts.pory"
	walk_up
# 581 "data/maps/Route116/scripts.pory"
	walk_left
# 582 "data/maps/Route116/scripts.pory"
	walk_left
# 583 "data/maps/Route116/scripts.pory"
	walk_left
# 584 "data/maps/Route116/scripts.pory"
	walk_left
# 585 "data/maps/Route116/scripts.pory"
	walk_left
# 586 "data/maps/Route116/scripts.pory"
	walk_left
# 587 "data/maps/Route116/scripts.pory"
	walk_left
# 588 "data/maps/Route116/scripts.pory"
	walk_left
# 589 "data/maps/Route116/scripts.pory"
	walk_left
# 590 "data/maps/Route116/scripts.pory"
	step_end
# 591 "data/maps/Route116/scripts.pory"

# 592 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 593 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 594 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 595 "data/maps/Route116/scripts.pory"
	end
# 596 "data/maps/Route116/scripts.pory"

# 597 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 598 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 599 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 600 "data/maps/Route116/scripts.pory"
	end
# 601 "data/maps/Route116/scripts.pory"

# 602 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 603 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 604 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 605 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 606 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 607 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 608 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 609 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 610 "data/maps/Route116/scripts.pory"
	release
# 611 "data/maps/Route116/scripts.pory"
	end
# 612 "data/maps/Route116/scripts.pory"

# 613 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 614 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 615 "data/maps/Route116/scripts.pory"
	release
# 616 "data/maps/Route116/scripts.pory"
	end
# 617 "data/maps/Route116/scripts.pory"

# 618 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 619 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 620 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 621 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 622 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 623 "data/maps/Route116/scripts.pory"
	release
# 624 "data/maps/Route116/scripts.pory"
	end
# 625 "data/maps/Route116/scripts.pory"

# 626 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 627 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 628 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 629 "data/maps/Route116/scripts.pory"
	release
# 630 "data/maps/Route116/scripts.pory"
	end
# 631 "data/maps/Route116/scripts.pory"

# 632 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 633 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 634 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 635 "data/maps/Route116/scripts.pory"
	release
# 636 "data/maps/Route116/scripts.pory"
	end
# 637 "data/maps/Route116/scripts.pory"

# 638 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 639 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 640 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 641 "data/maps/Route116/scripts.pory"
	end
# 642 "data/maps/Route116/scripts.pory"

# 643 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 644 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 645 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 646 "data/maps/Route116/scripts.pory"
	end
# 647 "data/maps/Route116/scripts.pory"

# 648 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 649 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 650 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 651 "data/maps/Route116/scripts.pory"
	end
# 652 "data/maps/Route116/scripts.pory"

# 653 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 654 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 655 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 656 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 657 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 658 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 659 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 660 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 661 "data/maps/Route116/scripts.pory"
	release
# 662 "data/maps/Route116/scripts.pory"
	end
# 663 "data/maps/Route116/scripts.pory"

# 664 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 665 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 666 "data/maps/Route116/scripts.pory"
	release
# 667 "data/maps/Route116/scripts.pory"
	end
# 668 "data/maps/Route116/scripts.pory"

# 669 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 670 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 671 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 672 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 673 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 674 "data/maps/Route116/scripts.pory"
	release
# 675 "data/maps/Route116/scripts.pory"
	end
# 676 "data/maps/Route116/scripts.pory"

# 677 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 678 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 679 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 680 "data/maps/Route116/scripts.pory"
	release
# 681 "data/maps/Route116/scripts.pory"
	end
# 682 "data/maps/Route116/scripts.pory"

# 683 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 684 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 685 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 686 "data/maps/Route116/scripts.pory"
	release
# 687 "data/maps/Route116/scripts.pory"
	end
# 688 "data/maps/Route116/scripts.pory"

# 689 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 690 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 691 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 692 "data/maps/Route116/scripts.pory"
	end
# 693 "data/maps/Route116/scripts.pory"

# 694 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 695 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 696 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 697 "data/maps/Route116/scripts.pory"
	end
# 698 "data/maps/Route116/scripts.pory"

# 699 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 700 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 701 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 702 "data/maps/Route116/scripts.pory"
	end
# 703 "data/maps/Route116/scripts.pory"

# 704 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 705 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 706 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 707 "data/maps/Route116/scripts.pory"
	end
# 708 "data/maps/Route116/scripts.pory"

# 709 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 710 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 711 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 712 "data/maps/Route116/scripts.pory"
	end
# 713 "data/maps/Route116/scripts.pory"

# 714 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 715 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 716 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 717 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 718 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 719 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 720 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 721 "data/maps/Route116/scripts.pory"

# 722 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 723 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 724 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 725 "data/maps/Route116/scripts.pory"

# 726 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 727 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 728 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 729 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 730 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 731 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 732 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 733 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 734 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 735 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 736 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 737 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 738 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 739 "data/maps/Route116/scripts.pory"

# 740 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 741 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 742 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 743 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 744 "data/maps/Route116/scripts.pory"

# 745 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 746 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 747 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 748 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 749 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 750 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 751 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 752 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 753 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 754 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 755 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 756 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 757 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 758 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 759 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 760 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 761 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 762 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 763 "data/maps/Route116/scripts.pory"

# 764 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 765 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 766 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 767 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 768 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 769 "data/maps/Route116/scripts.pory"

# 770 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 771 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 772 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 773 "data/maps/Route116/scripts.pory"

# 774 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 775 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 776 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 777 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 778 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 779 "data/maps/Route116/scripts.pory"

# 780 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 781 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 782 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 783 "data/maps/Route116/scripts.pory"

# 784 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 785 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 786 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 787 "data/maps/Route116/scripts.pory"

# 788 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 789 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 790 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 791 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 792 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 793 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 794 "data/maps/Route116/scripts.pory"

# 795 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 796 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 797 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 798 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 799 "data/maps/Route116/scripts.pory"

# 800 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 801 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 802 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 803 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 804 "data/maps/Route116/scripts.pory"

# 805 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 806 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 807 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 808 "data/maps/Route116/scripts.pory"

# 809 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 810 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 811 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 812 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 813 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 814 "data/maps/Route116/scripts.pory"

# 815 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 816 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 817 "data/maps/Route116/scripts.pory"

# 818 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 819 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 820 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 821 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 822 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 823 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 824 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 825 "data/maps/Route116/scripts.pory"

# 826 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 827 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 828 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 829 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 830 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 831 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 832 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"

Route116_Text_TakingABreak::
# 156 "data/maps/Route116/scripts.pory"
	.string "I'm taking a break from hunting rare\n"
	.string "POKéMON.$"

Route116_Text_ElusiveSkitty::
# 160 "data/maps/Route116/scripts.pory"
	.string "Why does SKITTY have to be so elusive?$"

Route116_Text_WouldYouLikeToBattle::
# 164 "data/maps/Route116/scripts.pory"
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
# 174 "data/maps/Route116/scripts.pory"
	.string "Excellent!\n"
	.string "I won't hold anything back!$"

Route116_Text_RivalDefeated::
# 179 "data/maps/Route116/scripts.pory"
	.string "You really are the real deal, huh?$"

Route116_Text_WeShouldReturnGoods::
# 183 "data/maps/Route116/scripts.pory"
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
# 191 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "We should go return those GOODS\l"
	.string "anyway.\l"
	.string "Come on!$"

Route116_Text_HangingAroundForABit2::
# 197 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "If you change your mind, I'll be hanging\l"
	.string "around here for a bit.$"

Route116_Text_ThisOldManIsUpset::
# 483 "data/maps/Route116/scripts.pory"
	.string "Hey. This old man is super upset!\n"
	.string "I'm trying to calm him down, but…$"

Route116_Text_GoCheckOutTunnel::
# 488 "data/maps/Route116/scripts.pory"
	.string "This guy wants to go save his POKéMON,\n"
	.string "but I'm afraid he's going to hurt\l"
	.string "himself.\l"
	.string "Would you go check out the tunnel?\l"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_StayPutOldMan::
# 494 "data/maps/Route116/scripts.pory"
	.string "Stay put, old man!\n"
	.string "{PLAYER} has got this.$"

Route116_Text_Rival1::
# 499 "data/maps/Route116/scripts.pory"
	.string "Would you go check out the tunnel?\n"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_BrineyStillMad::
# 504 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
	.string "darling PEEKO!\p"
	.string "Wrrrooooooaaaar! PEEKO!$"

Route116_Text_BattleAfterAll::
# 510 "data/maps/Route116/scripts.pory"
	.string "Are you ready to have that battle after\n"
	.string "all?$"
