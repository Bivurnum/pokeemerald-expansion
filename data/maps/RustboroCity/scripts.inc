# 9 "data/maps/RustboroCity/scripts.pory"

# 10 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_LITTLE_BOY, 7
# 11 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_LITTLE_GIRL, 8
# 12 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 9
# 13 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_GRUNT, 10
# 14 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_RIVAL2, 14
# 15 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_SCIENTIST, 15
# 16 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_RIVAL1, 17

RustboroCity_MapScripts::
# 30 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 40 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RustboroCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 31 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 32 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 33 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 1, RustboroCity_EventScript_SetRivalForRetrieveGoods
# 34 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_EventScript_SetRivalForRetrieveGoods
# 35 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 4, RustboroCity_EventScript_SetForReturnGoods
# 36 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 37 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 38 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	return

RustboroCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 41 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0


RustboroCity_EventScript_PositionScientistForExit::
# 46 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 47 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 15, 11, 15
# 48 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 11, 15
# 49 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_DOWN
	end


RustboroCity_EventScript_PositionScientistLeftExit::
# 54 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 15, 12, 15
# 55 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 12, 15
# 56 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_DOWN
	end


RustboroCity_EventScript_HideMapNamePopup::
# 61 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return


RustboroCity_EventScript_SetRivalForRetrieveGoods::
# 66 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 21, 10
	return


RustboroCity_EventScript_SetForReturnGoods::
# 70 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	return


RustboroCity_EventScript_ScientistAddMatchCall::
# 74 "data/maps/RustboroCity/scripts.pory"
	lockall
# 75 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 76 "data/maps/RustboroCity/scripts.pory"
	destroyfollower
# 77 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 78 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 79 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 80 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkDown
# 81 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 82 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 83 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_PlayerWalkDown
# 84 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 85 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 86 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 87 "data/maps/RustboroCity/scripts.pory"
	addobject 15
# 88 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_ScientistApproachPlayer
# 89 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 90 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 91 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_ExclamationMark
# 92 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 93 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_Delay48
# 94 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 95 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 96 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 97 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 98 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_ScientistWalkInPlaceDown
# 99 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 100 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 101 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 102 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 103 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 104 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 11
	goto_if_eq RustboroCity_EventScript_ScientistAddMatchCall_2
# 112 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_WalkInPlaceFasterLeft
# 113 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 114 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_UpdatePokenav
# 115 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_GoToPlayerUpgradeRight
# 116 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
RustboroCity_EventScript_ScientistAddMatchCall_1:
# 118 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_UpdatePokenav
# 119 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_WalkInPlaceFasterDown
# 120 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 121 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 122 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 123 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 124 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
	return

RustboroCity_EventScript_ScientistAddMatchCall_2:
# 105 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_WalkInPlaceFasterRight
# 106 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 107 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_UpdatePokenav
# 108 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_GoToPlayerUpgradeLeft
# 109 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	goto RustboroCity_EventScript_ScientistAddMatchCall_1


RustboroCity_EventScript_UpdatePokenav::
# 128 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 129 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 130 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 131 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 132 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 133 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 134 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 135 "data/maps/RustboroCity/scripts.pory"
	delay 20
	return


RustboroCity_EventScript_PleaseSelectPokenav::
# 140 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 141 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 142 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 143 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
	return


RustboroCity_EventScript_MatchCallTutorial::
# 147 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 148 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 149 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 150 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 151 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_MatchCallTutorial_3
# 153 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_MatchCallTutorial_4
# 155 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_MatchCallTutorial_5
# 157 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_MatchCallTutorial_6
# 159 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_MatchCallTutorial_7
# 161 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_MatchCallTutorial_8
# 163 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_MatchCallTutorial_9
# 165 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_MatchCallTutorial_10
RustboroCity_EventScript_MatchCallTutorial_1:
# 168 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 169 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 170 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 171 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 172 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 173 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_ScientistLeave
# 174 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 175 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 176 "data/maps/RustboroCity/scripts.pory"
	removeobject 15
# 177 "data/maps/RustboroCity/scripts.pory"
	waitse
# 178 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 179 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 180 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 11
	goto_if_eq RustboroCity_EventScript_MatchCallTutorial_12
