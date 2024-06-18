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
	compare VAR_RUSTBORO_CITY_STATE, 3
	goto_if_eq Route116_EventScript_SetWandasBoyfriendPos_2
# 29 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq Route116_EventScript_SetWandasBoyfriendPos_2
Route116_EventScript_SetWandasBoyfriendPos_1:
	return

Route116_EventScript_SetWandasBoyfriendPos_2:
# 30 "data/maps/Route116/scripts.pory"
	setobjectxyperm 30, 46, 9
	goto Route116_EventScript_SetWandasBoyfriendPos_1


# 35 "data/maps/Route116/scripts.pory"

# 36 "data/maps/Route116/scripts.pory"
Route116_OnLoad:
# 37 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
# 38 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
# 39 "data/maps/Route116/scripts.pory"
	end
# 40 "data/maps/Route116/scripts.pory"

# 41 "data/maps/Route116/scripts.pory"
Route116_OnFrame:
# 42 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 43 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, Route116_EventScript_TalkToRivalAfterAquaBattle
# 44 "data/maps/Route116/scripts.pory"
	.2byte 0

Route116_EventScript_TalkToRivalAfterAquaBattle::
# 48 "data/maps/Route116/scripts.pory"
	goto_if_unset FLAG_HIDE_ROUTE_116_MR_BRINEY, Route116_EventScript_TalkToRivalAfterAquaBattle_2
# 51 "data/maps/Route116/scripts.pory"
	lockall
# 52 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 5
# 53 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 54 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkRight
# 55 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 56 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WouldYouLikeToBattle, MSGBOX_YESNO
# 57 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 58 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_DeclineRivalBattle
	end

Route116_EventScript_TalkToRivalAfterAquaBattle_2:
	end


Route116_EventScript_RivalBattle::
# 63 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WontHoldAnythingBack
# 64 "data/maps/Route116/scripts.pory"
	checkfriendchoice
# 65 "data/maps/Route116/scripts.pory"
	switch VAR_RESULT
# 66 "data/maps/Route116/scripts.pory"
	case SPENCER, Route116_EventScript_RivalBattle_3
# 68 "data/maps/Route116/scripts.pory"
	case BREN, Route116_EventScript_RivalBattle_4
# 70 "data/maps/Route116/scripts.pory"
	case KYLE, Route116_EventScript_RivalBattle_5
Route116_EventScript_RivalBattle_1:
# 73 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MeetYouAtBrineysCottage, MSGBOX_DEFAULT
# 74 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 75 "data/maps/Route116/scripts.pory"
	compare VAR_0x8001, 46
	goto_if_eq Route116_EventScript_RivalBattle_7
# 79 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalLeaveAfterBattle
Route116_EventScript_RivalBattle_6:
# 81 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 82 "data/maps/Route116/scripts.pory"
	removeobject 30
# 83 "data/maps/Route116/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_RIVAL1
# 84 "data/maps/Route116/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
# 85 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_RivalBattle_3:
# 67 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_4:
# 69 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_5:
# 71 "data/maps/Route116/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_ROUTE_116, Route116_Text_RivalDefeated
	goto Route116_EventScript_RivalBattle_1

Route116_EventScript_RivalBattle_7:
# 76 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalLeaveAfterBattle2
	goto Route116_EventScript_RivalBattle_6


Route116_EventScript_DeclineRivalBattle::
# 90 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_HangingAroundForABit, MSGBOX_DEFAULT
# 91 "data/maps/Route116/scripts.pory"
	closemessage
# 92 "data/maps/Route116/scripts.pory"
	releaseall
	end


Route116_EventScript_Rival2::
# 97 "data/maps/Route116/scripts.pory"
	lock
# 98 "data/maps/Route116/scripts.pory"
	faceplayer
# 99 "data/maps/Route116/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route116_EventScript_Rival2_2
# 104 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ElusiveSkitty, MSGBOX_DEFAULT
Route116_EventScript_Rival2_1:
# 106 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Rival2_2:
# 100 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TakingABreak, MSGBOX_DEFAULT
# 101 "data/maps/Route116/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route116_EventScript_Rival2_1


# 110 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle:
# 111 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 111 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 112 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 113 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 116 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalLeaveAfterBattle2:
# 117 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 118 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 118 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 119 "data/maps/Route116/scripts.pory"
	walk_fast_left
