# 1 "data/maps/Route116/scripts.pory"

# 2 "data/maps/Route116/scripts.pory"
.set LOCALID_BRINEY, 11
# 3 "data/maps/Route116/scripts.pory"
.set LOCALID_WANDAS_BF_OUTSIDE, 21
# 4 "data/maps/Route116/scripts.pory"
.set LOCALID_RIVAL2, 29
# 5 "data/maps/Route116/scripts.pory"

# 6 "data/maps/Route116/scripts.pory"
Route116_MapScripts::
# 7 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
# 8 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
# 9 "data/maps/Route116/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
# 10 "data/maps/Route116/scripts.pory"
	.byte 0
# 11 "data/maps/Route116/scripts.pory"

# 12 "data/maps/Route116/scripts.pory"
Route116_OnTransition:
# 13 "data/maps/Route116/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 14 "data/maps/Route116/scripts.pory"
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
# 15 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 16 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
# 17 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
# 18 "data/maps/Route116/scripts.pory"
	end
# 19 "data/maps/Route116/scripts.pory"

# 20 "data/maps/Route116/scripts.pory"
Route116_EventScript_SetWandasBoyfriendPos::
# 21 "data/maps/Route116/scripts.pory"
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
# 22 "data/maps/Route116/scripts.pory"
	return
# 23 "data/maps/Route116/scripts.pory"

# 24 "data/maps/Route116/scripts.pory"
Route116_OnLoad:
# 25 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
# 26 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
# 27 "data/maps/Route116/scripts.pory"
	end
# 28 "data/maps/Route116/scripts.pory"

# 29 "data/maps/Route116/scripts.pory"
Route116_OnFrame:
# 30 "data/maps/Route116/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 31 "data/maps/Route116/scripts.pory"
	.2byte 0

Route116_EventScript_Rival2::
# 35 "data/maps/Route116/scripts.pory"
	lock
# 36 "data/maps/Route116/scripts.pory"
	faceplayer
# 37 "data/maps/Route116/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route116_EventScript_Rival2_2
# 42 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ElusiveSkitty, MSGBOX_DEFAULT
Route116_EventScript_Rival2_1:
# 44 "data/maps/Route116/scripts.pory"
	release
	end

Route116_EventScript_Rival2_2:
# 38 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TakingABreak, MSGBOX_DEFAULT
# 39 "data/maps/Route116/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route116_EventScript_Rival2_1


# 56 "data/maps/Route116/scripts.pory"

# 57 "data/maps/Route116/scripts.pory"
Route116_EventScript_WandasBoyfriend::
# 58 "data/maps/Route116/scripts.pory"
	lock
# 59 "data/maps/Route116/scripts.pory"
	faceplayer
# 60 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
# 61 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
# 62 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
# 63 "data/maps/Route116/scripts.pory"
	release
# 64 "data/maps/Route116/scripts.pory"
	end
# 65 "data/maps/Route116/scripts.pory"

# 66 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntLeftTunnel::
# 67 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
# 68 "data/maps/Route116/scripts.pory"
	release
# 69 "data/maps/Route116/scripts.pory"
	end
# 70 "data/maps/Route116/scripts.pory"

# 71 "data/maps/Route116/scripts.pory"
Route116_EventScript_BoyfriendGruntInTunnel::
# 72 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
# 73 "data/maps/Route116/scripts.pory"
	release
# 74 "data/maps/Route116/scripts.pory"
	end
# 75 "data/maps/Route116/scripts.pory"

# 76 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployee::
# 77 "data/maps/Route116/scripts.pory"
	lock
# 78 "data/maps/Route116/scripts.pory"
	faceplayer
# 79 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
# 80 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
# 81 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 82 "data/maps/Route116/scripts.pory"
	end
# 83 "data/maps/Route116/scripts.pory"

# 84 "data/maps/Route116/scripts.pory"
Route116_EventScript_GiveRepeatBall::
# 85 "data/maps/Route116/scripts.pory"
	setflag FLAG_MET_DEVON_EMPLOYEE