# 185 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceRight
# 186 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
RustboroCity_EventScript_MatchCallTutorial_11:
# 188 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 189 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_Rival1LetsRegister, MSGBOX_DEFAULT
# 190 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 191 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 192 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 193 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredRival1, MSGBOX_DEFAULT
# 194 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 195 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 196 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 197 "data/maps/RustboroCity/scripts.pory"
	checkfriendchoice
# 198 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 199 "data/maps/RustboroCity/scripts.pory"
	case SPENCER, RustboroCity_EventScript_MatchCallTutorial_17
# 201 "data/maps/RustboroCity/scripts.pory"
	case BREN, RustboroCity_EventScript_MatchCallTutorial_18
# 203 "data/maps/RustboroCity/scripts.pory"
	case KYLE, RustboroCity_EventScript_MatchCallTutorial_19
RustboroCity_EventScript_MatchCallTutorial_15:
# 206 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SeeYouSoon, MSGBOX_DEFAULT
# 207 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 208 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1LeaveAfterPokenav
# 209 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 210 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 211 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 212 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_DEVON_3F_RIVAL1
# 213 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 214 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 215 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_MatchCallTutorial_3:
# 152 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_4:
# 154 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_5:
# 156 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_6:
# 158 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_7:
# 160 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_8:
# 162 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_9:
# 164 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_10:
# 166 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_12:
# 181 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
# 182 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceLeft
	goto RustboroCity_EventScript_MatchCallTutorial_11

RustboroCity_EventScript_MatchCallTutorial_17:
# 200 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_BREN_MATCH_CALL
	goto RustboroCity_EventScript_MatchCallTutorial_15

RustboroCity_EventScript_MatchCallTutorial_18:
# 202 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_KYLE_MATCH_CALL
	goto RustboroCity_EventScript_MatchCallTutorial_15

RustboroCity_EventScript_MatchCallTutorial_19:
# 204 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
	goto RustboroCity_EventScript_MatchCallTutorial_15


# 219 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 220 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 223 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 224 "data/maps/RustboroCity/scripts.pory"
	walk_down
	step_end

# 227 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 228 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 229 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 233 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 234 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 235 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 236 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 237 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 238 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 239 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 240 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 243 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 244 "data/maps/RustboroCity/scripts.pory"
	walk_up
	step_end

# 247 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GoToPlayerUpgradeLeft:
# 248 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 249 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 250 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 251 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 254 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GoToPlayerUpgradeRight:
# 255 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 256 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 257 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 258 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 261 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1LeaveAfterPokenav:
# 262 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 262 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 262 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 262 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 284 "data/maps/RustboroCity/scripts.pory"

# 285 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 286 "data/maps/RustboroCity/scripts.pory"
	lock
# 287 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 288 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 289 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 290 "data/maps/RustboroCity/scripts.pory"
	release
# 291 "data/maps/RustboroCity/scripts.pory"
	end
# 292 "data/maps/RustboroCity/scripts.pory"

# 293 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 294 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 295 "data/maps/RustboroCity/scripts.pory"
	release
# 296 "data/maps/RustboroCity/scripts.pory"
	end
# 297 "data/maps/RustboroCity/scripts.pory"

# 298 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 299 "data/maps/RustboroCity/scripts.pory"
	lock
# 300 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 301 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 302 "data/maps/RustboroCity/scripts.pory"
	release
# 303 "data/maps/RustboroCity/scripts.pory"
	end
# 304 "data/maps/RustboroCity/scripts.pory"

# 305 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 306 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 307 "data/maps/RustboroCity/scripts.pory"
	end
# 308 "data/maps/RustboroCity/scripts.pory"

# 309 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 310 "data/maps/RustboroCity/scripts.pory"
	lock
# 311 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 312 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 313 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 314 "data/maps/RustboroCity/scripts.pory"
	release
# 315 "data/maps/RustboroCity/scripts.pory"
	end
# 316 "data/maps/RustboroCity/scripts.pory"

# 317 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 318 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 319 "data/maps/RustboroCity/scripts.pory"
	release
# 320 "data/maps/RustboroCity/scripts.pory"
	end
# 321 "data/maps/RustboroCity/scripts.pory"

# 322 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 323 "data/maps/RustboroCity/scripts.pory"
	lock
# 324 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 325 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 326 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 327 "data/maps/RustboroCity/scripts.pory"
	release
