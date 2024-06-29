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
	compare VAR_TEMP_3, 5
	goto_if_ne DewfordTown_Hall_EventScript_Rival2_2
# 26 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WhatTheHeck, MSGBOX_DEFAULT
# 27 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_TEMP_3, 5
DewfordTown_Hall_EventScript_Rival2_1:
# 29 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 30 "data/maps/DewfordTown_Hall/scripts.pory"
	release
	end

DewfordTown_Hall_EventScript_Rival2_2:
# 23 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_StuckInMyHead, MSGBOX_DEFAULT
	goto DewfordTown_Hall_EventScript_Rival2_1


# 47 "data/maps/DewfordTown_Hall/scripts.pory"

# 48 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Girl::
# 49 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 50 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 51 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 52 "data/maps/DewfordTown_Hall/scripts.pory"
	special IsTrendyPhraseBoring
# 53 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
# 54 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
# 55 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 56 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 57 "data/maps/DewfordTown_Hall/scripts.pory"

# 58 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_GirlBoredOfTrend::
# 59 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
# 60 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 61 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 62 "data/maps/DewfordTown_Hall/scripts.pory"

# 63 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Woman::
# 64 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 65 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 66 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 67 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
# 68 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 69 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 70 "data/maps/DewfordTown_Hall/scripts.pory"

# 71 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Man::
# 72 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 73 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 74 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 75 "data/maps/DewfordTown_Hall/scripts.pory"
	special BufferDeepLinkPhrase
# 76 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
# 77 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
# 78 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
# 79 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 80 "data/maps/DewfordTown_Hall/scripts.pory"

# 81 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ConfirmTrendLink::
# 82 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
# 83 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 84 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 85 "data/maps/DewfordTown_Hall/scripts.pory"

# 86 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_RejectTrendLink::
# 87 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
# 88 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 89 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 90 "data/maps/DewfordTown_Hall/scripts.pory"

# 91 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ExpertM::
# 92 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 93 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 94 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 95 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
# 96 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 97 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
# 98 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 99 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 100 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 101 "data/maps/DewfordTown_Hall/scripts.pory"

# 102 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Twin::
# 103 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 104 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 105 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 106 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
# 107 "data/maps/DewfordTown_Hall/scripts.pory"
	closemessage
# 108 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
# 109 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 110 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 111 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 112 "data/maps/DewfordTown_Hall/scripts.pory"

# 113 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LittleBoy::
# 114 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 115 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 116 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 117 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
# 118 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 119 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 120 "data/maps/DewfordTown_Hall/scripts.pory"

# 121 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Bookshelf::
# 122 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 123 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 124 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
# 125 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 126 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 127 "data/maps/DewfordTown_Hall/scripts.pory"

# 128 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_Painting::
# 129 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 130 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 131 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 132 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 133 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
# 134 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
# 135 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_SmileTitle
# 136 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
# 137 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_LastTitle
# 138 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_LastTitle
# 139 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_BirthTitle
# 140 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_LastTitle
# 141 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 142 "data/maps/DewfordTown_Hall/scripts.pory"

# 143 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ScreamTitle::
# 144 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
# 145 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 146 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 147 "data/maps/DewfordTown_Hall/scripts.pory"

# 148 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SmileTitle::
# 149 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
# 150 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 151 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 152 "data/maps/DewfordTown_Hall/scripts.pory"

# 153 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_LastTitle::
# 154 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
# 155 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 156 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 157 "data/maps/DewfordTown_Hall/scripts.pory"

# 158 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_BirthTitle::
# 159 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
# 160 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 161 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 162 "data/maps/DewfordTown_Hall/scripts.pory"

# 163 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SchoolKidM::
# 164 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 165 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 0
# 166 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 167 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 168 "data/maps/DewfordTown_Hall/scripts.pory"

# 169 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PsychicM::
# 170 "data/maps/DewfordTown_Hall/scripts.pory"
	lockall
# 171 "data/maps/DewfordTown_Hall/scripts.pory"
	setvar VAR_0x8008, 1
# 172 "data/maps/DewfordTown_Hall/scripts.pory"
	goto DewfordTown_Hall_EventScript_DoTrendDebate
# 173 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 174 "data/maps/DewfordTown_Hall/scripts.pory"

# 175 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DoTrendDebate::
# 176 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 177 "data/maps/DewfordTown_Hall/scripts.pory"
	special GetDewfordHallPaintingNameIndex
# 178 "data/maps/DewfordTown_Hall/scripts.pory"
	switch VAR_RESULT
