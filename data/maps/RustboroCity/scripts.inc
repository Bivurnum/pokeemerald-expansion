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
	call_if_eq VAR_RUSTBORO_CITY_STATE, 4, RustboroCity_EventScript_SetForReturnGoods
# 39 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 40 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 41 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
# 42 "data/maps/RustboroCity/scripts.pory"
	end
# 43 "data/maps/RustboroCity/scripts.pory"

# 44 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 45 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 46 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 12, 15
# 47 "data/maps/RustboroCity/scripts.pory"
	end
# 48 "data/maps/RustboroCity/scripts.pory"

# 49 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 50 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 11, 15
# 51 "data/maps/RustboroCity/scripts.pory"
	end
# 52 "data/maps/RustboroCity/scripts.pory"

# 53 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 54 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 55 "data/maps/RustboroCity/scripts.pory"
	return

RustboroCity_EventScript_SetForReturnGoods::
# 59 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm 17, 29, 10
# 60 "data/maps/RustboroCity/scripts.pory"
	turnobject 9, DIR_WEST
	return


# 63 "data/maps/RustboroCity/scripts.pory"

# 64 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 65 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 66 "data/maps/RustboroCity/scripts.pory"
	.2byte 0
# 67 "data/maps/RustboroCity/scripts.pory"

# 68 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 69 "data/maps/RustboroCity/scripts.pory"
	lockall
# 70 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 71 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 72 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 73 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 74 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 75 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_SCIENTIST
# 76 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 77 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 78 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 79 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
# 80 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 81 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
# 82 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 83 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 84 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 85 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 86 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 87 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 88 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 89 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 90 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 91 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 93 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 94 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 95 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 96 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 97 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 98 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 99 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 100 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 101 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 102 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 103 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 104 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 105 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 106 "data/maps/RustboroCity/scripts.pory"

# 107 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 108 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 109 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 110 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 111 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 112 "data/maps/RustboroCity/scripts.pory"

# 113 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 114 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 115 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 116 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 117 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 118 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 119 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 120 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 121 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 122 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 123 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 124 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 125 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 126 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 127 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 128 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 129 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 130 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 131 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 132 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 133 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 134 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_SCIENTIST
# 135 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 136 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 137 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 138 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 139 "data/maps/RustboroCity/scripts.pory"
	end
# 140 "data/maps/RustboroCity/scripts.pory"

# 141 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 142 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 143 "data/maps/RustboroCity/scripts.pory"
	step_end
# 144 "data/maps/RustboroCity/scripts.pory"

# 145 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 146 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 147 "data/maps/RustboroCity/scripts.pory"
	step_end
# 148 "data/maps/RustboroCity/scripts.pory"

# 149 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 150 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 151 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 152 "data/maps/RustboroCity/scripts.pory"
	step_end
# 153 "data/maps/RustboroCity/scripts.pory"

# 154 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 155 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 156 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 157 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 158 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 159 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 160 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 161 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 162 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 163 "data/maps/RustboroCity/scripts.pory"
	step_end
# 164 "data/maps/RustboroCity/scripts.pory"

# 165 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 166 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 167 "data/maps/RustboroCity/scripts.pory"
	step_end
# 168 "data/maps/RustboroCity/scripts.pory"

# 169 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 170 "data/maps/RustboroCity/scripts.pory"
	lock
# 171 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 172 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 173 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 174 "data/maps/RustboroCity/scripts.pory"
	release
# 175 "data/maps/RustboroCity/scripts.pory"
	end
# 176 "data/maps/RustboroCity/scripts.pory"

# 177 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 178 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 179 "data/maps/RustboroCity/scripts.pory"
	release
# 180 "data/maps/RustboroCity/scripts.pory"
	end
# 181 "data/maps/RustboroCity/scripts.pory"

# 182 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 183 "data/maps/RustboroCity/scripts.pory"
	lock
# 184 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 185 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 186 "data/maps/RustboroCity/scripts.pory"
	release
# 187 "data/maps/RustboroCity/scripts.pory"
	end
# 188 "data/maps/RustboroCity/scripts.pory"

# 189 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 190 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 191 "data/maps/RustboroCity/scripts.pory"
	end
# 192 "data/maps/RustboroCity/scripts.pory"

# 193 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 194 "data/maps/RustboroCity/scripts.pory"
	lock
# 195 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 196 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 197 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 198 "data/maps/RustboroCity/scripts.pory"
	release
