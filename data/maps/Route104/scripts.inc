# 1 "data/maps/Route104/scripts.pory"

# 2 "data/maps/Route104/scripts.pory"
@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
# 3 "data/maps/Route104/scripts.pory"
@  These are labeled in DewfordTown/scripts.inc
# 4 "data/maps/Route104/scripts.pory"
.set LOCALID_RIVAL, 34
# 5 "data/maps/Route104/scripts.pory"

# 6 "data/maps/Route104/scripts.pory"
Route104_MapScripts::
# 7 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
# 8 "data/maps/Route104/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
# 9 "data/maps/Route104/scripts.pory"
	.byte 0
# 10 "data/maps/Route104/scripts.pory"

# 11 "data/maps/Route104/scripts.pory"
Route104_OnFrame:
# 12 "data/maps/Route104/scripts.pory"
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
# 13 "data/maps/Route104/scripts.pory"
	.2byte 0
# 14 "data/maps/Route104/scripts.pory"

# 15 "data/maps/Route104/scripts.pory"
Route104_EventScript_StartSailToDewford::
# 16 "data/maps/Route104/scripts.pory"
	lockall
# 17 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_SailToDewford
# 18 "data/maps/Route104/scripts.pory"
	end
# 19 "data/maps/Route104/scripts.pory"

# 20 "data/maps/Route104/scripts.pory"
Route104_OnTransition:
# 21 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_RIVAL1
# 22 "data/maps/Route104/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 23 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_TrySetRivalPos
# 24 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
# 25 "data/maps/Route104/scripts.pory"
	end
# 26 "data/maps/Route104/scripts.pory"

# 27 "data/maps/Route104/scripts.pory"
Route104_EventScript_ShowOrHideWhiteHerbFlorist::
# 28 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
# 29 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
# 30 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 31 "data/maps/Route104/scripts.pory"
	return
# 32 "data/maps/Route104/scripts.pory"

# 33 "data/maps/Route104/scripts.pory"
Route104_EventScript_HideWhiteHerbFlorist::
# 34 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
# 35 "data/maps/Route104/scripts.pory"
	return
# 36 "data/maps/Route104/scripts.pory"

# 37 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrySetRivalPos::
# 38 "data/maps/Route104/scripts.pory"
	goto_if_ge VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_DontSetRivalPos
# 39 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
# 40 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
# 41 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 17, 52
# 42 "data/maps/Route104/scripts.pory"
	return
# 43 "data/maps/Route104/scripts.pory"

# 44 "data/maps/Route104/scripts.pory"
Route104_EventScript_DontSetRivalPos::
# 45 "data/maps/Route104/scripts.pory"
	return

Route104_EventScript_Rival1::
# 49 "data/maps/Route104/scripts.pory"
	lock
# 50 "data/maps/Route104/scripts.pory"
	faceplayer
# 51 "data/maps/Route104/scripts.pory"
	compare VAR_TEMP_5, 5
	goto_if_ne Route104_EventScript_Rival1_2
# 56 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsAcrossTheSea, MSGBOX_DEFAULT
Route104_EventScript_Rival1_1:
# 58 "data/maps/Route104/scripts.pory"
	release
	end

Route104_EventScript_Rival1_2:
# 52 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeToSurf, MSGBOX_DEFAULT
# 53 "data/maps/Route104/scripts.pory"
	setvar VAR_TEMP_5, 5
	goto Route104_EventScript_Rival1_1


# 70 "data/maps/Route104/scripts.pory"

# 71 "data/maps/Route104/scripts.pory"
Route104_EventScript_Rival::
# 72 "data/maps/Route104/scripts.pory"
	lockall
# 73 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 1
# 74 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 75 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 76 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 77 "data/maps/Route104/scripts.pory"

# 78 "data/maps/Route104/scripts.pory"
Route104_EventScript_RivalTrigger::
# 79 "data/maps/Route104/scripts.pory"
	lockall
# 80 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
# 81 "data/maps/Route104/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 8
# 82 "data/maps/Route104/scripts.pory"
	setvar VAR_ROUTE104_STATE, 2
# 83 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 84 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 85 "data/maps/Route104/scripts.pory"
	delay 10
# 86 "data/maps/Route104/scripts.pory"
	addobject LOCALID_RIVAL
# 87 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
# 88 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
# 89 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 90 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
# 91 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 92 "data/maps/Route104/scripts.pory"
	delay 20
# 93 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8008, 0
# 94 "data/maps/Route104/scripts.pory"
	call RustboroCity_EventScript_PlayRivalMusic
# 95 "data/maps/Route104/scripts.pory"
	playse SE_PIN
# 96 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
# 97 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 98 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
# 99 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 100 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_RivalEncounter
# 101 "data/maps/Route104/scripts.pory"

# 102 "data/maps/Route104/scripts.pory"
@ Unused, shares script with Rustboro encounter instead
# 103 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayRivalMusic::
# 104 "data/maps/Route104/scripts.pory"
	checkplayergender
# 105 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_PlayMayMusic
# 106 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_PlayBrendanMusic
# 107 "data/maps/Route104/scripts.pory"
	return
# 108 "data/maps/Route104/scripts.pory"

# 109 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayMayMusic::
# 110 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 111 "data/maps/Route104/scripts.pory"
	return
# 112 "data/maps/Route104/scripts.pory"

# 113 "data/maps/Route104/scripts.pory"
Route104_EventScript_PlayBrendanMusic::
# 114 "data/maps/Route104/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 115 "data/maps/Route104/scripts.pory"
	return
# 116 "data/maps/Route104/scripts.pory"

# 117 "data/maps/Route104/scripts.pory"
Route104_EventScript_RivalEncounter::
# 118 "data/maps/Route104/scripts.pory"
	checkplayergender
# 119 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, Route104_EventScript_MayEncounter
# 120 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, Route104_EventScript_BrendanEncounter
# 121 "data/maps/Route104/scripts.pory"
	end
# 122 "data/maps/Route104/scripts.pory"

# 123 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayEncounter::
# 124 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
# 125 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
# 126 "data/maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 127 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
# 128 "data/maps/Route104/scripts.pory"
	closemessage
# 129 "data/maps/Route104/scripts.pory"
	delay 30
# 130 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 131 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
# 132 "data/maps/Route104/scripts.pory"
	waitfanfare