# 328 "data/maps/RustboroCity/scripts.pory"
	end
# 329 "data/maps/RustboroCity/scripts.pory"

# 330 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 331 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 332 "data/maps/RustboroCity/scripts.pory"
	release
# 333 "data/maps/RustboroCity/scripts.pory"
	end
# 334 "data/maps/RustboroCity/scripts.pory"

# 335 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 336 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 337 "data/maps/RustboroCity/scripts.pory"
	end
# 338 "data/maps/RustboroCity/scripts.pory"

# 339 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 340 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 341 "data/maps/RustboroCity/scripts.pory"
	end
# 342 "data/maps/RustboroCity/scripts.pory"

# 343 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 344 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 345 "data/maps/RustboroCity/scripts.pory"
	end
# 346 "data/maps/RustboroCity/scripts.pory"

# 347 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 348 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 349 "data/maps/RustboroCity/scripts.pory"
	end
# 350 "data/maps/RustboroCity/scripts.pory"

# 351 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 352 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 353 "data/maps/RustboroCity/scripts.pory"
	end
# 354 "data/maps/RustboroCity/scripts.pory"

# 355 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 356 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 357 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 358 "data/maps/RustboroCity/scripts.pory"
	end
# 359 "data/maps/RustboroCity/scripts.pory"

# 360 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 361 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 362 "data/maps/RustboroCity/scripts.pory"
	end
# 363 "data/maps/RustboroCity/scripts.pory"

# 364 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 365 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 366 "data/maps/RustboroCity/scripts.pory"
	end
# 367 "data/maps/RustboroCity/scripts.pory"

# 368 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 369 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 370 "data/maps/RustboroCity/scripts.pory"
	end
# 371 "data/maps/RustboroCity/scripts.pory"

# 372 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 373 "data/maps/RustboroCity/scripts.pory"
	lock
# 374 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 375 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 376 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 377 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 378 "data/maps/RustboroCity/scripts.pory"
	release
# 379 "data/maps/RustboroCity/scripts.pory"
	end
# 380 "data/maps/RustboroCity/scripts.pory"

# 381 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 382 "data/maps/RustboroCity/scripts.pory"
	lock
# 383 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 384 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 385 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 386 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 387 "data/maps/RustboroCity/scripts.pory"
	release
# 388 "data/maps/RustboroCity/scripts.pory"
	end
# 389 "data/maps/RustboroCity/scripts.pory"

# 390 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 391 "data/maps/RustboroCity/scripts.pory"
	lock
# 392 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 393 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 394 "data/maps/RustboroCity/scripts.pory"
	release
# 395 "data/maps/RustboroCity/scripts.pory"
	end
# 396 "data/maps/RustboroCity/scripts.pory"

# 397 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 398 "data/maps/RustboroCity/scripts.pory"
	lockall
# 399 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 400 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 401 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 402 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 403 "data/maps/RustboroCity/scripts.pory"
	end
# 404 "data/maps/RustboroCity/scripts.pory"

# 405 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 406 "data/maps/RustboroCity/scripts.pory"
	lockall
# 407 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 408 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 409 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 410 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 411 "data/maps/RustboroCity/scripts.pory"
	end
# 412 "data/maps/RustboroCity/scripts.pory"

# 413 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 414 "data/maps/RustboroCity/scripts.pory"
	lockall
# 415 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 416 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 417 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 418 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 419 "data/maps/RustboroCity/scripts.pory"
	end
# 420 "data/maps/RustboroCity/scripts.pory"

# 421 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 422 "data/maps/RustboroCity/scripts.pory"
	lockall
# 423 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 424 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 425 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 426 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 427 "data/maps/RustboroCity/scripts.pory"
	end
# 428 "data/maps/RustboroCity/scripts.pory"

# 429 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 430 "data/maps/RustboroCity/scripts.pory"
	lockall
# 431 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 432 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 433 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 434 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 435 "data/maps/RustboroCity/scripts.pory"
	end
# 436 "data/maps/RustboroCity/scripts.pory"

# 437 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 438 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 439 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 440 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 441 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 442 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 443 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 444 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 445 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 446 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 447 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 448 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 449 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 450 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 451 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 452 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 453 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 454 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 455 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 456 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 457 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 458 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 459 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 460 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 461 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 462 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 463 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 464 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 465 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 466 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 467 "data/maps/RustboroCity/scripts.pory"
	end