# 199 "data/maps/RustboroCity/scripts.pory"
	end
# 200 "data/maps/RustboroCity/scripts.pory"

# 201 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 202 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 203 "data/maps/RustboroCity/scripts.pory"
	release
# 204 "data/maps/RustboroCity/scripts.pory"
	end
# 205 "data/maps/RustboroCity/scripts.pory"

# 206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 207 "data/maps/RustboroCity/scripts.pory"
	lock
# 208 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 209 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 210 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 211 "data/maps/RustboroCity/scripts.pory"
	release
# 212 "data/maps/RustboroCity/scripts.pory"
	end
# 213 "data/maps/RustboroCity/scripts.pory"

# 214 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 215 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 216 "data/maps/RustboroCity/scripts.pory"
	release
# 217 "data/maps/RustboroCity/scripts.pory"
	end
# 218 "data/maps/RustboroCity/scripts.pory"

# 219 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 220 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 221 "data/maps/RustboroCity/scripts.pory"
	end
# 222 "data/maps/RustboroCity/scripts.pory"

# 223 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 224 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 225 "data/maps/RustboroCity/scripts.pory"
	end
# 226 "data/maps/RustboroCity/scripts.pory"

# 227 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 228 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 229 "data/maps/RustboroCity/scripts.pory"
	end
# 230 "data/maps/RustboroCity/scripts.pory"

# 231 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 232 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 233 "data/maps/RustboroCity/scripts.pory"
	end
# 234 "data/maps/RustboroCity/scripts.pory"

# 235 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 236 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 237 "data/maps/RustboroCity/scripts.pory"
	end
# 238 "data/maps/RustboroCity/scripts.pory"

# 239 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 240 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 241 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 242 "data/maps/RustboroCity/scripts.pory"
	end
# 243 "data/maps/RustboroCity/scripts.pory"

# 244 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 245 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 246 "data/maps/RustboroCity/scripts.pory"
	end
# 247 "data/maps/RustboroCity/scripts.pory"

# 248 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 249 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 250 "data/maps/RustboroCity/scripts.pory"
	end
# 251 "data/maps/RustboroCity/scripts.pory"

# 252 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 253 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 254 "data/maps/RustboroCity/scripts.pory"
	end
# 255 "data/maps/RustboroCity/scripts.pory"

# 256 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 257 "data/maps/RustboroCity/scripts.pory"
	lock
# 258 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 259 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 260 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 261 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 262 "data/maps/RustboroCity/scripts.pory"
	release
# 263 "data/maps/RustboroCity/scripts.pory"
	end
# 264 "data/maps/RustboroCity/scripts.pory"

# 265 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 266 "data/maps/RustboroCity/scripts.pory"
	lock
# 267 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 268 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 269 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 270 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 271 "data/maps/RustboroCity/scripts.pory"
	release
# 272 "data/maps/RustboroCity/scripts.pory"
	end
# 273 "data/maps/RustboroCity/scripts.pory"

# 274 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 275 "data/maps/RustboroCity/scripts.pory"
	lock
# 276 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 277 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 278 "data/maps/RustboroCity/scripts.pory"
	release
# 279 "data/maps/RustboroCity/scripts.pory"
	end
# 280 "data/maps/RustboroCity/scripts.pory"

# 281 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 282 "data/maps/RustboroCity/scripts.pory"
	lockall
# 283 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 284 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 285 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 286 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 287 "data/maps/RustboroCity/scripts.pory"
	end
# 288 "data/maps/RustboroCity/scripts.pory"

# 289 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 290 "data/maps/RustboroCity/scripts.pory"
	lockall
# 291 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 292 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 293 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 294 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 295 "data/maps/RustboroCity/scripts.pory"
	end
# 296 "data/maps/RustboroCity/scripts.pory"

# 297 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 298 "data/maps/RustboroCity/scripts.pory"
	lockall
# 299 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 300 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 301 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 302 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 303 "data/maps/RustboroCity/scripts.pory"
	end
# 304 "data/maps/RustboroCity/scripts.pory"

# 305 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 306 "data/maps/RustboroCity/scripts.pory"
	lockall
# 307 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 308 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 309 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 310 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 311 "data/maps/RustboroCity/scripts.pory"
	end
# 312 "data/maps/RustboroCity/scripts.pory"

# 313 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 314 "data/maps/RustboroCity/scripts.pory"
	lockall
