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
	clearflag FLAG_HIDE_ROUTE_116_RIVAL1
# 330 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
# 331 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
# 332 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
# 333 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
# 334 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 335 "data/maps/RustboroCity/scripts.pory"
	end
# 336 "data/maps/RustboroCity/scripts.pory"

# 337 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 338 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ShadyCharacterTookOff::
# 339 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 340 "data/maps/RustboroCity/scripts.pory"
	return
# 341 "data/maps/RustboroCity/scripts.pory"

# 342 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 343 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_YouGotItThankYou::
# 344 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 345 "data/maps/RustboroCity/scripts.pory"
	return
# 346 "data/maps/RustboroCity/scripts.pory"

# 347 "data/maps/RustboroCity/scripts.pory"
@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
# 348 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachUp::
# 349 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
# 350 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 351 "data/maps/RustboroCity/scripts.pory"
	return
# 352 "data/maps/RustboroCity/scripts.pory"

# 353 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 354 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachLeft::
# 355 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
# 356 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 357 "data/maps/RustboroCity/scripts.pory"
	return
# 358 "data/maps/RustboroCity/scripts.pory"

# 359 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 360 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachRight::
# 361 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
# 362 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 363 "data/maps/RustboroCity/scripts.pory"
	return
# 364 "data/maps/RustboroCity/scripts.pory"

# 365 "data/maps/RustboroCity/scripts.pory"
@ Unused, see above
# 366 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachDown::
# 367 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
# 368 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 369 "data/maps/RustboroCity/scripts.pory"
	return
# 370 "data/maps/RustboroCity/scripts.pory"

# 371 "data/maps/RustboroCity/scripts.pory"
@ Unused, similar movement to the above scripts
# 372 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeApproachPlayerFar::
# 373 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
# 374 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 375 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 376 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 377 "data/maps/RustboroCity/scripts.pory"
	return
# 378 "data/maps/RustboroCity/scripts.pory"

# 379 "data/maps/RustboroCity/scripts.pory"
@ Unused
# 380 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscapeExtended:
# 381 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 382 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 383 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 384 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 385 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 386 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	walk_fast_up
# 398 "data/maps/RustboroCity/scripts.pory"
	step_end
# 399 "data/maps/RustboroCity/scripts.pory"

# 400 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_GruntEscape:
# 401 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 402 "data/maps/RustboroCity/scripts.pory"
	walk_faster_right
# 403 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
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
	step_end
# 418 "data/maps/RustboroCity/scripts.pory"

# 419 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt1:
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
	walk_right
# 426 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_up
# 427 "data/maps/RustboroCity/scripts.pory"
	step_end
# 428 "data/maps/RustboroCity/scripts.pory"

# 429 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeChaseGrunt2:
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
	walk_up
# 437 "data/maps/RustboroCity/scripts.pory"
	step_end
# 438 "data/maps/RustboroCity/scripts.pory"

# 439 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 440 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachUp:
# 441 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 442 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 443 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 444 "data/maps/RustboroCity/scripts.pory"
	step_end
# 445 "data/maps/RustboroCity/scripts.pory"

# 446 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 447 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachLeft:
# 448 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 449 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 450 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 451 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 452 "data/maps/RustboroCity/scripts.pory"
	step_end
# 453 "data/maps/RustboroCity/scripts.pory"

# 454 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 455 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachRight:
# 456 "data/maps/RustboroCity/scripts.pory"
	walk_down
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
RustboroCity_Movement_EmployeeApproachDown:
# 464 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 465 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 466 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 467 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 468 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 469 "data/maps/RustboroCity/scripts.pory"
	step_end
# 470 "data/maps/RustboroCity/scripts.pory"

# 471 "data/maps/RustboroCity/scripts.pory"
@ Functionally unused
# 472 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerFar:
# 473 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 474 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 475 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 476 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 477 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 478 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 479 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_down
# 480 "data/maps/RustboroCity/scripts.pory"
	step_end

RustboroCity_EventScript_DevonEmployee1::
# 484 "data/maps/RustboroCity/scripts.pory"
	lock
# 485 "data/maps/RustboroCity/scripts.pory"
	faceplayer
# 486 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
# 487 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
# 488 "data/maps/RustboroCity/scripts.pory"
	release
	end


RustboroCity_EventScript_ReturnGoodsSpokeToEmployee::
# 493 "data/maps/RustboroCity/scripts.pory"
	waitse
# 494 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 4
# 495 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger0::
# 500 "data/maps/RustboroCity/scripts.pory"
	lockall
# 501 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 502 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger1::
# 507 "data/maps/RustboroCity/scripts.pory"
	lockall
# 508 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 509 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger2::
# 514 "data/maps/RustboroCity/scripts.pory"
	lockall
# 515 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 516 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_HelpGetGoodsTrigger3::
# 521 "data/maps/RustboroCity/scripts.pory"
	lockall
# 522 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 523 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end


RustboroCity_EventScript_EmployeeAskToGetGoods::
# 528 "data/maps/RustboroCity/scripts.pory"
	clearflag FLAG_HIDE_RUSTBORO_RIVAL1
# 529 "data/maps/RustboroCity/scripts.pory"
	addobject LOCALID_RIVAL1
# 530 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp1
# 531 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft1
# 532 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown1
# 533 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown1
# 534 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
# 535 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 3
# 536 "data/maps/RustboroCity/scripts.pory"
	copyobjectxytoperm LOCALID_DEVON_EMPLOYEE
# 537 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
# 538 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_Rival1AfterAskToGetGoods
# 539 "data/maps/RustboroCity/scripts.pory"
	releaseall
	end


