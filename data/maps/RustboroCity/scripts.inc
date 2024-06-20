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

# 29 "data/maps/RustboroCity/scripts.pory"

# 30 "data/maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 31 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 32 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 33 "data/maps/RustboroCity/scripts.pory"
	.byte 0
# 34 "data/maps/RustboroCity/scripts.pory"

# 35 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnTransition:
# 36 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 37 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 38 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 1, RustboroCity_EventScript_SetRivalForRetrieveGoods
# 39 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_EventScript_SetRivalForRetrieveGoods
# 40 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 4, RustboroCity_EventScript_SetForReturnGoods
# 41 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 42 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 43 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
# 44 "data/maps/RustboroCity/scripts.pory"
	end
# 45 "data/maps/RustboroCity/scripts.pory"

# 46 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 47 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 48 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 12, 15
# 49 "data/maps/RustboroCity/scripts.pory"
	end
# 50 "data/maps/RustboroCity/scripts.pory"

# 51 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 52 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 11, 15
# 53 "data/maps/RustboroCity/scripts.pory"
	end
# 54 "data/maps/RustboroCity/scripts.pory"

# 55 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 56 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 57 "data/maps/RustboroCity/scripts.pory"
	return

RustboroCity_EventScript_SetRivalForRetrieveGoods::
# 61 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 21, 10
	return


RustboroCity_EventScript_SetForReturnGoods::
# 65 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	return


# 68 "data/maps/RustboroCity/scripts.pory"

# 69 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 70 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 71 "data/maps/RustboroCity/scripts.pory"
	.2byte 0
# 72 "data/maps/RustboroCity/scripts.pory"

# 73 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 74 "data/maps/RustboroCity/scripts.pory"
	lockall
# 75 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 76 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 77 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 78 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 79 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 80 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_SCIENTIST
# 81 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 82 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 83 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 84 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
# 85 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 86 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
# 87 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 88 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 89 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 90 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 91 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 93 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 94 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 95 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 96 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 97 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 98 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 99 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 100 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 101 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 102 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 103 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 104 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 105 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 106 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 107 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 108 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 109 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 110 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 111 "data/maps/RustboroCity/scripts.pory"

# 112 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 113 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 114 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 115 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 116 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 117 "data/maps/RustboroCity/scripts.pory"

# 118 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 119 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 120 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 121 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 122 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 123 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 124 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 125 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 126 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 127 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 128 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 129 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 130 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 131 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 132 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 133 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 134 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 135 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 136 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 137 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 138 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 139 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_SCIENTIST
# 140 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 141 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 142 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 143 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 144 "data/maps/RustboroCity/scripts.pory"
	end
# 145 "data/maps/RustboroCity/scripts.pory"

# 146 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 147 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 148 "data/maps/RustboroCity/scripts.pory"
	step_end
# 149 "data/maps/RustboroCity/scripts.pory"

# 150 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 151 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 152 "data/maps/RustboroCity/scripts.pory"
	step_end
# 153 "data/maps/RustboroCity/scripts.pory"

# 154 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 155 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 156 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 157 "data/maps/RustboroCity/scripts.pory"
	step_end
# 158 "data/maps/RustboroCity/scripts.pory"

# 159 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 160 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 161 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 162 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 163 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 164 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 165 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 166 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 167 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 168 "data/maps/RustboroCity/scripts.pory"
	step_end
# 169 "data/maps/RustboroCity/scripts.pory"

# 170 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 171 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 172 "data/maps/RustboroCity/scripts.pory"
	step_end
# 173 "data/maps/RustboroCity/scripts.pory"

# 174 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 175 "data/maps/RustboroCity/scripts.pory"
	lock
# 176 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 177 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 178 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 179 "data/maps/RustboroCity/scripts.pory"
	release
# 180 "data/maps/RustboroCity/scripts.pory"
	end
# 181 "data/maps/RustboroCity/scripts.pory"

# 182 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 183 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 184 "data/maps/RustboroCity/scripts.pory"
	release
# 185 "data/maps/RustboroCity/scripts.pory"
	end
# 186 "data/maps/RustboroCity/scripts.pory"

# 187 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 188 "data/maps/RustboroCity/scripts.pory"
	lock
# 189 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 190 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 191 "data/maps/RustboroCity/scripts.pory"
	release
# 192 "data/maps/RustboroCity/scripts.pory"
	end