# 315 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 316 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 317 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 318 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 319 "data/maps/RustboroCity/scripts.pory"
	end
# 320 "data/maps/RustboroCity/scripts.pory"

# 321 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 322 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 323 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 324 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 325 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 326 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 327 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 328 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 329 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 330 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 331 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 332 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 333 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 334 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 335 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 336 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 337 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 338 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 339 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 340 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 341 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 342 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 343 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 344 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 345 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 346 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 347 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 348 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 349 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 350 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 351 "data/maps/RustboroCity/scripts.pory"
	end
# 352 "data/maps/RustboroCity/scripts.pory"

# 353 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 354 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 355 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 356 "data/maps/RustboroCity/scripts.pory"
	return
# 357 "data/maps/RustboroCity/scripts.pory"

# 358 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 360 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 361 "data/maps/RustboroCity/scripts.pory"
	return
# 362 "data/maps/RustboroCity/scripts.pory"

# 363 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 364 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 365 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 366 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 367 "data/maps/RustboroCity/scripts.pory"
	return
# 368 "data/maps/RustboroCity/scripts.pory"

# 369 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 370 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 371 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 372 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 373 "data/maps/RustboroCity/scripts.pory"
	return
# 374 "data/maps/RustboroCity/scripts.pory"

# 375 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 376 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 377 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 378 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 379 "data/maps/RustboroCity/scripts.pory"
	return
# 380 "data/maps/RustboroCity/scripts.pory"

# 381 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 382 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 383 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 384 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 385 "data/maps/RustboroCity/scripts.pory"
	return
# 386 "data/maps/RustboroCity/scripts.pory"

# 387 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 388 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 389 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 390 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 391 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 392 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 393 "data/maps/RustboroCity/scripts.pory"
	return
# 394 "data/maps/RustboroCity/scripts.pory"

# 395 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 396 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 397 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 398 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 399 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 400 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 401 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 402 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 404 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 405 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 406 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 407 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
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
	step_end
# 415 "data/maps/RustboroCity/scripts.pory"

# 416 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 417 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 418 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 419 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 420 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 421 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 422 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 423 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 424 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 425 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 426 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 427 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 428 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 429 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 430 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 431 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 432 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 433 "data/maps/RustboroCity/scripts.pory"
	step_end
# 434 "data/maps/RustboroCity/scripts.pory"

# 435 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 436 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 437 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 438 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 439 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 440 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 441 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 442 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 443 "data/maps/RustboroCity/scripts.pory"
	step_end
# 444 "data/maps/RustboroCity/scripts.pory"

# 445 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 446 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 447 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 448 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 449 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 450 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 451 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 452 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 453 "data/maps/RustboroCity/scripts.pory"
	step_end
# 454 "data/maps/RustboroCity/scripts.pory"

# 455 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 456 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 457 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 458 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 459 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 460 "data/maps/RustboroCity/scripts.pory"
	step_end
# 461 "data/maps/RustboroCity/scripts.pory"

# 462 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 463 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 464 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 465 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 466 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 467 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 468 "data/maps/RustboroCity/scripts.pory"
	step_end
# 469 "data/maps/RustboroCity/scripts.pory"

# 470 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 471 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 472 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 473 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 474 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 475 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 476 "data/maps/RustboroCity/scripts.pory"
	step_end
# 477 "data/maps/RustboroCity/scripts.pory"

# 478 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 479 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 480 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 481 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 482 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 483 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 484 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 485 "data/maps/RustboroCity/scripts.pory"
	step_end
# 486 "data/maps/RustboroCity/scripts.pory"

# 487 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 488 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 489 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 490 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 491 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 492 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 493 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 494 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 495 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 496 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 500 "data/maps/RustboroCity/scripts.pory"
	lock
# 501 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 502 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 503 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 504 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 509 "data/maps/RustboroCity/scripts.pory"
	waitse
# 510 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 511 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 516 "data/maps/RustboroCity/scripts.pory"
	lockall
# 517 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 518 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 523 "data/maps/RustboroCity/scripts.pory"
	lockall
# 524 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 525 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 530 "data/maps/RustboroCity/scripts.pory"
	lockall
# 531 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 532 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 537 "data/maps/RustboroCity/scripts.pory"
	lockall
# 538 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 539 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 544 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 545 "data/maps/RustboroCity/scripts.pory"
	addobject 17