# 133 "data/maps/Route104/scripts.pory"
	closemessage
# 134 "data/maps/Route104/scripts.pory"
	delay 30
# 135 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 136 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 137 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 138 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
# 139 "data/maps/Route104/scripts.pory"
	closemessage
# 140 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 141 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 142 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 143 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 144 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
# 145 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 146 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 147 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 148 "data/maps/Route104/scripts.pory"
	releaseall
# 149 "data/maps/Route104/scripts.pory"
	end
# 150 "data/maps/Route104/scripts.pory"

# 151 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalWalkSlowLeft:
# 152 "data/maps/Route104/scripts.pory"
	walk_slow_left
# 153 "data/maps/Route104/scripts.pory"
	step_end
# 154 "data/maps/Route104/scripts.pory"

# 155 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalApproachPlayer:
# 156 "data/maps/Route104/scripts.pory"
	walk_down
# 157 "data/maps/Route104/scripts.pory"
	face_right
# 158 "data/maps/Route104/scripts.pory"
	step_end
# 159 "data/maps/Route104/scripts.pory"

# 160 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerFaceRival:
# 161 "data/maps/Route104/scripts.pory"
	delay_4
# 162 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 163 "data/maps/Route104/scripts.pory"
	step_end
# 164 "data/maps/Route104/scripts.pory"

# 165 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayAskToBattle::
# 166 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
# 167 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleMay
# 168 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
# 169 "data/maps/Route104/scripts.pory"
	releaseall
# 170 "data/maps/Route104/scripts.pory"
	end
# 171 "data/maps/Route104/scripts.pory"

# 172 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMay::
# 173 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
# 174 "data/maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 175 "data/maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleMayTreecko
# 176 "data/maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleMayTorchic
# 177 "data/maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleMayMudkip
# 178 "data/maps/Route104/scripts.pory"
	end
# 179 "data/maps/Route104/scripts.pory"

# 180 "data/maps/Route104/scripts.pory"
Route104_EventScript_MayDefeated::
# 181 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
# 182 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 183 "data/maps/Route104/scripts.pory"
	releaseall
# 184 "data/maps/Route104/scripts.pory"
	end
# 185 "data/maps/Route104/scripts.pory"

# 186 "data/maps/Route104/scripts.pory"
Route104_EventScript_RestoreMusic::
# 187 "data/maps/Route104/scripts.pory"
	savebgm MUS_DUMMY
# 188 "data/maps/Route104/scripts.pory"
	fadedefaultbgm
# 189 "data/maps/Route104/scripts.pory"
	return
# 190 "data/maps/Route104/scripts.pory"

# 191 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTreecko::
# 192 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, Route104_Text_MayDefeat
# 193 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 194 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 195 "data/maps/Route104/scripts.pory"
	end
# 196 "data/maps/Route104/scripts.pory"

# 197 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayTorchic::
# 198 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, Route104_Text_MayDefeat
# 199 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 200 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 201 "data/maps/Route104/scripts.pory"
	end
# 202 "data/maps/Route104/scripts.pory"

# 203 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleMayMudkip::
# 204 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, Route104_Text_MayDefeat
# 205 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 206 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_MayDefeated
# 207 "data/maps/Route104/scripts.pory"
	end
# 208 "data/maps/Route104/scripts.pory"

# 209 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanEncounter::
# 210 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
# 211 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
# 212 "data/maps/Route104/scripts.pory"
	setflag FLAG_REGISTER_RIVAL_POKENAV
# 213 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
# 214 "data/maps/Route104/scripts.pory"
	closemessage
# 215 "data/maps/Route104/scripts.pory"
	delay 30
# 216 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 217 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
# 218 "data/maps/Route104/scripts.pory"
	waitfanfare
# 219 "data/maps/Route104/scripts.pory"
	closemessage
# 220 "data/maps/Route104/scripts.pory"
	delay 30
# 221 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
# 222 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
# 223 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
# 224 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
# 225 "data/maps/Route104/scripts.pory"
	closemessage
# 226 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 227 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
# 228 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 229 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_RIVAL
# 230 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
# 231 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 232 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 233 "data/maps/Route104/scripts.pory"
	call Route104_EventScript_RestoreMusic
# 234 "data/maps/Route104/scripts.pory"
	releaseall
# 235 "data/maps/Route104/scripts.pory"
	end
# 236 "data/maps/Route104/scripts.pory"

# 237 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanAskToBattle::
# 238 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
# 239 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route104_EventScript_BattleBrendan
# 240 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 241 "data/maps/Route104/scripts.pory"
	releaseall
# 242 "data/maps/Route104/scripts.pory"
	end
# 243 "data/maps/Route104/scripts.pory"

# 244 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendan::
# 245 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
# 246 "data/maps/Route104/scripts.pory"
	switch VAR_STARTER_MON
# 247 "data/maps/Route104/scripts.pory"
	case 0, Route104_EventScript_BattleBrendanTreecko
# 248 "data/maps/Route104/scripts.pory"
	case 1, Route104_EventScript_BattleBrendanTorchic
# 249 "data/maps/Route104/scripts.pory"
	case 2, Route104_EventScript_BattleBrendanMudkip
# 250 "data/maps/Route104/scripts.pory"
	end
# 251 "data/maps/Route104/scripts.pory"

# 252 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrendanDefeated::
# 253 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
# 254 "data/maps/Route104/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route104_EventScript_RestoreMusic
# 255 "data/maps/Route104/scripts.pory"
	releaseall
# 256 "data/maps/Route104/scripts.pory"
	end
# 257 "data/maps/Route104/scripts.pory"

# 258 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTreecko::
# 259 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Route104_Text_BrendanDefeat
# 260 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 261 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 262 "data/maps/Route104/scripts.pory"
	end
# 263 "data/maps/Route104/scripts.pory"

# 264 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanTorchic::
# 265 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Route104_Text_BrendanDefeat
# 266 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 267 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 268 "data/maps/Route104/scripts.pory"
	end
# 269 "data/maps/Route104/scripts.pory"

# 270 "data/maps/Route104/scripts.pory"
Route104_EventScript_BattleBrendanMudkip::
# 271 "data/maps/Route104/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Route104_Text_BrendanDefeat
# 272 "data/maps/Route104/scripts.pory"
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
# 273 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_BrendanDefeated
# 274 "data/maps/Route104/scripts.pory"
	end
