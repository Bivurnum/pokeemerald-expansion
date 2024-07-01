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
# 32 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
# 42 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

RustboroCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 33 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 34 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 35 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 1, RustboroCity_EventScript_SetRivalForRetrieveGoods
# 36 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_EventScript_SetRivalForRetrieveGoods
# 37 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 4, RustboroCity_EventScript_SetForReturnGoods
# 38 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 39 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 40 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	return

RustboroCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 43 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0


RustboroCity_EventScript_PositionScientistForExit::
# 48 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 49 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 15, 11, 15
# 50 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 11, 15
# 51 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_DOWN
	end


RustboroCity_EventScript_PositionScientistLeftExit::
# 56 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 15, 12, 15
# 57 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 12, 15
# 58 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 17, MOVEMENT_TYPE_FACE_DOWN
	end


RustboroCity_EventScript_HideMapNamePopup::
# 63 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return


RustboroCity_EventScript_SetRivalForRetrieveGoods::
# 68 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 21, 10
	return


RustboroCity_EventScript_SetForReturnGoods::
# 72 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	return


RustboroCity_EventScript_ScientistAddMatchCall::
# 76 "data/maps/RustboroCity/scripts.pory"
	lockall
# 77 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 78 "data/maps/RustboroCity/scripts.pory"
	destroyfollower
# 79 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 80 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 81 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 82 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkDown
# 83 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 84 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 85 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_PlayerWalkDown
# 86 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 87 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 88 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 89 "data/maps/RustboroCity/scripts.pory"
	addobject 15
# 90 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_ScientistApproachPlayer
# 91 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 93 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_ExclamationMark
# 94 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 95 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_Delay48
# 96 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 97 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 98 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 99 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 100 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_ScientistWalkInPlaceDown
# 101 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 102 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 103 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 104 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 105 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 106 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 11
	goto_if_eq RustboroCity_EventScript_ScientistAddMatchCall_2
# 114 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_WalkInPlaceFasterLeft
# 115 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 116 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_UpdatePokenav
# 117 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_GoToPlayerUpgradeRight
# 118 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
RustboroCity_EventScript_ScientistAddMatchCall_1:
# 120 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_UpdatePokenav
# 121 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_WalkInPlaceFasterDown
# 122 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 123 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 124 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 125 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 126 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
	return

RustboroCity_EventScript_ScientistAddMatchCall_2:
# 107 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, Common_Movement_WalkInPlaceFasterRight
# 108 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 109 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_UpdatePokenav
# 110 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_GoToPlayerUpgradeLeft
# 111 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	goto RustboroCity_EventScript_ScientistAddMatchCall_1


RustboroCity_EventScript_UpdatePokenav::
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
	delay 10
# 136 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 137 "data/maps/RustboroCity/scripts.pory"
	delay 20
	return


RustboroCity_EventScript_PleaseSelectPokenav::
# 142 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 143 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 144 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 145 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
	return


RustboroCity_EventScript_MatchCallTutorial::
# 149 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 150 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 151 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 152 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 153 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_MatchCallTutorial_3
# 155 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_MatchCallTutorial_4
# 157 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_MatchCallTutorial_5
# 159 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_MatchCallTutorial_6
# 161 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_MatchCallTutorial_7
# 163 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_MatchCallTutorial_8
# 165 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_MatchCallTutorial_9
# 167 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_MatchCallTutorial_10
RustboroCity_EventScript_MatchCallTutorial_1:
# 170 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 171 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 172 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 173 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 174 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 175 "data/maps/RustboroCity/scripts.pory"
	applymovement 15, RustboroCity_Movement_ScientistLeave
# 176 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 177 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 178 "data/maps/RustboroCity/scripts.pory"
	removeobject 15
# 179 "data/maps/RustboroCity/scripts.pory"
	waitse
# 180 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 181 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 182 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 11
	goto_if_eq RustboroCity_EventScript_MatchCallTutorial_12
# 187 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceRight
# 188 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
RustboroCity_EventScript_MatchCallTutorial_11:
# 190 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 191 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_Rival1LetsRegister, MSGBOX_DEFAULT
# 192 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 193 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 194 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 195 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredRival1, MSGBOX_DEFAULT
# 196 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 197 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 198 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 199 "data/maps/RustboroCity/scripts.pory"
	checkfriendchoice
# 200 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 201 "data/maps/RustboroCity/scripts.pory"
	case SPENCER, RustboroCity_EventScript_MatchCallTutorial_17
# 203 "data/maps/RustboroCity/scripts.pory"
	case BREN, RustboroCity_EventScript_MatchCallTutorial_18
# 205 "data/maps/RustboroCity/scripts.pory"
	case KYLE, RustboroCity_EventScript_MatchCallTutorial_19