# 179 "data/maps/DewfordTown_Hall/scripts.pory"
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
# 180 "data/maps/DewfordTown_Hall/scripts.pory"
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
# 181 "data/maps/DewfordTown_Hall/scripts.pory"
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
# 182 "data/maps/DewfordTown_Hall/scripts.pory"
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
# 183 "data/maps/DewfordTown_Hall/scripts.pory"
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
# 184 "data/maps/DewfordTown_Hall/scripts.pory"
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
# 185 "data/maps/DewfordTown_Hall/scripts.pory"
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
# 186 "data/maps/DewfordTown_Hall/scripts.pory"
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
# 187 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 188 "data/maps/DewfordTown_Hall/scripts.pory"

# 189 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate1::
# 190 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 191 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
# 192 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 193 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
# 194 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 195 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 196 "data/maps/DewfordTown_Hall/scripts.pory"

# 197 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate2::
# 198 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 199 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
# 200 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 201 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
# 202 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 203 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 204 "data/maps/DewfordTown_Hall/scripts.pory"

# 205 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate3::
# 206 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 207 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
# 208 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 209 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
# 210 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 211 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 212 "data/maps/DewfordTown_Hall/scripts.pory"

# 213 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate4::
# 214 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 215 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
# 216 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 217 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
# 218 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 219 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 220 "data/maps/DewfordTown_Hall/scripts.pory"

# 221 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_TrendDebate5::
# 222 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact1
# 223 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
# 224 "data/maps/DewfordTown_Hall/scripts.pory"
	call DewfordTown_Hall_EventScript_DebateReact2
# 225 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
# 226 "data/maps/DewfordTown_Hall/scripts.pory"
	releaseall
# 227 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 228 "data/maps/DewfordTown_Hall/scripts.pory"

# 229 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer1::
# 230 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 231 "data/maps/DewfordTown_Hall/scripts.pory"

# 232 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact1::
# 233 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
# 234 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 235 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
# 236 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
# 237 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 238 "data/maps/DewfordTown_Hall/scripts.pory"

# 239 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactWest::
# 240 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 241 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 242 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 243 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 244 "data/maps/DewfordTown_Hall/scripts.pory"

# 245 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DontMovePlayer2::
# 246 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 247 "data/maps/DewfordTown_Hall/scripts.pory"

# 248 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_DebateReact2::
# 249 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
# 250 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 251 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
# 252 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
# 253 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 254 "data/maps/DewfordTown_Hall/scripts.pory"

# 255 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
# 256 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
# 257 "data/maps/DewfordTown_Hall/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
# 258 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 259 "data/maps/DewfordTown_Hall/scripts.pory"

# 260 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
# 261 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 262 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 263 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 264 "data/maps/DewfordTown_Hall/scripts.pory"

# 265 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
# 266 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 267 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 268 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 269 "data/maps/DewfordTown_Hall/scripts.pory"

# 270 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_PlayerReactEast::
# 271 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
# 272 "data/maps/DewfordTown_Hall/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 273 "data/maps/DewfordTown_Hall/scripts.pory"
	waitmovement 0
# 274 "data/maps/DewfordTown_Hall/scripts.pory"
	return
# 275 "data/maps/DewfordTown_Hall/scripts.pory"

# 276 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
# 277 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_left
# 278 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 279 "data/maps/DewfordTown_Hall/scripts.pory"

# 280 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
# 281 "data/maps/DewfordTown_Hall/scripts.pory"
	walk_in_place_right
# 282 "data/maps/DewfordTown_Hall/scripts.pory"
	step_end
# 283 "data/maps/DewfordTown_Hall/scripts.pory"

# 284 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_SludgeBombMan::
# 285 "data/maps/DewfordTown_Hall/scripts.pory"
	lock
# 286 "data/maps/DewfordTown_Hall/scripts.pory"
	faceplayer
# 287 "data/maps/DewfordTown_Hall/scripts.pory"
	call Common_EventScript_BufferTrendyPhrase
# 288 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
# 289 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
# 290 "data/maps/DewfordTown_Hall/scripts.pory"
	giveitem ITEM_TM_SLUDGE_BOMB
# 291 "data/maps/DewfordTown_Hall/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 292 "data/maps/DewfordTown_Hall/scripts.pory"
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
# 293 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 294 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 295 "data/maps/DewfordTown_Hall/scripts.pory"

# 296 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
# 297 "data/maps/DewfordTown_Hall/scripts.pory"
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
# 298 "data/maps/DewfordTown_Hall/scripts.pory"
	release