# 275 "data/maps/Route104/scripts.pory"

# 276 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBackUp:
# 277 "data/maps/Route104/scripts.pory"
	lock_facing_direction
# 278 "data/maps/Route104/scripts.pory"
	walk_down
# 279 "data/maps/Route104/scripts.pory"
	unlock_facing_direction
# 280 "data/maps/Route104/scripts.pory"
	step_end
# 281 "data/maps/Route104/scripts.pory"

# 282 "data/maps/Route104/scripts.pory"
Route104_Movement_RivalExitBrineysCottage:
# 283 "data/maps/Route104/scripts.pory"
	walk_down
# 284 "data/maps/Route104/scripts.pory"
	step_end
# 285 "data/maps/Route104/scripts.pory"

# 286 "data/maps/Route104/scripts.pory"
Route104_EventScript_ExpertF::
# 287 "data/maps/Route104/scripts.pory"
	lock
# 288 "data/maps/Route104/scripts.pory"
	faceplayer
# 289 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
# 290 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
# 291 "data/maps/Route104/scripts.pory"
	giveitem ITEM_CHESTO_BERRY
# 292 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 293 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
# 294 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 295 "data/maps/Route104/scripts.pory"
	release
# 296 "data/maps/Route104/scripts.pory"
	end
# 297 "data/maps/Route104/scripts.pory"

# 298 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBerry::
# 299 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
# 300 "data/maps/Route104/scripts.pory"
	release
# 301 "data/maps/Route104/scripts.pory"
	end
# 302 "data/maps/Route104/scripts.pory"

# 303 "data/maps/Route104/scripts.pory"
Route104_EventScript_WhiteHerbFlorist::
# 304 "data/maps/Route104/scripts.pory"
	lock
# 305 "data/maps/Route104/scripts.pory"
	faceplayer
# 306 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
# 307 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
# 308 "data/maps/Route104/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 309 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 310 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_WHITE_HERB
# 311 "data/maps/Route104/scripts.pory"
	release
# 312 "data/maps/Route104/scripts.pory"
	end
# 313 "data/maps/Route104/scripts.pory"

# 314 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedWhiteHerb::
# 315 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
# 316 "data/maps/Route104/scripts.pory"
	release
# 317 "data/maps/Route104/scripts.pory"
	end
# 318 "data/maps/Route104/scripts.pory"

# 319 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl1::
# 320 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
# 321 "data/maps/Route104/scripts.pory"
	end
# 322 "data/maps/Route104/scripts.pory"

# 323 "data/maps/Route104/scripts.pory"
Route104_EventScript_BugCatcher::
# 324 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
# 325 "data/maps/Route104/scripts.pory"
	end
# 326 "data/maps/Route104/scripts.pory"

# 327 "data/maps/Route104/scripts.pory"
Route104_EventScript_BrineysCottageSign::
# 328 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
# 329 "data/maps/Route104/scripts.pory"
	end
# 330 "data/maps/Route104/scripts.pory"

# 331 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignPetalburg::
# 332 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
# 333 "data/maps/Route104/scripts.pory"
	end
# 334 "data/maps/Route104/scripts.pory"

# 335 "data/maps/Route104/scripts.pory"
Route104_EventScript_RouteSignRustboro::
# 336 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
# 337 "data/maps/Route104/scripts.pory"
	end
# 338 "data/maps/Route104/scripts.pory"

# 339 "data/maps/Route104/scripts.pory"
Route104_EventScript_FlowerShopSign::
# 340 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
# 341 "data/maps/Route104/scripts.pory"
	end
# 342 "data/maps/Route104/scripts.pory"

# 343 "data/maps/Route104/scripts.pory"
Route104_EventScript_TrainerTipsDoubleBattles::
# 344 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
# 345 "data/maps/Route104/scripts.pory"
	end
# 346 "data/maps/Route104/scripts.pory"

# 347 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy1::
# 348 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
# 349 "data/maps/Route104/scripts.pory"
	end
# 350 "data/maps/Route104/scripts.pory"

# 351 "data/maps/Route104/scripts.pory"
Route104_EventScript_Woman::
# 352 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
# 353 "data/maps/Route104/scripts.pory"
	end
# 354 "data/maps/Route104/scripts.pory"

# 355 "data/maps/Route104/scripts.pory"
Route104_EventScript_Boy2::
# 356 "data/maps/Route104/scripts.pory"
	lock
# 357 "data/maps/Route104/scripts.pory"
	faceplayer
# 358 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_BULLET_SEED, Route104_EventScript_ReceivedBulletSeed
# 359 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
# 360 "data/maps/Route104/scripts.pory"
	giveitem ITEM_TM_BULLET_SEED
# 361 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 362 "data/maps/Route104/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULLET_SEED
# 363 "data/maps/Route104/scripts.pory"
	release
# 364 "data/maps/Route104/scripts.pory"
	end
# 365 "data/maps/Route104/scripts.pory"

# 366 "data/maps/Route104/scripts.pory"
Route104_EventScript_ReceivedBulletSeed::
# 367 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
# 368 "data/maps/Route104/scripts.pory"
	release
# 369 "data/maps/Route104/scripts.pory"
	end
# 370 "data/maps/Route104/scripts.pory"

# 371 "data/maps/Route104/scripts.pory"
Route104_EventScript_Girl2::
# 372 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
# 373 "data/maps/Route104/scripts.pory"
	end
# 374 "data/maps/Route104/scripts.pory"

# 375 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewford::
# 376 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_R104, MAP_ROUTE104, 0
# 377 "data/maps/Route104/scripts.pory"
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104, 0
# 378 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
# 379 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 380 "data/maps/Route104/scripts.pory"
	removeobject LOCALID_BRINEY_R104
# 381 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
# 382 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 383 "data/maps/Route104/scripts.pory"
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 384 "data/maps/Route104/scripts.pory"
	call Common_EventScript_PlayBrineysBoatMusic
# 385 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
# 386 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
# 387 "data/maps/Route104/scripts.pory"
	end
# 388 "data/maps/Route104/scripts.pory"

# 389 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordNoCall::
# 390 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
# 391 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
# 392 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 393 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 394 "data/maps/Route104/scripts.pory"

