Route102_MapScripts::
# 2 "data/maps/Route102/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route102_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route102_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 3 "data/maps/Route102/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	return


# 7 "data/maps/Route102/scripts.pory"

# 8 "data/maps/Route102/scripts.pory"
Route102_EventScript_LittleBoy::
# 9 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
# 10 "data/maps/Route102/scripts.pory"
	end
# 11 "data/maps/Route102/scripts.pory"

# 12 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignOldale::
# 13 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
# 14 "data/maps/Route102/scripts.pory"
	end
# 15 "data/maps/Route102/scripts.pory"

# 16 "data/maps/Route102/scripts.pory"
Route102_EventScript_RouteSignPetalburg::
# 17 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
# 18 "data/maps/Route102/scripts.pory"
	end
# 19 "data/maps/Route102/scripts.pory"

# 20 "data/maps/Route102/scripts.pory"
Route102_EventScript_Boy::
# 21 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
# 22 "data/maps/Route102/scripts.pory"
	end
# 23 "data/maps/Route102/scripts.pory"

# 24 "data/maps/Route102/scripts.pory"
Route102_EventScript_Calvin::
# 25 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
# 26 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 27 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
# 28 "data/maps/Route102/scripts.pory"
	setvar VAR_0x8004, TRAINER_CALVIN_1
# 29 "data/maps/Route102/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 30 "data/maps/Route102/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
# 31 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 32 "data/maps/Route102/scripts.pory"
	release
# 33 "data/maps/Route102/scripts.pory"
	end
# 34 "data/maps/Route102/scripts.pory"

# 35 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
# 36 "data/maps/Route102/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 37 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 38 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
# 39 "data/maps/Route102/scripts.pory"
	release
# 40 "data/maps/Route102/scripts.pory"
	end
# 41 "data/maps/Route102/scripts.pory"

# 42 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegisterMatchCall::
# 43 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
# 44 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 45 "data/maps/Route102/scripts.pory"
	release
# 46 "data/maps/Route102/scripts.pory"
	end
# 47 "data/maps/Route102/scripts.pory"

# 48 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinTryRegister::
# 49 "data/maps/Route102/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
# 50 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
# 51 "data/maps/Route102/scripts.pory"
	release
# 52 "data/maps/Route102/scripts.pory"
	end
# 53 "data/maps/Route102/scripts.pory"

# 54 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRegister::
# 55 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
# 56 "data/maps/Route102/scripts.pory"
	register_matchcall TRAINER_CALVIN_1
# 57 "data/maps/Route102/scripts.pory"
	release
# 58 "data/maps/Route102/scripts.pory"
	end
# 59 "data/maps/Route102/scripts.pory"

# 60 "data/maps/Route102/scripts.pory"
Route102_EventScript_CalvinRematch::
# 61 "data/maps/Route102/scripts.pory"
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
# 62 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
# 63 "data/maps/Route102/scripts.pory"
	end
# 64 "data/maps/Route102/scripts.pory"

# 65 "data/maps/Route102/scripts.pory"
Route102_EventScript_Rick::
# 66 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
# 67 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 68 "data/maps/Route102/scripts.pory"
	end
# 69 "data/maps/Route102/scripts.pory"

# 70 "data/maps/Route102/scripts.pory"
Route102_EventScript_Tiana::
# 71 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
# 72 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
# 73 "data/maps/Route102/scripts.pory"
	end
# 74 "data/maps/Route102/scripts.pory"

# 75 "data/maps/Route102/scripts.pory"
Route102_EventScript_Allen::
# 76 "data/maps/Route102/scripts.pory"
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
# 77 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
# 78 "data/maps/Route102/scripts.pory"
	end

Route102_EventScript_Rival1::
# 82 "data/maps/Route102/scripts.pory"
	lock
# 83 "data/maps/Route102/scripts.pory"
	faceplayer
# 84 "data/maps/Route102/scripts.pory"
	goto_if_unset FLAG_ITEM_ROUTE_102_POTION, Route102_EventScript_Rival1_2
# 98 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_4, 5
	goto_if_ne Route102_EventScript_Rival1_9
# 112 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RivalBetterAtThis
Route102_EventScript_Rival1_1:
# 115 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Rival1_2:
# 85 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_3, 5
	goto_if_ne Route102_EventScript_Rival1_6
# 90 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RivalItemSoClose, MSGBOX_DEFAULT
Route102_EventScript_Rival1_5:
# 92 "data/maps/Route102/scripts.pory"
	applymovement 10, Common_Movement_FaceLeft
# 93 "data/maps/Route102/scripts.pory"
	waitmovement 0
# 94 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Rival1_6:
# 86 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RivalHowToGetItem, MSGBOX_DEFAULT
# 87 "data/maps/Route102/scripts.pory"
	setvar VAR_TEMP_3, 5
	goto Route102_EventScript_Rival1_5

Route102_EventScript_Rival1_9:
# 99 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RivalHowdYouGetThatItem, MSGBOX_DEFAULT
# 100 "data/maps/Route102/scripts.pory"
	setvar VAR_TEMP_4, 5
# 101 "data/maps/Route102/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_RIVAL1
# 102 "data/maps/Route102/scripts.pory"
	getplayerxy VAR_0x8006, VAR_0x8007
# 103 "data/maps/Route102/scripts.pory"
	switch VAR_0x8006
