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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 209 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1LeaveAfterPokenav
# 210 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 211 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 212 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 213 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_DEVON_3F_RIVAL1
# 214 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 215 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 216 "data/maps/RustboroCity/scripts.pory"
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


# 220 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 221 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 225 "data/maps/RustboroCity/scripts.pory"
	walk_down
	step_end

# 228 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 229 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 230 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 234 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 235 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 236 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 237 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 238 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 239 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 240 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 241 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 244 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 245 "data/maps/RustboroCity/scripts.pory"
	walk_up
	step_end

# 248 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GoToPlayerUpgradeLeft:
# 249 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 250 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 251 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 252 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 255 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GoToPlayerUpgradeRight:
# 256 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 257 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 258 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 259 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 262 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1LeaveAfterPokenav:
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 263 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 264 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 265 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 285 "data/maps/RustboroCity/scripts.pory"

# 286 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 287 "data/maps/RustboroCity/scripts.pory"
	lock
# 288 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 289 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 290 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 291 "data/maps/RustboroCity/scripts.pory"
	release
# 292 "data/maps/RustboroCity/scripts.pory"
	end
# 293 "data/maps/RustboroCity/scripts.pory"

# 294 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 295 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 296 "data/maps/RustboroCity/scripts.pory"
	release
# 297 "data/maps/RustboroCity/scripts.pory"
	end
# 298 "data/maps/RustboroCity/scripts.pory"

# 299 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 300 "data/maps/RustboroCity/scripts.pory"
	lock
# 301 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 302 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 303 "data/maps/RustboroCity/scripts.pory"
	release
# 304 "data/maps/RustboroCity/scripts.pory"
	end
# 305 "data/maps/RustboroCity/scripts.pory"

# 306 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 307 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 308 "data/maps/RustboroCity/scripts.pory"
	end
# 309 "data/maps/RustboroCity/scripts.pory"

# 310 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 311 "data/maps/RustboroCity/scripts.pory"
	lock
# 312 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 313 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 314 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 315 "data/maps/RustboroCity/scripts.pory"
	release
# 316 "data/maps/RustboroCity/scripts.pory"
	end
# 317 "data/maps/RustboroCity/scripts.pory"

# 318 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 319 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 320 "data/maps/RustboroCity/scripts.pory"
	release
# 321 "data/maps/RustboroCity/scripts.pory"
	end
# 322 "data/maps/RustboroCity/scripts.pory"

# 323 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 324 "data/maps/RustboroCity/scripts.pory"
	lock
# 325 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 326 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 327 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 328 "data/maps/RustboroCity/scripts.pory"
	release
# 329 "data/maps/RustboroCity/scripts.pory"
	end
# 330 "data/maps/RustboroCity/scripts.pory"

# 331 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 332 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 333 "data/maps/RustboroCity/scripts.pory"
	release
# 334 "data/maps/RustboroCity/scripts.pory"
	end
# 335 "data/maps/RustboroCity/scripts.pory"

# 336 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 337 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 338 "data/maps/RustboroCity/scripts.pory"
	end
# 339 "data/maps/RustboroCity/scripts.pory"

# 340 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 341 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 342 "data/maps/RustboroCity/scripts.pory"
	end
# 343 "data/maps/RustboroCity/scripts.pory"

# 344 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 345 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 346 "data/maps/RustboroCity/scripts.pory"
	end
# 347 "data/maps/RustboroCity/scripts.pory"

# 348 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 349 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 350 "data/maps/RustboroCity/scripts.pory"
	end
# 351 "data/maps/RustboroCity/scripts.pory"

# 352 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 353 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 354 "data/maps/RustboroCity/scripts.pory"
	end
# 355 "data/maps/RustboroCity/scripts.pory"

# 356 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 357 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 358 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 359 "data/maps/RustboroCity/scripts.pory"
	end
# 360 "data/maps/RustboroCity/scripts.pory"

# 361 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 362 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 363 "data/maps/RustboroCity/scripts.pory"
	end
# 364 "data/maps/RustboroCity/scripts.pory"