# 395 "data/maps/Route104/scripts.pory"
Route104_EventScript_SailToDewfordDadCalls::
# 396 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
# 397 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
# 398 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 399 "data/maps/Route104/scripts.pory"
	pokenavcall Route104_Text_DadPokenavCall
# 400 "data/maps/Route104/scripts.pory"
	waitmessage
# 401 "data/maps/Route104/scripts.pory"
	delay 30
# 402 "data/maps/Route104/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 403 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
# 404 "data/maps/Route104/scripts.pory"
	waitfanfare
# 405 "data/maps/Route104/scripts.pory"
	closemessage
# 406 "data/maps/Route104/scripts.pory"
	delay 30
# 407 "data/maps/Route104/scripts.pory"
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
# 408 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
# 409 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
# 410 "data/maps/Route104/scripts.pory"
	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
# 411 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 412 "data/maps/Route104/scripts.pory"
	goto Route104_EventScript_ArriveInDewford
# 413 "data/maps/Route104/scripts.pory"

# 414 "data/maps/Route104/scripts.pory"
Route104_EventScript_ArriveInDewford::
# 415 "data/maps/Route104/scripts.pory"
	delay 50
# 416 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
# 417 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 418 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 419 "data/maps/Route104/scripts.pory"
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
# 420 "data/maps/Route104/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
# 421 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 422 "data/maps/Route104/scripts.pory"
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
# 423 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BRINEY_DEWFORD
# 424 "data/maps/Route104/scripts.pory"
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
# 425 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
# 426 "data/maps/Route104/scripts.pory"
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
# 427 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 428 "data/maps/Route104/scripts.pory"
	addobject LOCALID_BOAT_DEWFORD
# 429 "data/maps/Route104/scripts.pory"
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
# 430 "data/maps/Route104/scripts.pory"
	call Common_EventScript_StopBrineysBoatMusic
# 431 "data/maps/Route104/scripts.pory"
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
# 432 "data/maps/Route104/scripts.pory"
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
# 433 "data/maps/Route104/scripts.pory"
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
# 434 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
# 435 "data/maps/Route104/scripts.pory"
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
# 436 "data/maps/Route104/scripts.pory"
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
# 437 "data/maps/Route104/scripts.pory"
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
# 438 "data/maps/Route104/scripts.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
# 439 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
# 440 "data/maps/Route104/scripts.pory"
	end
# 441 "data/maps/Route104/scripts.pory"

# 442 "data/maps/Route104/scripts.pory"
Route104_EventScript_DeliverLetterReminder::
# 443 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
# 444 "data/maps/Route104/scripts.pory"
	releaseall
# 445 "data/maps/Route104/scripts.pory"
	end
# 446 "data/maps/Route104/scripts.pory"

# 447 "data/maps/Route104/scripts.pory"
Route104_EventScript_LandedInDewford::
# 448 "data/maps/Route104/scripts.pory"
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
# 449 "data/maps/Route104/scripts.pory"
	releaseall
# 450 "data/maps/Route104/scripts.pory"
	end
# 451 "data/maps/Route104/scripts.pory"

# 452 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordBeforeDadCalls:
# 453 "data/maps/Route104/scripts.pory"
	walk_down
# 454 "data/maps/Route104/scripts.pory"
	walk_down
# 455 "data/maps/Route104/scripts.pory"
	walk_down
# 456 "data/maps/Route104/scripts.pory"
	walk_down
# 457 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 458 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 459 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 460 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 461 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 462 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 463 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 464 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 465 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 466 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 467 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 468 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 469 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 470 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 471 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 472 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 473 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 474 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 475 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 476 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 477 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 478 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 479 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 480 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 481 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 482 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 483 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 484 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 485 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 486 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 487 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 488 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 489 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 490 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 491 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 492 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 493 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 494 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 495 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 496 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 497 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 498 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 499 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 500 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 501 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 502 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 503 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 504 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 505 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 506 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 507 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 508 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 509 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 510 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 511 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 512 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 513 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 514 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 515 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 516 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 517 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 518 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 519 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 520 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 521 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 522 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 523 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 524 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 525 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 526 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 527 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 528 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 529 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 530 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 531 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 532 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 533 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 534 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 535 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 536 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 537 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 538 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 539 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 540 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 541 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 542 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 543 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 544 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 545 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 546 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 547 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 548 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 549 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 550 "data/maps/Route104/scripts.pory"
	step_end
# 551 "data/maps/Route104/scripts.pory"

# 552 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewfordAfterDadCalls:
# 553 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 554 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 555 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 556 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 557 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 558 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 559 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 560 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 561 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 562 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 563 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 564 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 565 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 566 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 567 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 568 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 569 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 570 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 571 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 572 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 573 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 574 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 575 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 576 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 577 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 578 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 579 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 580 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 581 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 582 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 583 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 584 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 585 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 586 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 587 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 588 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 589 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 590 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 591 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 592 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 593 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 594 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 595 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 596 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 597 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 598 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 599 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 600 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 601 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 602 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 603 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 604 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 605 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 606 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 607 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 608 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 609 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 610 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 611 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 612 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 613 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 614 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 615 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 616 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 617 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 618 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 619 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 620 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 621 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 622 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 623 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 624 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 625 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 626 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 627 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 628 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 629 "data/maps/Route104/scripts.pory"
	walk_right
# 630 "data/maps/Route104/scripts.pory"
	walk_right
# 631 "data/maps/Route104/scripts.pory"
	walk_down
# 632 "data/maps/Route104/scripts.pory"
	walk_down
# 633 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 634 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 635 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 636 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 637 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 638 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 639 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 640 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 641 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 642 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 643 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 644 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 645 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 646 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 647 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 648 "data/maps/Route104/scripts.pory"
	walk_down
# 649 "data/maps/Route104/scripts.pory"
	walk_down
# 650 "data/maps/Route104/scripts.pory"
	step_end
# 651 "data/maps/Route104/scripts.pory"

# 652 "data/maps/Route104/scripts.pory"
Route104_Movement_SailToDewford:
# 653 "data/maps/Route104/scripts.pory"
	walk_down
# 654 "data/maps/Route104/scripts.pory"
	walk_down
# 655 "data/maps/Route104/scripts.pory"
	walk_down
# 656 "data/maps/Route104/scripts.pory"
	walk_down