RustboroCity_EventScript_MatchCallTutorial_15:
# 208 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SeeYouSoon, MSGBOX_DEFAULT
# 209 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 210 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 211 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1LeaveAfterPokenav
# 212 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 213 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 214 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 215 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_DEVON_3F_RIVAL1
# 216 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 217 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 218 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_MatchCallTutorial_3:
# 154 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_4:
# 156 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_5:
# 158 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_6:
# 160 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_7:
# 162 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_8:
# 164 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_9:
# 166 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_10:
# 168 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_PleaseSelectPokenav
	goto RustboroCity_EventScript_MatchCallTutorial_1

RustboroCity_EventScript_MatchCallTutorial_12:
# 183 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
# 184 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceLeft
	goto RustboroCity_EventScript_MatchCallTutorial_11

RustboroCity_EventScript_MatchCallTutorial_17:
# 202 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_BREN_MATCH_CALL
	goto RustboroCity_EventScript_MatchCallTutorial_15

RustboroCity_EventScript_MatchCallTutorial_18:
# 204 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_KYLE_MATCH_CALL
	goto RustboroCity_EventScript_MatchCallTutorial_15

RustboroCity_EventScript_MatchCallTutorial_19:
# 206 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
	goto RustboroCity_EventScript_MatchCallTutorial_15


# 222 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 223 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 226 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 227 "data/maps/RustboroCity/scripts.pory"
	walk_down
	step_end

# 230 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 231 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 232 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 236 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 237 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 238 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 239 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 240 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 241 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 242 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 243 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 246 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 247 "data/maps/RustboroCity/scripts.pory"
	walk_up
	step_end

# 250 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GoToPlayerUpgradeLeft:
# 251 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 252 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 253 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 254 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 257 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GoToPlayerUpgradeRight:
# 258 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 259 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 260 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 261 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 264 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1LeaveAfterPokenav:
# 265 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 265 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 265 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 265 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 266 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 267 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 287 "data/maps/RustboroCity/scripts.pory"

# 288 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 289 "data/maps/RustboroCity/scripts.pory"
	lock
# 290 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 291 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 292 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 293 "data/maps/RustboroCity/scripts.pory"
	release
# 294 "data/maps/RustboroCity/scripts.pory"
	end
# 295 "data/maps/RustboroCity/scripts.pory"

# 296 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 297 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 298 "data/maps/RustboroCity/scripts.pory"
	release
# 299 "data/maps/RustboroCity/scripts.pory"
	end
# 300 "data/maps/RustboroCity/scripts.pory"

# 301 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 302 "data/maps/RustboroCity/scripts.pory"
	lock
# 303 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 304 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 305 "data/maps/RustboroCity/scripts.pory"
	release
# 306 "data/maps/RustboroCity/scripts.pory"
	end
# 307 "data/maps/RustboroCity/scripts.pory"

# 308 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 309 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 310 "data/maps/RustboroCity/scripts.pory"
	end
# 311 "data/maps/RustboroCity/scripts.pory"

# 312 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 313 "data/maps/RustboroCity/scripts.pory"
	lock
# 314 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 315 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 316 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 317 "data/maps/RustboroCity/scripts.pory"
	release
# 318 "data/maps/RustboroCity/scripts.pory"
	end
# 319 "data/maps/RustboroCity/scripts.pory"

# 320 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 321 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 322 "data/maps/RustboroCity/scripts.pory"
	release
# 323 "data/maps/RustboroCity/scripts.pory"
	end
# 324 "data/maps/RustboroCity/scripts.pory"

# 325 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 326 "data/maps/RustboroCity/scripts.pory"
	lock
# 327 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 328 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 329 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 330 "data/maps/RustboroCity/scripts.pory"
	release
# 331 "data/maps/RustboroCity/scripts.pory"
	end
# 332 "data/maps/RustboroCity/scripts.pory"

# 333 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 334 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 335 "data/maps/RustboroCity/scripts.pory"
	release
# 336 "data/maps/RustboroCity/scripts.pory"
	end
# 337 "data/maps/RustboroCity/scripts.pory"

# 338 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 339 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 340 "data/maps/RustboroCity/scripts.pory"
	end
# 341 "data/maps/RustboroCity/scripts.pory"

# 342 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 343 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 344 "data/maps/RustboroCity/scripts.pory"
	end
# 345 "data/maps/RustboroCity/scripts.pory"

# 346 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 347 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 348 "data/maps/RustboroCity/scripts.pory"
	end
# 349 "data/maps/RustboroCity/scripts.pory"

# 350 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 351 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 352 "data/maps/RustboroCity/scripts.pory"
	end
# 353 "data/maps/RustboroCity/scripts.pory"

# 354 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 355 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 356 "data/maps/RustboroCity/scripts.pory"
	end
# 357 "data/maps/RustboroCity/scripts.pory"

# 358 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 360 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 361 "data/maps/RustboroCity/scripts.pory"
	end
