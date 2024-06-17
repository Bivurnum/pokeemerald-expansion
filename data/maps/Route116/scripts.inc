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
# 25 "data/maps/Route116/scripts.pory"

# 26 "data/maps/Route116/scripts.pory"
Route116_EventScript_SetWandasBoyfriendPos::
# 27 "data/maps/Route116/scripts.pory"
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
# 28 "data/maps/Route116/scripts.pory"
	return
# 29 "data/maps/Route116/scripts.pory"

# 30 "data/maps/Route116/scripts.pory"
Route116_OnLoad:
# 31 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
# 32 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
# 33 "data/maps/Route116/scripts.pory"
	end
# 34 "data/maps/Route116/scripts.pory"

# 35 "data/maps/Route116/scripts.pory"
Route116_OnFrame:
# 36 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 37 "data/maps/Route116/scripts.pory"
	.2byte 0

Route116_EventScript_Rival2::
# 41 "data/maps/Route116/scripts.pory"
	lock
# 42 "data/maps/Route116/scripts.pory"
	faceplayer
# 43 "data/maps/Route116/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route116_EventScript_Rival2_2
# 48 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ElusiveSkitty, MSGBOX_DEFAULT
Route116_EventScript_Rival2_1:
# 50 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Rival2_2:
# 44 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TakingABreak, MSGBOX_DEFAULT
# 45 "data/maps/Route116/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route116_EventScript_Rival2_1


# 62 "data/maps/Route116/scripts.pory"

# 63 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 64 "data/maps/Route116/scripts.pory"
	lock
# 65 "data/maps/Route116/scripts.pory"
	faceplayer
# 66 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 67 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 68 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 69 "data/maps/Route116/scripts.pory"
	release
# 70 "data/maps/Route116/scripts.pory"
	end
# 71 "data/maps/Route116/scripts.pory"

# 72 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 73 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 74 "data/maps/Route116/scripts.pory"
	release
# 75 "data/maps/Route116/scripts.pory"
	end
# 76 "data/maps/Route116/scripts.pory"

# 77 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 78 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 79 "data/maps/Route116/scripts.pory"
	release
# 80 "data/maps/Route116/scripts.pory"
	end
# 81 "data/maps/Route116/scripts.pory"

# 82 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 83 "data/maps/Route116/scripts.pory"
	lock
# 84 "data/maps/Route116/scripts.pory"
	faceplayer
# 85 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 86 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 87 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 88 "data/maps/Route116/scripts.pory"
	end
# 89 "data/maps/Route116/scripts.pory"

# 90 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 91 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 92 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 93 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 94 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 95 "data/maps/Route116/scripts.pory"
	closemessage
# 96 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 97 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 98 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 99 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 100 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 101 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 102 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 103 "data/maps/Route116/scripts.pory"
	release
# 104 "data/maps/Route116/scripts.pory"
	end
# 105 "data/maps/Route116/scripts.pory"

# 106 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 107 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 108 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 109 "data/maps/Route116/scripts.pory"
	return
# 110 "data/maps/Route116/scripts.pory"

# 111 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 112 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 113 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 114 "data/maps/Route116/scripts.pory"
	return
# 115 "data/maps/Route116/scripts.pory"

# 116 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 117 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 118 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 119 "data/maps/Route116/scripts.pory"
	end
# 120 "data/maps/Route116/scripts.pory"

# 121 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 122 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 123 "data/maps/Route116/scripts.pory"
	release
# 124 "data/maps/Route116/scripts.pory"
	end
# 125 "data/maps/Route116/scripts.pory"

# 126 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 127 "data/maps/Route116/scripts.pory"
	walk_left
# 128 "data/maps/Route116/scripts.pory"
	walk_left
# 129 "data/maps/Route116/scripts.pory"
	walk_left
# 130 "data/maps/Route116/scripts.pory"
	walk_left
# 131 "data/maps/Route116/scripts.pory"
	walk_left
# 132 "data/maps/Route116/scripts.pory"
	walk_left
# 133 "data/maps/Route116/scripts.pory"
	walk_left
# 134 "data/maps/Route116/scripts.pory"
	walk_left
# 135 "data/maps/Route116/scripts.pory"
	step_end
# 136 "data/maps/Route116/scripts.pory"

# 137 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 138 "data/maps/Route116/scripts.pory"
	walk_down
# 139 "data/maps/Route116/scripts.pory"
	walk_left
# 140 "data/maps/Route116/scripts.pory"
	walk_left
# 141 "data/maps/Route116/scripts.pory"
	walk_left
# 142 "data/maps/Route116/scripts.pory"
	walk_left