RustboroCity_EventScript_Rival1AfterAskToGetGoods::
# 544 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 545 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 546 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 547 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_NoticeRival1
# 548 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 549 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoPlayer, MSGBOX_DEFAULT
# 550 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 551 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachPlayer
# 552 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 553 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_WhatsGoingOn, MSGBOX_DEFAULT
# 554 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 555 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerExplain
# 556 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 557 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_GuyGotMugged, MSGBOX_DEFAULT
# 558 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 559 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 560 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_3
# 564 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_4
# 568 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
# 569 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_5
RustboroCity_EventScript_Rival1AfterAskToGetGoods_1:
# 574 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 575 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_DontWorrySir, MSGBOX_DEFAULT
# 576 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 577 "data/maps/RustboroCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq RustboroCity_EventScript_Rival1AfterAskToGetGoods_7
# 581 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_SpeakLeft
RustboroCity_EventScript_Rival1AfterAskToGetGoods_6:
# 583 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 584 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_ThankBothOfYou, MSGBOX_DEFAULT
# 585 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 586 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 587 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_12
# 590 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_13
# 593 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
# 594 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_14
RustboroCity_EventScript_Rival1AfterAskToGetGoods_10:
# 598 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 599 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_LetsGoCatchMugger, MSGBOX_DEFAULT
# 600 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 601 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceRight
# 602 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 603 "data/maps/RustboroCity/scripts.pory"
	switch VAR_TEMP_1
# 604 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_Rival1AfterAskToGetGoods_17
# 606 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_Rival1AfterAskToGetGoods_18
# 608 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_Rival1AfterAskToGetGoods_19
# 610 "data/maps/RustboroCity/scripts.pory"
	case 3, RustboroCity_EventScript_Rival1AfterAskToGetGoods_20
RustboroCity_EventScript_Rival1AfterAskToGetGoods_15:
# 613 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 614 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_RIVAL1
# 615 "data/maps/RustboroCity/scripts.pory"
	removeobject LOCALID_RIVAL1
	return

RustboroCity_EventScript_Rival1AfterAskToGetGoods_3:
# 561 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 562 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceLeft
# 563 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_4:
# 565 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 566 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceDown
# 567 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_5:
# 570 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
# 571 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_FaceLeft
# 572 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_1

RustboroCity_EventScript_Rival1AfterAskToGetGoods_7:
# 578 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_SpeakDown
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_6

RustboroCity_EventScript_Rival1AfterAskToGetGoods_12:
# 588 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 589 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee2and3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_13:
# 591 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
# 592 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ReturnToPlayer1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_14:
# 595 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 596 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ApproachDevonEmployee0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_10

RustboroCity_EventScript_Rival1AfterAskToGetGoods_17:
# 605 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger0
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_18:
# 607 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger1
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_19:
# 609 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger2
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15

RustboroCity_EventScript_Rival1AfterAskToGetGoods_20:
# 611 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL1, RustboroCity_Movement_Rival1ChaseMugger3
	goto RustboroCity_EventScript_Rival1AfterAskToGetGoods_15


RustboroCity_EventScript_EmployeeFacePlayerUp1::
# 621 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 622 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 623 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 624 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 625 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 626 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 627 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 628 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 629 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 630 "data/maps/RustboroCity/scripts.pory"
	setobjectxy LOCALID_RIVAL1, 22, 9
	return


RustboroCity_EventScript_EmployeeFacePlayerLeft1::
# 635 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 636 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 637 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 638 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 639 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 640 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 641 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 642 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
# 643 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
	return


RustboroCity_EventScript_EmployeeFacePlayerDown1::
# 648 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 649 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 650 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 651 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 652 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 653 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 654 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 655 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 656 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 657 "data/maps/RustboroCity/scripts.pory"
	setobjectxy LOCALID_RIVAL1, 22, 11
	return


RustboroCity_EventScript_EmployeeApproachPlayerDown1::
# 662 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 663 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 664 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 665 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 666 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 667 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 668 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 669 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 670 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 671 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 672 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 673 "data/maps/RustboroCity/scripts.pory"
	setobjectxy LOCALID_RIVAL1, 22, 12
	return


# 677 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_EmployeeApproachPlayerDown:
# 678 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 679 "data/maps/RustboroCity/scripts.pory"
	step_end

# 682 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_NoticeRival1:
# 683 "data/maps/RustboroCity/scripts.pory"
	emote_exclamation_mark
# 684 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_faster_left
	step_end

# 687 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachPlayer:
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 688 "data/maps/RustboroCity/scripts.pory"
	walk_right
	step_end

# 691 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_PlayerExplain:
# 692 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 692 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 692 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 693 "data/maps/RustboroCity/scripts.pory"
	delay_16
	step_end

# 696 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee0:
# 697 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 698 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 698 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 701 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee1:
# 702 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 703 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 703 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 704 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 707 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ApproachDevonEmployee2and3:
# 708 "data/maps/RustboroCity/scripts.pory"
	walk_up
# 709 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 709 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 712 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakUp:
# 713 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 713 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 716 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakDown:
# 717 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
# 717 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_down
	step_end

# 720 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakRight:
# 721 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
# 721 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_right
	step_end

# 724 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_SpeakLeft:
# 725 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
# 725 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_left
	step_end

# 728 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ReturnToPlayer1:
# 729 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 730 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
# 730 "data/maps/RustboroCity/scripts.pory"
	walk_in_place_up
	step_end

# 733 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger0:
# 734 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 734 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 735 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 736 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 739 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger1:
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 740 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 741 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 744 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger2:
# 745 "data/maps/RustboroCity/scripts.pory"
	walk_fast_down
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 746 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 747 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 750 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_Rival1ChaseMugger3:
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 751 "data/maps/RustboroCity/scripts.pory"
	walk_fast_up
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 752 "data/maps/RustboroCity/scripts.pory"
	walk_fast_right
# 753 "data/maps/RustboroCity/scripts.pory"
	set_invisible
	step_end

# 783 "data/maps/RustboroCity/scripts.pory"

# 784 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger0::
# 785 "data/maps/RustboroCity/scripts.pory"
	lockall
# 786 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 787 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 788 "data/maps/RustboroCity/scripts.pory"
	end
# 789 "data/maps/RustboroCity/scripts.pory"

# 790 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger1::
# 791 "data/maps/RustboroCity/scripts.pory"
	lockall
# 792 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 793 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 794 "data/maps/RustboroCity/scripts.pory"
	end
# 795 "data/maps/RustboroCity/scripts.pory"

# 796 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger2::
# 797 "data/maps/RustboroCity/scripts.pory"
	lockall
