# 3 "data/maps/DewfordTown_Hall/scripts.pory"

# 4 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_EXPERT_M, 4
# 5 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_TWIN, 5
# 6 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_SCHOOL_KID_M, 7
# 7 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_PSYCHIC_M, 8
# 8 "data/maps/DewfordTown_Hall/scripts.pory"
.set LOCALID_RIVAL2, 10

DewfordTown_Hall_MapScripts::
# 12 "data/maps/DewfordTown_Hall/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Hall_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

DewfordTown_Hall_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 13 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	return


DewfordTown_Hall_EventScript_Rival2::
# 18 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 19 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement 10, Common_Movement_FacePlayer
# 20 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 21 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 22 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WhatTheHeck, MSGBOX_DEFAULT
# 23 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 24 "data/maps/DewfordTown_Hall/scripts.pory"
	release
	end


# 34 "data/maps/DewfordTown_Hall/scripts.pory"

# 35 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Girl::
# 36 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 37 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 38 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 39 "data/maps/DewfordTown_Hall/scripts.pory"
	special IsTrendyPhraseBoring
# 40 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
# 41 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
# 42 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 43 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 44 "data/maps/DewfordTown_Hall/scripts.pory"

# 45 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_GirlBoredOfTrend::
# 46 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
# 47 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 48 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 49 "data/maps/DewfordTown_Hall/scripts.pory"

# 50 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Woman::
# 51 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 52 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 53 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 54 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
# 55 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 56 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 57 "data/maps/DewfordTown_Hall/scripts.pory"

# 58 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Man::
# 59 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 60 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 61 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 62 "data/maps/DewfordTown_Hall/scripts.pory"
	special BufferDeepLinkPhrase
# 63 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
# 64 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
# 65 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
# 66 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 67 "data/maps/DewfordTown_Hall/scripts.pory"

# 68 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ConfirmTrendLink::
# 69 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
# 70 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 71 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 72 "data/maps/DewfordTown_Hall/scripts.pory"

# 73 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_RejectTrendLink::
# 74 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
# 75 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 76 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 77 "data/maps/DewfordTown_Hall/scripts.pory"

# 78 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ExpertM::
# 79 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 80 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 81 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 82 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
# 83 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 84 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
# 85 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 86 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 87 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 88 "data/maps/DewfordTown_Hall/scripts.pory"

# 89 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Twin::
# 90 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 91 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 92 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 93 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
# 94 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 95 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
# 96 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 97 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 98 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 99 "data/maps/DewfordTown_Hall/scripts.pory"

# 100 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LittleBoy::
# 101 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 102 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 103 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 104 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
# 105 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 106 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 107 "data/maps/DewfordTown_Hall/scripts.pory"

# 108 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Bookshelf::
# 109 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 110 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 111 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
# 112 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 113 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 114 "data/maps/DewfordTown_Hall/scripts.pory"

# 115 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Painting::
# 116 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 117 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 118 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 119 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 120 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
# 121 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
# 122 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_SmileTitle
# 123 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
# 124 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_LastTitle
# 125 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_LastTitle
# 126 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_BirthTitle
# 127 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_LastTitle
# 128 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 129 "data/maps/DewfordTown_Hall/scripts.pory"

# 130 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ScreamTitle::
# 131 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
# 132 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 133 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 134 "data/maps/DewfordTown_Hall/scripts.pory"

# 135 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SmileTitle::
# 136 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
# 137 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 138 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 139 "data/maps/DewfordTown_Hall/scripts.pory"

# 140 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LastTitle::
# 141 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
# 142 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 143 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 144 "data/maps/DewfordTown_Hall/scripts.pory"

# 145 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_BirthTitle::
# 146 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
# 147 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 148 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 149 "data/maps/DewfordTown_Hall/scripts.pory"

# 150 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SchoolKidM::
# 151 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 152 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 0
# 153 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 154 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 155 "data/maps/DewfordTown_Hall/scripts.pory"

# 156 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PsychicM::
# 157 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 158 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 1
# 159 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 160 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 161 "data/maps/DewfordTown_Hall/scripts.pory"

# 162 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DoTrendDebate::
# 163 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 164 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 165 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 166 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
# 167 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
# 168 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
# 169 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
# 170 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
# 171 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
# 172 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
# 173 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
# 174 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 175 "data/maps/DewfordTown_Hall/scripts.pory"

# 176 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate1::
# 177 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 178 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
# 179 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 180 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
# 181 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 182 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 183 "data/maps/DewfordTown_Hall/scripts.pory"

# 184 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate2::
# 185 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 186 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
# 187 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 188 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
# 189 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 190 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 191 "data/maps/DewfordTown_Hall/scripts.pory"

# 192 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate3::
# 193 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 194 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
# 195 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 196 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
# 197 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 198 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 199 "data/maps/DewfordTown_Hall/scripts.pory"

# 200 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate4::
# 201 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 202 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
# 203 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 204 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
# 205 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 206 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 207 "data/maps/DewfordTown_Hall/scripts.pory"