# 120 "data/maps/Route116/scripts.pory"
	set_invisible
	step_end

# 168 "data/maps/Route116/scripts.pory"

# 169 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 170 "data/maps/Route116/scripts.pory"
	lock
# 171 "data/maps/Route116/scripts.pory"
	faceplayer
# 172 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 173 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 174 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 175 "data/maps/Route116/scripts.pory"
	release
# 176 "data/maps/Route116/scripts.pory"
	end
# 177 "data/maps/Route116/scripts.pory"

# 178 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 179 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 180 "data/maps/Route116/scripts.pory"
	release
# 181 "data/maps/Route116/scripts.pory"
	end
# 182 "data/maps/Route116/scripts.pory"

# 183 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 184 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 185 "data/maps/Route116/scripts.pory"
	release
# 186 "data/maps/Route116/scripts.pory"
	end
# 187 "data/maps/Route116/scripts.pory"

# 188 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 189 "data/maps/Route116/scripts.pory"
	lock
# 190 "data/maps/Route116/scripts.pory"
	faceplayer
# 191 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 192 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 193 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 194 "data/maps/Route116/scripts.pory"
	end
# 195 "data/maps/Route116/scripts.pory"

# 196 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 197 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 198 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 199 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 200 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 201 "data/maps/Route116/scripts.pory"
	closemessage
# 202 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 203 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 204 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 205 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 206 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 207 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 208 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 209 "data/maps/Route116/scripts.pory"
	release
# 210 "data/maps/Route116/scripts.pory"
	end
# 211 "data/maps/Route116/scripts.pory"

# 212 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 213 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 214 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 215 "data/maps/Route116/scripts.pory"
	return
# 216 "data/maps/Route116/scripts.pory"

# 217 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 218 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 219 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 220 "data/maps/Route116/scripts.pory"
	return
# 221 "data/maps/Route116/scripts.pory"

# 222 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 223 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 224 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 225 "data/maps/Route116/scripts.pory"
	end
# 226 "data/maps/Route116/scripts.pory"

# 227 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 228 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 229 "data/maps/Route116/scripts.pory"
	release
# 230 "data/maps/Route116/scripts.pory"
	end
# 231 "data/maps/Route116/scripts.pory"

# 232 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 233 "data/maps/Route116/scripts.pory"
	walk_left
# 234 "data/maps/Route116/scripts.pory"
	walk_left
# 235 "data/maps/Route116/scripts.pory"
	walk_left
# 236 "data/maps/Route116/scripts.pory"
	walk_left
# 237 "data/maps/Route116/scripts.pory"
	walk_left
# 238 "data/maps/Route116/scripts.pory"
	walk_left
# 239 "data/maps/Route116/scripts.pory"
	walk_left
# 240 "data/maps/Route116/scripts.pory"
	walk_left
# 241 "data/maps/Route116/scripts.pory"
	step_end
# 242 "data/maps/Route116/scripts.pory"

# 243 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 244 "data/maps/Route116/scripts.pory"
	walk_down
# 245 "data/maps/Route116/scripts.pory"
	walk_left
# 246 "data/maps/Route116/scripts.pory"
	walk_left
# 247 "data/maps/Route116/scripts.pory"
	walk_left
# 248 "data/maps/Route116/scripts.pory"
	walk_left
# 249 "data/maps/Route116/scripts.pory"
	walk_left
# 250 "data/maps/Route116/scripts.pory"
	walk_left
# 251 "data/maps/Route116/scripts.pory"
	walk_left
# 252 "data/maps/Route116/scripts.pory"
	walk_left
# 253 "data/maps/Route116/scripts.pory"
	walk_left
# 254 "data/maps/Route116/scripts.pory"
	step_end
# 255 "data/maps/Route116/scripts.pory"

# 256 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 257 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 258 "data/maps/Route116/scripts.pory"
	end
# 259 "data/maps/Route116/scripts.pory"

# 260 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 261 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 262 "data/maps/Route116/scripts.pory"
	end
# 263 "data/maps/Route116/scripts.pory"

# 264 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 265 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 266 "data/maps/Route116/scripts.pory"
	end
# 267 "data/maps/Route116/scripts.pory"

# 268 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 269 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 270 "data/maps/Route116/scripts.pory"
	end