# 143 "data/maps/Route116/scripts.pory"
	walk_left
# 144 "data/maps/Route116/scripts.pory"
	walk_left
# 145 "data/maps/Route116/scripts.pory"
	walk_left
# 146 "data/maps/Route116/scripts.pory"
	walk_left
# 147 "data/maps/Route116/scripts.pory"
	walk_left
# 148 "data/maps/Route116/scripts.pory"
	step_end
# 149 "data/maps/Route116/scripts.pory"

# 150 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 151 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 152 "data/maps/Route116/scripts.pory"
	end
# 153 "data/maps/Route116/scripts.pory"

# 154 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 155 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 156 "data/maps/Route116/scripts.pory"
	end
# 157 "data/maps/Route116/scripts.pory"

# 158 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 159 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 160 "data/maps/Route116/scripts.pory"
	end
# 161 "data/maps/Route116/scripts.pory"

# 162 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 163 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 164 "data/maps/Route116/scripts.pory"
	end
# 165 "data/maps/Route116/scripts.pory"

# 166 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 167 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 168 "data/maps/Route116/scripts.pory"
	end

Route116_EventScript_Briney::
# 172 "data/maps/Route116/scripts.pory"
	lock
# 173 "data/maps/Route116/scripts.pory"
	faceplayer
# 174 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 175 "data/maps/Route116/scripts.pory"
	closemessage
# 176 "data/maps/Route116/scripts.pory"
	getplayerxy VAR_0x8001, VAR_0x8002
# 177 "data/maps/Route116/scripts.pory"
	switch VAR_0x8001
# 178 "data/maps/Route116/scripts.pory"
	case 44, Route116_EventScript_Briney_3
# 182 "data/maps/Route116/scripts.pory"
	case 45, Route116_EventScript_Briney_4
Route116_EventScript_Briney_1:
# 187 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Briney_3:
# 179 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave1
# 180 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 181 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1

Route116_EventScript_Briney_4:
# 183 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave2
# 184 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney2
# 185 "data/maps/Route116/scripts.pory"
	waitmovement 0
	goto Route116_EventScript_Briney_1


Route116_EventScript_Rival1::
# 192 "data/maps/Route116/scripts.pory"
	lock
# 193 "data/maps/Route116/scripts.pory"
	faceplayer
# 194 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_Rival1, MSGBOX_DEFAULT
# 195 "data/maps/Route116/scripts.pory"
	closemessage
# 196 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 197 "data/maps/Route116/scripts.pory"
	release
	end


Route116_EventScript_BrineyTrigger0::
# 202 "data/maps/Route116/scripts.pory"
	lockall
# 203 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival0
# 204 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 205 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger1::
# 210 "data/maps/Route116/scripts.pory"
	lockall
# 211 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival1
# 212 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 213 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyTrigger2::
# 218 "data/maps/Route116/scripts.pory"
	lockall
# 219 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route116_Movement_PlayerApproachRival2
# 220 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 221 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_BrineyEvent
	end


Route116_EventScript_BrineyEvent::
# 226 "data/maps/Route116/scripts.pory"
	delay 10
# 227 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 228 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThisOldManIsUpset, MSGBOX_DEFAULT
# 230 "data/maps/Route116/scripts.pory"
	closemessage
# 231 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_FaceRight
# 232 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 233 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyWalkToPlayer
# 234 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 235 "data/maps/Route116/scripts.pory"
	applymovement 11, Common_Movement_BeginTalkLeft
# 236 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 237 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 238 "data/maps/Route116/scripts.pory"
	closemessage
# 239 "data/maps/Route116/scripts.pory"
	applymovement 11, Route116_Movement_BrineyRunToCave
# 240 "data/maps/Route116/scripts.pory"
	applymovement 30, Route116_Movement_RivalChaseBriney
# 241 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 242 "data/maps/Route116/scripts.pory"
	applymovement 30, Common_Movement_BeginTalkDown
# 243 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 244 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 245 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 246 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoCheckOutTunnel, MSGBOX_DEFAULT
# 247 "data/maps/Route116/scripts.pory"
	closemessage
# 248 "data/maps/Route116/scripts.pory"
	turnobject 30, DIR_EAST
# 249 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 250 "data/maps/Route116/scripts.pory"
	releaseall
	return


# 253 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival0:
# 254 "data/maps/Route116/scripts.pory"
	walk_right
# 254 "data/maps/Route116/scripts.pory"
	walk_right
# 255 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 258 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival1:
# 259 "data/maps/Route116/scripts.pory"
	walk_right