# 365 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 366 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 367 "data/maps/RustboroCity/scripts.pory"
	end
# 368 "data/maps/RustboroCity/scripts.pory"

# 369 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 370 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 371 "data/maps/RustboroCity/scripts.pory"
	end
# 372 "data/maps/RustboroCity/scripts.pory"

# 373 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 374 "data/maps/RustboroCity/scripts.pory"
	lock
# 375 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 376 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 377 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 378 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 379 "data/maps/RustboroCity/scripts.pory"
	release
# 380 "data/maps/RustboroCity/scripts.pory"
	end
# 381 "data/maps/RustboroCity/scripts.pory"

# 382 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 383 "data/maps/RustboroCity/scripts.pory"
	lock
# 384 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 385 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 386 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 387 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 388 "data/maps/RustboroCity/scripts.pory"
	release
# 389 "data/maps/RustboroCity/scripts.pory"
	end
# 390 "data/maps/RustboroCity/scripts.pory"

# 391 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 392 "data/maps/RustboroCity/scripts.pory"
	lock
# 393 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 394 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 395 "data/maps/RustboroCity/scripts.pory"
	release
# 396 "data/maps/RustboroCity/scripts.pory"
	end
# 397 "data/maps/RustboroCity/scripts.pory"

# 398 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 399 "data/maps/RustboroCity/scripts.pory"
	lockall
# 400 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 401 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 402 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 403 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 404 "data/maps/RustboroCity/scripts.pory"
	end
# 405 "data/maps/RustboroCity/scripts.pory"

# 406 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 407 "data/maps/RustboroCity/scripts.pory"
	lockall
# 408 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 409 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 410 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 411 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 412 "data/maps/RustboroCity/scripts.pory"
	end
# 413 "data/maps/RustboroCity/scripts.pory"

# 414 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 415 "data/maps/RustboroCity/scripts.pory"
	lockall
# 416 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 417 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 418 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 419 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 420 "data/maps/RustboroCity/scripts.pory"
	end
# 421 "data/maps/RustboroCity/scripts.pory"

# 422 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 423 "data/maps/RustboroCity/scripts.pory"
	lockall
# 424 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 425 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 426 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 427 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 428 "data/maps/RustboroCity/scripts.pory"
	end
# 429 "data/maps/RustboroCity/scripts.pory"

# 430 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 431 "data/maps/RustboroCity/scripts.pory"
	lockall
# 432 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 433 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 434 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 435 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 436 "data/maps/RustboroCity/scripts.pory"
	end
# 437 "data/maps/RustboroCity/scripts.pory"

# 438 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 439 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 440 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 441 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 442 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 443 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 444 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 445 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 446 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 447 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 448 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 449 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 450 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 451 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 452 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 453 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 454 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 455 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 456 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 457 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 458 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 459 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 460 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 461 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 462 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 463 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 464 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 465 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 466 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 467 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 468 "data/maps/RustboroCity/scripts.pory"
	end
# 469 "data/maps/RustboroCity/scripts.pory"

# 470 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 471 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 472 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 473 "data/maps/RustboroCity/scripts.pory"
	return
# 474 "data/maps/RustboroCity/scripts.pory"

# 475 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 476 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 477 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 478 "data/maps/RustboroCity/scripts.pory"
	return
# 479 "data/maps/RustboroCity/scripts.pory"

# 480 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 482 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 483 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 484 "data/maps/RustboroCity/scripts.pory"
	return
# 485 "data/maps/RustboroCity/scripts.pory"

# 486 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 487 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 488 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 489 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 490 "data/maps/RustboroCity/scripts.pory"
	return
# 491 "data/maps/RustboroCity/scripts.pory"

# 492 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 493 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 494 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 495 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 496 "data/maps/RustboroCity/scripts.pory"
	return
# 497 "data/maps/RustboroCity/scripts.pory"

# 498 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 499 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 500 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 501 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 502 "data/maps/RustboroCity/scripts.pory"
	return
# 503 "data/maps/RustboroCity/scripts.pory"