# 271 "data/maps/Route116/scripts.pory"

# 272 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 273 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 274 "data/maps/Route116/scripts.pory"
	end

Route116_EventScript_Briney::
# 278 "data/maps/Route116/scripts.pory"
	lock
# 279 "data/maps/Route116/scripts.pory"
	faceplayer
# 280 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BrineyStillMad, MSGBOX_DEFAULT
# 281 "data/maps/Route116/scripts.pory"
	closemessage
# 282 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 283 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 284 "data/maps/Route116/scripts.pory"
	case 44, Route116_EventScript_Briney_3
# 288 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Briney_4
Route116_EventScript_Briney_1:
# 293 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Briney_3:
# 285 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave1
# 286 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 287 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1

Route116_EventScript_Briney_4:
# 289 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave2
# 290 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney2
# 291 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1


Route116_EventScript_Rival1::
# 298 "data/maps/Route116/scripts.pory"
	lockall
# 299 "data/maps/Route116/scripts.pory"
	faceplayer
# 300 "data/maps/Route116/scripts.pory"
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_eq Route116_EventScript_Rival1_2
Route116_EventScript_Rival1_1:
# 305 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_Rival1, MSGBOX_DEFAULT
# 306 "data/maps/Route116/scripts.pory"
	closemessage
# 307 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 308 "data/maps/Route116/scripts.pory"
	releaseall
	end

Route116_EventScript_Rival1_2:
# 301 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BattleAfterAll, MSGBOX_YESNO
# 302 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route116_EventScript_RivalBattle
# 303 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route116_EventScript_DeclineRivalBattle
	goto Route116_EventScript_Rival1_1


Route116_EventScript_BrineyTrigger0::
# 313 "data/maps/Route116/scripts.pory"
	lockall
# 314 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival0
# 315 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 316 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger1::
# 321 "data/maps/Route116/scripts.pory"
	lockall
# 322 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival1
# 323 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 324 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger2::
# 329 "data/maps/Route116/scripts.pory"
	lockall
# 330 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival2
# 331 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 332 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyEvent::
# 337 "data/maps/Route116/scripts.pory"
	delay 10
# 338 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 339 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 340 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThisOldManIsUpset, MSGBOX_DEFAULT
# 341 "data/maps/Route116/scripts.pory"
	closemessage
# 342 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_FaceRight
# 343 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 344 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyWalkToPlayer
# 345 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 346 "data/maps/Route116/scripts.pory"
	applymovement 11, Common_Movement_BeginTalkLeft
# 347 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 348 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 349 "data/maps/Route116/scripts.pory"
	closemessage
# 350 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave
# 351 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 352 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 353 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 354 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 355 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 356 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 357 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoCheckOutTunnel, MSGBOX_DEFAULT
# 358 "data/maps/Route116/scripts.pory"
	closemessage
# 359 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 360 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 361 "data/maps/Route116/scripts.pory"
	releaseall
	return


# 364 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival0:
# 365 "data/maps/Route116/scripts.pory"
	walk_right
# 365 "data/maps/Route116/scripts.pory"
	walk_right
# 366 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 369 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival1:
# 370 "data/maps/Route116/scripts.pory"
	walk_right
# 370 "data/maps/Route116/scripts.pory"
	walk_right
# 371 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 374 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival2:
# 375 "data/maps/Route116/scripts.pory"
	walk_right
# 375 "data/maps/Route116/scripts.pory"
	walk_right
# 376 "data/maps/Route116/scripts.pory"
	walk_up
# 376 "data/maps/Route116/scripts.pory"
	walk_up
# 377 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 380 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyWalkToPlayer:
# 381 "data/maps/Route116/scripts.pory"
	walk_fast_down
	step_end

# 384 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave:
# 385 "data/maps/Route116/scripts.pory"
	walk_fast_up
# 386 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 386 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 386 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 387 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 388 "data/maps/Route116/scripts.pory"
	face_right
# 389 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 390 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 390 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 390 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 391 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 392 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 395 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney:
# 396 "data/maps/Route116/scripts.pory"
	delay_4
# 396 "data/maps/Route116/scripts.pory"
	delay_4
# 396 "data/maps/Route116/scripts.pory"
	delay_4