# 657 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 658 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 659 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 660 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 661 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 662 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 663 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 664 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 665 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 666 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 667 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 668 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 669 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 670 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 671 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 672 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 673 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 674 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 675 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 676 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 677 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 678 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 679 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 680 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 681 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 682 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 683 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 684 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 685 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 686 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 687 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 688 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 689 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 690 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 691 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 692 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 693 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 694 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 695 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 696 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 697 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 698 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 699 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 700 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 701 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 702 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 703 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 704 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 705 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 706 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 707 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 708 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 709 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 710 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 711 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 712 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 713 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 714 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 715 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 716 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 717 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 718 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 719 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 720 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 721 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 722 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 723 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 724 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 725 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 726 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 727 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 728 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 729 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 730 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 731 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 732 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 733 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 734 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 735 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 736 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 737 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 738 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 739 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 740 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 741 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 742 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 743 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 744 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 745 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 746 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 747 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 748 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 749 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 750 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 751 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 752 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 753 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 754 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 755 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 756 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 757 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 758 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 759 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 760 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 761 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 762 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 763 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 764 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 765 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 766 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 767 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 768 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 769 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 770 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 771 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 772 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 773 "data/maps/Route104/scripts.pory"
	walk_faster_down
# 774 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 775 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 776 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 777 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 778 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 779 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 780 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 781 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 782 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 783 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 784 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 785 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 786 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 787 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 788 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 789 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 790 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 791 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 792 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 793 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 794 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 795 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 796 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 797 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 798 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 799 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 800 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 801 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 802 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 803 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 804 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 805 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 806 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 807 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 808 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 809 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 810 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 811 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 812 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 813 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 814 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 815 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 816 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 817 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 818 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 819 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 820 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 821 "data/maps/Route104/scripts.pory"
	walk_faster_right
# 822 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 823 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 824 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 825 "data/maps/Route104/scripts.pory"
	walk_fast_right
# 826 "data/maps/Route104/scripts.pory"
	walk_right
# 827 "data/maps/Route104/scripts.pory"
	walk_right
# 828 "data/maps/Route104/scripts.pory"
	walk_down
# 829 "data/maps/Route104/scripts.pory"
	walk_down
# 830 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 831 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 832 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 833 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 834 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 835 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 836 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 837 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 838 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 839 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 840 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 841 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 842 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 843 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 844 "data/maps/Route104/scripts.pory"
	walk_fast_down
# 845 "data/maps/Route104/scripts.pory"
	walk_down
# 846 "data/maps/Route104/scripts.pory"
	walk_down
# 847 "data/maps/Route104/scripts.pory"
	step_end
# 848 "data/maps/Route104/scripts.pory"

# 849 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerBoardBoat:
# 850 "data/maps/Route104/scripts.pory"
	walk_left
# 851 "data/maps/Route104/scripts.pory"
	walk_down
# 852 "data/maps/Route104/scripts.pory"
	walk_down
# 853 "data/maps/Route104/scripts.pory"
	step_end
# 854 "data/maps/Route104/scripts.pory"

# 855 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerExitBoat:
# 856 "data/maps/Route104/scripts.pory"
	walk_down
# 857 "data/maps/Route104/scripts.pory"
	step_end
# 858 "data/maps/Route104/scripts.pory"

# 859 "data/maps/Route104/scripts.pory"
Route104_Movement_PlayerMoveForBriney:
# 860 "data/maps/Route104/scripts.pory"
	walk_down
# 861 "data/maps/Route104/scripts.pory"
	walk_left
# 862 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_right
# 863 "data/maps/Route104/scripts.pory"
	step_end
# 864 "data/maps/Route104/scripts.pory"

# 865 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyBoardBoat:
# 866 "data/maps/Route104/scripts.pory"
	walk_down
# 867 "data/maps/Route104/scripts.pory"
	walk_down
# 868 "data/maps/Route104/scripts.pory"
	step_end
# 869 "data/maps/Route104/scripts.pory"

# 870 "data/maps/Route104/scripts.pory"
Route104_Movement_BrineyExitBoat:
# 871 "data/maps/Route104/scripts.pory"
	walk_down
# 872 "data/maps/Route104/scripts.pory"
	walk_in_place_faster_left
# 873 "data/maps/Route104/scripts.pory"
	step_end
# 874 "data/maps/Route104/scripts.pory"

# 875 "data/maps/Route104/scripts.pory"
Route104_EventScript_Ivan::
# 876 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat
# 877 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
# 878 "data/maps/Route104/scripts.pory"
	end
# 879 "data/maps/Route104/scripts.pory"

# 880 "data/maps/Route104/scripts.pory"
Route104_EventScript_Billy::
# 881 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
# 882 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
# 883 "data/maps/Route104/scripts.pory"
	end
# 884 "data/maps/Route104/scripts.pory"

# 885 "data/maps/Route104/scripts.pory"
Route104_EventScript_Haley::
# 886 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
# 887 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 888 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
# 889 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_HALEY_1
# 890 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 891 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
# 892 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 893 "data/maps/Route104/scripts.pory"
	release
# 894 "data/maps/Route104/scripts.pory"
	end
# 895 "data/maps/Route104/scripts.pory"

# 896 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaleyAfterBattle::
# 897 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 898 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 899 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
# 900 "data/maps/Route104/scripts.pory"
	release
# 901 "data/maps/Route104/scripts.pory"
	end
# 902 "data/maps/Route104/scripts.pory"

# 903 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaleyAfterBattle::
# 904 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
# 905 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 906 "data/maps/Route104/scripts.pory"
	release
# 907 "data/maps/Route104/scripts.pory"
	end
# 908 "data/maps/Route104/scripts.pory"

# 909 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterHaley::
# 910 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
# 911 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
# 912 "data/maps/Route104/scripts.pory"
	release
# 913 "data/maps/Route104/scripts.pory"
	end
# 914 "data/maps/Route104/scripts.pory"

# 915 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterHaley::
# 916 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
# 917 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_HALEY_1
# 918 "data/maps/Route104/scripts.pory"
	release
# 919 "data/maps/Route104/scripts.pory"
	end
# 920 "data/maps/Route104/scripts.pory"

# 921 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchHaley::
# 922 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
# 923 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
# 924 "data/maps/Route104/scripts.pory"
	end