# 86 "data/maps/Route116/scripts.pory"
	giveitem ITEM_REPEAT_BALL
# 87 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
# 88 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
# 89 "data/maps/Route116/scripts.pory"
	closemessage
# 90 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
# 91 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
# 92 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
# 93 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
# 94 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 95 "data/maps/Route116/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
# 96 "data/maps/Route116/scripts.pory"
	setflag FLAG_RECEIVED_REPEAT_BALL
# 97 "data/maps/Route116/scripts.pory"
	release
# 98 "data/maps/Route116/scripts.pory"
	end
# 99 "data/maps/Route116/scripts.pory"

# 100 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExit::
# 101 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
# 102 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 103 "data/maps/Route116/scripts.pory"
	return
# 104 "data/maps/Route116/scripts.pory"

# 105 "data/maps/Route116/scripts.pory"
Route116_EventScript_DevonEmployeeExitEast::
# 106 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
# 107 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 108 "data/maps/Route116/scripts.pory"
	return
# 109 "data/maps/Route116/scripts.pory"

# 110 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryGiveRepeatBallAgain::
# 111 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
# 112 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GiveRepeatBall
# 113 "data/maps/Route116/scripts.pory"
	end
# 114 "data/maps/Route116/scripts.pory"

# 115 "data/maps/Route116/scripts.pory"
Route116_EventScript_NoRoomForRepeatBall::
# 116 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
# 117 "data/maps/Route116/scripts.pory"
	release
# 118 "data/maps/Route116/scripts.pory"
	end
# 119 "data/maps/Route116/scripts.pory"

# 120 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExit:
# 121 "data/maps/Route116/scripts.pory"
	walk_left
# 122 "data/maps/Route116/scripts.pory"
	walk_left
# 123 "data/maps/Route116/scripts.pory"
	walk_left
# 124 "data/maps/Route116/scripts.pory"
	walk_left
# 125 "data/maps/Route116/scripts.pory"
	walk_left
# 126 "data/maps/Route116/scripts.pory"
	walk_left
# 127 "data/maps/Route116/scripts.pory"
	walk_left
# 128 "data/maps/Route116/scripts.pory"
	walk_left
# 129 "data/maps/Route116/scripts.pory"
	step_end
# 130 "data/maps/Route116/scripts.pory"

# 131 "data/maps/Route116/scripts.pory"
Route116_Movement_DevonEmployeeExitEast:
# 132 "data/maps/Route116/scripts.pory"
	walk_down
# 133 "data/maps/Route116/scripts.pory"
	walk_left
# 134 "data/maps/Route116/scripts.pory"
	walk_left
# 135 "data/maps/Route116/scripts.pory"
	walk_left
# 136 "data/maps/Route116/scripts.pory"
	walk_left
# 137 "data/maps/Route116/scripts.pory"
	walk_left
# 138 "data/maps/Route116/scripts.pory"
	walk_left
# 139 "data/maps/Route116/scripts.pory"
	walk_left
# 140 "data/maps/Route116/scripts.pory"
	walk_left
# 141 "data/maps/Route116/scripts.pory"
	walk_left
# 142 "data/maps/Route116/scripts.pory"
	step_end
# 143 "data/maps/Route116/scripts.pory"

# 144 "data/maps/Route116/scripts.pory"
Route116_EventScript_RouteSignRustboro::
# 145 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
# 146 "data/maps/Route116/scripts.pory"
	end
# 147 "data/maps/Route116/scripts.pory"

# 148 "data/maps/Route116/scripts.pory"
Route116_EventScript_RusturfTunnelSign::
# 149 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
# 150 "data/maps/Route116/scripts.pory"
	end
# 151 "data/maps/Route116/scripts.pory"

# 152 "data/maps/Route116/scripts.pory"
Route116_EventScript_TunnelersRestHouseSign::
# 153 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
# 154 "data/maps/Route116/scripts.pory"
	end
# 155 "data/maps/Route116/scripts.pory"

# 156 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBToStopEvolution::
# 157 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
# 158 "data/maps/Route116/scripts.pory"
	end