# 397 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 398 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 398 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 398 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 399 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 400 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 400 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 400 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 401 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 402 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 405 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave1:
# 406 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 406 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 406 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 407 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 408 "data/maps/Route116/scripts.pory"
	delay_8
# 409 "data/maps/Route116/scripts.pory"
	face_right
# 410 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 411 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 411 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 411 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 412 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 413 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 416 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave2:
# 417 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 418 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 418 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 418 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 419 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 420 "data/maps/Route116/scripts.pory"
	delay_8
# 421 "data/maps/Route116/scripts.pory"
	face_right
# 422 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 423 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 423 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 423 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 424 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 425 "data/maps/Route116/scripts.pory"
	face_down
# 426 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 427 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 428 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 429 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 432 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney2:
# 433 "data/maps/Route116/scripts.pory"
	delay_4
# 433 "data/maps/Route116/scripts.pory"
	delay_4
# 433 "data/maps/Route116/scripts.pory"
	delay_4
# 434 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 435 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 436 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 436 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 436 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 437 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 438 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 438 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 439 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 440 "data/maps/Route116/scripts.pory"
	face_down
# 441 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 442 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 443 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 444 "data/maps/Route116/scripts.pory"
	face_right
# 445 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 446 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 447 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 448 "data/maps/Route116/scripts.pory"
	face_right
# 449 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 483 "data/maps/Route116/scripts.pory"

# 484 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 485 "data/maps/Route116/scripts.pory"
	lock
# 486 "data/maps/Route116/scripts.pory"
	faceplayer
# 487 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 488 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 489 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 490 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 491 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 492 "data/maps/Route116/scripts.pory"
	release
# 493 "data/maps/Route116/scripts.pory"
	end
# 494 "data/maps/Route116/scripts.pory"

# 495 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 496 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 497 "data/maps/Route116/scripts.pory"
	closemessage
# 498 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 499 "data/maps/Route116/scripts.pory"
	end
# 500 "data/maps/Route116/scripts.pory"

# 501 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 502 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 503 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 504 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 505 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 506 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 507 "data/maps/Route116/scripts.pory"
	release
# 508 "data/maps/Route116/scripts.pory"
	end
# 509 "data/maps/Route116/scripts.pory"

# 510 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 511 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 512 "data/maps/Route116/scripts.pory"
	closemessage
# 513 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 514 "data/maps/Route116/scripts.pory"
	end
# 515 "data/maps/Route116/scripts.pory"

# 516 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 517 "data/maps/Route116/scripts.pory"
	delay 20
# 518 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 519 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 520 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 521 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 522 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 523 "data/maps/Route116/scripts.pory"
	release
# 524 "data/maps/Route116/scripts.pory"
	end
# 525 "data/maps/Route116/scripts.pory"

# 526 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 527 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 528 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 529 "data/maps/Route116/scripts.pory"
	return
# 530 "data/maps/Route116/scripts.pory"

# 531 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 532 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 533 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 534 "data/maps/Route116/scripts.pory"
	return
# 535 "data/maps/Route116/scripts.pory"

# 536 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
# 537 "data/maps/Route116/scripts.pory"
	walk_left
# 538 "data/maps/Route116/scripts.pory"
	walk_left
# 539 "data/maps/Route116/scripts.pory"
	walk_left
# 540 "data/maps/Route116/scripts.pory"
	walk_left
# 541 "data/maps/Route116/scripts.pory"
	walk_left
# 542 "data/maps/Route116/scripts.pory"
	walk_left
# 543 "data/maps/Route116/scripts.pory"
	walk_left
# 544 "data/maps/Route116/scripts.pory"
	walk_left
# 545 "data/maps/Route116/scripts.pory"
	walk_left
# 546 "data/maps/Route116/scripts.pory"
	step_end
# 547 "data/maps/Route116/scripts.pory"

# 548 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 549 "data/maps/Route116/scripts.pory"
	walk_up
# 550 "data/maps/Route116/scripts.pory"
	walk_left
# 551 "data/maps/Route116/scripts.pory"
	walk_left
# 552 "data/maps/Route116/scripts.pory"
	walk_left
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
	step_end
# 560 "data/maps/Route116/scripts.pory"

# 561 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 562 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 563 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 564 "data/maps/Route116/scripts.pory"
	end
# 565 "data/maps/Route116/scripts.pory"