# 546 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 547 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 548 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 549 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 550 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 551 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 552 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm 9
# 553 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 554 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 555 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 560 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 561 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 562 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 563 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_NoticeRival1
# 564 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 565 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 566 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 567 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachPlayer
# 568 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 569 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 570 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 571 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 572 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 573 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 574 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 575 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 576 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 580 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 584 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 585 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 590 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 591 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 592 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 593 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 597 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 599 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 600 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 601 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 602 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 603 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 606 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 609 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 610 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 614 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 615 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 616 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 617 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceRight
# 618 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 619 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 620 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 622 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 624 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 626 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_20
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 629 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 630 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 631 "data/maps/RustboroCity/scripts.pory"
	removeobject 17
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 577 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 578 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 579 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 581 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 582 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceDown
# 583 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 586 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 587 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_FaceLeft
# 588 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 594 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 604 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 605 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 607 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 608 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 611 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 612 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 621 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 623 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 625 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger2
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_20:
# 627 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_Rival1ChaseMugger3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 637 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 638 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 639 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 640 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 641 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 642 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 643 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 644 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 645 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 646 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 651 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 652 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 653 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 654 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 655 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 656 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 657 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 658 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 659 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 664 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 665 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 666 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 667 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 668 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 669 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 670 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 671 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 672 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 673 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 678 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 679 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 680 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 681 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 682 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 683 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 684 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 685 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 686 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 687 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 688 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 689 "data/maps/RustboroCity/scripts.pory"
	setobjectxy 17, 22, 12
	return


# 693 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 694 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 695 "data/maps/RustboroCity/scripts.pory"
	step_end

# 698 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_NoticeRival1:
# 699 "data/maps/RustboroCity/scripts.pory"
	emote_exclamation_mark
# 700 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_left
	step_end

# 703 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 707 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 708 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 708 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 708 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 709 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 712 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 713 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 714 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 714 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 717 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 718 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 719 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 719 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 720 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 720 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 723 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 724 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 725 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 725 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 728 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 729 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 729 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 732 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 733 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 733 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 736 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 737 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 737 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 740 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 741 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 741 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 744 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 745 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 749 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 750 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 750 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 755 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 756 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 757 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 760 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2:
# 761 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
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
# 762 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 763 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 766 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger3:
# 767 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 767 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
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

RustboroCity_EventScript_ReturnGoodsTrigger0::
# 800 "data/maps/RustboroCity/scripts.pory"
	lockall
# 801 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 802 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerUp2
# 803 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger1::
# 808 "data/maps/RustboroCity/scripts.pory"
	lockall
# 809 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 810 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 811 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger2::
# 816 "data/maps/RustboroCity/scripts.pory"
	lockall
# 817 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 818 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeFacePlayerDown2
# 819 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoodsTrigger3::
# 824 "data/maps/RustboroCity/scripts.pory"
	lockall
# 825 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 826 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 827 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_ReturnGoods::
# 832 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 833 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 834 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 835 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 836 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 837 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 838 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 839 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 840 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 841 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 842 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 843 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 844 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_BagFull::
# 849 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return


RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 854 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterUp
# 855 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterUp
# 856 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 857 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 858 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 859 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 860 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 861 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 862 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 863 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 864 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 869 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
# 870 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterRight
# 871 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 872 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 873 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 874 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 875 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 876 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 877 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_RivalMoveForReturnGoodsRight
# 878 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 879 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 880 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 885 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 886 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 887 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 888 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 889 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 890 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 891 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 892 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 893 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 894 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 895 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 900 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterDown
# 901 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_WalkInPlaceFasterDown
# 902 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 903 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 904 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 905 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, Common_Movement_ExclamationMark
# 906 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 907 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 908 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 909 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, RustboroCity_Movement_EmployeeApproachPlayerDown
# 910 "data/maps/RustboroCity/scripts.pory"
	applymovement 17, RustboroCity_Movement_EmployeeApproachPlayerDown
# 911 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 912 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 913 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerRight::
# 918 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_WalkInPlaceFasterLeft
# 919 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 920 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 921 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_ExclamationMark
# 922 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 923 "data/maps/RustboroCity/scripts.pory"
	applymovement 9, Common_Movement_Delay48
# 924 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_Rival1::
# 929 "data/maps/RustboroCity/scripts.pory"
	lock
# 930 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 931 "data/maps/RustboroCity/scripts.pory"
	compare VAR_RUSTBORO_CITY_STATE, 4
	goto_if_eq RustboroCity_EventScript_Rival1_2