# 159 "data/maps/Route116/scripts.pory"

# 160 "data/maps/Route116/scripts.pory"
Route116_EventScript_TrainerTipsBagHasPockets::
# 161 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
# 162 "data/maps/Route116/scripts.pory"
	end
# 163 "data/maps/Route116/scripts.pory"

# 164 "data/maps/Route116/scripts.pory"
Route116_EventScript_Briney::
# 165 "data/maps/Route116/scripts.pory"
	lock
# 166 "data/maps/Route116/scripts.pory"
	faceplayer
# 167 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 168 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 169 "data/maps/Route116/scripts.pory"
	release
# 170 "data/maps/Route116/scripts.pory"
	end
# 171 "data/maps/Route116/scripts.pory"

# 172 "data/maps/Route116/scripts.pory"
Route116_EventScript_BrineyTrigger::
# 173 "data/maps/Route116/scripts.pory"
	lockall
# 174 "data/maps/Route116/scripts.pory"
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterRight
# 175 "data/maps/Route116/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 176 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 177 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
# 178 "data/maps/Route116/scripts.pory"
	setvar VAR_ROUTE116_STATE, 2
# 179 "data/maps/Route116/scripts.pory"
	releaseall
# 180 "data/maps/Route116/scripts.pory"
	end
# 181 "data/maps/Route116/scripts.pory"

# 182 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesMan::
# 183 "data/maps/Route116/scripts.pory"
	lock
# 184 "data/maps/Route116/scripts.pory"
	faceplayer
# 185 "data/maps/Route116/scripts.pory"
	checkitem ITEM_BLACK_GLASSES
# 186 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
# 187 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 188 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
# 189 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 190 "data/maps/Route116/scripts.pory"
	release
# 191 "data/maps/Route116/scripts.pory"
	end
# 192 "data/maps/Route116/scripts.pory"

# 193 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesNotOnPlayer::
# 194 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
# 195 "data/maps/Route116/scripts.pory"
	closemessage
# 196 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 197 "data/maps/Route116/scripts.pory"
	end
# 198 "data/maps/Route116/scripts.pory"

# 199 "data/maps/Route116/scripts.pory"
Route116_EventScript_PlayerHasGlasses::
# 200 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
# 201 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
# 202 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, FoundBlackGlasses
# 203 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
# 204 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
# 205 "data/maps/Route116/scripts.pory"
	release
# 206 "data/maps/Route116/scripts.pory"
	end
# 207 "data/maps/Route116/scripts.pory"

# 208 "data/maps/Route116/scripts.pory"
Route116_EventScript_FoundGlassesOnPlayer::
# 209 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
# 210 "data/maps/Route116/scripts.pory"
	closemessage
# 211 "data/maps/Route116/scripts.pory"
	goto Route116_EventScript_GlassesManExit
# 212 "data/maps/Route116/scripts.pory"
	end
# 213 "data/maps/Route116/scripts.pory"

# 214 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExit::
# 215 "data/maps/Route116/scripts.pory"
	delay 20
# 216 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
# 217 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
# 218 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
# 219 "data/maps/Route116/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
# 220 "data/maps/Route116/scripts.pory"
	removeobject VAR_LAST_TALKED
# 221 "data/maps/Route116/scripts.pory"
	release
# 222 "data/maps/Route116/scripts.pory"
	end
# 223 "data/maps/Route116/scripts.pory"

# 224 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitNormal::
# 225 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
# 226 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 227 "data/maps/Route116/scripts.pory"
	return
# 228 "data/maps/Route116/scripts.pory"

# 229 "data/maps/Route116/scripts.pory"
Route116_EventScript_GlassesManExitEast::
# 230 "data/maps/Route116/scripts.pory"
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
# 231 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 232 "data/maps/Route116/scripts.pory"
	return
# 233 "data/maps/Route116/scripts.pory"

# 234 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExit:
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
	walk_left
# 242 "data/maps/Route116/scripts.pory"
	walk_left
# 243 "data/maps/Route116/scripts.pory"
	walk_left