# 566 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 567 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 568 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 569 "data/maps/Route116/scripts.pory"
	end
# 570 "data/maps/Route116/scripts.pory"

# 571 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 572 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 573 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 574 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 575 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 576 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 577 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 578 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 579 "data/maps/Route116/scripts.pory"
	release
# 580 "data/maps/Route116/scripts.pory"
	end
# 581 "data/maps/Route116/scripts.pory"

# 582 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 583 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 584 "data/maps/Route116/scripts.pory"
	release
# 585 "data/maps/Route116/scripts.pory"
	end
# 586 "data/maps/Route116/scripts.pory"

# 587 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 588 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 589 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 590 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 591 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 592 "data/maps/Route116/scripts.pory"
	release
# 593 "data/maps/Route116/scripts.pory"
	end
# 594 "data/maps/Route116/scripts.pory"

# 595 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 596 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 597 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 598 "data/maps/Route116/scripts.pory"
	release
# 599 "data/maps/Route116/scripts.pory"
	end
# 600 "data/maps/Route116/scripts.pory"

# 601 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 602 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 603 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 604 "data/maps/Route116/scripts.pory"
	release
# 605 "data/maps/Route116/scripts.pory"
	end
# 606 "data/maps/Route116/scripts.pory"

# 607 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 608 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 609 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 610 "data/maps/Route116/scripts.pory"
	end
# 611 "data/maps/Route116/scripts.pory"

# 612 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 613 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 614 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 615 "data/maps/Route116/scripts.pory"
	end
# 616 "data/maps/Route116/scripts.pory"

# 617 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 618 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 619 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 620 "data/maps/Route116/scripts.pory"
	end
# 621 "data/maps/Route116/scripts.pory"

# 622 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 623 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 624 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 625 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 626 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 627 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 628 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 629 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 630 "data/maps/Route116/scripts.pory"
	release
# 631 "data/maps/Route116/scripts.pory"
	end
# 632 "data/maps/Route116/scripts.pory"

# 633 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 634 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 635 "data/maps/Route116/scripts.pory"
	release
# 636 "data/maps/Route116/scripts.pory"
	end
# 637 "data/maps/Route116/scripts.pory"

# 638 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 639 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 640 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 641 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 642 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 643 "data/maps/Route116/scripts.pory"
	release
# 644 "data/maps/Route116/scripts.pory"
	end
# 645 "data/maps/Route116/scripts.pory"

# 646 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 647 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 648 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 649 "data/maps/Route116/scripts.pory"
	release
# 650 "data/maps/Route116/scripts.pory"
	end
# 651 "data/maps/Route116/scripts.pory"

# 652 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 653 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 654 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 655 "data/maps/Route116/scripts.pory"
	release
# 656 "data/maps/Route116/scripts.pory"
	end
# 657 "data/maps/Route116/scripts.pory"

# 658 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 659 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 660 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 661 "data/maps/Route116/scripts.pory"
	end
# 662 "data/maps/Route116/scripts.pory"

# 663 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 664 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 665 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 666 "data/maps/Route116/scripts.pory"
	end
# 667 "data/maps/Route116/scripts.pory"

# 668 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 669 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 670 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 671 "data/maps/Route116/scripts.pory"
	end
# 672 "data/maps/Route116/scripts.pory"

# 673 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 674 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 675 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 676 "data/maps/Route116/scripts.pory"
	end
# 677 "data/maps/Route116/scripts.pory"

# 678 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 679 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 680 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 681 "data/maps/Route116/scripts.pory"
	end
# 682 "data/maps/Route116/scripts.pory"

# 683 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 684 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 685 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 686 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 687 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 688 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 689 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 690 "data/maps/Route116/scripts.pory"

# 691 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 692 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 693 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 694 "data/maps/Route116/scripts.pory"

# 695 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 696 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 697 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 698 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 699 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 700 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 701 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 702 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 703 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 704 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 705 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 706 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 707 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 708 "data/maps/Route116/scripts.pory"

# 709 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 710 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 711 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 712 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 713 "data/maps/Route116/scripts.pory"

# 714 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 715 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 716 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 717 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 718 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 719 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 720 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 721 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 722 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 723 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 724 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 725 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 726 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 727 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 728 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 729 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 730 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 731 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 732 "data/maps/Route116/scripts.pory"

