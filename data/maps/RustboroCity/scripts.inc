# 1 "data/maps/RustboroCity/scripts.pory"

# 2 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_LITTLE_BOY, 7
# 3 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_LITTLE_GIRL, 8
# 4 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_DEVON_EMPLOYEE, 9
# 5 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_GRUNT, 10
# 6 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_RIVAL2, 14
# 7 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_SCIENTIST, 15
# 8 "data/maps/RustboroCity/scripts.pory"
.set LOCALID_RIVAL1, 17

# 21 "data/maps/RustboroCity/scripts.pory"

# 22 "data/maps/RustboroCity/scripts.pory"
RustboroCity_MapScripts::
# 23 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
# 24 "data/maps/RustboroCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
# 25 "data/maps/RustboroCity/scripts.pory"
	.byte 0
# 26 "data/maps/RustboroCity/scripts.pory"

# 27 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnTransition:
# 28 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_VISITED_RUSTBORO_CITY
# 29 "data/maps/RustboroCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 30 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
# 31 "data/maps/RustboroCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 32 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
# 33 "data/maps/RustboroCity/scripts.pory"
	end
# 34 "data/maps/RustboroCity/scripts.pory"

# 35 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistForExit::
# 36 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
# 37 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 12, 15
# 38 "data/maps/RustboroCity/scripts.pory"
	end
# 39 "data/maps/RustboroCity/scripts.pory"

# 40 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PositionScientistLeftExit::
# 41 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_SCIENTIST, 11, 15
# 42 "data/maps/RustboroCity/scripts.pory"
	end
# 43 "data/maps/RustboroCity/scripts.pory"

# 44 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_HideMapNamePopup::
# 45 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 46 "data/maps/RustboroCity/scripts.pory"
	return
# 47 "data/maps/RustboroCity/scripts.pory"

# 48 "data/maps/RustboroCity/scripts.pory"
RustboroCity_OnFrame:
# 49 "data/maps/RustboroCity/scripts.pory"
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
# 50 "data/maps/RustboroCity/scripts.pory"
	.2byte 0
# 51 "data/maps/RustboroCity/scripts.pory"

# 52 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ScientistAddMatchCall::
# 53 "data/maps/RustboroCity/scripts.pory"
	lockall
# 54 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 1
# 55 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
# 56 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 57 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 58 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 59 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_SCIENTIST
# 60 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
# 61 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 62 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 63 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
# 64 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 65 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
# 66 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 67 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 68 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 69 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
# 70 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 71 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
# 72 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 73 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HAS_MATCH_CALL
# 74 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterLeft
# 75 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 76 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 77 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 78 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 79 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 80 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 81 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 82 "data/maps/RustboroCity/scripts.pory"
	playse SE_CLICK
# 83 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 84 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFasterDown
# 85 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 86 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
# 87 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 88 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 89 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 90 "data/maps/RustboroCity/scripts.pory"

# 91 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PleaseSelectPokenav::
# 92 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
# 93 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 94 "data/maps/RustboroCity/scripts.pory"
	delay 10
# 95 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MatchCallTutorial
# 96 "data/maps/RustboroCity/scripts.pory"

# 97 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MatchCallTutorial::
# 98 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
# 99 "data/maps/RustboroCity/scripts.pory"
	special ScriptMenu_CreateStartMenuForPokenavTutorial
# 100 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 101 "data/maps/RustboroCity/scripts.pory"
	switch VAR_RESULT
# 102 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
# 103 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
# 104 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
# 105 "data/maps/RustboroCity/scripts.pory"
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
# 106 "data/maps/RustboroCity/scripts.pory"
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
# 107 "data/maps/RustboroCity/scripts.pory"
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
# 108 "data/maps/RustboroCity/scripts.pory"
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
# 109 "data/maps/RustboroCity/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
# 110 "data/maps/RustboroCity/scripts.pory"
	special OpenPokenavForTutorial
# 111 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 112 "data/maps/RustboroCity/scripts.pory"
	delay 20
# 113 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
# 114 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 115 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
# 116 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 117 "data/maps/RustboroCity/scripts.pory"
	playse SE_EXIT
# 118 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_SCIENTIST
# 119 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
# 120 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 7
# 121 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 122 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 123 "data/maps/RustboroCity/scripts.pory"
	end