# 259 "data/maps/Route116/scripts.pory"
	walk_right
# 260 "data/maps/Route116/scripts.pory"
	walk_up
	step_end

# 263 "data/maps/Route116/scripts.pory"
Route116_Movement_PlayerApproachRival2:
# 264 "data/maps/Route116/scripts.pory"
	walk_right
# 264 "data/maps/Route116/scripts.pory"
	walk_right
# 265 "data/maps/Route116/scripts.pory"
	walk_up
# 265 "data/maps/Route116/scripts.pory"
	walk_up
# 266 "data/maps/Route116/scripts.pory"
	face_up
	step_end

# 269 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyWalkToPlayer:
# 270 "data/maps/Route116/scripts.pory"
	walk_fast_down
	step_end

# 273 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave:
# 274 "data/maps/Route116/scripts.pory"
	walk_fast_up
# 275 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 275 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 275 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 276 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 277 "data/maps/Route116/scripts.pory"
	face_right
# 278 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 279 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 279 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 279 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 280 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 281 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 284 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney:
# 285 "data/maps/Route116/scripts.pory"
	delay_4
# 285 "data/maps/Route116/scripts.pory"
	delay_4
# 285 "data/maps/Route116/scripts.pory"
	delay_4
# 286 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 287 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 287 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 287 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 288 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 289 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 289 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 289 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 290 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 291 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 294 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave1:
# 295 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 295 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 295 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 296 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 297 "data/maps/Route116/scripts.pory"
	delay_8
# 298 "data/maps/Route116/scripts.pory"
	face_right
# 299 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 300 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 300 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 300 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 301 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 302 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 305 "data/maps/Route116/scripts.pory"
Route116_Movement_BrineyRunToCave2:
# 306 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 307 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 307 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 307 "data/maps/Route116/scripts.pory"
	walk_fast_right
# 308 "data/maps/Route116/scripts.pory"
	walk_in_place_faster_up
# 309 "data/maps/Route116/scripts.pory"
	delay_8
# 310 "data/maps/Route116/scripts.pory"
	face_right
# 311 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 312 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 312 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 312 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 313 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 314 "data/maps/Route116/scripts.pory"
	face_down
# 315 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 316 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 317 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 318 "data/maps/Route116/scripts.pory"
	face_left
	step_end

# 321 "data/maps/Route116/scripts.pory"
Route116_Movement_RivalChaseBriney2:
# 322 "data/maps/Route116/scripts.pory"
	delay_4
# 322 "data/maps/Route116/scripts.pory"
	delay_4
# 322 "data/maps/Route116/scripts.pory"
	delay_4
# 323 "data/maps/Route116/scripts.pory"
	jump_in_place_right
# 324 "data/maps/Route116/scripts.pory"
	walk_fast_down
# 325 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 325 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 325 "data/maps/Route116/scripts.pory"
	walk_faster_right
# 326 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 327 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 327 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 328 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 329 "data/maps/Route116/scripts.pory"
	face_down
# 330 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 331 "data/maps/Route116/scripts.pory"
	walk_slow_up
# 332 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 333 "data/maps/Route116/scripts.pory"
	face_right
# 334 "data/maps/Route116/scripts.pory"
	lock_facing_direction
# 335 "data/maps/Route116/scripts.pory"
	walk_slow_left
# 336 "data/maps/Route116/scripts.pory"
	unlock_facing_direction
# 337 "data/maps/Route116/scripts.pory"
	face_right
# 338 "data/maps/Route116/scripts.pory"
	delay_16
	step_end

# 362 "data/maps/Route116/scripts.pory"

# 363 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 364 "data/maps/Route116/scripts.pory"
	lock
# 365 "data/maps/Route116/scripts.pory"
	faceplayer
# 366 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 367 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 368 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 369 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 370 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 371 "data/maps/Route116/scripts.pory"
	release
# 372 "data/maps/Route116/scripts.pory"
	end
# 373 "data/maps/Route116/scripts.pory"

# 374 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 375 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 376 "data/maps/Route116/scripts.pory"
	closemessage
# 377 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 378 "data/maps/Route116/scripts.pory"
	end
# 379 "data/maps/Route116/scripts.pory"

# 380 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 381 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 382 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 383 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 384 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 385 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 386 "data/maps/Route116/scripts.pory"
	release
# 387 "data/maps/Route116/scripts.pory"
	end
# 388 "data/maps/Route116/scripts.pory"

# 389 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 390 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 391 "data/maps/Route116/scripts.pory"
	closemessage
# 392 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 393 "data/maps/Route116/scripts.pory"
	end
# 394 "data/maps/Route116/scripts.pory"