# 504 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 505 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 506 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 507 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 508 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 509 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 510 "data/maps/RustboroCity/scripts.pory"
	return
# 511 "data/maps/RustboroCity/scripts.pory"

# 512 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 513 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 514 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 515 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 516 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 517 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 518 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 519 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 531 "data/maps/RustboroCity/scripts.pory"
	step_end
# 532 "data/maps/RustboroCity/scripts.pory"

# 533 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 534 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 535 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 536 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 537 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 538 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 539 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 540 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 550 "data/maps/RustboroCity/scripts.pory"
	step_end
# 551 "data/maps/RustboroCity/scripts.pory"

# 552 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
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
	walk_right
# 559 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 560 "data/maps/RustboroCity/scripts.pory"
	step_end
# 561 "data/maps/RustboroCity/scripts.pory"

# 562 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
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
	walk_up
# 570 "data/maps/RustboroCity/scripts.pory"
	step_end
# 571 "data/maps/RustboroCity/scripts.pory"

# 572 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 573 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 574 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 575 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 576 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 577 "data/maps/RustboroCity/scripts.pory"
	step_end
# 578 "data/maps/RustboroCity/scripts.pory"

# 579 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 580 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 581 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 582 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 583 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 584 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 585 "data/maps/RustboroCity/scripts.pory"
	step_end
# 586 "data/maps/RustboroCity/scripts.pory"

# 587 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 588 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 589 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 590 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 591 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 592 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 593 "data/maps/RustboroCity/scripts.pory"
	step_end
# 594 "data/maps/RustboroCity/scripts.pory"

# 595 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 596 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 597 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 598 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 599 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 600 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 601 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 602 "data/maps/RustboroCity/scripts.pory"
	step_end
# 603 "data/maps/RustboroCity/scripts.pory"

# 604 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 605 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 606 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 607 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 608 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 609 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 610 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 611 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 612 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 613 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 617 "data/maps/RustboroCity/scripts.pory"
	lock
# 618 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 619 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 620 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 621 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 626 "data/maps/RustboroCity/scripts.pory"
	waitse
# 627 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 628 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 633 "data/maps/RustboroCity/scripts.pory"
	lockall
# 634 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 635 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 640 "data/maps/RustboroCity/scripts.pory"
	lockall
# 641 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 642 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 647 "data/maps/RustboroCity/scripts.pory"
	lockall
# 648 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 649 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 654 "data/maps/RustboroCity/scripts.pory"
	lockall
# 655 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 656 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 661 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 662 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 663 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 664 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 665 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 666 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 667 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 668 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 669 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm 9
# 670 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 671 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 672 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 677 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 678 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 679 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 680 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_NoticeRival1
# 681 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 682 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 683 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 684 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachPlayer
# 685 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 686 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 687 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 688 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 689 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 690 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 691 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 692 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 693 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 697 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 701 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 702 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 707 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 708 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 709 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 710 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 714 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 716 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 717 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 718 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 719 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 720 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 723 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 726 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 727 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 731 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 732 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 733 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 734 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceRight
# 735 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 736 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 737 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 739 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 741 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 743 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_20
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 746 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 747 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 748 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 749 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 29, 10
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 694 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 695 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 696 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 698 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 699 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceDown
# 700 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 703 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 704 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 705 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 711 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 721 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 722 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 724 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 725 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 728 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 729 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 738 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 740 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 742 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger2
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_20:
# 744 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 755 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 756 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 757 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 758 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 759 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 760 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 761 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 762 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 763 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 764 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 769 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 770 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 771 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 772 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 773 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 774 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 775 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 776 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 777 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 782 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 783 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 784 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 785 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 786 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 787 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 788 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 789 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 790 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 791 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 796 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 797 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 798 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 799 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 800 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 801 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 802 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 803 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 804 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 805 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 806 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 807 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 12
	return


# 811 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 812 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 813 "data/maps/RustboroCity/scripts.pory"
	step_end

# 816 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_NoticeRival1:
# 817 "data/maps/RustboroCity/scripts.pory"
	emote_exclamation_mark