RustboroCity_EventScript_Rival1_1:
# 935 "data/maps/RustboroCity/scripts.pory"
	release
	end

RustboroCity_EventScript_Rival1_2:
# 932 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_EventScript_Rival1_Text_0, MSGBOX_DEFAULT
# 933 "data/maps/RustboroCity/scripts.pory"
	closemessage
	goto RustboroCity_EventScript_Rival1_1


# 939 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalMoveForReturnGoodsRight:
# 940 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 940 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 941 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 942 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 945 "data/maps/RustboroCity/scripts.pory"

# 946 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 947 "data/maps/RustboroCity/scripts.pory"
	lockall
# 948 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 949 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 950 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 951 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 952 "data/maps/RustboroCity/scripts.pory"

# 953 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 954 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 955 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 956 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 957 "data/maps/RustboroCity/scripts.pory"
	return
# 958 "data/maps/RustboroCity/scripts.pory"

# 959 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 960 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 961 "data/maps/RustboroCity/scripts.pory"
	return
# 962 "data/maps/RustboroCity/scripts.pory"

# 963 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 964 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 965 "data/maps/RustboroCity/scripts.pory"
	return
# 966 "data/maps/RustboroCity/scripts.pory"

# 967 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 968 "data/maps/RustboroCity/scripts.pory"
	lockall
# 969 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 970 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 971 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 972 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 973 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 974 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 975 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 976 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 977 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 978 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 979 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 980 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 981 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 982 "data/maps/RustboroCity/scripts.pory"

# 983 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 984 "data/maps/RustboroCity/scripts.pory"
	lockall
# 985 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 986 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 987 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 988 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 989 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 990 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 991 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 992 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 993 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 994 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 995 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 996 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 997 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 998 "data/maps/RustboroCity/scripts.pory"

# 999 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 1000 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1001 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1002 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1003 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1004 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1005 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1006 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1007 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1008 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1009 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 1010 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1011 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1012 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1013 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1014 "data/maps/RustboroCity/scripts.pory"

# 1015 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 1016 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1017 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1018 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1019 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1020 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1021 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1022 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1023 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1024 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1025 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 1026 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1027 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1028 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1029 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1030 "data/maps/RustboroCity/scripts.pory"

# 1031 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 1032 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1033 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1034 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1035 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1036 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1037 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1038 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1039 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1040 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1041 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 1042 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1043 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1044 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1045 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1046 "data/maps/RustboroCity/scripts.pory"

# 1047 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 1048 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1049 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1050 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1051 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1052 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1053 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1054 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1055 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1056 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1057 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 1058 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1059 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1060 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1061 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1062 "data/maps/RustboroCity/scripts.pory"

# 1063 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 1064 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1065 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1066 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1067 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1068 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1069 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1070 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1071 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1072 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1073 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 1074 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1075 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1076 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1077 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1078 "data/maps/RustboroCity/scripts.pory"

# 1079 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 1080 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1081 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1082 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1083 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1084 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1085 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1086 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1087 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1088 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1089 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 1090 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1091 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1092 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1093 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1094 "data/maps/RustboroCity/scripts.pory"

# 1095 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 1096 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 1097 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1098 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1099 "data/maps/RustboroCity/scripts.pory"
	end
# 1100 "data/maps/RustboroCity/scripts.pory"

# 1101 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1102 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1103 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1104 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1105 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1106 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1107 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1108 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1109 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1110 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1111 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1112 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1113 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
# 1114 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1115 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1116 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1117 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1118 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1119 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1120 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1121 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1122 "data/maps/RustboroCity/scripts.pory"
	end
# 1123 "data/maps/RustboroCity/scripts.pory"

# 1124 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1125 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1126 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1127 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1128 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1129 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1130 "data/maps/RustboroCity/scripts.pory"
	end
# 1131 "data/maps/RustboroCity/scripts.pory"

# 1132 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1133 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1134 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1135 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 1136 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 1137 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 1138 "data/maps/RustboroCity/scripts.pory"
	end
# 1139 "data/maps/RustboroCity/scripts.pory"

# 1140 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1141 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1142 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1143 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1144 "data/maps/RustboroCity/scripts.pory"
	end
# 1145 "data/maps/RustboroCity/scripts.pory"

# 1146 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1147 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1148 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1149 "data/maps/RustboroCity/scripts.pory"
	return
# 1150 "data/maps/RustboroCity/scripts.pory"