# 193 "data/maps/RustboroCity/scripts.pory"

# 194 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 195 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 196 "data/maps/RustboroCity/scripts.pory"
	end
# 197 "data/maps/RustboroCity/scripts.pory"

# 198 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 199 "data/maps/RustboroCity/scripts.pory"
	lock
# 200 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 201 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 202 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 203 "data/maps/RustboroCity/scripts.pory"
	release
# 204 "data/maps/RustboroCity/scripts.pory"
	end
# 205 "data/maps/RustboroCity/scripts.pory"

# 206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 207 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 208 "data/maps/RustboroCity/scripts.pory"
	release
# 209 "data/maps/RustboroCity/scripts.pory"
	end
# 210 "data/maps/RustboroCity/scripts.pory"

# 211 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 212 "data/maps/RustboroCity/scripts.pory"
	lock
# 213 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 214 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 215 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 216 "data/maps/RustboroCity/scripts.pory"
	release
# 217 "data/maps/RustboroCity/scripts.pory"
	end
# 218 "data/maps/RustboroCity/scripts.pory"

# 219 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 220 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 221 "data/maps/RustboroCity/scripts.pory"
	release
# 222 "data/maps/RustboroCity/scripts.pory"
	end
# 223 "data/maps/RustboroCity/scripts.pory"

# 224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 225 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 226 "data/maps/RustboroCity/scripts.pory"
	end
# 227 "data/maps/RustboroCity/scripts.pory"

# 228 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 229 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 230 "data/maps/RustboroCity/scripts.pory"
	end
# 231 "data/maps/RustboroCity/scripts.pory"

# 232 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 233 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 234 "data/maps/RustboroCity/scripts.pory"
	end
# 235 "data/maps/RustboroCity/scripts.pory"

# 236 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 237 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 238 "data/maps/RustboroCity/scripts.pory"
	end
# 239 "data/maps/RustboroCity/scripts.pory"

# 240 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 241 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 242 "data/maps/RustboroCity/scripts.pory"
	end
# 243 "data/maps/RustboroCity/scripts.pory"

# 244 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 245 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 246 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 247 "data/maps/RustboroCity/scripts.pory"
	end
# 248 "data/maps/RustboroCity/scripts.pory"

# 249 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 250 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 251 "data/maps/RustboroCity/scripts.pory"
	end
# 252 "data/maps/RustboroCity/scripts.pory"

# 253 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 254 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 255 "data/maps/RustboroCity/scripts.pory"
	end
# 256 "data/maps/RustboroCity/scripts.pory"

# 257 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 258 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 259 "data/maps/RustboroCity/scripts.pory"
	end
# 260 "data/maps/RustboroCity/scripts.pory"

# 261 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 262 "data/maps/RustboroCity/scripts.pory"
	lock
# 263 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 264 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 265 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 266 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 267 "data/maps/RustboroCity/scripts.pory"
	release
# 268 "data/maps/RustboroCity/scripts.pory"
	end
# 269 "data/maps/RustboroCity/scripts.pory"

# 270 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 271 "data/maps/RustboroCity/scripts.pory"
	lock
# 272 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 273 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 274 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 275 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 276 "data/maps/RustboroCity/scripts.pory"
	release
# 277 "data/maps/RustboroCity/scripts.pory"
	end
# 278 "data/maps/RustboroCity/scripts.pory"

# 279 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 280 "data/maps/RustboroCity/scripts.pory"
	lock
# 281 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 282 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 283 "data/maps/RustboroCity/scripts.pory"
	release
# 284 "data/maps/RustboroCity/scripts.pory"
	end
# 285 "data/maps/RustboroCity/scripts.pory"

# 286 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 287 "data/maps/RustboroCity/scripts.pory"
	lockall
# 288 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 289 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 290 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 291 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 292 "data/maps/RustboroCity/scripts.pory"
	end
# 293 "data/maps/RustboroCity/scripts.pory"

# 294 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 295 "data/maps/RustboroCity/scripts.pory"
	lockall
# 296 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 297 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 298 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 299 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 300 "data/maps/RustboroCity/scripts.pory"
	end
# 301 "data/maps/RustboroCity/scripts.pory"

# 302 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 303 "data/maps/RustboroCity/scripts.pory"
	lockall
# 304 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 305 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 306 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 307 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 308 "data/maps/RustboroCity/scripts.pory"
	end
