# 1 "data/maps/Route103/scripts.pory"

# 2 "data/maps/Route103/scripts.pory"
.set LOCALID_RIVAL, 2
# 3 "data/maps/Route103/scripts.pory"

# 4 "data/maps/Route103/scripts.pory"
Route103_MapScripts::
# 5 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
# 6 "data/maps/Route103/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
# 7 "data/maps/Route103/scripts.pory"
	.byte 0
# 8 "data/maps/Route103/scripts.pory"

# 9 "data/maps/Route103/scripts.pory"
Route103_OnTransition:
# 10 "data/maps/Route103/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/Route103/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
# 12 "data/maps/Route103/scripts.pory"
	end
# 13 "data/maps/Route103/scripts.pory"

# 14 "data/maps/Route103/scripts.pory"
Route103_OnLoad:
# 15 "data/maps/Route103/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
# 16 "data/maps/Route103/scripts.pory"
	end
# 17 "data/maps/Route103/scripts.pory"

# 18 "data/maps/Route103/scripts.pory"
Route103_EventScript_OpenAlteringCave::
# 19 "data/maps/Route103/scripts.pory"
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
# 20 "data/maps/Route103/scripts.pory"
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
# 21 "data/maps/Route103/scripts.pory"
	return
# 22 "data/maps/Route103/scripts.pory"

# 23 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rival::
# 24 "data/maps/Route103/scripts.pory"
	lockall
# 25 "data/maps/Route103/scripts.pory"
	checkfriendchoice
# 26 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, SPENCER, Route103_EventScript_RivalBren
# 27 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, BREN, Route103_EventScript_RivalKyle
# 28 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, KYLE, Route103_EventScript_RivalSpencer
# 29 "data/maps/Route103/scripts.pory"
	end

Route103_EventScript_Rival2::
# 33 "data/maps/Route103/scripts.pory"
	lock
# 34 "data/maps/Route103/scripts.pory"
	faceplayer
# 35 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_CantBeatWingull, MSGBOX_DEFAULT
# 36 "data/maps/Route103/scripts.pory"
	closemessage
# 37 "data/maps/Route103/scripts.pory"
	release
	end


Route103_EventScript_RivalBren::
# 42 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrenRoute103Pokemon, MSGBOX_DEFAULT
# 43 "data/maps/Route103/scripts.pory"
	closemessage
# 44 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 45 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 46 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 47 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 48 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 49 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 50 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 51 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrenLetsBattle, MSGBOX_DEFAULT
# 52 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_StartBrenBattle
	end


Route103_EventScript_RivalKyle::
# 57 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_KyleRoute103Pokemon, MSGBOX_DEFAULT
# 58 "data/maps/Route103/scripts.pory"
	closemessage
# 59 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 60 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 61 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 62 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 63 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 65 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 66 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_KyleLetsBattle, MSGBOX_DEFAULT
# 67 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_StartKyleBattle
	end


Route103_EventScript_RivalSpencer::
# 72 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_SpencerRoute103Pokemon, MSGBOX_DEFAULT
# 73 "data/maps/Route103/scripts.pory"
	closemessage
# 74 "data/maps/Route103/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 75 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 76 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 77 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 78 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 79 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 80 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 81 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_SpencerLetsBattle, MSGBOX_DEFAULT
# 82 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_StartSpencerBattle
	end


# 86 "data/maps/Route103/scripts.pory"

# 87 "data/maps/Route103/scripts.pory"

# 88 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartKyleBattle::
# 89 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_KYLE_ROUTE_103, Route103_Text_KyleDefeated
# 90 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterKyleBattle
# 91 "data/maps/Route103/scripts.pory"
	end
# 92 "data/maps/Route103/scripts.pory"

# 93 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartBrenBattle::
# 94 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_BREN_ROUTE_103, Route103_Text_BrenDefeated
# 95 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterBrenBattle
# 96 "data/maps/Route103/scripts.pory"
	end
# 97 "data/maps/Route103/scripts.pory"

# 98 "data/maps/Route103/scripts.pory"
Route103_EventScript_StartSpencerBattle::
# 99 "data/maps/Route103/scripts.pory"
	trainerbattle_no_intro TRAINER_SPENCER_ROUTE_103, Route103_Text_SpencerDefeated
# 100 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_AfterSpencerBattle
# 101 "data/maps/Route103/scripts.pory"
	end
# 102 "data/maps/Route103/scripts.pory"