# 124 "data/maps/RustboroCity/scripts.pory"

# 125 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkInPlaceDown:
# 126 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 127 "data/maps/RustboroCity/scripts.pory"
	step_end
# 128 "data/maps/RustboroCity/scripts.pory"

# 129 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerWalkDown:
# 130 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 131 "data/maps/RustboroCity/scripts.pory"
	step_end
# 132 "data/maps/RustboroCity/scripts.pory"

# 133 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistApproachPlayer:
# 134 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 135 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 136 "data/maps/RustboroCity/scripts.pory"
	step_end
# 137 "data/maps/RustboroCity/scripts.pory"

# 138 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 139 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistWalkAroundPlayer:
# 140 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 141 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 142 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 143 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 144 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 145 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 146 "data/maps/RustboroCity/scripts.pory"
	delay_16
# 147 "data/maps/RustboroCity/scripts.pory"
	step_end
# 148 "data/maps/RustboroCity/scripts.pory"

# 149 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_ScientistLeave:
# 150 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 151 "data/maps/RustboroCity/scripts.pory"
	step_end
# 152 "data/maps/RustboroCity/scripts.pory"

# 153 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatMan::
# 154 "data/maps/RustboroCity/scripts.pory"
	lock
# 155 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 156 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
# 157 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
# 158 "data/maps/RustboroCity/scripts.pory"
	release
# 159 "data/maps/RustboroCity/scripts.pory"
	end
# 160 "data/maps/RustboroCity/scripts.pory"

# 161 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_FatManSawGrunt::
# 162 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
# 163 "data/maps/RustboroCity/scripts.pory"
	release
# 164 "data/maps/RustboroCity/scripts.pory"
	end
# 165 "data/maps/RustboroCity/scripts.pory"

# 166 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonEmployee2::
# 167 "data/maps/RustboroCity/scripts.pory"
	lock
# 168 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 169 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
# 170 "data/maps/RustboroCity/scripts.pory"
	release
# 171 "data/maps/RustboroCity/scripts.pory"
	end
# 172 "data/maps/RustboroCity/scripts.pory"

# 173 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Woman::
# 174 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
# 175 "data/maps/RustboroCity/scripts.pory"
	end
# 176 "data/maps/RustboroCity/scripts.pory"

# 177 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1::
# 178 "data/maps/RustboroCity/scripts.pory"
	lock
# 179 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 180 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
# 181 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
# 182 "data/maps/RustboroCity/scripts.pory"
	release
# 183 "data/maps/RustboroCity/scripts.pory"
	end
# 184 "data/maps/RustboroCity/scripts.pory"

# 185 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man1HaveBadge::
# 186 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
# 187 "data/maps/RustboroCity/scripts.pory"
	release
# 188 "data/maps/RustboroCity/scripts.pory"
	end
# 189 "data/maps/RustboroCity/scripts.pory"

# 190 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2::
# 191 "data/maps/RustboroCity/scripts.pory"
	lock
# 192 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 193 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_EventScript_Boy2BrineyLeftTunnel
# 194 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyWalksInTheTunnel, MSGBOX_DEFAULT
# 195 "data/maps/RustboroCity/scripts.pory"
	release
# 196 "data/maps/RustboroCity/scripts.pory"
	end
# 197 "data/maps/RustboroCity/scripts.pory"

# 198 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy2BrineyLeftTunnel::
# 199 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
# 200 "data/maps/RustboroCity/scripts.pory"
	release
# 201 "data/maps/RustboroCity/scripts.pory"
	end
# 202 "data/maps/RustboroCity/scripts.pory"

# 203 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Twin::
# 204 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
# 205 "data/maps/RustboroCity/scripts.pory"
	end
# 206 "data/maps/RustboroCity/scripts.pory"

# 207 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_NinjaBoy::
# 208 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
# 209 "data/maps/RustboroCity/scripts.pory"
	end
# 210 "data/maps/RustboroCity/scripts.pory"

# 211 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TunnelSign::
# 212 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
# 213 "data/maps/RustboroCity/scripts.pory"
	end
# 214 "data/maps/RustboroCity/scripts.pory"