# 309 "data/maps/RustboroCity/scripts.pory"

# 310 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 311 "data/maps/RustboroCity/scripts.pory"
	lockall
# 312 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 313 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 314 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 315 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 316 "data/maps/RustboroCity/scripts.pory"
	end
# 317 "data/maps/RustboroCity/scripts.pory"

# 318 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 319 "data/maps/RustboroCity/scripts.pory"
	lockall
# 320 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 321 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 322 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 323 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 324 "data/maps/RustboroCity/scripts.pory"
	end
# 325 "data/maps/RustboroCity/scripts.pory"

# 326 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 327 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 328 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 329 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 330 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 331 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 332 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 333 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 334 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 335 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 336 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 337 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 338 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 339 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 340 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 341 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 342 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 343 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 344 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 345 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 346 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 347 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 348 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 349 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 350 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 351 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 352 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 353 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 354 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 355 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 356 "data/maps/RustboroCity/scripts.pory"
	end
# 357 "data/maps/RustboroCity/scripts.pory"

# 358 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 360 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 361 "data/maps/RustboroCity/scripts.pory"
	return
# 362 "data/maps/RustboroCity/scripts.pory"

# 363 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 364 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 365 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 366 "data/maps/RustboroCity/scripts.pory"
	return
# 367 "data/maps/RustboroCity/scripts.pory"

# 368 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 369 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 370 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 371 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 372 "data/maps/RustboroCity/scripts.pory"
	return
# 373 "data/maps/RustboroCity/scripts.pory"

# 374 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 375 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 376 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 377 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 378 "data/maps/RustboroCity/scripts.pory"
	return
# 379 "data/maps/RustboroCity/scripts.pory"

# 380 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 381 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 382 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 383 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 384 "data/maps/RustboroCity/scripts.pory"
	return
# 385 "data/maps/RustboroCity/scripts.pory"

# 386 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 387 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 388 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 389 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 390 "data/maps/RustboroCity/scripts.pory"
	return
# 391 "data/maps/RustboroCity/scripts.pory"

# 392 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 393 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 394 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 395 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 396 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 397 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 398 "data/maps/RustboroCity/scripts.pory"
	return
# 399 "data/maps/RustboroCity/scripts.pory"

# 400 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 401 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 402 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 404 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 405 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 406 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 407 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 408 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 409 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 410 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 411 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 412 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 413 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 414 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 415 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 416 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 417 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 418 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 419 "data/maps/RustboroCity/scripts.pory"
	step_end
# 420 "data/maps/RustboroCity/scripts.pory"

# 421 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 422 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 423 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 424 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 425 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 426 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 427 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 428 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 429 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 430 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 431 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 432 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 433 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 434 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 435 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 436 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 437 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 438 "data/maps/RustboroCity/scripts.pory"
	step_end
# 439 "data/maps/RustboroCity/scripts.pory"

# 440 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 441 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 442 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 443 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 444 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 445 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 446 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 447 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 448 "data/maps/RustboroCity/scripts.pory"
	step_end
# 449 "data/maps/RustboroCity/scripts.pory"

# 450 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 451 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 452 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 453 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 454 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 455 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 456 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 457 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 458 "data/maps/RustboroCity/scripts.pory"
	step_end
# 459 "data/maps/RustboroCity/scripts.pory"

# 460 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 461 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 462 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 463 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 464 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 465 "data/maps/RustboroCity/scripts.pory"
	step_end
# 466 "data/maps/RustboroCity/scripts.pory"

# 467 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 468 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 469 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 470 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 471 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 472 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 473 "data/maps/RustboroCity/scripts.pory"
	step_end
# 474 "data/maps/RustboroCity/scripts.pory"

# 475 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 476 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 477 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 478 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 479 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 480 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 481 "data/maps/RustboroCity/scripts.pory"
	step_end
# 482 "data/maps/RustboroCity/scripts.pory"

# 483 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 484 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 485 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 486 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 487 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 488 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 489 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 490 "data/maps/RustboroCity/scripts.pory"
	step_end
# 491 "data/maps/RustboroCity/scripts.pory"

# 492 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 493 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 494 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 495 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 496 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 497 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 498 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 499 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 500 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 501 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 505 "data/maps/RustboroCity/scripts.pory"
	lock
# 506 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 507 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 508 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 509 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 514 "data/maps/RustboroCity/scripts.pory"
	waitse