# 1151 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 1152 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 1153 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1154 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1155 "data/maps/RustboroCity/scripts.pory"
	end
# 1156 "data/maps/RustboroCity/scripts.pory"

# 1157 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 1158 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 1159 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1160 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1161 "data/maps/RustboroCity/scripts.pory"
	end
# 1162 "data/maps/RustboroCity/scripts.pory"

# 1163 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 1164 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 1165 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1166 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1167 "data/maps/RustboroCity/scripts.pory"
	end
# 1168 "data/maps/RustboroCity/scripts.pory"

# 1169 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1170 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1171 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1172 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1173 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1174 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1175 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1176 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1177 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1178 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1179 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1180 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1181 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_SPENCER_MATCH_CALL
# 1182 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1183 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1184 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1185 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1186 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1187 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1188 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1189 "data/maps/RustboroCity/scripts.pory"
	end
# 1190 "data/maps/RustboroCity/scripts.pory"

# 1191 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1192 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1193 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1194 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1195 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1196 "data/maps/RustboroCity/scripts.pory"
	end
# 1197 "data/maps/RustboroCity/scripts.pory"

# 1198 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1199 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1200 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1201 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 1202 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 1203 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 1204 "data/maps/RustboroCity/scripts.pory"
	end
# 1205 "data/maps/RustboroCity/scripts.pory"

# 1206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1207 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1208 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1209 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1210 "data/maps/RustboroCity/scripts.pory"
	end
# 1211 "data/maps/RustboroCity/scripts.pory"

# 1212 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 1213 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 1214 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1215 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1216 "data/maps/RustboroCity/scripts.pory"
	end
# 1217 "data/maps/RustboroCity/scripts.pory"

# 1218 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 1219 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 1220 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1221 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1222 "data/maps/RustboroCity/scripts.pory"
	end
# 1223 "data/maps/RustboroCity/scripts.pory"

# 1224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 1225 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 1226 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1227 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1228 "data/maps/RustboroCity/scripts.pory"
	end
# 1229 "data/maps/RustboroCity/scripts.pory"

# 1230 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1231 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1232 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1233 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1234 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1235 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1236 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1237 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1238 "data/maps/RustboroCity/scripts.pory"

# 1239 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1240 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1241 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1242 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1243 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1244 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1245 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1246 "data/maps/RustboroCity/scripts.pory"

# 1247 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1248 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1249 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1250 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1251 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1252 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1253 "data/maps/RustboroCity/scripts.pory"

# 1254 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1255 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1256 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1257 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1258 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1259 "data/maps/RustboroCity/scripts.pory"

# 1260 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1261 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1262 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1263 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1264 "data/maps/RustboroCity/scripts.pory"

# 1265 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1266 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1267 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1268 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1269 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1270 "data/maps/RustboroCity/scripts.pory"

# 1271 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1272 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1273 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1274 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1275 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1276 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1277 "data/maps/RustboroCity/scripts.pory"

# 1278 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1279 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1280 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1281 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1282 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1283 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1284 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1285 "data/maps/RustboroCity/scripts.pory"

# 1286 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1287 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1288 "data/maps/RustboroCity/scripts.pory"
	end
# 1289 "data/maps/RustboroCity/scripts.pory"

# 1290 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1291 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1292 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1293 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1294 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1295 "data/maps/RustboroCity/scripts.pory"

# 1296 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1297 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1298 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1299 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1300 "data/maps/RustboroCity/scripts.pory"

# 1301 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1302 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1303 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1304 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1305 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1306 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1307 "data/maps/RustboroCity/scripts.pory"

# 1308 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1309 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1310 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1311 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1312 "data/maps/RustboroCity/scripts.pory"

# 1313 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1314 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1315 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1316 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1317 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1318 "data/maps/RustboroCity/scripts.pory"

# 1319 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1320 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1321 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1322 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1323 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1324 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1325 "data/maps/RustboroCity/scripts.pory"

# 1326 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1327 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1328 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1329 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1330 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1331 "data/maps/RustboroCity/scripts.pory"

# 1332 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1333 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1334 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1335 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1336 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1337 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1338 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1339 "data/maps/RustboroCity/scripts.pory"

# 1340 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1341 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1342 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1343 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1344 "data/maps/RustboroCity/scripts.pory"

# 1345 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1346 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1347 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1348 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1349 "data/maps/RustboroCity/scripts.pory"