# 103 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterKyleBattle::
# 104 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_KyleTimeToHeadBack, MSGBOX_DEFAULT
# 105 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 106 "data/maps/Route103/scripts.pory"
	end
# 107 "data/maps/Route103/scripts.pory"

# 108 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterBrenBattle::
# 109 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_BrenTimeToHeadBack, MSGBOX_DEFAULT
# 110 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 111 "data/maps/Route103/scripts.pory"
	end
# 112 "data/maps/Route103/scripts.pory"

# 113 "data/maps/Route103/scripts.pory"
Route103_EventScript_AfterSpencerBattle::
# 114 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_SpencerTimeToHeadBack, MSGBOX_DEFAULT
# 115 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalExit
# 116 "data/maps/Route103/scripts.pory"
	end
# 117 "data/maps/Route103/scripts.pory"

# 118 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExit::
# 119 "data/maps/Route103/scripts.pory"
	closemessage
# 120 "data/maps/Route103/scripts.pory"
	switch VAR_FACING
# 121 "data/maps/Route103/scripts.pory"
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
# 122 "data/maps/Route103/scripts.pory"
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
# 123 "data/maps/Route103/scripts.pory"
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
# 124 "data/maps/Route103/scripts.pory"
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
# 125 "data/maps/Route103/scripts.pory"
	end
# 126 "data/maps/Route103/scripts.pory"

# 127 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingNorth::
# 128 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
# 129 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
# 130 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 131 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth2
# 133 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 134 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 135 "data/maps/Route103/scripts.pory"
	end
# 136 "data/maps/Route103/scripts.pory"

# 137 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingEastOrWest::
# 138 "data/maps/Route103/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
# 139 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 140 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 141 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 142 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 143 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 144 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 145 "data/maps/Route103/scripts.pory"
	end
# 146 "data/maps/Route103/scripts.pory"

# 147 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalExitFacingSouth::
# 148 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
# 149 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 150 "data/maps/Route103/scripts.pory"
	playse SE_LEDGE
# 151 "data/maps/Route103/scripts.pory"
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
# 152 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 153 "data/maps/Route103/scripts.pory"
	goto Route103_EventScript_RivalEnd
# 154 "data/maps/Route103/scripts.pory"
	end
# 155 "data/maps/Route103/scripts.pory"

# 156 "data/maps/Route103/scripts.pory"
Route103_EventScript_RivalEnd::
# 157 "data/maps/Route103/scripts.pory"
	removeobject LOCALID_RIVAL
# 158 "data/maps/Route103/scripts.pory"
	setvar VAR_BIRCH_LAB_STATE, 4
# 159 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
# 160 "data/maps/Route103/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
# 161 "data/maps/Route103/scripts.pory"
	setflag FLAG_HIDE_ROUTE_103_RIVAL
# 162 "data/maps/Route103/scripts.pory"
	setvar VAR_OLDALE_RIVAL_STATE, 1
# 163 "data/maps/Route103/scripts.pory"
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
# 164 "data/maps/Route103/scripts.pory"
	savebgm MUS_DUMMY
# 165 "data/maps/Route103/scripts.pory"
	fadedefaultbgm
# 166 "data/maps/Route103/scripts.pory"
	releaseall
# 167 "data/maps/Route103/scripts.pory"
	end
# 168 "data/maps/Route103/scripts.pory"

# 169 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth1:
# 170 "data/maps/Route103/scripts.pory"
	walk_left
# 171 "data/maps/Route103/scripts.pory"
	walk_down
# 172 "data/maps/Route103/scripts.pory"
	step_end
# 173 "data/maps/Route103/scripts.pory"

# 174 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExitFacingNorth2:
# 175 "data/maps/Route103/scripts.pory"
	jump_2_down
# 176 "data/maps/Route103/scripts.pory"
	delay_16
# 177 "data/maps/Route103/scripts.pory"
	walk_down
# 178 "data/maps/Route103/scripts.pory"
	walk_down
# 179 "data/maps/Route103/scripts.pory"
	walk_down
# 180 "data/maps/Route103/scripts.pory"
	walk_down
# 181 "data/maps/Route103/scripts.pory"
	step_end
# 182 "data/maps/Route103/scripts.pory"

# 183 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingNorth:
# 184 "data/maps/Route103/scripts.pory"
	delay_16
# 185 "data/maps/Route103/scripts.pory"
	delay_4
# 186 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_left
# 187 "data/maps/Route103/scripts.pory"
	delay_16
# 188 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 189 "data/maps/Route103/scripts.pory"
	step_end