# 515 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 516 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 521 "data/maps/RustboroCity/scripts.pory"
	lockall
# 522 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 523 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 528 "data/maps/RustboroCity/scripts.pory"
	lockall
# 529 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 530 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 535 "data/maps/RustboroCity/scripts.pory"
	lockall
# 536 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 537 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 542 "data/maps/RustboroCity/scripts.pory"
	lockall
# 543 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 544 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 549 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 550 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 551 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 552 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 553 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 554 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 555 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 556 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 557 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm 9
# 558 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 559 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 560 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 565 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 566 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 567 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 568 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_NoticeRival1
# 569 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 570 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 571 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 572 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachPlayer
# 573 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 574 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 575 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 576 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 577 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 578 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 579 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 580 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 581 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 585 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 589 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 590 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 595 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 596 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 597 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 598 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 602 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 604 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 605 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 606 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 607 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 608 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 611 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 614 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 615 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 619 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 620 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 621 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 622 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceRight
# 623 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 624 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 625 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 627 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 629 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 631 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_20
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 634 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 635 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 636 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
# 637 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 29, 10
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 582 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 583 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 584 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 586 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 587 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceDown
# 588 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 591 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 592 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 593 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 599 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 609 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 610 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 612 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 613 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 616 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 617 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 626 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 628 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 630 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger2
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_20:
# 632 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 643 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 644 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 645 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 646 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 647 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 648 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 649 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 650 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 651 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 652 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 657 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 658 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 659 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 660 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 661 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 662 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 663 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 664 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 665 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 670 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 671 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 672 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 673 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 674 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 675 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 676 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 677 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 678 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 679 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 684 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 685 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 686 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 687 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 688 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 689 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 690 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 691 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 692 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 693 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 694 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 695 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 12
	return


# 699 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 700 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 701 "data/maps/RustboroCity/scripts.pory"
	step_end

# 704 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_NoticeRival1:
# 705 "data/maps/RustboroCity/scripts.pory"
	emote_exclamation_mark
# 706 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_left
	step_end

# 709 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 710 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 713 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 714 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 714 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 714 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 715 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 718 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 719 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 720 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 720 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 723 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 724 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 725 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 725 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 726 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 726 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 729 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 730 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 731 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 731 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 734 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 738 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 739 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 739 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 742 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 743 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 743 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 746 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 747 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 747 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 750 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 755 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 758 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 761 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 763 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 766 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2:
# 767 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 768 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 769 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 772 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger3:
# 773 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 773 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 774 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 775 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0::
# 806 "data/maps/RustboroCity/scripts.pory"
	lockall
# 807 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 808 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerUp2
# 809 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger1::
# 814 "data/maps/RustboroCity/scripts.pory"
	lockall
# 815 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 816 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 817 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger2::
# 822 "data/maps/RustboroCity/scripts.pory"
	lockall
# 823 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 824 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerDown2
# 825 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger3::
# 830 "data/maps/RustboroCity/scripts.pory"
	lockall
# 831 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 832 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 833 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoods::
# 838 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 839 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 840 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 841 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_ReturnGoods_2
# 845 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_EAST
RustboroCity_EventScript_ReturnGoods_1:
# 847 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 848 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 849 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 850 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 851 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 852 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 853 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 854 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 855 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 856 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end

RustboroCity_EventScript_ReturnGoods_2:
# 842 "data/maps/RustboroCity/scripts.pory"
	turnobject 17, DIR_NORTH
	goto RustboroCity_EventScript_ReturnGoods_1


RustboroCity_EventScript_BagFull::
# 861 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return


RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 866 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 867 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 868 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 869 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 870 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 871 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 872 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 873 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 874 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 875 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 876 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 881 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
# 882 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterRight
# 883 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 884 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 885 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 886 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 887 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 888 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 889 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_RivalMoveForReturnGoodsRight
# 890 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 891 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 892 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 897 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 898 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 899 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 900 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 901 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 902 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 903 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 904 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 905 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 906 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 907 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 912 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 913 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 914 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 915 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 916 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 917 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 918 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 919 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 920 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 921 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 922 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_EmployeeApproachPlayerDown
# 923 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 924 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 925 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerRight::
# 930 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 931 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 932 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 933 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 934 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 935 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 936 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_Rival1::
# 941 "data/maps/RustboroCity/scripts.pory"
	lock