# 818 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_left
	step_end

# 821 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 822 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 825 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 826 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 826 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 826 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 827 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 830 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 831 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 832 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 832 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 835 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 836 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 837 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 837 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 838 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 838 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 841 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 842 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 843 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 843 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 846 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 847 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 847 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 850 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 851 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 851 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 854 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 855 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 855 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 858 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 859 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 859 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 862 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 863 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 864 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 864 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 867 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 868 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 869 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 870 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 873 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 874 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 875 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 878 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2:
# 879 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 880 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 881 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 884 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger3:
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 885 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 886 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 887 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
# 918 "data/maps/RustboroCity/scripts.pory"
	lockall
# 919 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 920 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerUp2
# 921 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger1::
# 926 "data/maps/RustboroCity/scripts.pory"
	lockall
# 927 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 928 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 929 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger2::
# 934 "data/maps/RustboroCity/scripts.pory"
	lockall
# 935 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 936 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerDown2
# 937 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger3::
# 942 "data/maps/RustboroCity/scripts.pory"
	lockall
# 943 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 944 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 945 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoods::
# 950 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 951 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 952 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 953 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_ReturnGoods_2
# 957 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_EAST
RustboroCity_EventScript_ReturnGoods_1:
# 959 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 960 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 961 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 962 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 963 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 964 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 965 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 966 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 967 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 968 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_ReturnGoods_2:
# 954 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_NORTH
	goto RustboroCity_EventScript_ReturnGoods_1


RustboroCity_EventScript_BagFull::
# 973 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return


RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 978 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 979 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 980 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 981 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 982 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 983 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 984 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 985 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 986 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 987 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 988 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 993 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
# 994 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterRight
# 995 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 996 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 997 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 998 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 999 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1000 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1001 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_RivalMoveForReturnGoodsRight
# 1002 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1003 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 1004 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 1009 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 1010 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 1011 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1012 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1013 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1014 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1015 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1016 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1017 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1018 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1019 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 1024 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 1025 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 1026 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1027 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1028 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1029 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 1030 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1031 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1032 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1033 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 1034 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_EmployeeApproachPlayerDown
# 1035 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1036 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1037 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerRight::
# 1042 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 1043 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1044 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1045 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 1046 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1047 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 1048 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_Rival1::
# 1053 "data/maps/RustboroCity/scripts.pory"
	lock
# 1054 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 1055 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq RustboroCity_EventScript_Rival1_2
RustboroCity_EventScript_Rival1_1:
# 1059 "data/maps/RustboroCity/scripts.pory"
	release
	end

RustboroCity_EventScript_Rival1_2:
# 1056 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_Rival1_Text_0, MSGBOX_DEFAULT
# 1057 "data/maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_Rival1_1


# 1063 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalMoveForReturnGoodsRight:
# 1064 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1064 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 1065 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1066 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

RustboroCity_EventScript_Rival2::
# 1070 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1071 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 7
	goto_if_eq RustboroCity_EventScript_Rival2_2
RustboroCity_EventScript_Rival2_1:
# 1074 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_FacePlayer
# 1075 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1076 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 2
# 1077 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return

RustboroCity_EventScript_Rival2_2:
# 1072 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	goto RustboroCity_EventScript_Rival2_1