# 468 "data/maps/RustboroCity/scripts.pory"

# 469 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 470 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 471 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 472 "data/maps/RustboroCity/scripts.pory"
	return
# 473 "data/maps/RustboroCity/scripts.pory"

# 474 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 475 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 476 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 477 "data/maps/RustboroCity/scripts.pory"
	return
# 478 "data/maps/RustboroCity/scripts.pory"

# 479 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 480 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 481 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 482 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 483 "data/maps/RustboroCity/scripts.pory"
	return
# 484 "data/maps/RustboroCity/scripts.pory"

# 485 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 486 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 487 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 488 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 489 "data/maps/RustboroCity/scripts.pory"
	return
# 490 "data/maps/RustboroCity/scripts.pory"

# 491 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 492 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 493 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 494 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 495 "data/maps/RustboroCity/scripts.pory"
	return
# 496 "data/maps/RustboroCity/scripts.pory"

# 497 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 498 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 499 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 500 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 501 "data/maps/RustboroCity/scripts.pory"
	return
# 502 "data/maps/RustboroCity/scripts.pory"

# 503 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 504 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 505 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 506 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 507 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 508 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 509 "data/maps/RustboroCity/scripts.pory"
	return
# 510 "data/maps/RustboroCity/scripts.pory"

# 511 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 512 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 513 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 514 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 515 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 516 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 517 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 518 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 519 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 520 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 521 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 522 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 523 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 524 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 525 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 526 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 527 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 528 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 529 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 530 "data/maps/RustboroCity/scripts.pory"
	step_end
# 531 "data/maps/RustboroCity/scripts.pory"

# 532 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 533 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 534 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 535 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 536 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 537 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 538 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 539 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 540 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 541 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 542 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 543 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 544 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 545 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 546 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 547 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 548 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 549 "data/maps/RustboroCity/scripts.pory"
	step_end
# 550 "data/maps/RustboroCity/scripts.pory"

# 551 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 552 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 553 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 554 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 555 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 556 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 557 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 558 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 559 "data/maps/RustboroCity/scripts.pory"
	step_end
# 560 "data/maps/RustboroCity/scripts.pory"

# 561 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 562 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 563 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 564 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 565 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 566 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 567 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 568 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 569 "data/maps/RustboroCity/scripts.pory"
	step_end
# 570 "data/maps/RustboroCity/scripts.pory"

# 571 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 572 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 573 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 574 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 575 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 576 "data/maps/RustboroCity/scripts.pory"
	step_end
# 577 "data/maps/RustboroCity/scripts.pory"

# 578 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 579 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 580 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 581 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 582 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 583 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 584 "data/maps/RustboroCity/scripts.pory"
	step_end
# 585 "data/maps/RustboroCity/scripts.pory"

# 586 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 587 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 588 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 589 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 590 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 591 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 592 "data/maps/RustboroCity/scripts.pory"
	step_end
# 593 "data/maps/RustboroCity/scripts.pory"

# 594 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 595 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 596 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 597 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 598 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 599 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 600 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 601 "data/maps/RustboroCity/scripts.pory"
	step_end
# 602 "data/maps/RustboroCity/scripts.pory"

# 603 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 604 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 605 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 606 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 607 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 608 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 609 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 610 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 611 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 612 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 616 "data/maps/RustboroCity/scripts.pory"
	lock
# 617 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 618 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 619 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 620 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 625 "data/maps/RustboroCity/scripts.pory"
	waitse
# 626 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 627 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 632 "data/maps/RustboroCity/scripts.pory"
	lockall
# 633 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 634 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 639 "data/maps/RustboroCity/scripts.pory"
	lockall
# 640 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 641 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 646 "data/maps/RustboroCity/scripts.pory"
	lockall
# 647 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 648 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 653 "data/maps/RustboroCity/scripts.pory"
	lockall