# 798 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 799 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 800 "data/maps/RustboroCity/scripts.pory"
	end
# 801 "data/maps/RustboroCity/scripts.pory"

# 802 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoodsTrigger3::
# 803 "data/maps/RustboroCity/scripts.pory"
	lockall
# 804 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 805 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_ReturnGoods
# 806 "data/maps/RustboroCity/scripts.pory"
	end
# 807 "data/maps/RustboroCity/scripts.pory"

# 808 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_ReturnGoods::
# 809 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, RustboroCity_EventScript_EmployeeFacePlayerUp2
# 810 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RustboroCity_EventScript_EmployeeFacePlayerLeft2
# 811 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RustboroCity_EventScript_EmployeeFacePlayerDown2
# 812 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RustboroCity_EventScript_EmployeeApproachPlayerDown2
# 813 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 4, RustboroCity_EventScript_EmployeeFacePlayerRight
# 814 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
# 815 "data/maps/RustboroCity/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 816 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, RustboroCity_EventScript_BagFull
# 817 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
# 818 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 819 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_RETURNED_DEVON_GOODS
# 820 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
# 821 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 5
# 822 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 823 "data/maps/RustboroCity/scripts.pory"
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 2, 2
# 824 "data/maps/RustboroCity/scripts.pory"
	waitstate
# 825 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 826 "data/maps/RustboroCity/scripts.pory"
	end
# 827 "data/maps/RustboroCity/scripts.pory"

# 828 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BagFull::
# 829 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 830 "data/maps/RustboroCity/scripts.pory"
	return
# 831 "data/maps/RustboroCity/scripts.pory"

# 832 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerUp2::
# 833 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 834 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 835 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 836 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 837 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 838 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 839 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 840 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 841 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 842 "data/maps/RustboroCity/scripts.pory"
	return
# 843 "data/maps/RustboroCity/scripts.pory"

# 844 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerLeft2::
# 845 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterRight
# 846 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 847 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 848 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 849 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 850 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 851 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 852 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
# 853 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 854 "data/maps/RustboroCity/scripts.pory"
	return
# 855 "data/maps/RustboroCity/scripts.pory"

# 856 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerDown2::
# 857 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
# 858 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 859 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 860 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 861 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 862 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
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
RustboroCity_EventScript_EmployeeApproachPlayerDown2::
# 869 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterDown
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
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
# 877 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 878 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 879 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 880 "data/maps/RustboroCity/scripts.pory"
	return
# 881 "data/maps/RustboroCity/scripts.pory"

# 882 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_EmployeeFacePlayerRight::
# 883 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterLeft
# 884 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 885 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 886 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
# 887 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 888 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
# 889 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 890 "data/maps/RustboroCity/scripts.pory"
	return
# 891 "data/maps/RustboroCity/scripts.pory"

# 892 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Rival::
# 893 "data/maps/RustboroCity/scripts.pory"
	lockall
# 894 "data/maps/RustboroCity/scripts.pory"
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
# 895 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 896 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 897 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 898 "data/maps/RustboroCity/scripts.pory"

# 899 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayRivalMusic::
# 900 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 901 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
# 902 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
# 903 "data/maps/RustboroCity/scripts.pory"
	return
# 904 "data/maps/RustboroCity/scripts.pory"

# 905 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayMayMusic::
# 906 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 907 "data/maps/RustboroCity/scripts.pory"
	return
# 908 "data/maps/RustboroCity/scripts.pory"

# 909 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_PlayBrendanMusic::
# 910 "data/maps/RustboroCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 911 "data/maps/RustboroCity/scripts.pory"
	return
# 912 "data/maps/RustboroCity/scripts.pory"

# 913 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger0::
# 914 "data/maps/RustboroCity/scripts.pory"
	lockall
# 915 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 916 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 917 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 918 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 919 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 920 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 921 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 922 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 923 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
# 924 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 925 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 926 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 927 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 928 "data/maps/RustboroCity/scripts.pory"

# 929 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger1::
# 930 "data/maps/RustboroCity/scripts.pory"
	lockall
# 931 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 932 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 933 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 934 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 935 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 936 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 937 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 938 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 939 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
# 940 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 941 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 942 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 943 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 944 "data/maps/RustboroCity/scripts.pory"

# 945 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger2::
# 946 "data/maps/RustboroCity/scripts.pory"
	lockall
# 947 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 948 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 949 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 950 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 951 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 952 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 953 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 954 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 955 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
# 956 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 957 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 958 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 959 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 960 "data/maps/RustboroCity/scripts.pory"

# 961 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger3::
# 962 "data/maps/RustboroCity/scripts.pory"
	lockall
# 963 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 964 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 965 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 966 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 967 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 968 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 969 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 970 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 971 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
# 972 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 973 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 974 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 975 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 976 "data/maps/RustboroCity/scripts.pory"

# 977 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger4::
# 978 "data/maps/RustboroCity/scripts.pory"
	lockall
# 979 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 980 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 981 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 982 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 983 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 984 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 985 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 986 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 987 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
# 988 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 989 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 990 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 991 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 992 "data/maps/RustboroCity/scripts.pory"

# 993 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger5::
# 994 "data/maps/RustboroCity/scripts.pory"
	lockall
# 995 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 996 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 997 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 998 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 999 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1000 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1001 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1002 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1003 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
# 1004 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1005 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1006 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1007 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1008 "data/maps/RustboroCity/scripts.pory"

# 1009 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger6::
# 1010 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1011 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1012 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1013 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1014 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1015 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1016 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1017 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1018 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1019 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
# 1020 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1021 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1022 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1023 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1024 "data/maps/RustboroCity/scripts.pory"

# 1025 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalTrigger7::
# 1026 "data/maps/RustboroCity/scripts.pory"
	lockall
# 1027 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 1028 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 1029 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1030 "data/maps/RustboroCity/scripts.pory"
	playse SE_PIN
# 1031 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 1032 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1033 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 1034 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1035 "data/maps/RustboroCity/scripts.pory"
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
# 1036 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1037 "data/maps/RustboroCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1038 "data/maps/RustboroCity/scripts.pory"
	waitmovement 0