# 395 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 396 "data/maps/Route116/scripts.pory"
	delay 20
# 397 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 398 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 399 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 400 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 401 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 402 "data/maps/Route116/scripts.pory"
	release
# 403 "data/maps/Route116/scripts.pory"
	end
# 404 "data/maps/Route116/scripts.pory"

# 405 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 406 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 407 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 408 "data/maps/Route116/scripts.pory"
	return
# 409 "data/maps/Route116/scripts.pory"

# 410 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 411 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 412 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 413 "data/maps/Route116/scripts.pory"
	return
# 414 "data/maps/Route116/scripts.pory"

# 415 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
# 416 "data/maps/Route116/scripts.pory"
	walk_left
# 417 "data/maps/Route116/scripts.pory"
	walk_left
# 418 "data/maps/Route116/scripts.pory"
	walk_left
# 419 "data/maps/Route116/scripts.pory"
	walk_left
# 420 "data/maps/Route116/scripts.pory"
	walk_left
# 421 "data/maps/Route116/scripts.pory"
	walk_left
# 422 "data/maps/Route116/scripts.pory"
	walk_left
# 423 "data/maps/Route116/scripts.pory"
	walk_left
# 424 "data/maps/Route116/scripts.pory"
	walk_left
# 425 "data/maps/Route116/scripts.pory"
	step_end
# 426 "data/maps/Route116/scripts.pory"

# 427 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 428 "data/maps/Route116/scripts.pory"
	walk_up
# 429 "data/maps/Route116/scripts.pory"
	walk_left
# 430 "data/maps/Route116/scripts.pory"
	walk_left
# 431 "data/maps/Route116/scripts.pory"
	walk_left
# 432 "data/maps/Route116/scripts.pory"
	walk_left
# 433 "data/maps/Route116/scripts.pory"
	walk_left
# 434 "data/maps/Route116/scripts.pory"
	walk_left
# 435 "data/maps/Route116/scripts.pory"
	walk_left
# 436 "data/maps/Route116/scripts.pory"
	walk_left
# 437 "data/maps/Route116/scripts.pory"
	walk_left
# 438 "data/maps/Route116/scripts.pory"
	step_end
# 439 "data/maps/Route116/scripts.pory"

# 440 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 441 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 442 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 443 "data/maps/Route116/scripts.pory"
	end
# 444 "data/maps/Route116/scripts.pory"

# 445 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 446 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 447 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 448 "data/maps/Route116/scripts.pory"
	end
# 449 "data/maps/Route116/scripts.pory"

# 450 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 451 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 452 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 453 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 454 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 455 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 456 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 457 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 458 "data/maps/Route116/scripts.pory"
	release
# 459 "data/maps/Route116/scripts.pory"
	end
# 460 "data/maps/Route116/scripts.pory"

# 461 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 462 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 463 "data/maps/Route116/scripts.pory"
	release
# 464 "data/maps/Route116/scripts.pory"
	end
# 465 "data/maps/Route116/scripts.pory"

# 466 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 467 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 468 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 469 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 470 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 471 "data/maps/Route116/scripts.pory"
	release
# 472 "data/maps/Route116/scripts.pory"
	end
# 473 "data/maps/Route116/scripts.pory"

# 474 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 475 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 476 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 477 "data/maps/Route116/scripts.pory"
	release
# 478 "data/maps/Route116/scripts.pory"
	end
# 479 "data/maps/Route116/scripts.pory"

# 480 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 481 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 482 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 483 "data/maps/Route116/scripts.pory"
	release
# 484 "data/maps/Route116/scripts.pory"
	end
# 485 "data/maps/Route116/scripts.pory"

# 486 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 487 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 488 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 489 "data/maps/Route116/scripts.pory"
	end
# 490 "data/maps/Route116/scripts.pory"

# 491 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 492 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 493 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 494 "data/maps/Route116/scripts.pory"
	end
# 495 "data/maps/Route116/scripts.pory"

# 496 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 497 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 498 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 499 "data/maps/Route116/scripts.pory"
	end
# 500 "data/maps/Route116/scripts.pory"

# 501 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 502 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 503 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 504 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 505 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 506 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 507 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 508 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 509 "data/maps/Route116/scripts.pory"
	release
# 510 "data/maps/Route116/scripts.pory"
	end
# 511 "data/maps/Route116/scripts.pory"

# 512 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 513 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 514 "data/maps/Route116/scripts.pory"
	release
# 515 "data/maps/Route116/scripts.pory"
	end
# 516 "data/maps/Route116/scripts.pory"