# 244 "data/maps/Route116/scripts.pory"
	step_end
# 245 "data/maps/Route116/scripts.pory"

# 246 "data/maps/Route116/scripts.pory"
Route116_Movement_GlassesManExitEast:
# 247 "data/maps/Route116/scripts.pory"
	walk_up
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
	walk_left
# 255 "data/maps/Route116/scripts.pory"
	walk_left
# 256 "data/maps/Route116/scripts.pory"
	walk_left
# 257 "data/maps/Route116/scripts.pory"
	step_end
# 258 "data/maps/Route116/scripts.pory"

# 259 "data/maps/Route116/scripts.pory"
Route116_EventScript_Joey::
# 260 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
# 261 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
# 262 "data/maps/Route116/scripts.pory"
	end
# 263 "data/maps/Route116/scripts.pory"

# 264 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jose::
# 265 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
# 266 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
# 267 "data/maps/Route116/scripts.pory"
	end
# 268 "data/maps/Route116/scripts.pory"

# 269 "data/maps/Route116/scripts.pory"
Route116_EventScript_Jerry::
# 270 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
# 271 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 272 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
# 273 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_JERRY_1
# 274 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 275 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
# 276 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 277 "data/maps/Route116/scripts.pory"
	release
# 278 "data/maps/Route116/scripts.pory"
	end
# 279 "data/maps/Route116/scripts.pory"

# 280 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerryAfterBattle::
# 281 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
# 282 "data/maps/Route116/scripts.pory"
	release
# 283 "data/maps/Route116/scripts.pory"
	end
# 284 "data/maps/Route116/scripts.pory"

# 285 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerryAfterBattle::
# 286 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 287 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 288 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
# 289 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 290 "data/maps/Route116/scripts.pory"
	release
# 291 "data/maps/Route116/scripts.pory"
	end
# 292 "data/maps/Route116/scripts.pory"

# 293 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterJerry::
# 294 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
# 295 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
# 296 "data/maps/Route116/scripts.pory"
	release
# 297 "data/maps/Route116/scripts.pory"
	end
# 298 "data/maps/Route116/scripts.pory"

# 299 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterJerry::
# 300 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
# 301 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_JERRY_1
# 302 "data/maps/Route116/scripts.pory"
	release
# 303 "data/maps/Route116/scripts.pory"
	end
# 304 "data/maps/Route116/scripts.pory"

# 305 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchJerry::
# 306 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
# 307 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
# 308 "data/maps/Route116/scripts.pory"
	end
# 309 "data/maps/Route116/scripts.pory"

# 310 "data/maps/Route116/scripts.pory"
Route116_EventScript_Clark::
# 311 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
# 312 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
# 313 "data/maps/Route116/scripts.pory"
	end
# 314 "data/maps/Route116/scripts.pory"

# 315 "data/maps/Route116/scripts.pory"
Route116_EventScript_Janice::
# 316 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
# 317 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
# 318 "data/maps/Route116/scripts.pory"
	end
# 319 "data/maps/Route116/scripts.pory"

# 320 "data/maps/Route116/scripts.pory"
Route116_EventScript_Karen::
# 321 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
# 322 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 323 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
# 324 "data/maps/Route116/scripts.pory"
	setvar VAR_0x8004, TRAINER_KAREN_1
# 325 "data/maps/Route116/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 326 "data/maps/Route116/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
# 327 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 328 "data/maps/Route116/scripts.pory"
	release
# 329 "data/maps/Route116/scripts.pory"
	end
# 330 "data/maps/Route116/scripts.pory"

# 331 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKarenAfterBattle::
# 332 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
# 333 "data/maps/Route116/scripts.pory"
	release
# 334 "data/maps/Route116/scripts.pory"
	end
# 335 "data/maps/Route116/scripts.pory"

# 336 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKarenAfterBattle::
# 337 "data/maps/Route116/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 338 "data/maps/Route116/scripts.pory"
	waitmovement 0
# 339 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
# 340 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 341 "data/maps/Route116/scripts.pory"
	release
# 342 "data/maps/Route116/scripts.pory"
	end