# 362 "data/maps/RustboroCity/scripts.pory"

# 363 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 364 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 365 "data/maps/RustboroCity/scripts.pory"
	end
# 366 "data/maps/RustboroCity/scripts.pory"

# 367 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 368 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 369 "data/maps/RustboroCity/scripts.pory"
	end
# 370 "data/maps/RustboroCity/scripts.pory"

# 371 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 372 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 373 "data/maps/RustboroCity/scripts.pory"
	end
# 374 "data/maps/RustboroCity/scripts.pory"

# 375 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 376 "data/maps/RustboroCity/scripts.pory"
	lock
# 377 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 378 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 379 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 380 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 381 "data/maps/RustboroCity/scripts.pory"
	release
# 382 "data/maps/RustboroCity/scripts.pory"
	end
# 383 "data/maps/RustboroCity/scripts.pory"

# 384 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 385 "data/maps/RustboroCity/scripts.pory"
	lock
# 386 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 387 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 388 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 389 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 390 "data/maps/RustboroCity/scripts.pory"
	release
# 391 "data/maps/RustboroCity/scripts.pory"
	end
# 392 "data/maps/RustboroCity/scripts.pory"

# 393 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 394 "data/maps/RustboroCity/scripts.pory"
	lock
# 395 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 396 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 397 "data/maps/RustboroCity/scripts.pory"
	release
# 398 "data/maps/RustboroCity/scripts.pory"
	end
# 399 "data/maps/RustboroCity/scripts.pory"

# 400 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 401 "data/maps/RustboroCity/scripts.pory"
	lockall
# 402 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 403 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 404 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 405 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 406 "data/maps/RustboroCity/scripts.pory"
	end
# 407 "data/maps/RustboroCity/scripts.pory"

# 408 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 409 "data/maps/RustboroCity/scripts.pory"
	lockall
# 410 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 411 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 412 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 413 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 414 "data/maps/RustboroCity/scripts.pory"
	end
# 415 "data/maps/RustboroCity/scripts.pory"

# 416 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 417 "data/maps/RustboroCity/scripts.pory"
	lockall
# 418 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 419 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 420 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 421 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 422 "data/maps/RustboroCity/scripts.pory"
	end
# 423 "data/maps/RustboroCity/scripts.pory"

# 424 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 425 "data/maps/RustboroCity/scripts.pory"
	lockall
# 426 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 427 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 428 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 429 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 430 "data/maps/RustboroCity/scripts.pory"
	end
# 431 "data/maps/RustboroCity/scripts.pory"

# 432 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 433 "data/maps/RustboroCity/scripts.pory"
	lockall
# 434 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 435 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 436 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 437 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 438 "data/maps/RustboroCity/scripts.pory"
	end
# 439 "data/maps/RustboroCity/scripts.pory"

# 440 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 441 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 442 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 443 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 444 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 445 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 446 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 447 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 448 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 449 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 450 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 451 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 452 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 453 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 454 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 455 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 456 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 457 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 458 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 459 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 460 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 461 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 462 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 463 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 464 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 465 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 466 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 467 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 468 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 469 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 470 "data/maps/RustboroCity/scripts.pory"
	end
# 471 "data/maps/RustboroCity/scripts.pory"

# 472 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 473 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 474 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 475 "data/maps/RustboroCity/scripts.pory"
	return
# 476 "data/maps/RustboroCity/scripts.pory"

# 477 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 478 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 479 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 480 "data/maps/RustboroCity/scripts.pory"
	return
# 481 "data/maps/RustboroCity/scripts.pory"

# 482 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 483 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 484 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 485 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 486 "data/maps/RustboroCity/scripts.pory"
	return
# 487 "data/maps/RustboroCity/scripts.pory"

# 488 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 489 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 490 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 491 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 492 "data/maps/RustboroCity/scripts.pory"
	return
# 493 "data/maps/RustboroCity/scripts.pory"

# 494 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 495 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 496 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 497 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 498 "data/maps/RustboroCity/scripts.pory"
	return
# 499 "data/maps/RustboroCity/scripts.pory"

# 500 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 501 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 502 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 503 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 504 "data/maps/RustboroCity/scripts.pory"
	return
# 505 "data/maps/RustboroCity/scripts.pory"

# 506 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 507 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 508 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 509 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 510 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 511 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 512 "data/maps/RustboroCity/scripts.pory"
	return
# 513 "data/maps/RustboroCity/scripts.pory"

# 514 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 515 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 516 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 517 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 518 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 519 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 520 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 521 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 531 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 532 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 533 "data/maps/RustboroCity/scripts.pory"
	step_end
# 534 "data/maps/RustboroCity/scripts.pory"

# 535 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 536 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 537 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 538 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 539 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 540 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 541 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 542 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 550 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 551 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 552 "data/maps/RustboroCity/scripts.pory"
	step_end
