# 1 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 2 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_MapScripts::
# 3 "data/maps/Route109_SeashoreHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
# 4 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.byte 0
# 5 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 6 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_OnTransition:
# 7 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
# 8 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 9 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 10 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Owner::
# 11 "data/maps/Route109_SeashoreHouse/scripts.pory"
	lock
# 12 "data/maps/Route109_SeashoreHouse/scripts.pory"
	faceplayer
# 13 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
# 14 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
# 15 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
# 16 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
# 17 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 18 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 19 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 20 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 21 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
# 22 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
# 23 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 24 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 25 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 26 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_DefeatedTrainers::
# 27 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
# 28 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP, 6
# 29 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
# 30 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_RECEIVED_6_SODA_POP
# 31 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 32 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 33 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 34 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_BagFull::
# 35 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
# 36 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 37 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 38 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 39 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
# 40 "data/maps/Route109_SeashoreHouse/scripts.pory"
	showmoneybox 0, 0
# 41 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
# 42 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
# 43 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
# 44 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 45 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 46 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 47 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 48 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_BuySodaPop::
# 49 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkmoney 300
# 50 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
# 51 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkitemspace ITEM_SODA_POP
# 52 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
# 53 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
# 54 "data/maps/Route109_SeashoreHouse/scripts.pory"
	removemoney 300
# 55 "data/maps/Route109_SeashoreHouse/scripts.pory"
	updatemoneybox
# 56 "data/maps/Route109_SeashoreHouse/scripts.pory"
	giveitem ITEM_SODA_POP
# 57 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 58 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 59 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 60 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 61 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_NotEnoughMoney::
# 62 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
# 63 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 64 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 65 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 66 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 67 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_NotEnoughSpace::
# 68 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 69 "data/maps/Route109_SeashoreHouse/scripts.pory"
	hidemoneybox
# 70 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
# 71 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 72 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 73 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Dwayne::
# 74 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 75 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
# 76 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 77 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 78 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Johanna::
# 79 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 80 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
# 81 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end
# 82 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 83 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_EventScript_Simon::
# 84 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 85 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
# 86 "data/maps/Route109_SeashoreHouse/scripts.pory"
	end

Route109_SeashoreHouse_EventScript_Rival2::
# 90 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkfriendchoice
# 91 "data/maps/Route109_SeashoreHouse/scripts.pory"
	switch VAR_RESULT
# 92 "data/maps/Route109_SeashoreHouse/scripts.pory"
	case SPENCER, Route109_SeashoreHouse_EventScript_Rival2_3
# 95 "data/maps/Route109_SeashoreHouse/scripts.pory"
	case BREN, Route109_SeashoreHouse_EventScript_Rival2_4
# 98 "data/maps/Route109_SeashoreHouse/scripts.pory"
	case KYLE, Route109_SeashoreHouse_EventScript_Rival2_5
Route109_SeashoreHouse_EventScript_Rival2_1:
	end

Route109_SeashoreHouse_EventScript_Rival2_3:
# 93 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_KYLE_SEASHORE, Route109_SeashoreHouse_Text_KyleIntro, Route109_SeashoreHouse_Text_KyleDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 94 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_KylePostBattle, MSGBOX_AUTOCLOSE
	goto Route109_SeashoreHouse_EventScript_Rival2_1

Route109_SeashoreHouse_EventScript_Rival2_4:
# 96 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_SPENCER_SEASHORE, Route109_SeashoreHouse_Text_SpencerIntro, Route109_SeashoreHouse_Text_SpencerDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 97 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	goto Route109_SeashoreHouse_EventScript_Rival2_1

Route109_SeashoreHouse_EventScript_Rival2_5:
# 99 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_single TRAINER_BREN_SEASHORE, Route109_SeashoreHouse_Text_BrenIntro, Route109_SeashoreHouse_Text_BrenDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
# 100 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_BrenPostBattle, MSGBOX_AUTOCLOSE
	goto Route109_SeashoreHouse_EventScript_Rival2_1


Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
# 106 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 107 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 108 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
# 109 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkflag FLAG_HIDE_SEASHORE_HOUSE_RIVAL2
# 110 "data/maps/Route109_SeashoreHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_2
Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_1:
# 121 "data/maps/Route109_SeashoreHouse/scripts.pory"
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
# 122 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_2:
# 111 "data/maps/Route109_SeashoreHouse/scripts.pory"
	checkfriendchoice
# 112 "data/maps/Route109_SeashoreHouse/scripts.pory"
	switch VAR_RESULT
# 113 "data/maps/Route109_SeashoreHouse/scripts.pory"
	case SPENCER, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_5
# 115 "data/maps/Route109_SeashoreHouse/scripts.pory"
	case BREN, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_6
# 117 "data/maps/Route109_SeashoreHouse/scripts.pory"
	case KYLE, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_7
	goto Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_1

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_5:
# 114 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_KYLE_SEASHORE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_1

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_6:
# 116 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_SPENCER_SEASHORE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_1

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_7:
# 118 "data/maps/Route109_SeashoreHouse/scripts.pory"
	goto_if_not_defeated TRAINER_BREN_SEASHORE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto Route109_SeashoreHouse_EventScript_CheckTrainersCompletion_1


Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
# 127 "data/maps/Route109_SeashoreHouse/scripts.pory"
	release
	end