# 1039 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_RivalEncounter
# 1040 "data/maps/RustboroCity/scripts.pory"

# 1041 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RivalEncounter::
# 1042 "data/maps/RustboroCity/scripts.pory"
	checkplayergender
# 1043 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
# 1044 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
# 1045 "data/maps/RustboroCity/scripts.pory"
	end
# 1046 "data/maps/RustboroCity/scripts.pory"

# 1047 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayEncounter::
# 1048 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
# 1049 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
# 1050 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1051 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
# 1052 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1053 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1054 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1055 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
# 1056 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1057 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1058 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1059 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1060 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1061 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1062 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 0
# 1063 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
# 1064 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1065 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1066 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1067 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1068 "data/maps/RustboroCity/scripts.pory"
	end
# 1069 "data/maps/RustboroCity/scripts.pory"

# 1070 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayAskToBattle::
# 1071 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_0x8008, 1
# 1072 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
# 1073 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
# 1074 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
# 1075 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1076 "data/maps/RustboroCity/scripts.pory"
	end
# 1077 "data/maps/RustboroCity/scripts.pory"

# 1078 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMay::
# 1079 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
# 1080 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1081 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleMayTreecko
# 1082 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleMayTorchic
# 1083 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleMayMudkip
# 1084 "data/maps/RustboroCity/scripts.pory"
	end
# 1085 "data/maps/RustboroCity/scripts.pory"

# 1086 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_MayBrineyHint::
# 1087 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
# 1088 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1089 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1090 "data/maps/RustboroCity/scripts.pory"
	end
# 1091 "data/maps/RustboroCity/scripts.pory"

# 1092 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_RestoreBgm::
# 1093 "data/maps/RustboroCity/scripts.pory"
	savebgm MUS_DUMMY
# 1094 "data/maps/RustboroCity/scripts.pory"
	fadedefaultbgm
# 1095 "data/maps/RustboroCity/scripts.pory"
	return
# 1096 "data/maps/RustboroCity/scripts.pory"

# 1097 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTreecko::
# 1098 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
# 1099 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1100 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1101 "data/maps/RustboroCity/scripts.pory"
	end
# 1102 "data/maps/RustboroCity/scripts.pory"

# 1103 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayTorchic::
# 1104 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
# 1105 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1106 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1107 "data/maps/RustboroCity/scripts.pory"
	end
# 1108 "data/maps/RustboroCity/scripts.pory"

# 1109 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleMayMudkip::
# 1110 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
# 1111 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1112 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_MayBrineyHint
# 1113 "data/maps/RustboroCity/scripts.pory"
	end
# 1114 "data/maps/RustboroCity/scripts.pory"

# 1115 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanEncounter::
# 1116 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
# 1117 "data/maps/RustboroCity/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
# 1118 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_MET_RIVAL_RUSTBORO
# 1119 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
# 1120 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1121 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1122 "data/maps/RustboroCity/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 1123 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 1124 "data/maps/RustboroCity/scripts.pory"
	waitfanfare
# 1125 "data/maps/RustboroCity/scripts.pory"
	closemessage
# 1126 "data/maps/RustboroCity/scripts.pory"
	delay 30
# 1127 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 1128 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 1129 "data/maps/RustboroCity/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 1130 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
# 1131 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1132 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1133 "data/maps/RustboroCity/scripts.pory"
	call RustboroCity_EventScript_RestoreBgm
# 1134 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1135 "data/maps/RustboroCity/scripts.pory"
	end
# 1136 "data/maps/RustboroCity/scripts.pory"

# 1137 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanAskToBattle::
# 1138 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
# 1139 "data/maps/RustboroCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
# 1140 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
# 1141 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1142 "data/maps/RustboroCity/scripts.pory"
	end
# 1143 "data/maps/RustboroCity/scripts.pory"

# 1144 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendan::
# 1145 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
# 1146 "data/maps/RustboroCity/scripts.pory"
	switch VAR_STARTER_MON
# 1147 "data/maps/RustboroCity/scripts.pory"
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
# 1148 "data/maps/RustboroCity/scripts.pory"
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
# 1149 "data/maps/RustboroCity/scripts.pory"
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
# 1150 "data/maps/RustboroCity/scripts.pory"
	end
# 1151 "data/maps/RustboroCity/scripts.pory"

# 1152 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BrendanBrineyHint::
# 1153 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
# 1154 "data/maps/RustboroCity/scripts.pory"
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_RestoreBgm
# 1155 "data/maps/RustboroCity/scripts.pory"
	releaseall
# 1156 "data/maps/RustboroCity/scripts.pory"
	end
# 1157 "data/maps/RustboroCity/scripts.pory"

# 1158 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTreecko::
# 1159 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
# 1160 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1161 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1162 "data/maps/RustboroCity/scripts.pory"
	end
# 1163 "data/maps/RustboroCity/scripts.pory"

# 1164 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanTorchic::
# 1165 "data/maps/RustboroCity/scripts.pory"
	@trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
# 1166 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1167 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1168 "data/maps/RustboroCity/scripts.pory"
	end
# 1169 "data/maps/RustboroCity/scripts.pory"

# 1170 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_BattleBrendanMudkip::
# 1171 "data/maps/RustboroCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
# 1172 "data/maps/RustboroCity/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
# 1173 "data/maps/RustboroCity/scripts.pory"
	goto RustboroCity_EventScript_BrendanBrineyHint
# 1174 "data/maps/RustboroCity/scripts.pory"
	end
# 1175 "data/maps/RustboroCity/scripts.pory"

# 1176 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer0:
# 1177 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1178 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1179 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1180 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1181 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1182 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1183 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1184 "data/maps/RustboroCity/scripts.pory"

# 1185 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer1:
# 1186 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1187 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1188 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1189 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1190 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1191 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1192 "data/maps/RustboroCity/scripts.pory"

# 1193 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer2:
# 1194 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1195 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1196 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1197 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1198 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1199 "data/maps/RustboroCity/scripts.pory"