# 215 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpSign::
# 216 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
# 217 "data/maps/RustboroCity/scripts.pory"
	end
# 218 "data/maps/RustboroCity/scripts.pory"

# 219 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_GymSign::
# 220 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
# 221 "data/maps/RustboroCity/scripts.pory"
	end
# 222 "data/maps/RustboroCity/scripts.pory"

# 223 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_DevonCorpBranchOfficeSign::
# 225 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
# 226 "data/maps/RustboroCity/scripts.pory"
	end
# 227 "data/maps/RustboroCity/scripts.pory"

# 228 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CitySign::
# 229 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
# 230 "data/maps/RustboroCity/scripts.pory"
	end
# 231 "data/maps/RustboroCity/scripts.pory"

# 232 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_TrainersSchoolSign::
# 233 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
# 234 "data/maps/RustboroCity/scripts.pory"
	end
# 235 "data/maps/RustboroCity/scripts.pory"

# 236 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_CuttersHouseSign::
# 237 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
# 238 "data/maps/RustboroCity/scripts.pory"
	end
# 239 "data/maps/RustboroCity/scripts.pory"

# 240 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleBoy::
# 241 "data/maps/RustboroCity/scripts.pory"
	lock
# 242 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 243 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
# 244 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
# 245 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 246 "data/maps/RustboroCity/scripts.pory"
	release
# 247 "data/maps/RustboroCity/scripts.pory"
	end
# 248 "data/maps/RustboroCity/scripts.pory"

# 249 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_LittleGirl::
# 250 "data/maps/RustboroCity/scripts.pory"
	lock
# 251 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 252 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
# 253 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
# 254 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 255 "data/maps/RustboroCity/scripts.pory"
	release
# 256 "data/maps/RustboroCity/scripts.pory"
	end
# 257 "data/maps/RustboroCity/scripts.pory"

# 258 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Man2::
# 259 "data/maps/RustboroCity/scripts.pory"
	lock
# 260 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 261 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
# 262 "data/maps/RustboroCity/scripts.pory"
	release
# 263 "data/maps/RustboroCity/scripts.pory"
	end
# 264 "data/maps/RustboroCity/scripts.pory"

# 265 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger0::
# 266 "data/maps/RustboroCity/scripts.pory"
	lockall
# 267 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 268 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 269 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 0
# 270 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 271 "data/maps/RustboroCity/scripts.pory"
	end
# 272 "data/maps/RustboroCity/scripts.pory"

# 273 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger1::
# 274 "data/maps/RustboroCity/scripts.pory"
	lockall
# 275 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 276 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 277 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 1
# 278 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 279 "data/maps/RustboroCity/scripts.pory"
	end
# 280 "data/maps/RustboroCity/scripts.pory"

# 281 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger2::
# 282 "data/maps/RustboroCity/scripts.pory"
	lockall
# 283 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 284 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 285 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 2
# 286 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 287 "data/maps/RustboroCity/scripts.pory"
	end
# 288 "data/maps/RustboroCity/scripts.pory"

# 289 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger3::
# 290 "data/maps/RustboroCity/scripts.pory"
	lockall
# 291 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 292 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 293 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 3
# 294 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 295 "data/maps/RustboroCity/scripts.pory"
	end
# 296 "data/maps/RustboroCity/scripts.pory"

# 297 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsTrigger4::
# 298 "data/maps/RustboroCity/scripts.pory"
	lockall
# 299 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
# 300 "data/maps/RustboroCity/scripts.pory"
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
# 301 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8004, 4
# 302 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_StolenGoodsScene
# 303 "data/maps/RustboroCity/scripts.pory"
	end
# 304 "data/maps/RustboroCity/scripts.pory"

# 305 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_StolenGoodsScene::
# 306 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
# 307 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 308 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 309 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_GRUNT
# 310 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_DEVON_EMPLOYEE
# 311 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
# 312 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 313 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_GRUNT
# 314 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
# 315 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 316 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
# 317 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 318 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
# 319 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 320 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 321 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_DEVON_EMPLOYEE
# 322 "data/maps/RustboroCity/scripts.pory"
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
# 323 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 324 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEVON_GOODS_STOLEN
# 325 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 2
# 326 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
# 327 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE116_STATE, 1
# 328 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 329 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 330 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 331 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 332 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 333 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 334 "data/maps/RustboroCity/scripts.pory"
	end