# 343 "data/maps/Route116/scripts.pory"

# 344 "data/maps/Route116/scripts.pory"
Route116_EventScript_TryRegisterKaren::
# 345 "data/maps/Route116/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
# 346 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
# 347 "data/maps/Route116/scripts.pory"
	release
# 348 "data/maps/Route116/scripts.pory"
	end
# 349 "data/maps/Route116/scripts.pory"

# 350 "data/maps/Route116/scripts.pory"
Route116_EventScript_RegisterKaren::
# 351 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
# 352 "data/maps/Route116/scripts.pory"
	register_matchcall TRAINER_KAREN_1
# 353 "data/maps/Route116/scripts.pory"
	release
# 354 "data/maps/Route116/scripts.pory"
	end
# 355 "data/maps/Route116/scripts.pory"

# 356 "data/maps/Route116/scripts.pory"
Route116_EventScript_RematchKaren::
# 357 "data/maps/Route116/scripts.pory"
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
# 358 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
# 359 "data/maps/Route116/scripts.pory"
	end
# 360 "data/maps/Route116/scripts.pory"

# 361 "data/maps/Route116/scripts.pory"
Route116_EventScript_Sarah::
# 362 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
# 363 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
# 364 "data/maps/Route116/scripts.pory"
	end
# 365 "data/maps/Route116/scripts.pory"

# 366 "data/maps/Route116/scripts.pory"
Route116_EventScript_Dawson::
# 367 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
# 368 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
# 369 "data/maps/Route116/scripts.pory"
	end
# 370 "data/maps/Route116/scripts.pory"

# 371 "data/maps/Route116/scripts.pory"
Route116_EventScript_Devan::
# 372 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
# 373 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
# 374 "data/maps/Route116/scripts.pory"
	end
# 375 "data/maps/Route116/scripts.pory"

# 376 "data/maps/Route116/scripts.pory"
Route116_EventScript_Johnson::
# 377 "data/maps/Route116/scripts.pory"
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
# 378 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
# 379 "data/maps/Route116/scripts.pory"
	end
# 380 "data/maps/Route116/scripts.pory"

# 381 "data/maps/Route116/scripts.pory"
Route116_Text_ScoundrelMadeOffWithPeeko:
# 382 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
# 383 "data/maps/Route116/scripts.pory"
	.string "We were on our walk, PEEKO and I, when\n"
# 384 "data/maps/Route116/scripts.pory"
	.string "we were jumped by an odd thug…\p"
# 385 "data/maps/Route116/scripts.pory"
	.string "The scoundrel made off with my\n"
# 386 "data/maps/Route116/scripts.pory"
	.string "darling PEEKO!\p"
# 387 "data/maps/Route116/scripts.pory"
	.string "Wrrrooooooaaaar! PEEKO!$"
# 388 "data/maps/Route116/scripts.pory"

# 389 "data/maps/Route116/scripts.pory"
Route116_Text_WantToDigTunnel:
# 390 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 391 "data/maps/Route116/scripts.pory"
	.string "I want to dig that tunnel!$"
# 392 "data/maps/Route116/scripts.pory"

# 393 "data/maps/Route116/scripts.pory"
Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
# 394 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
# 395 "data/maps/Route116/scripts.pory"
	.string "What's going on?\p"
# 396 "data/maps/Route116/scripts.pory"
	.string "I was digging the tunnel without any\n"
# 397 "data/maps/Route116/scripts.pory"
	.string "tools when some goon ordered me out!\p"
# 398 "data/maps/Route116/scripts.pory"
	.string "That tunnel's filled with POKéMON\n"
# 399 "data/maps/Route116/scripts.pory"
	.string "that react badly to loud noises.\l"
# 400 "data/maps/Route116/scripts.pory"
	.string "They could cause an uproar.\p"
# 401 "data/maps/Route116/scripts.pory"
	.string "That's why we stopped using heavy\n"
# 402 "data/maps/Route116/scripts.pory"
	.string "equipment for tunneling…\p"