# 654 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 655 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 660 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 661 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 662 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 663 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 664 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 665 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 666 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 667 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 668 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm 9
# 669 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 670 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 671 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 676 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 677 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 678 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 679 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_NoticeRival1
# 680 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 681 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 682 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 683 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachPlayer
# 684 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 685 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 686 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 687 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 688 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 689 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 690 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 691 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 692 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 696 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 700 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 701 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 706 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 707 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 708 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 709 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 713 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 715 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 716 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 717 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 718 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 719 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 722 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 725 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 726 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 730 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 731 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 732 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 733 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceRight
# 734 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 735 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 736 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 738 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 740 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 742 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_20
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 745 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 746 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 747 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 748 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 29, 10
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 693 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 694 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 695 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 697 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 698 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceDown
# 699 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 702 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 703 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 704 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 710 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 720 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 721 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 723 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 724 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 727 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 728 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 737 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 739 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 741 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger2
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_20:
# 743 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 754 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 755 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 756 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 757 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 758 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 759 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 760 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 761 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 762 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 763 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 768 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 769 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 770 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 771 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 772 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 773 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 774 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 775 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 776 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 781 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 782 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 783 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 784 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 785 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 786 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 787 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 788 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 789 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 790 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 795 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 796 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 797 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 798 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 799 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 800 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 801 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 802 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 803 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 804 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 805 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 806 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 12
	return


# 810 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 811 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 812 "data/maps/RustboroCity/scripts.pory"
	step_end

# 815 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_NoticeRival1:
# 816 "data/maps/RustboroCity/scripts.pory"
	emote_exclamation_mark
# 817 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_left
	step_end

# 820 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 821 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 824 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 825 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 825 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 825 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 826 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 829 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 830 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 831 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 831 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 834 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 835 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 836 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 836 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 837 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 837 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 840 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 841 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 842 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 842 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 845 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 846 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 846 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 849 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 850 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 850 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 853 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 854 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 854 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 857 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 858 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 858 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 861 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 862 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 863 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 863 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 866 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 867 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 867 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 872 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 873 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 877 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2:
# 878 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 883 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger3:
# 884 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 884 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
# 917 "data/maps/RustboroCity/scripts.pory"
	lockall
# 918 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 919 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerUp2
# 920 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger1::
# 925 "data/maps/RustboroCity/scripts.pory"
	lockall
# 926 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 927 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 928 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger2::
# 933 "data/maps/RustboroCity/scripts.pory"
	lockall
# 934 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 935 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerDown2
# 936 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger3::
# 941 "data/maps/RustboroCity/scripts.pory"
	lockall
# 942 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 943 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 944 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoods::
# 949 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 950 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 951 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 952 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_ReturnGoods_2
# 956 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_EAST
RustboroCity_EventScript_ReturnGoods_1:
# 958 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 959 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 960 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 961 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 962 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 963 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 964 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 965 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 966 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 967 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_ReturnGoods_2:
# 953 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_NORTH
	goto RustboroCity_EventScript_ReturnGoods_1


RustboroCity_EventScript_BagFull::
# 972 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return


RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 977 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 978 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 979 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 980 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 981 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 982 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 983 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 984 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 985 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 986 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 987 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 992 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
# 993 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterRight
# 994 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 995 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 996 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 997 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 998 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 999 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1000 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_RivalMoveForReturnGoodsRight
# 1001 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1002 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 1003 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 1008 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 1009 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 1010 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1011 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1012 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1013 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1014 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1015 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1016 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1017 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1018 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 1023 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 1024 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 1025 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1026 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1027 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1028 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1029 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1030 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1031 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1032 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 1033 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_EmployeeApproachPlayerDown
# 1034 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1035 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1036 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerRight::
# 1041 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 1042 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1043 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1044 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1045 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1046 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1047 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_Rival1::
# 1052 "data/maps/RustboroCity/scripts.pory"
	lock
# 1053 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 1054 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq RustboroCity_EventScript_Rival1_2
RustboroCity_EventScript_Rival1_1:
# 1058 "data/maps/RustboroCity/scripts.pory"
	release
	end

RustboroCity_EventScript_Rival1_2:
# 1055 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_Rival1_Text_0, MSGBOX_DEFAULT
# 1056 "data/maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_Rival1_1


# 1062 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalMoveForReturnGoodsRight:
# 1063 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1063 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1064 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1065 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

RustboroCity_EventScript_Rival::
# 1069 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1070 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 1071 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1072 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1073 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_PlayRivalMusic::
# 1077 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 1078 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 1079 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	return


RustboroCity_EventScript_PlayMayMusic::
# 1084 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return


RustboroCity_EventScript_PlayBrendanMusic::
# 1089 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return