# 553 "data/maps/RustboroCity/scripts.pory"

# 554 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 555 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 556 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 557 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 558 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 559 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 560 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 561 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 562 "data/maps/RustboroCity/scripts.pory"
	step_end
# 563 "data/maps/RustboroCity/scripts.pory"

# 564 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 565 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 566 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 567 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 568 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 569 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 570 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 571 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 572 "data/maps/RustboroCity/scripts.pory"
	step_end
# 573 "data/maps/RustboroCity/scripts.pory"

# 574 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 575 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 576 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 577 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 578 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 579 "data/maps/RustboroCity/scripts.pory"
	step_end
# 580 "data/maps/RustboroCity/scripts.pory"

# 581 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 582 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 583 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 584 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 585 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 586 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 587 "data/maps/RustboroCity/scripts.pory"
	step_end
# 588 "data/maps/RustboroCity/scripts.pory"

# 589 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 590 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 591 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 592 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 593 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 594 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 595 "data/maps/RustboroCity/scripts.pory"
	step_end
# 596 "data/maps/RustboroCity/scripts.pory"

# 597 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 598 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 599 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 600 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 601 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 602 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 603 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 604 "data/maps/RustboroCity/scripts.pory"
	step_end
# 605 "data/maps/RustboroCity/scripts.pory"

# 606 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 607 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 608 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 609 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 610 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 611 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 612 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 613 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 614 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 615 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 619 "data/maps/RustboroCity/scripts.pory"
	lock
# 620 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 621 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 622 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 623 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 628 "data/maps/RustboroCity/scripts.pory"
	waitse
# 629 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 630 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 635 "data/maps/RustboroCity/scripts.pory"
	lockall
# 636 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 637 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 642 "data/maps/RustboroCity/scripts.pory"
	lockall
# 643 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 644 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 649 "data/maps/RustboroCity/scripts.pory"
	lockall
# 650 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 651 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 656 "data/maps/RustboroCity/scripts.pory"
	lockall
# 657 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 658 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 663 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 664 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 665 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 666 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 667 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 668 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 669 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 670 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 671 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm 9
# 672 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 673 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 674 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 679 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 680 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 681 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 682 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_NoticeRival1
# 683 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 684 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 685 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 686 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachPlayer
# 687 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 688 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 689 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 690 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 691 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 692 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 693 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 694 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 695 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 699 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 703 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 704 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 709 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 710 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 711 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 712 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 716 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 718 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 719 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 720 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 721 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 722 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 725 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 728 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 729 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 733 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 734 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 735 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 736 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceRight
# 737 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 738 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 739 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 741 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 743 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 745 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_20
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 748 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 749 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 750 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 751 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 29, 10
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 696 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 697 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 698 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 700 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 701 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceDown
# 702 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 705 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 706 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 707 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 713 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 723 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 724 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 726 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 727 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 730 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 731 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 740 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 742 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 744 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger2
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_20:
# 746 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 757 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 758 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 759 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 760 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 761 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 762 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 763 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 764 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 765 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 766 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 771 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 772 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 773 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 774 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 775 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 776 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 777 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 778 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 779 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 784 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 785 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 786 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 787 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 788 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 789 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 790 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 791 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 792 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 793 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 798 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 799 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 800 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 801 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 802 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 803 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 804 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 805 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 806 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 807 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 808 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 809 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 12
	return


# 813 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 814 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 815 "data/maps/RustboroCity/scripts.pory"
	step_end

# 818 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_NoticeRival1:
# 819 "data/maps/RustboroCity/scripts.pory"
	emote_exclamation_mark
# 820 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_left
	step_end

# 823 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 824 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 827 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 828 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 828 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 828 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 829 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 832 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 833 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 834 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 834 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 837 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 838 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 839 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 839 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 840 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 840 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 843 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 844 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 845 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 845 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 848 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 849 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 849 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 852 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 853 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 853 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 856 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 857 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 857 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 860 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 861 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 861 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 864 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 865 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 866 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 866 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 869 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 870 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 870 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 871 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 872 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 875 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 876 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 877 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 880 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2:
# 881 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 882 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 883 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 886 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger3:
# 887 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 887 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 888 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 889 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
# 920 "data/maps/RustboroCity/scripts.pory"
	lockall
# 921 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 922 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerUp2
# 923 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger1::
# 928 "data/maps/RustboroCity/scripts.pory"
	lockall
# 929 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 930 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 931 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger2::
# 936 "data/maps/RustboroCity/scripts.pory"
	lockall
# 937 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 938 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerDown2
# 939 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger3::
# 944 "data/maps/RustboroCity/scripts.pory"
	lockall
# 945 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 946 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 947 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoods::
# 952 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 953 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 954 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 955 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_ReturnGoods_2
# 959 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_EAST
RustboroCity_EventScript_ReturnGoods_1:
# 961 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 962 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 963 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 964 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 965 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 966 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 967 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 968 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 969 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 970 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_ReturnGoods_2:
# 956 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_NORTH
	goto RustboroCity_EventScript_ReturnGoods_1