RustboroCity_EventScript_RivalTrigger0::
# 1081 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1082 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1083 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1084 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1085 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1086 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1087 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1088 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1089 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1090 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1091 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer0
# 1092 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1093 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1094 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1095 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger1::
# 1099 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1100 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1101 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1102 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1103 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1104 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1105 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1106 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1107 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1108 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1109 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer1
# 1110 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1111 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1112 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1113 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger2::
# 1117 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1118 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1119 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1120 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1121 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1122 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1123 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1124 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1125 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1126 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1127 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer2
# 1128 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1129 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1130 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1131 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger3::
# 1135 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1136 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1137 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1138 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1139 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1140 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1141 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1142 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1143 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1144 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1145 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer3
# 1146 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1147 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1148 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1149 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger4::
# 1153 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1154 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1155 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1156 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1157 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1158 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1159 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1160 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1161 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1162 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1163 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer4
# 1164 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1165 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1166 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1167 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger5::
# 1171 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1172 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1173 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1174 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1175 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1176 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1177 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1178 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1179 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1180 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1181 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer5
# 1182 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1183 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1184 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1185 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger6::
# 1189 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1190 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 0
# 1191 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1192 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1193 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1194 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1195 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1196 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1197 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1198 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1199 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer6
# 1200 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1201 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1202 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1203 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalTrigger7::
# 1207 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1208 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8005, 7
# 1209 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 1210 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_WalkInPlaceFasterDown
# 1211 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1212 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1213 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_ExclamationMark
# 1214 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1215 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, Common_Movement_Delay48
# 1216 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1217 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalApproachPlayer7
# 1218 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1219 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1220 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1221 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
	return


RustboroCity_EventScript_RivalEncounter::
# 1225 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8005, 2
	goto_if_eq RustboroCity_EventScript_RivalEncounter_2
# 1229 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouThoughtYoudWalkBy, MSGBOX_DEFAULT
RustboroCity_EventScript_RivalEncounter_1:
# 1231 "data/maps/RustboroCity/scripts.pory"
	checkfriendchoice
# 1232 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 1233 "data/maps/RustboroCity/scripts.pory"
	case SPENCER, RustboroCity_EventScript_RivalEncounter_7
# 1235 "data/maps/RustboroCity/scripts.pory"
	case BREN, RustboroCity_EventScript_RivalEncounter_8
# 1237 "data/maps/RustboroCity/scripts.pory"
	case KYLE, RustboroCity_EventScript_RivalEncounter_9
RustboroCity_EventScript_RivalEncounter_5:
# 1240 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1241 "data/maps/RustboroCity/scripts.pory"
	switch VAR_FACING
# 1242 "data/maps/RustboroCity/scripts.pory"
	case DIR_NORTH, RustboroCity_EventScript_RivalEncounter_12
# 1244 "data/maps/RustboroCity/scripts.pory"
	case DIR_EAST, RustboroCity_EventScript_RivalEncounter_13
# 1246 "data/maps/RustboroCity/scripts.pory"
	case DIR_WEST, RustboroCity_EventScript_RivalEncounter_14
# 1248 "data/maps/RustboroCity/scripts.pory"
	case DIR_SOUTH, RustboroCity_EventScript_RivalEncounter_15
# 1251 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
RustboroCity_EventScript_RivalEncounter_10:
# 1253 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1254 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1255 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GoingToAnIslandTown, MSGBOX_DEFAULT
# 1256 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1257 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1258 "data/maps/RustboroCity/scripts.pory"
	switch VAR_FACING
# 1259 "data/maps/RustboroCity/scripts.pory"
	case DIR_NORTH, RustboroCity_EventScript_RivalEncounter_19
# 1261 "data/maps/RustboroCity/scripts.pory"
	case DIR_EAST, RustboroCity_EventScript_RivalEncounter_20
# 1263 "data/maps/RustboroCity/scripts.pory"
	case DIR_WEST, RustboroCity_EventScript_RivalEncounter_21
# 1265 "data/maps/RustboroCity/scripts.pory"
	case DIR_SOUTH, RustboroCity_EventScript_RivalEncounter_22
# 1268 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
RustboroCity_EventScript_RivalEncounter_17:
# 1270 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1271 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 1272 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonWantsToGiveReward, MSGBOX_DEFAULT
# 1273 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1274 "data/maps/RustboroCity/scripts.pory"
	switch VAR_0x8005
# 1275 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_RivalEncounter_26
# 1277 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_RivalEncounter_27
# 1280 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack
RustboroCity_EventScript_RivalEncounter_24:
# 1282 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1283 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontLeaveWithoutMe
# 1284 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1285 "data/maps/RustboroCity/scripts.pory"
	compare VAR_0x8005, 2
	goto_if_eq RustboroCity_EventScript_RivalEncounter_30