# 403 "data/maps/Route116/scripts.pory"
	.string "I'm worried that the goon will do\n"
# 404 "data/maps/Route116/scripts.pory"
	.string "something stupid and startle the\l"
# 405 "data/maps/Route116/scripts.pory"
	.string "POKéMON into an uproar.$"
# 406 "data/maps/Route116/scripts.pory"

# 407 "data/maps/Route116/scripts.pory"
Route116_Text_GoonHightailedItOutOfTunnel:
# 408 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
# 409 "data/maps/Route116/scripts.pory"
	.string "That goofy goon hightailed it out of\n"
# 410 "data/maps/Route116/scripts.pory"
	.string "the tunnel! I can go back to digging!$"
# 411 "data/maps/Route116/scripts.pory"

# 412 "data/maps/Route116/scripts.pory"
Route116_Text_ThankYouTokenOfAppreciation:
# 413 "data/maps/Route116/scripts.pory"
	.string "Oh! It's you!\p"
# 414 "data/maps/Route116/scripts.pory"
	.string "You're that person who not only helped\n"
# 415 "data/maps/Route116/scripts.pory"
	.string "me in PETALBURG WOODS, but also got\l"
# 416 "data/maps/Route116/scripts.pory"
	.string "back my stolen package and then even\l"
# 417 "data/maps/Route116/scripts.pory"
	.string "graciously delivered it to SLATEPORT!\p"
# 418 "data/maps/Route116/scripts.pory"
	.string "CAPT. STERN informed us that the\n"
# 419 "data/maps/Route116/scripts.pory"
	.string "package arrived, too!\p"
# 420 "data/maps/Route116/scripts.pory"
	.string "I thank you very, very much!\p"
# 421 "data/maps/Route116/scripts.pory"
	.string "Why, if I were a rain cloud, I would\n"
# 422 "data/maps/Route116/scripts.pory"
	.string "shower you with gratitude and hail\l"
# 423 "data/maps/Route116/scripts.pory"
	.string "you as a hero!\p"
# 424 "data/maps/Route116/scripts.pory"
	.string "For you, the most wonderful TRAINER,\n"
# 425 "data/maps/Route116/scripts.pory"
	.string "I bear good news!\p"
# 426 "data/maps/Route116/scripts.pory"
	.string "Recently, our company developed\n"
# 427 "data/maps/Route116/scripts.pory"
	.string "a new kind of POKé BALL.\p"
# 428 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation, this\n"
# 429 "data/maps/Route116/scripts.pory"
	.string "is our gift to our wonderful TRAINER!$"
# 430 "data/maps/Route116/scripts.pory"

# 431 "data/maps/Route116/scripts.pory"
Route116_Text_NewBallAvailableAtMart:
# 432 "data/maps/Route116/scripts.pory"
	.string "Our new POKé BALL will be available\n"
# 433 "data/maps/Route116/scripts.pory"
	.string "at the POKéMON MART in RUSTBORO.\p"
# 434 "data/maps/Route116/scripts.pory"
	.string "Please do try it out!\n"
# 435 "data/maps/Route116/scripts.pory"
	.string "Thank you and bye-bye!$"
# 436 "data/maps/Route116/scripts.pory"

# 437 "data/maps/Route116/scripts.pory"
Route116_Text_BagIsJamPacked:
# 438 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
# 439 "data/maps/Route116/scripts.pory"
	.string "I can't give you this REPEAT BALL.$"
# 440 "data/maps/Route116/scripts.pory"

# 441 "data/maps/Route116/scripts.pory"
Route116_Text_TokenOfAppreciation:
# 442 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
# 443 "data/maps/Route116/scripts.pory"
	.string "your delivering our package, I have\l"
# 444 "data/maps/Route116/scripts.pory"
	.string "a gift of a new kind of POKé BALL\l"
# 445 "data/maps/Route116/scripts.pory"
	.string "for our most wonderful TRAINER!$"
# 446 "data/maps/Route116/scripts.pory"

# 447 "data/maps/Route116/scripts.pory"
Route116_Text_CanYouHelpMeFindGlasses:
# 448 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
# 449 "data/maps/Route116/scripts.pory"
	.string "Can you help me find them?$"