RustboroCity_EventScript_BagFull::
# 975 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return


RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 980 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 981 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 982 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 983 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 984 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 985 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 986 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 987 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 988 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 989 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 990 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 995 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
# 996 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterRight
# 997 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 998 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 999 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1000 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1001 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1002 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1003 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_RivalMoveForReturnGoodsRight
# 1004 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1005 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 1006 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 1011 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 1012 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 1013 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1014 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1015 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1016 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1017 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1018 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1019 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1020 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1021 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 1026 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 1027 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 1028 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1029 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1030 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1031 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1032 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1033 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1034 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1035 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 1036 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_EmployeeApproachPlayerDown
# 1037 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1038 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1039 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerRight::
# 1044 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 1045 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1046 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1047 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1048 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1049 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1050 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_Rival1::
# 1055 "data/maps/RustboroCity/scripts.pory"
	lock
# 1056 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 1057 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq RustboroCity_EventScript_Rival1_2
RustboroCity_EventScript_Rival1_1:
# 1061 "data/maps/RustboroCity/scripts.pory"
	release
	end

RustboroCity_EventScript_Rival1_2:
# 1058 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_Rival1_Text_0, MSGBOX_DEFAULT
# 1059 "data/maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_Rival1_1


# 1065 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalMoveForReturnGoodsRight:
# 1066 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1066 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1067 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1068 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

RustboroCity_EventScript_Rival2::
# 1072 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1073 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 7
	goto_if_eq RustboroCity_EventScript_Rival2_2
RustboroCity_EventScript_Rival2_1:
# 1076 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_FacePlayer
# 1077 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1078 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 2
# 1079 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return

RustboroCity_EventScript_Rival2_2:
# 1074 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	goto RustboroCity_EventScript_Rival2_1


RustboroCity_EventScript_RivalTrigger0::
# 1083 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1084 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1085 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1086 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1087 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1088 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1089 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1090 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1091 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1092 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1093 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer0
# 1094 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1095 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1096 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1097 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger1::
# 1101 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1102 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1103 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1104 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1105 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1106 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1107 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1108 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1109 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1110 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1111 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer1
# 1112 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1113 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1114 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1115 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger2::
# 1119 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1120 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1121 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1122 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1123 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1124 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1125 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1126 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1127 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1128 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1129 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer2
# 1130 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1131 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1132 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1133 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger3::
# 1137 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1138 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1139 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1140 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1141 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1142 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1143 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1144 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1145 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1146 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1147 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer3
# 1148 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1149 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1150 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1151 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger4::
# 1155 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1156 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1157 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1158 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1159 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1160 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1161 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1162 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1163 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1164 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1165 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer4
# 1166 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1167 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1168 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1169 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger5::
# 1173 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1174 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1175 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1176 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1177 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1178 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1179 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1180 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1181 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1182 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1183 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer5
# 1184 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1185 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1186 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1187 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger6::
# 1191 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1192 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1193 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1194 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1195 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1196 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1197 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1198 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1199 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1200 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1201 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer6
# 1202 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1203 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1204 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1205 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger7::
# 1209 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1210 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 7
# 1211 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1212 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1213 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1214 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1215 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1216 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1217 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1218 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1219 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer7
# 1220 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1221 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1222 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1223 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalEncounter::
# 1227 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8005, 2
	goto_if_eq RustboroCity_EventScript_RivalEncounter_2
# 1231 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouThoughtYoudWalkBy, MSGBOX_DEFAULT
RustboroCity_EventScript_RivalEncounter_1:
# 1233 "data/maps/RustboroCity/scripts.pory"
	checkfriendchoice
# 1234 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 1235 "data/maps/RustboroCity/scripts.pory"
	case SPENCER, RustboroCity_EventScript_RivalEncounter_7
# 1237 "data/maps/RustboroCity/scripts.pory"
	case BREN, RustboroCity_EventScript_RivalEncounter_8
# 1239 "data/maps/RustboroCity/scripts.pory"
	case KYLE, RustboroCity_EventScript_RivalEncounter_9
RustboroCity_EventScript_RivalEncounter_5:
# 1242 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1243 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8005, 2
	goto_if_eq RustboroCity_EventScript_RivalEncounter_11
# 1259 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
RustboroCity_EventScript_RivalEncounter_10:
# 1261 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1262 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1263 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GoingToAnIslandTown, MSGBOX_DEFAULT
# 1264 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1265 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1266 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8005, 2
	goto_if_eq RustboroCity_EventScript_RivalEncounter_15