# 1200 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer3:
# 1201 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1202 "data/maps/RustboroCity/scripts.pory"
	walk_left
# 1203 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1204 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1205 "data/maps/RustboroCity/scripts.pory"

# 1206 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer4:
# 1207 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1208 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1209 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1210 "data/maps/RustboroCity/scripts.pory"

# 1211 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer5:
# 1212 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1213 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1214 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1215 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1216 "data/maps/RustboroCity/scripts.pory"

# 1217 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer6:
# 1218 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1219 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1220 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1221 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1222 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1223 "data/maps/RustboroCity/scripts.pory"

# 1224 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Movement_RivalApproachPlayer7:
# 1225 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1226 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1227 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1228 "data/maps/RustboroCity/scripts.pory"
	walk_right
# 1229 "data/maps/RustboroCity/scripts.pory"
	walk_down
# 1230 "data/maps/RustboroCity/scripts.pory"
	step_end
# 1231 "data/maps/RustboroCity/scripts.pory"

# 1232 "data/maps/RustboroCity/scripts.pory"
RustboroCity_EventScript_Boy1::
# 1233 "data/maps/RustboroCity/scripts.pory"
	msgbox RustboroCity_Text_YouCanHave2On2Battle, MSGBOX_NPC
# 1234 "data/maps/RustboroCity/scripts.pory"
	end
# 1235 "data/maps/RustboroCity/scripts.pory"

# 1236 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WeShortenItToDevon:
# 1237 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON CORPORATION…\n"
# 1238 "data/maps/RustboroCity/scripts.pory"
	.string "We all just shorten it to DEVON.\p"
# 1239 "data/maps/RustboroCity/scripts.pory"
	.string "That company makes all sorts of\n"
# 1240 "data/maps/RustboroCity/scripts.pory"
	.string "convenient products.$"
# 1241 "data/maps/RustboroCity/scripts.pory"

# 1242 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_SneakyLookingManWentAroundCorner:
# 1243 "data/maps/RustboroCity/scripts.pory"
	.string "Hm? A sneaky-looking man?\p"
# 1244 "data/maps/RustboroCity/scripts.pory"
	.string "Come to think of it, yes, a shady-\n"
# 1245 "data/maps/RustboroCity/scripts.pory"
	.string "looking guy went around the corner.$"
# 1246 "data/maps/RustboroCity/scripts.pory"

# 1247 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HaveYouChallengedGym:
# 1248 "data/maps/RustboroCity/scripts.pory"
	.string "Have you taken the POKéMON GYM\n"
# 1249 "data/maps/RustboroCity/scripts.pory"
	.string "challenge?\p"
# 1250 "data/maps/RustboroCity/scripts.pory"
	.string "When you get that shiny GYM BADGE\n"
# 1251 "data/maps/RustboroCity/scripts.pory"
	.string "in hand, I guess TRAINERS begin to\l"
# 1252 "data/maps/RustboroCity/scripts.pory"
	.string "realize what is required of them.$"
# 1253 "data/maps/RustboroCity/scripts.pory"

# 1254 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HeyThatsRustborosGymBadge:
# 1255 "data/maps/RustboroCity/scripts.pory"
	.string "Hey, that's RUSTBORO's GYM BADGE!\p"
# 1256 "data/maps/RustboroCity/scripts.pory"
	.string "Out of all the POKéMON GYM BADGES,\n"
# 1257 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO's is the coolest, I'd say.$"
# 1258 "data/maps/RustboroCity/scripts.pory"

# 1259 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureNewAroundHere:
# 1260 "data/maps/RustboroCity/scripts.pory"
	.string "Oh? Who might you be?\n"
# 1261 "data/maps/RustboroCity/scripts.pory"
	.string "You're a new face around these parts.\p"
# 1262 "data/maps/RustboroCity/scripts.pory"
	.string "Have you just transferred into the\n"
# 1263 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL?$"
# 1264 "data/maps/RustboroCity/scripts.pory"

# 1265 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymLeaderIsntEasyWithFire:
# 1266 "data/maps/RustboroCity/scripts.pory"
	.string "I challenged the GYM LEADER, but…\p"
# 1267 "data/maps/RustboroCity/scripts.pory"
	.string "It's not going to be easy winning with\n"
# 1268 "data/maps/RustboroCity/scripts.pory"
	.string "my FIRE-type POKéMON…\p"
# 1269 "data/maps/RustboroCity/scripts.pory"
	.string "FIRE-type POKéMON don't match up\n"
# 1270 "data/maps/RustboroCity/scripts.pory"
	.string "well against ROCK-type POKéMON…$"
# 1271 "data/maps/RustboroCity/scripts.pory"

# 1272 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyWalksInTheTunnel:
# 1273 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1274 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1275 "data/maps/RustboroCity/scripts.pory"
	.string "He goes for walks in the tunnel every\n"
# 1276 "data/maps/RustboroCity/scripts.pory"
	.string "so often.$"
# 1277 "data/maps/RustboroCity/scripts.pory"

# 1278 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MrBrineyLovesPeeko:
# 1279 "data/maps/RustboroCity/scripts.pory"
	.string "The old sailor MR. BRINEY lives in\n"
# 1280 "data/maps/RustboroCity/scripts.pory"
	.string "a cottage by the sea.\p"
# 1281 "data/maps/RustboroCity/scripts.pory"
	.string "He said he was going shopping in\n"
# 1282 "data/maps/RustboroCity/scripts.pory"
	.string "SLATEPORT for his pet, PEEKO.\p"
# 1283 "data/maps/RustboroCity/scripts.pory"
	.string "That old sea dog, he must really love\n"
# 1284 "data/maps/RustboroCity/scripts.pory"
	.string "that PEEKO.$"
# 1285 "data/maps/RustboroCity/scripts.pory"

# 1286 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WowYouHavePokemon:
# 1287 "data/maps/RustboroCity/scripts.pory"
	.string "Wow, you have POKéMON with you, too.\p"
# 1288 "data/maps/RustboroCity/scripts.pory"
	.string "When I get bigger, I'm going to go\n"
# 1289 "data/maps/RustboroCity/scripts.pory"
	.string "places with POKéMON, too.$"