# 1350 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1351 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1352 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1353 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1354 "data/maps/RustboroCity/scripts.pory"

# 1355 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1356 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1357 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1358 "data/maps/RustboroCity/scripts.pory"

# 1359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1360 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1361 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1362 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1363 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1364 "data/maps/RustboroCity/scripts.pory"

# 1365 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1366 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1367 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1368 "data/maps/RustboroCity/scripts.pory"

# 1369 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1370 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1371 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1372 "data/maps/RustboroCity/scripts.pory"

# 1373 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1374 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1375 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1376 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1377 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1378 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1379 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1380 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1381 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1382 "data/maps/RustboroCity/scripts.pory"

# 1383 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1384 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1385 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"

# 1409 "data/maps/RustboroCity/scripts.pory"

# 1410 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1411 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1412 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1413 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1414 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1415 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1416 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1417 "data/maps/RustboroCity/scripts.pory"

# 1418 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1419 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1420 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1421 "data/maps/RustboroCity/scripts.pory"

# 1422 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1423 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1424 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1425 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1426 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1427 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1428 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1429 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1430 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1431 "data/maps/RustboroCity/scripts.pory"

# 1432 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1433 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1434 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1435 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1436 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1437 "data/maps/RustboroCity/scripts.pory"

# 1438 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1439 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1440 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1441 "data/maps/RustboroCity/scripts.pory"

# 1442 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1443 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1444 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1445 "data/maps/RustboroCity/scripts.pory"

# 1446 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1447 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1448 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1449 "data/maps/RustboroCity/scripts.pory"

# 1450 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1451 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1452 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1453 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1454 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1455 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1456 "data/maps/RustboroCity/scripts.pory"

# 1457 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1458 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1459 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1460 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1461 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1462 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1463 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1464 "data/maps/RustboroCity/scripts.pory"

# 1465 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1466 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1467 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1468 "data/maps/RustboroCity/scripts.pory"

# 1469 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1470 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1471 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1472 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1473 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1474 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1475 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1476 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1477 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1478 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1479 "data/maps/RustboroCity/scripts.pory"

# 1480 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1481 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1482 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1483 "data/maps/RustboroCity/scripts.pory"

# 1484 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1485 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1486 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1487 "data/maps/RustboroCity/scripts.pory"

# 1488 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1489 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1490 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1491 "data/maps/RustboroCity/scripts.pory"

# 1492 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1493 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1494 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1495 "data/maps/RustboroCity/scripts.pory"

# 1496 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1497 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1498 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1499 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1500 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1501 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1502 "data/maps/RustboroCity/scripts.pory"

# 1503 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1504 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1505 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1506 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1507 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1508 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1509 "data/maps/RustboroCity/scripts.pory"

# 1510 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1511 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1512 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1513 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1514 "data/maps/RustboroCity/scripts.pory"

# 1515 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1516 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1517 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1518 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1519 "data/maps/RustboroCity/scripts.pory"

# 1520 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1521 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1522 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1523 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1524 "data/maps/RustboroCity/scripts.pory"

# 1525 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1526 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1527 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1528 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1529 "data/maps/RustboroCity/scripts.pory"

# 1530 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1531 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1532 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1533 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1534 "data/maps/RustboroCity/scripts.pory"

# 1535 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1536 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1537 "data/maps/RustboroCity/scripts.pory"

# 1538 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1539 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1540 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1541 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1542 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1543 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1544 "data/maps/RustboroCity/scripts.pory"

# 1545 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1546 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1547 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1548 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1549 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1550 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1551 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1552 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1553 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1554 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1555 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1556 "data/maps/RustboroCity/scripts.pory"

# 1557 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1558 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1559 "data/maps/RustboroCity/scripts.pory"

# 1560 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1561 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1562 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1563 "data/maps/RustboroCity/scripts.pory"

# 1564 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1565 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1566 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1567 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1568 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1569 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1570 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1571 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1572 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_EventScript_Rival1_Text_0:
# 932 "data/maps/RustboroCity/scripts.pory"
	.string "Aren't you going to\nreturn the GOODS?$"

RustboroCity_Text_YoPlayer::
# 772 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 776 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 781 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 785 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 789 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 794 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"

RustboroCity_Text_YouGotItThankYou::
# 1388 "data/maps/RustboroCity/scripts.pory"
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
# 1399 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_PleaseComeWithMe::
# 1404 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
	.string "Both of you please come with me!$"