RustboroCity_EventScript_RivalTrigger0::
# 1094 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1095 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1096 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1097 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1098 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1099 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1100 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1101 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1102 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1103 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 1104 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1105 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1106 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1107 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger1::
# 1111 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1112 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1113 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1114 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1115 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1116 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1117 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1118 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1119 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1120 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 1121 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1122 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1123 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1124 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger2::
# 1128 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1129 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1130 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1131 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1132 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1133 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1134 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1135 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1136 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1137 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 1138 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1139 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1140 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1141 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger3::
# 1145 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1146 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1147 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1148 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1149 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1150 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1151 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1152 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1153 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1154 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 1155 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1156 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1157 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1158 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger4::
# 1162 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1163 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1164 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1165 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1166 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1167 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1168 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1169 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1170 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1171 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 1172 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1173 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1174 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1175 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger5::
# 1179 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1180 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1181 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1182 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1183 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1184 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1185 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1186 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1187 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1188 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 1189 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1190 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1191 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1192 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger6::
# 1196 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1197 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1198 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1199 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1200 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1201 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1202 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1203 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1204 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1205 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 1206 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1207 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1208 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1209 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger7::
# 1213 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1214 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1215 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1216 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1217 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1218 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1219 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1220 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1221 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1222 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 1223 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1224 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1225 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1226 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalEncounter::
# 1230 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 1231 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1232 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
	end


# 1236 "data/maps/RustboroCity/scripts.pory"

# 1237 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1238 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1239 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1240 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1241 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1242 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1243 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1244 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1245 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1246 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1247 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1248 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1249 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
# 1250 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1251 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1252 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1253 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1254 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1255 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1256 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1257 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1258 "data/maps/RustboroCity/scripts.pory"
	end
# 1259 "data/maps/RustboroCity/scripts.pory"

# 1260 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1261 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1262 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1263 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1264 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1265 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1266 "data/maps/RustboroCity/scripts.pory"
	end
# 1267 "data/maps/RustboroCity/scripts.pory"

# 1268 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1269 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1270 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1271 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 1272 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 1273 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 1274 "data/maps/RustboroCity/scripts.pory"
	end
# 1275 "data/maps/RustboroCity/scripts.pory"

# 1276 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1277 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1278 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1279 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1280 "data/maps/RustboroCity/scripts.pory"
	end
# 1281 "data/maps/RustboroCity/scripts.pory"

# 1282 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1283 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1284 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1285 "data/maps/RustboroCity/scripts.pory"
	return
# 1286 "data/maps/RustboroCity/scripts.pory"

# 1287 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 1288 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 1289 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1290 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1291 "data/maps/RustboroCity/scripts.pory"
	end
# 1292 "data/maps/RustboroCity/scripts.pory"

# 1293 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 1294 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 1295 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1296 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1297 "data/maps/RustboroCity/scripts.pory"
	end
# 1298 "data/maps/RustboroCity/scripts.pory"

# 1299 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 1300 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 1301 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1302 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1303 "data/maps/RustboroCity/scripts.pory"
	end
# 1304 "data/maps/RustboroCity/scripts.pory"

# 1305 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1306 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1307 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1308 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1309 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1310 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1311 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1312 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1313 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1314 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1315 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1316 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1317 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
# 1318 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1319 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1320 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1321 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1322 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1323 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1324 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1325 "data/maps/RustboroCity/scripts.pory"
	end
# 1326 "data/maps/RustboroCity/scripts.pory"

# 1327 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1328 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1329 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1330 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1331 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1332 "data/maps/RustboroCity/scripts.pory"
	end
# 1333 "data/maps/RustboroCity/scripts.pory"

# 1334 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1335 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1336 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1337 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 1338 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 1339 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 1340 "data/maps/RustboroCity/scripts.pory"
	end
# 1341 "data/maps/RustboroCity/scripts.pory"

# 1342 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1343 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1344 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1345 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1346 "data/maps/RustboroCity/scripts.pory"
	end
# 1347 "data/maps/RustboroCity/scripts.pory"

# 1348 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 1349 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 1350 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1351 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1352 "data/maps/RustboroCity/scripts.pory"
	end
# 1353 "data/maps/RustboroCity/scripts.pory"