# 335 "data/maps/RustboroCity/scripts.pory"

# 336 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 337 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 338 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 339 "data/maps/RustboroCity/scripts.pory"
	return
# 340 "data/maps/RustboroCity/scripts.pory"

# 341 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 342 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 343 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 344 "data/maps/RustboroCity/scripts.pory"
	return
# 345 "data/maps/RustboroCity/scripts.pory"

# 346 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 347 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 348 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 349 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 350 "data/maps/RustboroCity/scripts.pory"
	return
# 351 "data/maps/RustboroCity/scripts.pory"

# 352 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 353 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 354 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 355 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 356 "data/maps/RustboroCity/scripts.pory"
	return
# 357 "data/maps/RustboroCity/scripts.pory"

# 358 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 359 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 360 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 361 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 362 "data/maps/RustboroCity/scripts.pory"
	return
# 363 "data/maps/RustboroCity/scripts.pory"

# 364 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 365 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 366 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 367 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 368 "data/maps/RustboroCity/scripts.pory"
	return
# 369 "data/maps/RustboroCity/scripts.pory"

# 370 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 371 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 372 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 373 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 374 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 375 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 376 "data/maps/RustboroCity/scripts.pory"
	return
# 377 "data/maps/RustboroCity/scripts.pory"

# 378 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 379 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 380 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 381 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 382 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 383 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 384 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 385 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 386 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 387 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 388 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 389 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 390 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 391 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 392 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 393 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 394 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 395 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 396 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 397 "data/maps/RustboroCity/scripts.pory"
	step_end
# 398 "data/maps/RustboroCity/scripts.pory"

# 399 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 400 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 401 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 402 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 404 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 405 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 406 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 415 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 416 "data/maps/RustboroCity/scripts.pory"
	step_end
# 417 "data/maps/RustboroCity/scripts.pory"

# 418 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
# 419 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 420 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 421 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 422 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 423 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 424 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 425 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 426 "data/maps/RustboroCity/scripts.pory"
	step_end
# 427 "data/maps/RustboroCity/scripts.pory"

# 428 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
# 429 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 430 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 431 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 432 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 433 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 434 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 435 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 436 "data/maps/RustboroCity/scripts.pory"
	step_end
# 437 "data/maps/RustboroCity/scripts.pory"

# 438 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 439 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 440 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 441 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 442 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 443 "data/maps/RustboroCity/scripts.pory"
	step_end
# 444 "data/maps/RustboroCity/scripts.pory"

# 445 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 446 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 447 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 448 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 449 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 450 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 451 "data/maps/RustboroCity/scripts.pory"
	step_end
# 452 "data/maps/RustboroCity/scripts.pory"

# 453 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 454 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 455 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 456 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 457 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 458 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 459 "data/maps/RustboroCity/scripts.pory"
	step_end
# 460 "data/maps/RustboroCity/scripts.pory"

# 461 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 462 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachDown:
# 463 "data/maps/RustboroCity/scripts.pory"
	walk_down
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
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 472 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 473 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 474 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 475 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 476 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 477 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 478 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 479 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 483 "data/maps/RustboroCity/scripts.pory"
	lock
# 484 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 485 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 486 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 487 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 492 "data/maps/RustboroCity/scripts.pory"
	waitse
# 493 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 494 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 499 "data/maps/RustboroCity/scripts.pory"
	lockall
# 500 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 501 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 506 "data/maps/RustboroCity/scripts.pory"
	lockall
# 507 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 508 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 513 "data/maps/RustboroCity/scripts.pory"
	lockall
# 514 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 515 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 520 "data/maps/RustboroCity/scripts.pory"
	lockall