# 942 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 943 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq RustboroCity_EventScript_Rival1_2
RustboroCity_EventScript_Rival1_1:
# 947 "data/maps/RustboroCity/scripts.pory"
	release
	end

RustboroCity_EventScript_Rival1_2:
# 944 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_Rival1_Text_0, MSGBOX_DEFAULT
# 945 "data/maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_Rival1_1


# 951 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalMoveForReturnGoodsRight:
# 952 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 952 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 953 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 954 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 957 "data/maps/RustboroCity/scripts.pory"

# 958 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 959 "data/maps/RustboroCity/scripts.pory"
	lockall
# 960 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 961 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 962 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 963 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 964 "data/maps/RustboroCity/scripts.pory"

# 965 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 966 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 967 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 968 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 969 "data/maps/RustboroCity/scripts.pory"
	return
# 970 "data/maps/RustboroCity/scripts.pory"

# 971 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 972 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 973 "data/maps/RustboroCity/scripts.pory"
	return
# 974 "data/maps/RustboroCity/scripts.pory"

# 975 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 976 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 977 "data/maps/RustboroCity/scripts.pory"
	return
# 978 "data/maps/RustboroCity/scripts.pory"

# 979 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 980 "data/maps/RustboroCity/scripts.pory"
	lockall
# 981 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 982 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 983 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 984 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 985 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 986 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 987 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 988 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 989 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 990 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 991 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 992 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 993 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 994 "data/maps/RustboroCity/scripts.pory"

# 995 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 996 "data/maps/RustboroCity/scripts.pory"
	lockall
# 997 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 998 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 999 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1000 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1001 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1002 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1003 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1004 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1005 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 1006 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1007 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1008 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1009 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1010 "data/maps/RustboroCity/scripts.pory"

# 1011 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 1012 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1013 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1014 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1015 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1016 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1017 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1018 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1019 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1020 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1021 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 1022 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1023 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1024 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1025 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1026 "data/maps/RustboroCity/scripts.pory"

# 1027 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 1028 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1029 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1030 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1031 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1032 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1033 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1034 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1035 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1036 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1037 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 1038 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1039 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1040 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1041 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1042 "data/maps/RustboroCity/scripts.pory"

# 1043 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 1044 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1045 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1046 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1047 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1048 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1049 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1050 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1051 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1052 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1053 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 1054 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1055 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1056 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1057 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1058 "data/maps/RustboroCity/scripts.pory"

# 1059 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 1060 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1061 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1062 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1063 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1064 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1065 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1066 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1067 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1068 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1069 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 1070 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1071 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1072 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1073 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1074 "data/maps/RustboroCity/scripts.pory"

# 1075 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 1076 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1077 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1078 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1079 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1080 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1081 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1082 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1083 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1084 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1085 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 1086 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1087 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1088 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1089 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1090 "data/maps/RustboroCity/scripts.pory"

# 1091 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 1092 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1093 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1094 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1095 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1096 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1097 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1098 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1099 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1100 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1101 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 1102 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1103 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1104 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1105 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1106 "data/maps/RustboroCity/scripts.pory"

# 1107 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 1108 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 1109 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1110 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1111 "data/maps/RustboroCity/scripts.pory"
	end
# 1112 "data/maps/RustboroCity/scripts.pory"

# 1113 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1114 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1115 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1116 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1117 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1118 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1119 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1120 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1121 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1122 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1123 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1124 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1125 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
# 1126 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1127 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1128 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1129 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1130 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1131 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1132 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1133 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1134 "data/maps/RustboroCity/scripts.pory"
	end
# 1135 "data/maps/RustboroCity/scripts.pory"

# 1136 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1137 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1138 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1139 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1140 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1141 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1142 "data/maps/RustboroCity/scripts.pory"
	end
# 1143 "data/maps/RustboroCity/scripts.pory"

# 1144 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1145 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1146 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1147 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 1148 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 1149 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 1150 "data/maps/RustboroCity/scripts.pory"
	end
# 1151 "data/maps/RustboroCity/scripts.pory"

# 1152 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1153 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1154 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1155 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1156 "data/maps/RustboroCity/scripts.pory"
	end
# 1157 "data/maps/RustboroCity/scripts.pory"

# 1158 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1159 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1160 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1161 "data/maps/RustboroCity/scripts.pory"
	return
# 1162 "data/maps/RustboroCity/scripts.pory"