# 1282 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
RustboroCity_EventScript_RivalEncounter_14:
# 1284 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1285 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1286 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonWantsToGiveReward, MSGBOX_DEFAULT
# 1287 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1288 "data/maps/RustboroCity/scripts.pory"
	switch VAR_0x8005
# 1289 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_RivalEncounter_29
# 1291 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_RivalEncounter_30
# 1294 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack
RustboroCity_EventScript_RivalEncounter_27:
# 1296 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1297 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontLeaveWithoutMe
# 1298 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1299 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8005, 2
	goto_if_eq RustboroCity_EventScript_RivalEncounter_42
# 1303 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalGoToDevonTriggered
RustboroCity_EventScript_RivalEncounter_41:
# 1305 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1306 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1307 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1308 "data/maps/RustboroCity/scripts.pory"
	removeobject 14
# 1309 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 1310 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RIVAL2_DEVON_2F
# 1311 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1312 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_RivalEncounter_2:
# 1228 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LongTimeNoSee, MSGBOX_DEFAULT
	goto RustboroCity_EventScript_RivalEncounter_1

RustboroCity_EventScript_RivalEncounter_7:
# 1236 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_RUSTBORO, RustboroCity_Text_RivalEndBattleKyle
	goto RustboroCity_EventScript_RivalEncounter_5

RustboroCity_EventScript_RivalEncounter_8:
# 1238 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_RUSTBORO, RustboroCity_Text_RivalEndBattleSpencer
	goto RustboroCity_EventScript_RivalEncounter_5

RustboroCity_EventScript_RivalEncounter_9:
# 1240 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_RUSTBORO, RustboroCity_Text_RivalEndBattleBren
	goto RustboroCity_EventScript_RivalEncounter_5

RustboroCity_EventScript_RivalEncounter_11:
# 1244 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 1245 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 15
	goto_if_eq RustboroCity_EventScript_RivalEncounter_18
# 1248 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 16
	goto_if_eq RustboroCity_EventScript_RivalEncounter_23
RustboroCity_EventScript_RivalEncounter_22:
# 1251 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 17
	goto_if_eq RustboroCity_EventScript_RivalEncounter_20
# 1255 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_15:
# 1267 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 1268 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 15
	goto_if_eq RustboroCity_EventScript_RivalEncounter_32
# 1271 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 16
	goto_if_eq RustboroCity_EventScript_RivalEncounter_37
RustboroCity_EventScript_RivalEncounter_36:
# 1274 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_0, 17
	goto_if_eq RustboroCity_EventScript_RivalEncounter_34
# 1278 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
	goto RustboroCity_EventScript_RivalEncounter_14

RustboroCity_EventScript_RivalEncounter_18:
# 1246 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkRight
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_19:
# 1249 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkDown
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_20:
# 1252 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkLeft
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_23:
# 1248 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 49
	goto_if_eq RustboroCity_EventScript_RivalEncounter_19
	goto RustboroCity_EventScript_RivalEncounter_22

RustboroCity_EventScript_RivalEncounter_29:
# 1290 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_WalkAwayByFacing
	goto RustboroCity_EventScript_RivalEncounter_27

RustboroCity_EventScript_RivalEncounter_30:
# 1292 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack7
	goto RustboroCity_EventScript_RivalEncounter_27

RustboroCity_EventScript_RivalEncounter_32:
# 1269 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkRight
	goto RustboroCity_EventScript_RivalEncounter_14

RustboroCity_EventScript_RivalEncounter_33:
# 1272 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkDown
	goto RustboroCity_EventScript_RivalEncounter_14

RustboroCity_EventScript_RivalEncounter_34:
# 1275 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkLeft
	goto RustboroCity_EventScript_RivalEncounter_14

RustboroCity_EventScript_RivalEncounter_37:
# 1271 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 49
	goto_if_eq RustboroCity_EventScript_RivalEncounter_33
	goto RustboroCity_EventScript_RivalEncounter_36

RustboroCity_EventScript_RivalEncounter_42:
# 1300 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalGoToDevonTalked
	goto RustboroCity_EventScript_RivalEncounter_41


RustboroCity_EventScript_WalkAwayByFacing::
# 1317 "data/maps/RustboroCity/scripts.pory"
	switch VAR_FACING
# 1318 "data/maps/RustboroCity/scripts.pory"
	case DIR_SOUTH, RustboroCity_EventScript_WalkAwayByFacing_3
# 1322 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 1323 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack2NWE
RustboroCity_EventScript_WalkAwayByFacing_1:
	return

RustboroCity_EventScript_WalkAwayByFacing_3:
# 1319 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWatchRivalLeaveSouth
# 1320 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack2South
	goto RustboroCity_EventScript_WalkAwayByFacing_1


# 1328 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack:
# 1329 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1329 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1329 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1331 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 1331 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
	step_end

# 1334 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack2NWE:
# 1335 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1335 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1335 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1336 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1336 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1336 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1337 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1337 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1337 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1337 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1338 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1338 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1339 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_down
	step_end