# 925 "data/maps/Route104/scripts.pory"

# 926 "data/maps/Route104/scripts.pory"
Route104_EventScript_Winston::
# 927 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
# 928 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 929 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
# 930 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_WINSTON_1
# 931 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 932 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
# 933 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 934 "data/maps/Route104/scripts.pory"
	release
# 935 "data/maps/Route104/scripts.pory"
	end
# 936 "data/maps/Route104/scripts.pory"

# 937 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinstonAfterBattle::
# 938 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 939 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 940 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
# 941 "data/maps/Route104/scripts.pory"
	release
# 942 "data/maps/Route104/scripts.pory"
	end
# 943 "data/maps/Route104/scripts.pory"

# 944 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinstonAfterBattle::
# 945 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
# 946 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 947 "data/maps/Route104/scripts.pory"
	release
# 948 "data/maps/Route104/scripts.pory"
	end
# 949 "data/maps/Route104/scripts.pory"

# 950 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterWinston::
# 951 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
# 952 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
# 953 "data/maps/Route104/scripts.pory"
	release
# 954 "data/maps/Route104/scripts.pory"
	end
# 955 "data/maps/Route104/scripts.pory"

# 956 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterWinston::
# 957 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
# 958 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_WINSTON_1
# 959 "data/maps/Route104/scripts.pory"
	release
# 960 "data/maps/Route104/scripts.pory"
	end
# 961 "data/maps/Route104/scripts.pory"

# 962 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchWinston::
# 963 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
# 964 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
# 965 "data/maps/Route104/scripts.pory"
	end
# 966 "data/maps/Route104/scripts.pory"

# 967 "data/maps/Route104/scripts.pory"
Route104_EventScript_Cindy::
# 968 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_EventScript_TryRegisterCindyAfterBattle
# 969 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 970 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
# 971 "data/maps/Route104/scripts.pory"
	setvar VAR_0x8004, TRAINER_CINDY_1
# 972 "data/maps/Route104/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 973 "data/maps/Route104/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
# 974 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 975 "data/maps/Route104/scripts.pory"
	release
# 976 "data/maps/Route104/scripts.pory"
	end
# 977 "data/maps/Route104/scripts.pory"

# 978 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindyAfterBattle::
# 979 "data/maps/Route104/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 980 "data/maps/Route104/scripts.pory"
	waitmovement 0
# 981 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
# 982 "data/maps/Route104/scripts.pory"
	release
# 983 "data/maps/Route104/scripts.pory"
	end
# 984 "data/maps/Route104/scripts.pory"

# 985 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindyAfterBattle::
# 986 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
# 987 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 988 "data/maps/Route104/scripts.pory"
	release
# 989 "data/maps/Route104/scripts.pory"
	end
# 990 "data/maps/Route104/scripts.pory"

# 991 "data/maps/Route104/scripts.pory"
Route104_EventScript_TryRegisterCindy::
# 992 "data/maps/Route104/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
# 993 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
# 994 "data/maps/Route104/scripts.pory"
	release
# 995 "data/maps/Route104/scripts.pory"
	end
# 996 "data/maps/Route104/scripts.pory"

# 997 "data/maps/Route104/scripts.pory"
Route104_EventScript_RegisterCindy::
# 998 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
# 999 "data/maps/Route104/scripts.pory"
	register_matchcall TRAINER_CINDY_1
# 1000 "data/maps/Route104/scripts.pory"
	release
# 1001 "data/maps/Route104/scripts.pory"
	end
# 1002 "data/maps/Route104/scripts.pory"

# 1003 "data/maps/Route104/scripts.pory"
Route104_EventScript_RematchCindy::
# 1004 "data/maps/Route104/scripts.pory"
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
# 1005 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
# 1006 "data/maps/Route104/scripts.pory"
	end
# 1007 "data/maps/Route104/scripts.pory"

# 1008 "data/maps/Route104/scripts.pory"
Route104_EventScript_Gina::
# 1009 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
# 1010 "data/maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1011 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
# 1012 "data/maps/Route104/scripts.pory"
	release
# 1013 "data/maps/Route104/scripts.pory"
	end
# 1014 "data/maps/Route104/scripts.pory"

# 1015 "data/maps/Route104/scripts.pory"
Route104_EventScript_Mia::
# 1016 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
# 1017 "data/maps/Route104/scripts.pory"
	special GetPlayerBigGuyGirlString
# 1018 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
# 1019 "data/maps/Route104/scripts.pory"
	release
# 1020 "data/maps/Route104/scripts.pory"
	end
# 1021 "data/maps/Route104/scripts.pory"

# 1022 "data/maps/Route104/scripts.pory"
Route104_EventScript_Darian::
# 1023 "data/maps/Route104/scripts.pory"
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
# 1024 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
# 1025 "data/maps/Route104/scripts.pory"
	end
# 1026 "data/maps/Route104/scripts.pory"

# 1027 "data/maps/Route104/scripts.pory"
Route104_Text_BrineyLivesInSeasideCottage:
# 1028 "data/maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
# 1029 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY lives.\p"
# 1030 "data/maps/Route104/scripts.pory"
	.string "He was once a mighty sailor who never\n"
# 1031 "data/maps/Route104/scripts.pory"
	.string "feared the sea, however stormy.$"
# 1032 "data/maps/Route104/scripts.pory"

# 1033 "data/maps/Route104/scripts.pory"
Route104_Text_WhatsItLikeAtBottomOfSea:
# 1034 "data/maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
# 1035 "data/maps/Route104/scripts.pory"
	.string "I wonder what it's like at the bottom\n"
# 1036 "data/maps/Route104/scripts.pory"
	.string "of the sea?$"
# 1037 "data/maps/Route104/scripts.pory"

# 1038 "data/maps/Route104/scripts.pory"
Route104_Text_ThrowBallAtWeakenedPokemon:
# 1039 "data/maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
# 1040 "data/maps/Route104/scripts.pory"
	.string "weaken the wild POKéMON first.\p"
# 1041 "data/maps/Route104/scripts.pory"
	.string "It will be easier to catch if it's been\n"
# 1042 "data/maps/Route104/scripts.pory"
	.string "poisoned, burned, or lulled to sleep.$"
# 1043 "data/maps/Route104/scripts.pory"