# 1163 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 1164 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 1165 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1166 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1167 "data/maps/RustboroCity/scripts.pory"
	end
# 1168 "data/maps/RustboroCity/scripts.pory"

# 1169 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 1170 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 1171 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1172 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1173 "data/maps/RustboroCity/scripts.pory"
	end
# 1174 "data/maps/RustboroCity/scripts.pory"

# 1175 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 1176 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 1177 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1178 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1179 "data/maps/RustboroCity/scripts.pory"
	end
# 1180 "data/maps/RustboroCity/scripts.pory"

# 1181 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1182 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1183 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1184 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1185 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1186 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1187 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1188 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1189 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1190 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1191 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1192 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1193 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
# 1194 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1195 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1196 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1197 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1198 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1199 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1200 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1201 "data/maps/RustboroCity/scripts.pory"
	end
# 1202 "data/maps/RustboroCity/scripts.pory"

# 1203 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1204 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1205 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1206 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1207 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1208 "data/maps/RustboroCity/scripts.pory"
	end
# 1209 "data/maps/RustboroCity/scripts.pory"

# 1210 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1211 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1212 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1213 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 1214 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 1215 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 1216 "data/maps/RustboroCity/scripts.pory"
	end
# 1217 "data/maps/RustboroCity/scripts.pory"

# 1218 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1219 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1220 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1221 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1222 "data/maps/RustboroCity/scripts.pory"
	end
# 1223 "data/maps/RustboroCity/scripts.pory"

# 1224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 1225 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 1226 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1227 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1228 "data/maps/RustboroCity/scripts.pory"
	end
# 1229 "data/maps/RustboroCity/scripts.pory"

# 1230 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 1231 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 1232 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1233 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1234 "data/maps/RustboroCity/scripts.pory"
	end
# 1235 "data/maps/RustboroCity/scripts.pory"

# 1236 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 1237 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 1238 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1239 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1240 "data/maps/RustboroCity/scripts.pory"
	end
# 1241 "data/maps/RustboroCity/scripts.pory"

# 1242 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1243 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1244 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1245 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1246 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1247 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1248 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1249 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1250 "data/maps/RustboroCity/scripts.pory"

# 1251 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1252 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1253 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1254 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1255 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1256 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1257 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1258 "data/maps/RustboroCity/scripts.pory"

# 1259 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1260 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1261 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1262 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1263 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1264 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1265 "data/maps/RustboroCity/scripts.pory"

# 1266 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1267 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1268 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1269 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1270 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1271 "data/maps/RustboroCity/scripts.pory"

# 1272 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1273 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1274 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1275 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1276 "data/maps/RustboroCity/scripts.pory"

# 1277 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1278 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1279 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1280 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1281 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1282 "data/maps/RustboroCity/scripts.pory"

# 1283 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1284 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1285 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1286 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1287 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1288 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1289 "data/maps/RustboroCity/scripts.pory"

# 1290 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1291 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1292 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1293 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1294 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1295 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1296 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1297 "data/maps/RustboroCity/scripts.pory"

# 1298 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1299 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1300 "data/maps/RustboroCity/scripts.pory"
	end
# 1301 "data/maps/RustboroCity/scripts.pory"

# 1302 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1303 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1304 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1305 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1306 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1307 "data/maps/RustboroCity/scripts.pory"

# 1308 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1309 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1310 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1311 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1312 "data/maps/RustboroCity/scripts.pory"

# 1313 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1314 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1315 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1316 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1317 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1318 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1319 "data/maps/RustboroCity/scripts.pory"

# 1320 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1321 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1322 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1323 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1324 "data/maps/RustboroCity/scripts.pory"

# 1325 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1326 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1327 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1328 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1329 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1330 "data/maps/RustboroCity/scripts.pory"

# 1331 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1332 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1333 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1334 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1335 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1336 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1337 "data/maps/RustboroCity/scripts.pory"

# 1338 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1339 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1340 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1341 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1342 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1343 "data/maps/RustboroCity/scripts.pory"

# 1344 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1345 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1346 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1347 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1348 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1349 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1350 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1351 "data/maps/RustboroCity/scripts.pory"

# 1352 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1353 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1354 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1355 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1356 "data/maps/RustboroCity/scripts.pory"

# 1357 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1358 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1359 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1360 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1361 "data/maps/RustboroCity/scripts.pory"