# 190 "data/maps/Route103/scripts.pory"

# 191 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit1:
# 192 "data/maps/Route103/scripts.pory"
	walk_down
# 193 "data/maps/Route103/scripts.pory"
	step_end
# 194 "data/maps/Route103/scripts.pory"

# 195 "data/maps/Route103/scripts.pory"
Route103_Movement_RivalExit2:
# 196 "data/maps/Route103/scripts.pory"
	jump_2_down
# 197 "data/maps/Route103/scripts.pory"
	delay_16
# 198 "data/maps/Route103/scripts.pory"
	walk_down
# 199 "data/maps/Route103/scripts.pory"
	walk_down
# 200 "data/maps/Route103/scripts.pory"
	walk_down
# 201 "data/maps/Route103/scripts.pory"
	step_end
# 202 "data/maps/Route103/scripts.pory"

# 203 "data/maps/Route103/scripts.pory"
Route103_Movement_WatchRivalExitFacingEastOrWest:
# 204 "data/maps/Route103/scripts.pory"
	delay_16
# 205 "data/maps/Route103/scripts.pory"
	walk_in_place_faster_down
# 206 "data/maps/Route103/scripts.pory"
	step_end
# 207 "data/maps/Route103/scripts.pory"

# 208 "data/maps/Route103/scripts.pory"
Route103_EventScript_Boy::
# 209 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
# 210 "data/maps/Route103/scripts.pory"
	end
# 211 "data/maps/Route103/scripts.pory"

# 212 "data/maps/Route103/scripts.pory"
Route103_EventScript_Man::
# 213 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
# 214 "data/maps/Route103/scripts.pory"
	end
# 215 "data/maps/Route103/scripts.pory"

# 216 "data/maps/Route103/scripts.pory"
Route103_EventScript_RouteSign::
# 217 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
# 218 "data/maps/Route103/scripts.pory"
	end
# 219 "data/maps/Route103/scripts.pory"

# 220 "data/maps/Route103/scripts.pory"
Route103_EventScript_Daisy::
# 221 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
# 222 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
# 223 "data/maps/Route103/scripts.pory"
	end
# 224 "data/maps/Route103/scripts.pory"

# 225 "data/maps/Route103/scripts.pory"
Route103_EventScript_Amy::
# 226 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
# 227 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 228 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
# 229 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
# 230 "data/maps/Route103/scripts.pory"
	end
# 231 "data/maps/Route103/scripts.pory"

# 232 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRegisterMatchCallAfterBattle::
# 233 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 234 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 235 "data/maps/Route103/scripts.pory"
	release
# 236 "data/maps/Route103/scripts.pory"
	end
# 237 "data/maps/Route103/scripts.pory"

# 238 "data/maps/Route103/scripts.pory"
Route102_EventScript_AmyRematch::
# 239 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
# 240 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
# 241 "data/maps/Route103/scripts.pory"
	end
# 242 "data/maps/Route103/scripts.pory"

# 243 "data/maps/Route103/scripts.pory"
Route103_EventScript_Liv::
# 244 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
# 245 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 246 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
# 247 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
# 248 "data/maps/Route103/scripts.pory"
	end
# 249 "data/maps/Route103/scripts.pory"

# 250 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRegisterMatchCallAfterBattle::
# 251 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
# 252 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_AMY_AND_LIV_1
# 253 "data/maps/Route103/scripts.pory"
	release
# 254 "data/maps/Route103/scripts.pory"
	end
# 255 "data/maps/Route103/scripts.pory"

# 256 "data/maps/Route103/scripts.pory"
Route102_EventScript_LivRematch::
# 257 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
# 258 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
# 259 "data/maps/Route103/scripts.pory"
	end
# 260 "data/maps/Route103/scripts.pory"

# 261 "data/maps/Route103/scripts.pory"
Route103_EventScript_Andrew::
# 262 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
# 263 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
# 264 "data/maps/Route103/scripts.pory"
	end
# 265 "data/maps/Route103/scripts.pory"

# 266 "data/maps/Route103/scripts.pory"
Route103_EventScript_Miguel::
# 267 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
# 268 "data/maps/Route103/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 269 "data/maps/Route103/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
# 270 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
# 271 "data/maps/Route103/scripts.pory"
	release
# 272 "data/maps/Route103/scripts.pory"
	end
# 273 "data/maps/Route103/scripts.pory"