# 208 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate5::
# 209 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 210 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
# 211 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 212 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
# 213 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 214 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 215 "data/maps/DewfordTown_Hall/scripts.pory"

# 216 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer1::
# 217 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 218 "data/maps/DewfordTown_Hall/scripts.pory"

# 219 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact1::
# 220 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
# 221 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 222 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
# 223 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
# 224 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 225 "data/maps/DewfordTown_Hall/scripts.pory"

# 226 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactWest::
# 227 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 228 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 229 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 230 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 231 "data/maps/DewfordTown_Hall/scripts.pory"

# 232 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer2::
# 233 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 234 "data/maps/DewfordTown_Hall/scripts.pory"

# 235 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact2::
# 236 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
# 237 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 238 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
# 239 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
# 240 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 241 "data/maps/DewfordTown_Hall/scripts.pory"

# 242 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
# 243 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
# 244 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
# 245 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 246 "data/maps/DewfordTown_Hall/scripts.pory"

# 247 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
# 248 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 249 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 250 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 251 "data/maps/DewfordTown_Hall/scripts.pory"

# 252 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
# 253 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 254 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 255 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 256 "data/maps/DewfordTown_Hall/scripts.pory"

# 257 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactEast::
# 258 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 259 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 260 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 261 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 262 "data/maps/DewfordTown_Hall/scripts.pory"

# 263 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
# 264 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_left
# 265 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 266 "data/maps/DewfordTown_Hall/scripts.pory"

# 267 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
# 268 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_right
# 269 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 270 "data/maps/DewfordTown_Hall/scripts.pory"

# 271 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SludgeBombMan::
# 272 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 273 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 274 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 275 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
# 276 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
# 277 "data/maps/DewfordTown_Hall/scripts.pory"
	giveitem ITEM_TM_SLUDGE_BOMB
# 278 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 279 "data/maps/DewfordTown_Hall/scripts.pory"
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
# 280 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 281 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 282 "data/maps/DewfordTown_Hall/scripts.pory"

# 283 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
# 284 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
# 285 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 286 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 287 "data/maps/DewfordTown_Hall/scripts.pory"

# 288 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
# 289 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 290 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 291 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I can't imagine what life would be like\n"
# 292 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "without “{STR_VAR_1}”!$"
# 293 "data/maps/DewfordTown_Hall/scripts.pory"

# 294 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GettingBoredOfTrend:
# 295 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 296 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 297 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But I'm getting kind of bored with it.\p"
# 298 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I should look for the next big thing.$"
# 299 "data/maps/DewfordTown_Hall/scripts.pory"

# 300 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TeachingMonAboutTrend:
# 301 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm teaching my POKéMON about\n"
# 302 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1},”\l"
# 303 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "but it's not going well.\p"
# 304 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's a bit too much, I think.$"
# 305 "data/maps/DewfordTown_Hall/scripts.pory"

# 306 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
# 307 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm studying up on the hip and trendy\n"
# 308 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” now.\p"
# 309 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is it true that there's a deep link\n"
# 310 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "between “{STR_VAR_1}”\l"
# 311 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "and “{STR_VAR_2}”?$"
# 312 "data/maps/DewfordTown_Hall/scripts.pory"

# 313 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_MyHunchWasRight:
# 314 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 315 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "So, my hunch was right!\p"
# 316 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm one step closer to being hip and\n"
# 317 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "happening, yowza!$"
# 318 "data/maps/DewfordTown_Hall/scripts.pory"

# 319 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_NotEasyToKeepUp:
# 320 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What?!\n"
# 321 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is that so?!\p"
# 322 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's not easy for an older fellow like\n"
# 323 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "me to keep up with trends!$"
# 324 "data/maps/DewfordTown_Hall/scripts.pory"

# 325 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TVShowAboutTrend:
# 326 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "This whole business about\n"
# 327 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\l"
# 328 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't there a TV show on it?$"
# 329 "data/maps/DewfordTown_Hall/scripts.pory"

# 330 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
# 331 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Across the sea…\p"
# 332 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is “{STR_VAR_1}”\n"
# 333 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "even more popular?$"
# 334 "data/maps/DewfordTown_Hall/scripts.pory"

# 335 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CollectTrendMerchandise:
# 336 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I collect official\n"
# 337 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 338 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "licensed merchandise.\p"
# 339 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I have official\n"
# 340 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DOLLS…\p"
# 341 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Official “{STR_VAR_1}”\n"
# 342 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "brand clothing…\p"
# 343 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "And officially licensed\n"
# 344 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 345 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "picture books.\p"
# 346 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Heheh, I own!\n"
# 347 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm not sharing anything with you!$"
# 348 "data/maps/DewfordTown_Hall/scripts.pory"

# 349 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BooksAboutTrend:
# 350 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "IDENTIFYING GOOD\n"
# 351 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” &\l"
# 352 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "BAD “{STR_VAR_1}”…\p"
# 353 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "THE LINK BETWEEN\n"
# 354 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” AND\l"
# 355 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "POKéMON…\p"
# 356 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "USEFUL\n"
# 357 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\p"
# 358 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's neatly jammed with books about\n"
# 359 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 360 "data/maps/DewfordTown_Hall/scripts.pory"