# 521 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 522 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 527 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 528 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RIVAL1
# 529 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 530 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 531 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 532 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 533 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 534 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 535 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_DEVON_EMPLOYEE
# 536 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 537 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 538 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 543 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 544 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 545 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 546 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 547 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 548 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 549 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachPlayer
# 550 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 551 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 552 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 553 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 554 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 555 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 556 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 557 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 558 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 562 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 566 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 567 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 572 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 573 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 574 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 575 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 579 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 581 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 582 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 583 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 584 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 585 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 588 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 591 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 592 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 596 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 597 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 598 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 599 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceRight
# 600 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 601 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 602 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 604 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 606 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 607 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 610 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 611 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 612 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RIVAL1
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 559 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 560 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceLeft
# 561 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 563 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 564 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceDown
# 565 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 568 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 569 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceLeft
# 570 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 576 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 586 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 587 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 589 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 590 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 593 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 594 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 603 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 605 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 608 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 618 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 619 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 620 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 621 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 622 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 623 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 624 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 625 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 626 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 627 "data/maps/RustboroCity/scripts.pory"
	setobjectxy LOCALID_RIVAL1, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 632 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 633 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 634 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 635 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 636 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 637 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 638 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 639 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 640 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 645 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 646 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 647 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 648 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 649 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 650 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 651 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 652 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 653 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 654 "data/maps/RustboroCity/scripts.pory"
	setobjectxy LOCALID_RIVAL1, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 659 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 660 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 661 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 662 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 663 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 664 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 665 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 666 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 667 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 668 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 669 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 670 "data/maps/RustboroCity/scripts.pory"
	setobjectxy LOCALID_RIVAL1, 22, 12
	return


# 674 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 675 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 676 "data/maps/RustboroCity/scripts.pory"
	step_end

# 679 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 680 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 683 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 684 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 684 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 684 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 685 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 688 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 689 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 690 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 690 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 693 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 694 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 695 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 695 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 696 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 696 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 699 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 700 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 701 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 701 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 704 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 705 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 705 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 708 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 709 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 709 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 712 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 713 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 713 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 716 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 717 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 717 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 720 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 721 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 722 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 722 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 725 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 726 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 726 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 727 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 728 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 731 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 732 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 733 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 736 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2and3:
# 737 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 737 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 738 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 739 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 769 "data/maps/RustboroCity/scripts.pory"

# 770 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 771 "data/maps/RustboroCity/scripts.pory"
	lockall
# 772 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 773 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 774 "data/maps/RustboroCity/scripts.pory"
	end
# 775 "data/maps/RustboroCity/scripts.pory"

# 776 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 777 "data/maps/RustboroCity/scripts.pory"
	lockall
# 778 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 779 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 780 "data/maps/RustboroCity/scripts.pory"
	end
# 781 "data/maps/RustboroCity/scripts.pory"

# 782 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 783 "data/maps/RustboroCity/scripts.pory"
	lockall
# 784 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 785 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 786 "data/maps/RustboroCity/scripts.pory"
	end
# 787 "data/maps/RustboroCity/scripts.pory"

# 788 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 789 "data/maps/RustboroCity/scripts.pory"
	lockall
# 790 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 791 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 792 "data/maps/RustboroCity/scripts.pory"
	end
# 793 "data/maps/RustboroCity/scripts.pory"

# 794 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 795 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 796 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 797 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 798 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 799 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 800 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 801 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 802 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 803 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 804 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 805 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 806 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 807 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 808 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 809 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 810 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 811 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 812 "data/maps/RustboroCity/scripts.pory"
	end
# 813 "data/maps/RustboroCity/scripts.pory"

# 814 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 815 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 816 "data/maps/RustboroCity/scripts.pory"
	return
# 817 "data/maps/RustboroCity/scripts.pory"

# 818 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 819 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 820 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 821 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 822 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 823 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 824 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 825 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 826 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 827 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 828 "data/maps/RustboroCity/scripts.pory"
	return
# 829 "data/maps/RustboroCity/scripts.pory"

# 830 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 831 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 832 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 833 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 834 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 835 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 836 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 837 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 838 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 839 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 840 "data/maps/RustboroCity/scripts.pory"
	return
# 841 "data/maps/RustboroCity/scripts.pory"

# 842 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 843 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 844 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 845 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 846 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 847 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 848 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 849 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 850 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 851 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 852 "data/maps/RustboroCity/scripts.pory"
	return
# 853 "data/maps/RustboroCity/scripts.pory"

# 854 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 855 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 856 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 857 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 858 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 859 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 860 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 861 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 862 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 863 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 864 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 865 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 866 "data/maps/RustboroCity/scripts.pory"
	return