# 1290 "data/maps/RustboroCity/scripts.pory"

# 1291 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CatchRarePokemonIfIGoToSchool:
# 1292 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL!\p"
# 1293 "data/maps/RustboroCity/scripts.pory"
	.string "If I go to this school, will I be able\n"
# 1294 "data/maps/RustboroCity/scripts.pory"
	.string "to catch rare POKéMON easily?$"
# 1295 "data/maps/RustboroCity/scripts.pory"

# 1296 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonCanChangeLookFromExp:
# 1297 "data/maps/RustboroCity/scripts.pory"
	.string "If a POKéMON gains experience in\n"
# 1298 "data/maps/RustboroCity/scripts.pory"
	.string "battles, it can sometimes change in\l"
# 1299 "data/maps/RustboroCity/scripts.pory"
	.string "the way it looks.$"
# 1300 "data/maps/RustboroCity/scripts.pory"

# 1301 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PokemonChangeShape:
# 1302 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON changes shape?\n"
# 1303 "data/maps/RustboroCity/scripts.pory"
	.string "If one did that, I would be shocked!$"
# 1304 "data/maps/RustboroCity/scripts.pory"

# 1305 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TradePokemonGrowFast:
# 1306 "data/maps/RustboroCity/scripts.pory"
	.string "A POKéMON you get in a trade from\n"
# 1307 "data/maps/RustboroCity/scripts.pory"
	.string "someone grows fast.\p"
# 1308 "data/maps/RustboroCity/scripts.pory"
	.string "But if you don't have certain GYM\n"
# 1309 "data/maps/RustboroCity/scripts.pory"
	.string "BADGES, it may not obey you…$"
# 1310 "data/maps/RustboroCity/scripts.pory"

# 1311 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_OutOfTheWay:
# 1312 "data/maps/RustboroCity/scripts.pory"
	.string "Get out!\n"
# 1313 "data/maps/RustboroCity/scripts.pory"
	.string "Out of the way!$"
# 1314 "data/maps/RustboroCity/scripts.pory"

# 1315 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_WaitDontTakeMyGoods:
# 1316 "data/maps/RustboroCity/scripts.pory"
	.string "Wait! Pleeeaaase!\p"
# 1317 "data/maps/RustboroCity/scripts.pory"
	.string "Don't take my GOODS!$"
# 1318 "data/maps/RustboroCity/scripts.pory"

# 1319 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_HelpMeIWasRobbed:
# 1320 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, it's you!\p"
# 1321 "data/maps/RustboroCity/scripts.pory"
	.string "You're one of those fantastic\n"
# 1322 "data/maps/RustboroCity/scripts.pory"
	.string "TRAINERS who helped me in\l"
# 1323 "data/maps/RustboroCity/scripts.pory"
	.string "PETALBURG WOODS!\p"
# 1324 "data/maps/RustboroCity/scripts.pory"
	.string "Help me! I was robbed by TEAM AQUA!\n"
# 1325 "data/maps/RustboroCity/scripts.pory"
	.string "I have to get the DEVON GOODS back!\p"
# 1326 "data/maps/RustboroCity/scripts.pory"
	.string "If I don't…\n"
# 1327 "data/maps/RustboroCity/scripts.pory"
	.string "I'm going to be in serious trouble.$"
# 1328 "data/maps/RustboroCity/scripts.pory"

# 1329 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel:
# 1330 "data/maps/RustboroCity/scripts.pory"
	.string "That shady character, I think he took\n"
# 1331 "data/maps/RustboroCity/scripts.pory"
	.string "off towards the tunnel over there.$"
# 1332 "data/maps/RustboroCity/scripts.pory"

# 1333 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouGotItThankYou:
# 1334 "data/maps/RustboroCity/scripts.pory"
	.string "Oh! How did it go?\n"
# 1335 "data/maps/RustboroCity/scripts.pory"
	.string "The DEVON GOODS?\p"
# 1336 "data/maps/RustboroCity/scripts.pory"
	.string "You did!\n"
# 1337 "data/maps/RustboroCity/scripts.pory"
	.string "You got them back!\p"
# 1338 "data/maps/RustboroCity/scripts.pory"
	.string "You really are a great TRAINER!\p"
# 1339 "data/maps/RustboroCity/scripts.pory"
	.string "I know! As my thanks, I'll give you\n"
# 1340 "data/maps/RustboroCity/scripts.pory"
	.string "another GREAT BALL!$"
# 1341 "data/maps/RustboroCity/scripts.pory"

# 1342 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YoureLoadedWithItems:
# 1343 "data/maps/RustboroCity/scripts.pory"
	.string "You're loaded with items.\n"
# 1344 "data/maps/RustboroCity/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 1345 "data/maps/RustboroCity/scripts.pory"

# 1346 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseComeWithMe:
# 1347 "data/maps/RustboroCity/scripts.pory"
	.string "Excuse me, please!\n"
# 1348 "data/maps/RustboroCity/scripts.pory"
	.string "Please come with me!$"
# 1349 "data/maps/RustboroCity/scripts.pory"

# 1350 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayHiLetsRegister:
# 1351 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1352 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1353 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV!\p"
# 1354 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1355 "data/maps/RustboroCity/scripts.pory"
	.string "contact one another anytime!\p"
# 1356 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1357 "data/maps/RustboroCity/scripts.pory"

# 1358 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredMay:
# 1359 "data/maps/RustboroCity/scripts.pory"
	.string "Registered MAY\n"
# 1360 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1361 "data/maps/RustboroCity/scripts.pory"

# 1362 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayPassedBrineyWantToBattle:
# 1363 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, I passed\n"
# 1364 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
# 1365 "data/maps/RustboroCity/scripts.pory"
	.string "I guess he's on his way home to his\n"
# 1366 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1367 "data/maps/RustboroCity/scripts.pory"
	.string "How's your POKéDEX coming along,\n"
# 1368 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
# 1369 "data/maps/RustboroCity/scripts.pory"
	.string "So…\n"
# 1370 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle?$"
# 1371 "data/maps/RustboroCity/scripts.pory"