# 733 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 734 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 735 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 736 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 737 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 738 "data/maps/Route116/scripts.pory"

# 739 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 740 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 741 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 742 "data/maps/Route116/scripts.pory"

# 743 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 744 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 745 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 746 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 747 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 748 "data/maps/Route116/scripts.pory"

# 749 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 750 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 751 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 752 "data/maps/Route116/scripts.pory"

# 753 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 754 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 755 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 756 "data/maps/Route116/scripts.pory"

# 757 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 758 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 759 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 760 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 761 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 762 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 763 "data/maps/Route116/scripts.pory"

# 764 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 765 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 766 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 767 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 768 "data/maps/Route116/scripts.pory"

# 769 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 770 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 771 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 772 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 773 "data/maps/Route116/scripts.pory"

# 774 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 775 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 776 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 777 "data/maps/Route116/scripts.pory"

# 778 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 779 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 780 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 781 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 782 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 783 "data/maps/Route116/scripts.pory"

# 784 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 785 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 786 "data/maps/Route116/scripts.pory"

# 787 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 788 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 789 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 790 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 791 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 792 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 793 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 794 "data/maps/Route116/scripts.pory"

# 795 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 796 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 797 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 798 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 799 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 800 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 801 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"

Route116_Text_TakingABreak::
# 123 "data/maps/Route116/scripts.pory"
	.string "I'm taking a break from hunting rare\n"
	.string "POKéMON.$"

Route116_Text_ElusiveSkitty::
# 127 "data/maps/Route116/scripts.pory"
	.string "Why does SKITTY have to be so elusive?$"

Route116_Text_WouldYouLikeToBattle::
# 131 "data/maps/Route116/scripts.pory"
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
# 141 "data/maps/Route116/scripts.pory"
	.string "Excellent!\n"
	.string "I won't hold anything back!$"

Route116_Text_RivalDefeated::
# 146 "data/maps/Route116/scripts.pory"
	.string "You really are the real deal, huh?$"

Route116_Text_MeetYouAtBrineysCottage::
# 150 "data/maps/Route116/scripts.pory"
	.string "You've certainly gotten stronger, but I\n"
	.string "got some licks in!\l"
	.string "I thought since I beat ROXANNE that I\l"
	.string "would have an easier time against you,\l"
	.string "though.\l"
	.string "But I suppose I should've expected it,\l"
	.string "since you've obviously beaten her too.\p"
	.string "Well, I suppose we should make our way\n"
	.string "to the next GYM. I hear it's in an island\l"
	.string "town called DEWFORD, but I don't have\l"
	.string "the slightest idea how we are going to\l"
	.string "get there.\l"
	.string "Maybe MR. BRINEY can help us.\l"
	.string "It can't hurt to ask.\p"
	.string "I'll meet you at his cottage!$"

Route116_Text_HangingAroundForABit::
# 161 "data/maps/Route116/scripts.pory"
	.string "No big deal.\n"
	.string "If you change your mind, I'll be hanging\l"
	.string "around here for a bit.\l"
	.string "I'm sure {RIVAL2} has gotten his hands on a\l"
	.string "SKITTY for his POKéDEX already.\l"
	.string "I can't let him beat me!$"

Route116_Text_ThisOldManIsUpset::
# 452 "data/maps/Route116/scripts.pory"
	.string "Hey. This old man is super upset!\n"
	.string "I'm trying to calm him down, but…$"

Route116_Text_GoCheckOutTunnel::
# 457 "data/maps/Route116/scripts.pory"
	.string "This guy wants to go save his POKéMON,\n"
	.string "but I'm afraid he's going to hurt\l"
	.string "himself.\l"
	.string "Would you go check out the tunnel?\l"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_StayPutOldMan::
# 463 "data/maps/Route116/scripts.pory"
	.string "Stay put, old man!\n"
	.string "{PLAYER} has got this.$"

Route116_Text_Rival1::
# 468 "data/maps/Route116/scripts.pory"
	.string "Would you go check out the tunnel?\n"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_BrineyStillMad::
# 473 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
	.string "darling PEEKO!\p"
	.string "Wrrrooooooaaaar! PEEKO!$"

Route116_Text_BattleAfterAll::
# 479 "data/maps/Route116/scripts.pory"
	.string "Are you ready to have that battle after\n"
	.string "all?$"