# 1044 "data/maps/Route104/scripts.pory"
Route104_Text_OnlyThrowBallAtWildPokemon:
# 1045 "data/maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
# 1046 "data/maps/Route104/scripts.pory"
	.string "someone else's POKéMON.\p"
# 1047 "data/maps/Route104/scripts.pory"
	.string "You should throw POKé BALLS only at\n"
# 1048 "data/maps/Route104/scripts.pory"
	.string "wild POKéMON.$"
# 1049 "data/maps/Route104/scripts.pory"

# 1050 "data/maps/Route104/scripts.pory"
Route104_Text_ImNotATrainer:
# 1051 "data/maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
# 1052 "data/maps/Route104/scripts.pory"
	.string "But that's right, if TRAINERS lock eyes,\n"
# 1053 "data/maps/Route104/scripts.pory"
	.string "it's a challenge to battle.\p"
# 1054 "data/maps/Route104/scripts.pory"
	.string "If you don't want to battle, stay out\n"
# 1055 "data/maps/Route104/scripts.pory"
	.string "of their sight.$"
# 1056 "data/maps/Route104/scripts.pory"

# 1057 "data/maps/Route104/scripts.pory"
Route104_Text_LikeFillingMouthWithSeedsTakeThis:
# 1058 "data/maps/Route104/scripts.pory"
	.string "I like filling my mouth with seeds,\n"
# 1059 "data/maps/Route104/scripts.pory"
	.string "then spitting them out fast!\p"
# 1060 "data/maps/Route104/scripts.pory"
	.string "You can have this, so you try it out!\p"
# 1061 "data/maps/Route104/scripts.pory"
	.string "Use it on a POKéMON, and it will learn\n"
# 1062 "data/maps/Route104/scripts.pory"
	.string "a move for firing seeds rapidly.$"
# 1063 "data/maps/Route104/scripts.pory"

# 1064 "data/maps/Route104/scripts.pory"
Route104_Text_TMsAreOneTimeUse:
# 1065 "data/maps/Route104/scripts.pory"
	.string "A word of advice!\p"
# 1066 "data/maps/Route104/scripts.pory"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
# 1067 "data/maps/Route104/scripts.pory"
	.string "for one-time use.\p"
# 1068 "data/maps/Route104/scripts.pory"
	.string "Once you use it, it's gone.\n"
# 1069 "data/maps/Route104/scripts.pory"
	.string "Think twice before using it!$"
# 1070 "data/maps/Route104/scripts.pory"

# 1071 "data/maps/Route104/scripts.pory"
Route104_Text_DontNeedThisTakeIt:
# 1072 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1073 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1074 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1075 "data/maps/Route104/scripts.pory"
	.string "shopping.\p"
# 1076 "data/maps/Route104/scripts.pory"
	.string "I don't need this WHITE HERB anymore.\n"
# 1077 "data/maps/Route104/scripts.pory"
	.string "Would you take it, please?$"
# 1078 "data/maps/Route104/scripts.pory"

# 1079 "data/maps/Route104/scripts.pory"
Route104_Text_FlowerShopSellingSaplings:
# 1080 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
# 1081 "data/maps/Route104/scripts.pory"
	.string "saplings recently.\p"
# 1082 "data/maps/Route104/scripts.pory"
	.string "It made me so happy, I went overboard\n"
# 1083 "data/maps/Route104/scripts.pory"
	.string "shopping. Where should I put them?$"
# 1084 "data/maps/Route104/scripts.pory"

# 1085 "data/maps/Route104/scripts.pory"
Route104_Text_MrBrineysCottage:
# 1086 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"
# 1087 "data/maps/Route104/scripts.pory"

# 1088 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignPetalburg:
# 1089 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1090 "data/maps/Route104/scripts.pory"
	.string "{RIGHT_ARROW} PETALBURG CITY$"
# 1091 "data/maps/Route104/scripts.pory"

# 1092 "data/maps/Route104/scripts.pory"
Route104_Text_RouteSignRustboro:
# 1093 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4\n"
# 1094 "data/maps/Route104/scripts.pory"
	.string "{UP_ARROW} RUSTBORO CITY$"
# 1095 "data/maps/Route104/scripts.pory"

# 1096 "data/maps/Route104/scripts.pory"
Route104_Text_PrettyPetalFlowShop:
# 1097 "data/maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"
# 1098 "data/maps/Route104/scripts.pory"

# 1099 "data/maps/Route104/scripts.pory"
Route104_Text_TrainerTipsDoubleBattles:
# 1100 "data/maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
# 1101 "data/maps/Route104/scripts.pory"
	.string "In the HOENN region there are pairs\n"
# 1102 "data/maps/Route104/scripts.pory"
	.string "of TRAINERS who challenge others\l"
# 1103 "data/maps/Route104/scripts.pory"
	.string "for 2-on-2 POKéMON battles called\l"
# 1104 "data/maps/Route104/scripts.pory"
	.string "DOUBLE BATTLES.\p"
# 1105 "data/maps/Route104/scripts.pory"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
# 1106 "data/maps/Route104/scripts.pory"
	.string "send out two POKéMON, the one at the\l"
# 1107 "data/maps/Route104/scripts.pory"
	.string "left of the list and the top one.\l"
# 1108 "data/maps/Route104/scripts.pory"
	.string "Watch how POKéMON are lined up.$"
# 1109 "data/maps/Route104/scripts.pory"

# 1110 "data/maps/Route104/scripts.pory"
Route104_Text_MayWeShouldRegister:
# 1111 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
# 1112 "data/maps/Route104/scripts.pory"
	.string "DEVON upgraded your POKéNAV with\n"
# 1113 "data/maps/Route104/scripts.pory"
	.string "the MATCH CALL system, huh?\p"
# 1114 "data/maps/Route104/scripts.pory"
	.string "We should register each other so we\n"
# 1115 "data/maps/Route104/scripts.pory"
	.string "can get in contact anytime.$"
# 1116 "data/maps/Route104/scripts.pory"

# 1117 "data/maps/Route104/scripts.pory"
Route104_Text_RegisteredMay:
# 1118 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered MAY\n"
# 1119 "data/maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1120 "data/maps/Route104/scripts.pory"

# 1121 "data/maps/Route104/scripts.pory"
Route104_Text_MayHowsYourPokedex:
# 1122 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
# 1123 "data/maps/Route104/scripts.pory"
	.string "how's your POKéDEX coming along?$"