# 450 "data/maps/Route116/scripts.pory"

# 451 "data/maps/Route116/scripts.pory"
Route116_Text_MayISeeThoseGlasses:
# 452 "data/maps/Route116/scripts.pory"
	.string "Those glasses!\n"
# 453 "data/maps/Route116/scripts.pory"
	.string "May I see them for a second?$"
# 454 "data/maps/Route116/scripts.pory"

# 455 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
# 456 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 457 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 458 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…\p"
# 459 "data/maps/Route116/scripts.pory"
	.string "Maybe my glasses aren't around\n"
# 460 "data/maps/Route116/scripts.pory"
	.string "here…$"
# 461 "data/maps/Route116/scripts.pory"

# 462 "data/maps/Route116/scripts.pory"
Route116_Text_CantFindGlassesNotHere:
# 463 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 464 "data/maps/Route116/scripts.pory"
	.string "I can't find my glasses anywhere…\l"
# 465 "data/maps/Route116/scripts.pory"
	.string "Maybe they're not around here…$"
# 466 "data/maps/Route116/scripts.pory"

# 467 "data/maps/Route116/scripts.pory"
Route116_Text_NotWhatImLookingFor:
# 468 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
# 469 "data/maps/Route116/scripts.pory"
	.string "These are BLACKGLASSES.\l"
# 470 "data/maps/Route116/scripts.pory"
	.string "They're not what I'm looking for…$"
# 471 "data/maps/Route116/scripts.pory"

# 472 "data/maps/Route116/scripts.pory"
Route116_Text_RouteSignRustboro:
# 473 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116\n"
# 474 "data/maps/Route116/scripts.pory"
	.string "{LEFT_ARROW} RUSTBORO CITY$"
# 475 "data/maps/Route116/scripts.pory"

# 476 "data/maps/Route116/scripts.pory"
Route116_Text_RusturfTunnelSign:
# 477 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 478 "data/maps/Route116/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 479 "data/maps/Route116/scripts.pory"
	.string "“The tunnel project has been\n"
# 480 "data/maps/Route116/scripts.pory"
	.string "canceled.”$"
# 481 "data/maps/Route116/scripts.pory"

# 482 "data/maps/Route116/scripts.pory"
Route116_Text_TunnelersRestHouse:
# 483 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"
# 484 "data/maps/Route116/scripts.pory"

# 485 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBToStopEvolution:
# 486 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 487 "data/maps/Route116/scripts.pory"
	.string "If you want to stop a POKéMON from\n"
# 488 "data/maps/Route116/scripts.pory"
	.string "evolving, press the B Button while it\l"
# 489 "data/maps/Route116/scripts.pory"
	.string "is trying to evolve.\l"
# 490 "data/maps/Route116/scripts.pory"
	.string "The startled POKéMON will stop.\p"
# 491 "data/maps/Route116/scripts.pory"
	.string "This is called an evolution cancel.$"
# 492 "data/maps/Route116/scripts.pory"

# 493 "data/maps/Route116/scripts.pory"
Route116_Text_TrainerTipsBagHasPockets:
# 494 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
# 495 "data/maps/Route116/scripts.pory"
	.string "Your BAG has several POCKETS.\p"
# 496 "data/maps/Route116/scripts.pory"
	.string "Items you obtain are automatically\n"
# 497 "data/maps/Route116/scripts.pory"
	.string "placed in the appropriate POCKETS.\p"
# 498 "data/maps/Route116/scripts.pory"
	.string "No TRAINER can afford to be without\n"
# 499 "data/maps/Route116/scripts.pory"
	.string "a BAG of their own.$"

Route116_Text_TakingABreak::
# 48 "data/maps/Route116/scripts.pory"
	.string "I'm taking a break from hunting rare\n"
	.string "POKéMON.$"

Route116_Text_ElusiveSkitty::
# 52 "data/maps/Route116/scripts.pory"
	.string "Why does SKITTY have to be so elusive?$"