# 274 "data/maps/Route103/scripts.pory"
Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
# 275 "data/maps/Route103/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 276 "data/maps/Route103/scripts.pory"
	waitmovement 0
# 277 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
# 278 "data/maps/Route103/scripts.pory"
	register_matchcall TRAINER_MIGUEL_1
# 279 "data/maps/Route103/scripts.pory"
	release
# 280 "data/maps/Route103/scripts.pory"
	end
# 281 "data/maps/Route103/scripts.pory"

# 282 "data/maps/Route103/scripts.pory"
Route103_EventScript_MiguelRematch::
# 283 "data/maps/Route103/scripts.pory"
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
# 284 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
# 285 "data/maps/Route103/scripts.pory"
	end
# 286 "data/maps/Route103/scripts.pory"

# 287 "data/maps/Route103/scripts.pory"
Route103_EventScript_Marcos::
# 288 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
# 289 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
# 290 "data/maps/Route103/scripts.pory"
	end
# 291 "data/maps/Route103/scripts.pory"

# 292 "data/maps/Route103/scripts.pory"
Route103_EventScript_Rhett::
# 293 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
# 294 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
# 295 "data/maps/Route103/scripts.pory"
	end
# 296 "data/maps/Route103/scripts.pory"

# 297 "data/maps/Route103/scripts.pory"
Route103_EventScript_Pete::
# 298 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
# 299 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
# 300 "data/maps/Route103/scripts.pory"
	end
# 301 "data/maps/Route103/scripts.pory"

# 302 "data/maps/Route103/scripts.pory"
Route103_EventScript_Isabelle::
# 303 "data/maps/Route103/scripts.pory"
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
# 304 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
# 305 "data/maps/Route103/scripts.pory"
	end
# 306 "data/maps/Route103/scripts.pory"

# 307 "data/maps/Route103/scripts.pory"
Route103_Text_KyleRoute103Pokemon:
# 308 "data/maps/Route103/scripts.pory"
	.string "KYLE: Let's see… Is PIKACHU\n"
# 309 "data/maps/Route103/scripts.pory"
	.string "found on this route?$"
# 310 "data/maps/Route103/scripts.pory"

# 311 "data/maps/Route103/scripts.pory"
Route103_Text_KyleLetsBattle:
# 312 "data/maps/Route103/scripts.pory"
	.string "Oh, hi, {PLAYER}{KUN}!\p"
# 313 "data/maps/Route103/scripts.pory"
	.string "…Oh, I see you finally got\n"
# 314 "data/maps/Route103/scripts.pory"
	.string "your POKéMON from PROF. BIRCH.\p"
# 315 "data/maps/Route103/scripts.pory"
	.string "Since we're here, let's have a quick\n"
# 316 "data/maps/Route103/scripts.pory"
	.string "battle!\p"
# 317 "data/maps/Route103/scripts.pory"
	.string "I'll give you a taste of what being\n"
# 318 "data/maps/Route103/scripts.pory"
	.string "a real TRAINER is like.$"
# 319 "data/maps/Route103/scripts.pory"

# 320 "data/maps/Route103/scripts.pory"
Route103_Text_KyleDefeated:
# 321 "data/maps/Route103/scripts.pory"
	.string "Wow! That's great!\n"
# 322 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}{KUN}, you're pretty good!$"
# 323 "data/maps/Route103/scripts.pory"

# 324 "data/maps/Route103/scripts.pory"
Route103_Text_KyleTimeToHeadBack:
# 325 "data/maps/Route103/scripts.pory"
	.string "KYLE: That's really impressive!\n"
# 326 "data/maps/Route103/scripts.pory"
	.string "I mean, you just got that POKéMON,\n"
# 327 "data/maps/Route103/scripts.pory"
	.string "but it already likes you.\p"
# 328 "data/maps/Route103/scripts.pory"
	.string "You might be able to befriend any\n"
# 329 "data/maps/Route103/scripts.pory"
	.string "kind of POKéMON easily.\p"
# 330 "data/maps/Route103/scripts.pory"
	.string "Oh, by the way, PROF. BIRCH mentioned\n"
# 331 "data/maps/Route103/scripts.pory"
	.string "That he wanted to speak to the three\l"
# 332 "data/maps/Route103/scripts.pory"
	.string "of us together once we all had POKéMON.\p"
# 333 "data/maps/Route103/scripts.pory"
	.string "Let's head back to the LAB!$"
# 334 "data/maps/Route103/scripts.pory"