# 1289 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalGoToDevonTriggered
RustboroCity_EventScript_RivalEncounter_29:
# 1291 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1292 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1293 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1294 "data/maps/RustboroCity/scripts.pory"
	removeobject 14
# 1295 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 1296 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RIVAL2_DEVON_2F
# 1297 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1298 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_RivalEncounter_2:
# 1226 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LongTimeNoSee, MSGBOX_DEFAULT
	goto RustboroCity_EventScript_RivalEncounter_1

RustboroCity_EventScript_RivalEncounter_7:
# 1234 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_RUSTBORO, RustboroCity_Text_RivalEndBattle
	goto RustboroCity_EventScript_RivalEncounter_5

RustboroCity_EventScript_RivalEncounter_8:
# 1236 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_RUSTBORO, RustboroCity_Text_RivalEndBattle
	goto RustboroCity_EventScript_RivalEncounter_5

RustboroCity_EventScript_RivalEncounter_9:
# 1238 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_RUSTBORO, RustboroCity_Text_RivalEndBattle
	goto RustboroCity_EventScript_RivalEncounter_5

RustboroCity_EventScript_RivalEncounter_12:
# 1243 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_13:
# 1245 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkRight
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_14:
# 1247 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkLeft
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_15:
# 1249 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkDown
	goto RustboroCity_EventScript_RivalEncounter_10

RustboroCity_EventScript_RivalEncounter_19:
# 1260 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkUp
	goto RustboroCity_EventScript_RivalEncounter_17

RustboroCity_EventScript_RivalEncounter_20:
# 1262 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkRight
	goto RustboroCity_EventScript_RivalEncounter_17

RustboroCity_EventScript_RivalEncounter_21:
# 1264 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkLeft
	goto RustboroCity_EventScript_RivalEncounter_17

RustboroCity_EventScript_RivalEncounter_22:
# 1266 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_BeginTalkDown
	goto RustboroCity_EventScript_RivalEncounter_17

RustboroCity_EventScript_RivalEncounter_26:
# 1276 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_WalkAwayByFacing
	goto RustboroCity_EventScript_RivalEncounter_24

RustboroCity_EventScript_RivalEncounter_27:
# 1278 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack7
	goto RustboroCity_EventScript_RivalEncounter_24

RustboroCity_EventScript_RivalEncounter_30:
# 1286 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_RivalGoToDevonTalked
	goto RustboroCity_EventScript_RivalEncounter_29


RustboroCity_EventScript_WalkAwayByFacing::
# 1303 "data/maps/RustboroCity/scripts.pory"
	switch VAR_FACING
# 1304 "data/maps/RustboroCity/scripts.pory"
	case DIR_SOUTH, RustboroCity_EventScript_WalkAwayByFacing_3
# 1308 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 1309 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack2NWE
RustboroCity_EventScript_WalkAwayByFacing_1:
	return

RustboroCity_EventScript_WalkAwayByFacing_3:
# 1305 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWatchRivalLeaveSouth
# 1306 "data/maps/RustboroCity/scripts.pory"
	applymovement 14, RustboroCity_Movement_Rival2WalkAwayComeBack2South
	goto RustboroCity_EventScript_WalkAwayByFacing_1


# 1314 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack:
# 1315 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1315 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1315 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1316 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1316 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1316 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1316 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1317 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 1317 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
	step_end

# 1320 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack2NWE:
# 1321 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1321 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1321 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1322 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1322 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1322 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1323 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1323 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1323 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1323 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1324 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1324 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1325 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_down
	step_end

# 1328 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack2South:
# 1329 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1330 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1331 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1331 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1332 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1332 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1332 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1332 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_right
# 1333 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1333 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1334 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_down
	step_end

# 1337 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival2WalkAwayComeBack7:
# 1338 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1339 "data/maps/RustboroCity/scripts.pory"
	walk_fast_left
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1340 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1341 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1341 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1341 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1341 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_fast_up
# 1342 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 1342 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
	step_end