# 299 "data/maps/DewfordTown_Hall/scripts.pory"
	end
# 300 "data/maps/DewfordTown_Hall/scripts.pory"

# 301 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
# 302 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 303 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 304 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I can't imagine what life would be like\n"
# 305 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "without “{STR_VAR_1}”!$"
# 306 "data/maps/DewfordTown_Hall/scripts.pory"

# 307 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GettingBoredOfTrend:
# 308 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What's in vogue? Why, it has to be\n"
# 309 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”!\p"
# 310 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But I'm getting kind of bored with it.\p"
# 311 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I should look for the next big thing.$"
# 312 "data/maps/DewfordTown_Hall/scripts.pory"

# 313 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TeachingMonAboutTrend:
# 314 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm teaching my POKéMON about\n"
# 315 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1},”\l"
# 316 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "but it's not going well.\p"
# 317 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's a bit too much, I think.$"
# 318 "data/maps/DewfordTown_Hall/scripts.pory"

# 319 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
# 320 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm studying up on the hip and trendy\n"
# 321 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” now.\p"
# 322 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is it true that there's a deep link\n"
# 323 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "between “{STR_VAR_1}”\l"
# 324 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "and “{STR_VAR_2}”?$"
# 325 "data/maps/DewfordTown_Hall/scripts.pory"

# 326 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_MyHunchWasRight:
# 327 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 328 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "So, my hunch was right!\p"
# 329 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm one step closer to being hip and\n"
# 330 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "happening, yowza!$"
# 331 "data/maps/DewfordTown_Hall/scripts.pory"

# 332 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_NotEasyToKeepUp:
# 333 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "What?!\n"
# 334 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is that so?!\p"
# 335 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's not easy for an older fellow like\n"
# 336 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "me to keep up with trends!$"
# 337 "data/maps/DewfordTown_Hall/scripts.pory"

# 338 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TVShowAboutTrend:
# 339 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "This whole business about\n"
# 340 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\l"
# 341 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't there a TV show on it?$"
# 342 "data/maps/DewfordTown_Hall/scripts.pory"

# 343 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
# 344 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Across the sea…\p"
# 345 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Is “{STR_VAR_1}”\n"
# 346 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "even more popular?$"
# 347 "data/maps/DewfordTown_Hall/scripts.pory"

# 348 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_CollectTrendMerchandise:
# 349 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I collect official\n"
# 350 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 351 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "licensed merchandise.\p"
# 352 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I have official\n"
# 353 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DOLLS…\p"
# 354 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Official “{STR_VAR_1}”\n"
# 355 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "brand clothing…\p"
# 356 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "And officially licensed\n"
# 357 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 358 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "picture books.\p"
# 359 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Heheh, I own!\n"
# 360 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm not sharing anything with you!$"
# 361 "data/maps/DewfordTown_Hall/scripts.pory"

# 362 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BooksAboutTrend:
# 363 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "IDENTIFYING GOOD\n"
# 364 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” &\l"
# 365 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "BAD “{STR_VAR_1}”…\p"
# 366 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "THE LINK BETWEEN\n"
# 367 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” AND\l"
# 368 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "POKéMON…\p"
# 369 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "USEFUL\n"
# 370 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\p"
# 371 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's neatly jammed with books about\n"
# 372 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 373 "data/maps/DewfordTown_Hall/scripts.pory"

# 374 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsScream:
# 375 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 376 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "SCREAM” is the title.$"
# 377 "data/maps/DewfordTown_Hall/scripts.pory"

# 378 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendsSmile:
# 379 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}'S\n"
# 380 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "SMILE” is the title.$"
# 381 "data/maps/DewfordTown_Hall/scripts.pory"

# 382 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LastTrend:
# 383 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE LAST\n"
# 384 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 385 "data/maps/DewfordTown_Hall/scripts.pory"

# 386 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BirthOfTrend:
# 387 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's titled “THE BIRTH OF\n"
# 388 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}”.$"
# 389 "data/maps/DewfordTown_Hall/scripts.pory"

# 390 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_SawTrendCoolestThing:
# 391 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I saw “{STR_VAR_1}”!\n"
# 392 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Cool, huh?\p"
# 393 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It's, like, the coolest thing going!\p"
# 394 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was awesome!\n"
# 395 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It was the real thing, oh yeah!$"
# 396 "data/maps/DewfordTown_Hall/scripts.pory"