# 1354 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 1355 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 1356 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1357 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1358 "data/maps/RustboroCity/scripts.pory"
	end
# 1359 "data/maps/RustboroCity/scripts.pory"

# 1360 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 1361 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 1362 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1363 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1364 "data/maps/RustboroCity/scripts.pory"
	end
# 1365 "data/maps/RustboroCity/scripts.pory"

# 1366 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1367 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1368 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1369 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1370 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1371 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1372 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1373 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1374 "data/maps/RustboroCity/scripts.pory"

# 1375 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1376 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1377 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1378 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1379 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1380 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1381 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1382 "data/maps/RustboroCity/scripts.pory"

# 1383 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1384 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1385 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1386 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1387 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1388 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1389 "data/maps/RustboroCity/scripts.pory"

# 1390 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1391 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1392 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1393 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1394 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1395 "data/maps/RustboroCity/scripts.pory"

# 1396 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1397 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1398 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1399 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1400 "data/maps/RustboroCity/scripts.pory"

# 1401 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1402 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1403 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1404 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1405 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1406 "data/maps/RustboroCity/scripts.pory"

# 1407 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1408 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1409 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1410 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1411 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1412 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1413 "data/maps/RustboroCity/scripts.pory"

# 1414 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1415 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1416 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1417 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1418 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1419 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1420 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1421 "data/maps/RustboroCity/scripts.pory"

# 1422 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1423 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1424 "data/maps/RustboroCity/scripts.pory"
	end
# 1425 "data/maps/RustboroCity/scripts.pory"

# 1426 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1427 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1428 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1429 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1430 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1431 "data/maps/RustboroCity/scripts.pory"

# 1432 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1433 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1434 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1435 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1436 "data/maps/RustboroCity/scripts.pory"

# 1437 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1438 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1439 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1440 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1441 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1442 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1443 "data/maps/RustboroCity/scripts.pory"

# 1444 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1445 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1446 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1447 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1448 "data/maps/RustboroCity/scripts.pory"

# 1449 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1450 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1451 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1452 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1453 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1454 "data/maps/RustboroCity/scripts.pory"

# 1455 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1456 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1457 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1458 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1459 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1460 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1461 "data/maps/RustboroCity/scripts.pory"

# 1462 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1463 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1464 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1465 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1466 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1467 "data/maps/RustboroCity/scripts.pory"

# 1468 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1469 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1470 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1471 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1472 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1473 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1474 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1475 "data/maps/RustboroCity/scripts.pory"

# 1476 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1477 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1478 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1479 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1480 "data/maps/RustboroCity/scripts.pory"

# 1481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1482 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1483 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1484 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1485 "data/maps/RustboroCity/scripts.pory"

# 1486 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1487 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1488 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1489 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1490 "data/maps/RustboroCity/scripts.pory"

# 1491 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1492 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1493 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1494 "data/maps/RustboroCity/scripts.pory"

# 1495 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1496 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1497 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1498 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1499 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1500 "data/maps/RustboroCity/scripts.pory"

# 1501 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1502 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1503 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1504 "data/maps/RustboroCity/scripts.pory"

# 1505 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1506 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1507 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1508 "data/maps/RustboroCity/scripts.pory"

# 1509 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1510 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1511 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1512 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1513 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1514 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1515 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1516 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1517 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1518 "data/maps/RustboroCity/scripts.pory"

# 1519 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1520 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1521 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"

# 1545 "data/maps/RustboroCity/scripts.pory"

# 1546 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1547 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1548 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1549 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1550 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1551 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1552 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1553 "data/maps/RustboroCity/scripts.pory"

# 1554 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1555 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1556 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1557 "data/maps/RustboroCity/scripts.pory"

# 1558 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1559 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1560 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1561 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1562 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1563 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1564 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1565 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1566 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1567 "data/maps/RustboroCity/scripts.pory"

# 1568 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1569 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1570 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1571 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1572 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1573 "data/maps/RustboroCity/scripts.pory"

# 1574 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1575 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1576 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1577 "data/maps/RustboroCity/scripts.pory"

# 1578 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1579 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1580 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1581 "data/maps/RustboroCity/scripts.pory"

# 1582 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1583 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1584 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1585 "data/maps/RustboroCity/scripts.pory"

# 1586 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1587 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1588 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1589 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1590 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1591 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1592 "data/maps/RustboroCity/scripts.pory"