# 1342 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack2South:
# 1343 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1344 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1344 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1344 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1344 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1345 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1345 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1347 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1347 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1348 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_down
	step_end

# 1351 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack7:
# 1352 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1353 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1354 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1354 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1355 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1355 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1355 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1355 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1356 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 1356 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
	step_end

# 1359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalGoToDevonTalked:
# 1360 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1360 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1360 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1361 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1361 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1361 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1361 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1362 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 1365 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalGoToDevonTriggered:
# 1366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1366 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1367 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 1370 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWatchRivalLeaveSouth:
# 1371 "data/maps/RustboroCity/scripts.pory"
	delay_8
# 1372 "data/maps/RustboroCity/scripts.pory"
	face_right
# 1373 "data/maps/RustboroCity/scripts.pory"
	delay_8
# 1374 "data/maps/RustboroCity/scripts.pory"
	face_up
	step_end

# 1432 "data/maps/RustboroCity/scripts.pory"

# 1433 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1434 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1435 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1436 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1437 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1438 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1439 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1440 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1441 "data/maps/RustboroCity/scripts.pory"

# 1442 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1443 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1444 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1445 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1446 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1447 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1448 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1449 "data/maps/RustboroCity/scripts.pory"

# 1450 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1451 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1452 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1453 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1454 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1455 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1456 "data/maps/RustboroCity/scripts.pory"

# 1457 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1458 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1459 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1460 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1461 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1462 "data/maps/RustboroCity/scripts.pory"

# 1463 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1464 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1465 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1466 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1467 "data/maps/RustboroCity/scripts.pory"

# 1468 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1469 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1470 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1471 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1472 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1473 "data/maps/RustboroCity/scripts.pory"

# 1474 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1475 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1476 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1477 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1478 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1479 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1480 "data/maps/RustboroCity/scripts.pory"

# 1481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1482 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1483 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1484 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1485 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1486 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1487 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1488 "data/maps/RustboroCity/scripts.pory"

# 1489 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1490 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1491 "data/maps/RustboroCity/scripts.pory"
	end
# 1492 "data/maps/RustboroCity/scripts.pory"

# 1493 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1494 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1495 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1496 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1497 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1498 "data/maps/RustboroCity/scripts.pory"

# 1499 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1500 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1501 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1502 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1503 "data/maps/RustboroCity/scripts.pory"

# 1504 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1505 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1506 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1507 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1508 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1509 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1510 "data/maps/RustboroCity/scripts.pory"

# 1511 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1512 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1513 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1514 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1515 "data/maps/RustboroCity/scripts.pory"

# 1516 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1517 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1518 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1519 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1520 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1521 "data/maps/RustboroCity/scripts.pory"

# 1522 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1523 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1524 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1525 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1526 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1527 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1528 "data/maps/RustboroCity/scripts.pory"

# 1529 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1530 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1531 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1532 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1533 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1534 "data/maps/RustboroCity/scripts.pory"

# 1535 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1536 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1537 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1538 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1539 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1540 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1541 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1542 "data/maps/RustboroCity/scripts.pory"

# 1543 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1544 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1545 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1546 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1547 "data/maps/RustboroCity/scripts.pory"

# 1548 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1549 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1550 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1551 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1552 "data/maps/RustboroCity/scripts.pory"

# 1553 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1554 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1555 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1556 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1557 "data/maps/RustboroCity/scripts.pory"

# 1558 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1559 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1560 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1561 "data/maps/RustboroCity/scripts.pory"

# 1562 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1563 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1564 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1565 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1566 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1567 "data/maps/RustboroCity/scripts.pory"

# 1568 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1569 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1570 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1571 "data/maps/RustboroCity/scripts.pory"

# 1572 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1573 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1574 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1575 "data/maps/RustboroCity/scripts.pory"

# 1576 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1577 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1578 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1579 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1580 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1581 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1582 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1583 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1584 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1585 "data/maps/RustboroCity/scripts.pory"

# 1586 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1587 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1588 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"

# 1612 "data/maps/RustboroCity/scripts.pory"

# 1613 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1614 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1615 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1616 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1617 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1618 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1619 "data/maps/RustboroCity/scripts.pory"

# 1620 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1621 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1622 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1623 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1624 "data/maps/RustboroCity/scripts.pory"

# 1625 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1626 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1627 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1628 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1629 "data/maps/RustboroCity/scripts.pory"

# 1630 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1631 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1632 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1633 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1634 "data/maps/RustboroCity/scripts.pory"

# 1635 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1636 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1637 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1638 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1639 "data/maps/RustboroCity/scripts.pory"

# 1640 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1641 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1642 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1643 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1644 "data/maps/RustboroCity/scripts.pory"

# 1645 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1646 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1647 "data/maps/RustboroCity/scripts.pory"