# 1362 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1363 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1364 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1365 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1366 "data/maps/RustboroCity/scripts.pory"

# 1367 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1368 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1369 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1370 "data/maps/RustboroCity/scripts.pory"

# 1371 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1372 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1373 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1374 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1375 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1376 "data/maps/RustboroCity/scripts.pory"

# 1377 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1378 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1379 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1380 "data/maps/RustboroCity/scripts.pory"

# 1381 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1382 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1383 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1384 "data/maps/RustboroCity/scripts.pory"

# 1385 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1386 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1387 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1388 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1389 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1390 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1391 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1392 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1393 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1394 "data/maps/RustboroCity/scripts.pory"

# 1395 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1396 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1397 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"

# 1421 "data/maps/RustboroCity/scripts.pory"

# 1422 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1423 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1424 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1425 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1426 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1427 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1428 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1429 "data/maps/RustboroCity/scripts.pory"

# 1430 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1431 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1432 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1433 "data/maps/RustboroCity/scripts.pory"

# 1434 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1435 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1436 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1437 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1438 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1439 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1440 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1441 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1442 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1443 "data/maps/RustboroCity/scripts.pory"

# 1444 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1445 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1446 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1447 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1448 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1449 "data/maps/RustboroCity/scripts.pory"

# 1450 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1451 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1452 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1453 "data/maps/RustboroCity/scripts.pory"

# 1454 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1455 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1456 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1457 "data/maps/RustboroCity/scripts.pory"

# 1458 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1459 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1460 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1461 "data/maps/RustboroCity/scripts.pory"

# 1462 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1463 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1464 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1465 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1466 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1467 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1468 "data/maps/RustboroCity/scripts.pory"

# 1469 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1470 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1471 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1472 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1473 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1474 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1475 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1476 "data/maps/RustboroCity/scripts.pory"

# 1477 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1478 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1479 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1480 "data/maps/RustboroCity/scripts.pory"

# 1481 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1482 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1483 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1484 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1485 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1486 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1487 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1488 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1489 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1490 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1491 "data/maps/RustboroCity/scripts.pory"

# 1492 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1493 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1494 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1495 "data/maps/RustboroCity/scripts.pory"

# 1496 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1497 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1498 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1499 "data/maps/RustboroCity/scripts.pory"

# 1500 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1501 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1502 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1503 "data/maps/RustboroCity/scripts.pory"

# 1504 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1505 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1506 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1507 "data/maps/RustboroCity/scripts.pory"

# 1508 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1509 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1510 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1511 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1512 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1513 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1514 "data/maps/RustboroCity/scripts.pory"

# 1515 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1516 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1517 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1518 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1519 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1520 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1521 "data/maps/RustboroCity/scripts.pory"

# 1522 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1523 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1524 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1525 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1526 "data/maps/RustboroCity/scripts.pory"

# 1527 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1528 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1529 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1530 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1531 "data/maps/RustboroCity/scripts.pory"

# 1532 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1533 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1534 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1535 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1536 "data/maps/RustboroCity/scripts.pory"

# 1537 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1538 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1539 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1540 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1541 "data/maps/RustboroCity/scripts.pory"

# 1542 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1543 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1544 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1545 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1546 "data/maps/RustboroCity/scripts.pory"

# 1547 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1548 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1549 "data/maps/RustboroCity/scripts.pory"

# 1550 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1551 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1552 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1553 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1554 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1555 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1556 "data/maps/RustboroCity/scripts.pory"

# 1557 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1558 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1559 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1560 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1561 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1562 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1563 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1564 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1565 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1566 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1567 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1568 "data/maps/RustboroCity/scripts.pory"

# 1569 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1570 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1571 "data/maps/RustboroCity/scripts.pory"

# 1572 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1573 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1574 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1575 "data/maps/RustboroCity/scripts.pory"

# 1576 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1577 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1578 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1579 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1580 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1581 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1582 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1583 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1584 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_Rival1_Text_0:
# 944 "data/maps/RustboroCity/scripts.pory"
	.string "Aren't you going to\nreturn the GOODS?$"

RustboroCity_Text_YoPlayer::
# 778 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 782 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 787 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 791 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 795 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 800 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"

RustboroCity_Text_YouGotItThankYou::
# 1400 "data/maps/RustboroCity/scripts.pory"
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
# 1411 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_PleaseComeWithMe::
# 1416 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
	.string "Both of you please come with me!$"