# 397 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
# 398 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, no, no, no.\p"
# 399 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That alleged\n"
# 400 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 401 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you claim to have seen--it's not.\p"
# 402 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "The authentic article is much…\n"
# 403 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "How should I say it?\l"
# 404 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Sharper, yet more mellow!\p"
# 405 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Ah, no matter. It's astonishing!$"
# 406 "data/maps/DewfordTown_Hall/scripts.pory"

# 407 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_ComposedTrendThemeSong:
# 408 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hey, listen, I composed a theme song\n"
# 409 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "for “{STR_VAR_1}.”\p"
# 410 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\n"
# 411 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "is really popular right now.\p"
# 412 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Okay, listen!\n"
# 413 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 414 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh!\n"
# 415 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!\p"
# 416 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wonderful\n"
# 417 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "{STR_VAR_1}!$"
# 418 "data/maps/DewfordTown_Hall/scripts.pory"

# 419 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WorkOnYourSinging:
# 420 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "… …\p"
# 421 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I dare say, chap, it would pay for you\n"
# 422 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "to work on your singing before you\l"
# 423 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "trifle yourself with\l"
# 424 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”$"
# 425 "data/maps/DewfordTown_Hall/scripts.pory"

# 426 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_OrganizeTrendParty:
# 427 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Anyway, as I was saying earlier, we\n"
# 428 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "should get together and organize a\l"
# 429 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” party\l"
# 430 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "on the island.$"
# 431 "data/maps/DewfordTown_Hall/scripts.pory"

# 432 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_BrilliantIndeed:
# 433 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Oh, a smashing good idea!\p"
# 434 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "It will settle once and for all\n"
# 435 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "who is the best at\l"
# 436 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}.”\l"
# 437 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Brilliant, indeed!\p"
# 438 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Starting today, our lives will revolve\n"
# 439 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "around “{STR_VAR_1}”!$"
# 440 "data/maps/DewfordTown_Hall/scripts.pory"

# 441 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
# 442 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I was thinking, though…\p"
# 443 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Wouldn't you agree that\n"
# 444 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” has\l"
# 445 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "grown from being something trendy to\l"
# 446 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "being a part of our daily lives?$"
# 447 "data/maps/DewfordTown_Hall/scripts.pory"

# 448 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
# 449 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Beg pardon?\n"
# 450 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That much, what?\p"
# 451 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "However, it's true that\n"
# 452 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 453 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "weighs heavily on your mind, whether\l"
# 454 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "you're awake or asleep.\p"
# 455 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Absolutely, you're the\n"
# 456 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 457 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "PROFESSOR, old sport!$"
# 458 "data/maps/DewfordTown_Hall/scripts.pory"

# 459 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
# 460 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "If you and me team up as a combo,\n"
# 461 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "we'll be invincible when it comes to all\l"
# 462 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "things “{STR_VAR_1}”!$"
# 463 "data/maps/DewfordTown_Hall/scripts.pory"

# 464 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_WellBeTrendDuo:
# 465 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Spot on, my friend!\p"
# 466 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "We shall be the\n"
# 467 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}” DUO!\p"
# 468 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Isn't that a ripe image?\n"
# 469 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hahahah!$"
# 470 "data/maps/DewfordTown_Hall/scripts.pory"

# 471 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_GiveYouSludgeBomb:
# 472 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "For me, SLUDGE BOMB is at the peak\n"
# 473 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "of popularity. It's the one.\p"
# 474 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "Hunh? You're telling me that you don't\n"
# 475 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "know about SLUDGE BOMB?\p"
# 476 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "That's outright pitiful.\n"
# 477 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'll give you one.$"
# 478 "data/maps/DewfordTown_Hall/scripts.pory"

# 479 "data/maps/DewfordTown_Hall/scripts.pory"
DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
# 480 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I love SLUDGE BOMB.\p"
# 481 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "But POKéMON with the move\n"
# 482 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”\l"
# 483 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "are in, too.$"

DewfordTown_Hall_Text_WhatTheHeck::
# 34 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "I'm trying to ask these people if\n"
	.string "they've seen STEVEN, but they just\l"
	.string "keep talking about\l"
	.string "“{STR_VAR_1}.”\p"
	.string "What the heck is\n"
	.string "“{STR_VAR_1},” anyway?!$"

DewfordTown_Hall_Text_StuckInMyHead::
# 40 "data/maps/DewfordTown_Hall/scripts.pory"
	.string "“{STR_VAR_1}”…\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Argh!\n"
	.string "It's getting stuck in my head!$"