# 1345 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalGoToDevonTalked:
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1346 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 1347 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1347 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1347 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1347 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1348 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 1351 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalGoToDevonTriggered:
# 1352 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1352 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1352 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1352 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 1353 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 1356 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWatchRivalLeaveSouth:
# 1357 "data/maps/RustboroCity/scripts.pory"
	delay_8
# 1358 "data/maps/RustboroCity/scripts.pory"
	face_right
# 1359 "data/maps/RustboroCity/scripts.pory"
	delay_8
# 1360 "data/maps/RustboroCity/scripts.pory"
	face_up
	step_end

# 1409 "data/maps/RustboroCity/scripts.pory"

# 1410 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1411 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1412 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1413 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1414 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1415 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1416 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1417 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1418 "data/maps/RustboroCity/scripts.pory"

# 1419 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1420 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1421 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1422 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1423 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1424 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1425 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1426 "data/maps/RustboroCity/scripts.pory"

# 1427 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1428 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1429 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1430 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1431 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1432 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1433 "data/maps/RustboroCity/scripts.pory"

# 1434 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1435 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1436 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1437 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1438 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1439 "data/maps/RustboroCity/scripts.pory"

# 1440 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1441 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1442 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1443 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1444 "data/maps/RustboroCity/scripts.pory"

# 1445 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1446 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1447 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1448 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1449 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1450 "data/maps/RustboroCity/scripts.pory"

# 1451 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1452 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1453 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1454 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1455 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1456 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1457 "data/maps/RustboroCity/scripts.pory"

# 1458 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1459 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1460 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1461 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1462 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1463 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1464 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1465 "data/maps/RustboroCity/scripts.pory"

# 1466 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1467 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1468 "data/maps/RustboroCity/scripts.pory"
	end
# 1469 "data/maps/RustboroCity/scripts.pory"

# 1470 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1471 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1472 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1473 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1474 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1475 "data/maps/RustboroCity/scripts.pory"

# 1476 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1477 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1478 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1479 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1480 "data/maps/RustboroCity/scripts.pory"

# 1481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1482 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1483 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1484 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1485 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1486 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1487 "data/maps/RustboroCity/scripts.pory"

# 1488 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1489 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1490 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1491 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1492 "data/maps/RustboroCity/scripts.pory"

# 1493 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1494 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1495 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1496 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1497 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1498 "data/maps/RustboroCity/scripts.pory"

# 1499 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1500 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1501 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1502 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1503 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1504 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1505 "data/maps/RustboroCity/scripts.pory"

# 1506 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1507 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1508 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1509 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1510 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1511 "data/maps/RustboroCity/scripts.pory"

# 1512 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1513 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1514 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1515 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1516 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1517 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1518 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1519 "data/maps/RustboroCity/scripts.pory"

# 1520 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1521 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1522 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1523 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1524 "data/maps/RustboroCity/scripts.pory"

# 1525 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1526 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1527 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1528 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1529 "data/maps/RustboroCity/scripts.pory"

# 1530 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1531 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1532 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1533 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1534 "data/maps/RustboroCity/scripts.pory"

# 1535 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1536 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1537 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1538 "data/maps/RustboroCity/scripts.pory"

# 1539 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1540 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1541 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1542 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1543 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1544 "data/maps/RustboroCity/scripts.pory"

# 1545 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1546 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1547 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1548 "data/maps/RustboroCity/scripts.pory"

# 1549 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1550 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1551 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1552 "data/maps/RustboroCity/scripts.pory"

# 1553 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1554 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1555 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1556 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1557 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1558 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1559 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1560 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1561 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1562 "data/maps/RustboroCity/scripts.pory"

# 1563 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1564 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1565 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"

# 1589 "data/maps/RustboroCity/scripts.pory"

# 1590 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1591 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1592 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1593 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1594 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1595 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1596 "data/maps/RustboroCity/scripts.pory"

# 1597 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1598 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1599 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1600 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1601 "data/maps/RustboroCity/scripts.pory"

# 1602 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1603 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1604 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1605 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1606 "data/maps/RustboroCity/scripts.pory"