# 1648 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1649 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1650 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1651 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1652 "data/maps/RustboroCity/scripts.pory"
	.string "You two, may I see those POKéNAVS?\n"
# 1653 "data/maps/RustboroCity/scripts.pory"
	.string "The ones our PRESIDENT gave you?$"
# 1654 "data/maps/RustboroCity/scripts.pory"

# 1655 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1656 "data/maps/RustboroCity/scripts.pory"
	.string "There you go!\p"
# 1657 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1658 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1659 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1660 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1661 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1662 "data/maps/RustboroCity/scripts.pory"
	.string "Our PRESIDENT STONE should\n"
# 1663 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1664 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1665 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1666 "data/maps/RustboroCity/scripts.pory"

# 1667 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1668 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1669 "data/maps/RustboroCity/scripts.pory"

# 1670 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1671 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1672 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}, {RIVAL}!$"
# 1673 "data/maps/RustboroCity/scripts.pory"

# 1674 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1675 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1676 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1677 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1678 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1679 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1680 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1681 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1682 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_Rival1_Text_0:
# 1058 "data/maps/RustboroCity/scripts.pory"
	.string "Aren't you going to\nreturn the GOODS?$"

RustboroCity_Text_Rival1LetsRegister::
# 270 "data/maps/RustboroCity/scripts.pory"
	.string "This is great!\n"
	.string "Let's register each other right now!$"

RustboroCity_Text_RegisteredRival1::
# 275 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER} registered {RIVAL}\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_SeeYouSoon::
# 280 "data/maps/RustboroCity/scripts.pory"
	.string "Now we can call each other whenever we\n"
	.string "want!\l"
	.string "I'm going to try to catch a last minute\l"
	.string "SLAKOTH in PETALBURG WOODS.\l"
	.string "You should find {RIVAL2} and meet me at\l"
	.string "MR. BRINEY'S cottage.\p"
	.string "See you soon!$"

RustboroCity_Text_YoPlayer::
# 892 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 896 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 901 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 905 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 909 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 914 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"

RustboroCity_Text_LongTimeNoSee::
# 1377 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, {PLAYER}!\n"
	.string "Long time no see.\p"
	.string "{RIVAL} told me that you stomped\n"
	.string "that AQUA thug yet again.\l"
	.string "And this time you did it solo!\l"
	.string "That's impressive!\p"
	.string "That settles it.\n"
	.string "I need to see you in action.\l"
	.string "Time for a battle!$"

RustboroCity_Text_YouThoughtYoudWalkBy::
# 1388 "data/maps/RustboroCity/scripts.pory"
	.string "You thought you'd just walk right by\n"
	.string "without so much as a 'hello'?\l"
	.string "I know it's been a little while,\l"
	.string "but c'mon!\p"
	.string "{RIVAL} told me that you stomped\n"
	.string "that AQUA thug yet again.\l"
	.string "And this time you did it solo!\l"
	.string "Very impressive!\p"
	.string "That settles it.\n"
	.string "I need to see you in action.\l"
	.string "Time for a battle!$"

RustboroCity_Text_RivalEndBattleSpencer::
# 1399 "data/maps/RustboroCity/scripts.pory"
	.string "Would you look at that!\n"
	.string "I lost!$"

RustboroCity_Text_RivalEndBattleBren::
# 1404 "data/maps/RustboroCity/scripts.pory"
	.string "You and your POKéMON have got some\n"
	.string "good teamwork!$"

RustboroCity_Text_RivalEndBattleKyle::
# 1408 "data/maps/RustboroCity/scripts.pory"
	.string "Huh.\n"
	.string "I lost again.$"

RustboroCity_Text_GoingToAnIslandTown::
# 1413 "data/maps/RustboroCity/scripts.pory"
	.string "What's that?\n"
	.string "You and {RIVAL} are going to ask an\l"
	.string "old sailor to take you to an island\l"
	.string "town?\p"
	.string "That sounds awesome!\n"
	.string "I want to come too!$"

RustboroCity_Text_DevonWantsToGiveReward::
# 1420 "data/maps/RustboroCity/scripts.pory"
	.string "What's that?\n"
	.string "The president of the DEVON corporation\l"
	.string "wants to give me a reward?\p"
	.string "Wow! I'd better go to the DEVON\n"
	.string "building!\l"
	.string "Thanks for letting me know.$"

RustboroCity_Text_DontLeaveWithoutMe::
# 1427 "data/maps/RustboroCity/scripts.pory"
	.string "I'll meet you at the old man's cottage\n"
	.string "when I'm done.\l"
	.string "Don't leave without me!$"

RustboroCity_Text_YouGotItThankYou::
# 1591 "data/maps/RustboroCity/scripts.pory"
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
# 1602 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_PleaseComeWithMe::
# 1607 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
	.string "Both of you please come with me!$"