# 517 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 518 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 519 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 520 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 521 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 522 "data/maps/Route116/scripts.pory"
	release
# 523 "data/maps/Route116/scripts.pory"
	end
# 524 "data/maps/Route116/scripts.pory"

# 525 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 526 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 527 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 528 "data/maps/Route116/scripts.pory"
	release
# 529 "data/maps/Route116/scripts.pory"
	end
# 530 "data/maps/Route116/scripts.pory"

# 531 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 532 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 533 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 534 "data/maps/Route116/scripts.pory"
	release
# 535 "data/maps/Route116/scripts.pory"
	end
# 536 "data/maps/Route116/scripts.pory"

# 537 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 538 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 539 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 540 "data/maps/Route116/scripts.pory"
	end
# 541 "data/maps/Route116/scripts.pory"

# 542 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 543 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 544 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 545 "data/maps/Route116/scripts.pory"
	end
# 546 "data/maps/Route116/scripts.pory"

# 547 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 548 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 549 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 550 "data/maps/Route116/scripts.pory"
	end
# 551 "data/maps/Route116/scripts.pory"

# 552 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 553 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 554 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 555 "data/maps/Route116/scripts.pory"
	end
# 556 "data/maps/Route116/scripts.pory"

# 557 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 558 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 559 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 560 "data/maps/Route116/scripts.pory"
	end
# 561 "data/maps/Route116/scripts.pory"

# 562 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 563 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 564 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 565 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 566 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 567 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 568 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 569 "data/maps/Route116/scripts.pory"

# 570 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 571 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 572 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 573 "data/maps/Route116/scripts.pory"

# 574 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 575 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 576 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 577 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 578 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 579 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 580 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 581 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 582 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 583 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 584 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 585 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 586 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 587 "data/maps/Route116/scripts.pory"

# 588 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 589 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 590 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 591 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 592 "data/maps/Route116/scripts.pory"

# 593 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 594 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 595 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 596 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 597 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 598 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 599 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 600 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 601 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 602 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 603 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 604 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 605 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 606 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 607 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 608 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 609 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 610 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 611 "data/maps/Route116/scripts.pory"

# 612 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 613 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 614 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 615 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 616 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 617 "data/maps/Route116/scripts.pory"

# 618 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 619 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 620 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 621 "data/maps/Route116/scripts.pory"

# 622 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 623 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 624 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 625 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 626 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 627 "data/maps/Route116/scripts.pory"

# 628 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 629 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 630 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 631 "data/maps/Route116/scripts.pory"

# 632 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 633 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 634 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 635 "data/maps/Route116/scripts.pory"

# 636 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 637 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 638 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 639 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 640 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 641 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 642 "data/maps/Route116/scripts.pory"

# 643 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 644 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 645 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 646 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 647 "data/maps/Route116/scripts.pory"

# 648 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 649 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 650 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 651 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 652 "data/maps/Route116/scripts.pory"

# 653 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 654 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 655 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 656 "data/maps/Route116/scripts.pory"

# 657 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 658 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 659 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 660 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 661 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 662 "data/maps/Route116/scripts.pory"

# 663 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 664 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 665 "data/maps/Route116/scripts.pory"

# 666 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 667 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 668 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 669 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 670 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 671 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 672 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 673 "data/maps/Route116/scripts.pory"

# 674 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 675 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 676 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 677 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 678 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 679 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 680 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"

Route116_Text_TakingABreak::
# 54 "data/maps/Route116/scripts.pory"
	.string "I'm taking a break from hunting rare\n"
	.string "POKéMON.$"

Route116_Text_ElusiveSkitty::
# 58 "data/maps/Route116/scripts.pory"
	.string "Why does SKITTY have to be so elusive?$"

Route116_Text_ThisOldManIsUpset::
# 341 "data/maps/Route116/scripts.pory"
	.string "Hey. This old man is super upset!\n"
	.string "I'm trying to calm him down, but…$"

Route116_Text_GoCheckOutTunnel::
# 346 "data/maps/Route116/scripts.pory"
	.string "This guy wants to go save his POKéMON,\n"
	.string "but I'm afraid he's going to hurt\l"
	.string "himself.\l"
	.string "Would you go check out the tunnel?\l"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"

Route116_Text_StayPutOldMan::
# 352 "data/maps/Route116/scripts.pory"
	.string "Stay put, old man!\n"
	.string "{PLAYER} has got this.$"

Route116_Text_Rival1::
# 357 "data/maps/Route116/scripts.pory"
	.string "Would you go check out the tunnel?\n"
	.string "I'm going to stay here and try to keep\l"
	.string "the old man calm.$"