# 1607 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1608 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1609 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1610 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1611 "data/maps/RustboroCity/scripts.pory"

# 1612 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1613 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1614 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1615 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1616 "data/maps/RustboroCity/scripts.pory"

# 1617 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1618 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1619 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1620 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1621 "data/maps/RustboroCity/scripts.pory"

# 1622 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1623 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1624 "data/maps/RustboroCity/scripts.pory"

# 1625 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1626 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1627 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1628 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1629 "data/maps/RustboroCity/scripts.pory"
	.string "You two, may I see those POKéNAVS?\n"
# 1630 "data/maps/RustboroCity/scripts.pory"
	.string "The ones our PRESIDENT gave you?$"
# 1631 "data/maps/RustboroCity/scripts.pory"

# 1632 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1633 "data/maps/RustboroCity/scripts.pory"
	.string "There you go!\p"
# 1634 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1635 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1636 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1637 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1638 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1639 "data/maps/RustboroCity/scripts.pory"
	.string "Our PRESIDENT STONE should\n"
# 1640 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1641 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1642 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1643 "data/maps/RustboroCity/scripts.pory"

# 1644 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1645 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1646 "data/maps/RustboroCity/scripts.pory"

# 1647 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1648 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1649 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}, {RIVAL}!$"
# 1650 "data/maps/RustboroCity/scripts.pory"

# 1651 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1652 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1653 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1654 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1655 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1656 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1657 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1658 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1659 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_Rival1_Text_0:
# 1056 "data/maps/RustboroCity/scripts.pory"
	.string "Aren't you going to\nreturn the GOODS?$"

RustboroCity_Text_Rival1LetsRegister::
# 268 "data/maps/RustboroCity/scripts.pory"
	.string "This is great!\n"
	.string "Let's register each other right now!$"

RustboroCity_Text_RegisteredRival1::
# 273 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER} registered {RIVAL}\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_SeeYouSoon::
# 278 "data/maps/RustboroCity/scripts.pory"
	.string "Now we can call each other whenever we\n"
	.string "want!\l"
	.string "I'm going to try to catch a last minute\l"
	.string "SLAKOTH in PETALBURG WOODS.\l"
	.string "You should find {RIVAL2} and meet me at\l"
	.string "MR. BRINEY'S cottage.\p"
	.string "See you soon!$"

RustboroCity_Text_YoPlayer::
# 890 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 894 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 899 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 903 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 907 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 912 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"

RustboroCity_Text_LongTimeNoSee::
# 1363 "data/maps/RustboroCity/scripts.pory"
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
# 1374 "data/maps/RustboroCity/scripts.pory"
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

RustboroCity_Text_RivalEndBattle::
# 1385 "data/maps/RustboroCity/scripts.pory"
	.string "Would you look at that!\n"
	.string "I lost!$"

RustboroCity_Text_GoingToAnIslandTown::
# 1390 "data/maps/RustboroCity/scripts.pory"
	.string "What's that?\n"
	.string "You and {RIVAL} are going to ask an\l"
	.string "old sailor to take you to an island\l"
	.string "town?\p"
	.string "That sounds awesome!\n"
	.string "I want to come too!$"

RustboroCity_Text_DevonWantsToGiveReward::
# 1397 "data/maps/RustboroCity/scripts.pory"
	.string "What's that?\n"
	.string "The president of the DEVON corporation\l"
	.string "wants to give me a reward?\p"
	.string "Wow! I'd better go to the DEVON\n"
	.string "building!\l"
	.string "Thanks for letting me know.$"

RustboroCity_Text_DontLeaveWithoutMe::
# 1404 "data/maps/RustboroCity/scripts.pory"
	.string "I'll meet you at the old man's cottage\n"
	.string "when I'm done.\l"
	.string "Don't leave without me!$"

RustboroCity_Text_YouGotItThankYou::
# 1568 "data/maps/RustboroCity/scripts.pory"
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
# 1579 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_PleaseComeWithMe::
# 1584 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
	.string "Both of you please come with me!$"