# 335 "data/maps/Route103/scripts.pory"
Route103_Text_BrenRoute103Pokemon:
# 336 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 337 "data/maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 338 "data/maps/Route103/scripts.pory"

# 339 "data/maps/Route103/scripts.pory"
Route103_Text_BrenLetsBattle:
# 340 "data/maps/Route103/scripts.pory"
	.string "Hey, it's {PLAYER}!\p"
# 341 "data/maps/Route103/scripts.pory"
	.string "What kind of POKéMON did you get?\p"
# 342 "data/maps/Route103/scripts.pory"
	.string "Since we're here, how about a\n"
# 343 "data/maps/Route103/scripts.pory"
	.string "little battle?\p"
# 344 "data/maps/Route103/scripts.pory"
	.string "I won't go easy on you!$"
# 345 "data/maps/Route103/scripts.pory"

# 346 "data/maps/Route103/scripts.pory"
Route103_Text_BrenDefeated:
# 347 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 348 "data/maps/Route103/scripts.pory"

# 349 "data/maps/Route103/scripts.pory"
Route103_Text_BrenTimeToHeadBack:
# 350 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 351 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 352 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 353 "data/maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 354 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 355 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 356 "data/maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 357 "data/maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 358 "data/maps/Route103/scripts.pory"

# 359 "data/maps/Route103/scripts.pory"
Route103_Text_SpencerRoute103Pokemon:
# 360 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
# 361 "data/maps/Route103/scripts.pory"
	.string "that one that live on ROUTE 103…$"
# 362 "data/maps/Route103/scripts.pory"

# 363 "data/maps/Route103/scripts.pory"
Route103_Text_SpencerLetsBattle:
# 364 "data/maps/Route103/scripts.pory"
	.string "Yo! {PLAYER}!\p"
# 365 "data/maps/Route103/scripts.pory"
	.string "You should show me what kind\n"
# 366 "data/maps/Route103/scripts.pory"
	.string "of POKéMON you got from the PROF.\p"
# 367 "data/maps/Route103/scripts.pory"
	.string "What better way to do that\n"
# 368 "data/maps/Route103/scripts.pory"
	.string "than through battling?"
# 369 "data/maps/Route103/scripts.pory"
	.string "C'mon!$"
# 370 "data/maps/Route103/scripts.pory"

# 371 "data/maps/Route103/scripts.pory"
Route103_Text_SpencerDefeated:
# 372 "data/maps/Route103/scripts.pory"
	.string "Huh, {PLAYER}, you're not too shabby.$"
# 373 "data/maps/Route103/scripts.pory"

# 374 "data/maps/Route103/scripts.pory"
Route103_Text_SpencerTimeToHeadBack:
# 375 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
# 376 "data/maps/Route103/scripts.pory"
	.string "I think I know why my dad has his eye\l"
# 377 "data/maps/Route103/scripts.pory"
	.string "out for you now.\p"
# 378 "data/maps/Route103/scripts.pory"
	.string "Look, your POKéMON already likes you,\n"
# 379 "data/maps/Route103/scripts.pory"
	.string "even though you just got it.\p"
# 380 "data/maps/Route103/scripts.pory"
	.string "{PLAYER}, I get the feeling that you\n"
# 381 "data/maps/Route103/scripts.pory"
	.string "could befriend any POKéMON with ease.\p"
# 382 "data/maps/Route103/scripts.pory"
	.string "We should head back to the LAB.$"
# 383 "data/maps/Route103/scripts.pory"

# 384 "data/maps/Route103/scripts.pory"
Route103_Text_ShouldHaveBroughtPotion:
# 385 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
# 386 "data/maps/Route103/scripts.pory"
	.string "I should have brought a POTION…$"
# 387 "data/maps/Route103/scripts.pory"

# 388 "data/maps/Route103/scripts.pory"
Route103_Text_ShortcutToOldale:
# 389 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
# 390 "data/maps/Route103/scripts.pory"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
# 391 "data/maps/Route103/scripts.pory"
	.string "Fufufu, that's useful, isn't it?$"
# 392 "data/maps/Route103/scripts.pory"

# 393 "data/maps/Route103/scripts.pory"
Route103_Text_RouteSign:
# 394 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103\n"
# 395 "data/maps/Route103/scripts.pory"
	.string "{DOWN_ARROW} OLDALE TOWN$"

Route103_Text_CantBeatWingull::
# 399 "data/maps/Route103/scripts.pory"
	.string "Darn.\n"
	.string "I'm really having trouble\l"
	.string "beating WINGULL in battle.$"