# 104 "data/maps/Route102/scripts.pory"
	case 16, Route102_EventScript_Rival1_14
# 106 "data/maps/Route102/scripts.pory"
	case 17, Route102_EventScript_Rival1_15
Route102_EventScript_Rival1_12:
# 109 "data/maps/Route102/scripts.pory"
	updateobject 10
	goto Route102_EventScript_Rival1_1

Route102_EventScript_Rival1_14:
# 105 "data/maps/Route102/scripts.pory"
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_UP
	goto Route102_EventScript_Rival1_12

Route102_EventScript_Rival1_15:
# 107 "data/maps/Route102/scripts.pory"
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_RIGHT
	goto Route102_EventScript_Rival1_12


Route102_EventScript_Rival2::
# 120 "data/maps/Route102/scripts.pory"
	lock
# 121 "data/maps/Route102/scripts.pory"
	faceplayer
# 122 "data/maps/Route102/scripts.pory"
	compare VAR_TEMP_2, 5
	goto_if_eq Route102_EventScript_Rival2_2
# 126 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_Rival2CatchRalts, MSGBOX_DEFAULT
# 127 "data/maps/Route102/scripts.pory"
	setvar VAR_TEMP_2, 5
Route102_EventScript_Rival2_1:
# 129 "data/maps/Route102/scripts.pory"
	release
	end

Route102_EventScript_Rival2_2:
# 123 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_Rival2CmonRalts, MSGBOX_DEFAULT
	goto Route102_EventScript_Rival2_1


# 162 "data/maps/Route102/scripts.pory"

# 163 "data/maps/Route102/scripts.pory"
Route102_Text_WatchMeCatchPokemon:
# 164 "data/maps/Route102/scripts.pory"
	.string "WALLY: {PLAYER}…\n"
# 165 "data/maps/Route102/scripts.pory"
	.string "POKéMON hide in tall grass like this,\l"
# 166 "data/maps/Route102/scripts.pory"
	.string "don't they?\p"
# 167 "data/maps/Route102/scripts.pory"
	.string "Please watch me and see if I can\n"
# 168 "data/maps/Route102/scripts.pory"
	.string "catch one properly.\p"
# 169 "data/maps/Route102/scripts.pory"
	.string "…Whoa!$"
# 170 "data/maps/Route102/scripts.pory"

# 171 "data/maps/Route102/scripts.pory"
Route102_Text_WallyIDidIt:
# 172 "data/maps/Route102/scripts.pory"
	.string "WALLY: I did it… It's my…\n"
# 173 "data/maps/Route102/scripts.pory"
	.string "My POKéMON!$"
# 174 "data/maps/Route102/scripts.pory"

# 175 "data/maps/Route102/scripts.pory"
Route102_Text_LetsGoBack:
# 176 "data/maps/Route102/scripts.pory"
	.string "{PLAYER}, thank you!\n"
# 177 "data/maps/Route102/scripts.pory"
	.string "Let's go back to the GYM!$"
# 178 "data/maps/Route102/scripts.pory"

# 179 "data/maps/Route102/scripts.pory"
Route102_Text_ImNotVeryTall:
# 180 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
# 181 "data/maps/Route102/scripts.pory"
	.string "into tall grass.\p"
# 182 "data/maps/Route102/scripts.pory"
	.string "The grass goes up my nose and…\n"
# 183 "data/maps/Route102/scripts.pory"
	.string "Fwafwafwafwafwa…\p"
# 184 "data/maps/Route102/scripts.pory"
	.string "Fwatchoo!$"
# 185 "data/maps/Route102/scripts.pory"

# 186 "data/maps/Route102/scripts.pory"
Route102_Text_CatchWholeBunchOfPokemon:
# 187 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
# 188 "data/maps/Route102/scripts.pory"
	.string "POKéMON!$"
# 189 "data/maps/Route102/scripts.pory"

# 190 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignOldale:
# 191 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 192 "data/maps/Route102/scripts.pory"
	.string "{RIGHT_ARROW} OLDALE TOWN$"
# 193 "data/maps/Route102/scripts.pory"

# 194 "data/maps/Route102/scripts.pory"
Route102_Text_RouteSignPetalburg:
# 195 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102\n"
# 196 "data/maps/Route102/scripts.pory"
	.string "{LEFT_ARROW} PETALBURG CITY$"

Route102_Text_RivalHowToGetItem::
# 133 "data/maps/Route102/scripts.pory"
	.string "I can see that item on the ground\n"
	.string "over there, but I just can't see\l"
	.string "a way to get to it…$"

Route102_Text_RivalItemSoClose::
# 139 "data/maps/Route102/scripts.pory"
	.string "It's so tantalizingly close!$"

Route102_Text_RivalHowdYouGetThatItem::
# 143 "data/maps/Route102/scripts.pory"
	.string "How'd you get to that item?!$"

Route102_Text_RivalBetterAtThis::
# 147 "data/maps/Route102/scripts.pory"
	.string "You're obviously better at this\n"
	.string "than I am…$"

Route102_Text_Rival2CatchRalts::
# 152 "data/maps/Route102/scripts.pory"
	.string "I'm going to find a RALTS.\n"
	.string "No matter how long it takes!$"

Route102_Text_Rival2CmonRalts::
# 157 "data/maps/Route102/scripts.pory"
	.string "C'mon RALTS!\n"
	.string "C'mon RALTS!$"