# 867 "data/maps/RustboroCity/scripts.pory"

# 868 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 869 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 870 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 871 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 872 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 873 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 874 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 875 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 876 "data/maps/RustboroCity/scripts.pory"
	return
# 877 "data/maps/RustboroCity/scripts.pory"

# 878 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 879 "data/maps/RustboroCity/scripts.pory"
	lockall
# 880 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 881 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 882 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 883 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 884 "data/maps/RustboroCity/scripts.pory"

# 885 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 886 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 887 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 888 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 889 "data/maps/RustboroCity/scripts.pory"
	return
# 890 "data/maps/RustboroCity/scripts.pory"

# 891 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 892 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 893 "data/maps/RustboroCity/scripts.pory"
	return
# 894 "data/maps/RustboroCity/scripts.pory"

# 895 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 896 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 897 "data/maps/RustboroCity/scripts.pory"
	return
# 898 "data/maps/RustboroCity/scripts.pory"

# 899 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 900 "data/maps/RustboroCity/scripts.pory"
	lockall
# 901 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 902 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 903 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 904 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 905 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 906 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 907 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 908 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 909 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 910 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 911 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 912 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 913 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 914 "data/maps/RustboroCity/scripts.pory"

# 915 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 916 "data/maps/RustboroCity/scripts.pory"
	lockall
# 917 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 918 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 919 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 920 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 921 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 922 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 923 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 924 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 925 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 926 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 927 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 928 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 929 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 930 "data/maps/RustboroCity/scripts.pory"

# 931 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 932 "data/maps/RustboroCity/scripts.pory"
	lockall
# 933 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 934 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 935 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 936 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 937 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 938 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 939 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 940 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 941 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 942 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 943 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 944 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 945 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 946 "data/maps/RustboroCity/scripts.pory"

# 947 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 948 "data/maps/RustboroCity/scripts.pory"
	lockall
# 949 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 950 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 951 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 952 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 953 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 954 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 955 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 956 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 957 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 958 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 959 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 960 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 961 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 962 "data/maps/RustboroCity/scripts.pory"

# 963 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 964 "data/maps/RustboroCity/scripts.pory"
	lockall
# 965 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 966 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 967 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 968 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 969 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 970 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 971 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 972 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 973 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 974 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 975 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 976 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 977 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 978 "data/maps/RustboroCity/scripts.pory"

# 979 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
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
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
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
RustboroCity_EventScript_RivalTrigger6::
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
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
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
RustboroCity_EventScript_RivalTrigger7::
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
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
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
RustboroCity_EventScript_RivalEncounter::
# 1028 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 1029 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1030 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1031 "data/maps/RustboroCity/scripts.pory"
	end
# 1032 "data/maps/RustboroCity/scripts.pory"

# 1033 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1034 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1035 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1036 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1037 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1038 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1039 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1040 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1041 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1042 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1043 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1044 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1045 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1046 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1047 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1048 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1049 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1050 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1051 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1052 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1053 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1054 "data/maps/RustboroCity/scripts.pory"
	end
# 1055 "data/maps/RustboroCity/scripts.pory"

# 1056 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1057 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1058 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1059 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1060 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1061 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1062 "data/maps/RustboroCity/scripts.pory"
	end
# 1063 "data/maps/RustboroCity/scripts.pory"

# 1064 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1065 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1066 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1067 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 1068 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 1069 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 1070 "data/maps/RustboroCity/scripts.pory"
	end
# 1071 "data/maps/RustboroCity/scripts.pory"

# 1072 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1073 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1074 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1075 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1076 "data/maps/RustboroCity/scripts.pory"
	end
# 1077 "data/maps/RustboroCity/scripts.pory"

# 1078 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1079 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1080 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1081 "data/maps/RustboroCity/scripts.pory"
	return
# 1082 "data/maps/RustboroCity/scripts.pory"

# 1083 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 1084 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 1085 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1086 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1087 "data/maps/RustboroCity/scripts.pory"
	end
# 1088 "data/maps/RustboroCity/scripts.pory"

# 1089 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 1090 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 1091 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1092 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1093 "data/maps/RustboroCity/scripts.pory"
	end
# 1094 "data/maps/RustboroCity/scripts.pory"