# 1372 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayOhHaventRaisedPokemonEnough:
# 1373 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1374 "data/maps/RustboroCity/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1375 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON very much?\p"
# 1376 "data/maps/RustboroCity/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1377 "data/maps/RustboroCity/scripts.pory"

# 1378 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayWantToBattle:
# 1379 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1380 "data/maps/RustboroCity/scripts.pory"
	.string "How about a little battle here?$"
# 1381 "data/maps/RustboroCity/scripts.pory"

# 1382 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayImNotGoingToLose:
# 1383 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1384 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1385 "data/maps/RustboroCity/scripts.pory"

# 1386 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayDefeat:
# 1387 "data/maps/RustboroCity/scripts.pory"
	.string "Yikes!\n"
# 1388 "data/maps/RustboroCity/scripts.pory"
	.string "You're better than I expected!$"
# 1389 "data/maps/RustboroCity/scripts.pory"

# 1390 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_MayMrBrineyHint:
# 1391 "data/maps/RustboroCity/scripts.pory"
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
# 1392 "data/maps/RustboroCity/scripts.pory"
	.string "I just passed…\p"
# 1393 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
# 1394 "data/maps/RustboroCity/scripts.pory"
	.string "might not know this, but MR. BRINEY\l"
# 1395 "data/maps/RustboroCity/scripts.pory"
	.string "was once a revered seafarer.$"
# 1396 "data/maps/RustboroCity/scripts.pory"

# 1397 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanHiLetsRegister:
# 1398 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1399 "data/maps/RustboroCity/scripts.pory"
	.string "You had a MATCH CALL feature put\n"
# 1400 "data/maps/RustboroCity/scripts.pory"
	.string "on your POKéNAV! Cool!\p"
# 1401 "data/maps/RustboroCity/scripts.pory"
	.string "Let's register each other so we can\n"
# 1402 "data/maps/RustboroCity/scripts.pory"
	.string "get in touch anytime!\p"
# 1403 "data/maps/RustboroCity/scripts.pory"
	.string "… … … … … …$"
# 1404 "data/maps/RustboroCity/scripts.pory"

# 1405 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_RegisteredBrendan:
# 1406 "data/maps/RustboroCity/scripts.pory"
	.string "Registered BRENDAN\n"
# 1407 "data/maps/RustboroCity/scripts.pory"
	.string "in the POKéNAV.$"
# 1408 "data/maps/RustboroCity/scripts.pory"

# 1409 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanPassedBrineyWantToBattle:
# 1410 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
# 1411 "data/maps/RustboroCity/scripts.pory"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
# 1412 "data/maps/RustboroCity/scripts.pory"
	.string "I bet he was on his way home to his\n"
# 1413 "data/maps/RustboroCity/scripts.pory"
	.string "cottage by the sea.\p"
# 1414 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, how's your POKéDEX?\n"
# 1415 "data/maps/RustboroCity/scripts.pory"
	.string "Have you filled in any pages yet?\p"
# 1416 "data/maps/RustboroCity/scripts.pory"
	.string "Mine rules.\p"
# 1417 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle to test how\n"
# 1418 "data/maps/RustboroCity/scripts.pory"
	.string "far you've progressed?$"
# 1419 "data/maps/RustboroCity/scripts.pory"

# 1420 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanNoConfidenceInPokemon:
# 1421 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1422 "data/maps/RustboroCity/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1423 "data/maps/RustboroCity/scripts.pory"

# 1424 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanWantToBattle:
# 1425 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1426 "data/maps/RustboroCity/scripts.pory"
	.string "Want to have a battle with me?$"
# 1427 "data/maps/RustboroCity/scripts.pory"

# 1428 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanIWontGoEasy:
# 1429 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1430 "data/maps/RustboroCity/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1431 "data/maps/RustboroCity/scripts.pory"

# 1432 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanDefeat:
# 1433 "data/maps/RustboroCity/scripts.pory"
	.string "Hmm…\n"
# 1434 "data/maps/RustboroCity/scripts.pory"
	.string "You're pretty good.$"
# 1435 "data/maps/RustboroCity/scripts.pory"

# 1436 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_BrendanMrBrineyHint:
# 1437 "data/maps/RustboroCity/scripts.pory"
	.string "BRENDAN: By the way, you know\n"
# 1438 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY? The guy I just passed?\p"
# 1439 "data/maps/RustboroCity/scripts.pory"
	.string "I bet you didn't know this, since you\n"
# 1440 "data/maps/RustboroCity/scripts.pory"
	.string "just moved here, {PLAYER}, but\l"
# 1441 "data/maps/RustboroCity/scripts.pory"
	.string "MR. BRINEY was once a great sailor.$"
# 1442 "data/maps/RustboroCity/scripts.pory"

# 1443 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TunnelNearingCompletion:
# 1444 "data/maps/RustboroCity/scripts.pory"
	.string "“Timesaving tunnel nearing\n"
# 1445 "data/maps/RustboroCity/scripts.pory"
	.string "completion!”\p"
# 1446 "data/maps/RustboroCity/scripts.pory"
	.string "…Is what it says on the sign, but\n"
# 1447 "data/maps/RustboroCity/scripts.pory"
	.string "there's also a big “X” splashed\l"
# 1448 "data/maps/RustboroCity/scripts.pory"
	.string "across it in red paint…$"
# 1449 "data/maps/RustboroCity/scripts.pory"

# 1450 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpSign:
# 1451 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORPORATION\p"
# 1452 "data/maps/RustboroCity/scripts.pory"
	.string "“For all your living needs, we make\n"
# 1453 "data/maps/RustboroCity/scripts.pory"
	.string "it all.”$"
# 1454 "data/maps/RustboroCity/scripts.pory"

# 1455 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_GymSign:
# 1456 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY POKéMON GYM\n"
# 1457 "data/maps/RustboroCity/scripts.pory"
	.string "LEADER: ROXANNE\p"
# 1458 "data/maps/RustboroCity/scripts.pory"
	.string "“The ROCK-loving honors student!”$"
# 1459 "data/maps/RustboroCity/scripts.pory"