# 1593 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1594 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1595 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1596 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1597 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1598 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1599 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1600 "data/maps/RustboroCity/scripts.pory"

# 1601 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1602 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1603 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1604 "data/maps/RustboroCity/scripts.pory"

# 1605 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1606 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1607 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1608 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1609 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1610 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1611 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1612 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1613 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1614 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1615 "data/maps/RustboroCity/scripts.pory"

# 1616 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1617 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1618 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1619 "data/maps/RustboroCity/scripts.pory"

# 1620 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1621 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1622 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1623 "data/maps/RustboroCity/scripts.pory"

# 1624 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1625 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1626 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1627 "data/maps/RustboroCity/scripts.pory"

# 1628 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1629 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1630 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1631 "data/maps/RustboroCity/scripts.pory"

# 1632 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1633 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1634 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1635 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1636 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1637 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1638 "data/maps/RustboroCity/scripts.pory"

# 1639 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1640 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1641 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1642 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1643 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1644 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1645 "data/maps/RustboroCity/scripts.pory"

# 1646 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1647 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1648 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1649 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1650 "data/maps/RustboroCity/scripts.pory"

# 1651 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1652 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1653 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1654 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1655 "data/maps/RustboroCity/scripts.pory"

# 1656 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1657 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1658 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1659 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1660 "data/maps/RustboroCity/scripts.pory"

# 1661 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1662 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1663 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1664 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1665 "data/maps/RustboroCity/scripts.pory"

# 1666 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1667 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1668 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1669 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1670 "data/maps/RustboroCity/scripts.pory"

# 1671 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1672 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1673 "data/maps/RustboroCity/scripts.pory"

# 1674 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1675 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1676 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1677 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1678 "data/maps/RustboroCity/scripts.pory"
	.string "You two, may I see those POKéNAVS?\n"
# 1679 "data/maps/RustboroCity/scripts.pory"
	.string "The ones our PRESIDENT gave you?$"
# 1680 "data/maps/RustboroCity/scripts.pory"

# 1681 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1682 "data/maps/RustboroCity/scripts.pory"
	.string "There you go!\p"
# 1683 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1684 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1685 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1686 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1687 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1688 "data/maps/RustboroCity/scripts.pory"
	.string "Our PRESIDENT STONE should\n"
# 1689 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1690 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1691 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1692 "data/maps/RustboroCity/scripts.pory"

# 1693 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1694 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1695 "data/maps/RustboroCity/scripts.pory"

# 1696 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1697 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1698 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}, {RIVAL}!$"
# 1699 "data/maps/RustboroCity/scripts.pory"

# 1700 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1701 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1702 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1703 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1704 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1705 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1706 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1707 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1708 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_Rival1_Text_0:
# 1055 "data/maps/RustboroCity/scripts.pory"
	.string "Aren't you going to\nreturn the GOODS?$"

RustboroCity_Text_Rival1LetsRegister::
# 267 "data/maps/RustboroCity/scripts.pory"
	.string "This is great!\n"
	.string "Let's register each other right now!$"

RustboroCity_Text_RegisteredRival1::
# 272 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER} registered {RIVAL}\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_SeeYouSoon::
# 277 "data/maps/RustboroCity/scripts.pory"
	.string "Now we can call each other whenever we\n"
	.string "want!\l"
	.string "I'm going to try to catch a last minute\l"
	.string "SLAKOTH in PETALBURG WOODS.\l"
	.string "You should find {RIVAL2} and meet me at\l"
	.string "MR. BRINEY'S cottage.\p"
	.string "See you soon!$"

RustboroCity_Text_YoPlayer::
# 889 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 893 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 898 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 902 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 906 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 911 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"

RustboroCity_Text_YouGotItThankYou::
# 1524 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
	.string "Your friend was telling me how you gave\l"
	.string "that thug a thrashing!\p"
	.string "Did you really bring the GOODS back?\n"
	.string "You did?\p"
	.string "Wonderful! You really are a great\n"
	.string "TRAINER!\p"
	.string "I know! As my thanks, I'll give you\n"
	.string "another GREAT BALL!$"

RustboroCity_Text_YoureLoadedWithItems::
# 1535 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_PleaseComeWithMe::
# 1540 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
	.string "Both of you please come with me!$"