# 1095 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 1096 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 1097 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1098 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1099 "data/maps/RustboroCity/scripts.pory"
	end
# 1100 "data/maps/RustboroCity/scripts.pory"

# 1101 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1102 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1103 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1104 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1105 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1106 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1107 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1108 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1109 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1110 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1111 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1112 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1113 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1114 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1115 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1116 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1117 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1118 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1119 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1120 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1121 "data/maps/RustboroCity/scripts.pory"
	end
# 1122 "data/maps/RustboroCity/scripts.pory"

# 1123 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1124 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1125 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1126 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1127 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1128 "data/maps/RustboroCity/scripts.pory"
	end
# 1129 "data/maps/RustboroCity/scripts.pory"

# 1130 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1131 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1132 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1133 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 1134 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 1135 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 1136 "data/maps/RustboroCity/scripts.pory"
	end
# 1137 "data/maps/RustboroCity/scripts.pory"

# 1138 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1139 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1140 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1141 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1142 "data/maps/RustboroCity/scripts.pory"
	end
# 1143 "data/maps/RustboroCity/scripts.pory"

# 1144 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 1145 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 1146 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1147 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1148 "data/maps/RustboroCity/scripts.pory"
	end
# 1149 "data/maps/RustboroCity/scripts.pory"

# 1150 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 1151 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 1152 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1153 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1154 "data/maps/RustboroCity/scripts.pory"
	end
# 1155 "data/maps/RustboroCity/scripts.pory"

# 1156 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 1157 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 1158 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1159 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1160 "data/maps/RustboroCity/scripts.pory"
	end
# 1161 "data/maps/RustboroCity/scripts.pory"

# 1162 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1163 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1164 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1165 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1166 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1167 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1168 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1169 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1170 "data/maps/RustboroCity/scripts.pory"

# 1171 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1172 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1173 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1174 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1175 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1176 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1177 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1178 "data/maps/RustboroCity/scripts.pory"

# 1179 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1180 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1181 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1182 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1183 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1184 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1185 "data/maps/RustboroCity/scripts.pory"

# 1186 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1187 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1188 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1189 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1190 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1191 "data/maps/RustboroCity/scripts.pory"

# 1192 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1193 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1194 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1195 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1196 "data/maps/RustboroCity/scripts.pory"

# 1197 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1198 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1199 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1200 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1201 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1202 "data/maps/RustboroCity/scripts.pory"

# 1203 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1204 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1205 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1206 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1207 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1208 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1209 "data/maps/RustboroCity/scripts.pory"

# 1210 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1211 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1212 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1213 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1214 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1215 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1216 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1217 "data/maps/RustboroCity/scripts.pory"

# 1218 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1219 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1220 "data/maps/RustboroCity/scripts.pory"
	end
# 1221 "data/maps/RustboroCity/scripts.pory"

# 1222 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1223 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1224 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1225 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1226 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1227 "data/maps/RustboroCity/scripts.pory"

# 1228 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1229 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1230 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1231 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1232 "data/maps/RustboroCity/scripts.pory"

# 1233 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1234 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1235 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1236 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1237 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1238 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1239 "data/maps/RustboroCity/scripts.pory"

# 1240 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1241 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1242 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1243 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1244 "data/maps/RustboroCity/scripts.pory"

# 1245 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1246 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1247 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1248 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1249 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1250 "data/maps/RustboroCity/scripts.pory"

# 1251 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1252 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1253 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1254 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1255 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1256 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1257 "data/maps/RustboroCity/scripts.pory"

# 1258 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1259 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1260 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1261 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1262 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1263 "data/maps/RustboroCity/scripts.pory"

# 1264 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1265 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1266 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1267 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1268 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1269 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1270 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1271 "data/maps/RustboroCity/scripts.pory"

# 1272 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1273 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1274 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1275 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1276 "data/maps/RustboroCity/scripts.pory"

# 1277 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1278 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1279 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1280 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1281 "data/maps/RustboroCity/scripts.pory"

# 1282 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1283 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1284 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1285 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1286 "data/maps/RustboroCity/scripts.pory"

# 1287 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1288 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1289 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1290 "data/maps/RustboroCity/scripts.pory"