# 1460 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevonCorpBranchOfficeSign:
# 1461 "data/maps/RustboroCity/scripts.pory"
	.string "DEVON CORP. BRANCH OFFICE\p"
# 1462 "data/maps/RustboroCity/scripts.pory"
	.string "“Access limited to DEVON employees\n"
# 1463 "data/maps/RustboroCity/scripts.pory"
	.string "and authorized personnel.”$"
# 1464 "data/maps/RustboroCity/scripts.pory"

# 1465 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CitySign:
# 1466 "data/maps/RustboroCity/scripts.pory"
	.string "RUSTBORO CITY\p"
# 1467 "data/maps/RustboroCity/scripts.pory"
	.string "“The city probing the integration of\n"
# 1468 "data/maps/RustboroCity/scripts.pory"
	.string "nature and science.”$"
# 1469 "data/maps/RustboroCity/scripts.pory"

# 1470 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_TrainersSchoolSign:
# 1471 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON TRAINER'S SCHOOL\p"
# 1472 "data/maps/RustboroCity/scripts.pory"
	.string "“We'll teach you anything about\n"
# 1473 "data/maps/RustboroCity/scripts.pory"
	.string "POKéMON!”$"
# 1474 "data/maps/RustboroCity/scripts.pory"

# 1475 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_CuttersHouse:
# 1476 "data/maps/RustboroCity/scripts.pory"
	.string "CUTTER'S HOUSE$"
# 1477 "data/maps/RustboroCity/scripts.pory"

# 1478 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_DevelopedNewPokenavFeature:
# 1479 "data/maps/RustboroCity/scripts.pory"
	.string "I've been developing an added feature\n"
# 1480 "data/maps/RustboroCity/scripts.pory"
	.string "for the POKéNAV…\p"
# 1481 "data/maps/RustboroCity/scripts.pory"
	.string "And it turned out great!\p"
# 1482 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, may I see that POKéNAV?\n"
# 1483 "data/maps/RustboroCity/scripts.pory"
	.string "The one our PRESIDENT gave you?$"
# 1484 "data/maps/RustboroCity/scripts.pory"

# 1485 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_AddedMatchCallPleaseCallMrStone:
# 1486 "data/maps/RustboroCity/scripts.pory"
	.string "There you go, {PLAYER}!\p"
# 1487 "data/maps/RustboroCity/scripts.pory"
	.string "I added a new feature named\n"
# 1488 "data/maps/RustboroCity/scripts.pory"
	.string "MATCH CALL to your POKéNAV.\p"
# 1489 "data/maps/RustboroCity/scripts.pory"
	.string "Using the MATCH CALL feature,\n"
# 1490 "data/maps/RustboroCity/scripts.pory"
	.string "you can chat with people who have\l"
# 1491 "data/maps/RustboroCity/scripts.pory"
	.string "been registered in your POKéNAV.\p"
# 1492 "data/maps/RustboroCity/scripts.pory"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
# 1493 "data/maps/RustboroCity/scripts.pory"
	.string "be registered in your POKéNAV.\p"
# 1494 "data/maps/RustboroCity/scripts.pory"
	.string "Test it out.\n"
# 1495 "data/maps/RustboroCity/scripts.pory"
	.string "Please give our PRESIDENT a call.$"
# 1496 "data/maps/RustboroCity/scripts.pory"

# 1497 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_PleaseSelectPokenav:
# 1498 "data/maps/RustboroCity/scripts.pory"
	.string "Please select the POKéNAV.$"
# 1499 "data/maps/RustboroCity/scripts.pory"

# 1500 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_IdBetterGetBackToWork:
# 1501 "data/maps/RustboroCity/scripts.pory"
	.string "Okay, I'd better get back to work.\n"
# 1502 "data/maps/RustboroCity/scripts.pory"
	.string "Please take care, {PLAYER}!$"
# 1503 "data/maps/RustboroCity/scripts.pory"

# 1504 "data/maps/RustboroCity/scripts.pory"
RustboroCity_Text_YouCanHave2On2Battle:
# 1505 "data/maps/RustboroCity/scripts.pory"
	.string "Did you know this?\p"
# 1506 "data/maps/RustboroCity/scripts.pory"
	.string "You can have a 2-on-2 battle even\n"
# 1507 "data/maps/RustboroCity/scripts.pory"
	.string "if you're not with another TRAINER.\p"
# 1508 "data/maps/RustboroCity/scripts.pory"
	.string "If you catch the eyes of two TRAINERS\n"
# 1509 "data/maps/RustboroCity/scripts.pory"
	.string "when you have two or more POKéMON,\l"
# 1510 "data/maps/RustboroCity/scripts.pory"
	.string "they'll both challenge you.\p"
# 1511 "data/maps/RustboroCity/scripts.pory"
	.string "Don't you think it'd be cool if you\n"
# 1512 "data/maps/RustboroCity/scripts.pory"
	.string "could beat two TRAINERS by yourself?$"

RustboroCity_Text_YoPlayer::
# 756 "data/maps/RustboroCity/scripts.pory"
	.string "Yo! {PLAYER}!$"

RustboroCity_Text_WhatsGoingOn::
# 760 "data/maps/RustboroCity/scripts.pory"
	.string "I heard there was a commotion going on\n"
	.string "here. What's going on?$"

RustboroCity_Text_GuyGotMugged::
# 765 "data/maps/RustboroCity/scripts.pory"
	.string "So this guy got mugged? That's\n"
	.string "absolutely despicable!$"

RustboroCity_Text_DontWorrySir::
# 769 "data/maps/RustboroCity/scripts.pory"
	.string "Don't worry, sir. {PLAYER} and I will\n"
	.string "get your GOODS back.$"

RustboroCity_Text_ThankBothOfYou::
# 773 "data/maps/RustboroCity/scripts.pory"
	.string "Oh, thank you! Both of you!\n"
	.string "I do hope you can get them back.$"

RustboroCity_Text_LetsGoCatchMugger::
# 778 "data/maps/RustboroCity/scripts.pory"
	.string "C'mon, {PLAYER}!\n"
	.string "Let's go catch that mugger!$"