# 361 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsScream:
# 362 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 363 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "SCREAM” is the title.$"
# 364 "data/maps/DewfordTown_Hall/scripts.pory"

# 365 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsSmile:
# 366 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 367 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "SMILE” is the title.$"
# 368 "data/maps/DewfordTown_Hall/scripts.pory"

# 369 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LastTrend:
# 370 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE LAST\n"
# 371 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 372 "data/maps/DewfordTown_Hall/scripts.pory"

# 373 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BirthOfTrend:
# 374 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE BIRTH OF\n"
# 375 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 376 "data/maps/DewfordTown_Hall/scripts.pory"

# 377 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_SawTrendCoolestThing:
# 378 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I saw “{STR_VAR_1}”!\n"
# 379 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Cool, huh?\p"
# 380 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's, like, the coolest thing going!\p"
# 381 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was awesome!\n"
# 382 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was the real thing, oh yeah!$"
# 383 "data/maps/DewfordTown_Hall/scripts.pory"

# 384 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
# 385 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, no, no, no.\p"
# 386 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That alleged\n"
# 387 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 388 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you claim to have seen--it's not.\p"
# 389 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "The authentic article is much…\n"
# 390 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "How should I say it?\l"
# 391 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Sharper, yet more mellow!\p"
# 392 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Ah, no matter. It's astonishing!$"
# 393 "data/maps/DewfordTown_Hall/scripts.pory"

# 394 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_ComposedTrendThemeSong:
# 395 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hey, listen, I composed a theme song\n"
# 396 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "for “{STR_VAR_1}.”\p"
# 397 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\n"
# 398 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "is really popular right now.\p"
# 399 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Okay, listen!\n"
# 400 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 401 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 402 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!\p"
# 403 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wonderful\n"
# 404 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!$"
# 405 "data/maps/DewfordTown_Hall/scripts.pory"

# 406 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WorkOnYourSinging:
# 407 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 408 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I dare say, chap, it would pay for you\n"
# 409 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "to work on your singing before you\l"
# 410 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "trifle yourself with\l"
# 411 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 412 "data/maps/DewfordTown_Hall/scripts.pory"

# 413 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_OrganizeTrendParty:
# 414 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Anyway, as I was saying earlier, we\n"
# 415 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "should get together and organize a\l"
# 416 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” party\l"
# 417 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "on the island.$"
# 418 "data/maps/DewfordTown_Hall/scripts.pory"

# 419 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BrilliantIndeed:
# 420 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, a smashing good idea!\p"
# 421 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It will settle once and for all\n"
# 422 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "who is the best at\l"
# 423 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”\l"
# 424 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Brilliant, indeed!\p"
# 425 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Starting today, our lives will revolve\n"
# 426 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "around “{STR_VAR_1}”!$"
# 427 "data/maps/DewfordTown_Hall/scripts.pory"

# 428 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
# 429 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I was thinking, though…\p"
# 430 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wouldn't you agree that\n"
# 431 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” has\l"
# 432 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "grown from being something trendy to\l"
# 433 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "being a part of our daily lives?$"
# 434 "data/maps/DewfordTown_Hall/scripts.pory"

# 435 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
# 436 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Beg pardon?\n"
# 437 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That much, what?\p"
# 438 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "However, it's true that\n"
# 439 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 440 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "weighs heavily on your mind, whether\l"
# 441 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you're awake or asleep.\p"
# 442 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Absolutely, you're the\n"
# 443 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 444 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "PROFESSOR, old sport!$"
# 445 "data/maps/DewfordTown_Hall/scripts.pory"

# 446 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
# 447 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "If you and me team up as a combo,\n"
# 448 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "we'll be invincible when it comes to all\l"
# 449 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "things “{STR_VAR_1}”!$"
# 450 "data/maps/DewfordTown_Hall/scripts.pory"

# 451 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WellBeTrendDuo:
# 452 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Spot on, my friend!\p"
# 453 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "We shall be the\n"
# 454 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DUO!\p"
# 455 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't that a ripe image?\n"
# 456 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hahahah!$"
# 457 "data/maps/DewfordTown_Hall/scripts.pory"

# 458 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GiveYouSludgeBomb:
# 459 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "For me, SLUDGE BOMB is at the peak\n"
# 460 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "of popularity. It's the one.\p"
# 461 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hunh? You're telling me that you don't\n"
# 462 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "know about SLUDGE BOMB?\p"
# 463 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That's outright pitiful.\n"
# 464 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'll give you one.$"
# 465 "data/maps/DewfordTown_Hall/scripts.pory"

# 466 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
# 467 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I love SLUDGE BOMB.\p"
# 468 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But POKéMON with the move\n"
# 469 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 470 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "are in, too.$"

DewfordTown_Hall_Text_WhatTheHeck::
# 28 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm trying to ask these people if\n"
	.string "they've seen STEVEN, but they just\l"
	.string "keep talking about\l"
	.string "“{STR_VAR_1}.”\p"
	.string "What the heck is\n"
	.string "“{STR_VAR_1},” anyway?!$"