# 182 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 183 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SeashoreHouseIntro:
# 184 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm the owner of the SEASHORE HOUSE.\n"
# 185 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "But you can call me MR. SEA!\p"
# 186 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "What I love above all is to see hot\n"
# 187 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "POKéMON battles.\p"
# 188 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Let me see that your heart burns hot!\p"
# 189 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If you can defeat all the TRAINERS\n"
# 190 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "here, I'll reward your efforts.$"
# 191 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 192 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
# 193 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Show me some hot matches!\p"
# 194 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I run this SEASHORE HOUSE just for\n"
# 195 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "that reason alone!$"
# 196 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 197 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
# 198 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You're scorching hot!\n"
# 199 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Those battles blazed!\l"
# 200 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm more than just satisfied!\p"
# 201 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "As thanks for showing me your hot\n"
# 202 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "streak, I want you to take these.\p"
# 203 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "It's half a dozen bottles of SODA POP!$"
# 204 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 205 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_BagFull:
# 206 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Oh, but hey, your BAG's jammed full.\n"
# 207 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'll hang on to these for you.$"
# 208 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 209 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_WantToBuySodaPop:
# 210 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Want to buy some SODA POP?\n"
# 211 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "POKéMON love it!\p"
# 212 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Just ¥300 a bottle!\n"
# 213 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Buy some!$"
# 214 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 215 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_HereYouGo:
# 216 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Here you go!$"
# 217 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 218 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_NotEnoughMoney:
# 219 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You don't have the money.$"
# 220 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 221 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_ThatsTooBad:
# 222 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "No?\n"
# 223 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That's too bad.$"
# 224 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 225 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwayneIntro:
# 226 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If you're looking for a battle in the\n"
# 227 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "SEASHORE HOUSE, you'll find no\l"
# 228 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "hotter TRAINER than me, matey!$"
# 229 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 230 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwayneDefeated:
# 231 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That was a hot battle!\n"
# 232 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I can accept that loss, matey!$"
# 233 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 234 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_DwaynePostBattle:
# 235 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
# 236 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "hot battles and ice-cold SODA POP!$"
# 237 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 238 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaIntro:
# 239 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Boring battles aren't worth the effort.\p"
# 240 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Fiery hot battles are what toughen up\n"
# 241 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "TRAINERS and POKéMON!$"
# 242 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 243 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaDefeated:
# 244 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That's hot!$"
# 245 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 246 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_JohannaPostBattle:
# 247 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Whew, I'm all thirsty.\n"
# 248 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Maybe I'll have a SODA POP.$"
# 249 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 250 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonIntro:
# 251 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I'm going to show you how great\n"
# 252 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "my POKéMON are, but don't cry!$"
# 253 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 254 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonDefeated:
# 255 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "…I lost, but I won't cry…$"
# 256 "data/maps/Route109_SeashoreHouse/scripts.pory"

# 257 "data/maps/Route109_SeashoreHouse/scripts.pory"
Route109_SeashoreHouse_Text_SimonPostBattle:
# 258 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "If one of my POKéMON knew the move\n"
# 259 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "for carrying me across water on its\l"
# 260 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "back, I could get rid of this inner tube.$"

Route109_SeashoreHouse_Text_SpencerIntro::
# 131 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That guy over there gave me some\n"
	.string "SODA POP in exchange for battling\l"
	.string "trainers who come in here. What a steal!\p"
	.string "…Hold on.\n"
	.string "You're a trainer!\l"
	.string "Time to earn my keep!$"

Route109_SeashoreHouse_Text_BrenIntro::
# 139 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That guy over there gave me some\n"
	.string "SODA POP in exchange for battling\l"
	.string "trainers who come in here. What a steal!\p"
	.string "…Hold on.\n"
	.string "You're a trainer!\l"
	.string "Time to earn my keep!$"

Route109_SeashoreHouse_Text_KyleIntro::
# 147 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "That guy over there gave me some\n"
	.string "SODA POP in exchange for battling\l"
	.string "trainers who come in here. What a steal!\p"
	.string "…Hold on.\n"
	.string "You're a trainer!\l"
	.string "Time to earn my keep!$"

Route109_SeashoreHouse_Text_SpencerDefeated::
# 155 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "At least I have my SODA POP!$"

Route109_SeashoreHouse_Text_BrenDefeated::
# 159 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "At least I have my SODA POP!$"

Route109_SeashoreHouse_Text_KyleDefeated::
# 163 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "At least I have my SODA POP!$"

Route109_SeashoreHouse_Text_SpencerPostBattle::
# 167 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I know it's for POKéMON, but\n"
	.string "I like the taste of SODA POP, too!$"

Route109_SeashoreHouse_Text_BrenPostBattle::
# 172 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I know it's for POKéMON, but\n"
	.string "I like the taste of SODA POP, too!$"

Route109_SeashoreHouse_Text_KylePostBattle::
# 177 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "I know it's for POKéMON, but\n"
	.string "I like the taste of SODA POP, too!$"