# 1291 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1292 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1293 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1294 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1295 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1296 "data/maps/RustboroCity/scripts.pory"

# 1297 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1298 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1299 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1300 "data/maps/RustboroCity/scripts.pory"

# 1301 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1302 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1303 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1304 "data/maps/RustboroCity/scripts.pory"

# 1305 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1306 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1307 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1308 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1309 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1310 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1311 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1312 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1313 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1314 "data/maps/RustboroCity/scripts.pory"

# 1315 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1316 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1317 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1318 "data/maps/RustboroCity/scripts.pory"

# 1319 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1320 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1321 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1322 "data/maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1323 "data/maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1324 "data/maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1325 "data/maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1326 "data/maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1327 "data/maps/RustboroCity/scripts.pory"

# 1328 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1329 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1330 "data/maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1331 "data/maps/RustboroCity/scripts.pory"

# 1332 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1333 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1334 "data/maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1335 "data/maps/RustboroCity/scripts.pory"

# 1336 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1337 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1338 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1339 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1340 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1341 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1342 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1343 "data/maps/RustboroCity/scripts.pory"

# 1344 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1345 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1346 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1347 "data/maps/RustboroCity/scripts.pory"

# 1348 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1349 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1350 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1351 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1352 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1353 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1354 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1355 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1356 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1357 "data/maps/RustboroCity/scripts.pory"

# 1358 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1359 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1360 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1361 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1362 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1363 "data/maps/RustboroCity/scripts.pory"

# 1364 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1365 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1366 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1367 "data/maps/RustboroCity/scripts.pory"

# 1368 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1369 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1370 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1371 "data/maps/RustboroCity/scripts.pory"

# 1372 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1373 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1374 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1375 "data/maps/RustboroCity/scripts.pory"

# 1376 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1377 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1378 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1379 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1380 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1381 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1382 "data/maps/RustboroCity/scripts.pory"

# 1383 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1384 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1385 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1386 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1387 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1388 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1389 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1390 "data/maps/RustboroCity/scripts.pory"

# 1391 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1392 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1393 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1394 "data/maps/RustboroCity/scripts.pory"

# 1395 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1396 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1397 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1398 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1399 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1400 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1401 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1402 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1403 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1404 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1405 "data/maps/RustboroCity/scripts.pory"

# 1406 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1407 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1408 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1409 "data/maps/RustboroCity/scripts.pory"

# 1410 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1411 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1412 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1413 "data/maps/RustboroCity/scripts.pory"

# 1414 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1415 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1416 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1417 "data/maps/RustboroCity/scripts.pory"

# 1418 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1419 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1420 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1421 "data/maps/RustboroCity/scripts.pory"

# 1422 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1423 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1424 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1425 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1426 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1427 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1428 "data/maps/RustboroCity/scripts.pory"

# 1429 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1430 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1431 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1432 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1433 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1434 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1435 "data/maps/RustboroCity/scripts.pory"

# 1436 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1437 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1438 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1439 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1440 "data/maps/RustboroCity/scripts.pory"

# 1441 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1442 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1443 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1444 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1445 "data/maps/RustboroCity/scripts.pory"

# 1446 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1447 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1448 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1449 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1450 "data/maps/RustboroCity/scripts.pory"

# 1451 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1452 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1453 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1454 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1455 "data/maps/RustboroCity/scripts.pory"

# 1456 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1457 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1458 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1459 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1460 "data/maps/RustboroCity/scripts.pory"

# 1461 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1462 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1463 "data/maps/RustboroCity/scripts.pory"

# 1464 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1465 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1466 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1467 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1468 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1469 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1470 "data/maps/RustboroCity/scripts.pory"

# 1471 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1472 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1473 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1474 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1475 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1476 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1477 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1478 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1479 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1480 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1481 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1482 "data/maps/RustboroCity/scripts.pory"

# 1483 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1484 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1485 "data/maps/RustboroCity/scripts.pory"

# 1486 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1487 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1488 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1489 "data/maps/RustboroCity/scripts.pory"

# 1490 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1491 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1492 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1493 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1494 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1495 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1496 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1497 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1498 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_Text_YoPlayer::
# 742 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 746 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 751 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 755 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 759 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 764 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"