# 1124 "data/maps/Route104/scripts.pory"

# 1125 "data/maps/Route104/scripts.pory"
Route104_Text_MayMinesDecentLetsBattle:
# 1126 "data/maps/Route104/scripts.pory"
	.string "Mine's looking pretty decent.\n"
# 1127 "data/maps/Route104/scripts.pory"
	.string "So…\l"
# 1128 "data/maps/Route104/scripts.pory"
	.string "How about a little battle?$"
# 1129 "data/maps/Route104/scripts.pory"

# 1130 "data/maps/Route104/scripts.pory"
Route104_Text_MayHaventRaisedPokemon:
# 1131 "data/maps/Route104/scripts.pory"
	.string "MAY: Oh, what's the matter?\p"
# 1132 "data/maps/Route104/scripts.pory"
	.string "Haven't you caught or raised your\n"
# 1133 "data/maps/Route104/scripts.pory"
	.string "POKéMON very much?\p"
# 1134 "data/maps/Route104/scripts.pory"
	.string "That's not very good for a TRAINER!$"
# 1135 "data/maps/Route104/scripts.pory"

# 1136 "data/maps/Route104/scripts.pory"
Route104_Text_MayLetsBattle:
# 1137 "data/maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
# 1138 "data/maps/Route104/scripts.pory"
	.string "How about a little battle here?$"
# 1139 "data/maps/Route104/scripts.pory"

# 1140 "data/maps/Route104/scripts.pory"
Route104_Text_MayIntro:
# 1141 "data/maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
# 1142 "data/maps/Route104/scripts.pory"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"
# 1143 "data/maps/Route104/scripts.pory"

# 1144 "data/maps/Route104/scripts.pory"
Route104_Text_MayDefeat:
# 1145 "data/maps/Route104/scripts.pory"
	.string "Yikes!\n"
# 1146 "data/maps/Route104/scripts.pory"
	.string "You're better than I expected!$"
# 1147 "data/maps/Route104/scripts.pory"

# 1148 "data/maps/Route104/scripts.pory"
Route104_Text_MayPostBattle:
# 1149 "data/maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
# 1150 "data/maps/Route104/scripts.pory"
	.string "good with the way you handle POKéMON.\p"
# 1151 "data/maps/Route104/scripts.pory"
	.string "But instead of only making them\n"
# 1152 "data/maps/Route104/scripts.pory"
	.string "battle, you should be like MR. BRINEY.\p"
# 1153 "data/maps/Route104/scripts.pory"
	.string "It's important to become friends with\n"
# 1154 "data/maps/Route104/scripts.pory"
	.string "POKéMON, too.$"
# 1155 "data/maps/Route104/scripts.pory"

# 1156 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanWeShouldRegister:
# 1157 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
# 1158 "data/maps/Route104/scripts.pory"
	.string "Cool, you had DEVON install the MATCH\n"
# 1159 "data/maps/Route104/scripts.pory"
	.string "CALL system on your POKéNAV!\p"
# 1160 "data/maps/Route104/scripts.pory"
	.string "Let's register each other in our\n"
# 1161 "data/maps/Route104/scripts.pory"
	.string "POKéNAVS so we can keep in touch.$"
# 1162 "data/maps/Route104/scripts.pory"

# 1163 "data/maps/Route104/scripts.pory"
Route104_Text_RegisteredBrendan:
# 1164 "data/maps/Route104/scripts.pory"
	.string "{PLAYER} registered BRENDAN\n"
# 1165 "data/maps/Route104/scripts.pory"
	.string "in the POKéNAV.$"
# 1166 "data/maps/Route104/scripts.pory"

# 1167 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanHowsYourPokedex:
# 1168 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
# 1169 "data/maps/Route104/scripts.pory"
	.string "Have you filled in any pages yet?$"
# 1170 "data/maps/Route104/scripts.pory"

# 1171 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanDoingGreatLetsBattle:
# 1172 "data/maps/Route104/scripts.pory"
	.string "Me, I'm doing great!\p"
# 1173 "data/maps/Route104/scripts.pory"
	.string "Want to check out how good I am with\n"
# 1174 "data/maps/Route104/scripts.pory"
	.string "a battle?$"
# 1175 "data/maps/Route104/scripts.pory"

# 1176 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanNoConfidence:
# 1177 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's the matter? Don't have\n"
# 1178 "data/maps/Route104/scripts.pory"
	.string "any confidence in your POKéMON?$"
# 1179 "data/maps/Route104/scripts.pory"

# 1180 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanLetsBattle:
# 1181 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
# 1182 "data/maps/Route104/scripts.pory"
	.string "Want to have a battle with me?$"
# 1183 "data/maps/Route104/scripts.pory"

# 1184 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanIntro:
# 1185 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
# 1186 "data/maps/Route104/scripts.pory"
	.string "a TRAINER, but I won't go easy!$"
# 1187 "data/maps/Route104/scripts.pory"

# 1188 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanDefeat:
# 1189 "data/maps/Route104/scripts.pory"
	.string "Hmm…\n"
# 1190 "data/maps/Route104/scripts.pory"
	.string "You're pretty good.$"
# 1191 "data/maps/Route104/scripts.pory"

# 1192 "data/maps/Route104/scripts.pory"
Route104_Text_BrendanPostBattle:
# 1193 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
# 1194 "data/maps/Route104/scripts.pory"
	.string "at handling POKéMON.\p"
# 1195 "data/maps/Route104/scripts.pory"
	.string "But, you know, you shouldn't just be\n"
# 1196 "data/maps/Route104/scripts.pory"
	.string "making POKéMON battle.\p"
# 1197 "data/maps/Route104/scripts.pory"
	.string "Like MR. BRINEY, it's important to\n"
# 1198 "data/maps/Route104/scripts.pory"
	.string "become friends with your POKéMON.$"

Route104_Text_WhatsItLikeToSurf::
# 62 "data/maps/Route104/scripts.pory"
	.string "Wouldn't it be awesome to ride a\n"
	.string "POKéMON over the water?$"

Route104_Text_WhatsAcrossTheSea::
# 66 "data/maps/Route104/scripts.pory"
	.string "I wonder what's out there beyond the\n"
	.string "sea…$"
